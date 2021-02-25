# ================================================================
# Write a program which contains filter(), map() and reduce() in it.
# Python application which contains one list of numbers. List
# contains the numbers which are accepted from user. Filter should
# filter out all prime numbers. Map function will multiply each
# number by 2. Reduce will return Maximum number from that numbers.
# ================================================================

import functools

# ===================================
# GetPrime : Get prime number status
# ===================================
def GetPrime(iNum):

    status = True

    # iterate the loop from 2 to iNum-1
    for iNo in range(2, iNum):

        # If the numbeer in not prime then mark the staus as
        # false and break the loop
        if(iNum % iNo == 0):

            status = False
            break;

    return status

# ===================================
# GetMax : lambda function
# ===================================

# Explain : Return 1st Number "if" (condition True) "else" Return 2nd Number
GetMax = lambda iNo1, iNo2 : (iNo1 if (iNo1 > iNo2) else iNo2)

# ================================================
# FMR_Operation : Performs operation with filter
#                 map and reduce
# ================================================
def FMR_Operation(iList):

    # Call to filter function to filter out required stuff
    iList = list(filter(GetPrime,iList))
    print("Filtered numbers are : ", iList)

    # Call to map function to map new values to the filtered list
    iList = list(map(lambda iNo : (iNo * 2), iList))
    print("Maped numbers are : ",iList)

    # Call to reduce function to get maximum number from list
    iRet = functools.reduce(GetMax, iList)
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
