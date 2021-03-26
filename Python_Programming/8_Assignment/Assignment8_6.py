# ================================================================
# Design python application which contains two threads named as
# thread1 and thread2. Thread1 display 1 to 50 on screen and thread2
# display 50 to 1 in reverse order on screen. Use synchronization
# technique
# ================================================================
import threading

# ==============================================
# Thread1 : Display 1 to 50 on screen
# ==============================================
def Thread1(lock):

    # apply lock
    lock.acquire()  

    # Iterate the loop
    for iNum in range(50):

        print("Thread1 : ",iNum+1)

    # release lock
    lock.release()

# ==============================================
# Thread2 : Display 50 to 1 on screen
# ==============================================
def Thread2(lock):

    # apply lock
    lock.acquire()
    
    # Iterate the loop
    for iNum in range(50, 0, -1):

        print("Thread2 : ",iNum)

    # release lock
    lock.release()

# ==================
# Entry Function
# ==================
def main():

    lck = threading.Lock()
    
    # create thread
    thrd1 = threading.Thread(target=Thread1,args=(lck,))
    thrd2 = threading.Thread(target=Thread2,args=(lck,))

    # Start the threads
    thrd1.start()
    thrd2.start()

    # wait parent
    thrd1.join()
    thrd2.join()
    

# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry point" function
    main()
