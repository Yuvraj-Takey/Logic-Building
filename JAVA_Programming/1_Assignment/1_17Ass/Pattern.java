/*
 *	a Java program to print Floyd’s triangle
 *
 *	@DSSD	- Yuvraj Takey
 */
 
 import java.io.*;
 import java.util.Scanner;
 
 class Draw
 {
 	int iRow,iCol;
 	
 	// default constructor+.-+
 	
 	Draw()
 	{
 		iRow = iCol = 0;
 	}
 	
 	// parameterised constructor
 	Draw(int ival)
 	{
 		iRow = iCol = ival;
 	}
 	
 	// get the size of pattern
 	public void getDepth()
 	{
 		Scanner s = new Scanner(System.in);
 		
 		// get input from user
 		System.out.println("Kindly enter the Pattern Depth");
 		iRow = iCol = s.nextInt();
 	}
 	
 	public void DrawPat()
 	{
 		if(iRow <= 0)
 		{
 			System.out.println("[SORRY] : size is not valid");
 			return;
 		}
 	
 		int index = 0, jindex = 0, icnt = 1;
 		
 		// iterate over the row
 		for(index = 0; index < iRow; index++)
 		{
 			// iterate over column
 			for(jindex = 0; (jindex <= index); jindex++)
 			{
 				// check for pattern
 				if((index == jindex) || (index > jindex))
 				{
 					System.out.print(" " + ( icnt ));
 					
 					// increment the icount
 					icnt++;
 				}
 			}
 			
 			System.out.println("");
 		}
 	}
 	
 }
 
 class Pattern
 {
 	public static void main(String arg[])
 	{
 		System.out.println("HELLO PATTERN");
 		
 		// create object
 		Draw d = new Draw();
 		
 		// call to method
 		d.getDepth();
 		d.DrawPat();
 		
 	}
 }
