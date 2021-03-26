# ================================================================
# Design python application which creates three threads as small,
# capital, digits. All the threads accepts string as parameter.
# Small thread display number of small characters, capital thread
# display number of capital characters and digits thread display
# number of digits. Display id and name of each thread.
# ================================================================
import threading

# ============================================================
# SmallChars : get the count of small chars from input string
# ============================================================
def SmallChars(sValue):

    print("\nThread ID : {}[{}]\t Thread Name : {}".format(threading.get_ident(),
                                                         threading.get_native_id(),
                                                         threading.currentThread().getName()))

    iCnt = 0
    
    # Iterate the complete string one-by-one
    for char in sValue:

        # filter
        if(char >= 'a' and char <= 'z'):

            iCnt = iCnt + 1

    print("Count of all small chars is : ", iCnt)

        
# ============================================================
# CapChars : get the count of capital chars from input string
# ============================================================
def CapChars(sValue):

    print("\nThread ID : {}[{}]\t Thread Name : {}".format(threading.get_ident(),
                                                         threading.get_native_id(),
                                                         threading.currentThread().getName()))

    iCnt = 0
    
    # Iterate the complete string one-by-one
    for char in sValue:

        # filter
        if(char >= 'A' and char <= 'Z'):

            iCnt = iCnt + 1

    print("Count of all capital chars is : ", iCnt)

# ============================================================
# Digits: get the count of digits from input string
# ============================================================
def Digits(sValue):

    print("\nThread ID : {}[{}]\t Thread Name : {}".format(threading.get_ident(),
                                                         threading.get_native_id(),
                                                         threading.currentThread().getName()))

    iCnt = 0
    
    # Iterate the complete string one-by-one
    for char in sValue:

        # filter
        if(char >= '0' and char <= '9'):

            iCnt = iCnt + 1

    print("Count of all digits is : ", iCnt)

# ==================
# Entry Function
# ==================
def main():

    # Accept the input from user
    sValue = input("Enter the random string (include: small, capital chars and digits \n> ")

    # Create the threads
    tSmall = threading.Thread(target=SmallChars, args=(sValue,))
    tCap = threading.Thread(target=CapChars, args=(sValue,))
    tDigit = threading.Thread(target=Digits, args=(sValue,))

    # start the threads
    tSmall.start()
    tCap.start()
    tDigit.start()

    # wait the parent
    tSmall.join()
    tCap.join()
    tDigit.join()

    
# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry point" function
    main()
