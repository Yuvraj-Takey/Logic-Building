# ================================================================
# Write a program which accept one number form user and return
# addition of its factors
# ================================================================

# ===================================
# Factors :  get addition of factors
# ===================================
def Factors(iNum):

    iSum = 0

    # Iterate the loop from 1 to the given number
    for iNo in range(1, iNum):

        # check for condition for division
        if(iNum % iNo == 0):

            # Perform the addition of factors
            iSum = iSum + iNo

            #print(iNo, end=" ")

    return iSum
# ==================
# Entry Function
# ==================
def main():

    # Accept user input
    iNumber = int(input("Enter a number : "))

    # call the function
    iRet = Factors(iNumber)

    # Output
    print("Addition of factors is : ", iRet)

# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry" function
    main()
