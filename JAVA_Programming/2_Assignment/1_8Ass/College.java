/*********************************************************************************************************************

	Modify program 5 to add another array member marks to the class that stores
	marks of 5 subjects and then rework with the program.

	@Author 	- Yuvraj Takey
	@Title		- DSSD-JAVA

**********************************************************************************************************************/

 import java.lang.*;
 import java.util.Scanner;
 
 class Student
 {
 	private String sName;
 	private int iRoll, iAge;
 	private int iMarks[];
 	private final String sSub[] = {"C  ","C++","DS ","Linux","Java"};
 	
 	
 	// default constructor
 	Student()
 	{
 		iRoll = iAge = 0;
 		iMarks = new int[5];
 	}
 	
 	// parameterised constructor
 	Student(String name, int roll, int age, int marks[])
 	{
 		iRoll = roll;
 		iAge = age;
 		sName = name;
 		iMarks = marks;
 	}
 	
 	public void setData()
 	{
 		// get the scanner object
 		Scanner s = new Scanner(System.in);
 		
 		// get data from user
 		System.out.println("Kindly enter the Student details");
 		System.out.print("Name : ");	sName = s.nextLine();
 		System.out.print("Roll : ");	iRoll = s.nextInt();
 		System.out.print("Age  : ");	iAge = s.nextInt();
 		
 		// get marks
 		System.out.println("Enter the marks of student");
 		for(int index = 0; index < iMarks.length; index++)
 		{
 			System.out.printf("%-10s\t:",sSub[index]);
 			iMarks[index] = s.nextInt();
 		}
 	}
 	
 	public void getData()
 	{
 		// check for empty value
 		if((sName.length() != 0) && (iRoll > 0))
 		{
 			// message 
 			System.out.println("\nDetails of Student:");
 			
 			// results
 			System.out.println("Student Name : " + sName);
 			System.out.println("Student Roll : " + iRoll);
 			System.out.println("Student Age  : " + iAge + "\n");
 			
 			// get marks
 			System.out.println("The marks of student");
 			for(int index = 0; index < iMarks.length; index++)
 			{
 				System.out.printf("%-10s\t: %s\n",sSub[index],iMarks[index]);
 				
 			}
 		}
 	}
 	
 	public void getTotalMarks()
 	{
 		if(iMarks.length > 0)
 		{
 			int iTotal = 0, index = 0;
 			
 			// calculate the marks
 			for(index = 0; index < iMarks.length; index++)
 			{
 				iTotal = iTotal + iMarks[index];
 			}
 			
 			//message
 			System.out.println("Total marks is : " + iTotal + "/" + (index*100));
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
 		Student std_con = new Student();
 		
 		// invoke class method
 		std_con.setData();
 		std_con.getData();
 		std_con.getTotalMarks();
 	}
 }
 
 
 
 
