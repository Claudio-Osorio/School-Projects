"""
Name:                  Claudio Osorio
Date:                  08/30/2021
Assignment:            Module2: Secret Message Class
Due Date:              9/5/2021

About this project:   Creating a SecretMessage class that contains the following member variables:
AgentId (who sent the message), Message, PriorityLevel (priority level of the message sent).
The SecretMessage class has an accessor and mutator functions for each member variable.

Assumptions:
I assumed the initiator was to be left alone (blank values) so that I could demonstrate
the accessor/mutator implementation instead of doing a single liner as part of the initialization
Eg: ourAgentA = OurSecretMessage(7, "There is a known spy in the computer lab.", 1)


All the work below was performed by Claudio Osorio
"""

class OurSecretMessage(object):
    def __init__(self):
        self.agentID = 0
        self.message = ""
        self.priority = 0

    #################
    #   ACCESSORS   #
    #################
    def Get_Agent_ID(self):
        return self.agentID

    def Get_Message(self):
        return self.message

    def Get_Priority(self):
        return self.priority

    ##############
    #  MUTATORS  #
    ##############
    def Set_AgentID(self, agentID):
        self.agentID = agentID

    def Set_Message(self, message):
        self.message = message

    def Set_Priority(self, priority):
        self.priority = priority

print("Welcome to Claudio Osorio - Module 2 - \"Secret Message\" Program\n")

##########################################
# CREATING OBJECTS AND INITIALIZING THEM #
##########################################
ourAgentA = OurSecretMessage()
ourAgentA.Set_AgentID(7)
ourAgentA.Set_Message("There is a known spy in the computer lab.")
ourAgentA.Set_Priority(1)

ourAgentB = OurSecretMessage()
ourAgentB.Set_AgentID(5)
ourAgentB.Set_Message("There is a peron who is acting like a spy in the cafeteria.")
ourAgentB.Set_Priority(2)

ourAgentC = OurSecretMessage()
ourAgentC.Set_AgentID(2)
ourAgentC.Set_Message("There is an unknown peron in the lobby")
ourAgentC.Set_Priority(3)

##################################
# PRINTING 3 DIFFERENT INSTANCES #
##################################
print("Message 1:")
print("AgentID: ", ourAgentA.Get_Agent_ID())
print("Message: ", ourAgentA.Get_Message())
print("Priority Level: ", ourAgentA.Get_Priority(), "\n")

print("Message 2:")
print("AgentID: ", ourAgentB.Get_Agent_ID())
print("Message: ", ourAgentB.Get_Message())
print("Priority Level: ", ourAgentB.Get_Priority(), "\n")

print("Message 3:")
print("AgentID: ", ourAgentC.Get_Agent_ID())
print("Message: ", ourAgentC.Get_Message())
print("Priority Level: ", ourAgentC.Get_Priority(), "\n")

print("\nThe program has ended as expected.")
