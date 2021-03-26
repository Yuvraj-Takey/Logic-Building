# ================================================================
# Design python application which creates two threads as evenlist
# and oddlist. Both the threads accept list of integers as parameter.
# Evenlist thread add all even elements from input list and display
# the addition. Oddlist thread add all odd elements from input
# list and display the addition
# ================================================================

import threading

# ================================================
# EvenList : Display addition of all even elements
# ================================================
def EvenList(iList):

    iSum = 0

    # Iterate the list
    for iNo in iList:

        # check for Even number
        if(iNo % 2 == 0):

            # perform addition
            iSum = iSum + iNo

    print("Addition of all Even element is : ", iSum)
    
# ===============================================
# OddList :  Display addition of all odd elements
# ===============================================
def OddList(iList):

    iSum = 0

    # Iterate the list
    for iNo in iList:

        # check for Odd number
        if(iNo % 2 != 0):

            # perform addition
            iSum = iSum + iNo

    print("Addition of all Odd element is : ", iSum)
    

# ==================
# Entry Function
# ==================
def main():

    iList = []
    
    # Accept the list size from user
    iSize = int(input("Enter the size of list : "))

    print("Enter the element step by step ")
    
    # get the values in the list
    for ind in range(iSize):

        # append the element in the list
        iList.append(int(input("> ")))


    # create the threads
    Thrd1 = threading.Thread(target=EvenList, args=(iList,))
    Thrd2 = threading.Thread(target=OddList, args=(iList,))

    # Start the thread
    Thrd1.start()
    Thrd2.start()

    # wait the parent
    Thrd1.join()
    Thrd2.join()
    

# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry point" function
    main()
