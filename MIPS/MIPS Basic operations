      .data
INTRODUCTION1:	.asciiz "############################################"
INTRODUCTION2:	.asciiz "\n#           Name: Claudio Osorio           #"
INTRODUCTION3:	.asciiz "\n#           Class: CDA 3100                #"
INTRODUCTION4:	.asciiz "\n# Assingment #4: Read in two numbers and   #"
INTRODUCTION5:	.asciiz "\n#     find the sum, difference, product,   #"
INTRODUCTION6:	.asciiz "\n# quotient/remainder, shift left and right #"
INTRODUCTION7:	.asciiz "\n############################################\n"
ASKINT1:        .asciiz "Please enter your first number:"
ASKINT2:      	.asciiz "Please enter your second number:"
ERRORNUM:       .asciiz "Try again. Make sure your numbers are positive\n"
ENDMSG:         .asciiz "\nWhy is Chewbacca considered a PRO?\n-Because he doesn't make wookie mistakes...\nGood Bye"
NEXTLINE:       .asciiz "\n"
REMAINDER:      .asciiz " REM "
SHIFTLEFT:      .asciiz "Shift Left "
SHIFTRIGHT:      .asciiz "Shift Right "
SLSYMB:         .asciiz " << "
SRSYMB:         .asciiz " >> "
SLASH:		      .byte		'/'
EQUAL:		      .byte	  '='
PLUS:		        .byte	  '+'
MINUS:		      .byte	  '-'
MULT:	          .byte	  '*'

                .align 2 #Forces the program to be on a full word boundary
                .text
                .globl main

badnumber:
   #=#=#=##=#=#=##=#=# VALIDATE NUMBER #=#=##=#=#=##=#=#=#

   #Print error
   li           $v0,4                  #Set syscall to print a string
   la           $a0,ERRORNUM           #Specify which string
   syscall                             #Execute

   #Get to main function
   j            program                   #Jump to main function

main:
   #=#=#=##=#=#=##=#=#=#INTRODUCTION#=#=#=##=#=#=##=#=#=#
    li           $v0,4                 #Set syscall to print a string
    la           $a0,INTRODUCTION1     #Specify which string
    syscall                            #Execute

    li           $v0,4                 #Set syscall to print a string
    la           $a0,INTRODUCTION2     #Specify which string
    syscall                            #Execute

    li           $v0,4                 #Set syscall to print a string
    la           $a0,INTRODUCTION3     #Specify which string
    syscall                            #Execute

    li           $v0,4                 #Set syscall to print a string
    la           $a0,INTRODUCTION4     #Specify which string
    syscall                            #Execute

    li           $v0,4                 #Set syscall to print a string
    la           $a0,INTRODUCTION5     #Specify which string
    syscall                            #Execute

    li           $v0,4                 #Set syscall to print a string
    la           $a0,INTRODUCTION6     #Specify which string
    syscall                            #Execute

    li           $v0,4                 #Set syscall to print a string
    la           $a0,INTRODUCTION7     #Specify which string
    syscall                            #Execute

program:
   #=#=#=##=#=#=##=#=#=#     INTEGER 1    #=#=#=##=#=#=##=#=#=#

    #Ask for integer 1
    li           $v0,4                 #Set syscall to print a string
    la           $a0,ASKINT1           #Specify which string
    syscall                            #Execute

    #Scan integer 1
    li           $v0,5                 #Set syscall to scan for an integer
    syscall			       #Execute
    move         $s1,$v0	       #Copy integer 1 to register

    #Validate integer 1. If incorrect (less than 1) start again with branch
    blt	         $s1,1,badnumber       #Test integer1 <1 then go to bad number
                                       #and start getting numbers again

    #=#=#=##=#=#=##=#=#=#     INTEGER 2   #=#=#=##=#=#=##=#=#=#

    #Ask for integer 2
    li           $v0,4                 #Set syscall to print a string
    la           $a0,ASKINT2           #Specify which string
    syscall                            #Execute

    #Scan integer 2
    li            $v0,5                #Set syscall to scan for an integer
    syscall			 			                 #Execute
    move          $s2,$v0			         #Copy integer 2 to register

    #Validate itneger 2. If incorrect (less than 1) start again with branch
    blt	         $s2,1,badnumber       #Test integer1 <1 then go to bad number
                                       #and start getting numbers again

    #=#=#=##=#=#=#OPTIONAL USE OF TEMPORARY#=#=#=##=#=#=##=#=#=#

    #Making sure the orignals never get changed...
    move		       $t1,$s1             #Copies integer1 into $t1
    move		       $t2,$s2             #Copies integer2 into $t2

    #=#=#=##=#=#=##=#=#=#EQUATION AND (+)#=#=#=##=#=#=##=#=#=#

    #Calculation
    add		         $t3,$t1,$t2         #integer 1 + integer 2, result is stored in $t3

    #Print integer 1
    li            $v0,1                #Set syscall to print an integer
    move          $a0,$t1              #Specify which integer (integer 1)
    syscall			 			                 #Execute

    #Print + sign
    li            $v0,11               #Set syscall to print a byte
    lb            $a0,PLUS             #Specify which byte to print  (plus sign)
    syscall			 			                 #Execute

    #Print integer 2
    li            $v0,1                #Set syscall to print an integer
    move          $a0,$t2              #Specify which integer (integer 2)
    syscall			 			                 #Execute

    #Print = sign
    li            $v0,11               #Set syscall to print a byte
    lb            $a0,EQUAL            #Specify which byte to print  (equal sign)
    syscall			 			                 #Execute

    #Print result
    li            $v0,1                #Set syscall to print an integer
    move          $a0,$t3              #Specify which integer (result)
    syscall			 			                 #Execute

    #Go to next line
    li           $v0,4                 #Set syscall to print a string
    la           $a0,NEXTLINE          #Specify which string
    syscall                            #Execute

    #=#=#=##=#=#=##=#=#=#EQUATION AND (-)#=#=#=##=#=#=##=#=#=#

    #Calculation
    move		       $t1,$s1             #Copies integer1 into $t1
    move		       $t2,$s2             #Copies integer2 into $t2
    sub 		       $t3,$t1,$t2         #integer 1 - integer 2, result is stored in $t3

    #Print integer 1
    li            $v0,1                #Set syscall to print an integer
    move          $a0,$t1              #Specify which integer (integer 1)
    syscall			 			                 #Execute

    #Print - sign
    li            $v0,11               #Set syscall to print a byte
    lb            $a0,MINUS            #Specify which byte to print  (minus sign)
    syscall			 			                 #Execute

    #Print integer 2
    li            $v0,1                #Set syscall to print an integer
    move          $a0,$t2              #Specify which integer (integer 2)
    syscall			 			                 #Execute

    #Print = sign
    li            $v0,11               #Set syscall to print a byte
    lb            $a0,EQUAL            #Specify which byte to print  (equal sign)
    syscall			 			                 #Execute

    #Print result
    li            $v0,1                #Set syscall to print an integer
    move          $a0,$t3              #Specify which integer (result)
    syscall			 			                 #Execute

    #Go to next line
    li           $v0,4                 #Set syscall to print a string
    la           $a0,NEXTLINE          #Specify which string
    syscall                            #Execute

    #=#=#=##=#=#=##=#=#=#EQUATION AND (*)#=#=#=##=#=#=##=#=#=#

    #Calculation
    move		       $t1,$s1             #Copies integer1 into $t1
    move		       $t2,$s2             #Copies integer2 into $t2
    mult		       $t1,$t2             #integer 1 * integer 2, result is stored in $t3
                                       #Upper 32 bits are stored in hi(use mflo)
                                       #Lower 32 bits stored in lo (use mflo)
    #Print integer 1
    li            $v0,1                #Set syscall to print an integer
    move          $a0,$t1              #Specify which integer (integer 1)
    syscall			 			                 #Execute

    #Print * sign
    li            $v0,11               #Set syscall to print a byte
    lb            $a0,MULT             #Specify which byte to print  (mult sign)
    syscall			 			                 #Execute

    #Print integer 2
    li            $v0,1                #Set syscall to print an integer
    move          $a0,$t2              #Specify which integer (integer 2)
    syscall			 			                 #Execute

    #Print = sign
    li            $v0,11               #Set syscall to print a byte
    lb            $a0,EQUAL            #Specify which byte to print  (equal sign)
    syscall			 			                 #Execute

    #Print result
    li            $v0,1                #Set syscall to print an integer
    mflo          $a0                  #Specify the product result is to be printed
    syscall			 			                 #Execute

    #Go to next line
    li           $v0,4                 #Set syscall to print a string
    la           $a0,NEXTLINE          #Specify which string
    syscall                            #Execute

    #=#=#=##=#=#=##=#=#=#EQUATION AND (/)#=#=#=##=#=#=##=#=#=#

    #Calculation
    move		       $t1,$s1             #Copies integer1 into $t1
    move		       $t2,$s2             #Copies integer2 into $t2
    div 		       $t3,$t1,$t2         #integer 1 / integer 2, result is stored in $t3
                                       #Quotient goes to register lo (use mflo)
                                       #Remainder goes to register hi (use mfhi)

    #Print integer 1
    li            $v0,1                #Set syscall to print an integer
    move          $a0,$t1              #Specify which integer (integer 1)
    syscall			 			                 #Execute

    #Print / sign
    li            $v0,11               #Set syscall to print a byte
    lb            $a0,SLASH            #Specify which byte to print  (Slash sign)
    syscall			 			                 #Execute

    #Print integer 2
    li            $v0,1                #Set syscall to print an integer
    move          $a0,$t2              #Specify which integer (integer 2)
    syscall			 			                 #Execute

    #Print = sign
    li            $v0,11               #Set syscall to print a byte
    lb            $a0,EQUAL            #Specify which byte to print  (equal sign)
    syscall			 			                 #Execute

    #Print Quotient
    li            $v0,1                #Set syscall to print an integer
    mflo          $a0                  #Specify Quotient is to be printed
    syscall			 			                 #Execute

    #Print string "REM" for remainder
    li           $v0,4                 #Set syscall to print a string
    la           $a0,REMAINDER         #Specify which string
    syscall                            #Execute

    #Print Remainder value
    li           $v0,1                #Set syscall to print an integer
    mfhi         $a0                  #Specify remainder is to be printed
    syscall			 			                #Execute

    #Go to next line
    li           $v0,4                 #Set syscall to print a string
    la           $a0,NEXTLINE          #Specify which string
    syscall                            #Execute

    #=#=#=##=#=#=##=#=#=#   SHIFT LEFT   #=#=#=##=#=#=##=#=#=#

    #Calculation
    sll         $t3,$t1,1              #Shift left integer 1 by 1 binary digits

    #Explain Operation
    li          $v0,4                  #Set syscall to print a string
    la          $a0,SHIFTLEFT          #Specify which string
    syscall                            #Execute

    #Print "1" because it shifts 1 to the left
    li          $v0,1                  #Set syscall to print an integer
    li          $t4,1                  #Load 1 to  $t4
    move        $a0,$t4                #Set $t4 to be printed
    syscall                            #Execute

    #Print <<
    li          $v0,4                  #Set syscall to print a string
    la          $a0,SLSYMB             #Specify which string (<<)
    syscall                            #Execute

    #Print result
    li          $v0,1                  #Set syscall to print an integer
    move        $a0,$t3                #Set $t3 to be printed
    syscall                            #Execute

    #Go to next line
    li           $v0,4                 #Set syscall to print a string
    la           $a0,NEXTLINE          #Specify which string
    syscall                            #Execute

    #=#=#=##=#=#=##=#=#=#  SHIFT RIGHT   #=#=#=##=#=#=##=#=#=#

    #Calculation
    srl         $t3,$t2,2              #Shift right integer 2 by 2 binary digits

    #Explain Operation
    li          $v0,4                  #Set syscall to print a string
    la          $a0,SHIFTRIGHT         #Specify which string
    syscall                            #Execute

    #Print "2" because it shifts 2 to the right
    li          $v0,1                  #Set syscall to print an integer
    li          $t4,2                  #Load 2 to  $t4
    move        $a0,$t4                #Set $t4 to be printed
    syscall                            #Execute

    #Print >>
    li          $v0,4                  #Set syscall to print a string
    la          $a0,SRSYMB             #Specify which string (>>)
    syscall                            #Execute

    #Print result
    li          $v0,1                  #Set syscall to print an integer
    move        $a0,$t3                #Set $t3 to be printed
    syscall                            #Execute

    #Go to next line
    li           $v0,4                 #Set syscall to print a string
    la           $a0,NEXTLINE          #Specify which string
    syscall                            #Execute

    #=#=#=##=#=#=##=#=#=#  SAY GOODBYE :'(   #=#=#=##=#=#=##=#=#=#

    li           $v0,4                 #Lame Chewbacca joke
    la           $a0,ENDMSG            #if funny maybe add extracredit
    syscall                            #Execute!  ;D

   jr			$ra 			           #End Program
