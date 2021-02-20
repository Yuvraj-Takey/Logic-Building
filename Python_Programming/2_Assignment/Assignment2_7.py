# ===================================================================
# Write a program which accept one number and display below pattern.
#
#       1 2 3
#       1 2 3
#       1 2 3
# ===================================================================

# =============================
# Pattern : Print the pattern
# =============================
def Pattern(iSize):

    # iterate the iLoop till iSize
    for iIndex in range(1, (iSize+1)):

        # iterate the jLoop till iSize
        for jIndex in range(1, (iSize+1)):

            # Print the pattern
            print(jIndex,"\t" , end=" ")
            
        print("\n")
        
# ==================
# Entry Function
# ==================
def main():

    # Accept the input from user
    iSize = int(input("Enter the size of pattern : "))
    
    # call to function
    Pattern(iSize)

# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry" function
    main()
