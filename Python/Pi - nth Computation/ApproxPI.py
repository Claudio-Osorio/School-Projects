# Name: Claudio Osorio Date: 1-5-2022  Section: Module 1
# Assignment: Python Basics - Compute PI Due Date: 1-9-2022
# About this project: This is a python script that prompts the user to input a positive integer (aka n)
#   that is greater than 0, validates it and does not move forward until the user enters a positive integer
#   that is greater than 0 .
# All work below was performed by Claudio Osorio

import math


# Calculates individual serie used to determine the approximation of Pi
def CalculateSerie(serieIndex, denAdd, denAddPow):
    if serieIndex % 2 == 0:
        serie = float(-(1 / ((3 + denAdd) * pow(3, denAddPow))))
    else:
        serie = float(1 / ((3 + denAdd) * pow(3, denAddPow)))
    return serie

# Returns the sum of all the individual non constant series used to determine the approx. of pi
def Series(n):
    series = 0.0
    denAdd = 0
    denAddPow = 1
    for serieIndex in range(n):
        series = series + CalculateSerie(serieIndex, denAdd, denAddPow)
        denAdd = denAdd + 2
        denAddPow = denAddPow + 1
    return series

# Main Program that calculates PI approximated to the 'n' series.
if __name__ == '__main__':
    n = "-1"
    while not n.isnumeric() or int(n) <= 0:
        print("Please enter a positive integer \"n\" to approximate PI:")
        n = input()

    if int(n) == 1:
        pi = float(math.sqrt(12.0) * 1.0)
    else:
        pi = float(math.sqrt(12.0) * (1.0 + Series(int(n)-1)))

    print("PI: = {}".format(pi))

