/**********************************************************************************************

	Modify program 1 with Integer class Object. Use the override equals method of
	Integer with two different object wrapping same primitive int value
	( like -10). demonstrate the difference in the output from program 11.

	@Author 	- Yuvraj Takey
	@Title  	- DSSD-JAVA

**************************************************************************************************/

 import java.lang.*;
 import java.util.Scanner;
 
 // base class
 class Person
 {
 	Integer i_Val;
 	
 	// default constructor
 	Person()
 	{
 		i_Val = new Integer(0);
 	}
 	
 	// parameterised constructor
 	Person(int i)
 	{
 		i_Val = new Integer(i);
 	}
 	
 	// method
 	public void setData(int index)
 	{
 		i_Val = index;
 	}
 	
 	// override method
 	public void getData()
 	{
 		System.out.println("[PER] : The given value is : " + i_Val);
 	}
 }
 
 // derived class
 class Employee extends Person
 {
 	int i_Val;
 	
 	// default constructor
 	Employee()
 	{
 		i_Val = 0;
 	}
 	
 	// method
 	public void setData(int index)
 	{
 		i_Val = index;
 	}
 	
 	// override method
 	public void getData()
 	{
 		System.out.println("[EMP] : The given value is : " + i_Val);
 	}
 }
 
 // main class
 public class Equals
 {
 	// entry point method
 	public static void main(String arg[])
 	{
 		System.out.println("JAVA-CODE");
 		
 		// get the object of class
 		Person pr = new Person(10);
 		
 		// get the integer class object
 		Integer in = new Integer(10);
 		//Integer next = in;
 		
 		
 		System.out.println("The Integer object and Person object are same : " + in.equals(pr));
 		
 	}
 }
 
 
 
 
 
