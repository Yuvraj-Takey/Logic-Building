/**********************************************************************************************

	Modify program 1 to add a default constructor and a SetData() member function.
		-Create an array of 3 student using the default constructor and another
		array of 2 students using the parametrized constructor, and then display
		the data of all 5 course objects.


	@Author 	- Yuvraj Takey
	@Title  	- DSSD-JAVA

**************************************************************************************************/

 import java.lang.*;
 import java.util.Scanner;
 
 // base class
 class Course
 {
 	int c_Id, c_Fees;
 	String c_Duration, c_Desc;
 	
 	// default constructor
 	Course()
 	{
 		c_Id = c_Fees = 0;
 		c_Duration = "";
 		c_Desc = "";
 	}
 	
 	// parameterised constructor
 	Course(int id, String desc, String duration, int fees)
 	{
 		 c_Id = id;
 		 c_Desc = desc;
 		 c_Duration = duration;
 		 c_Fees = fees;
 	}
 	
 	// set data from user
 	public void setData()
 	{
 		// get scanner object
 		Scanner s = new Scanner(System.in);
 		
 		// accept from user
 		System.out.println("Kindly enter the details for Student ");
 			
 		 c_Id = s.nextInt();
		 s.nextLine();
		 c_Desc = s.nextLine();
 		 c_Duration = s.nextLine();
 		 c_Fees = s.nextInt();
 	}
 	
 	
 	// display data
 	public void getData()
 	{
 		if(c_Id > 0)
 		{
 			// Result
	 		System.out.println("\nCourse Id      : " + c_Id);
	 		System.out.println("Course Descrip : " + c_Desc);
	 		System.out.println("Course Duration: " + c_Duration);
	 		System.out.println("Course Fees    : " + c_Fees);
	 	}
 	}
 }
 
 // main class
 public class College
 {
 	// entry point method
 	public static void main(String arg[])
 	{
 		System.out.println("JAVA-CODE");
 		int c_Id, c_Fees;
 		String c_Duration, c_Desc;
 		
 		// get scanner object
 		Scanner s = new Scanner(System.in);
 		
 		// get the Cousre array
 		Course cr1[] = new Course[3];
 		Course cr2[] = new Course[2];
 		
 		// loop for default object
 		for(int index = 0; index < cr1.length; index++)
 		{
 			cr1[index] = new Course();
 			
 			// invoke class method
 			cr1[index].setData();
 		}
 		
 		
 		// loop for parameterised object
 		for(int index = 0; index < cr2.length; index++)
 		{
 			// accept from user
 			System.out.println("Kindly enter the details for Student ");
 			
 			 c_Id = s.nextInt();
 			 s.nextLine();
	 		 c_Desc = s.nextLine();
	 		 c_Duration = s.nextLine();
	 		 c_Fees = s.nextInt();
 			
 			// get the object 
 			cr2[index] = new Course(c_Id, c_Desc, c_Duration, c_Fees);
 		}
 		
 		
 		
 		// Result
 		for(int index = 0; index < cr1.length; index++)
 		{
	 		// invoke class method
	 		cr1[index].getData();
	 	}
	 	// Result
 		for(int index = 0; index < cr2.length; index++)
 		{
	 		// invoke class method
	 		cr2[index].getData();
	 	}
 	}
 }
 
 
 
 
 
