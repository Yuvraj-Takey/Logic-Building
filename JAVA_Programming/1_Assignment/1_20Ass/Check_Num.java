/*
 *	a Java Program to Check Whether a Number can be expressed as Sum of Two Prime Numbers.
 *
 *	@DSSD	- Yuvraj Takey
 */
 
 import java.lang.*;
 import java.util.Scanner;
 
 class CheckPrime
 {
 	int iPrime[];
 	final static int p_Arr_Size = 95;
 	
 	// default constructor
 	CheckPrime()
 	{
 		iPrime = new int[p_Arr_Size];
 	}
 	
 	// method check for prime
 	public boolean isPrime(int ino)
 	{
 		int index = 0, icnt = 0;

		// iterate till the given number 		
 		for(index = 1; index < ino; index++)
 		{
 			if((ino % index) == 0)
 			{
 				icnt++;
 			}
 		}
 		
 		if(icnt == 1)
 		{
 			return true;
 		}
 		else
 		{
 			return false;
 		}
 	}
 	
 	// method for get prime from range
 	public void getPrime()
 	{
 		int index = 0, jindex = 0;
 		
 		for(index = 1; index < 500; index++)
 		{
 			// check prime
 			if(isPrime(index))
 			{	
 				// store the prime number into array
 				iPrime[jindex++] = index;
 			}
 		}
 		
 		System.out.println();
 	}
 	
 	public void tellPrime(int iNumber)
 	{
 		int index = 0, jindex = 0;
 		
 		System.out.println("[INFO_] : Pair of Two prime numbers:");
 		
 		// iterate over prime array
 		for(index = 0; index < (p_Arr_Size-1); index++)
 		{
 			// iterate over prime array
 			for(jindex = index; (jindex < p_Arr_Size) && (iNumber >= iPrime[jindex]); jindex++)
 			{
 				// check for iNumber with sum of two prime numbers
 				if(iNumber == (iPrime[jindex] + iPrime[index]))
 				{
 					System.out.print("(" + iPrime[index] + "," + iPrime[jindex] + ")");
 				}
 			}
 		}
 		
 		System.out.println("\n");
 	}
 	
 }
 
 class Check_Num
 {
 	public static void main(String arg[])
 	{
 		System.out.println("HELLO PRIME OPERATION");
 		Scanner s = new Scanner(System.in);
 		int iNumber = 0;
 		
 		// get the object
 		CheckPrime cp = new CheckPrime();
 		cp.getPrime();
 		
 		// get input from user
 		System.out.println("Kindly enter the number [Range : 1 - 500]");
 		iNumber = s.nextInt();
 		
 		// a method for getting sum of two prime numbers
 		cp.tellPrime(iNumber);
 	}
 }
