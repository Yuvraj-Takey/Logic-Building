# =======================================================================
# Write a program which contains filter(), map() and reduce() in it.
# Python application which contains one list of numbers. List
# contains the numbers which are accepted from user. Filter should
# filter out all such numbers which are even. Map function will
# calculate its square. Reduce will return addition of all that numbers.
# ========================================================================

import functools

# ==========================================
# getEven : Lamda functions for even number
# ==========================================
getEven = lambda iNo : (iNo % 2 == 0)

# ==========================================
# getSqur : Lamda functions for square
# ==========================================
getSqur = lambda iNo : (iNo * iNo)

# ==========================================
# getAdd : Lamda functions for addition
# ==========================================
getAdd = lambda iNo1, iNo2 : (iNo1 + iNo2)

# ==============================================
# FMR_Operation : Performs operation with filter
#                 map and reduce
# ==============================================
def FMR_Operation(iList):

    # Call to filter function to filter out required stuff
    iList = list(filter(getEven,iList))
    print("Filtered numbers are : ", iList)

    # Call to map function to map new values to the filtered list
    iList = list(map(getSqur, iList))
    print("Maped numbers are : ",iList)

    iRet = functools.reduce(getAdd, iList)
    print("Result of reduced number is : ", iRet)

# ==================
# Entry Function
# ==================
def main():

    iList = []

    # Accept the input size from user
    iSize = int(input("Enter the size for input list numbers : "))

    # Accept the numbers from user
    for iNo in range(iSize):
        value = int(input("Enter the number : "))

        # append the values into list
        iList.append(value)

    # Call to the function
    FMR_Operation(iList)

# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry point" function
    main()
