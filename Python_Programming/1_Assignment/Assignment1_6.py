# ================================================================
# Write a program which accept number from user and check whether
# that number is positive or negative or zero.
# ================================================================

# =========================
# CheckNum : check number
# =========================
def CheckNum(iNum):

    # Use filter for the condition
    if (iNum == 0):
        print("Zero")

    elif(iNum < 0):
        print("Negative Number")
        
    else:
        print("Positive Number")
        
# ==================
# Entry Function
# ==================
def main():

    # User input
    iNumber = int(input("Enter a number (include positive/negative) : "))

    # Check and call to function
    CheckNum(iNumber)

# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry" function
    main()
