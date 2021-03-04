# ================================================================
# Write a recursive program which display below pattern.
#
#   1 2 3 4 5
# ================================================================

# ================================================
# PatternNumber : prints number range recursively
# ================================================
def PatternNumber(iSize):

    # Recursion stop condition
    if(iSize == 0):
        return

    # Recursion continue condition
    PatternNumber(iSize-1)
    
    # Print the patterm
    print(" {} ".format(iSize), end="")

# ==================
# Entry Function
# ==================
def main():

    # Accept the size of number-range
    iSize = int(input("Enter the number : "))
    
    # Call to the function
    PatternNumber(iSize)

# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry point" function
    main()
