# ================================================================
# Write a program which contains one function named as Add()
# which accepts two numbers from user and return addition of
# that two numbers.
# ================================================================

# =============================
# Add: addition of two number
# =============================
def Add(iNo1, iNo2):

    # Addition of given number
    iAns = iNo1 + iNo2
    
    # return the addition of given number
    return iAns

    
# ==================
# Entry Function
# ==================
def main():

    iNum1 = 0
    iNum2 = 0

    # Accept 2 numbers from user
    iNum1 = int(input("Enter 1st number : "))
    iNum2 = int(input("Enter 2nd number : "))

    # Call to the function
    iRet = Add(iNum1, iNum2)

    # Output
    print("Addition of given number is : ", iRet)

# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry" function
    main()
