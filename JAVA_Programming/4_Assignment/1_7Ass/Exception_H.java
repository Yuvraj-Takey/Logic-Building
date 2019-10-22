/*********************************************************************************************************************

	a java program to demonstrate the use of try, catch, finally throw and throws keyword
	and demonstrate the following points in the program.
		Multiple catch blocks.
		try-catch-finally combination.
		try-finally combination.
		Exception propagation among many methods.
		Use of getMessage(), printStackTrace() function of Throwable class.
		Nested try blocks

	@Author 	- Yuvraj Takey
	@Title		- DSSD-JAVA

**********************************************************************************************************************/

 import java.lang.*;
 import java.util.Scanner;
 import java.lang.Exception.*;
 import java.lang.RuntimeException;
 import java.util.InputMismatchException;

 
 class Foo
 {
 	int i_Val;
 	
 	// default constructor
 	Foo()
 	{
 		i_Val = 0;
 	}
 	
 	public void getNum() throws Exception
 	{
 		// get the scanner object
 		Scanner s = new Scanner(System.in);
 		
 		System.out.print("\nKindly enter any value\n[Demonstrate Exception example]\n\n--> ");
 			
 		// get integral value from user
	 	i_Val = s.nextInt();
 	}
 	
 	public void checkPrime() throws Exception
 	{
 		int index = 0, icnt = 0;
 		
 		// get the number
 		getNum();
 		
 		// iterate 
 		for(index = 0; index <= i_Val; index++)
 		{
 			if(( i_Val / index ) == 0)
 			{
 				icnt++;
 			}
 		}
 		
 		// check for status
 		if(icnt == 1)
 		{
 			System.out.println("[INFO] : The given number is prime");
 		}
 		else
 		{
 			System.out.println("[INFO] : The given number is not prime");
 		}
 	}
 	
 	public void checkEven() throws Exception
 	{
 		int retval = 0;
 		
 		try
 		{
 			// get the number
 			getNum();
 		
 			try
 			{
	 			// check prime
	 			retval = (2 % i_Val);
	 			
	 			if(retval == 0)
	 			{
	 				System.out.println("[INFO] : Given number is even");
	 			}
	 			else
	 			{
	 				System.out.println("[INFO] : Given number is even");
	 			}
	 		}
	 		catch(NumberFormatException e)
	 		{
	 			e.printStackTrace();
	 		}
 		}
 		finally
 		{
 			System.out.println("[INFO] : inside finally of checkEven()");
 		}
 		
 		// message
 		System.out.println("[INFO] : came out from finally of checkEven()");
 	}
 	
 	public void ex_Operation()
 	{ 		
 		try
 		{	
	 		// check the number for even
	 		checkEven();
	 		
	 		
	 		// check the number for prime
	 		checkPrime();
	 		
	 	}
	 	catch(NumberFormatException e)
	 	{
	 		e.printStackTrace();
	 	}
	 	catch(ArithmeticException e)
	 	{
	 		System.out.println("[EXCP] : Arithmetic Exception Occured  -> " + e.getMessage());
	 	}
	 	catch(InputMismatchException e)
	 	{
	 		e.printStackTrace();
	 	}
	 	catch(Exception e)
	 	{
	 		System.out.println(e.getMessage());
	 	}
	 	finally
	 	{
	 		System.out.println("[INFO] : inside finally block");
	 	}
	 	
	 	// message
	 	System.out.println("[INFO] : came out from finally block");
 	}
 }
 
 // main class
 public class Exception_H
 {
 	// entry point method
 	public static void main(String arg[]) throws Exception
 	{
 		System.out.println("JAVA CODE");
 		
 		// get the object of clas
 		Foo f = new Foo();
 		
 		// invoke the method
 		f.ex_Operation();
 	}
 }
 
 
 
 
