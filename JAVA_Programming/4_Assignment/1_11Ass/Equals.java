/*********************************************************************************************************************

	a program to demonstrate the use of equals method of Object class and
	compare its functionality with ( = = ) operator.

	@Author 	- Yuvraj Takey
	@Title		- DSSD-JAVA

**********************************************************************************************************************/

 import java.lang.*;
 
 class Check
 {
 	int iNum;
 	
 	// default constructor
 	Check()
 	{
 		iNum = 0;
 	}
 	
 	// parameterised constructor
 	Check(int iVal)
 	{
 		iNum = iVal;
 	}
 	
 }
 
 // main class
 public class Equals
 {
 	// entry point method
 	public static void main(String arg[])
 	{
 		System.out.println("JAVA CODE");
 		System.out.println("[INFO_] : Creating object of class Check");
 		
 		// get the object of classes
 		Integer in = new Integer(50);
 		Check ck = new Check();
 		
 		// get the reference of Check class
 		Check ck_Obj = ck;
 		
 		// check equality of object
 		System.out.println("[INFO_] : The Integer objects are equal with same value : " + in.equals(50));
 		System.out.println("[INFO_] : The Integer objects are equal with diff value : " + in.equals(60));
 
 		// get for class Check		
 		System.out.println("[INFO_] : The Check class objects are equal \t\t: " + ck.equals(ck_Obj));
 		
 		// get another object reference
 		ck_Obj = new Check();;
 		
 		//Now, ck_Obj and ck will be pointing to different objects.
 		System.out.println("[INFO_] : The Check class objects are equal \t\t: " + (ck == ck_Obj));
 	}
 }
 
 
 
 
