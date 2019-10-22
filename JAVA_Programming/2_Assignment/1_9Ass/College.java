/*********************************************************************************************************************

	Define a class of type address that has street, locality and city as members.
		-Rework program 5 to add to the student class an object of address class
		as a data member which stores the student's address.

	@Author 	- Yuvraj Takey
	@Title		- DSSD-JAVA

**********************************************************************************************************************/

 import java.lang.*;
 import java.util.Scanner;
 
 class Address
 {
 	String street, locality, city;
 	
 	// default constructor
 	Address()
 	{
 		// code
 	}
 	
 	public void setData()
 	{
 		// get scanner
 		Scanner s = new Scanner(System.in);
 		
 		// message
 		System.out.println("Kindle enter the student address");
 		
 		System.out.print("Street   :\t "); street = s.nextLine();
 		System.out.print("Locality :\t "); locality = s.nextLine();
 		System.out.print("City     :\t "); city = s.nextLine();
 		
 	}
 	
 	public void getData()
 	{
 		// message
 		System.out.println("Student local Address :");
 		
 		if(!street.isEmpty())
 		System.out.println("Street   :\t " + street);
 		
 		if(!locality.isEmpty())
 		System.out.println("Locality :\t " + locality);
 		
 		if(!city.isEmpty())
 		System.out.println("City     :\t " + city);
 	}
 }
 
 class Student
 {
 	Address std_add;
 	private String sName;
 	private int iRoll, iAge;
 	
 	
 	// default constructor
 	Student()
 	{
 		// get the object of Address class
 		std_add = new Address();
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
 		System.out.print("Name\t : ");	sName = s.nextLine();
 		System.out.print("Roll\t : ");	iRoll = s.nextInt();
 		System.out.print("Age \t : ");	iAge = s.nextInt();
 		
 		// set the student address
 		std_add.setData();
 	}
 	
 	public void getData()
 	{
 		// check for empty value
 		if((sName.length() != 0) && (iRoll > 0))
 		{
 			// message
 			System.out.println("\nStudent Details");
 		
 			// results
 			System.out.println("Name\t : " + sName);
 			System.out.println("Roll\t : " + iRoll);
 			System.out.println("Age \t : " + iAge + "\n");
 			
 			// get the student address
 			std_add.getData();
 		}
 		else
 		{
 			// message
 			System.out.println("[SORRY] : Inappropriate Student Details");
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
 	}
 }
 
 
 
 
