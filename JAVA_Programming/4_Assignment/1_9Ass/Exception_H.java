/*********************************************************************************************************************

	Repeat program 8 with unchecked Exception and demonstrate the difference in both
	program

	@Author 	- Yuvraj Takey
	@Title		- DSSD-JAVA

**********************************************************************************************************************/

 import java.lang.*;
 import java.util.Scanner;
 import java.lang.Exception;
 import java.io.IOException;

 
 class UNChecked_E
 {
 	int i_Num;
 
 	// default constructor
 	public UNChecked_E()
 	{
 		i_Num = 0;
 	}
 	
 	public boolean checkNum()
 	{
 		boolean flag = true;
 		
	 		// check the number
	 		if((i_Num > 5) || (i_Num < 1))
	 		{
	 			flag = false;
	 			throw new IndexOutOfBoundsException("\n[INFO] : given data is out of range\n");
	 		}
	 		
	 	return flag;
 	}
 	
 	public void foo()
 	{
 		int retval = 0;
 		Scanner s = new Scanner(System.in);
 		
 		// get input from user
 		System.out.println("Kindly enter any data [No. Range : 1-5]\n(Demonstrate the checked exception - use number out of range)");
 		i_Num = s.nextInt();
 		
 		if(checkNum())
 		{
 			System.out.println("[INFO] : Data is valid");
 		}
 	}
 	
 }
 
 
 
 // main class
 public class Exception_H
 {
 	// entry point method
 	public static void main(String arg[])
 	{
 		System.out.println("JAVA CODE");
 		
 		// get the object 
 		UNChecked_E ce = new UNChecked_E();	
 		
 		// invoke the method
 		ce.foo();
 		
	 	// end message
	 	System.out.println("\n[INFO] : End execution");
 	}
 }
 
 



 /***
 
 Unchecked : are the exceptions that are not checked at compiled time.
 	In C++, all exceptions are unchecked, so it is not forced by the compiler to either handle or specify the exception.
 	It is up to the programmers to be civilized, and specify or catch the exceptions.
	In Java exceptions under Error and RuntimeException classes are unchecked exceptions, everything else under throwable is checked.
 
 		Consider the following Java program. It compiles fine, but it throws ArithmeticException when run. 
 		The compiler allows it to compile, because ArithmeticException is an unchecked exception.
 
 import java.io.*; 
  
 class Main 
 {
 	public static void main(String args[]) 
 	{
 		int x = 0;
 		int y = 10;
 		int z = y/x;
 	}
 }
 
 ***/
 
