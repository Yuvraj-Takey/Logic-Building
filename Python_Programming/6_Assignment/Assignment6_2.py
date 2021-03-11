# ==============================================================================
# Write a program which contains one class named as Circle.
# Circle class contains three instance variables as Radius ,Area, Circumference.
# That class contains one class variable as PI which is initialise to 3.14.
# Inside init method initialise all instance variables to 0.0.
# There are three instance methods inside class as Accept(), CalculateArea(),
# CalculateCircumference(), Display().
# Accept method will accept value of Radius from user.
# CalculateArea() method will calculate area of circle and store it into instance
# variable Area. CalculateCircumference() method will calculate circumference of
# circle and store it into instance variable Circumference. And Display() method
# will display value of all the instance variables as Radius , Area, Circumference.
# After designing the above class call all instance methods by creating multiple
# objects.
# ==============================================================================

# ==============================================
# Class Circle : performs operation on circle
# ==============================================
class circle:

    # class variable
    PI = 3.14
    
    # Like constructor
    #-----------------------------------
    def __init__(self):

        # instance variable
        self.Radius = 0.0
        self.Area = 0.0
        self.Circumference = 0.0

    #-----------------------------------
    def Accept(self):

        # Get input
        self.Radius = float(input("Enter the value of radius : "))

    #-----------------------------------
    def CalculateArea(self):

        # Make calculations
        self.Area = (self.PI * (self.Radius**2))

    #-----------------------------------
    def CalculateCircumference(self):

        # Make calculation
        self.Circumference = (2 * self.PI * self.Radius)

    #-----------------------------------
    def Display(self):

        # Output
        print("Radius of a circle is : ",self.Radius)
        print("Area of circle is : ",self.Area)
        print("Area of circumference is : ",self.Circumference)


# ==================
# Entry Function
# ==================
def main():

    # create object of a class
    cobj = circle()

    # Invoke instance functions
    cobj.Accept()
    cobj.CalculateArea()
    cobj.CalculateCircumference()
    cobj.Display()
    

# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry" function
    main()
