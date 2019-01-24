/*
 * a program to count the vowels and letters in free text given as standard input. Read text a character at a time until you encounter
 * end-of-data. Then print out the number of occurrences of each of the vowels a, e, i,o and u in the text,
 * the total number of letters, and each of the vowels as an integer percentage of the letter total.
 *
 *	@Author - Yuvraj Takey
 */
 
 #include <stdio.h>
 
 int main()
 {
 	int iTotal = 0, ia = 0, ie = 0, ii = 0, io = 0, iu = 0, rest = 0;
 	char ch = ' ';

	// accept input till negativevalue is entered 	
 	while((ch = getchar()) != EOF)
 	{
 		// count tootal number is encountered
 		iTotal++;
 		
 		switch(ch)
 		{
 			case 'a':
 				ia++;
 				break;
 		
 			case 'e':
 				ie++;
 				break;
 		
 			case 'i':
 				ii++;
 				break;
 		
 			case 'o':
 				io++;
 				break;
 		
 			case 'u':
 				iu++;
 				break;
 		
 			default:
 				rest++;
 				break;
 		}
 	}
 	
 	// printing character
 	printf("Number of characters:\n");
 	printf("a : %d, e : %d, i : %d, o : %d, u : %d, rest : %d\n",ia,ie,ii,io,iu,rest);
 
 	// calculate	
 	ia = (((float)ia/iTotal)*100);
 	ie = (((float)ie/iTotal)*100);
 	ii = (((float)ii/iTotal)*100);
 	io = (((float)io/iTotal)*100);
 	iu = (((float)iu/iTotal)*100);
 	rest = (((float)rest/iTotal)*100);
 	
 	// printing result
 	printf("Percentage of total:\n");
 	printf("a : %d, e : %d, i : %d, o : %d, u : %d, rest : %d\n",ia,ie,ii,io,iu,rest);
 	
 	
 	return 0;
 }
