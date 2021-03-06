/**********************************************************************************************

	a java file Person.java containing definition of independent class Person in package com.person, 
	and another java file Address.java containing definition of independent class Address in com.address package.
	-Write a container class employee that has a person and an address object as contained
	data members (besides other data members) by importing the above packages.
	-Demonstrate the passing of arguments in the constructors of person and
	address classes by the constructor of the employee class.

	---> use command : javac -d . <java_file_name>

	@Author 	- Yuvraj Takey
	@Title  	- DSSD-JAVA	[Person Class]

**************************************************************************************************/
 
 package com;
 import java.lang.*;
 import java.util.Scanner;
 
 
 public class Person
 {
 	int i_Val, j_Val;
 	
 	// default constructor
 	public Person()
 	{
 		System.out.println("[PER] : inside default constructor");
 	}
 	
 	// parameterised constructor
 	public Person(int index, int jindex)
 	{
 		System.out.println("[PER] : inside parameterised constructor - " + index + " and " + jindex);
 		
 		i_Val = index;
 		j_Val = jindex;
 	}
 	
 	// clean up method
 	public void finalize()
 	{
 		System.out.println("[PER] : inside finalizer method");
 	}
 }
 

 
