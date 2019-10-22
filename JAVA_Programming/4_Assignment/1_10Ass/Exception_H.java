/*********************************************************************************************************************

	Create a user defined exception to check whether your employee exist in your
	data structure (use any data structure to store the employees -like array,
	ArrayList etc) and throw exception if name is not in the employees list. Use the
	catch and finally block to make an appropriate solution.

	@Author 	- Yuvraj Takey
	@Title		- DSSD-JAVA

**********************************************************************************************************************/

 import java.lang.*;
 import java.util.Scanner;
 import java.util.ArrayList;
 
 class EmpNotFoundException extends Exception
 {
 	String eStr;
 	
 	// default constructor
 	public EmpNotFoundException()
 	{
 		eStr.concat("[EXCEP] : EmpNotFoundException occured");
 	}
 	
 	// parameterised constructor
 	public EmpNotFoundException(String excepStr)
 	{
 		eStr = excepStr;
 	}
 	
 	public void printStackTraceEmp()
 	{
 		System.out.println("Exception in thread java.lang.EmpNotFoundException \n\t " + eStr);
 	}
 }
 
 class Employee
 {
 	ArrayList<String> eList;
 	String eName;
 
 	// default contructor
 	public Employee()
 	{
 		// get object of empty array list with default size is 10
 		eList = new ArrayList<String>();
 	}
 	
 	// parameterised constructor
 	public Employee(int iSize)
 	{
 		// get object of empty array list with provided size
 		eList = new ArrayList<String>(iSize);
 	}
 	
 	public void loadEmpData()
 	{
 		if(eList != null)
 		{
 			eList.add("Yuvraj Takey");
 			eList.add("Shashank Udakhe");
 			eList.add("Rahul Bobate");
 			eList.add("Shahaji Kadam");
 			eList.add("Rushikesh Kushte");
 			eList.add("Mayur Kale");
 			eList.add("Nalin Vaidya");
 			eList.add("Aniket Kadam");
 			eList.add("Trupti Patil");
 			eList.add("Akshay Kadam");
 		}
 	}
 	
 	public void getName()
 	{
 		// get the scanner object
 		Scanner s = new Scanner(System.in);
 		
 		// get from user
 		System.out.println("[INFO_] : Kindly enter the name of employee");
 		eName = s.nextLine();
 	}
 	
 	public void checkEmp()
 	{
 		boolean flag = false;
 		
 		try
 		{
 		
	 		// iterate over the ArrayList
	 		for(String data : eList)
	 		{
	 			// compare date with user provided data
	 			if((data.compareToIgnoreCase(eName)) == 0)
	 			{
	 				flag = true;
	 				break;
	 			}
	 		}
	 		
	 		// check loop status
	 		if(!flag)
	 		{
	 			throw new EmpNotFoundException("[EXCEP] : Given employee details are not listed in system");
	 		}
 		}
 		catch(EmpNotFoundException e)
 		{
 			e.printStackTraceEmp();
 		}
 		finally
 		{ 	
 			// free the ArrayList		
 			eList.clear();
 			
 			//message
 			System.out.println("[INFO_] : memory deallocation completes");
 		}
 	}
 	
 }
 
 // main class
 public class Exception_H
 {
 	// entry point method
 	public static void main(String arg[])
 	{
 		System.out.println("JAVA CODE");
 		
 		// get the object of employee class
 		Employee em = new Employee();
 		
 		// invoke the class method
 		em.loadEmpData();
 		em.getName();
 		
 		// check availibility
 		em.checkEmp();
 	}
 }
 
 
 
 
