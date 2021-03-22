# =========================================================================
# Write a program which contains one class named as BookStore.
# BookStore class contains two instance variables as Name ,Author.
# That class contains one class variable as NoOfBooks which is
# initialise to 0. There is one instance methods of class as
# Display which displays name , Author and number of books.
# Initialise instance variable in init method by accepting the
# values from user as name and author. Inside init method
# increment value of NoOfBooks by one. After creating the class
# create the two objects of BookStore class as
# Obj1 = BookStore(“Linux System Programming”, “Robert Love”)
# Obj1.Display() # Linux System Programming by Robert Love. No of books : 1
# Obj2 = BookStore(“C Programming”, “Dennis Ritchie”)
# Obj2.Display() # C Programming by Dennis Ritchie. No of books : 2
# =========================================================================

# ==============================================
# Class Bookstore : Maintains book information
# ==============================================
class Bookstore:

    # class variable
    NoOfBooks = 0

    # Like constructor
    # ================================
    def __init__(self, name, author):

        # instance variable
        self.Name = name
        self.Author = author

        # increment book count - class variable
        Bookstore.NoOfBooks = Bookstore.NoOfBooks + 1 

    # ================================
    def Display(self):

        #Output
        print("Name : ",self.Name)
        print("Author : ",self.Author)
        print("No. of Books : ",Bookstore.NoOfBooks)


# ==================
# Entry Function
# ==================
def main():

    # Create an object
    obj1 = Bookstore("Linux System Programming", "Robert Love")

    # Invoke class method
    obj1.Display()

    # Another object
    obj2 = Bookstore("C Programming","Dennis Ritchie")

    # Invoke class method
    obj2.Display()
    

# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry point" function
    main()
