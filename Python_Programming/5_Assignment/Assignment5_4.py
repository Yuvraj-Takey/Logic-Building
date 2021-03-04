# ================================================================
# Write a recursive program which accept number from user and
# return summation of its digits.
# ================================================================

# ==============================================
# SumDigit : Calculate summation of digits
# ==============================================
def SumDigit(iNumber, iSum):

    # Recursion stop condition
    if(int(iNumber) == 0):
        return iSum

    # Perform calculation
    iDigit = int(iNumber % 10)
    iSum = iSum + iDigit
    iNumber = iNumber/10
    
    # Recursion continue condition, CALL to function
    # Taking return value of a function, means we are preserving the iSum value
    # Accross function calls
    iSum = SumDigit(iNumber, iSum)

    return iSum

# ==================
# Entry Function
# ==================
def main():

    iSum = 0
    
    # Accept input from user
    iNumber = int(input("Enter the number : "))
    
    # Call to the function
    iSum = SumDigit(iNumber, iSum)

    # Output
    print("Digit-Summation of a given number is : ", iSum)

# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry point" function
    main()
