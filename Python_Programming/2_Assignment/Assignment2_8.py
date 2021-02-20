# ===================================================================
# Write a program which accept one number and display below pattern
#
#       1 
#       1 2 
#       1 2 3
# ===================================================================

# =============================
# Pattern : Print the pattern
# =============================
def Pattern(iSize):

    # Iterate the iLoop till iSize
    for iIndex in range(iSize):
        
        # Iterate the iLoop till iSize
        for jIndex in range(iIndex+1):

            # Print the pattern
            print((jIndex+1),"\t",end=" ")

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
