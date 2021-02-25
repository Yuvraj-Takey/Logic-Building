# ================================================================
# Write a program which contains one lambda function which accepts
# two parameters and return its multiplication
# ================================================================

# ====================================
# Lambda function for multiplication
# ====================================
Mult = lambda iNo1, iNo2 : (iNo1 * iNo2)

# ==============================================
# LamMult : Returns multiplication of numbers
# ==============================================
def LamMult(iNum1, iNum2):

    # call to the lambda fuction
    iRet = Mult(iNum1, iNum2)

    return iRet

# ==================
# Entry Function
# ==================
def main():

    # Accept the value from user
    iVal1 = int(input("Enter 1st value for multiplication : "))
    iVal2 = int(input("Enter 1st value for multiplication : "))

    # Call to the fuction
    print("Multiplication of given numbers is : ",LamMult(iVal1, iVal2))

# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry point" function
    main()
