# ================================================================
# Write a program which accept N numbers from user and store it
# into List. Return addition of all prime numbers from that List.
# Main python file accepts N numbers from user and pass each number
# to ChkPrime() function which is part of our user defined module
# named as MarvellousNum. Name of the function from main python
# file should be ListPrime().
# ================================================================
import MarvellousNum as mvn


# ========================================================
# ListPrime : Returns additionos prime numbers from list
# ========================================================
def ListPrime(iList):

    iSum = 0

    # Iterate the complete input list
    for iNum in iList:

        # verify the prime number
        if(mvn.ChkPrime(iNum)):

            # perform addtion of prime number
            iSum = iSum + iNum
            
    return iSum

# ==================
# Entry Function
# ==================
def main():

    iList = []
    
    # Accept the size of input list
    iSize = int(input("Enter the size of input list : "))

    # Accept the values into list
    for iNo in range(iSize):
        iValue = int(input("Enter the number : "))

        # Append value to the list
        iList.append(iValue)
        
    # Call to the function
    iRet = ListPrime(iList)

    # Output
    print("The addition of all prime number is : ",iRet)

# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry point" function
    main()
