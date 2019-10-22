/*
 *	a Java Program to Make a Calculator using Switch Case.
 *
 *
 *	@DSSD	- Yuvraj Takey
 */
 
 import java.lang.*;
 import java.util.Scanner;
 import java.lang.Double;
 
 class CalOp
 {
 	private double iResult;
 	
 	// default constructor
 	public CalOp()
 	{
 		iResult = 0.0;
 	}
 	
 	public double getResult()
 	{ 		
 		return iResult;
 	}
 	
 	private boolean checkExpr(String sExpr)
 	{
 		boolean status = false;
 		
 		// check for invalid string
 		if(sExpr.matches(".*[a-zA-Z].*"))
 		{
 			status = true;
 		}
 		
 		// check for invalid string
 		if((!sExpr.matches(".*[0-9]")) || (!sExpr.matches("[0-9].*")))
 		{
 			status = true;
 		}
 		
 		return status;
 	}
 	
 	public void performOp()
 	{
 		String sOp[], sExpr;
 		Scanner s = new Scanner(System.in);
 		
 		// get the input from user
 		System.out.println("Kindly perform the calculator operation (using : + - / *)");
 		sExpr = s.nextLine();
 	
 		// validate the expression
 		if(checkExpr(sExpr))
 		{
 			System.out.println("[SORRY] : invalid calculation");
 			return;
 		}
 
 		// rearrage the input string
 		sExpr = sExpr.replaceAll("[+]"," + ");
 		sExpr = sExpr.replaceAll("[*]"," * ");
 		sExpr = sExpr.replaceAll("[/]"," / ");
 		sExpr = sExpr.replaceAll("[-]"," - ");
 		sExpr = sExpr.replaceAll(" +"," ");
 		
 		// split the string (with blank space)
 		sOp = sExpr.split(" ");
 		
 		for(int index = 0; index < sOp.length; index++)
 		{
	 		switch(sOp[index])
	 		{
	 			case "+":
	 			{
	 				// check for array boundry 
	 				if((index+1) >= sOp.length)
	 				{
	 					index = -1;
	 				}
	 				else
	 				{
	 					// perform calculation
	 					iResult = (Double.parseDouble(sOp[index-1]) + Double.parseDouble(sOp[index+1]));
	 					
	 					// add result back into string[]
	 					sOp[index + 1] = Double.toString(iResult);
	 					
	 					// increment the index value
	 					index++;
	 				}
	 				
	 				break;
	 			}
	 			case "-":
	 			{
	 				// check for array boundry 
	 				if((index+1) >= sOp.length)
	 				{
	 					index = -2;
	 				}
	 				else
	 				{
	 					// perform calculation
	 					iResult = (Double.parseDouble(sOp[index-1]) - Double.parseDouble(sOp[index+1]));
	 					
	 					// add result back into string[]
	 					sOp[index + 1] = Double.toString(iResult);
	 					
	 					// increment the index value
	 					index++;
	 				}
	 			
	 				break;
	 			}
	 			case "*":
	 			{
	 				// check for array boundry 
	 				if((index+1) >= sOp.length)
	 				{
	 					index = -3;
	 				}
	 				else
	 				{
	 					// perform calculation
	 					iResult = (Double.parseDouble(sOp[index-1]) * Double.parseDouble(sOp[index+1]));
	 					
	 					// add result back into string[]
	 					sOp[index + 1] = Double.toString(iResult);
	 					
	 					// increment the index value
	 					index++;
	 				}
	 			
	 				break;
	 			}
	 			case "/":
	 			{
	 				// check for array boundry 
	 				if((index+1) >= sOp.length)
	 				{
	 					index = -4;
	 				}
	 				else
	 				{
	 					// perform calculation
	 					iResult = (Double.parseDouble(sOp[index-1]) / Double.parseDouble(sOp[index+1]));
	 					
	 					// add result back into string[]
	 					sOp[index + 1] = Double.toString(iResult);
	 					
	 					// increment the index value
	 					index++;
	 				}
	 			
	 				break;
	 			}
	 			
	 		}// end of switch
	 		
	 		// invalid expresion
	 		if(index < 0)
	 		{
	 			System.out.println("[SORRY] : operation could not be perform " + index);
	 			iResult = 0.0;
	 			break;
	 		}
	 		
	 	}// end of for
 		
 	}
 }
 
 class Calc
 {
 	public static void main(String arg[])
 	{
 		System.out.println("WELCOME TO CALCULATOR");
 	
 		double retval = 0.0;
 		
 		// get the object of upper class
 		CalOp cp = new CalOp();
 		
 		// call to method
 		cp.performOp();
 		
 		// get result
 		if((retval = cp.getResult() ) != 0.0)
 		System.out.println("Result is : " + retval);
 	}
 }
