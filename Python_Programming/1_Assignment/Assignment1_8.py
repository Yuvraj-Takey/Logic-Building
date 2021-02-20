# ================================================================
# Write a program which accept number from user and print that
# number of “*” on screen.
# ================================================================

# ===============================
# PrintStar : print * on screen
# ===============================
def PrintStar(iNum):

    # iterate the loop till iNum
    for index in range(iNum):
        print("* \t", end=" ")
        
# ==================
# Entry Function
# ==================
def main():

    # accept the number from user
    iNumber = int(input("Enter a number : "))

    # call the function
    PrintStar(iNumber)

# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry" function
    main()
