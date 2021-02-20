# ==================================================================
# Write a program which accept one number and display below pattern
#
#       * * *
#       * *
#       * 
# ==================================================================

# =============================
# Pattern :  get a pattern
# =============================
def Pattern(iSize):

    # iterate 0 to iSize
    for iIndex in range(iSize):

        # iterate form iSize to iIndex [reversely]
        for jIndex in range(iSize, iIndex , -1):

            # Print the pattern
            print("*\t", end=" ")
            
        print("\n")
# ==================
# Entry Function
# ==================
def main():

    # Accept user input
    iSize = int(input("Enter the size of pattern : "))
    
    # Call to function
    Pattern(iSize)

# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry" function
    main()
