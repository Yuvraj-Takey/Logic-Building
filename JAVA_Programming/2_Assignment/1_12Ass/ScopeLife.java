/*********************************************************************************************************************

	a program to demonstrate the scope and lifetime of primitive values
	and class objects.


	@Author 	- Yuvraj Takey
	@Title		- DSSD-JAVA

**********************************************************************************************************************/

 import java.lang.*;
 import java.util.Scanner;
 
 
 class Check
 {
 	static int iNo1;
 	int iNo2;
 	
 	// default constructor
 	Check()
 	{
 		iNo1 = iNo2 = 1;
 	}
 	
 	// parameterised constructor
 	Check(int iNum1, int iNum2)
 	{
 		iNo1 = iNum1;
 		iNo2 = iNum2;
 	}
 	
 	public void swap(int iNum1, int iNum2)
 	{
 		//swap of  numbers
 		iNum1 = iNum1 + iNum2;
 		iNum2 = iNum1 - iNum2;
 		iNum1 = iNum1 - iNum2;
 		
 		System.out.println("[SWAP] : Value after swap : iNo1 [" + iNum1 + "] iNo2 [" + iNum2 + "]");
 	}
 	
 	public void sameVal()
 	{
 		int iNo1 = 30, iNo2 = 40;
 		
 		System.out.println("[SVAL] : iNo1 : " + iNo1);
 		System.out.println("[SVAL] : iNo2 : " + iNo2);
 		System.out.println("[SVAL] : this.iNo1 : " + this.iNo1);
 		System.out.println("[SVAL] : this.iNo2 : " + this.iNo2);
 		
 		
 		// change value
 		System.out.println("[SVAL] : Changing value..");
 		this.iNo1 = 50;
 		this.iNo2 = 60;
 		
 		System.out.println("[SVAL] : this.iNo1  : " + this.iNo1);
 		System.out.println("[SVAL] : Check.iNo1 : " + Check.iNo1);
 		System.out.println("[SVAL] : this.iNo2  : " + this.iNo2);
 		System.out.println("[SVAL] : iNo2 : " + iNo2);
 	}
 }
 
 public class ScopeLife
 {
 	public static void main(String arg[])
 	{
 		System.out.println("JAVA CODE");
 		int iNo1 = 10, iNo2 = 20;
 		
 		
 		// get the object of above class
 		Check ck = new Check();
 		
 		// invoke class methods
 		System.out.println("[MAIN] : Value before swap: iNo1 [" + iNo1 + "] iNo2 [" + iNo2 + "]");
 		ck.swap(iNo1,iNo2);
 		System.out.println("[MAIN] : Value after swap : iNo1 [" + iNo1 + "] iNo2 [" + iNo2 + "]");
 		
 		ck.sameVal();
 		
 	}
 }
