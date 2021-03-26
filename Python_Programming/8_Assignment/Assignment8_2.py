# ================================================================
# Design python application which creates two threads as evenfactor
# and oddfactor. Both the thread accept one parameter as integer.
# Evenfactor thread will display addition of even factors of given
# number and oddfactor will display addition of odd factors of given
# number. After execution of both the thread gets completed main
# thread should display message as “exit from main”
#
# ================================================================
import threading as multithreading

# ==============================================
# GetFact : Get factors of a given number
# ==============================================
def GetFact(iNumber):

    iList = []
    
    # iterate the loop
    for iNo in range(1,iNumber+1):

        # check the number
        if(iNumber % iNo == 0):

            # Append the factors in a list
            iList.append(iNo)

    return iList

# ==============================================
# EvenFact : Get the addition of all even factors
# ==============================================
def EvenFact(iNumber):

    iAdd = 0

    # get the factors of a given number
    iList = GetFact(iNumber)

    # iterate the list
    for iNo in iList:

        # check for Even number
        if(iNo % 2 == 0):

            # add the number
            iAdd = iAdd + iNo
            
    print("Addition of all even factors is : ", iAdd)

# ==============================================
# OddFact : Get the addition of all odd factors
# ==============================================
def OddFact(iNumber):

    iAdd = 0

    # get the factors of a given number
    iList = GetFact(iNumber)

    # iterate the list
    for iNo in iList:

        # check for Odd number
        if(iNo % 2 != 0):

            # add the number
            iAdd = iAdd + iNo
            
    print("Addition of all odd factors is : ", iAdd)

# ==================
# Entry Function
# ==================
def main():

    # Accept the input from user
    iNumber = int(input("Enter the number : "))
    
    # Create two threads
    Thrd1 = multithreading.Thread(target=EvenFact, args=(iNumber,))
    Thrd2 = multithreading.Thread(target=OddFact, args=(iNumber,))

    # Start the threads
    Thrd1.start()
    Thrd2.start()

    # Wait parent
    Thrd1.join()
    Thrd2.join()

    # Print statement
    print("exit from main")

# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry point" function
    main()
