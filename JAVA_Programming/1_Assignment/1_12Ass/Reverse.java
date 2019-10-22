/*
 *	a Java Program to Reverse a String using Recursion.
 *		ex: HELLO WORLD		==>   OLLEH DLROW
 *
 *
 *	@DSSD	- Yuvraj Takey
 */
 
 import java.lang.*;
 import java.util.Scanner;
 
 class StrRev
 {
 	String oStr;
 
 	// default constructor
 	StrRev()
 	{
 		// code
 	}
 	
 	public void getString()
 	{
 		Scanner s = new Scanner(System.in);
 		
 		// get input from user
 		System.out.println("Kindly enter the String");
 		oStr = s.nextLine(); 		
 	}
 	
 	public void doReverse(StringBuilder oStr, int... index)
 	{
 		// termination
 		if(index[0] >= index[1])
 		{
 			return;
 		}
 	
 		// perform operation
 		// get the first character
 		char ch = oStr.charAt(index[0]);
 		
 		// replace last character with first
 		oStr.setCharAt(index[0],oStr.charAt(index[1]));
 		
 		// set character 'ch' to the last position
 		oStr.setCharAt(index[1],ch);
 		
 		// Recursive call
 		doReverse(oStr, (index[0]+1), (index[1]-1));
 	
 	}
 	
 	public String showRevStr()
 	{
 		// get the StringBuilder object (which is mutable)
 		StringBuilder rStr = new StringBuilder();
 		StringBuilder sTemp = new StringBuilder();
 		
 		// check for string length	
 		if(oStr.length() != 0)
 		{ 
 			
 			// get temporary String array
	 		String arr[];
	 		
	 		// Split the original string
	 		arr = oStr.split(" ");
	 		
	 		// iterate till the String array
	 		for(int index = 0; index < arr.length; index++)
	 		{
	 			// clear the string
	 			sTemp.setLength(0);
	 			sTemp.append(arr[index]);
 				
 				// pass the original string along with empty string(for reversing)
 				doReverse(sTemp,0,sTemp.length()-1);
 				
 				// append the result into new string
 				rStr.append(sTemp + " ");
 			}
 		}
 		
 		return rStr.toString();
 	}
 }
 
 public class Reverse
 {
 	public static void main(String arg[])
 	{
 		System.out.println("HELLO REVERSE");
 		
 		// get the object of class
 		StrRev sr = new StrRev();
 		sr.getString();
 		System.out.println("Result is : " + sr.showRevStr());
 		
 	}
 }
