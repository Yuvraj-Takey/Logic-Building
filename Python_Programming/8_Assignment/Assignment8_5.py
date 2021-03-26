# ================================================================
# Design python application which contains two threads named as
# thread1 and thread2. Thread1 display 1 to 50 on screen and thread2
# display 50 to 1 in reverse order on screen. After execution of
# thread1 gets completed then schedule thread2
# ================================================================
import threading

# ==============================================
# Thread1 : Display 1 to 50 on screen
# ==============================================
def Thread1():

    # Iterate the loop
    for iNum in range(50):

        print("Thread1 : ",iNum+1)

# ==============================================
# Thread2 : Display 50 to 1 on screen
# ==============================================
def Thread2():
    
    # Iterate the loop
    for iNum in range(50, 0, -1):

        print("Thread2 : ",iNum)

# ==================
# Entry Function
# ==================
def main():
    
    # create thread
    thrd1 = threading.Thread(target=Thread1)
    thrd2 = threading.Thread(target=Thread2)

    # Start the thread1 and wait to parent 
    thrd1.start()
    thrd1.join()

    # Start the thread1 and wait to parent 
    thrd2.start()
    thrd2.join()
    

# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry point" function
    main()
