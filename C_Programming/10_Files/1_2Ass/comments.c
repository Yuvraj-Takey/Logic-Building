/*
 * Write a program to remove all the comments from a ‘C’ program
 *
 *	@Author - Yuvraj Takey
 */
 
 #include <stdio.h>
 #include <fcntl.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <string.h>
 
 #define END		0
 #define MAXBUFF	512
 #define RUNNING	1

/***********************************************************************************
	Function			: rm_Comments()
	Description			: This function removes all the comments from given file
	Input				: int, char*
	Output				: nothing

	@Author : Yuvraj Takey
*/ 
 void rm_Comments(int fd, char *name)
 {
 	char p_Buf[MAXBUFF] = {'\0'}, o_Buf[MAXBUFF] = {'\0'};
 	int i_Res = 0, i_off = 0, i_out = 0, index;
 	
 	// open the output file
 	i_out = open(name,O_WRONLY|O_CREAT);
 	if(i_out == -1)
 	{
 		printf("[SORRY] : file not exist\n");
 		return;
 	}
 	
 	// iterate till end of the file
 	while((i_Res = read(fd,p_Buf,MAXBUFF)) != END)
 	{
 		// iterate till all operation not performen
 		for(index = 0, i_off = 0; index != i_Res; index++)
 		{
 			// check for first comment symbol
 			if(p_Buf[index] == '/')
 			{
 				// check for single line comment
 				if(p_Buf[index + 1] == '/')
 				{
 					// iterate till new line not get
 					while(p_Buf[index] != '\n')
 					{
 						index++;
 					}
 				}// check for multiple line command
 				else if(p_Buf[index + 1] == '*')
 				{
 					// iterate till condition becomes fails
 					while(RUNNING)
 					{
 						// check for multiple line comment (end)
 						if((p_Buf[index] == '*') && (p_Buf[index + 1] == '/'))
 						{
 							// file index
 							index++;
 							break;
 						}
 						
 						// file index
 						index++;
 					}
 				}
 				else
 				{
 					// if other than comment copy all character to new buffer
 					o_Buf[i_off] = p_Buf[index];
 					
 					// increment new buffer index
 					i_off++;
 				}
 			}
 			else
 			{
 				// copy buffer to buffer
 				o_Buf[i_off] = p_Buf[index];
 				
 				// index of new buffer
 				i_off++;
 			}
 		}
 		
 		// write the whole updated buffer into new file
 		i_Res = write(i_out,o_Buf,strlen(o_Buf));
 		
 		// flush all the old memory
 		memset(o_Buf,0,MAXBUFF);
 		memset(p_Buf,0,MAXBUFF);
 	}	
 	
 	return;
 }
 
 int main()
 {
 	int i_fd = 0;
 
 	// open the file	
 	i_fd = open("interest.c",O_RDWR);
 	
 	// calling to the function
 	rm_Comments(i_fd,"output.c");
 	
 	// free the resources
 	close(i_fd);
 	
 	return 0;
 }
