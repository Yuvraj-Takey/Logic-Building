/*
 *	A Java program to check if a number is Armstrong number or not.
 *
 *	@DSSD	- Yuvraj Takey
 */
 
 import java.lang.*;
 import java.util.Scanner;
 import java.lang.Math;
 
 class Armstrong
 {
 	int iNumber;
 
 	// default constructor
 	Armstrong()
 	{
 		iNumber = 0;
 	}
 	
 	// parameterised constructor
 	Armstrong(int ival)
 	{
 		iNumber = ival;
 	}
 	
 	public boolean isArm()
 	{
 		int iTemp = iNumber, iDigit = 0, iSum = 0, iLen = 0;

		// get the length of number
		iLen = Integer.toString(iNumber).length();

		// iterate while till number end
 		while(iTemp != 0)
 		{
 			// get the digit from number
 			iDigit = iTemp % 10;
 			
 			// calculate the armstrong
 			iSum = iSum + (int)Math.pow(iDigit,iLen);
 		
 			// reduce the number
 			iTemp = iTemp / 10;
 		}
 		
 		if(iSum == iNumber)
 		{
 			return true;
 		}
 		else
 		{
 			return false;
 		}
 	}
 	
 	
 }
 
 public class Check_Num
 {
 	public static void main(String arg[])
 	{
 		System.out.println("[INFO_] : WELCOME TO ARMSTRONG");
 	
 		int iNumber = 0;
 	
 		// get the scanner
 		Scanner s = new Scanner(System.in);
 		
 		System.out.println("[INFO_] : Kindly enter any number");
 		iNumber = s.nextInt();
 	
 		// get the object
 		Armstrong arm = new Armstrong(iNumber);
 		
 		// check for number
 		if(arm.isArm())
 		{
 			System.out.println("[INFO_] : The given number is armstrong");
 		}
 		else
 		{
 			System.out.println("[INFO_] : The given number is not armstrong");
 		}
 	}
 }
 
