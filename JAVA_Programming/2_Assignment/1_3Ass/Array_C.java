/*********************************************************************************************************************

	Write user-defined function to find the sum of an array passed as argument.
	a program that declares an array of 10 elements and uses this to 

	--->
		Find the sum of all elements.
		Find the sum of first 5 elements.
		Find the sum of last 5 elements.

	@Author 	- Yuvraj Takey
	@Title		- DSSD-JAVA

**********************************************************************************************************************/

 import java.lang.*;
 import java.util.Scanner;
 
 class ArrayOP
 {
 	private int iSum;
 	
 	// defualt constructor
 	public ArrayOP()
 	{
 		iSum = 0;
 	}
 	
 	public void showSum()
 	{
 		// message
 		System.out.println("Result : " + iSum);
 	}
 	
 	public void getSumAll(int arr[])
 	{
 		// reset the iSum
 		iSum = 0;
 		
 		// iterate the loop till the array
 		for(int index = 0; index < arr.length; index++)
 		{
 			// perform addition
 			iSum = iSum + arr[index];
 		}
 	}
 	
 	public void getSumFirstHalf(int arr[])
 	{
 		// reset the iSum
 		iSum = 0;
 		
 		// iterate the loop till the array
 		for(int index = 0; index < (arr.length)/2; index++)
 		{
 			// perform addition
 			iSum = iSum + arr[index];
 		}
 	}
 	
 	public void getSumLastHalf(int arr[])
 	{
 		// reset the iSum
 		iSum = 0;
 		
 		// iterate the loop till the array
 		for(int index = (arr.length)/2; index < arr.length; index++)
 		{
 			// perform addition
 			iSum = iSum + arr[index];
 		}
 	}
 }
 
 // main class
 public class Array_C
 {
 	// entry point method
 	public static void main(String arg[])
 	{
 		System.out.println("JAVA CODE");
 		
 		// get the Scanner object
 		Scanner s = new Scanner(System.in);
 		int iarr[] = new int[10];
 		
 		// message
 		System.out.println("Kindly enter the 10 element for array");
 		
 		// fill the array with user choice
 		for(int index = 0; index < iarr.length; index++)
 		{
 			iarr[index] = s.nextInt();
 		}
 		
 		// get the object of above class
 		ArrayOP aop = new ArrayOP();
 		
 		// invoke the class method
 		aop.getSumAll(iarr);
 		System.out.print("Sum of all 10 array element :");
 		aop.showSum();
 		
 		aop.getSumFirstHalf(iarr);
 		System.out.print("Sum of 1st 5 array element  :");
 		aop.showSum();
 		
 		aop.getSumLastHalf(iarr);
 		System.out.print("Sum of last 5 array element :");
 		aop.showSum();
 	}
 }
 
 
 
 
