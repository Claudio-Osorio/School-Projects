# Name: Claudio Osorio Date: 2-2-2022
# Section: Module 5
# Assignment: Project Wrangling Data Python
# Due Date: 2-6-2022
# About this project: Cleaning datasets and preparing data for a presentation.
# Assumptions: N/A
# All code below was written by Claudio Osorio

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

"""
5 QUESTIONS THAT REQUIRE DATA ANALYSIS TO SOLVE:

1. From all the videos in the top 8 technology-related youtube channels, which are the 10 most liked videos?
2. From the top 8 youtube technology-related channels, which are the top 3 channels with greatest average of views?
3. How many kindle books reviews mention "love"? (By month of the year)
4. How many kindle books reviews mention "hate"? (By day of the month)
5. What is the distribution of chess players and their BLITZ elo rating? (By to year of birth)
"""

"""
DATASETS USED TO ANSWER EACH QUESTION:
Question #1
Dataset Name: "VideoStatistics.csv"
Source: https://www.kaggle.com/ashishmhatre927/top-tech-youtuber-video-statistics-data

Question #2
Dataset Name: "VideoStatistics.csv"
Source: https://www.kaggle.com/ashishmhatre927/top-tech-youtuber-video-statistics-data

Question #3
Dataset Name: "all_kindle_review.csv"
Source: https://www.kaggle.com/meetnagadia/amazon-kindle-book-review-for-sentiment-analysis

Question #4
Dataset Name: "all_kindle_review.csv"
Source: https://www.kaggle.com/meetnagadia/amazon-kindle-book-review-for-sentiment-analysis

Question #5
Dataset Name: "top_chess_players_aug_2020.csv"
Source: https://www.kaggle.com/vikasojha98/world-top-chess-players-august-2020
"""

"""
ATTRIBUTES USED FROM EACH DATASET TO ANSWER EACH QUESTION:
Question #1
- Video_id
- Video_Channel_title
- Stats_Like

Question #2
-Video_Channel_title
-Stats_view

Question #3 
reviewTime
reviewText

Question #4
reviewTime
reviewText

Question #5
Name        
Year_of_birth
Standard_Rating 
"""

if __name__ == '__main__':

    """ QUESTION 1 """
    file_top8channels = r"VideoStatistics.csv"
    df_top8channels = pd.read_csv(file_top8channels)

    # GRAPHS (BEFORE)
    # Box plot
    sns.boxplot(x=df_top8channels['Stats_Like'], data=df_top8channels)
    plt.show()

    # Scatter plot
    fig, ax = plt.subplots(figsize=(18, 10))
    ax.scatter(df_top8channels['Stats_Like'], df_top8channels['Video_Channel_title'])

    # x and y axis labels
    ax.set_xlabel('Likes')
    ax.set_ylabel('Channel')
    plt.show()

    # Extracting attributes needed
    # Renaming attributes for more clarity
    df_top8channels_pivot = df_top8channels[['Video_id', 'Video_Channel_title', 'Stats_Like']]
    df_top8channels_pivot = df_top8channels_pivot.rename(columns={'Video_id': 'Video'})
    df_top8channels_pivot = df_top8channels_pivot.rename(columns={'Video_Channel_title': 'Channel'})
    df_top8channels_pivot = df_top8channels_pivot.rename(columns={'Stats_Like': 'Likes'})

    # Replacing non available values to be equal to the mean.
    video_likes_mean =  df_top8channels_pivot['Likes'].mean()
    df_top8channels_pivot = df_top8channels_pivot.replace(to_replace=np.nan, value=video_likes_mean)

    # Generating full link for every youtube video
    youtube_header = 'https://youtube.com/watch?v='
    list_of_full_links = list()
    for i in range(len(df_top8channels_pivot)):
        list_of_full_links.append(youtube_header + str(df_top8channels_pivot.iloc[i, 0]))

    # Inserting a new attribute that contains all links
    df_top8channels_pivot.insert(3, 'Links', list_of_full_links )

    # Sorting all videos by Likes
    df_t8_sorted_by_likes = df_top8channels_pivot.sort_values('Likes', ascending=False)

    # Getting all possible channels
    list_of_channels = list()
    for each_channel in df_top8channels_pivot['Channel'].unique():
        list_of_channels.append(each_channel)

    print("*#*#*#**#*#*#*  QUESTION #1 ANSWER  *#*#*#**#*#*#*")
    # Displaying all possible channels
    print("CHANNELS: ")
    for each_channel in list_of_channels:
        print(f"{each_channel}")

    # Displaying top 10 videos
    pivot_top_10_videos = df_t8_sorted_by_likes[['Channel','Likes','Links']]
    print("\nTHE TOP 10 LIKED VIDEOS ARE:")
    print(pivot_top_10_videos.head(10))
    print("\n")


    # Dropping Outliers
    df_top8channels = df_top8channels[df_top8channels['Stats_Like'] > 0]
    df_top8channels = df_top8channels[df_top8channels['Stats_Like'] < 400]

    # GRAPHS (AFTER)
    # Box plot
    sns.boxplot(x=df_top8channels['Stats_Like'], data=df_top8channels)
    plt.show()

    # Scatter plot
    fig, ax = plt.subplots(figsize=(18, 10))
    ax.scatter(df_top8channels['Stats_Like'], df_top8channels['Video_Channel_title'])

    # x and y axis labels
    ax.set_xlabel('Likes')
    ax.set_ylabel('Channel')
    plt.show()




    """ QUESTION 2 """
    file_top8channels = r"VideoStatistics.csv"
    df_top8channels = pd.read_csv(file_top8channels)

    # GRAPHS (BEFORE)
    # Box plot
    sns.boxplot(x=df_top8channels['Stats_view'], data=df_top8channels)
    plt.show()

    # Scatter plot
    fig, ax = plt.subplots(figsize=(18, 10))
    ax.scatter(df_top8channels['Stats_view'], df_top8channels['Video_Channel_title'])

    # x and y axis labels
    ax.set_xlabel('Views')
    ax.set_ylabel('Channel')
    plt.show()

    # Extracting attributes needed and renaming them for more clarity
    df_top8_views_pivot = df_top8channels[['Video_Channel_title', 'Stats_view']]
    df_top8_views_pivot = df_top8_views_pivot.rename(columns={'Video_Channel_title': 'Channel'})
    df_top8_views_pivot = df_top8_views_pivot.rename(columns={'Stats_view': 'Views'})

    # Cleaning dataset by replacing non available values to be equal to the mean.
    video_views_mean = df_top8_views_pivot['Views'].mean()
    df_top8_views_pivot = df_top8_views_pivot.replace(to_replace=np.nan, value=video_views_mean)

    # Finding average views per channel and storing it in a list
    list_of_avg_views = list()
    for each_channel in list_of_channels:
        df_rows_specific = df_top8_views_pivot.query('Channel == @each_channel')
        channel_avg_views = df_rows_specific['Views'].mean()
        list_of_avg_views.append(channel_avg_views)

    # Making new dataframe that contains channels and their average views
    df_channels_and_avg_views = pd.DataFrame()
    df_channels_and_avg_views.insert(0, 'Channel', list_of_channels )
    df_channels_and_avg_views.insert(1, 'Avg_Views', list_of_avg_views )

    # Sorting channels by average views
    df_channels_and_avg_views = df_channels_and_avg_views.sort_values('Avg_Views', ascending=False)
    pivot_top_3_channels_by_avg_views = df_channels_and_avg_views.head(3)

    print("*#*#*#**#*#*#*  QUESTION #2 ANSWER  *#*#*#**#*#*#*")
    print("\nTOP 3 YOUTUBE TECH-RELATED CHANNELS BY AVERAGE VIEWS:")
    print(pivot_top_3_channels_by_avg_views)

    # Dropping Outliers
    df_top8channels = df_top8channels[df_top8channels['Stats_view'] > 0]
    df_top8channels = df_top8channels[df_top8channels['Stats_view'] < 10000]

    # GRAPHS (AFTER)
    # Box plot
    sns.boxplot(x=df_top8channels['Stats_view'], data=df_top8channels)
    plt.show()

    # Scatter plot
    fig, ax = plt.subplots(figsize=(18, 10))
    ax.scatter(df_top8channels['Stats_view'], df_top8channels['Video_Channel_title'])

    # x and y axis labels
    ax.set_xlabel('Views')
    ax.set_ylabel('Channel')
    plt.show()



    """ Question 3 """
    file_kr = r"all_kindle_review.csv"
    df_kindle = pd.read_csv(file_kr, encoding ="ISO-8859-1", engine='python')

    # Review Date to DateTime. When date conversion fails cell becomes NaT (not a time)
    # this NaT can be selected using null. isnull()
    print("Reviews by Date:")

    df_kindle['reviewTime'] = pd.to_datetime(df_kindle['reviewTime'], format='%m %d, %Y',errors='coerce')

    df_kindle['Year'] = df_kindle['reviewTime'].dt.year
    df_kindle['Month'] = df_kindle['reviewTime'].dt.month
    df_kindle['Day'] = df_kindle['reviewTime'].dt.day

    # Dropping rows that don't have texts or dates for the reviews
    df_kindle.dropna(subset=["reviewText"], inplace=True)
    print(df_kindle.head())

    # Extracting attributes needed and renaming them for more clarity
    df_kindle_compact = df_kindle[['reviewText', 'Month','Day','Year']]

    print("\nTOP 20 MOST COMMON REVIEWS:")
    print(*collections.Counter(df_kindle_compact['reviewText']).most_common(20), sep="\n")
    print("\n")

    # Parsing the dataframe using the word "love"
    print("Parsing the dataframe using the phrase \"love\":")

    df_kindle_compact_mention = df_kindle_compact[df_kindle_compact['reviewText'].str.contains('love', na=False)]
    print(df_kindle_compact_mention['reviewText'].head())
    print("\nThe amount of reviews with the phrase \"love\" in it are: ",len(df_kindle_compact_mention))


    # Count of reviews mentioning the phrase "love" (by month of the year)
    df_kindle_compact_mention_monthly = df_kindle_compact_mention['Month'].value_counts()
    df_kindle_compact_mention_monthly = df_kindle_compact_mention_monthly.sort_index()
    print("*#*#*#**#*#*#*  QUESTION #3 ANSWER  *#*#*#**#*#*#*")
    print("MONTHLY COUNT OF REVIEWS CONTAINING THE PHRASE: \"love\"")
    print(df_kindle_compact_mention_monthly)

    # Outliers are of no relevance to answer my question therefore I'm leaving it last.
    # The best thing I can do is remove wrong dates....
    # Dropping Outliers of years under 2006 because the reviews are too old...
    drop_values = np.where(df_kindle['Day'] > 31)
    df_kindle.drop(drop_values[0], inplace = True)
    drop_values = np.where(df_kindle['Month'] > 12)
    df_kindle.drop(drop_values[0], inplace = True)

    # GRAPHS (AFTER)
    # Box plot
    sns.boxplot(x=df_kindle['Day'], data=df_kindle)
    plt.show()

    # Scatter plot
    fig, ax = plt.subplots(figsize=(18, 10))
    ax.scatter(df_kindle['Day'], df_kindle['Month'])

    # x and y axis labels
    ax.set_xlabel('Day')
    ax.set_ylabel('Month')
    plt.show()


    """ QUESTION 4 """
    file_kr = r"all_kindle_review.csv"
    df_kindle = pd.read_csv(file_kr, encoding ="ISO-8859-1", engine='python')

    # Review Date to DateTime. When date conversion fails cell becomes NaT (not a time)
    # this NaT can be selected using null. isnull()
    print("Reviews by Date:")

    df_kindle['reviewTime'] = pd.to_datetime(df_kindle['reviewTime'], format='%m %d, %Y',errors='coerce')

    df_kindle['Year'] = df_kindle['reviewTime'].dt.year
    df_kindle['Month'] = df_kindle['reviewTime'].dt.month
    df_kindle['Day'] = df_kindle['reviewTime'].dt.day

    # GRAPHS (BEFORE)
    # Box plot
    sns.boxplot(x= df_kindle['Month'], data=df_kindle)
    plt.show()

    # Scatter plot
    fig, ax = plt.subplots(figsize=(18, 10))
    ax.scatter(df_kindle['Month'], df_kindle['Year'])

    # x and y axis labels
    ax.set_xlabel('Month')
    ax.set_ylabel('Year')
    plt.show()



    # Dropping rows that don't have texts or dates for the reviews
    df_kindle.dropna(subset=["reviewText"], inplace=True)
    print(df_kindle.head())

    # Extracting attributes needed and renaming them for more clarity
    df_kindle_compact = df_kindle[['reviewText', 'Month','Day','Year']]

    # Parsing the dataframe using the word "hate"
    print("Parsing the dataframe using the phrase \"hate\":")

    df_kindle_compact_mention = df_kindle_compact[df_kindle_compact['reviewText'].str.contains('hate', na=False)]
    print(df_kindle_compact_mention['reviewText'].head())
    print("\nThe amount of reviews with the phrase \"hate\" in it are: ",len(df_kindle_compact_mention))


    # Count of reviews mentioning the phrase "hate" (by month of the year)
    df_kindle_compact_mention_daily = df_kindle_compact_mention['Day'].value_counts()
    df_kindle_compact_mention_daily = df_kindle_compact_mention_daily.sort_index()
    print("*#*#*#**#*#*#*  QUESTION #4 ANSWER  *#*#*#**#*#*#*")
    print("DAILY COUNT OF REVIEWS CONTAINING THE PHRASE: \"hate\"")
    print(df_kindle_compact_mention_daily)

    # Outliers are of no relevance to answer my question therefore I'm leaving it last.
    # Dropping Outliers of years under 2006 because the reviews are too old...
    drop_values = np.where(df_kindle['Month'] > 12)
    df_kindle.drop(drop_values[0], inplace = True)
    drop_values = np.where(df_kindle['Year'] < 2006)
    df_kindle.drop(drop_values[0], inplace = True)

    # GRAPHS (AFTER)
    # Box plot
    sns.boxplot(x=df_kindle['Month'], data=df_kindle)
    plt.show()

    # Scatter plot
    fig, ax = plt.subplots(figsize=(18, 10))
    ax.scatter(df_kindle['Month'], df_kindle['Year'])

    # x and y axis labels
    ax.set_xlabel('Month')
    ax.set_ylabel('Year')
    plt.show()


    """ QUESTION 5 """
    file_chess_players = r"top_chess_players_aug_2020.csv"
    df_chess_players = pd.read_csv(file_chess_players, encoding ="ISO-8859-1", engine='python')

    print("*#*#*#**#*#*#*  QUESTION #5 ANSWER  *#*#*#**#*#*#*")
    # GRAPHS (BEFORE)
    # Box plot
    sns.boxplot(x= df_chess_players['Blitz_rating'], data=df_chess_players)
    plt.show()

    # Scatter plot
    fig, ax = plt.subplots(figsize=(18, 10))
    ax.scatter(df_chess_players['Year_of_birth'], df_chess_players['Blitz_rating'])

    # x and y axis labels
    ax.set_xlabel('Year of Birth')
    ax.set_ylabel('Blitz rating')
    plt.show()

    # Dropping Outliers
    drop_values = np.where(df_chess_players['Blitz_rating'] < 1000)
    df_chess_players.drop(drop_values[0], inplace = True)
    drop_values = np.where(df_chess_players['Blitz_rating'] > 2000)
    df_chess_players.drop(drop_values[0], inplace = True)

    # GRAPHS (AFTER)
    # Box Graph
    sns.boxplot(x= df_chess_players['Blitz_rating'], data=df_chess_players)
    plt.show()

    # Scatter plot
    fig, ax = plt.subplots(figsize=(18, 10))
    ax.scatter(df_chess_players['Year_of_birth'], df_chess_players['Blitz_rating'])

    # x and y axis labels
    ax.set_xlabel('Year of Birth')
    ax.set_ylabel('Blitz rating')
    plt.show()
