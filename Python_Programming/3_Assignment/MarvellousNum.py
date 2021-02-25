# ===================================================
# Check prime number or not through separate module
# ===================================================

# ==================================
# ChkPrime : verify the prime number
# ==================================
def ChkPrime(iNum):

    status = True
    
    # Iterate the loop from 2 to iNum-1
    for iNo in range(2, iNum):

        # make filter for prime number
        if(iNum % iNo == 0):
            status = False
            break

    return status

