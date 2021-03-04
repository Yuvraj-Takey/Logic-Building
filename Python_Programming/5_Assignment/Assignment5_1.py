# ================================================================
# Write a recursive program which display below pattern
#
#   * * * * *
# ================================================================

# ==============================================
# PatternStar :  Print the given pattern
# ==============================================
def PatternStar(iSize):

    # Recursion Stop condition
    if(iSize == 0):
        return

    # Print pattern
    print(" * ", end=" ")

    # Recursion Continue condition, Call again
    PatternStar(iSize-1)

# ==================
# Entry Function
# ==================
def main():

    # Accept input from user
    starSize = int(input("Eneter the size of star : "))

    # Call to function
    PatternStar(starSize)

# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry point" function
    main()
