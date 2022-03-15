"""
Name:                  Claudio Osorio
Date:                  11/02/2021

About this project:
-Apply parallel and distributed computing to computational problems and analyze
the scalability and efficiency of the solutions.
-Apply Python towards several contemporary programming requirements and techniques
involving secure, distributed, and parallel computing.

Assumptions:
-If the database files are not present then the script "Setup.py" needs to be run at least once.
(A database file needs to be generated before it can be used by the scripts).

All the work below was performed by Claudio Osorio
"""
from flask import Flask, render_template, request, session, flash, jsonify
import sqlite3 as sql
import os
import string
import base64
import Encryption
import pandas as pd
import socket
import hmac
import hashlib

app = Flask(__name__)

#######################
# Rendering home page #
#######################
@app.route('/')
def home():
    if not session.get('logged_in'):
        return render_template('login.html')
    else:
        return render_template('home.html', Username=session['name'])


####################
# Login Validation #
####################
@app.route('/login', methods=['POST', 'GET'])
def login():
    try:
        name = request.form['UserName']
        name = str(Encryption.cipher.encrypt(bytes(name, 'utf-8')).decode("utf-8"))
        password = request.form['Password']
        password = str(Encryption.cipher.encrypt(bytes(password, 'utf-8')).decode("utf-8"))

        with sql.connect('SecretAgents.db') as con:
            con.row_factory = sql.Row
            cur = con.cursor()

            sql_select_query = """SELECT * FROM AGENTS WHERE 
            AgentName = ? and LoginPassword = ?"""
            cur.execute(sql_select_query, (name, password))
            row = cur.fetchone();

            if row != None:
                session['logged_in'] = True
                session['name'] = str(Encryption.cipher.decrypt(name))
                session['SecLvl'] = int(row['AgentSecurityLevel'])
                flash('You were successfully logged in')
            else:
                session['logged_in'] = False
                flash('Invalid Username and/or Password')
    except:
        con.rollback()
        flash("Error with database operations")
    finally:
        con.close()
    return home()


################################
# Rendering page for new agent #
################################
@app.route('/enternew')
def new_agent():
    if not session.get('logged_in'):
        return render_template('login.html')
    elif session.get('SecLvl') == 1:
        return render_template('enternew.html')
    else:
        flash('Query Result: Page Not Found')
        return render_template('home.html')


##########################################################
# Obtaining input for new agent and validating it before #
# it can be written to the database                      #
##########################################################
@app.route('/addrec', methods=['POST', 'GET'])
def addrec():
    if request.method == 'POST':

        if not session.get('logged_in'):
            return render_template('login.html')
        elif session.get('SecLvl') == 1:
            try:
                aName = request.form['AgentName']
                aAlias = request.form['AgentAlias']
                aSLevel = request.form['SecurityLevel']
                aPass = request.form['Password']

                msg = ""
                msg1 = ""
                msg2 = ""
                msg3 = ""
                msg4 = ""

                errorFlag = False
                if aName == "" or aName.isspace():
                    msg1 = "You cannot enter in an empty name."
                    errorFlag = True

                if aAlias == "" or aAlias.isspace():
                    msg2 = "You cannot enter in an empty alias."
                    errorFlag = True

                range_1 = range(1, 10, 1)
                if int(aSLevel) not in range_1 or not aSLevel.isnumeric():
                    msg3 = "The security level must be a numeric value between 1 and 10."
                    errorFlag = True

                if aPass == "" or aPass.isspace():
                    msg4 = "You cannot enter in an empty password."
                    errorFlag = True

                if errorFlag == True:
                    raise ValueError("Data cannot be inserted to the table because some of input is invalid")
                with sql.connect('SecretAgents.db') as con:
                    cur = con.cursor()

                    # Encryption
                    aName = str(Encryption.cipher.encrypt(bytes(aName, 'utf-8')).decode("utf-8"))
                    aAlias = str(Encryption.cipher.encrypt(bytes(aAlias, 'utf-8')).decode("utf-8"))
                    # Security Level is not required to be encrypted.
                    aPass = str(Encryption.cipher.encrypt(bytes(aPass, 'utf-8')).decode("utf-8"))

                    cur.execute("INSERT INTO AGENTS (AgentName,AgentAlias,AgentSecurityLevel,LoginPassword)"
                                " VALUES (?,?,?,?)",
                                (aName, aAlias, aSLevel, aPass))
                    con.commit()
                    msg = "Agent successfully added"
            except:
                con.rollback()
                if msg == "":
                    msg = "Error during insert operation"

            finally:
                return render_template("result.html", msg=msg, msg1=msg1, msg2=msg2, msg3=msg3, msg4=msg4)
                con.close()
        else:
            flash('Query Result: Page not found')
            return render_template('login.html')


##############################################################################
# Sending Message to Boss Page, Message Encryption and submission via socket #
##############################################################################
@app.route('/sendMessageToBoss')
def sendMessageToBoss():
    if not session.get('logged_in'):
        return render_template('login.html')
    else:
        return render_template('SendMessageToBoss.html')


@app.route('/messageBoss', methods=['POST'])
def messageBoss():
    if not session.get('logged_in'):
        return render_template('login.html')
    else:
        if request.method == 'POST':
            try:
                agentMessage = request.form['message']

                if agentMessage.isspace() or agentMessage == "":
                    raise ValueError("Message Cannot be empty")

                # Encrypting message before it gets sent
                msgForServer = str(session.get('SecLvl')) + " " + agentMessage
                encryptedMessage = str(Encryption.cipher.encrypt(bytes(msgForServer, 'utf-8')).decode("utf-8"))
                HOST, PORT = "localhost", 9999
                sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

                # Connect to server and send data
                sock.connect((HOST, PORT))
                sock.sendall(bytes(encryptedMessage, "utf-8"))

                sock.close()
                msg = "Message successfully sent to boss"
            except ValueError:
                msg = "Message NOT sent. Message cannot be empty"
            except:
                msg = "Error - Message NOT sent to boss"
            finally:
                return render_template("result.html", msg=msg)


#######################################################
# Sending Authenticated and Encrypted Message to Boss #
#######################################################
@app.route('/sendAuthMessageToBoss')
def sendAuthMessageToBoss():
    if not session.get('logged_in'):
        return render_template('login.html')
    else:
        return render_template('SendAuthenticatedMessageToBoss.html')


@app.route('/authMessageBoss', methods=['POST'])
def authMessageBoss():
    if not session.get('logged_in'):
        return render_template('login.html')
    else:
        if request.method == 'POST':
            try:
                agentMessage = request.form['message']
                if agentMessage.isspace() or agentMessage == "":
                    raise ValueError("Message Cannot be empty")

                # agentId + message
                delimiter = " "
                msgForServer = str(str(session.get('SecLvl')) + delimiter + agentMessage)

                # Encrypting Message and Signature
                encryptedMessage = Encryption.cipher.encrypt(bytes(msgForServer, 'utf-8'))

                # Generating Authentication for agentId + delimiter + message
                secretKey = b'1234'
                messageSignature = hmac.new(secretKey, bytes(msgForServer, 'utf-8'),
                                            digestmod=hashlib.sha3_512).digest()
                message = encryptedMessage + messageSignature

                # Connect to server and send data
                HOST, PORT = "localhost", 8888
                sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
                sock.connect((HOST, PORT))
                sock.sendall(message)

                sock.close()
                msg = "Message successfully sent to boss"
            except ValueError:
                msg = "Message NOT sent. Message cannot be empty"
            except:
                msg = "Error - Message NOT sent to boss"
            finally:
                return render_template("result.html", msg=msg)


##############################################################################
# Printing to the list page a table with the contents stored in the database #
##############################################################################
@app.route('/list')
def list():
    if not session.get('logged_in'):
        return render_template('login.html')
    elif session.get('SecLvl') == 1 or session.get('SecLvl') == 2:
        con = sql.connect("SecretAgents.db")
        con.row_factory = sql.Row

        cur = con.cursor()
        cur.execute("SELECT * FROM AGENTS")

        cur.execute("SELECT AgentName, AgentAlias, AgentSecurityLevel, LoginPassword FROM AGENTS")
        df = pd.DataFrame(cur.fetchall(), columns=['Name', 'Alias', 'SecurityLevel', 'Password'])

        # Encryption
        index = 0
        for someName in df['Name']:
            someName = str(Encryption.cipher.decrypt(someName))
            df._set_value(index, 'Name', someName)
            index += 1

        index = 0
        for someAlias in df['Alias']:
            someAlias = str(Encryption.cipher.decrypt(someAlias))
            df._set_value(index, 'Alias', someAlias)
            index += 1

        index = 0
        for somePassword in df['Password']:
            somePassword = str(Encryption.cipher.decrypt(somePassword))
            df._set_value(index, 'Password', somePassword)
            index += 1

        con.close()
        return render_template("list.html", rows=df)
    else:
        flash('Query Result: Page Not Found')
        return render_template('home.html')


#######################################
# Logout function to log out the user #
#######################################
@app.route('/logout')
def logout():
    session['SecLvl'] = 0
    session['logged_in'] = False
    session['name'] = ""
    return home()


########################################################
# Running the program. (Also running it in debug mode) #
########################################################
if __name__ == '__main__':
    app.secret_key = os.urandom(12)
    app.run(debug=True)
