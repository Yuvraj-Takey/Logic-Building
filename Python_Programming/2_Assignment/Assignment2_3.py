# ================================================================
# Write a program which accept one number from user and return
# its factorial
# ================================================================

# =============================
# Fact: get foctorials
# =============================
def Fact(iNum):

    iSum = 1
    
    # iterate the loop from 2 to iNumber+1 times
    for iNo in range(2,(iNum+1)):

        # Perform calculation
        iSum = iSum * iNo

    return iSum
# ==================
# Entry Function
# ==================
def main():

    # Accept user input
    iNumber = int(input("Enter the number for factorial : "))

    # Call to function
    print("Factorial of a given number is : ",Fact(iNumber))
    
# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry" function
    main()
