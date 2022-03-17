# Name: Claudio Osorio Date: 1-27-2022
# Section: Module 4
# Assignment: Wrangling Data Python
# Due Date: 1-30-2022
# About this project: Cleaning datasets.
# Assumptions: N/A
# All work below was performed by Claudio Osorio


import pandas as pd
import numpy as np
import collections
import scipy
import statistics
import matplotlib
import seaborn as sns
import matplotlib.pyplot as plt
from scipy import stats
from datetime import datetime

if __name__ == '__main__':

    # PROBLEM 1 Data Wrangling (20 Points)
    # Dataset Name: "Pitchers_Adjusted_Salary.csv"
    # Source:https://www.kaggle.com/andrewdecker/pitcher-salary-adjusted-to-inflation

    # Dataset Name: "Hitters_Adjusted_Salary.csv"
    # Source: https://www.kaggle.com/andrewdecker/hitters-salary-adjusted-to-inflation
    file_pitchers = r"Pitchers_Adjusted_Salary.csv"
    df_pitchers = pd.read_csv(file_pitchers)

    file_hitters = r"Hitters_Adjusted_Salary.csv"
    df_hitters = pd.read_csv(file_hitters)


    PAS = 'Pitcher ADJ Salary'
    HAS = 'Hitter Adj Salary'

    # Extracting the columns for the pitchers ID, salary and adjusted salary, renaming it and sorting it
    df_pitchers_pivot = df_pitchers[['yearID','playerID', 'salary', 'ADJ Salary']]
    df_pitchers_salaries = df_pitchers_pivot.rename(columns={'ADJ Salary': PAS})
    df_pitchers_salaries = df_pitchers_salaries.sort_values(PAS, ascending=False)

    # Reshaping: Melt, pivot, concat

    # Extracting the columns for the hitters ID, salary and adjusted salary, renaming it and sorting it
    df_hitters_pivot = df_hitters[['yearID','playerID', 'salary','ADJ Salary']]
    df_hitters_salaries = df_hitters_pivot.rename(columns={'ADJ Salary': HAS})
    df_hitters_salaries = df_hitters_salaries.sort_values(HAS, ascending=False)
    df_p_melted = pd.melt(df_pitchers_salaries)
    df_h_melted = pd.melt(df_hitters_salaries)

    print("Melt - Pitchers:")
    print(df_p_melted.head())
    print("\n")
    print("Melt - Hitters:")
    print(df_h_melted.head())
    print("\n")

    print("Concat - Pitchers + Hitters:")
    df_p_and_h = pd.concat([df_pitchers_salaries,df_hitters_salaries])
    print(df_p_and_h.head())
    print("\n")

    # Removing the columns Salary
    df_pitchers_salaries = df_pitchers_salaries.drop(columns = ['salary'])
    df_hitters_salaries = df_hitters_salaries.drop(columns= ['salary'])

    # Replacing non available values to be equal to the mean. (In this case 'nan' are salaries that are set as zero)
    # Notice: This is a pessimistic mean because this mean included the values that were previously zero.
    pitchers_pes_mean =  df_pitchers_salaries[PAS].mean()
    df_pitchers_salaries = df_pitchers_salaries.replace(to_replace=0.00, value=pitchers_pes_mean)

    hitters_pes_mean = df_hitters_salaries[HAS].mean()
    df_hitters_salaries = df_hitters_salaries.replace(to_replace=0.00, value=hitters_pes_mean)

    top10_P = df_pitchers_salaries.head(10)
    top10_P = top10_P.sort_values('yearID', ascending=False)

    top10_H = df_hitters_salaries.head(10)
    top10_H = top10_H.sort_values('yearID', ascending=False)

    # Real player stats. Player can be matched using his/her ID at https://www.baseball-reference.com/
    # but the salaries obtained here will be higher due to the adjustment due to inflation.
    print("\nTOP 10 HIGHEST ANNUAL SALARIES IN BASEBALL: (Sorted by year and adjusted by inflation)")
    print("\nPITCHERS:")
    print(top10_P)
    print("\nHITTERS:")
    print(top10_H)

    # PROBLEM 2 Text Attributes (30 points)
    # Dataset Name: "7282_1.csv"    This dataset is about hotel reviews.
    # Source: https://www.kaggle.com/datafiniti/hotel-reviews
    file_hotel_reviews = r"7282_1.csv"
    df_hotel_reviews = pd.read_csv(file_hotel_reviews, encoding = "ISO-8859-1", engine='python')

    # Dropping rows that don't have texts for the reviews or that have some useless text that I noticed.
    df_hotel_reviews["reviews.text"].replace("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx", "", inplace=True)
    df_hotel_reviews.dropna(subset=["reviews.text"], inplace=True)

    print("\nTOP 20 MOST COMMON REVIEWS")
    print(*collections.Counter(df_hotel_reviews['reviews.text']).most_common(20),sep="\n")
    print("\n")

    # Parsing the dataframe using the word "clean"
    print("Parsing the dataframe using the phrase \"very clean room\":")

    df_hotel_mentions_of_clean = df_hotel_reviews[df_hotel_reviews['reviews.text'].str.contains('very clean room', na=False)]
    print(df_hotel_mentions_of_clean['reviews.text'].head())
    print("\nThe amount of reviews with the phrase \"very clean room\" in it are: ",len(df_hotel_mentions_of_clean))

    # Review Date to DateTime
    # Sample from dataset: "2016-10-29T20:20:54Z"
    print("Reviews by Date:")
    df_hotel_reviews['review_date'] =  pd.to_datetime(df_hotel_reviews['reviews.dateAdded'])
    print(df_hotel_reviews.head())

    df_hotel_reviews['month'] = df_hotel_reviews['review_date'].dt.month
    df_hotel_reviews['day'] = df_hotel_reviews['review_date'].dt.day
    df_hotel_reviews['year'] = df_hotel_reviews['review_date'].dt.year
    df_hotel_reviews['hour'] = df_hotel_reviews['review_date'].dt.hour
    df_hotel_reviews['minute'] = df_hotel_reviews['review_date'].dt.minute

    # Review Date and Time Separated as attributes in the dataframe:
    # NOTE: The dataset dates come in a very strange manner.
    # It seems like the original source stored them in batches with zeros and everything
    print(df_hotel_reviews[['month','day','year','hour','minute']])

    # Count of reviews mentioning the phrase "very clean room" (by month)
    df_hotel_reviews_by_month = df_hotel_reviews[df_hotel_reviews['reviews.text'].
        str.contains('very clean room',na=False, regex=False)]
    df_hotel_reviews_by_month = df_hotel_reviews_by_month['month'].value_counts()
    df_hotel_reviews_by_month = df_hotel_reviews_by_month.sort_index()
    print("MONTHLY COUNT OF REVIEWS CONTAINING THE PHRASE: \"not very clean room\"")
    print(df_hotel_reviews_by_month)

    # Graph
    plt.xlabel('Months')
    plt.ylabel('Ocurrences')
    plt.title('Reviews mentioning \"very clean room\" by month')
    plt.plot(df_hotel_reviews_by_month.index, df_hotel_reviews_by_month.values)
    plt.show()


    #  PROBLEM 3 Outliers (20 points)
    # Dataset Name: "top_chess_players_aug_2020.csv"
    # Source: https://www.kaggle.com/vikasojha98/world-top-chess-players-august-2020

    file_top_chess_players = r"top_chess_players_aug_2020.csv"
    df_top_chess_players = pd.read_csv(file_top_chess_players, encoding = "ISO-8859-1", engine='python')

    # Box Plotting
    # The outsiders have an standard elo rating:  1000 < x < 2750
    sns.boxplot(x= df_top_chess_players['Standard_Rating'], data=df_top_chess_players)
    plt.show()

    # Scatter plot (BEFORE)
    fig, ax = plt.subplots(figsize=(18, 10))
    ax.scatter(df_top_chess_players['Year_of_birth'], df_top_chess_players['Standard_Rating'])

    # x-axis label
    ax.set_xlabel('Year of Birth')
    # y-axis label
    ax.set_ylabel('Rating')

    # Showing Graph (BEFORE)
    plt.show()

    # Dropping Outliers
    # Dropping low-end outliers ( 1000 > x )
    drop_values = np.where(df_top_chess_players['Standard_Rating']<1000)
    df_top_chess_players.drop(drop_values[0], inplace = True)

    # Dropping high-end outliers ( x > 2750 )
    drop_values = np.where(df_top_chess_players['Standard_Rating']>2750)
    df_top_chess_players.drop(drop_values[0], inplace = True)

    # Showing Graph
    sns.boxplot(x= df_top_chess_players['Standard_Rating'], data=df_top_chess_players)
    plt.show()

    # Scatter plot (AFTER)
    fig, ax = plt.subplots(figsize=(18, 10))
    ax.scatter(df_top_chess_players['Year_of_birth'], df_top_chess_players['Standard_Rating'])

    # x-axis label
    ax.set_xlabel('Year of Birth')
    # y-axis label
    ax.set_ylabel('Rating')

    # Showing Graph
    plt.show()
