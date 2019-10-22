/*
 *	a program in Java to reverse any String.
 *
 *	@DSSD	- Yuvraj Takey
 */
 
 import java.lang.*;
 import java.util.Scanner;
 
 public class Reverse
 {
 	public static void main(String arg[])
 	{
 		// get the string builder object
 		StringBuilder sName = new StringBuilder();
 		
 		// get the Scanner object
 		Scanner s = new Scanner(System.in);
 		
 		System.out.println("Kindly enter any string");
 		sName.append(s.nextLine());
 		
 		// Result
 		System.out.println("Your string is : " + sName.reverse());
 	}
 }
