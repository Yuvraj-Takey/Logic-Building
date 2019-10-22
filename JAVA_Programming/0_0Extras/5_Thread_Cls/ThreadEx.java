/*********************************************************************************************************************

	Demonstrate the Thread class example

	@Author 	- Yuvraj Takey
	@Title		- DSSD-JAVA

**********************************************************************************************************************/

 import java.lang.*;
 import java.util.Scanner;
 
 
 class User_Thread extends Thread
 {
 	// default constructor
 	public User_Thread()
 	{	
 		super();
 	}
 	
 	// callback method
 	public void run()
 	{
 		int index = 0;
 		
 		for(index = 0; index < 10; index++)
 		{
 			System.out.println("Thread : " + " ID "  + Thread.currentThread().getName());
 			
 			try
 			{
 				Thread.sleep(1000);
 			}
 			catch(Exception e)
 			{
 				e.printStackTrace();
 			}
 		}
 		
 	}
 }
 
 // main class
 public class ThreadEx
 {
 	// entry point method
 	public static void main(String arg[])
 	{
 		System.out.println("JAVA CODE");
 		
 		// get class object
 		User_Thread ut = new User_Thread();
 		
 		// get thread object
 		Thread T1 = new Thread(ut,"ONE");
 		Thread T2 = new Thread(ut,"TWO");
 		
 		// start the thread
 		T1.start();
 		T2.start();
 	}
 }
 
 
 
 
