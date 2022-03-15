        ############################################################
        #                      Assignment#6                        #
        #               Created by Claudio Osorio                  #
        #    Disclaimer: This Program may contain small portions   #
        #  of code based on Dr. Gaitros class lectures or videos.  #
        ############################################################
                .data
INTRODUCTION1:	.asciiz "############################################"
INTRODUCTION2:	.asciiz "\n#           Name: Claudio Osorio           #"
INTRODUCTION3:	.asciiz "\n#           Class: CDA 3100                #"
INTRODUCTION4:	.asciiz "\n#       Assingment #6: TIC-TAC-TOE         #"
INTRODUCTION5:	.asciiz "\n############################################\n"
INTRO:          .asciiz "\nWelcome to Tic-Tac-Toe\n"
INTROPOS:       .asciiz "\n1|2|3\n-----\n4|5|6\n-----\n7|8|9\n"
P1INPUT:        .asciiz "\nPlayer 1 enter a position:"
P2INPUT:      	.asciiz "\nPlayer 2 enter a position:"
VALUES:         .asciiz "0123456789"#positions 0123456789
DASHES:         .asciiz "\n-----\n"
WINNERMSG:      .asciiz "\nThe winner is "
TIEMSG:         .asciiz "\nTIE Game"
BADINPUT:       .asciiz "\nYour input is not valid. Enter a number from 1 to 9: "
EOL:            .byte '\n'
BAR:            .byte '|'
X:              .byte 'X'
O:              .byte 'O'
                .text
                .globl main

main:
        #=#=#=##=#=#=##=#=#=#INTRODUCTION#=#=#=##=#=#=##=#=#=##=#=#=#=#=#=#=#=#=#=#=#=

        #Printing String 1
        li              $v0,4                 # Set syscall to print a string
        la              $a0,INTRODUCTION1     # Specify which string
        syscall                               # Execute
        #Printing String 2
        li              $v0,4                 # Set syscall to print a string
        la              $a0,INTRODUCTION2     # Specify which string
        syscall                               # Execute
        #Printing String 3
        li              $v0,4                 # Set syscall to print a string
        la              $a0,INTRODUCTION3     # Specify which string
        syscall                               # Execute
        #Printing String 4
        li              $v0,4                 # Set syscall to print a string
        la              $a0,INTRODUCTION4     # Specify which string
        syscall                               # Execute
        #Printing String 5
        li              $v0,4                 # Set syscall to print a string
        la              $a0,INTRODUCTION5     # Specify which string
        syscall                               # Execute

        #Showing Welcome Msg
        li              $v0,4                 # Set syscall to print a string
        la              $a0,INTRO             # Specify which string
        syscall                               # Execute
        #=#=#=##=#=#=##=#=#=# SHOWING POSITIONS #=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=
        #Positions Msg & Graph
        #Showing DEMO POSITIONS
        li              $v0,4                 # Set syscall to print a string
        la              $a0,INTROPOS          # Specify which string
        syscall                               # Execute

        #=#=#=##=#=#=##=#=#=#    GAME BEGINS  =##=#=#=##=#=#=##=#=#=#=#=#=#=#=#=#
        #=#=#=##=#=#=##=#=#=# MOVE 1 - PLAYER 1 #=#=#=##=#=#=##=#=#=##=#=#=#=#=#

        #Turn for player 1
        addiu           $sp, $sp, -4          # Get stack space
        sw              $ra, 4($sp)           # Store the return register
        jal             player1input          # Get player 1 input
        lw              $ra, 4($sp)           # Restore the return register
        addiu           $sp, $sp, 4           # Return the stack space
        lb              $t0,X                 # Load player "X"
        sb              $t0,0($v0)            # Set the "X" to the board

        #Print the board
        addiu           $sp, $sp, -4          # Get  stack space
        sw              $ra, 4($sp)           # Store the return register
        jal             BOARD                 # Go to print the board
        lw              $ra, 4 ($sp)          # Restore the return register
        addiu           $sp, $sp, 4           # Return the stack space

        #=#=#=##=#=#=##=#=#=# MOVE 1 - PLAYER 2 #=#=#=##=#=#=##=#=#=##=#=#=#=#=#

        #Turn for player 2
        addiu           $sp, $sp, -4          # Get stack space
        sw              $ra, 4($sp)           # Store the return register
        jal             player2input          # Get player 2 input
        lw              $ra, 4($sp)           # Restore the return register
        addiu           $sp, $sp, 4           # Return the stack space
        lb              $t0,O                 # Load player "O"
        sb              $t0,0($v0)            # Set the "O" to the board

        #Print the board
        addiu           $sp, $sp, -4          # Get  stack space
        sw              $ra, 4($sp)           # Store the return register
        jal             BOARD                 # Go to print the board
        lw              $ra, 4 ($sp)          # Restore the return register
        addiu           $sp, $sp, 4           # Return the stack space

        #=#=#=##=#=#=##=#=#=# MOVE 2 - PLAYER 1 #=#=#=##=#=#=##=#=#=##=#=#=#=#=#

        #Turn for player 1
        addiu           $sp, $sp, -4          # Get stack space
        sw              $ra, 4($sp)           # Store the return register
        jal             player1input          # Get player 1 input
        lw              $ra, 4($sp)           # Restore the return register
        addiu           $sp, $sp, 4           # Return the stack space
        lb              $t0,X                 # Load player "X"
        sb              $t0,0($v0)            # Set the "X" to the board

        #Print the board
        addiu           $sp, $sp, -4          # Get  stack space
        sw              $ra, 4($sp)           # Store the return register
        jal             BOARD                 # Go to print the board
        lw              $ra, 4 ($sp)          # Restore the return register
        addiu           $sp, $sp, 4           # Return the stack space

        #=#=#=##=#=#=##=#=#=# MOVE 2 - PLAYER 2 #=#=#=##=#=#=##=#=#=##=#=#=#=#=#
        #Turn for player 2
        addiu           $sp, $sp, -4          # Get stack space
        sw              $ra, 4($sp)           # Store the return register
        jal             player2input          # Get player 2 input
        lw              $ra, 4($sp)           # Restore the return register
        addiu           $sp, $sp, 4           # Return the stack space
        lb              $t0,O                 # Load player "O"
        sb              $t0,0($v0)            # Set the "O" to the board

        #Print the board
        addiu           $sp, $sp, -4          # Get  stack space
        sw              $ra, 4($sp)           # Store the return register
        jal             BOARD                 # Go to print the board
        lw              $ra, 4 ($sp)          # Restore the return register
        addiu           $sp, $sp, 4           # Return the stack space

        #=#=#=##=#=#=##=#=#=# MOVE 3 - PLAYER 1 #=#=#=##=#=#=##=#=#=##=#=#=#=#=#

        #Turn for player 1
        addiu           $sp, $sp, -4          # Get stack space
        sw              $ra, 4($sp)           # Store the return register
        jal             player1input          # Get player 1 input
        lw              $ra, 4($sp)           # Restore the return register
        addiu           $sp, $sp, 4           # Return the stack space
        lb              $t0,X                 # Load player "X"
        sb              $t0,0($v0)            # Set the "X" to the board

        #Print the board
        addiu           $sp, $sp, -4          # Get  stack space
        sw              $ra, 4($sp)           # Store the return register
        jal             BOARD                 # Go to print the board
        lw              $ra, 4 ($sp)          # Restore the return register
        addiu           $sp, $sp, 4           # Return the stack space

        #=#=#=##=#=#=##= CHECK IF THERE IS A WINNER #=##=#=#=##=#=#=##=#=#=#=#=#
        addiu           $sp,$sp,-4            # Get some Stack space
        sw              $ra,4($sp)            # Store the return register
        jal             WIN                   # Go to check if there is a winner
        lw              $ra,4($sp)            # Restore the retun register
        addiu           $sp,$sp,4             # Restore the stack space
        bnez            $v0,W                 # If the return value is zero then
                                              # there is a winner

        #=#=#=##=#=#=##=#=#=# MOVE 3 - PLAYER 2 #=#=#=##=#=#=##=#=#=##=#=#=#=#=#
        #Turn for player 2
        addiu           $sp, $sp, -4          # Get stack space
        sw              $ra, 4($sp)           # Store the return register
        jal             player2input          # Get player 2 input
        lw              $ra, 4($sp)           # Restore the return register
        addiu           $sp, $sp, 4           # Return the stack space
        lb              $t0,O                 # Load player "O"
        sb              $t0,0($v0)            # Set the "O" to the board

        #Print the board
        addiu           $sp, $sp, -4          # Get  stack space
        sw              $ra, 4($sp)           # Store the return register
        jal             BOARD                 # Go to print the board
        lw              $ra, 4 ($sp)          # Restore the return register
        addiu           $sp, $sp, 4           # Return the stack space

        #=#=#=##=#=#=##= CHECK IF THERE IS A WINNER #=##=#=#=##=#=#=##=#=#=#=#=#
        addiu           $sp,$sp,-4            # Get some Stack space
        sw              $ra,4($sp)            # Store the return register
        jal             WIN                   # Go to check if there is a winner
        lw              $ra,4($sp)            # Restore the retun register
        addiu           $sp,$sp,4             # Restore the stack space
        bnez            $v0,W                 # If the return value is zero then
                                              # there is a winner                  # Go to check if there is a winner
        #=#=#=##=#=#=##=#=#=# MOVE 4 - PLAYER 1 #=#=#=##=#=#=##=#=#=##=#=#=#=#=#
        #Turn for player 1
        addiu           $sp, $sp, -4          # Get stack space
        sw              $ra, 4($sp)           # Store the return register
        jal             player1input          # Get player 1 input
        lw              $ra, 4($sp)           # Restore the return register
        addiu           $sp, $sp, 4           # Return the stack space
        lb              $t0,X                 # Load player "X"
        sb              $t0,0($v0)            # Set the "X" to the board

        #Print the board
        addiu           $sp, $sp, -4          # Get  stack space
        sw              $ra, 4($sp)           # Store the return register
        jal             BOARD                 # Go to print the board
        lw              $ra, 4 ($sp)          # Restore the return register
        addiu           $sp, $sp, 4           # Return the stack space

        #=#=#=##=#=#=##= CHECK IF THERE IS A WINNER #=##=#=#=##=#=#=##=#=#=#=#=#
        addiu           $sp,$sp,-4            # Get some Stack space
        sw              $ra,4($sp)            # Store the return register
        jal             WIN                   # Go to check if there is a winner
        lw              $ra,4($sp)            # Restore the retun register
        addiu           $sp,$sp,4             # Restore the stack space
        bnez            $v0,W                 # If the return value is zero then
                                              # there is a winner                # Go to check if there is a winner
        #=#=#=##=#=#=##=#=#=# MOVE 4 - PLAYER 2 #=#=#=##=#=#=##=#=#=##=#=#=#=#=#
        #Turn for player 2
        addiu           $sp, $sp, -4          # Get stack space
        sw              $ra, 4($sp)           # Store the return register
        jal             player2input          # Get player 2 input
        lw              $ra, 4($sp)           # Restore the return register
        addiu           $sp, $sp, 4           # Return the stack space
        lb              $t0,O                 # Load player "O"
        sb              $t0,0($v0)            # Set the "O" to the board

        #Print the board
        addiu           $sp, $sp, -4          # Get  stack space
        sw              $ra, 4($sp)           # Store the return register
        jal             BOARD                 # Go to print the board
        lw              $ra, 4 ($sp)          # Restore the return register
        addiu           $sp, $sp, 4           # Return the stack space

        #=#=#=##=#=#=##= CHECK IF THERE IS A WINNER #=##=#=#=##=#=#=##=#=#=#=#=#
        addiu           $sp,$sp,-4            # Get some Stack space
        sw              $ra,4($sp)            # Store the return register
        jal             WIN                   # Go to check if there is a winner
        lw              $ra,4($sp)            # Restore the retun register
        addiu           $sp,$sp,4             # Restore the stack space
        bnez            $v0,W                 # If the return value is zero then
                                              # there is a winner

        #=#=#=##=#=#=##=#=#=# MOVE 5 - PLAYER 1 #=#=#=##=#=#=##=#=#=##=#=#=#=#=#

        #Turn for player 1
        addiu           $sp, $sp, -4          # Get stack space
        sw              $ra, 4($sp)           # Store the return register
        jal             player1input          # Get player 1 input
        lw              $ra, 4($sp)           # Restore the return register
        addiu           $sp, $sp, 4           # Return the stack space
        lb              $t0,X                 # Load player "X"
        sb              $t0,0($v0)            # Set the "X" to the board

        #Print the board
        addiu           $sp, $sp, -4          # Get  stack space
        sw              $ra, 4($sp)           # Store the return register
        jal             BOARD                 # Go to print the board
        lw              $ra, 4 ($sp)          # Restore the return register
        addiu           $sp, $sp, 4           # Return the stack space

        #=#=#=##=#=#=##= CHECK IF THERE IS A WINNER #=##=#=#=##=#=#=##=#=#=#=#=#
        addiu           $sp,$sp,-4            # Get some Stack space
        sw              $ra,4($sp)            # Store the return register
        jal             WIN                   # Go to check if there is a winner
        lw              $ra,4($sp)            # Restore the retun register
        addiu           $sp,$sp,4             # Restore the stack space
        bnez            $v0,W                 # If the return value is zero then
                                              # there is a winner
        #=#=#=##=#=#=# IF NO WINNER THE GAME IS TIED #=#=#=#=##=#=#=##=#=#=#=#=#
        #DISPLAYS GAME IS TIE
T:
        li              $v0,4                 # Set syscall to print a string
        la              $a0,TIEMSG            # Specify which string
        syscall                               # Execute
        jr              $ra                   # Exit Program
################################################################################

#=#=#=#=#=#=#=#=#=#= FINDS THE WINNER AND DISPLAYS IT #=#=#=#=#=#=#=#=#=#
W:
        move            $t0,$v0               # Save the winning character
        li              $v0,4                 # Set syscall to print a string
        la              $a0,WINNERMSG         # Load the string "The winner is"
        syscall
        move            $a0,$t0               # Winning char to $a0
        li              $v0,11                # Printing a byte
        syscall
        lb              $a0,EOL               # Newline
        syscall

        jr              $ra                   #Exit Program

#=#=#=#=#=#=#=#=#=#=#=#=#=#    PRINTS THE BOARD  #=#=#=#=#=#=#=#=#=#=#=#=#
BOARD:
        #Top 3 values
        la              $t0,VALUES            # Load the board values 0123456789
        li              $v0,11                # Set syscall to print bytes

        #Pos1
        lb              $a0,1($t0)            # Value to first square
        syscall
        lb              $a0,BAR               # Print byte of bar "|"
        syscall
        #Pos2
        lb              $a0,2($t0)            # Load the second square
        syscall
        #Pos3
        lb              $a0,BAR               # Print byte of bar "|"
        syscall
        lb              $a0,3($t0)            # Load the third square
        syscall
#Dashes
        li              $v0,4                 # Set syscall to print a string
        la              $a0,DASHES            # Specify which string "----"
        syscall
#Middle 3 values
        li              $v0,11                # Set syscall to print bytes
        #Pos4
        lb              $a0,4($t0)            # Load the fourth square
        syscall
        lb              $a0,BAR               # Print byte of bar "|"
        syscall
        #Pos5
        lb              $a0,5($t0)            # Load the fifth square
        syscall
        lb              $a0,BAR               # Print byte of bar "|"
        syscall
        #Pos6
        lb              $a0,6($t0)            # Load the sixth square
        syscall
#Dashes
        li              $v0,4                 # Set syscall to print a string
        la              $a0,DASHES            # Specify which string "----"
        syscall
#Bottom 3 values
        li              $v0,11                # Set syscall to print bytes
        #Pos7
        lb              $a0,7($t0)            # Load the seventh square
        syscall
        lb              $a0,BAR               # Print byte of bar "|"
        syscall
        #Pos8
        lb              $a0,8($t0)            # Load the eigth square
        syscall
        lb              $a0,BAR               # Print byte of bar "|"
        syscall
        #Pos9
        lb              $a0,9($t0)            # Load the ninth square
        syscall
        lb              $a0,EOL               # Print NewLine
        syscall

        jr              $ra                   # Return Program

#=#=#=##=#=#=#=#=# TAKE PLAYER 1 VALID INPUT #=#=##=#=#=#=#=#=##=#=#=#=#
player1input:
        li              $v0,4                 # Set syscall to print a string
        la              $a0,P1INPUT           # Specify which string - Player1 turn
        syscall                               # Execute
        #STORE NUM
        li              $v0,5                 # Set syscall to read int number
        syscall                               # Execute
        #CHECK NUMBER IS VALID (Between 1 & 9)
        li              $t1,1                 # Load 1 to $t1
        blt             $v0,$t1,inputnotvalid1# If input < 1 go to inputnovalid for player1
        li              $t1,9                 # Load 9 to $t1
        bgt             $v0,$t1,inputnotvalid1# If input > 9 go to inputnovalid for player1
#Load Board
        la              $t0,VALUES            # Load board values
        add             $a0,$t0,$v0           # Match the user input square

        addiu           $sp,$sp,-4
        sw              $ra, 4($sp)
        jal             SQOK                  # Check if square is being used or not
        lw              $ra,4($sp)
        addiu           $sp,$sp,4
        beqz            $v0,player1input
        jr              $ra                   # Input was valid; return program to current move in game

        #=#=#=#=#=#=#=#=#=# INPUT FROM PLAYER 1 IS NOT VALID #=#=#=#=#=#=#=#=#=#
inputnotvalid1:
        li              $v0,4                 # Set syscall to print a string
        la              $a0,BADINPUT          # Specify which string
        syscall                               # Execute
        j               player1input          # Get Valid Input from Player 1

        #=#=#=##=#=#=#=#=# TAKE PLAYER 2 VALID INPUT #=#=##=#=#=#=#=#=##=#=#=#=#
player2input:
        li              $v0,4                 # Set syscall to print a string
        la              $a0,P2INPUT           # Specify which string - Player2 turn
        syscall                               # Execute
        #STORE NUM
        li              $v0,5                 # Set syscall to read int number
        syscall                               # Execute
        #CHECK NUMBER IS VALID (Between 1 & 9)
        li              $t2,1                 # Load 1 to $t1
        blt             $v0,$t2,inputnotvalid2# If input < 1 go to inputnovalid for player2
        li              $t2,9                 # Load 9 to $t1
        bgt             $v0,$t2,inputnotvalid2# If input > 9 go to inputnovalid for player2
        #Load Board
        la              $t0,VALUES            # Load board values
        add             $a0,$t0,$v0           # Match the user input with square by using address

        addiu           $sp,$sp,-4            # Allocates 1 word on the stack
        sw              $ra, 4($sp)           # Saves $ra in the upper stack
        jal             SQOK                  # Check if square is being used or not
        lw              $ra,4($sp)
        addiu           $sp,$sp,4
        beqz            $v0,player2input
        jr              $ra                   # Input was valid; return program to current move in game

        #=#=#=#=#=#=#=#=#=# INPUT FROM PLAYER 2 IS NOT VALID #=#=#=#=#=#=#=#=#=#
inputnotvalid2:
        li              $v0,4                 # Set syscall to print a string
        la              $a0,BADINPUT          # Specify which string
        syscall                               # Execute
        j               player2input          # Get Valid Input from Player 2

        #=#=#=#=#=#=#=#=#=#=#= CHECKING SQUARE IS AVAILABLE #=#=#=#=#=#=#=#=#=#=#
SQOK:
        li              $v0,0                 # Assume the square is not being used
        lb              $t0,X                 # Checking if there is a X
        lb              $t1,0($a0)            # Load the byte of the pos
        beq             $t0,$t1,NOK           # If same value is stored then not OK
        lb              $t0,O                 # Checking if there is an O
        beq             $t0,$t1,NOK           # If same value is stored then not OK
        move            $v0,$a0               # The square is empty. Everything is OK

        #=#=#=#=#=#=#=#= SQUARE NOT OK, IT IS ALREADY USED #=#=#=#=#=#=#=#=#=#=#=
NOK:
        jr              $ra                   # Return to routine. New value cannot be placed.


WIN:
        #Go to a check by row
        addiu           $sp,$sp,-4            # Get stack space
        sw              $ra, 4($sp)           # Store stack space
        jal             ROWS                  # Check if there is a win on the rows
        lw              $ra,4($sp)
        addiu           $sp,$sp,4             # Get stack space
        bnez            $v0,WINNER            # A player own
        addiu           $sp,$sp,-4            # Get stack space
        #Go to a check by columns
        sw              $ra, 4($sp)           # Store stack space
        jal             COLS                  # Check if there is a win on the columns
        lw              $ra,4($sp)
        addiu           $sp,$sp,4             # Get stack space
        bnez            $v0,WINNER            # A player own
        addiu           $sp,$sp,-4            # Get stack space
        #Go to a check by diagonal
        sw              $ra,4($sp)            # Store stack space
        jal             DIAG                  # Check if ther eis a win on the diagonal
        lw              $ra,4($sp)
        addiu           $sp,$sp,4             # Restore stack space
WINNER:
        jr              $ra
        #=#=#=#=#=#=#=#=#=# FINDING THE WINNER ON THE ROWS #=#=#=#=#=#=#=#=#=#
ROWS:
        addiu           $sp,$sp,-4            # Get space from the stack
        sw              $ra,4($sp)            # Save off return address

        #Checking row 1
        li              $a0,1                 # Set row 1 to be checked
        jal             ROW                   # Check row 1
        #Checking row 2
        bnez            $v0,ROWW              # If $v0 not zero, row Won
        li              $a0,2                 # Set row 2 to be checked
        jal             ROW                   # Check row 2
        #Checking row 3
        bnez            $v0,ROWW              # If $v0 not zero, Row Won
        li              $a0,3                 # Set row 3 to be checked
        jal             ROW                   # Check row 3
        #No row has a win
        bnez            $v0,ROWW              # If $v0 not zero, Row Won
        li              $v0,0                 # There is no wins on any row

ROWW:
        lw              $ra,4($sp)
        addiu           $sp,$sp,4             # Restore stack space
        jr              $ra                   # Go back to routine


ROW:
        li             $v0,0                  # Assume there is no win on the rows
        addiu          $a0,$a0,-1             # Getting desired row index
        li             $t0,3                  # Size of each row
        mul            $t0,$t0,$a0            # Offset in $t0
        la             $t1,VALUES             # Load address of the board from VALUES
        addi           $t1,$t1,1              # +1 to the address
        add            $t1,$t1,$t0            # Add an offset to the address
        lb             $t2,0($t1)             # Loading 1st square on row
        lb             $t3,1($t1)             # Loading 2nd square on row
        bne            $t2,$t3,ROWN           # If not equal no winner
        lb             $t3,2($t1)             # Loading 3rd square on row
        bne            $t2,$t3,ROWN           # If not equal no winner
        move           $v0,$t1                # Loading byte of winner
ROWN:
        jr             $ra                    #No Winner

        #=#=#=#=#=#=#=#=#=# FINDING THE WINNER ON THE COLUMNS #=#=#=#=#=#=#=#=#=#
COLS:
        #Checking col 1
        addiu          $sp,$sp,-4            # Get space from the stack
        sw             $ra,4($sp)            # Save return address
        li             $a0,1                 # Specifying column to check
        jal            COL                   # Go check col 1
        bnez           $v0,COLW              # If $v0 is not zero, this col won
        #Checking col 2
        li             $a0,2                 # Specifying column to check
        jal            COL                   # Go check col 2
        bnez           $v0,COLW              # If $v0 is not zero, this col won
        #Checking col 3
        li             $a0,3                 # Specifying column to check
        jal            COL                   # Go check col 3
        bnez           $v0,COLW              # Checking if no col won
        #No col has a win
        li             $v0,0                 # There is no win on any col

COLW:
        lw             $ra,4($sp)
        addiu          $sp,$sp,4
        jr             $ra                   # Go back to routine

COL:
        li             $v0,0                 # Assume there is no win on the cols
        la             $t0,VALUES            # Load address of the board from VALUES
        add            $t0,$t0,$a0           # Adding the number of the colums 1,2 or 3

        lb             $t1,0($t0)            # Loading first square on col
        lb             $t2,3($t0)            # Loading second square on col
        lb             $t3,6($t0)            # Loading third suare on col
        li             $v0,0

        bne            $t1,$t2,COLN          # If 1st sqr on col != 2nd sqr on col
        bne            $t1,$t3,COLN          # If 1st sqr on col != 3rd sqr on col
        move           $v0,$t1               # Else - Storing the winning char

        #No winner was found
COLN:
        jr             $ra                    #No Winner

        #=#=#=#=#=#=#=#=# FINDING THE WINNER ON THE DIAGONALS #=#=#=#=#=#=#=#=#
        #Checking the first diagonal , squares 1,5,9
DIAG:
        li              $v0,0                 # Assume no diagonal won
        la              $t0,VALUES            # Load address to board in $t0
        lb              $t1,1($t0)            # Loading 1st diag square (1st diag)
        lb              $t2,5($t0)            # Loading 2nd diag square (1st diag)
        lb              $t3,9($t0)            # Loading 3rd diag square (1st diag)
        bne             $t1,$t2,DIAG2         # If 1st diag sqr != 2nd diag sqr = No match
        bne             $t1,$t3,DIAG2         # If 1st diag sqr != 3rd diag sqr = No match
        move            $v0,$t1               # There is a winner
        jr              $ra

        #Checking the second diagonal , squares 3,5,7
DIAG2:
        lb              $t1,3($t0)            # Loading 1st square (2nd diag)
        lb              $t2,5($t0)            # Loading 2nd square (2nd diag)
        lb              $t3,7($t0)            # Loading 3rd square (2nd diag)
        bne             $t1,$t2,DIAGN         # If 1st sqr (2nd diag) != 2nd sqr (2nd diag) = No match
        bne             $t1,$t3,DIAGN         # If 1st sqr (2nd diag) != 3rd sqr (2nd diag) = No match
        move            $v0,$t1               # There is a win

        #No winner was found
DIAGN:
        jr              $ra                   # No winner
