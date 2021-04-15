# ==================================================================
# Accept file name and one string from user and return the frequency
# of that string from file
# ==================================================================
import sys
# ===========================================================
# FreqCnt : Calculate the frequency count of a given string
#           from the given file
# ===========================================================
def FreqCnt(fileName, strData):

    # Open the file
    fileN = open(fileName,'r')

    # read the file
    data = fileN.read()

    cnt = 0

    # iterate the file's data
    for sData in data.split(' '):

        # split the data on \n
        for iData in sData.split('\n'):

            # match the data, and increment the count
            if(strData == iData):
                cnt = cnt + 1

    return cnt
    

# ==================
# Entry Function
# ==================
def main():

    # Accept input from user
    if(len(sys.argv) != 3):
        print("[SORRY]\nInput <pyFile> <FileName> <String>")
        return

    # make the method call
    freI = FreqCnt(sys.argv[1],sys.argv[2])

    # output
    print("The frequency count of the string in the file is : ", freI)

# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry point" function
    main()
