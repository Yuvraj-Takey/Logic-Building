# ================================================================
# Write a program which accept one number and display below pattern
#       * * * * *
#       * * * * *
# ================================================================

# =============================
# Pattern : Drow a pattern
# =============================
def Pattern(iSize):

    # iterate the outer loop
    for Iindex in range(iSize):

       # iterate the outer loop
        for Jindex in range(iSize):

            #print the pattern
            print("*\t", end=" ")

        # next line break
        print("\n")

# ==================
# Entry Function
# ==================
def main():

    # Accept user input for pattern
    iPatSize = int(input("Enter the size for pattern : "))

    # call to function
    Pattern(iPatSize)    
    

# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry" function
    main()
