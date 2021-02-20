# ================================================================
# Write a program which display first 10 even numbers on screen.
# ================================================================

# =============================
# EvenList : get first 10 even 
# =============================
def EvenList():

    iNum = 1
    iIndex = 0

    # Iterate the loop till 10 times
    while(iIndex != 10):

        # Check for the even number
        if(iNum % 2 == 0):
            print(iNum, end=" ")

            # Increment the iIndex value out of 10
            iIndex = iIndex + 1

        # increment the iNum value to get next number
        iNum = iNum + 1
# ==================
# Entry Function
# ==================
def main():

    # Call the function to get list of even numbers
    EvenList()

# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry" function
    main()
