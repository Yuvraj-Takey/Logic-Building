# ================================================================
# Write a recursive program which display below pattern.
#
#   5 4 3 2 1
# ================================================================

# ==============================================
# PatternNumber : prints the given pattern 
# ==============================================
def PatternNumber(iSize):

    # Recursion stop condition
    if(iSize == 0):
        return

    # Print the pattern
    print("{}  ".format(iSize), end="")

    # Recursion Continue condition, CAll to function
    PatternNumber(iSize-1)

# ==================
# Entry Function
# ==================
def main():

    # Accept the input from user
    iSize = int(input("Enter the size : "))
    
    # Call to the fuction
    PatternNumber(iSize)

# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry point" function
    main()
