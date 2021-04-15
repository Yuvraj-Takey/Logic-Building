# ================================================================
# Write a program which accepts file name from user and check
# whether that file exists in current directory or not.
#
# Input : Demo.txt
# Check whether Demo.txt exists or not.
# ================================================================
import os

# ==================
# Entry Function
# ==================
def main():

    # Accept the name from user
    fName = input("Enter the filename : ")

    # check the file
    if(os.path.exists(fName)):
        print("\n> The given file is exist\n")
    else:
        print("\n> The given file is not exist\n")

# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry point" function
    main()
