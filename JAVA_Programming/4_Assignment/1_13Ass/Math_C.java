/*********************************************************************************************************************

	Demonstrate the use of ceil(), floor(), round(), random(), abs(), max(), min()
	methods of Math class.

	@Author 	- Yuvraj Takey
	@Title		- DSSD-JAVA

**********************************************************************************************************************/

 import java.lang.*;
 import java.util.Scanner;
 import java.lang.Math;

 class M_Operation
 {
 	Scanner s;
 	
 	// default constructor
 	M_Operation()
 	{
 		s = new Scanner(System.in); 
 	}
 	
 	
 	private void m_Ceil()
 	{
 		double d_Val = 0.0;
 		
 		// get user input
 		System.out.println("Kindly enter the double type value");
 		d_Val = s.nextDouble();
 		
 		// message
 		System.out.println("Result : " + Math.ceil(d_Val));
 	}
 	private void m_Floor()
 	{
 		double d_Val = 0.0;
 		
 		// get user input
 		System.out.println("Kindly enter the double type value");
 		d_Val = s.nextDouble();
 		
 		// message
 		System.out.println("Result : " + Math.floor(d_Val));
 	}
 	private void m_Round()
 	{
 		double d_Val = 0.0;
 		
 		// get user input
 		System.out.println("Kindly enter the double type value");
 		d_Val = s.nextDouble();
 		
 		// message
 		System.out.println("Result : " + Math.round(d_Val));
 	}
 	private void m_Abs()
 	{
 		double d_Val = 0.0;
 		
 		// get user input
 		System.out.println("Kindly enter the double type value (prefer negative value)");
 		d_Val = s.nextDouble();
 		
 		// message
 		System.out.println("Result : " + Math.abs(d_Val));
 	}
 	private void m_Random()
 	{
 		// message
 		System.out.println("Result : " + Math.random());
 	}
 	private void m_Max()
 	{
 		double d_Val1 = 0.0;
 		double d_Val2 = 0.0;
 		
 		// get user input
 		System.out.println("Kindly enter the 2 double type value");
 		d_Val1 = s.nextDouble();
 		d_Val2 = s.nextDouble();
 		
 		// message
 		System.out.println("Result : " + Math.max(d_Val1,d_Val2));
 	}
 	private void m_Min()
 	{
 		double d_Val1 = 0.0;
 		double d_Val2 = 0.0;
 		
 		// get user input
 		System.out.println("Kindly enter the 2 double type value");
 		d_Val1 = s.nextDouble();
 		d_Val2 = s.nextDouble();
 		
 		// message
 		System.out.println("Result : " + Math.min(d_Val1,d_Val2));
 	}
 	
 	public void listOperation()
 	{
 		short choice = 0;
 		
 		try
 		{
	 		while(true)
	 		{
	 			// get menu
	 			System.out.println("Kindly select your operation");
	 			System.out.println("1.	ceil");
	 			System.out.println("2.	floor");
	 			System.out.println("3.	round");
	 			System.out.println("4.	random");
	 			System.out.println("5.	abs");
	 			System.out.println("6.	max");
	 			System.out.println("7.	min");
	 			System.out.print("8.	Exit\n---->  ");
	 			choice = s.nextShort();
	 			
	 			// get the case
	 			switch(choice)
	 			{
	 				case 1:
	 				{
	 					m_Ceil();
	 					break;
	 				}
	 				case 2:
	 				{
	 					m_Floor();
	 					break;
	 				}
	 				case 3:
	 				{
	 					m_Round();
	 					break;
	 				}
	 				case 4:
	 				{
	 					m_Random();
	 					break;
	 				}
	 				case 5:
	 				{
	 					m_Abs();
	 					break;
	 				}
	 				case 6:
	 				{
	 					m_Max();
	 					break;
	 				}
	 				case 7:
	 				{
	 					m_Min();
	 					break;
	 				}
	 				case 8:
	 				{
	 					choice = '\b';
	 					break;
	 				}
	 				default:
	 				{
	 					break;
	 				}
	 				
	 			}// switch
	 			
	 			// check for temiation condition
	 			if(choice == '\b')
	 			{
	 				break;
	 			}
	 			
	 		}// while
	 	}
	 	catch(Exception e)
	 	{
	 		e.printStackTrace();
	 	}
	 	
 	}
 }
 
 // main class
 public class Math_C
 {
 	// entry point method
 	public static void main(String arg[])
 	{
 		System.out.println("JAVA CODE");
 		
 		// get the object of above class
 		M_Operation mop = new M_Operation();
 		
 		mop.listOperation();
 	}
 }
 
 
 
 
