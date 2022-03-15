"""
Name:                  Claudio Osorio
Date:                  09/07/2021
Assignment:            Module3: SQLite3 Database
Due Date:              9/12/2021

About this project:   Developing a database for a small scale real-world application using
third-party Python libraries discussed in the course. Solving a simple programming problem
based on various approaches of information management.

Assumptions:
The SQLite table is only created on the other script (1/2). The other script (1/2) will be
run at least once before running this script.

All the work below was performed by Claudio Osorio
Script File Number 2/2 (two out of two)
"""
import sqlite3
print ("Welcome to Claudio Osorio's SQLite Database Program (Part 2)\n")
#####################################
#  Creating Connection to Database  #
#####################################
conn = sqlite3.connect('SecretAgents.db')

######################################
# Creating Cursor to Execute Queries #
######################################
cur = conn.cursor()

######################################
# Control (reference) Database Table #
######################################
print("\nThis is what the untouched table looks like:")
for row in cur.execute('SELECT * FROM SECRETAGENTS;'):
    print(row)

########################################
# "Selecting data from a Single Table" #
########################################
print("\nShowing All Data Selected From a Single Table:")
print(cur.execute('SELECT * FROM SECRETAGENTS;').fetchall())

######################################
# Deleting Single Row From the Table #
######################################
cur.execute('''DELETE FROM SECRETAGENTS
               WHERE AgentId = 6;''')
conn.commit()

########################################
# Printing Table After Deletion of Row #
########################################
print("\nDisplaying table after deletion of row where AgentId = 6:")
for row in cur.execute('SELECT * FROM SECRETAGENTS;'):
    print(row)

####################
# Update Statement #
####################
conn.execute('''UPDATE SECRETAGENTS
                SET AgentAlias = 'Predator'
                WHERE AgentId = 2; ''')
conn.commit()

#####################################
# Printing Table After Alias Update #
#####################################
print("\nDisplaying table update \"Predator\" replaced single row AgentAlias:")
for row in cur.execute('SELECT * FROM SECRETAGENTS;'):
    print(row)

#########################
#  Column Manipulation  #
#########################
print("\nReturning Table After Selecting Columns \"AgentName\" and \"AgentAlias\"")
print(cur.execute('SELECT AgentName, AgentAlias FROM SECRETAGENTS;').fetchall())

######################
#  Row Manipulation  #
######################
print("\nReturning Rows After Selecting AgentId 3 and 4")
print(conn.execute('''SELECT * FROM SECRETAGENTS
                Where AgentId IN (3,4) ;''').fetchall())

###############################
# Row and Column Manipulation #
###############################
print("\nReturning Selected \"AgentAlias\" where AgentName is Princess Diana:")
print(conn.execute('''SELECT AgentAlias FROM SECRETAGENTS
                WHERE AgentName = "Princess Diana";''').fetchall())

#Closing Connection
conn.close()

print("This script has ended successfully")