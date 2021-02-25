# ==================================================================
# Write a program which contains iFilter(), iMap() and iReduce() in it.
# Python application which contains one list of numbers. List contains
# the numbers which are accepted from user. iFilter should filter out
# all such numbers which greater than or equal to 70 and less than or
# equal to 90. iMap function will increase each number by 10. iReduce
# will return product of all that numbers.
# ================================================================

# =================================================
# iReduce : Calculate product of given numbers
# =================================================
def iReduce(iValues):

    iPro = 1
    
    # Iterate the list till end
    for iNo in iValues:

        # calculate
        iPro = iPro * iNo

    return iPro

# =================================================
# iMap : Map new values with existing input value
# =================================================
def iMap(iValues):

    # iterate the input list till end
    for iIndex in range(len(iValues)):

        # map new value with existing value
        iValues[iIndex] = iValues[iIndex] + 10

    return iValues
    
# =================================================
# iFilter : filter out required numbers from list
# =================================================
def iFilter(iValues):

    iNewList = []

    # iterate the list till end
    for iNo in iValues:

        # Make the filter
        if((iNo >= 70) & (iNo <= 90)):

            # Append the values in new list
            iNewList.append(iNo)

    return iNewList

# ==============================================
# FMR_Operation : Performs operation with Filter
#                 Map and reduce
# ==============================================
def FMR_Operation(iList):

    # Call to filter function to filter out required stuff
    iList = iFilter(iList)
    print("Filtered numbers are : ", iList)

    # Call to map function to map new values to the filtered list
    iList = iMap(iList)
    print("Maped numbers are : ",iList)

    iRet = iReduce(iList)
    print("Result of reduced number is : ", iRet)
    
# ==================
# Entry Function
# ==================
def main():

    iList = []
    iSize = 0

    # Accept the input size from user
    iSize = int(input("Enter the size for input-list : "))
    
    # Accept the input from user
    for iNo in range(iSize):
        value = int(input("Enter the number : "))

        # Add the value into list
        iList.append(value)
        
    # Call to the function
    FMR_Operation(iList)

# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry point" function
    main()
