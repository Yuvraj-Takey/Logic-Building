/**********************************************************************************************

	Define a base class person and a derived class employee with single inheritance.
	-Define SetData() member functions in each of the class with different
	signatures to set the data members and demonstrate overloading of member
	functions.
	-Define GetData() member functions in each of the class with same signatures
	to display data and demonstrate overriding of member functions.


	@Author 	- Yuvraj Takey
	@Title  	- DSSD-JAVA

**************************************************************************************************/

 import java.lang.*;
 import java.util.Scanner;
 
 // base class
 class Person
 {
 	int i_Val, j_Val;
 	
 	// default constructor
 	Person()
 	{
 		i_Val = j_Val = 0;
 	}
 	
 	// overload method
 	public void setData(int index)
 	{
 		i_Val = index;
 	}
 	
 	// overload method
 	public void setData(int index, int jindex)
 	{
 		i_Val = index;
 		j_Val = jindex;
 	}
 	
 	// override method
 	public void getData()
 	{
 		System.out.println("[PER] : The given value is : " + i_Val + " and " + j_Val);
 	}
 }
 
 // derived class
 class Employee extends Person
 {
 	int i_Val, j_Val;
 	
 	// default constructor
 	Employee()
 	{
 		i_Val = j_Val = 0;
 	}
 	
 	// overload method
 	public void setData(int index)
 	{
 		i_Val = index;
 	}
 	
 	// overload method
 	public void setData(int index, int jindex)
 	{
 		i_Val = index;
 		j_Val = jindex;
 	}
 	
 	// override method
 	public void getData()
 	{
 		System.out.println("[EMP] : The given value is : " + i_Val + " and " + j_Val);
 	}
 }
 
 // main class
 public class Inherit_C
 {
 	// entry point method
 	public static void main(String arg[])
 	{
 		System.out.println("JAVA-CODE");
 		
 		// get the object of both the class
 		Person pr = new Person();
 		Employee em = new Employee();
 		
 		// set the data
 		pr.setData(10);
 		em.setData(20,30);
 		
 		// get the data
 		pr.getData();
 		em.getData();
 	}
 }
 
 
 
 
 
