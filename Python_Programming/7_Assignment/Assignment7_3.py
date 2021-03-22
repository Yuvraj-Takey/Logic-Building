# ===========================================================================
# Write a program which contains one class named as Numbers.
# Arithmetic class contains one instance variables as Value.
# Inside init method initialise that instance variables to the value which
# is accepted from user. There are four instance methods inside class as
# ChkPrime(), ChkPerfect(), SumFactors(),Factors().
# ChkPrime() method will returns true if number is prime otherwise return false.
# ChkPerfect() method will returns true if number is perfect otherwise return false.
# Factors() method will display all factors of instance variable.
# SumFactors() method will return addition of all factors. Use this method in any
# another method as a helper method if required.
# After designing the above class call all instance methods by creating multiple
# objects.
# ===========================================================================

# ==============================================
# Class Number : perform number operation
# ==============================================
class Number:

    # Constructor
    # ===================================
    def __init__(self):

        # Accept input from user
        value = int(input("Enter the value for operation : "))
        
        # Instance Variable
        self.iValue = value

    # ===================================
    def ChkPrime(self):

        # a number that is divisible only by itself and 1

        iNum = -1

        # Iterate the loop from 2 to number-1
        for iNum in range(2, self.iValue):

            # divide the number with iNum
            if( self.iValue % iNum == 0):

                # if control comes here, means the number has divisor
                iNum = 0
                break

        # check the status of above loop
        if( (iNum == 0) & (self.iValue != 1) ):
            return False
        else:
            return True

    # ===================================
    def GetDivisors(self, iNum):

        iList = []

        # Iterate the loop
        for iNo in range(1,iNum+1):

            # Get divisor
            if(iNum % iNo == 0):

                # Add the number to the list
                iList.append(iNo)
                
        return iList
    
    # ===================================
    def ChkPerfect(self):

        # a perfect number is a positive
        # integer that is equal to the sum of its positive divisors,
        # excluding the number itself

        # Get all divisors of the given number
        iDivisor = self.GetDivisors(self.iValue)

        iSum = 0
        
        # iterate the loop
        for iNum in iDivisor[:-1]:

            # make addition of all divisors
            iSum = iSum + iNum

        # check the status
        if(iSum == self.iValue):
            return True
        else:
            return False
            
    
    # ===================================
    def Factors(self):

        # Output
        print("Factors of a given number is : ",self.GetDivisors(self.iValue))
    
    # ===================================
    def SumFactors(self):
        
        # Get all divisors of the given number
        iDivisor = self.GetDivisors(self.iValue)

        iSum = 0
        
        # iterate the loop
        for iNum in iDivisor:

            # make addition of all divisors
            iSum = iSum + iNum

        # Output
        print("Addition of all factors of a give number is : ", iSum)


# ==================
# Entry Function
# ==================
def main():

    # create class object
    obj = Number()

    # Invoke class methods
    if(obj.ChkPrime()):
        print("The given number is prime")
    else:
        print("The given number is not prime")

    # Invoke class methods
    if(obj.ChkPerfect()):
        print("The given number is perfect")
    else:
        print("The given number is not perfect")

    # Invoke class methods
    obj.Factors()

    # Invoke class methods
    obj.SumFactors()

# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry point" function
    main()
