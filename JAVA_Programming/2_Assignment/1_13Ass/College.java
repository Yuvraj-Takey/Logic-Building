/*********************************************************************************************************************

	Modify program 5 to add
		a) a private static data member counter that keeps a track of the number
		of students currently existing
		b) a private static function member SetCounter() that increments the
		counter by one.
		Demonstrate the use of these members.


	@Author 	- Yuvraj Takey
	@Title		- DSSD-JAVA

**********************************************************************************************************************/

 import java.lang.*;
 import java.util.Scanner;
 
 class Student
 {
 	private static int counter = 0;
 	private String sName;
 	private int iRoll, iAge;
 	
 	
 	// default constructor
 	Student()
 	{
 		iRoll = iAge = 0;
 		setCounter();
 	}
 	
 	// parameterised constructor
 	Student(String name, int roll, int age)
 	{
 		iRoll = roll;
 		iAge = age;
 		sName = name;
 		setCounter();
 	}
 	
 	private static void setCounter()
 	{
 		// increment counter
 		counter++;
 		
 		// message
 		System.out.println("Object " + Student.counter + " created");
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
 		Student std_run1 = new Student("Yuvraj Takey",33,25);
 		Student std_run2 = new Student("john leo",34,25);
 		
 		
 		// invoke class method
 		std_run1.getData();
 		std_run1.getData();
 		
 		
 	}
 }
 
 
 
 
