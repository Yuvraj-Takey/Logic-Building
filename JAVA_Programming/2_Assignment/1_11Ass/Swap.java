/*********************************************************************************************************************

	Write a program to swap two numbers by
		a) Passing primitive values to the method (attempt to show that swapping is not possible)
		b) Creating two objects of Integer class and passing these object to
		method using reference variable.

	@Author 	- Yuvraj Takey
	@Title		- DSSD-JAVA

**********************************************************************************************************************/

 import java.lang.*;
 import java.util.Scanner;
 
 class Swap_op
 {
 
 	// default constructor
 	public Swap_op()
 	{
 		//code
 	}
 	
 	// method for swapping
 	public void swapNos(int ino1, int ino2)
 	{
 		// swapping numbers
 		ino1 = ino1 + ino2;
 		ino2 = ino1 - ino2;
 		ino1 = ino1 - ino2;
 	}
 	
 	// method for swapping
 	public void swapNos(Integer ob1, Integer ob2)
 	{
 		// swapping numbers
 		ob1 = ob1.intValue() + ob2.intValue();
 		ob2 = ob1.intValue() - ob2.intValue();
 		ob1 = ob1.intValue() - ob2.intValue();
 	}
 }
 
 
 // main class
 public class Swap
 {
 	// entry point method
 	public static void main(String arg[])
 	{
 		System.out.println("JAVA CODE");
 		int i_PNo1 = 10, i_PNo2 = 20;
 		
 		// get integer object
 		Integer i_ONo1 = new Integer(30);
 		Integer i_ONo2 = new Integer(40);
 		
 		
 		// get the object
 		Swap_op so = new Swap_op();
 		
 		
 		
 		// invoke class method
 		System.out.println("Using Primitive :-");
 		System.out.println("[BEFORE] - First value : [" + i_PNo1 + "], Second value : [" + i_PNo2 + "]");
 		so.swapNos(i_PNo1,i_PNo2);
 		System.out.println("[AFTER_] - First value : [" + i_PNo1 + "], Second value : [" + i_PNo2 + "]");
 		
 		
 		System.out.println("\nUsing Integer Object :-");
 		System.out.println("[BEFORE] - First value : [" + i_ONo1.intValue() + "], Second value : [" + i_ONo2.intValue() + "]");
 		so.swapNos(i_ONo1,i_ONo2);
 		System.out.println("[AFTER_] - First value : [" + i_ONo1.intValue() + "], Second value : [" + i_ONo2.intValue() + "]");
	
		// message
		System.out.println("[INFO_] : See Notes in Swap.java ..");
 	}
 }
 
 /**
 NOTES:
 	Java is always uses pass by value mechanism, and Integer is immutable and you can't update the callers reference. 
 	Hence, It is not possible to swap two primitives or Integer objects using a method.


 	You can use an array or IntHolder or any user class objects
 	
 	Example of IntHolder Class: [import -> org.omg.CORBA.IntHolder]
 	
 	public void swapNos(IntHolder ob1, IntHolder ob2)
 	{
 		// swapping numbers
 		ob1.value = ob1.value + ob2.value;
 		ob2.value = ob1.value - ob2.value;
 		ob1.value = ob1.value - ob2.value;
 	}
 
 **/
 
 
 
