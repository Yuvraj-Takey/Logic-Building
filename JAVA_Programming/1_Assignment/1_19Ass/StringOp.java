/*
 *	java programs to check palindrome string using Stack, Queue, for or while loop.
 *	
 *	@DSSD	- Yuvraj Takey
 */
 
 import java.lang.*;
 import java.util.Scanner;
 import java.lang.StringBuilder;
 
 class C_Palindrome
 {
 	String s_Val;
 
 	// default constructor
 	C_Palindrome()
 	{
 		// code
 	}
 	
 	public void getString()
 	{
 		// get the scanner object
 		Scanner s = new Scanner(System.in);
 		
 		// get input form user
 		System.out.println("Kindly enter the string");
 		s_Val = s.nextLine();
 	}
 	
 	// check string palindrome using stack functionality
 	public boolean isPalin_STK()
 	{
 		int index = 0, jindex = s_Val.length()-1;
 		StringBuilder sSTK = new StringBuilder();
 		
 		// iterate for till the string
 		for(index = 0; index < s_Val.length(); index++,jindex--)
 		{
 			// using Stack representation
 			sSTK.append(s_Val.charAt(jindex));
 		}
 		
 		// compare the strings
 		if((s_Val.compareToIgnoreCase(sSTK.toString())) == 0 )
 		{
 			return true;
 		}
 		else
 		{
 			return false;
 		}
 	}
 	
 	// check string palindrome using queue functionality
 	public boolean isPalin_QUE()
 	{
 		int index = 0, jindex = 0;
 		StringBuilder sQUE = new StringBuilder();
 		
 		// iterate for till the string
 		for(index = 0; index < s_Val.length(); index++)
 		{
 			// using Queue representation
 			sQUE.insert(jindex,s_Val.charAt(index));
 		}
 		
 		// compare the strings
 		if((s_Val.compareToIgnoreCase(sQUE.toString())) == 0 )
 		{
 			return true;
 		}
 		else
 		{
 			return false;
 		}
 	}
 	
 	// check string palindrome using while functionality
 	public boolean isPalin_WHI()
 	{
 		int index = 0, jindex = s_Val.length()-1;
 		
 		// iterator
 		while(index <= jindex)
 		{
 			// check for unmatched condition
 			if(s_Val.charAt(index) != s_Val.charAt(jindex))
 			{
 				break;
 			}
 		
 			// manage the pointers
 			index++;
 			jindex--;
 		}
 		
 		// check status of while
 		if(index >= jindex)
 		{
 			return true;
 		}
 		else
 		{
 			return false;
 		}
 		
 		
 	}
 }
 
 class StringOp
 {
 	public static void main(String arg[])
 	{
 		System.out.println("HELLO STRING OPERATION");
 		Scanner s = new Scanner(System.in);
 		
 		// get the object
 		C_Palindrome cp = new C_Palindrome();
 		cp.getString();
 		
 		// check using stack
 		if(cp.isPalin_STK())
 		{
 			System.out.println("[INFO_] : String is Palindrome [STACK]");
 		}
 		else
 		{
 			System.out.println("[INFO_] : String is not Palindrome [STACK]");
 		}
 		
 		// check using queue
 		if(cp.isPalin_QUE())
 		{
 			System.out.println("[INFO_] : String is Palindrome [QUEUE]");
 		}
 		else
 		{
 			System.out.println("[INFO_] : String is not Palindrome [QUEUE]");
 		}
 		
 		// check using while
 		if(cp.isPalin_WHI())
 		{
 			System.out.println("[INFO_] : String is Palindrome [WHILE]");
 		}
 		else
 		{
 			System.out.println("[INFO_] : String is not Palindrome [WHILE]");
 		}
 	}
 }
