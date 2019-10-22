/*********************************************************************************************************************

	write a program to demonstrate
		a) Labeled break
		b) Labeled continue

	@Author 	- Yuvraj Takey
	@Title		- DSSD-JAVA

**********************************************************************************************************************/

 import java.lang.*;
 import java.util.Scanner;

 class LabelEx
 {
 	// default constructor
 	public LabelEx()
 	{
 		// code
 	}
 	
 	public void labelBreak()
 	{
 		// get the scanner object
 		Scanner s = new Scanner(System.in);
 		
 		int iArr[] = {10,20,30,40,10,50}, index = 0, jindex = 0;
 		
 		// message 
 		System.out.println("get the first duplicate value from array");
 		
 		LBreak:
 			for(index = 0; index < (iArr.length-1); index++)
 			{
 				for(jindex = (index + 1); jindex < iArr.length; jindex++)
 				{
 					// ckeck for equality
 					if(iArr[index] == iArr[jindex])
 					{
 						break LBreak;
 					}
 				}
 			}
 			
 			// result
 			if(index != (iArr.length-1))
 			System.out.println("[INFO_] : index - (" + index + ", " + jindex + ") value - " + iArr[index]);
 			else
 			System.out.println("[INFO_] : \t-No duplicate entries");
 		
 	}
 	
 	public void labelContinue()
 	{
 		// get the scanner object
 		Scanner s = new Scanner(System.in);
 		
 		int iArr[] = {10,20,10,40,10,50}, index = 0, jindex = 0, count = 0, iteration = 0;
 	
 		// message 
 		System.out.println("\nget the number of matching pair from array");
 		
 		LCont:
 			for(index = 0; index < iArr.length; index++)
 			{
 				for(jindex = (index + 1); jindex < iArr.length; jindex++)
 				{
 					iteration++;
 					
 					// ckeck for equality
 					if(iArr[index] == iArr[jindex])
 					{
 						count++;
 						continue LCont;
 					}
 				}
 			}
 			
 			// result
 			if(count != 0)
 			System.out.println("[INFO_] : Matching pair : " + count + " iteration : " + iteration);
 			else
 			System.out.println("[INFO_] : \t-No matching pair");
 	}
 }
 
 
 // main class
 public class Labeled
 {
 	// entry point method
 	public static void main(String arg[])
 	{
 		System.out.println("JAVA CODE");
 		
 		// get the object
 		LabelEx le = new LabelEx();
 		
 		// invoke class method
 		le.labelBreak();
 		le.labelContinue();
 	}
 }
 
 
 
 
