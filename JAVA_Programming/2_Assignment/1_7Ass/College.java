/*********************************************************************************************************************

	Demonstrate the use of all access specifiers(public, protected, default and
	private) with the data members of student class in program 5.

	@Author 	- Yuvraj Takey
	@Title		- DSSD-JAVA

**********************************************************************************************************************/

 import java.lang.*;
 import java.util.Scanner;
 
 class Student
 {
 	int iAge;
 	public int iRoll;
 	protected String sName; 	
	private char cGrade;
	 	
 	
 	// default constructor
 	public Student()
 	{
 		iRoll = iAge = 0;
 		cGrade = 'z';
 	}
 	
 	// parameterised constructor
 	public Student(String name, int roll, int age, char grade)
 	{
 		iRoll = roll;
 		iAge = age;
 		sName = name;
 		cGrade = grade;
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
 		System.out.print("grade: ");	cGrade = s.next().charAt(0);
 	}
 	
 	public void getData()
 	{
 		// check for empty value
 		if((sName.length() != 0) && (iRoll > 0))
 		{
 			// results
 			System.out.println("Student Name : " + sName);
 			System.out.println("Student Roll : " + iRoll);
 			System.out.println("Student Age  : " + iAge);
 			System.out.println("Student Grade: " + cGrade + "\n");
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
 		Student std_run = new Student("Yuvraj Takey",33,25,'A');
 		Student std_con = new Student();
 		
 		// invoke class method
 		std_con.setData();
 		std_con.getData();
 		std_run.getData();
 	}
 }
 
 
 
 
