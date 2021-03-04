# ================================================================
#Write a recursive program which accept number from user and return
# its factorial.
# ================================================================

# ==============================================
# Facto : Calculate factorial of a given number
# ==============================================
def Facto(iNumber):

    iFact = 1
    
    #Recursion Stop condition
    if(iNumber == 0):
        return iFact

    # Recursion continue conditiont, CALL to function
    #
    # Taking return value of a function, means we are preserving the iFact value
    # Accross function calls
    iFact = Facto(iNumber-1)

    # Calculate the factorial
    iFact = iFact * iNumber

    return iFact

# ==================
# Entry Function
# ==================
def main():

    iFact = 0
    
    # Accept the input from user
    iNumber = int(input("Enter the number : "))
    
    # Call to the function
    iFact = Facto(iNumber)

    # Output
    print("The factorial of a given number is : ",iFact)

# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry point" function
    main()
