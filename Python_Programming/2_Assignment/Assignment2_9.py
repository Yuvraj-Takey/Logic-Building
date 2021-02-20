# ===================================================================
# Write a program which accept number from user and return number of
# digits in that number
# ===================================================================

# =============================
# DigitCnt : count the digit
# =============================
def DigitCnt(iNum):

    iCnt = 0

    # iterate the loop till the number becomes 1 or less than 1
    while(iNum >= 1):

        # increment the count and reduce the number by 1 digit
        iCnt = iCnt + 1
        iNum = iNum / 10


    return iCnt
    
# ==================
# Entry Function
# ==================
def main():

    # Accept the input from user
    iNumber = int(input("Enter the number : "))
    
    # call to function
    iRet = DigitCnt(iNumber)

    # output
    print("The number of digits are present in the given number is : ", iRet)

# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry" function
    main()
