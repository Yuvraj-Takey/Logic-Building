/**********************************************************************************************

	Rework program 5 to use both inheritance and containership.
	The employee class inherits from person class and acts as a container class for address class object.

	@Author 	- Yuvraj Takey
	@Title  	- DSSD-JAVA	[Employee class]

**************************************************************************************************/
 
 import com.Address;
 import java.lang.*;
 import java.util.Scanner;
 
 
 class Employee extends Person
 {
 	Address ad;
 	
 	int i_Val, j_Val;
 	
 	// default constructor
 	Employee()
 	{
 		// call to base class constructor
 		super();
 	
 		System.out.println("[EMP] : inside default constructor");
 		
 		// get the object of Address classes
 		ad = new Address();
 	}
 	
 	// parameterised constructor
 	Employee(int index, int jindex)
 	{
 		// call to base class constructor
 		super(index,jindex);
 		
 		System.out.println("[EMP] : inside parameterised constructor");
 		
 		i_Val = index;
 		j_Val = jindex;
 		
 		// get the object of address classes
 		ad = new Address(jindex,index);
 	}
 }
 
 // main class
 public class Contain_Inherit 
 {
 	// entry point method
 	public static void main(String arg[])
 	{
 		System.out.println("JAVA-CODE");
 		
 		// get the object of above class
 		Employee em = new Employee();
 	}
 }
 
