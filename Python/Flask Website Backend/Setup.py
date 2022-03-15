
import sqlite3
import string, base64

import pandas as pd

import Encryption

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
    conn.execute('''DROP TABLE AGENTS''')
    # save changes
    conn.commit()
    print('Agents table dropped.')
except:
    print('Agents table did not exist')

####################################
# Create AGENTS Table in database  #
####################################
cur.execute('''CREATE TABLE AGENTS(
AgentId            INTEGER     PRIMARY KEY NOT NULL,
AgentName          TEXT                    NOT NULL,
AgentAlias         TEXT                    NOT NULL,
AgentSecurityLevel INTEGER                 NOT NULL,
LoginPassword      TEXT                    NOT NULL);
''')

###################
# Saving Database #
###################
conn.commit()
print('AGENTS Table created')

#######################################################################
# Inserting "Agents" to the "AGENTS" table. Information is encrypted  #
#######################################################################
# Princes Diana
valueAgentName = str(Encryption.cipher.encrypt(b'Princess Diana').decode("utf-8"))
valueAgentAlias = str(Encryption.cipher.encrypt(b'Lady Di').decode("utf-8"))
valueAgentSecurityLevel = 1
valueLoginPassword = str(Encryption.cipher.encrypt(b'test123').decode("utf-8"))
cur.execute('''INSERT INTO AGENTS (AgentName,AgentAlias,AgentSecurityLevel,LoginPassword)
                VALUES(?, ?, ?, ?) ''', (valueAgentName, valueAgentAlias, valueAgentSecurityLevel, valueLoginPassword))
conn.commit()

# Henry Thorgood
valueAgentName = str(Encryption.cipher.encrypt(b'Henry Thorgood').decode("utf-8"))
valueAgentAlias = str(Encryption.cipher.encrypt(b'Goody 2 shoes').decode("utf-8"))
valueAgentSecurityLevel = 3
valueLoginPassword = str(Encryption.cipher.encrypt(b'test123').decode("utf-8"))
cur.execute('''INSERT INTO AGENTS (AgentName,AgentAlias,AgentSecurityLevel, LoginPassword) VALUES(?, ?, ?, ?)''',
            (valueAgentName, valueAgentAlias, valueAgentSecurityLevel, valueLoginPassword))
conn.commit()

# Tina Fairchild
valueAgentName = str(Encryption.cipher.encrypt(b'Tina Fairchild').decode("utf-8"))
valueAgentAlias = str(Encryption.cipher.encrypt(b'Happy').decode("utf-8"))
valueAgentSecurityLevel = 1
valueLoginPassword = str(Encryption.cipher.encrypt(b'test123').decode("utf-8"))
cur.execute('''INSERT INTO AGENTS (AgentName,AgentAlias,AgentSecurityLevel, LoginPassword) VALUES(?, ? , ?, ? )''',
            (valueAgentName, valueAgentAlias, valueAgentSecurityLevel, valueLoginPassword))
conn.commit()

# Tom Smith
valueAgentName = str(Encryption.cipher.encrypt(b'Tom Smith').decode("utf-8"))
valueAgentAlias = str(Encryption.cipher.encrypt(b'Sleepy').decode("utf-8"))
valueAgentSecurityLevel = 1
valueLoginPassword = str(Encryption.cipher.encrypt(b'test987').decode("utf-8"))
cur.execute('''INSERT INTO AGENTS (AgentName,AgentAlias,AgentSecurityLevel, LoginPassword) VALUES(?, ? , ?, ? )''',
            (valueAgentName, valueAgentAlias, valueAgentSecurityLevel, valueLoginPassword))
conn.commit()

# Kim Lovegood
valueAgentName = str(Encryption.cipher.encrypt(b'Kim Lovegood').decode("utf-8"))
valueAgentAlias = str(Encryption.cipher.encrypt(b'Snoozy').decode("utf-8"))
valueAgentSecurityLevel = 2
valueLoginPassword = str(Encryption.cipher.encrypt(b'test987').decode("utf-8"))
cur.execute('''INSERT INTO AGENTS (AgentName,AgentAlias,AgentSecurityLevel, LoginPassword) VALUES(?, ? , ?, ? )''',
            (valueAgentName, valueAgentAlias, valueAgentSecurityLevel, valueLoginPassword))
conn.commit()

# Tim Harris
valueAgentName = str(Encryption.cipher.encrypt(b'Tim Harris').decode("utf-8"))
valueAgentAlias = str(Encryption.cipher.encrypt(b'Doc').decode("utf-8"))
valueAgentSecurityLevel = 3
valueLoginPassword = str(Encryption.cipher.encrypt(b'test987').decode("utf-8"))
cur.execute('''INSERT INTO AGENTS (AgentName,AgentAlias,AgentSecurityLevel, LoginPassword) VALUES(?, ? , ?, ? )''',
            (valueAgentName, valueAgentAlias, valueAgentSecurityLevel, valueLoginPassword))
conn.commit()


##########################################
# Printing the Encrypted Table of Agents #
##########################################
for row in cur.execute('SELECT * FROM AGENTS;'):
    print(row)

###################
# Saving Database #
###################
conn.commit()
print("Changes were saved.")

###########################################
# SecretAgents Database Connection Closed #
###########################################
conn.close()
print('AGENTS - Connection closed.')

##################################################
#  Creating Connection to Boss Messages Database #
##################################################
conn = sqlite3.connect('BossMessages.db')

######################################
# Creating Cursor to Execute Queries #
######################################
cur = conn.cursor()
print('\n')

################################
# Dropping table from database #
################################
try:
    conn.execute('''DROP TABLE MESSAGES''')
    # save changes
    conn.commit()
    print('MESSAGES table dropped.')
except:
    print('MESSAGES table did not exist')

##############################################################
# Create MESSAGES Table in database                          #
##############################################################
cur.execute('''CREATE TABLE MESSAGES(
MessageId       INTEGER     PRIMARY KEY NOT NULL,
AgentId         INTEGER                 NOT NULL,
Message         TEXT                    NOT NULL); 
             ''')

###################
# Saving Database #
###################
conn.commit()
print('MESSAGES Table created')

####################################################################################
# Inserting default messages to the "MESSAGES" table. Information is NOT encrypted #
####################################################################################
valueAgentId = 1
valueMessage = 'Testing 1 2 3 '
cur.execute('''INSERT INTO MESSAGES (AgentId,Message)
                VALUES(?, ?) ''', (valueAgentId, valueMessage))
conn.commit()

valueAgentId = 2
valueMessage = 'Testing 1 2 3 '
cur.execute('''INSERT INTO MESSAGES (AgentId,Message)
                VALUES(?, ?) ''', (valueAgentId, valueMessage))
conn.commit()

valueAgentId = 3
valueMessage = 'Drink more ovaltine'
cur.execute('''INSERT INTO MESSAGES (AgentId,Message)
                VALUES(?, ?) ''', (valueAgentId, valueMessage))
conn.commit()

valueAgentId = 2
valueMessage = 'The cat is orange'
cur.execute('''INSERT INTO MESSAGES (AgentId,Message)
                VALUES(?, ?) ''', (valueAgentId, valueMessage))
conn.commit()


valueAgentId = 1
valueMessage = 'The clock runs backwards'
cur.execute('''INSERT INTO MESSAGES (AgentId,Message)
                VALUES(?, ?) ''', (valueAgentId, valueMessage))
conn.commit()

valueAgentId = 3
valueMessage = 'Testing 1 2 3 '
cur.execute('''INSERT INTO MESSAGES (AgentId,Message)
                VALUES(?, ?) ''', (valueAgentId, valueMessage))
conn.commit()

###################
# Saving Database #
###################
conn.commit()
print("Changes were saved.")

################################
# Printing content of MESSAGES #
################################
for row in cur.execute('SELECT * FROM MESSAGES'):
    print(row)

##############################
# Database Connection Closed #
##############################
conn.close()
print('MESSAGES - Connection closed.')

print("This script has ended successfully")
