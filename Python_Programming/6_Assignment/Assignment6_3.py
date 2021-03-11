# =========================================================================================
# Write a program which contains one class named as Arithmetic.
# Arithmetic class contains three instance variables as Value1 ,Value2.
# Inside init method initialise all instance variables to 0.
# There are three instance methods inside class as Accept(), Addition(),
# Subtraction(), Multiplication(), Division().
# Accept method will accept value of Value1 and Value2 from user.
# Addition() method will perform addition of Value1 ,Value2 and return result.
# Subtraction() method will perform subtraction of Value1 ,Value2 and return result.
# Multiplication() method will perform multiplication of Value1 ,Value2 and return result.
# Division() method will perform division of Value1 ,Value2 and return result.
# After designing the above class call all instance methods by creating multiple objects.
# =========================================================================================

# ==============================================
# Class Arithmetic : Arithmetic calculations
# ==============================================
class Arithmetic:

    # Like Constructor
    # ------------------------------
    def __init__(self):

        # initialize instance variables
        self.Value1 = 0
        self.Value2 = 0 
        self.Value3 = 0

    # ------------------------------
    def Accept(self):

        # Accept values from user
        self.Value1 = int(input("Enter the first value for calculation : "))
        self.Value2 = int(input("Enter the second value for calculation : "))

    # ------------------------------
    def Addition(self):
        
        # Perform calculation
        self.Value3 = self.Value1 + self.Value2

        return self.Value3

    # ------------------------------
    def Substraction(self):

        # Perform calculation
        self.Value3 = self.Value1 - self.Value2

        return self.Value3

    # ------------------------------
    def Multiplication(self):

        # Perform calculation
        self.Value3 = self.Value1 * self.Value2

        return self.Value3

    # ------------------------------
    def Division(self):

        # Perform calculation
        self.Value3 = float(self.Value1) / float(self.Value2)

        return self.Value3

    
# ==================
# Entry Function
# ==================
def main():

    # Create class object
    aobj = Arithmetic()

    # Invoke instance methods
    aobj.Accept()

    print("Addition of given number is : ",aobj.Addition())
    print("Substraction of given number is : ",aobj.Substraction())
    print("Multiplication of given number is : ",aobj.Multiplication())
    print("Division of given number is : ",aobj.Division())

    # delete object
    del aobj
    #aobj.Accept()   # NOT Allow
    

# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry point" function
    main()
