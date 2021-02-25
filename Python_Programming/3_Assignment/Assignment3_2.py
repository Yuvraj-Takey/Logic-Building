# ================================================================
# Write a program which accept N numbers from user and store it
# into List. Return Maximum number from that List
# ================================================================

# ===================================
# MaxNum : Get maximum from the list
# ===================================
def MaxNum(iList):

    # Set the initial value to iMax variable
    iMax = iList[0]

    #Iterate the complete list
    for iNo in iList:

        # Get the max number
        if(iMax < iNo):
            iMax = iNo
            
    return iMax

# ==================
# Entry Function
# ==================
def main():

    iList=[]

    # Accept user input for list size
    iSize = int(input("Enter the size of input numbers : "))

    # iterate the loop till the size
    for iNo in range(iSize):
        value = int(input("Enter the number : "))
        iList.append(value)

    # Call to the function
    print("The maximum number from the given list is : ",MaxNum(iList))

# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry point" function
    main()
