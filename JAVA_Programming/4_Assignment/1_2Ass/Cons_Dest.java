/**********************************************************************************************

	Modify program 1 to define a parametrized constructor and finalizer in each
	class. Demonstrate calling the constructor of the base class from the constructor
	of the derived class.
	-Create objects of person and employee classes to show the order of
	invocation of constructors.


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
 		System.out.println("[PER] : inside default constructor");
 		
 		i_Val = j_Val = 0;
 	}
 	
 	// parameterised constructor
 	Person(int index, int jindex)
 	{
 		System.out.println("[PER] : inside parameterised constructor");
 		
 		i_Val = index;
 		j_Val = jindex;
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
 	
 	// class endup method
 	public void finalize() throws Throwable		// here finalize is not a keyword (you can call it Explicitely)
 	{
 		System.out.println("[PER] : inside finalizer... ");
 	}
 }
 
 // derived class
 class Employee extends Person
 {
 	int i_Val, j_Val;
 	
 	// default constructor
 	Employee()
 	{
 		System.out.println("[EMP] : inside default constructor");
 		
 		i_Val = j_Val = 0;
 	}
 	
 	// parameterised constructor	// by default parameterised const will call base's default cons.(without super key)
 	Employee(int index, int jindex)
 	{
 		// calling base class constructor
 		super(index,jindex);
 		
 		System.out.println("[EMP] : inside parameterised constructor (super method)");
 		
 		i_Val = index;
 		j_Val = jindex;
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
 	
 	// class endup method
 	public void finalize() throws Throwable		// here finalize is not a keyword (you can call it Explicitely)
 	{
 		// call to base class finalize
 		super.finalize();
 		
 		System.out.println("[EMP] : inside finalizer... ");
 	}
 }
 
 // main class
 public class Cons_Dest
 {
 	// entry point method
 	public static void main(String arg[])
 	{
 		System.out.println("JAVA-CODE");
 		
 		// get the object of both the class
 		Person pr = new Person(5,15);
 		Employee em = new Employee(25,35);
 		
 		// abandoned the objects
 		pr = null;
 		em = null;
 		
 		// requesting to Garbage collector to invoke finalize method
 		System.gc();
 	}
 }
 
 
 
 
 
