/*
 *
 * program to read your name into a character array. Print the name along with the length of your name 
 * and sizeof the array in which name is stored.
 *
 *	@Author - Yuvraj Takey
 */
 
 #include <stdio.h>
 #include <string.h>
 
 int main()
 {
 	char c_Name[50] = {'\0'};
 	
 	printf("Kindly enter your name\n");
 	scanf("%[^'\n']s",c_Name);
 	
 	printf("\nYour Name \t: %s\nName Length \t: %ld\nArray Size \t: %ld\n",c_Name,strlen(c_Name),sizeof(c_Name));
 	
 	return 0;
 }
