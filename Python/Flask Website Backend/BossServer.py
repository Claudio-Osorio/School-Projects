import socketserver
import Encryption
import sqlite3
import sys

######################
# Server TCP Handler #
######################
class MyTCPHandler(socketserver.BaseRequestHandler):
    def handle(self):
        dataReceived = self.request.recv(1024).strip()
        self.data = str(Encryption.cipher.decrypt(dataReceived))
        self.data = self.data.partition(" ")

        print("{} sent message:".format(self.data[0]))
        print(self.data[2])

        ##################################################
        #  Creating Connection to Boss Messages Database #
        ########################    ##########################
        conn = sqlite3.connect('BossMessages.db')

        ######################################
        # Creating Cursor to Execute Queries #
        ######################################
        cur = conn.cursor()
        print('\n')


        ####################################################################################
        # Inserting default messages to the "MESSAGES" table. Information is NOT encrypted #
        ####################################################################################
        valueAgentId = int(self.data[0])
        valueMessage = str(self.data[2])
        try:
            cur.execute('''INSERT INTO MESSAGES (AgentId,Message)
                            VALUES(?, ?) ''', (valueAgentId, valueMessage))
            conn.commit()
        except:
            print('MESSAGES table did not exist.'
                  '\nYou should have created a database first.'
                  '\nProgram will end now.')
            sys.exit()


if __name__ == "__main__":
    try:
        HOST, PORT = "localhost", 9999
        server = socketserver.TCPServer((HOST, PORT), MyTCPHandler)
        server.serve_forever()
    except server.error as e:
        print("Error:", e)
        exit(1)
    finally:
        server.close()
