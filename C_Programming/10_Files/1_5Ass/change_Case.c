/*
 * a program which reads a line of characters. Each character entered from the keyboard is tested to determine its case,
 * and is then written to the data file in opposite case. Display the contents of the file.
 *
 *
 *	@Author - Yuvraj Takey
 */
 
 #include <stdio.h>
 #include <fcntl.h>
 #include <unistd.h>
 #include <string.h>
 
 #define MAXCHAR	500
 #define MAXNAME	255
 #define END		0
 #define BAD_DESC	(-1)
 #define STDERR		2
 #define STDOUT		1
 #define STDIN		0
 
 /***********************************************************************************
	Function			: change_Case()
	Description			: This function toggle the case of character and write it in file
	Input				: int, char[]
	Output				: nothing

	@Author : Yuvraj Takey
*/
 
 void change_Case(int i_fd, char c_Data[MAXCHAR])
 {
 	int i_ret = 0, i_index = 0;
 	
 	// convert the case sensivity of the data
 	for(i_index = 0; c_Data[i_index] != '\0'; i_index++)
 	{
 		if((c_Data[i_index] >= 'a') && (c_Data[i_index] <= 'z'))
 		{
 			c_Data[i_index] = c_Data[i_index] - 32;
 		}
 		else if((c_Data[i_index] >= 'A') && (c_Data[i_index] <= 'Z'))
 		{
 			c_Data[i_index] = c_Data[i_index] + 32;
 		}
 	}
 	
 	// write converted (case) data into file
 	i_ret = write(i_fd,c_Data,i_index);
 	if(i_ret == BAD_DESC)
 	{
 		dprintf(STDERR,"[sorry] : unable to write into file\n");
 	}
 	else
 	{
 		// flush the memory for reuse
 		memset(c_Data,0,MAXCHAR);
 		
 		// reset the offset 
 		lseek(i_fd,0,SEEK_SET);
 		
 		// read the data from file
 		i_ret = read(i_fd,c_Data,MAXCHAR);
 		if(i_ret == BAD_DESC)
 		{
 			dprintf(STDERR,"[sorry] : unable to read data from file\n");
 		}
 		else
 		{
 			// display the file data on screen
 			dprintf(STDOUT,"%s\n",c_Data);
 		}
 	}
 	

 	return;
 }
 
 int main()
 {
 	int i_fd = 0;
 	char c_Data[MAXCHAR] = {'\0'}, c_name[MAXNAME] = {'\0'};

 	printf("Enter the name for file\n");
	scanf("%[^'\n']s",c_name);
 
  	// open/create the file
 	i_fd = open(c_name,O_RDWR | O_CREAT);
 	if(i_fd == BAD_DESC)
 	{
 		dprintf(STDERR,"[sorry] : file could not open/created");
 		return -1;
 	}
 	
 	// accept input from console	
 	printf("Kindly enter your data (include : upper & lower case)\nuse '~' : to end the operation\n");
 	scanf("%[^'~']s",c_Data);
 	
 	// calling function
 	change_Case(i_fd,c_Data);
 	
 	// printing on screen
 	printf("Program execution completed\n"); 	
 
 	close(i_fd);	
 	return 0;
 }
