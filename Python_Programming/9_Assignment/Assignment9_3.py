# ================================================================
# Write a program which accept file name from user and create new
# file named as Demo.txt and copy all contents from existing file
# into new file. Accept file name through command line arguments
# ================================================================
import sys

# ==============================================
# FileOp : Copy the content from given file into
#           new file.
# ==============================================
def FileOp(fName):

    # Open the given-existing file
    fObR = open(fName,'r')

    # get the content from the opened file
    fileData = fObR.read()

    # Create the new file
    fObW = open("Demo2.txt", 'w')

    # Write the data into new file
    fObW.write(fileData)

    # close all files
    fObR.close()
    fObW.close()

# ==================
# Entry Function
# ==================
def main():
    
    # validate the inputs
    if( len(sys.argv) != 2):
        print("SORRY: \ninput: <pyFile> <FileName>")

        return
    
    # Get command-line inputs
    fName = sys.argv[1]
    
    # Make file operation
    FileOp(fName)

# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry point" function
    main()
