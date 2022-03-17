# Name: Claudio Osorio
# Date: 3-11-2022
# Section: Module 9
# Assignment: BayesNet
# Due Date: 3-13-2022
# About this project: Practicing BayesNet
# Assumptions: N/A
# All work below was performed by Claudio Osorio.
# NOTE:
# 1.- I'm assuming only the responses "Very favorably" are the ones that imply "Liking" a character.
# 2.- I'm allowing some NaN values to be present in the rows of the DF as long as the values in the subsets
# that I'm working on are not incomplete. In other words, I choose to use all the rows that have values useful
# to me.

# Dataset Used: StarWars.xlsx

import pandas as pd
import scipy
from scipy import stats
import statistics
from BayesNet import *

if __name__ == '__main__':
    T, F = True, False

    # Reading CSV file
    file = r"StarWars.xlsx"
    df = pd.read_excel(file)


    # NOTE: This data set was partially pre-cleaned to improve naming
    # and descriptions before importing it to dataframe to facilitate the work.

    # Cleaning DF
    # Dropping responses that are incomplete or had no answers.
    # *Only leaves responses of people who have watched all the movies and answered every field
    df.dropna(subset=['Gender',
                      'Expanded_Universe_Fan',
                      'Rate_Yoda',
                      'Rate_Princess_Leia'], inplace=True)

    #### Female and Not Female. Count and Probabilities ###
    dfFemale = df.query('Gender == "Female"')
    amtFemale = dfFemale.shape[0]

    dfNotFemale = df.query('Gender != "Female"')
    amtNotFemale = dfNotFemale.shape[0]

    numRows = df.shape[0]

    # Probability of Female
    pFemale = amtFemale / numRows

    # Probability of Not Female
    pNotFemale = amtNotFemale / numRows

    #### Likes Star Wars Expanded Universe Conditional Probabilities ###

    #p(U|F)
    df_U_F = df.query('Expanded_Universe_Fan == "Yes" and Gender == "Female"')
    p_U_F = (df_U_F.shape[0] / numRows) / pFemale

    #p(-U|F)
    df_notU_F = df.query('Expanded_Universe_Fan != "Yes" and Gender == "Female"')
    p_notU_F = (df_notU_F.shape[0] / numRows) / pFemale

    #p(U|-F)
    df_U_notF = df.query('Expanded_Universe_Fan == "Yes" and Gender != "Female"')
    p_U_notF = (df_U_notF.shape[0] / numRows) / pNotFemale

    #p(-U|-F)
    df_notU_notF = df.query('Expanded_Universe_Fan != "Yes" and Gender != "Female"')
    p_notU_notF = (df_notU_notF.shape[0] / numRows) / pNotFemale


    # Defining Liking and Not liking Universe Expansion:
    df_ExpUniverse = df.query('Expanded_Universe_Fan == "Yes"')
    pExpUniverse = df_ExpUniverse.shape[0] / numRows

    df_NotExpUniverse = df.query('Expanded_Universe_Fan != "Yes"')
    pNotExpUniverse = df_NotExpUniverse.shape[0] / numRows

    #### Likes Princess Leia Conditional Probabilities ###

    # p(L|U)
    df_L_U = df.query('Rate_Princess_Leia == "Very favorably" and Expanded_Universe_Fan == "Yes"')
    p_L_U = (df_L_U.shape[0] / df.shape[0]) / pExpUniverse

    # p(-L|U)
    df_notL_U = df.query('Rate_Princess_Leia != "Very favorably" and Expanded_Universe_Fan == "Yes"')
    p_notL_U = (df_notL_U.shape[0] / df.shape[0]) / pExpUniverse

    # p(L|-U)
    df_L_notU = df.query('Rate_Princess_Leia == "Very favorably" and Expanded_Universe_Fan != "Yes"')
    p_L_notU = (df_L_notU.shape[0] / df.shape[0]) / pNotExpUniverse

    # p(-L|-U)
    df_notL_notU = df.query('Rate_Princess_Leia != "Very favorably" and Expanded_Universe_Fan != "Yes"')
    p_notL_notU = (df_notL_notU.shape[0] / df.shape[0]) / pNotExpUniverse

    #### Likes Yoda Conditional Probabilities ###
    # p(Y|U)
    df_Y_U = df.query('Rate_Yoda == "Very favorably" and Expanded_Universe_Fan == "Yes"')
    p_Y_U = (df_Y_U.shape[0] / df.shape[0]) / pExpUniverse

    # p(-Y|U)
    df_notY_U = df.query('Rate_Yoda != "Very favorably" and Expanded_Universe_Fan == "Yes"')
    p_notY_U = (df_notY_U.shape[0] / df.shape[0]) / pExpUniverse

    # p(Y|-U)
    df_Y_notU = df.query('Rate_Yoda == "Very favorably" and Expanded_Universe_Fan != "Yes"')
    p_Y_notU = (df_Y_notU.shape[0] / df.shape[0]) / pNotExpUniverse

    # p(-Y|-U)
    df_notY_notU = df.query('Rate_Yoda != "Very favorably" and Expanded_Universe_Fan != "Yes"')
    p_notY_notU = (df_notY_notU.shape[0] / df.shape[0]) / pNotExpUniverse


    print(f"\nDataset: StarWars.xlsx\n"
          f"\n\t\tACCURATE SUMMARY without ENUMERATION ASK"
          f"\nNumber of rows: {df.shape[0]}\n"
          f"Number of columns: {df.shape[1]}\n"
          f"Name of columns: {df.columns}\n"
          f"\nFemale Count: F  {amtFemale}\n"
          f"Not Female Count: -F   {amtNotFemale}\n"
          f"\nProbability of being Female: p(F)  {pFemale}\n"
          f"Probability of NOT being a Female: p(-F)   {pNotFemale}\n"
          
          f"\nProbability of Liking StarWars Universe Given it's a Female: p(U|F)    {p_U_F}\n"
          f"Probability of NOT Liking StarWars Universe Given it's a Female: p(-U|F)     {p_notU_F}\n"
          f"Probability of Liking StarWars Universe Given it's NOT a Female: p(U|-F)    {p_U_notF}\n"
          f"Probability of NOT Liking StarWars Universe Given it's NOT a Female: p(-U|-F)      {p_notU_notF}\n"
          
          f"\nProbability of liking Princess Leia Given Female Likes Exp. Universe: p(L|U)   {p_L_U}\n"
          f"Probability of NOT liking Princess Leia Given Female Likes Exp. Universe: p(-L|U)   {p_notL_U}\n"
          f"Probability of liking Princess Leia Given Female does NOT Like Exp. Universe: p(L|-U)   {p_L_notU}\n"
          f"Probability of NOT liking Princess Leia Given Female does NOT Like Universe: p(-L|-U)   {p_notL_notU}\n"

          f"\nProbability of liking Yoda Given Female Likes Exp. Universe: p(Y|U)   {p_Y_U}\n"
          f"Probability of NOT liking Yoda Given Female Likes Exp. Universe: p(-Y|U)   {p_notY_U}\n"
          f"Probability of liking Yoda Given Female doesnt Likes Exp. Universe: p(Y|-U)   {p_Y_notU}\n"
          f"Probability of NOT liking Yoda Given Female Likes Exp. Universe: p(-Y|-U)   {p_notY_notU}\n")

    print ("################## S O L U T I O N S ##################")
    print("\nProblem 1 (graph and attributes listed on paper) pdf attached...")

    # Problem 2.  p(U|F) ... for manually solving p(U,F)/p(F)
    problem2_U_F = df_U_F.shape[0]  #  U,F
    print("\nProblem 2 Data (solved on paper):"
          "\nProbability of Expanded Universe (U) Given Female (F).      p(U|F)")

    print(f"\nProblem 2 DATA Needed to solve by hand:\n"
          f"Count: U,F  = {problem2_U_F}\n"
          f"Female Count = {amtFemale}\n"
          f"Total Rows = {numRows}\n")
    print("* My results on paper are: p(U|F):  T = 0.17, end F is implied 1-0.17 = 0.83")

    percentLikes_ExpandedUniverse_Given_Female = p_U_F
    percentLikes_ExpandedUniverse_Given_NOTFemale = p_U_notF
    percentLikes_PrincessLeia_Given_Likes_ExpandedUniverse = p_L_U
    percentLikes_PrincessLeia_Given_DoesNOTLike_ExpandedUniverse = p_notL_U
    percentLikes_Yoda_Given_Likes_ExpandedUniverse = p_Y_U
    percentLikes_Yoda_Given_DoesNOTLike_ExpandedUniverse = p_Y_notU

    # BAYESNET
    StarWars = BayesNet([
        ('Female', '', pFemale),

        ('Universe', 'Female',
        {(T): percentLikes_ExpandedUniverse_Given_Female,
        (F): percentLikes_ExpandedUniverse_Given_NOTFemale}),

        ('Leia', 'Universe',
        {(T): percentLikes_PrincessLeia_Given_Likes_ExpandedUniverse,
        (F): percentLikes_PrincessLeia_Given_DoesNOTLike_ExpandedUniverse}),

        ('Yoda','Universe',
        {(T): percentLikes_Yoda_Given_Likes_ExpandedUniverse,
        (F): percentLikes_Yoda_Given_DoesNOTLike_ExpandedUniverse})
                                            ])
    print("Problem 4")
    print("USING BAYES - ENUMERATION:")
    print("Finding Universe Given Female = T   ( p(U|F)", enumeration_ask(
        'Universe', dict(Female=T),
        StarWars).show_approx())



    # Problem 5.  p(L|U) ... for manually solving p(L,U)/p(U)
    problem5_L_U = df_L_U.shape[0]  #  L,U
    problem5_ExpandedUniverse_count = df_ExpUniverse.shape[0]
    print("\nProblem 5"
          "\nData (solved on paper):"
          "\nProbability of Liking Princess Leia Given Expanded Universe (U).      p(L|U)")

    print(f"DATA Needed to solve by hand:"
      f"Count: L,U  = {problem5_L_U}\n"
      f"Likes Expanded Universe Count = {problem5_ExpandedUniverse_count}\n"
      f"Total Rows = {numRows}\n")

    print("* My results on paper are: p(L|U):  T = 0.71, end F is implied 1-0.71 = 0.29\n"
          "This was rounded to 2 decimal places. Therefore results match.")
    print("Problem 6")
    print("USING BAYES - ENUMERATION:")
    print("Finding Likes Princess Leia Given Universe = T   ( p(L|U)", enumeration_ask(
        'Leia', dict(Universe=T),
        StarWars).show_approx())


