/*
 *	A Java program to check if a number is palindrome or not, Use java api.
 *
 *	@DSSD	- Yuvraj Takey
 */
 
 import java.lang.*;
 import java.util.Scanner;
 import java.lang.Integer;
 import java.lang.StringBuilder;

 
 class Palindrome
 {
 	int iNumber;
 	
 	// default constructor
 	Palindrome()
 	{
 		iNumber = 0;
 	}
 	
 	// parameterised constructor
 	Palindrome(int ival)
 	{
 		iNumber = ival;
 	}
 	
 	public boolean isPalinN()
 	{
 		// get String Builder
 		StringBuilder sb = new StringBuilder();
 		
 		// add Number to string Builder
 		sb.append(iNumber);
 		
 		// convert stringBuilder to string and reverse the string
 		String str = sb.reverse().toString();
 		
 		// check for equaliy
 		if(str.compareTo(Integer.toString(iNumber)) == 0)
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
 		int iNumber = 0;
 		Scanner s = new Scanner(System.in);
 	
 		System.out.println("PALINDROME EXAMPLE");
 		
 		// get input from user
 		System.out.println("Kindly enter the number");
 		iNumber = s.nextInt();
 		
 		// get the class object
 		Palindrome cNum = new Palindrome(iNumber);
 		
 		// call to method
 		if(cNum.isPalinN())
 		{
 			System.out.println("[INFO_] : Number is Palindrome");
 		}
 		else
 		{
 			System.out.println("[INFO_] : Number is not Palindrome");
 		}		
 	}
 }
