/*********************************************************************************************************************

	Define a class of type Distance that has Feet and Inches as members.
		-Define a function that adds two Distances passed as argument and
		 returns the sum as another Distance object.
		-Place the class in a package named user.own.pack .
		 Compile and run the java file using console (javac and java utility).
		-Write a program that imports this package and uses class to find the sum of two distances.


	@Author 	- Yuvraj Takey
	@Title		- DSSD-JAVA

**********************************************************************************************************************/

 import java.lang.*;
 import user.own.pack.Distance;

// main class
 public class Calc
 { 
 	// entry point method
 	public static void main(String arg[])
 	{
 		System.out.println("JAVA CODE");
 		
 		// get the Distance reference
 		Distance dref;
 		
 		// get the object of Distance
 		Distance dt1 = new Distance(3,25);
 		Distance dt2 = new Distance(2,5);
 		Distance dt = new Distance();
 		
 		// get calculation
 		dref = dt.addDist(dt1,dt2);
 		dref.getDist();
 	}
 }

