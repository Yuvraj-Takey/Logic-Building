# ================================================================
# Write a program which accept N numbers from user and store it
# into List. Return Minimum number from that List.
# ================================================================

# ====================================
# MinNum : Get maximum from the list
# ====================================
def MinNum(iNumList):

    # Set the initial value to minimum
    iMin = iNumList[0]

    # iterate the complete given list
    for iNum in iNumList:

        # check for minimum value
        if(iMin > iNum):

            # change the variable to minimum number
            iMin = iNum

    return iMin

# ==================
# Entry Function
# ==================
def main():

    iList=[]

    # Accept the inpit size
    iSize = int(input("Enter the size of input list : "))
    
    # Accept the input from user
    for iNo in range(iSize):
        iValue = int(input("Enter the number : "))

        # Append the input value to the list
        iList.append(iValue)
    
    # call to the function
    print("The minimum value from the given list",MinNum(iList))

# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry point" function
    main()
