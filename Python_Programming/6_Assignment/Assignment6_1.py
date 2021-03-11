# ================================================================
# Write a program which contains one class named as Demo.
# Demo class contains two instance variables as no1 ,no2.
# That class contains one class variable as Value.
# There are two instance methods of class as Fun and Gun which
# displays values of instance variables.
# Initialise instance variable in init method by accepting the
# values from user and perform operations
#
# ================================================================

# ==============================================
# Class Demo : Basic class structure
# ==============================================
class Demo:

    # Class Variable
    iValue = 999

    # Like Constructor
    # -------------------------
    def __init__(self, val1, val2):

        # Initialize Instance variable
        self.no1 = val1
        self.no2 = val2

    # -------------------------
    def fun(self):

        # output
        print("Value of Instance variable no1 is : ",self.no1)
        print("Value of Instance variable no2 is : ",self.no2)

    # -------------------------
    def gun(self):

        # output
        print("Value of Class variable iValue is : ",self.iValue)

# ==================
# Entry Function
# ==================
def main():

    # Accept values from user
    iNo1 = int(input("Enter the value for no1 : "))
    iNo2 = int(input("Enter the value for no2 : "))

    # Create class object
    obj1 = Demo(iNo1, iNo2)
    obj2 = Demo(51, 101)

    # change class variable value
    Demo.iValue = 777       # Reflect to complete class
    obj1.iValue = 888       # Reflect in instance

    # Invoke class methods
    obj1.fun()
    obj2.fun()
    obj1.gun()
    obj2.gun()


# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry point" function
    main()
