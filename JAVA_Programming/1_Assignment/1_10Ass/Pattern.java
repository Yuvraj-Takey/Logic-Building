/*
 *	Print following structure in Java.
 *
 *	@DSSD	- Yuvraj Takey
 */
 
 import java.lang.*;
 
 class DrawLine
 {
 	int iRow, iCol;
 	
 	// default constructor
 	DrawLine()
 	{
 		iRow = iCol = 0;
 	}
 
 	// parameterised constructor	
 	DrawLine(int ival)
 	{
 		iCol = ival;
 		iRow = ival;
 	}
 	
 	void DrawPat()
 	{
 		// check for empty
 		if(iRow <= 0)
 		{
 			System.out.println("[SORRY] : Unable to get the size");
 			return;
 		}
 		
 		// checks for size
 		if(iRow < 3)
 		{
 			System.out.println("[SORRY] : Size should not be less than 3");
 			return;
 		}
 		
 		// check for odd value
 		if((iRow % 2) == 0)
		{
			System.out.println("[SORRY] : Size should be odd");
 			return;
		} 		
 		
 		int index = 0, jindex = 0, icnt = 1;
 		
 		// row iterator
 		for(index = 0; index < iRow; index++)
 		{ 	
 			// column iterator		
 			for(jindex = 0; (jindex < icnt) && (jindex < iCol); jindex++)
 			{
 				// printing symbol
 				System.out.print("* ");
 			}
 			
 			System.out.println("");
 			
 			// condition for pattern
 			if(index >= (iRow/2))
 			{
 				icnt = icnt - 2;
 			}
 			else
 			{
 				icnt = icnt + 2;
 			}
 		}
 	}
 }
 
 class Pattern
 {
 	public static void main(String args[])
 	{
 		int ival = 5;
 	
 		System.out.println("WELCOME TO PATTERN");
 		
 		// creating object
 		DrawLine dl = new DrawLine(ival);
 		
 		// call the method 
 		dl.DrawPat();		
 	}
 }
