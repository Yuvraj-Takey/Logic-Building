/**********************************************************************************************

	Rework program 5 to use both inheritance and containership.
	The employee class inherits from person class and acts as a container class for address class object.

	@Author 	- Yuvraj Takey
	@Title  	- DSSD-JAVA	[Address Class]

**************************************************************************************************/
 
 package com;
 import java.lang.*;
 import java.util.Scanner;
 
 public class Address
 {
 	int i_Val, j_Val;
 	
 	// default constructor
 	public Address()
 	{
 		System.out.println("[ADR] : inside default constructor");
 	}
 	
 	// parameterised constructor
 	public Address(int index, int jindex)
 	{
 		System.out.println("[ADR] : inside parameterised constructor - " + index + " and " + jindex);
 		
 		i_Val = index;
 		j_Val = jindex;
 	}
 	
 	// clean up method
 	public void finalize()
 	{
 		System.out.println("[ADR] : inside finalizer method");
 	}
 }
 

 
