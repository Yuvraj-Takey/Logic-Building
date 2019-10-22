
/*
 *	a program in Java to find out if a number is prime or not also accept the input from user.
 *
 *	@DSSD	- Yuvraj Takey
 */


 import java.lang.*;
 import java.util.Scanner;
 
 class Prime
 {
 	private int iNumber;
 	
 	// constructor
 	Prime()
 	{
 		iNumber = 0;
 	}
 	
 	// Parameterised constructor
 	Prime(int iVal)
 	{
 		iNumber = iVal;
 	}
 	
 	// method for setting the number as class data
 	void set_Number(int iVal)
 	{
 		iNumber = iVal;
 	}
 	
 	// method for check whether the number is Even or Odd
 	boolean isPrimeN()
 	{
 		if(iNumber == 0)
 		{
 			System.out.println("[SORRY] : Number is not initialized");
 			return false;
 		}
 		
 		// logic for Prime
 		int index = 0, icnt = 0;
 	
 		// iterate till the number	
 		for(index = 1; index < iNumber; index++)
 		{
 			// make division
 			if((iNumber % index) == 0)
	 		{
	 			icnt++;
	 		}
 		}
 		
 		// check the count status
 		if(icnt == 1)
 		{
 			return true;
 		}
 		else
 		{
 			return false;
 		}
  	}
 }
 
 class Check_Num
 {
 	public static void main(String arg[])
	{
		int iNumber = 0;
		Scanner s = new Scanner(System.in);
		
		// create the object
		Prime cNum = new Prime();
		
		// accept the input from user
		System.out.println("Kindly ente the number :");
		iNumber = s.nextInt();
		
		// call to class method
		cNum.set_Number(iNumber);
		
		// check for number
		if(cNum.isPrimeN())
		{
			// Result
			System.out.println("[INFO_] : The given number is Prime");
		}
		else
		{
			// Result
			System.out.println("[INFO_] : The given number is not Prime");
		}		
	}
 }
 
 
 
 
 
