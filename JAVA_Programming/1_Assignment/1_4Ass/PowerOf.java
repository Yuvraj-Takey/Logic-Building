/*
 *	How to find if a number is power of 2 in Java.
 *	
 *	@DSSD	- Yuvraj Takey
 */
 
 
 import java.lang.*;
 import java.util.Scanner;
 import java.lang.Math;

 
 class Power
 {
 	int iNumber;
 	
 	// default constructor
 	Power()
 	{
 		iNumber = 0;
 	}
 	
 	// parameterised constructor
 	Power(int ival)
 	{
 		iNumber = ival;
 	}
 	
 	// method define
 	public boolean isPowerTwo()
 	{
 		int retval = 0;
 		
 		// using floorMod method in Math class
 		if((retval = Math.floorMod(iNumber,2)) == 0)
 		{
 			return true;
 		}
 		else
 		{
 			return false;
 		}
 	}
 }
 
 class PowerOf
 {
 	public static void main(String arg[])
 	{
 		int iNumber = 0;
 		Scanner s = new Scanner(System.in);
 		
 		System.out.println("[INFO_] : WELCOME TO POWERoF EXAMPLE");
 		
 		// get the value from user
 		iNumber = s.nextInt();
 		
 		// create the object
 		Power pw = new Power(iNumber);
 		
 		// check for result
 		if(pw.isPowerTwo())
 		{
 			System.out.println("[INFO_] : Yes, the number is power of 2");
 		}
 		else
 		{
 			System.out.println("[INFO_] : No, the number is not power of 2");
 		}
 		
 	}
 }
