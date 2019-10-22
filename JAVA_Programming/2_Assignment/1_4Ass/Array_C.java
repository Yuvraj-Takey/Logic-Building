/*********************************************************************************************************************

	Rework with the previous function and the program so that it finds the sum of elements
	when the index of the starting element and the number of elements is specified. (Range - Array)

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
 	
 	public void getSumAll(int arr[], int istart, int ilen)
 	{
 		// check condition
 		if((istart < 0) || (istart > arr.length) || (ilen < 0) || (ilen > arr.length))
 		{
 			System.out.println("[SORRY] : operation could not be perform");
 			return ;
 		}
 		
 		// reset the iSum
 		iSum = 0;
 		
 		// iterate the loop till the array
 		for(int index = istart; index < ilen; index++)
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
 		int iRange = 0, iEle = 0;
 		
 		// message
 		System.out.println("Kindly enter the 10 element for array");
 		
 		// fill the array with user choice
 		for(int index = 0; index < iarr.length; index++)
 		{
 			iarr[index] = s.nextInt();
 		}
 		
 		System.out.println("Kindly enter the starting index and the number of elements that has to sum");
 		iRange = s.nextInt();
 		iEle = s.nextInt();
 		
 		// get the object of above class
 		ArrayOP aop = new ArrayOP();
 		
 		// invoke the class method
 		aop.getSumAll(iarr, iRange, iEle);
 		System.out.print("Sum of array element :");
 		aop.showSum();
 		
 	}
 }
 
 
 
 
