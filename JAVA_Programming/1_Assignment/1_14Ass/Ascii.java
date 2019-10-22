/*
 *	a Java Program to find ASCII value of a Character.
 *
 *	@DSSD	- Yuvraj Takey
 */
 
 import java.lang.*;
 import java.util.Scanner;
 import java.lang.Character;
 
 public class Ascii
 {
 	public static void main(String args[])
 	{
 		char ch;
 		
 		// get the scanner object
 		Scanner s = new Scanner(System.in);
 		
 		// get user input
 		System.out.println("ASCII Value Finder \nKindly enter the character");
 		ch = s.next().charAt(0);
 		
 		// print the ASCII value
 		System.out.println("ASCII of character is : " + (int)ch);
 	}
 }
