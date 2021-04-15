# ================================================================
# Write a program which accept file name from user and open that
# file and display the contents of that file on screen.
# ================================================================

# ==================
# Entry Function
# ==================
def main():
    
    # Accept the input from user
    fName = input("Enter the file name : ")

    # open the given file
    fObj = open(fName, 'r')

    # Read the content from opened file
    fileData = fObj.read()

    # Output
    print("File contents are : \n", fileData)

    # Close the file
    fObj.close()

# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry point" function
    main()
