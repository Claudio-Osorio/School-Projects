# Name: Claudio Osorio
# Date: 3-1-2022
# Section: Module 8
# Assignment: Uncertain Probabilities
# Due Date: 3-6-2022
# About this project: Practicing probabilities and Bayes on a data set.
# Assumptions: N/A
# All work below was performed by Claudio Osorio.
# Dataset Used: StarWars.xlsx
# NOTE: My probabilities are based on 3 characters of the Starwars movies and how
# "favorably" they are to people. In this case if they are "very favorably" it means people
# like the character. This assignment tries to extract people's perception of those characters.

import pandas as pd
import scipy
from scipy import stats
import statistics

if __name__ == '__main__':
    # Reading CSV file
    file = r"StarWars.xlsx"
    df = pd.read_excel(file)

    # NOTE: This data set was partially cleaned manually to improve naming
    # and descriptions before importing it to dataframe to facilitate the work.

    print("\nBEFORE:")
    print(df.head(10).to_string())

    # Cleaning DF
    # Dropping responses that are incomplete or had no answers.
    # *Only leaves responses of people who have watched all the movies and answered every field
    df.dropna(inplace=True)

    print("\nAFTER:")
    print(df.head(10).to_string())

    # Probability of liking Princess Leia:  P(A1)
    dfPrincess = df.query('Rate_Princess_Leia == "Very favorably"')
    pA1 = dfPrincess.shape[0] / df.shape[0]

    # Probability of liking C-3PO: P(A2)
    dfC3PO = df.query('Rate_C3P0 == "Very favorably"')
    pA2 = dfC3PO.shape[0] / df.shape[0]

    # Probability of liking Master Yoda: P(A3)
    dfYoda = df.query('Rate_Yoda == "Very favorably"')
    pA3 = dfYoda.shape[0] / df.shape[0]

    # Probability of liking Princess Leia AND C-3PO: P(A1,A2)
    dfPrincessAndC3PO = df.query('Rate_C3P0 == "Very favorably" and Rate_Princess_Leia == "Very favorably"')
    pA1andA2 = dfPrincessAndC3PO.shape[0] / df.shape[0]

    # Probability of liking C-3PO AND Master Yoda: P(A2,A3)
    dfC3POAndYoda = df.query('Rate_C3P0 == "Very favorably" and Rate_Yoda == "Very favorably"')
    pA2andA3 = dfC3POAndYoda.shape[0] / df.shape[0]

    # Probability of liking Princess Leia OR C-3PO: P(A1vA2)
    pA1vA2 = pA1 + pA2 - pA1andA2

    # Probability of liking all 3. (Princess, C3PO, Yoda): P(A1,A2,A3)
    dfLikeAll = df.query('Rate_C3P0 == "Very favorably" and '
                         'Rate_Princess_Leia == "Very favorably" and '
                         'Rate_Yoda == "Very favorably"')
    pA1AndA2AndA3 = dfLikeAll.shape[0] / df.shape[0]

    # Probability of liking Princess Leia and Master Yoda: P(A1,A3)
    dfPrincessAndYoda = df.query('Rate_Princess_Leia == "Very favorably" and Rate_Yoda == "Very favorably"')
    pA1andA3 = dfPrincessAndYoda.shape[0] / df.shape[0]

    # Probability of liking C-3PO knowing the probability of liking Princess Leia and Master Yoda: P(A2|A1,A3)
    # Rule: P(A|B) = P(A,B)/P(B)
    # Substitution: A = A2  #  B = A1,A3
    # Formula:
    # P(A2|A1,A3)   =   P(A2,A1,A3) / P(A1,A3)
    # P(A2|A1,A3)   =   P(A1,A2,A3) / P(A1,A3)
    cp_A2_bar_A1andA3 = pA1AndA2AndA3 / pA1andA3

    # Using Bayes: Probability of liking Princess Leia and Master Yoda knowing the probability of
    # liking C-3PO. P(A1,A3|A2)
    # Rule: P(A|B) = [P(B|A) * P(A)] / P(B)
    # Substitution: A = A1,A3   #  B = A2
    # Formula:
    # P([A1,A3]|A2) = ([P(A2|[A1,A3]] * P(A1,A3) ) / P(A2)
    pBayes = (cp_A2_bar_A1andA3 * pA1andA3) / pA2

    print(f"\n\nDataset: StarWars.xlsx\n"
          f"Probability of liking Princess Leia:  P(A1) is {round((pA1) * 100, 2)}%\n"
          f"Probability of liking C-3PO: P(A2) is {round((pA2) * 100, 2)}%\n"
          f"Probability of liking Master Yoda: P(A3) is {round((pA3) * 100, 2)}%\n"
          f"Probability of liking Princess Leia OR C-3PO: P(A1vA2) is {round((pA1vA2) * 100, 2)}%\n"
          f"Probability of liking Princess Leia AND Master Yoda: P(A1,A3) is {round((pA1andA3) * 100, 2)}%\n"
          f"Probability of liking C-3PO knowing the probability of liking Princess Leia"
          f" and Master Yoda: P(A2|A1,A3) is {round((cp_A2_bar_A1andA3) * 100, 2)}%\n"
          f"Probability of liking Princess Leia AND Master Yoda knowing the probability of "
          f"liking C-3PO. P(A1,A3|A2) is {round((pBayes)*100,2)}%")


    # Creates and displays a distribution table with the count of the data based
    # upon three attributes that  you select from the data set (10 points)

    print("\n")
    print("------------------------------")
    print(" LIKES CHARACTER |     COUNT")
    print("------------------------------")
    print(f"  Princess Leia  |\t\t{dfPrincess.shape[0]}")
    print(f"      C-3PO      |\t\t{dfC3PO.shape[0]}")
    print(f"   Master Yoda   |\t\t{dfYoda.shape[0]}")
    print("------------------------------")

    print("\n")
    print("------------------------------")
    print("LIKES CHARACTER | PERCENTAGE")
    print("------------------------------")
    print(f" Princess Leia |\t{round(pA1,2)}")
    print(f"     C-3PO     |\t{round(pA2,2)}")
    print(f"  Master Yoda  |\t{round(pA3,2)}")
    print("------------------------------")

    print("\nLikes Both:")
    print("---------------------------------------------")
    print("   CHARACTER   |   CHARACTER   | PERCENTAGE")
    print("---------------------------------------------")
    print(f" Princess Leia |     C-3PO     |\t{round(pA1andA2,2)}")
    print(f" Princess Leia |  Master Yoda  |\t{round(pA1andA3,2)}")
    print(f"     C-3PO     |  Master Yoda  |\t{round(pA2andA3,2)}")
    print("---------------------------------------------")
