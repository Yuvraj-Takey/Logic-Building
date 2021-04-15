# ================================================================
# Write a program which accept two file names from user and compare
# contents of both the files. If both the files contains same
# contents then display success otherwise display failure. Accept
# names of both the files from command line.
# ================================================================
import sys

# ==============================================
# CmpFile :  compare two given files
# ==============================================
def CmpFile(file1, file2):

    fileStatus = True

    # open both the files in read mode
    f1 = open(file1,'r')
    f2 = open(file2,'r')

    # read both the files
    fileData1 = f1.read()
    fileData2 = f2.read()

    # check the length of both files
    if(len(fileData1) != len(fileData2)):
        fileStatus = False

    else:

        # iterate the memory buffer
        for iInd in range(len(fileData1)):

            # Check the data
            if( fileData1[iInd] != fileData2[iInd] ):

                fileStatus = False
                break;

    return fileStatus

# ==================
# Entry Function
# ==================
def main():

    # Filter the CMD input
    if(len(sys.argv) != 3):
        print("[SORRY]\ninput-> <pyFile> <FileName1> <FileName2>")
        return

    # call to the method
    if(CmpFile(sys.argv[1], sys.argv[2])):
        print("\nBoth the files are same\n")
    else:
        print("\nBoth the files are not same\n")

# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry point" function
    main()
