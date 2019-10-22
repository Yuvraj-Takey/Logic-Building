/*********************************************************************************************************************

	Distance class that will provide the operation for calculating distance

	@Author 	- Yuvraj Takey
	@Title		- DSSD-JAVA

**********************************************************************************************************************/

 package user.own.pack;
 import java.lang.*;
 import java.util.Scanner;
 
 public class Distance
 {
 	int feet, inches;
 	
 	// default constructor
 	public Distance()
 	{
 		feet = inches = 0;
 	}
 	
 	// parameterised constructor
 	public Distance(int feet, int inches)
 	{
 		this.feet = feet;
 		this.inches = inches;
 	}
 	
 	public void setDist()
 	{
 		// get Scanner object
 		Scanner s = new Scanner(System.in);
 	
 		// message
 		System.out.println("Kindly enter the value of feet and inches");
 		feet = s.nextInt();
 		inches = s.nextInt();
 	}
 	public void getDist()
 	{
 		if((feet > 0) && (inches > 0))
 		System.out.println("Result : " + feet + "." + inches + " inches");
 		else
 		System.out.println("[SORRY] : inappropriate/incomplete values");
 	}
 	
 	// method for adding two distances
 	public Distance addDist(Distance d1, Distance d2)
 	{
 		// get the Distance object
 		Distance result = new Distance();
 		int i_feet = 0, i_inch = 0;
 		
 		//calculate distance
 		i_feet = d1.feet + d2.feet;
 		i_inch = d1.inches + d2.inches;
 		
 		// if inces is 12 then it should add 1 in feet
 		result.feet = i_feet + (i_inch/12);
 		result.inches = i_inch % 12;
 		
 		return result;
 	}
 }
 
  
 
 
 
