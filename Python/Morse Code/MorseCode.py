"""
Name:                  Claudio Osorio
Date:                  08/24/2021
Assignment:            Module1: Morse Code
Due Date:              8/29/2021

About this project:   Writing a python script that prompts the user to input a string,
validates that the string is not empty and does not only contain spaces, converts each
letter (aka the input letter) to the secret code output letter that corresponds to it
in the table above, and displays the result to the screen.

Assumptions:NA
All the work below was performed by Claudio Osorio
"""
print ("Welcome to the Morse Code Script by Claudio Osorio")
######################################
# DEFINING THE MORSE CODE DICTIONARY #
######################################
morseCodeDict = {"A": ".-", "B": "-...", "C": "-.-.", "D": "-..", "E": ".",
                 "F": "..-.", "G": "--.", "H": "....", "I": "..", "J": ".---", "K": "-.-",
                 "L": ".-..", "M": "--", "N": "-.", "O": "---", "P": ".--.", "Q": "--.-",
                 "R": ".-.", "S": "...", "T": "-", "U": "..-", "V": "...-", "W": ".--",
                 "X": "-..-", "Y": "-.--", "Z": "--.."}

###################################
# MAKING SURE THE STRING IS VALID #
###################################
userString =""
isAllSpaces = True
while len(userString) == 0 or isAllSpaces:
    print("Please enter a string: ")
    userString = input()
    for x in range(0, len(userString)):
        if userString[x] != ' ':
            isAllSpaces = False
            break
        else:
            print("\nSorry. Your string is not valid. Try again")
            break

print("You entered: ", userString)
#########################################################################
# MATCHING ALPHABETIC CHARACTERS AND PRINTING THE MORSE CODE EQUIVALENT #
#########################################################################
for eachLetter in range(0, len(userString)):
    if userString[eachLetter].isalpha():
        print(morseCodeDict[userString[eachLetter].upper()])
    else:
        print(userString[eachLetter])

print("Thanks for using my program. Have a nice day.")
