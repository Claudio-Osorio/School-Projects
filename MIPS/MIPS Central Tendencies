      .data
INTRODUCTION1:	.asciiz "############################################"
INTRODUCTION2:	.asciiz "\n#           Name: Claudio Osorio           #"
INTRODUCTION3:	.asciiz "\n#           Class: CDA 3100                #"
INTRODUCTION4:	.asciiz "\n# Assingment #5:Mips Assembly Programming  #"
INTRODUCTION5:	.asciiz "\n#     Sum, Min, Max, Mean, and Variance    #"
INTRODUCTION6:	.asciiz "\n############################################\n"
INTRO:          .asciiz "Enter 5 integer numbers:"
ASKNUM1:        .asciiz "\nPlease enter your first number:"
ASKNUM2:      	.asciiz "Please enter your second number:"
ASKNUM3:      	.asciiz "Please enter your third number:"
ASKNUM4:      	.asciiz "Please enter your fourth number:"
ASKNUM5:      	.asciiz "Please enter your fifth number:"
OK:             .asciiz "\nCode Working OK"
PFLOAT:         .asciiz "Floating Point List:\n"
NEWLINE:        .asciiz "\n"
SUMRESULT:      .asciiz "\nThe Sum of the numbers is: "
SMALLEST:       .asciiz "\nThe Smallest number is: "
LARGEST:        .asciiz "\nThe Largest number is: "
MEAN:           .asciiz "\nThe Mean of the numbers is: "
VARIANCE:       .asciiz "\nThe Variance of the numbers is: "
                .align 2       #Forces the program to be on a full word boundary
MYARRAY:        .space 20      #20 bytes allocated (4 for each of the 5 32bit numbers)
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
        #Printing String 6
        li              $v0,4                 # Set syscall to print a string
        la              $a0,INTRODUCTION6     # Specify which string
        syscall                               # Execute
        #Ask to enter 5 integers
        li              $v0,4                 # Set syscall to print a string
        la              $a0,INTRO             # Specify which string
        syscall                               # Execute
        #=#=#=##=#=#=##=#=#=# ASK NUM1 #=#=#=##=#=#=##=#=#=#
        li              $v0,4                 # Set syscall to print a string
        la              $a0,ASKNUM1           # Specify which string
        syscall                               # Execute
        #STORE NUM
        li              $v0,5                 # Set syscall to read int number
        syscall                               # Execute
        move            $t1,$v0               # Store num into $t1

        #=#=#=##=#=#=##=#=#=# ASK NUM2 #=#=#=##=#=#=##=#=#=#
        li              $v0,4                 # Set syscall to print a string
        la              $a0,ASKNUM2           # Specify which string
        syscall                               # Execute
        #STORE NUM
        li              $v0,5                 # Set syscall to read int number
        syscall                               # Execute
        move            $t2,$v0               # Store num into $t2
        #=#=#=##=#=#=##=#=#=# ASK NUM3 #=#=#=##=#=#=##=#=#=#
        li              $v0,4                 # Set syscall to print a string
        la              $a0,ASKNUM3           # Specify which string
        syscall                               # Execute
        #STORE NUM
        li              $v0,5                 # Set syscall to read int number
        syscall                               # Execute
        move            $t3,$v0               # Store num into $t3
        #=#=#=##=#=#=##=#=#=# ASK NUM4 #=#=#=##=#=#=##=#=#=#
        li              $v0,4                 # Set syscall to print a string
        la              $a0,ASKNUM4           # Specify which string
        syscall                               # Execute
        #STORE NUM
        li              $v0,5                 # Set syscall to read int number
        syscall                               # Execute
        move            $t4,$v0               # Store num into $t4

        #=#=#=##=#=#=##=#=#=# ASK NUM5 #=#=#=##=#=#=##=#=#=##=#=#=#=#=#=#=#=#=#=#=#=

        li              $v0,4                 # Set syscall to print a string
        la              $a0,ASKNUM5           # Specify which string
        syscall                               # Execute
        #STORE NUM
        li              $v0,5                 # Set syscall to read int number
        syscall                               # Execute
        move            $t5,$v0               # Store num into $t5

        #=#=#=##=#=#=##=#=#=# CONVERTING NUMS TO FLOAT #=#=#=##=#=#=##=#=#=##=#=#=#=#=#=

        #NUM1
        mtc1            $t1,$f1               # Prepare number to be converted
        cvt.s.w         $f1,$f1               # Converting from int to float s.prec
        #NUM2
        mtc1            $t2,$f2               # Prepare number to be converted
        cvt.s.w         $f2,$f2               # Converting from int to float s.prec
        #NUM3
        mtc1            $t3,$f3               # Prepare number to be converted
        cvt.s.w         $f3,$f3               # Converting from int to float s.prec
        #NUM4
        mtc1            $t4,$f4               # Prepare number to be converted
        cvt.s.w         $f4,$f4               # Converting from int to float s.prec
        #NUM5
        mtc1            $t5,$f5               # Prepare number to be converted
        cvt.s.w         $f5,$f5               # Converting from int to float s.prec

        #=#=#=##=#=#=##=#=#=# STORING NUMBERS INTO ARRAY #=#=#=##=#=#=##=#=#=##=#=#=#=#=#=

        #LOADING ARRAY ADDRESS
        la              $t0, MYARRAY
        #NUM 1
        s.s             $f1,($t0)             # Storing value into array
        addi            $t0,$t0,4             # Moving array address to next 4 words (nxt pos)
        #NUM 2
        s.s             $f2,($t0)             # Storing value into array
        addi            $t0,$t0,4             # Moving array address to next 4 words (nxt pos)
        #NUM 3
        s.s             $f3, ($t0)            # Storing value into array
        addi            $t0,$t0,4             # Moving array address to next 4 words (nxt pos)
        #NUM 4
        s.s             $f4, ($t0)            # Storing value into array
        addi            $t0,$t0,4             # Moving array address to next 4 words (nxt pos)
        #NUM 5
        s.s             $f5, ($t0)            # Storing value into array
        addi            $t0,$t0,4             # Moving array address to next 4 words (nxt pos)

        #=#=#=##=#=#=##=#=#=# READING FROM ARRAY & PRINTING #=#=#=##=#=#=##=#=#=##=#=#=#=#=#=

        #HEADER MSG
        li              $v0,4                 # Set syscall to print a string
        la              $a0,PFLOAT            # Specify which string
        syscall                               # Execute
        #GETTING ADDRRESS OF ARRAY
        la              $t0, MYARRAY
        #PRINTING NUM1 FROM ARRAY
        li              $v0,2                 # Set syscall to print s.prec float
        l.s             $f12,($t0)            # Specify which float
        syscall                               # Execute
        li              $v0,4                 # Set syscall to print a string
        la              $a0,NEWLINE           # Specify which string
        syscall                               # Execute
        #PRINTING NUM2 FROM ARRAY
        addi            $t0,$t0,4             # Moving array address to next 4 words (nxt pos)
        li              $v0,2                 # Set syscall to print s.prec float
        l.s             $f12,($t0)            # Specify which float
        syscall                               # Execute
        li              $v0,4                 # Set syscall to print a string
        la              $a0,NEWLINE           # Specify which string
        syscall                               # Execute
        #PRINTING NUM3 FROM ARRAY
        addi            $t0,$t0,4             # Moving array address to next 4 words (nxt pos)
        li              $v0,2                 # Set syscall to print s.prec float
        l.s             $f12,($t0)            # Specify which float
        syscall                               # Execute
        li              $v0,4                 # Set syscall to print a string
        la              $a0,NEWLINE           # Specify which string
        syscall                               # Execute
        #PRINTING NUM4 FROM ARRAY
        addi            $t0,$t0,4             # Moving array address to next 4 words (nxt pos)
        li              $v0,2                 # Set syscall to print s.prec float
        l.s             $f12,($t0)            # Specify which float
        syscall                               # Execute
        li              $v0,4                 # Set syscall to print a string
        la              $a0,NEWLINE           # Specify which string
        syscall                               # Execute
        #PRINTING NUM5 FROM ARRAY
        addi            $t0,$t0,4             # Moving array address to next 4 words (nxt pos)
        li              $v0,2                 # Set syscall to print s.prec float
        l.s             $f12,($t0)            # Specify which float
        syscall                               # Execute

        #=#=#=##=#=#=##=#=#=# SUMMING NUMBERS #=#=#=##=#=#=##=#=#=#=#=#=#=#=#=#=#=#=#=#=#=
        #CALCULATION
        add.s           $f6,$f1,$f2           # $f1+$f2 stored in $f6
        add.s           $f6,$f3,$f6           # $f3+$f6 stored in $f6
        add.s           $f6,$f4,$f6           # $f4+$f6 stored in $f6
        add.s           $f6,$f5,$f6           # $f5+$f6 stored in $f6
        #PRINTING RESULT
        li              $v0,4                 # Set syscall to print a string
        la              $a0,SUMRESULT         # Specify which string
        syscall                               # Execute
        li              $v0,2                 # Set syscall to print s.prec float
        mov.s           $f12,$f6              # Specify which float
        syscall                               # Execute
        #=#=#=##=#=#=##=#=#=# SMALLEST NUMBER #=#=#=##=#=#=##=#=#=#=#=#=#=#=#=#=#=#=#=#=#=
        #f5 < f4
        c.le.s          $f5,$f4               # Compare if f5 < f7 then bc1t will be 1
        bc1t            STORESMALLER1         # If bc1t is 1 then jump to store smaller
        #ELSE
        mov.s           $f7,$f4               # Store $f4 as the smallest to $f7
        j               CONTINUE1             # If Needed Jump to next step
        #Store the smaller in $f7
STORESMALLER1:
        mov.s           $f7,$f5               # Store the smallest to $f7
        j               CONTINUE1
        #f4 < f7
CONTINUE1:
        c.le.s          $f4,$f7               # Compare if f4 < f7 then bc1t will be 1
        bc1t            STORESMALLER2         # If bc1t is 1 then jump to store smaller
        j               CONTINUE2             # If no branch jump to next step
        #Store the smaller in $f7
STORESMALLER2:
        mov.s           $f7,$f4               # Store the smallest to $f7
        j               CONTINUE2             # Continue
        #f3 < f7
CONTINUE2:
        c.le.s          $f3,$f7               # Compare if f3 < f7 then bc1t will be 1
        bc1t            STORESMALLER3         # If bc1t is 1 then jump to store smaller
        j               CONTINUE3             # If no branch jump to next step
        #Store the smaller in $f7
STORESMALLER3:
        mov.s           $f7,$f3               # Store the smallest to $f7
        j               CONTINUE3             # Continue
        #f2 < f7
CONTINUE3:
        c.le.s          $f2,$f7               # Compare if f2 < f7 then bc1t will be 1
        bc1t            STORESMALLER4         # If bc1t is 1 then jump to store smaller
        j               CONTINUE4             # If no branch jump to next step
        #Store the smaller in $f7
STORESMALLER4:
        mov.s           $f7,$f2               # Store the smallest to $f7
        j               CONTINUE4             # Continue
        #f1 < f7
CONTINUE4:
        c.le.s          $f1,$f7               # Branch if f1 < f7 then bc1t will be 1
        bc1t            STORESMALLER5         # If bc1t is 1 then jump to store smaller
        j               SMALLESTNUMBER        # If no branch jump to next step
        #Store the smaller in $f7
STORESMALLER5:
        mov.s           $f7,$f1               # Store the smallest to $f7
        j               SMALLESTNUMBER        # Go to find out which one is the smallest of all.

SMALLESTNUMBER:
        #Print Header of Smaller number

        li              $v0,4                 # Set syscall to print a string
        la              $a0,SMALLEST          # Specify which string
        syscall                               # Execute

        li              $v0,2                 # Set syscall to print a single prec. float
        mov.s           $f12,$f7              # Moving f7 to f12 to be printed
        syscall                               # Execute

        #=#=#=##=##=#=##=#=#=# LARGEST NUMBER #=#=#=##=#=#=##=#=#=#=##=#=#=#=#=#=#=#=#=#=#=#=

        c.le.s          $f5,$f4               # Compare if f5 < f8 then bc1t will be 0
        bc1f            STORELARGER1          # If bc1t is 0 then jump to store larger
        j               CONTINUE10            # If Needed Jump to next step
        #Store the larger in $f8
STORELARGER1:
        mov.s           $f8,$f5               # Store the larger to $f8
        j               CONTINUE10
CONTINUE10:
        c.le.s          $f4,$f8               # Compare if f4 < f8 then bc1t will be 0
        bc1f            STORELARGER2          # If bc1t is 0 then jump to store larger
        j               CONTINUE20            # If no branch jump to next step
        #Store the larger in $f8
STORELARGER2:
        mov.s           $f8,$f4               # Store the larger to $f8
        j               CONTINUE20            # Continue
CONTINUE20:
        c.le.s          $f3,$f8               # Compare if f3 < f8 then bc1t will be 0
        bc1f            STORELARGER3          # If bc1t is 0 then jump to store larger
        j               CONTINUE30            # If no branch jump to next step
        #Store the larger in $f8
STORELARGER3:
        mov.s           $f8,$f3               # Store the larger to $f8
        j               CONTINUE30            # Continue
CONTINUE30:
        c.le.s          $f2,$f8               # Compare if f2 < f8 then bc1t will be 0
        bc1f            STORELARGER4          # If bc1t is 0 then jump to store larger
        j               CONTINUE40            # If no branch jump to next step
        #Store the larger in $f8
STORELARGER4:
        mov.s           $f8,$f2               # Store the larger to $f8
        j               CONTINUE40            # Continue
CONTINUE40:
        c.le.s          $f1,$f8               # Branch if f1 < f8 then bc1t will be 0
        bc1f            STORELARGER5          # If bc1t is 0 then jump to store larger
        j               LARGESTNUMBER         # If no branch jump to next step
        #Store the larger in $f8
STORELARGER5:
        mov.s           $f8,$f1               # Store the largest to $f8
        j               LARGESTNUMBER         # Go to find out which one is the largest of all.

LARGESTNUMBER:
        #Print Header of largest number
        li              $v0,4                 # Set syscall to print a string
        la              $a0,LARGEST           # Specify which string
        syscall                               # Execute
        #Printing result Largest Number
        li              $v0,2                 # Set syscall to print a single prec. float
        mov.s           $f12,$f8              # Moving f8 to f12 to be printed
        syscall                               # Execute

        #=#=##=#=#=##=#=#=##=#=#=# MEAN #=#=#=##=#=#=##=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=

        #Taking the sum stored in f6 and dividing it by the number of single prec. floats (5)
        addi            $t9,$zero,5           # Loading 5 to $t9
        #Converting 5 to float
        mtc1            $t9,$f0               # Loading $t9 to $f0
        cvt.s.w         $f0,$f0               # Converting from int to float s.prec
        #Calculating the mean
        div.s           $f9,$f6,$f0           # Dividing the sum of numbers by the qty of nums.
        #Printing mean
        li              $v0,4                 # Set syscall to print a string
        la              $a0,MEAN              # Specify which string
        syscall                               # Execute

        li              $v0,2                 # Set syscall to print a single prec. float
        mov.s           $f12,$f9              # Moving f9 to f12 to be printed
        syscall                               # Execute
        #=#=#=##=#=#=##=#==##=#=# VARIANCE =##=#=#=#=##=#=#=##=#=#=#
        #Calculation
        sub.s           $f15,$f1,$f9          # Num1-Mean
        mul.s           $f15,$f15,$f15        # Square result

        sub.s           $f16,$f2,$f9          # Num2-Mean
        mul.s           $f16,$f16,$f16        # Square result

        sub.s           $f17,$f3,$f9          # Num3-Mean
        mul.s           $f17,$f17,$f17        # Square result

        sub.s           $f18,$f4,$f9          # Num4-Mean
        mul.s           $f18,$f18,$f18        # Square result

        sub.s           $f19,$f5,$f9          # Num5-Mean
        mul.s           $f19,$f19,$f19        # Square result

        add.s           $f15,$f15,$f16        # (num1-mean)^2 + (num2-mean)^2
        add.s           $f15,$f15,$f17        # Previous + (num3-mean)^2
        add.s           $f15,$f15,$f18        # Previous + (num4-mean)^2
        add.s           $f15,$f15,$f19        # Previous + (num3-mean)^2

        li              $t7,4                 # Loading 4 to $t7
        mtc1            $t7,$f16              # Passing int 4 to float
        cvt.s.w         $f16,$f16             # Converting from int to float s.prec
        div.s           $f15,$f15,$f16        # Divide sum above from (n-1 which is 5-1 =4)
        #Printing variance
        li              $v0,4                 # Set syscall to print a string
        la              $a0,VARIANCE          # Specify which string
        syscall                               # Execute

        li              $v0,2                 # Set syscall to print a single prec. float
        mov.s           $f12,$f15             # Printing variance result
        syscall                               # Execute

        j               $ra                   # Exit Program
