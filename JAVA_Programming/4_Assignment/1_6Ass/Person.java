/**********************************************************************************************

	Rework program 5 to use both inheritance and containership.
	The employee class inherits from person class and acts as a container class for address class object.
	
	@Author 	- Yuvraj Takey
	@Title  	- DSSD-JAVA	[Person Class]

**************************************************************************************************/
 
 import java.lang.*;
 import java.util.Scanner;
 
 public class Person
 {
 	int i_Val, j_Val;
 	
 	// default constructor
 	public Person()
 	{
 		System.out.println("[PER] : inside default constructor");
 	}
 	
 	// parameterised constructor
 	public Person(int index, int jindex)
 	{
 		System.out.println("[PER] : inside parameterised constructor - " + index + " and " + jindex);
 		
 		i_Val = index;
 		j_Val = jindex;
 	}
 	
 	// clean up method
 	public void finalize()
 	{
 		System.out.println("[PER] : inside finalizer method");
 	}
 }
 

 
