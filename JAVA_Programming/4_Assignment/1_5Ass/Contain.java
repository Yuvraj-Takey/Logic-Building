/**********************************************************************************************

	a java file Person.java containing definition of independent class Person in package com.person, 
	and another java file Address.java containing definition of independent class Address in com.address package.
	-Write a container class employee that has a person and an address object as contained
	data members (besides other data members) by importing the above packages.
	-Demonstrate the passing of arguments in the constructors of person and
	address classes by the constructor of the employee class.

	---> use command : javac -d . <java_file_name>

	@Author 	- Yuvraj Takey
	@Title  	- DSSD-JAVA	[Employee class]

**************************************************************************************************/
 
 import com.Person;
 import com.Address;
 import java.lang.*;
 import java.util.Scanner;
 
 
 class Employee
 {
 	Person pr;
 	Address ad;
 	
 	int i_Val, j_Val;
 	
 	// default constructor
 	Employee()
 	{
 		System.out.println("[EMP] : inside default constructor");
 		
 		// get the object of both classes
 		pr = new Person();
 		ad = new Address();
 	}
 	
 	// parameterised constructor
 	Employee(int index, int jindex)
 	{
 		System.out.println("[EMP] : inside parameterised constructor");
 		
 		i_Val = index;
 		j_Val = jindex;
 		
 		// get the object of both classes
 		pr = new Person(index,jindex);
 		ad = new Address(jindex,index);
 	}
 }
 
 // main class
 public class Contain 
 {
 	// entry point method
 	public static void main(String arg[])
 	{
 		System.out.println("JAVA-CODE");
 		
 		// get the object of above class
 		Employee em = new Employee(10,20);
 	}
 }
 
