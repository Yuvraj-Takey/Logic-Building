# ==============================================================================
# Write a program which contains one class named as BankAccount.
# BankAccount class contains two instance variables as Name & Amount.
# That class contains one class variable as ROI which is initialise to 10.5.
# Inside init method initialise all name and amount variables by accepting the
# values from user. There are Four instance methods inside class as Display(),
# Deposit(), Withdraw(), CalculateIntrest(). Deposit() method will accept the
# amount from user and add that value in class instance variable Amount.
# Withdraw() method will accept amount to be withdrawn from user and subtract
# that amount from class instance variable Amount. CalculateIntrest() method
# calculate the interest based on Amount by considering rate of interest which
# is Class variable as ROI. And Display() method will display value of all the
# instance variables as Name and Amount. After designing the above class call
# all instance methods by creating multiple objects.
# ==============================================================================

# ==============================================
# Class BankAccount : Bank operations
# ==============================================
class BankAccount:

    # Class Variable
    ROI = 10.5

    # Like constructor
    # ================================
    def __init__(self):

        # Accept the values from user
        name = input("Enter the customer name : ")
        amount = int(input("Enter the basic amount : "))
        
        # Instance Variable
        self.Name = name
        self.Amount = amount

    # ================================
    def Display(self):

        # Output
        print("Name : ", self.Name)
        print("Amount : ",self.Amount)
    
    # ================================
    def Deposite(self):

        # Accept input
        ivalue = int(input("Enter the Deposite amount : "))

        # update the database
        self.Amount = self.Amount + ivalue
        
    # ================================
    def Withdraw(self):

        # Accept input
        ivalue = int(input("Enter the Withdraw amount : "))

        # update the database
        self.Amount = self.Amount - ivalue
        
    # ================================
    def CalculateInterest(self):

        # Calculate ROI
        rateofint = (self.Amount * BankAccount.ROI * 1)/100

        # Output
        print("Interest is : ", rateofint)


# ==================
# Entry Function
# ==================
def main():

    # create the object
    obj1 = BankAccount()

    # Invoke class methods
    obj1.Deposite()
    obj1.Display()
    obj1.Withdraw()
    obj1.Display()
    obj1.CalculateInterest()

# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry point" function
    main()
