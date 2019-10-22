/*
 *
 *
 */
 
 import java.io.*;
 
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
 	
 	public void DrawPat()
 	{
 		if(iRow <= 0)
 		{
 			System.out.println("[SORRY] : size is not valid");
 			return;
 		}
 	
 		int index = 0, jindex = 0, icnt = 1;
 		
 		// iterate over the row
 		for(index = 0; index < iRow; index++,icnt++)
 		{
 			// iterate over column
 			for(jindex = 0; (jindex <= index); jindex++)
 			{
 				// check for pattern
 				if((index == jindex) || (index > jindex))
 				{
 					System.out.print(" " + ( icnt ));
 					
 					// calculate the icnt
 					icnt = icnt + ((iRow-1) - jindex);
 				}
 			}
 			
 			System.out.println("");
 			
 			// reset the icnt to index
 			icnt = index+1;
 		}
 	}
 	
 }
 
 class Pattern
 {
 	public static void main(String arg[])
 	{
 		System.out.println("HELLO PATTERN");
 		
 		// create object
 		Draw d = new Draw(9);
 		d.DrawPat();
 		
 	}
 }
