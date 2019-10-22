/*********************************************************************************************************************

	Demonstrate the access specifiers public and default with the student class
	in program 5 and also demonstrate that other access specifiers(protected and
	private) can not be used with class.

	@Author 	- Yuvraj Takey
	@Title		- DSSD-JAVA

**********************************************************************************************************************/

 import java.lang.*;
 import java.util.Scanner;
 
 class Student
 {
 	String sName;
 	public int iRoll, iAge;
 	
 	
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
 }
 
 // main class
 public class College
 {
 	// entry point method
 	public static void main(String arg[])
 	{
 		System.out.println("JAVA CODE");
 	
 		// get the scanner object
 		Scanner s = new Scanner(System.in);	
 		
 		// get the object of above class
 		Student std_run = new Student();
 		Student std_con = new Student();
 		
 		// get data from user
 		System.out.println("Kindlye enter the Strudents details");
 		System.out.print("Name : ");	std_run.sName = s.nextLine();
 		System.out.print("Roll : ");	std_run.iRoll = s.nextInt();
 		System.out.print("Age  : ");	std_run.iAge = s.nextInt();
 	
 		// get  the values
 		System.out.println("Student Name : " + std_run.sName);
 		System.out.println("Student Roll : " + std_run.iRoll);
 		System.out.println("Student Age  : " + std_run.iAge + "\n");	
 	
 	}	
 }
 
 
 
 
