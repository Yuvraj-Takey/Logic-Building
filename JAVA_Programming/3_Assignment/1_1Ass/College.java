/**********************************************************************************************

	Define a class named Course having data members ID, Description, Duration and Fees. 
		-The class should have one parametrized constructors and GetData()
		function member to display the data.
		-Create an array of 5 course objects and then display the data for all
		of them.


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
 	
 	// parameterised constructor
 	Course(int id, String desc, String duration, int fees)
 	{
 		 c_Id = id;
 		 c_Desc = desc;
 		 c_Duration = duration;
 		 c_Fees = fees;
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
 		Course cr[] = new Course[5];
 		
 		for(int index = 0; index < cr.length; index++)
 		{
 			// accept from user
 			System.out.println("Kinly enter the details for Student : " + (index+1));
 			
 			 c_Id = s.nextInt();
 			 s.nextLine();
	 		 c_Desc = s.nextLine();
	 		 c_Duration = s.nextLine();
	 		 c_Fees = s.nextInt();
 			
 			// get the object 
 			cr[index] = new Course(c_Id, c_Desc, c_Duration, c_Fees);
 		}
 		
 		// Result
 		for(int index = 0; index < cr.length; index++)
 		{
	 		// invoke class method
	 		cr[index].getData();
	 	}
 	}
 }
 
 
 
 
 
