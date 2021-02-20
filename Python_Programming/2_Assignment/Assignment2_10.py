# ===================================================================
# Write a program which accept number from user and return addition
# of digits in that number
# ===================================================================

# ===============================================
# DigitAdd : Add the digits in the given number
# ===============================================
def DigitAdd(iNum):

    iSum = 0

    # Iterate the loop till the number becomes 1 or less than 1
    while(iNum >= 1):

        # Extract single digit from number and make addition
        iDigi = int(iNum % 10)
        iSum = iSum + iDigi
        
        # Reduce the number by 1 digit
        iNum = iNum / 10

    return iSum
    
# ==================
# Entry Function
# ==================
def main():

    # Accept the input from user
    iNumber = int(input("Enter the number : "))
    
    # call to function
    iRet = DigitAdd(iNumber)

    # output
    print("The addition of digits in the given number is : ", iRet)

# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry" function
    main()
