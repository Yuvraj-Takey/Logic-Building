# ================================================================
# Write a program which accept N numbers from user and store it
# into List. Return addition of all elements from that List
# ================================================================

# ============================
# AddList : add list elements
# ============================
def AddList(elements):

    iSum = 0

    # Iterate the complete given list
    for iNum in elements:

        # Add numbers 1-by-1
        iSum = iSum + iNum

    return iSum

# ==================
# Entry Function
# ==================
def main():

    iList = []

    # Accept from user
    iSize = int(input("Enter the size of input number : "))

    # Iterate the loop for accepting inputs
    for iNo in range(iSize):
        value = int(input("Enter the value : "))
        iList.append(value)

    # Call to the function
    print("The addition for the given numbers is : ",AddList(iList))

# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry point" function
    main()
