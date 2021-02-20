# ================================================================
# Write a program which accept name from user and display length
# of its name
# ================================================================

# =====================================
# NameLen : get length of the string
# =====================================
def NameLen(sName):

    # Print the length of given string
    print("Length of the given string is : ", len(sName))
    
# ==================
# Entry Function
# ==================
def main():

    # Get input from user
    getName = input("Enter the string name : ")
    NameLen(getName)

# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry" function
    main()
