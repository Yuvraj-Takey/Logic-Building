/*
 *
 * Use scanf function to read a string of characters (into character type array called text) including alphabets,
 * digits, blanks, tabs etc except new line character. Write a loop that will examine each character in
 * a character-type array and determine how many of the characters are letters, how many are digits,
 * how many are blanks and how many are tabs. Assume that text contains 80 characters.
 *
 *	@Author - Yuvraj Takey
 */
 
 #include <stdio.h>
 #define MAXCHAR	80
 
 int main()
 {
 	char text[MAXCHAR] = {'\0'};
 	int index = 0, i_letter = 0, i_blank = 0, i_tab = 0, i_digit = 0, i_special = 0;
 	
 	printf("Kindly enter any text (include : alphabet, digit, tabs, blanks [Max : %d character])\n\n->",MAXCHAR);
 	scanf("%[^'\n']s",text);
 	
 	// iterate the loop till end of our string
 	for(index = 0; text[index] != '\0'; index++)
 	{
 		// filter for letter characters, digits, tabs, spaces, special characters
 		if( ((text[index] >= 'A') && (text[index] <= 'Z')) || ((text[index] >= 'a') && (text[index] <= 'z')) )
 		{
 			i_letter++;
 		}
 		else if( (text[index] >= '0') && (text[index] <= '9') )
 		{
 			i_digit++;
 		}
 		else if(text[index] == '\t')
 		{
 			i_tab++;
 		}
 		else if(text[index] == ' ')
 		{
 			i_blank++;
 		}
 		else
 		{
 			i_special++;
 		}
 	}
 	
 	printf("\nLetters	\t: %d\nDigits	\t: %d\nTabs	\t: %d\nSpaces	\t: %d\nSpecial	\t: %d\n",i_letter,i_digit,i_tab,i_blank,i_special);
 	
 	return 0;
 }
