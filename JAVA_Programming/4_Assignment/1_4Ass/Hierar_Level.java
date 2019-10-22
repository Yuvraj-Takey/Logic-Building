/**********************************************************************************************

	Modify program 2 to define another class student that derives from person, to
	create a hierarchial inheritance.(employee and student inherit from person)
	-Create objects of person, employee, and student classes to show the order of
	invocation of constructors


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
 
 // class strudent (A person can be student)
 class Student extends Person
 {
 	int i_Val, j_Val;
 
 	// default constructor
 	Student()
 	{
 		System.out.println("[STD] : inside default constructor ");
 		
 		i_Val = j_Val = 0;
 	}
 	
 	// parameterised constructor
 	Student(int index, int jindex)
 	{
 		// calling base class constructor
 		super(index,jindex);
 		
 		System.out.println("[STD] : inside parameterised constructor ");
 		
 		i_Val = index;
 		j_Val = jindex;
 	}
 }
 
 // main class
 public class Hierar_Level
 {
 	// entry point method
 	public static void main(String arg[])
 	{
 		System.out.println("JAVA-CODE");
 		
 		// get the object of all the classes
 		Person pr = new Person();
 		Employee em = new Employee();
 		Student st = new Student();
 	}
 }
 
 
 
 
 
