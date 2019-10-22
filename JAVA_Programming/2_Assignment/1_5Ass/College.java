/*********************************************************************************************************************

	Define a class of type Student that has rollno, name and age as private data
	members. Define SetData() and GetData() as public member functions with
	appropriate functionality.
		-Write a program that declares 2 student objects, initializes the first
		at run-time and second by reading from console, and then displays both
		student’s data.

	@Author 	- Yuvraj Takey
	@Title		- DSSD-JAVA

**********************************************************************************************************************/

 import java.lang.*;
 import java.util.Scanner;
 
 class Student
 {
 	private String sName;
 	private int iRoll, iAge;
 	
 	
 	// default constructor
 	Student()
 	{
 		iRoll = iAge = 0;
 	}
 	
 	// parameterised constructor
 	Student(String name, int roll, int age)
 	{
 		iRoll = roll;
 		iAge = age;
 		sName = name;
 	}
 	
 	public void setData()
 	{
 		// get the scanner object
 		Scanner s = new Scanner(System.in);
 		
 		// get data from user
 		System.out.println("Kindlye enter the Strudents details");
 		System.out.print("Name : ");	sName = s.nextLine();
 		System.out.print("Roll : ");	iRoll = s.nextInt();
 		System.out.print("Age  : ");	iAge = s.nextInt();
 	}
 	
 	public void getData()
 	{
 		// check for empty value
 		if((sName.length() != 0) && (iRoll > 0))
 		{
 			// results
 			System.out.println("Student Name : " + sName);
 			System.out.println("Student Roll : " + iRoll);
 			System.out.println("Student Age  : " + iAge + "\n");
 		}
 	}
 }
 
 // main class
 public class College
 {
 	// entry point method
 	public static void main(String arg[])
 	{
 		System.out.println("JAVA CODE");
 		
 		// get the object of above class
 		Student std_run = new Student("Yuvraj Takey",33,25);
 		Student std_con = new Student();
 		
 		// invoke class method
 		std_con.setData();
 		std_con.getData();
 		std_run.getData();
 	}
 }
 
 
 
 
