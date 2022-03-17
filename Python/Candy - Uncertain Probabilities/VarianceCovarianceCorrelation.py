# Name: Claudio Osorio Date: 1-21-2022
# Section: Module 3
# Assignment: Variance, Covariance, and Correlation Python
# Due Date: 1-23-2022
# About this project: Calculating Variance, Covariance, and Correlation of a dataset.
# Assumptions: N/A
# All work below was performed by Claudio Osorio

# PLEASE NOTE:
# *The dataset being used is "candy-data.csv"

import pandas as pd
import scipy
from scipy import stats
import statistics

if __name__ == '__main__':
    print("Written by Claudio Osorio")
    file = 'candy-data.csv'
    df = pd.read_csv(file)

    df_A1 = df.filter(['chocolate'])
    df_A2 = df.filter(['fruity'])
    df_A3 = df.filter(['caramel'])

    # Finding Variance
    print("Variance: ")
    print("A1 aka Chocolate: ", df_A1.var())
    print("\nA2 aka Fruity: ", df_A2.var())
    print("\nA3 aka Caramel: ", df_A3.var())

    df_A1_and_A2 = df.filter(['chocolate','fruity'])
    df_A1_and_A3 = df.filter(['chocolate','caramel'])
    df_A2_and_A3 = df.filter(['fruity','caramel'])

    # Finding Covariance
    print("\nCovariance:")
    print("Chocolate and Fruity: \n", df_A1_and_A2.cov())
    print("\nChocolate and Caramel: \n", df_A1_and_A3.cov())
    print("\nFruity and Caramel: \n", df_A2_and_A3.cov())

    ## COVARIANCE RELATIONSHIP:
    # The covariance relationship between Chocolate[A1] and Fruity[A2] is small and negative.
    # Compare -0.185014 vs -0.185014 .Therefore there is little to none covariance between
    # both A1 and A2.

    # The covariance relationship between Chocolate[A1] and Caramel[A3] is small and positive.
    # Compare 0.046499 vs 0.046499 .Therefore there is little to none covariance
    # between both A1 and A3.

    # The covariance relationship between Fruity[A2] and Caramel[A3] is very small and negative.
    # Compare -0.062605 vs -0.062605. Therefore there is almost no covariance between A2 and A3.

    #Finding Correlation
    print("\nCorrelation:")
    print("Chocolate and Fruity: \n", df_A1_and_A2.corr())
    print("\nChocolate and Caramel: \n", df_A1_and_A3.corr())
    print("\nFruity and Caramel: \n", df_A2_and_A3.corr())

    ## CORRELATION RELATIONSHIP:
    # The correlation between A1 and A2 is -0.741721 which is closer to -1 than to 0.
    # Therefore the correlation relationship between Chocolate[A1] and Fruity[A2]
    # is negatively strong. For this reason we can say that if the candy competitor has
    # chocolate candy it is likely that it will NOT have fruity candy and vice versa.

    # Knowing that the correlation between Chocolate[A1] and Caramel[A3] is 0.249875 we
    # can say relationship between both is positively weak.  0.25 is closer to 0 than to 1.
    # Therefore there is little to no correlation.

    # Knowing that -0.335485 is closer to 0 than to -1 we can say that:
    # The correlation relationship between Fruity[A2] and Caramel[A3] is negatively weak.
    # Therefore there is little to no correlation.



