
/*
 *	a program in Java to check if a number is even or odd.
 *
 *	@DSSD	- Yuvraj Takey
 */


 import java.lang.*;
 
 class Even_Odd
 {
 	private int iNumber;
 	
 	// constructor
 	Even_Odd()
 	{
 		iNumber = 0;
 	}
 	
 	// Parameterised constructor
 	Even_Odd(int iVal)
 	{
 		iNumber = iVal;
 	}
 	
 	// method for setting the number as class data
 	void set_Number(int iVal)
 	{
 		iNumber = iVal;
 	}
 	
 	// method for check whether the number is Even or Odd
 	boolean isEvenN()
 	{
 		if(iNumber == 0)
 		{
 			System.out.println("[SORRY] : Number is not initialized");
 			return false;
 		}
 		
 		// logic for Even_Odd
 		if((iNumber % 2) == 0)
 		{
 			return true;
 		}
 		else
 		{
 			return false;
 		}
 	}
 }
 
 
 // only one clas can be public, and which is holding main method in it
 class Check_Num
 {
 	public static void main(String arg[])
	{
		int iNumber = 11;
		
		// create the object
		Even_Odd cNum = new Even_Odd();
		
		// call to class method
		cNum.set_Number(iNumber);
		
		// check for number
		if(cNum.isEvenN())
		{
			// Result
			System.out.println("[INFO_] : "+ iNumber +" - The given number is Even");
		}
		else
		{
			// Result
			System.out.println("[INFO_] : "+ iNumber +" - The given number is odd");
		}		
	}
 }
 
 
 
 
 
