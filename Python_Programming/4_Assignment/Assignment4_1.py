# ================================================================
# Write a program which contains one lambda function which accepts
# one parameter and return power of two
# ================================================================

# ====================================================
# PowerTwo : Get the power of two of the given number
# ====================================================
def PowerTwo(iNum):

    # Write a nested functin and calculte the power of two
    iPow = lambda iNum : (iNum * iNum)

    # Call to the lambda function and return the calculation
    return iPow(iNum)

# ==================
# Entry Function
# ==================
def main():

    # Accept the input from user
    iValue = int(input("Enter the value for power-calculation : "))

    # call to the function
    iRet = PowerTwo(iValue)

    # Output
    print("The power of two of a given number is : ", iRet)

# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry point" function
    main()
