# Name: Claudio Osorio Date: 1-14-2022
# Section: Module 2
# Assignment: Uncertain Probabilities Python
# Due Date: 1-16-2022
# About this project: Calculating probabilities (and Bayes) of a data set.
# Assumptions: N/A
# All work below was performed by Claudio Osorio

# PLEASE NOTE:
# *The dataset being used is "candy-data.csv"


import pandas as pd
import scipy
from scipy import stats
import statistics

if __name__ == '__main__':
    print('Written by Claudio Osorio')
    # Reading CSV file
    file = r"candy-data.csv"
    df = pd.read_csv(file)

    listOfAttributes = list()
    listIndex = 0
    for header in df.columns:
        listOfAttributes.append(str(header))



    # Probability of candy to have chocolate:  P(A1)
    dfChocolate = df.query('chocolate == 1')
    pA1 = dfChocolate.shape[0] / df.shape[0]

    # Probability of candy to have caramel: P(A2)
    dfCaramel = df.query('caramel == 1')
    pA2 = dfCaramel.shape[0] / df.shape[0]

    # Probability of candy coming in bars: P(A3)
    dfBar = df.query('bar == 1')
    pA3 = dfBar.shape[0] / df.shape[0]

    # Probability of a having chocolate and caramel: P(A1,A2)
    dfChocolateAndCaramel = df.query('chocolate == 1 and caramel == 1')
    pA1andA2 = dfChocolateAndCaramel.shape[0] / df.shape[0]

    #Probability of having chocolate or caremel: P(A1vA2)
    pA1orA2 = pA1 + pA2 - pA1andA2

    # Probability of both: candy being chocolate and coming in bars
    dfChocolateAndBar = df.query('chocolate == 1 and bar == 1')
    pA1andA3 = dfChocolateAndBar.shape[0] / df.shape[0]

    # Probability of a having chocolate and caramel: P(A1,A2)
    dfChocolateAndCaramelandBar = df.query('chocolate == 1 and caramel == 1 and bar ==1')
    pA1andA2andA3 = dfChocolateAndCaramelandBar.shape[0] / df.shape[0]

    # Probability of candy having Caramel given the p. of candy having Chocolate and
    # coming as a bar.
    # Solving: P(A|B) = P(A,B)|P(B)
    # Substitution: A = A2  #  B = A1,A3
    # Formula:
    # P(A2|A1,A3)   =   P(A2,[A1,A3])  / P(A1,A3)
    pA2_bar_A1andA3 = (pA1andA2andA3) / pA1andA3

    # Solving P(A1,A3|A2) by using Bayes:
    # Rule: P(A|B) = ( P(B|A) * P(A) ) / P(B)
    # Substitution: A = A1,A3   #  B = A2
    # Formula:
    # P([A1,A3]|A2) = ( P(A2|[A1,A3])   * P(A1,A3) ) / P(A2)
    pA1andA3_bar_A2 = ( pA2_bar_A1andA3 * pA1andA3 ) / pA2

    print(f"Dataset: candy-data.csv\n"
          f"Probability of candy having Chocolate [P(A1)] is {round((pA1) * 100, 2)}%\n"
          f"Probability of candy having Caramel [P(A2)] is {round((pA2) * 100, 2)}%\n"
          f"Probability that a candy comes in bars [P(A3)] is {round((pA3) * 100, 2)}%\n\n"
          f"Probability that candy is Chocolate or Caramel [P(A1 v A2)] is "
          f"{round((pA1orA2) * 100, 2)}%\n"
          f"Probability candy is Chocolate and Bar [P(A1,A3)] is {round((pA1andA3) * 100, 2)}%\n\n"
          f"Probability that candy is Caramel given the p. of Chocolate and Bar [P(A2|A1,A3)]"
          f" is {round((pA2_bar_A1andA3)*100,2)}%\n\n"
          f"Probability that candy is Chocolate and Bar given the p. of Caramel [P(A1,A3|A2)] "
          f"is {round((pA1andA3_bar_A2)*100,2)}%")

