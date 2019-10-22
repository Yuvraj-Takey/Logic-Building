/*********************************************************************************************************************

	a program to throw a checked exception explicitly using 'throw' keyword
	
	a) Handle the exception in same method.
	b) use throws clause and handle the exception in some other method
	(calling method)
	c) Don't either handle or use the throws clause. Observe the result.

	@Author 	- Yuvraj Takey
	@Title		- DSSD-JAVA

**********************************************************************************************************************/

 import java.lang.*;
 import java.util.Scanner;
 import java.lang.Exception;
 import java.io.IOException;

 
 class Checked_E
 {
 	int i_Num;
 
 	// default constructor
 	public Checked_E()
 	{
 		i_Num = 0;
 	}
 	
 	public boolean checkNum()
 	{
 		boolean flag = true;
 		try
 		{
	 		// check the number
	 		if((i_Num > 5) || (i_Num < 1))
	 		{
	 			flag = false;
	 			throw new IOException("given data is out of range");
	 		}	 		
	 	}
	 	catch(IOException e)
	 	{
	 		e.printStackTrace();
	 		throw e;
	 	}
	 	finally
	 	{
	 		return flag;
	 	}
 	}
 	
 	public void foo() throws IOException, Exception
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
 	public static void main(String arg[]) throws Exception
 	{
 		System.out.println("JAVA CODE");
 		
 		// get the object 
 		Checked_E ce = new Checked_E();	
 		
 		// invoke the method
 		ce.foo();
 		
	 	// end message
	 	System.out.println("\n[INFO] : End execution");
 	}
 }
 
 



 /***
 
 Checked: are the exceptions that are checked at compile time. If some code within a method throws a checked exception,
 then the method must either handle the exception or it must specify the exception using throws keyword.

	For example, consider the following Java program that opens file at location “C:\test\a.txt” and
	prints the first three lines of it. The program doesn’t compile,
	because the function main() uses FileReader() and FileReader() throws a checked exception FileNotFoundException.
	It also uses readLine() and close() methods, and these methods also throw checked exception IOException
 
 
 import java.io.*; 
  
 class Main 
 {
 	public static void main(String[] args) 
 	{ 
 		FileReader file = new FileReader("C:\\test\\a.txt"); 
 		BufferedReader fileInput = new BufferedReader(file); 
 		
 		// Print first 3 lines of file "C:\test\a.txt"
 		for (int counter = 0; counter < 3; counter++) 
 		System.out.println(fileInput.readLine());
 		
 		fileInput.close(); 
 	} 
} 
 
 ***/
 
