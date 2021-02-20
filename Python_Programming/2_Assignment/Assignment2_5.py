# ================================================================
# Write a program which accept one number for user and check
# whether number is prime or not
# ================================================================

# =================================
# CheckPrime : Check prime number
# =================================
def CheckPrime(iNum):

    # filters
    if(iNum == 1):
        return True
    
    # iterate the loop from (2) to (given number - 1)
    for iNo in range(2, iNum):

        # check prime condition
        if(iNum % iNo == 0):

            # Once the control comes here, i.e the number
            # is not prime (b'cos of, for loop condition)
            # Now, Do not procced forward, break the loop
            # and return False

            break;

    # Check the success-status of above loop [if, not break]
    if(iNo == (iNum-1)):
        return True
    else:
        return False
# ==================
# Entry Function
# ==================
def main():

    # Accept number from user
    iNumber = int(input("Enter a number : "))

    # Call to function
    if(CheckPrime(iNumber)):
        print("It is Prime Number")
    else:
        print("It is not Prime Number")

# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry" function
    main()
