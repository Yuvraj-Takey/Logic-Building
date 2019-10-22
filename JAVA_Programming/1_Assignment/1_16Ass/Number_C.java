/*
 *	a Java program to generate random number.
 *
 *
 *	@DSSD	- Yuvraj Takey
 */
 
 import java.lang.*;
 import java.util.Scanner;
 import java.util.Random;
 import java.lang.Math;
 
 class NumberOp
 {
 	// default constructor
 	public NumberOp()
 	{
 		// code
 	}
 	
 	public int genRandNum()
 	{
 		int iRNum = 0;
 		
 		// get the object of Random class
 		Random rd = new Random();
 		
 		// get the random number
 		iRNum = Math.abs((short)rd.nextInt());
 		
 		return iRNum;
 	}
 }
 
 public class Number_C
 {
 	public static void main(String arg[])
 	{
 		System.out.println("HELLO NUMBER CLASS");
 		
 		// get the object of above class
 		NumberOp nop = new NumberOp();
 		
 		// result
 		for(int i = 0; i < 5; i++)
 		System.out.println("Random Number ["+ (i+1) +"] : " + nop.genRandNum());
 	}
 }
 
