# ================================================================
# Write a program which display 10 to 1 on screen
# ================================================================

# ===========================
# Display : iterate reverse
# ===========================
def Display():
    
    # iterate the loop in reverse order
    for index in range(10, 0, -1):
        print(index,"\t", end=" ")

# ==================
# Entry Function
# ==================
def main():

    # call to function
    Display()

# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry" function
    main()
