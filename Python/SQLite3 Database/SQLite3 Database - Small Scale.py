"""
Name:                  Claudio Osorio
Date:                  09/07/2021
Assignment:            Module3: SQLite3 Database
Due Date:              9/12/2021

About this project:   Developing a database for a small scale real-world application using
third-party Python libraries discussed in the course. Solving a simple programming problem
based on various approaches of information management.

Assumptions:
The SQLite table is only created on this script. This script will be run at least once
before the other script. The 2nd script (2/2) needs to see the table created on this script

All the work below was performed by Claudio Osorio
Script File Number 1/2 (one out of two)
"""
import sqlite3

print ("Welcome to Claudio Osorio's SQLite Database Program (Part 1)\n")
#####################################
#  Creating Connection to Database  #
#####################################
conn = sqlite3.connect('SecretAgents.db')

######################################
# Creating Cursor to Execute Queries #
######################################
cur = conn.cursor()

################################
# Dropping table from database #
################################
try:
    conn.execute('''DROP TABLE SECRETAGENTS''')
    # save changes
    conn.commit()
    print('Agents table dropped.')
except:
    print('Agents table did not exist')

##############################################################
# Create Table in database                                   #
# Note: AgentId is "TEXT" to prevent agent 000 to show as 0  #
##############################################################
cur.execute('''CREATE TABLE SECRETAGENTS(
AgentId            TEXT     PRIMARY KEY NOT NULL,
AgentName          TEXT                 NOT NULL,
AgentAlias         TEXT                 NOT NULL,
AgentSecurityLevel INTEGER              NOT NULL,
LoginPassword      TEXT                 NOT NULL);
''')

###################
# Saving Database #
###################
conn.commit()
print('SecretAgents Table created')

##################################################
# Inserting "Agents" to the "SECRETAGENTS" table #
##################################################
cur.execute('''INSERT INTO SECRETAGENTS VALUES (1, 'Princess Diana', 'Lady Di', 1, 'test123')''')
cur.execute('''INSERT INTO SECRETAGENTS VALUES (2, 'Henry Thorgood', 'Goody 2 shoes', 3, 'test123')''')
cur.execute('''INSERT INTO SECRETAGENTS VALUES (3, 'Tina Fairchild', 'Happy', 1, 'test123')''')
cur.execute('''INSERT INTO SECRETAGENTS VALUES (4, 'Tom Smith', 'Sleepy', 1, 'test987')''')
cur.execute('''INSERT INTO SECRETAGENTS VALUES (5, 'Kim Lovegood', 'Snoozy', 2, 'test987')''')
cur.execute('''INSERT INTO SECRETAGENTS VALUES (6, 'Tim Harris', 'Doc', 3, 'test987')''')

###################
# Saving Database #
###################
conn.commit()
print("Changes were saved.")

#########################
# Iterate Over The Rows #
#########################
for row in cur.execute('SELECT * FROM SECRETAGENTS;'):
    print(row)

##############################
# Database Connection Closed #
##############################
conn.close()
print('Connection closed.')

print("This script has ended successfully")
