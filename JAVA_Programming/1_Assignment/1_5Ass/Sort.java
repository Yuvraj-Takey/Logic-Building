/*
 *	A program to sort an integer array.
 *
 *	@DSSD	- Yuvraj Takey
 */
 
 import java.lang.*;
 import java.util.Scanner;
 import java.util.Arrays;
 
 class SortArray
 {
 	int iArr[];
 
 	// Default Constructor
 	SortArray()
 	{
 		// get the memory for array
 		iArr = new int[5];
 	}
 	
 	// parameterised Constructor
 	SortArray(int isize)
 	{
 		// get the memory for array
 		iArr = new int[isize];
 	}
 	
 	public void getArray()
 	{
 		System.out.println("Kindly enter the array element : ");
 		
 		// get scanner object
 		Scanner s = new Scanner(System.in);
 		
 		// get the member of array
 		for(int index = 0; index < iArr.length; index++)
 		{
 			iArr[index] = s.nextInt();
 		}
 	}
 	
 	// method
 	public void sortIntArray()
 	{
 		// sort the array
 		Arrays.sort(iArr);
 	}
 	
 	public void showArray()
 	{
 		System.out.println("Array elemets are : ");
 		
 		// for each loop
 		for(int ival : iArr)
 		{
 			System.out.print(ival + " ");
 		}
 		
 		System.out.println(); 		
 	}
 	
 }
 
 
 class Sort
 {
 	public static void main(String args[])
 	{
 		System.out.println("WELCOME TO SORT");
 		
 		int isize = 0;
 		
 		// get scanner object
 		Scanner s = new Scanner(System.in);
 		
 		System.out.println("Kindly enter the size of array");
 		isize = s.nextInt();
 		
 		// get the object
 		SortArray sa = new SortArray(isize);
 		
 		// call to method
 		sa.getArray();
 		
 		// call to method
 		sa.sortIntArray();
 		
 		// display the array
 		sa.showArray();
 		
 	}
 }
 
 
 /*
 	Facilities provided by the Java-Arrays Class:
 	There are often times when we need to do following tasks on an array in Java.

	Sort an array.
	Binary search in sorted array. And many more.
	
	Methods in Java Array:
		The Arrays class of the java.util package contains several static methods that we can use to fill, sort, search, etc in arrays.
	This class is a member of the Java Collections Framework and is present in java.util.arrays.
 */
 
 
 
 
 
 
 
