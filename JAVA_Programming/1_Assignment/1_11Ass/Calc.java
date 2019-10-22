/*
 *	a Java Program to Calculate average using Array use IntStream Interface.
 *
 *	@DSSD	- Yuvraj Takey
 */
 
 import java.lang.*;
 import java.util.Scanner;
 import java.util.stream.*;
 
 class CalAvg
 {
 	int iArr[];
 	
 	// default constructor
 	CalAvg()
 	{
 		// code
 	}
 	
 	public void getArray()
 	{
 		int iLen = 0;
 		
 		// get the scanner object
 		Scanner s = new Scanner(System.in);
 		
 		// get length from user
 		System.out.println("Kindly enter the length of array");
 		iLen = s.nextInt();
 		
 		// allocate the memory of array
 		iArr = new int[iLen];
 		
 		// get the array element
 		System.out.println("Kindly enter the array element");
 		for(int index = 0; index < iLen; index++)
 		{
 			iArr[index] = s.nextInt();
 		}
 	}
 	
 	public void showArray()
 	{
 		System.out.print("Your Array is : ");
 	
 		// check for array status
 		if(iArr.length != 0)
 		{
 			// iterate till end of array
 			for(int val : iArr)
 			{
 				System.out.print(val + " ");
 			}
 			
 			System.out.println();
 		}
 	}
 	
 	public float getAverage()
 	{
 		float iAvg = 0;
 		
 		// calculate the average
 		iAvg = ((float) (IntStream.of(iArr).sum()) / iArr.length );
 		
 		return iAvg;
 	}
 }
 
 public class Calc
 {
 	public static void main(String arg[])
 	{
 		System.out.println("HELLO_Calculate"); 		
 		
 		// get the object of above class
 		CalAvg ca = new CalAvg();
 		
 		// get input from user
 		ca.getArray();
 		ca.showArray();
 		
 		// Result
 		System.out.println("The Average is : " + ca.getAverage());
 	}
 }
