# ================================================================
# Design python application which creates two thread named as even
# and odd. Even thread will display first 10 even numbers and odd
# thread will display first 10 odd numbers.
# ================================================================

import threading

# ==============================================
# Even : get list of first 10 even numbers 
# ==============================================
def Even():

    iNum = 0
    iList = []

    # Iterate the loop till 10
    while(iNum != 10):

        # check for even number
        if(iNum % 2 == 0):

            # Add the entry into the list
            iList.append(iNum)

        # increment the number
        iNum = iNum + 1

    # Output
    print("Even Numbers : ", iList)

# ==============================================
# Odd : get list of first 10 odd numbers
# ==============================================
def Odd():

    iNum = 0
    iList = []

    # Iterate the loop till 10
    while(iNum != 10):

        # check for odd number
        if(iNum % 2 != 0):

            # Add the entry into the list
            iList.append(iNum)
            
        # increment the number
        iNum = iNum + 1

    # Output
    print("Odd Numbers : ", iList)
    
# ==================
# Entry Function
# ==================
def main():

    # Create Thread
    Thrd1 = threading.Thread(target=Even, args=())
    Thrd2 = threading.Thread(target=Odd, args=())

    # Start the thread
    Thrd1.start()
    Thrd2.start()

    # wait parent from their child
    Thrd1.join()
    Thrd2.join()

# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry point" function
    main()
