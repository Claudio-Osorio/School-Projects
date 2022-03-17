# Name: Claudio Osorio Date: 1-16-2022
# Section: Module 2
# Assignment: Identify Questions and Data Sets
# Due Date: 1-16-2022
# About this project: Evaluates the central tendencies and variation of attributes of the 3 datasets imported.
# Assumptions: N/A
# All work below was performed by Claudio Osorio

# PLEASE NOTE:
# * I may have partially changed some headers because they contained spaces.
# * Some of the dataset filenames names may have been renamed to remove spaces or unwanted characters.
# * The RuntimeWarning is meaningless because zero hospitalizations is an actual statistic
# * I consider it is better to provide the central tendencies by continent. Showing the
#  tendencies in general would be too broad and showing it by country would be too long of an output.
# * The dataset being used are the following:
# "daily-covid19-hospitalisation-data", "TSLA", "gdp-of-all-countries19602020"

import pandas as pd
import scipy
import matplotlib.pyplot as plt
from scipy import stats
import statistics
import numpy as np

# Displays the central tendencies and variation of each attribute.
def CentralTendencies(customDF, attribute):
    print('Max: ', customDF[attribute].max())
    print('Min: ', customDF[attribute].min())
    print('Mean: ', customDF[attribute].mean())
    print('Median: ', customDF[attribute].median())
    print('Geometric mean: ', scipy.stats.gmean(customDF[attribute]))
    print('Standard Deviation: ', (statistics.stdev(customDF[attribute])))
    return customDF[attribute].mean()

if __name__ == '__main__':
    # Covid19 Hospitalization Dataset
    # Reading the dataset. Copying it to dataframe
    print("###### Covid19 Hospitalization Dataset ######")
    file = r"daily-covid19-hospitalisation-data.csv"
    df = pd.read_csv(file)

    print("The following are non-computable attributes:\n"
          "- entity\n"
          "- iso_code\n"
          "- date\n"
          "- indicator\n")

    print("Daily ICU occupancy for all countries:")
    daily_ICU_occupancy = df.query('indicator == "Daily ICU occupancy"')
    CentralTendencies(daily_ICU_occupancy, 'value')
    print("\n")


    print("Daily ICU occupancy for all countries per million:")
    daily_ICU_occupancy_per_M = df.query('indicator == "Daily ICU occupancy per million"')
    CentralTendencies(daily_ICU_occupancy_per_M, 'value')
    print("\n")

    ### QUESTION 1 ###
    # Finding the daily ICU occupancy per million for every unique country
    for each_country in df['entity'].unique():
        daily_ICU_occupancy_per_M_each_country = df.query('indicator == "Daily ICU occupancy per million"'
                                                          ' and entity == @each_country')
        country_series = daily_ICU_occupancy_per_M_each_country['value'].values
        type(country_series)
        #Plotting the line of each country
        plt.plot(country_series, label=each_country)

    # Final Graph Touch Up
    plt.xlabel('Days From 7/17/2020 to 1/10/2022')
    plt.ylabel('Daily ICU occupancy per million')
    plt.title('ICU Hospitalization Rate by Country')
    plt.legend(loc=2, prop={'size': 8})
    plt.show()

    plt.clf()
    #### Netherlands vs Portugal ####
    # Comparing only 2 countries for better visibility
    #Netherlands
    country1 = 'Netherlands'
    daily_ICU_occupancy_per_M_A = df.query('indicator == "Daily ICU occupancy per million"'
                                           ' and entity == @country1')

    A_series = daily_ICU_occupancy_per_M_A['value'].values
    type(A_series)
    plt.plot(A_series, label=country1)

    #Portugal
    country2 = 'Portugal'
    daily_ICU_occupancy_per_M_B = df.query('indicator == "Daily ICU occupancy per million"'
                                           ' and entity == @country2')

    B_series = daily_ICU_occupancy_per_M_B['value'].values
    type(B_series)
    plt.plot(B_series, label=country2)

    # Final Graph Touch Up
    plt.xlabel('Days From 7/17/2020 to 1/10/2022')
    plt.ylabel('Daily ICU occupancy per million')
    plt.title(f'ICU Hospitalization Rate {country1} vs {country2}')
    plt.legend(loc=2, prop={'size': 10})
    plt.show()

    plt.clf() #Clear plot
    # GDP Of All Continents/Countries
    # Reading the dataset. Copying it to dataframe
    print("###### GDY by Continent Dataset (Last 60 Years) ######")
    file3 = r"gdp-of-all-countries19602020.csv"
    df3 = pd.read_csv(file3)

    print("The following are non-computable attributes:\n"
          "- year\n"
          "- rank\n"
          "- country\n"
          "- state\n")

    ### QUESTION 2 ###
    # Making list of all possible years
    years = df3['year'].unique()
    list_of_years = list()
    list_gdp_per_year = list()
    for each_year in years:
        list_of_years.append(each_year)

    # For every unique continent I store it's gdp (per year)
    for each_continent in df3['state'].unique():
        specific_continent_df = df3.query('state == @each_continent')
        # Summing all the GDP of each country in the continent and storing it in an array by year.
        for each_year in years:
            df_all_continent_during_this_year = specific_continent_df.query('year == @each_year')
            # Sum GDP of ea country per year
            total_continent_gdp_in_this_year = df_all_continent_during_this_year['gdp'].sum()
            list_gdp_per_year.append(total_continent_gdp_in_this_year)

        # Plotting the line of this continent on the graph
        plt.plot(list_of_years, list_gdp_per_year, label=each_continent)
        # Clearing the list of GDP for every year
        list_gdp_per_year.clear()
    # Final Graph Touch Up
    plt.xlabel('Years From 1960 to 2020')
    plt.ylabel('GDP (x 10^13) ')
    plt.title('Continents GDP From 1960 to 2020')
    plt.legend(loc=2, prop={'size': 8})
    plt.show()
    plt.clf()  # Clear plot

    for aContinent in df3['state'].unique():
        aContinent_str = str(aContinent)
        print(aContinent_str + " - GDP: ")
        dfContinent = df3.query('state == @aContinent_str')
        CentralTendencies(dfContinent, 'gdp')
        print("\n")

    ### QUESTION 3 ###
    #### US vs CHINA 1999 ####
    #US
    country1 = 'the United States'
    year1 = 1999
    country1_GDP = df3.query('country == @country1 and year == @year1')
    A_GDP1 = country1_GDP['gdp'].values
    type(A_GDP1)

    #China
    country2 = 'China'
    country2_GDP = df3.query('country == @country2 and year == @year1')
    B_GDP1 = country2_GDP['gdp'].values
    type(B_GDP1)

    #### US vs CHINA 2019 ####
    # US
    year2 = 2019
    country1_GDP2 = df3.query('country == @country1 and year == @year2')
    A_GDP2 = country1_GDP2['gdp'].values
    type(A_GDP2)

    # China
    country2_GDP2 = df3.query('country == @country2 and year == @year2')
    B_GDP2 = country2_GDP2['gdp'].values
    type(B_GDP2)

    # Final Graph Touch Up

    plt.bar(country1 + "-" + str(year1), int(A_GDP1[0]), label=country1 + "-" + str(year1))
    plt.bar(country2 + "-" + str(year1), int(B_GDP1[0]), label=country2 + "-" + str(year1))
    plt.bar(country1 + "-" + str(year2), int(A_GDP2[0]), label=country1 + "-" + str(year2))
    plt.bar(country2 + "-" + str(year2), int(B_GDP2[0]), label=country2 + "-" + str(year2))

    plt.xlabel('Countries')
    plt.ylabel('GDP (x 10^13)')
    plt.title(f'GDP comparison: {country1} vs {country2}')
    plt.legend(loc=2, prop={'size': 10})
    plt.show()
    plt.clf() #Clear plot

    # Stats US vs CHINA
    print(f'{country1} - {year1}: GDP was: {A_GDP1[0]}\n{country2} - {year1}: GDP was:{B_GDP1[0]}')
    print(f'{country1} - {year2}: GDP was: {A_GDP2[0]}\n{country2} - {year2}: GDP was:{B_GDP2[0]}')
    print(f"Difference:\nIn {year1}, {country1} had an economy {(A_GDP1[0]/B_GDP1[0])} times bigger"
          f"\nIn {year2}, {country1} had an economy {(A_GDP2[0]/B_GDP2[0])} times bigger\n\n")


    ### QUESTION 4 ###
    # Tesla Stock Price
    # Reading the dataset. Copying it to dataframe
    print("###### TSLA Stock Price Dataset (11 Years) ######")
    file2 = r"TSLA.csv"
    df2 = pd.read_csv(file2)
    print("The following is the non-computable attribute:\n"
          "- Date\n")

    # OPEN
    print("TSLA stock daily OPEN: ")
    TSLA_open_mean = CentralTendencies(df2, 'Open')
    print("\n")


    # HIGH
    print("TSLA stock daily HIGH: ")
    TSLA_high_mean = CentralTendencies(df2, 'High')
    print("\n")

    ### QUESTION 5 ###
    # BAR GRAPH
    plt.bar("Daily OPEN", TSLA_open_mean, label="OPEN")
    plt.bar("Daily HIGH", TSLA_high_mean, label="HIGH")

    plt.xlabel('TYPE')
    plt.ylabel('MEAN')
    plt.title(f'TSLA STOCK: 11 YEAR - DAILY OPEN VS DAILY HIGH (2010/2021)')
    plt.legend(loc=2, prop={'size': 10})
    plt.show()
    plt.clf()  # Clear plot

    print("TSLA stock daily LOW: ")
    CentralTendencies(df2, 'Low')
    print("\n")

    print("TSLA stock daily Adjusted Close: ")
    CentralTendencies(df2, 'Adj Close')
    print("\n")

    print("TSLA stock daily Volume: ")
    CentralTendencies(df2, 'Volume')
    print("\n")
