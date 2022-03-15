import hashlib
import hmac
import socketserver
import Encryption
import sqlite3
import sys


# HMAC Server TCP Handler
class MyHMACTCPHandler(socketserver.BaseRequestHandler):
    def handle(self):
        dataReceived = self.request.recv(1024).strip()
        messageEncrypted = dataReceived[:len(dataReceived) - 64]

        # Decrypting
        message = Encryption.cipher.decrypt(messageEncrypted)
        signature = dataReceived[-64:]

        # Extracting segments from the data
        segment = message.partition(" ")
        agentID = segment[0]
        data = segment[2]

        # Verify Authentication
        if self.verification(message, signature):
            print("{} sent message:".format(agentID))
            print(data)

            # Creating Connection to Boss Messages Database
            conn = sqlite3.connect('BossMessages.db')

            # Creating Cursor to Execute Queries #
            cur = conn.cursor()
            print('\n')

            # Inserting default messages to the "MESSAGES" table. Information is NOT encrypted #
            try:
                cur.execute('''INSERT INTO MESSAGES (AgentId,Message)
                                        VALUES(?, ?) ''', (agentID, data))
                conn.commit()
            except:
                print('MESSAGES table did not exist.'
                      '\nYou should have created a database first.'
                      '\nProgram will end now.')
                sys.exit()
        else:
            print("Unauthenticated message received! Be on alert! Watch out for bad guys!!!")

    # Authentication Process Verification
    def verification(self, messageReceived, signatureReceived):
        secretKey = b'1234'
        messageReceivedSignature = hmac.new(secretKey, bytes(messageReceived, 'utf-8'),
                                            digestmod=hashlib.sha3_512).digest()

        if messageReceivedSignature != signatureReceived:
            return False
        else:
            return True


if __name__ == "__main__":
    try:
        HOST, PORT = "localhost", 8888
        server = socketserver.TCPServer((HOST, PORT), MyHMACTCPHandler)
        server.serve_forever()
    except server.error as e:
        print("Error:", e)
        exit(1)
    finally:
        server.close()
