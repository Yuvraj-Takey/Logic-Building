# ================================================================
# Write a program which contains one function that accept one
# number from user and returns true if number is divisible by 5
# otherwise return false
# ================================================================

# =================================
# CheckDivi : check divisible by 5
# =================================
def CheckDivi(iNum):

    # Use filter for the condition
    if (iNum % 5 == 0):
        return True
    else:
        return False
   
# ==================
# Entry Function
# ==================
def main():

    # User input
    iNumber = int(input("Enter a number to check divisibility of 5 : "))

    # Check and call to function
    if(CheckDivi(iNumber)):
        print("True")
    else:
        print("False")

# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry" function
    main()
