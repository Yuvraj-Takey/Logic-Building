# ================================================================
# Write a program which accept N numbers from user and store it
# into List. Accept one another number from user and return
# frequency of that number from List.
# ================================================================

# ==============================================
# FreqList : Get the frequency count from list
# ==============================================
def FreqList(iMatch, iList):

    iCnt = 0
    
    # Iterate the complete list till end
    for iNum in iList:

        # Compare each element and increment the matching count
        if(iMatch == iNum):
            iCnt = iCnt + 1

    return iCnt

# ==================
# Entry Function
# ==================
def main():

    iList = []
    
    # Accept the size of list form user
    iSize = int(input("Enter the size of the input variables : "))

    # Accept the element one-by-one into the list
    for iNo in range(iSize):
        iValue = int(input("Enter the value : "))

        # Add the value to list
        iList.append(iValue)

    # Accept the match variable from user
    iMatch = int(input("Enter the value for frequency count : "))
    
    # Call to the function
    print("The frequency of {} value is : {}".format(iMatch,FreqList(iMatch, iList)))

# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry point" function
    main()
