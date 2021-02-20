# ================================================================
# Create on module named as Arithmetic which contains 4 functions
# as Add() for addition, Sub() for subtraction, Mult() for
# multiplication and Div() for division. All functions accepts two
# parameters as number and perform the operation. Write on python
# program which call all the functions from Arithmetic module by
# accepting the parameters from user.
# ================================================================

# Import module
import Arithmetic as arithm

# ==========================================
# InvokeArth : make arithmatic calculation
# ==========================================
def InvokeArth(iNum1, iNum2):

    print("Arithmatic Operations\n")
    
    # Make addition
    iRet = arithm.Add(iNum1,iNum2)
    print("Addition of {} and {} is =>\t\t{}".format(iNum1,iNum2,iRet))

    # Make addition
    iRet = arithm.Sub(iNum1,iNum2)
    print("Substraction of {} and {} is =>\t\t{}".format(iNum1,iNum2,iRet))

    # Make addition
    iRet = arithm.Mult(iNum1,iNum2)
    print("Multiplication of {} and {} is =>\t{}".format(iNum1,iNum2,iRet))

    # Make addition
    iRet = arithm.Div(iNum1,iNum2)
    print("Division of {} and {} is =>\t\t{}".format(iNum1,iNum2,iRet))
    
# ==================
# Entry Function
# ==================
def main():

    # Accept inputs from user
    iNumber1 = int(input("Enter 1st number for Arthmatic : "))
    iNumber2 = int(input("Enter 2nd number for Arthmatic : "))

    # Call to function
    InvokeArth(iNumber1, iNumber2)

# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry" function
    main()
