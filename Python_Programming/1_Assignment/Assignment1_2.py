# ================================================================
# Write a program which contains one function named as ChkNum()
# which accept one parameter as number. If number is even then
# it should display “Even number” otherwise display “Odd number”
# on console
# ================================================================

# ==================
# ChkNum : Even-Odd
# ==================
def ChkNum(number):

    # Check the even number
    if((number % 2) == 0):
        print("Even Number")
    else:
        print("Odd Number")
        
# ==================
# Entry Function
# ==================
def main():

    iNum = 11

    # Call to function
    ChkNum(iNum)

# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry point" function
    main()
