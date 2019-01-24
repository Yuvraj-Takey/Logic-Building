/*
 * a program last that prints the last n lines of its text input. By default n should be 5
 *
 *	@Author - Yuvraj Takey
 */
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <fcntl.h>
 #include <unistd.h>
 #include <string.h>
 #include <errno.h>
 #define MAXBUFF	250
 #define RUNNING	1
 #define FAILURE	-1
 #define SUCCESS	0
 #define FINISH		-1
 
 /***********************************************************************************
	Function			: last_N()
	Description			: This function impliments [$ tail -n] command
	Input				: int, char*
	Output				: nothing

	@Author : Yuvraj Takey
*/

void last_N(int i_line, char *f_name)
{
	char c_arr[MAXBUFF] = {'\0'};
	int i_fd = 0, i_offs = 0, index = 0, i_ret = 0,i_size = MAXBUFF, i_remain = MAXBUFF;
		
	i_fd = open(f_name,O_RDONLY);
	if(i_fd == FAILURE)
	{
		printf("[SORRY] : given file could not open\nReason : %s\n",strerror(errno));
		return;
	}
	
	// proced while loop, until we don't get i_line
	while(i_line != -1)
	{
		//flush the memory
		memset(c_arr,0,MAXBUFF);
		
		// if i_offs equals minus value, that mean file data is lessthan buffer length
		i_offs = lseek(i_fd,-(i_size),SEEK_END);
		if(i_offs == FAILURE)
		{
			// set offset to starting position and read whole file
			i_offs = lseek(i_fd,0,SEEK_SET);
			if(i_offs == FAILURE)
			{
				printf("[SORRY] : unable to seek in file\n");
				break;
			}
			else
			{
				// file contains data, which is less than MAXBUFF
				// read whole data, from file
				i_ret = read(i_fd,c_arr,i_remain);
				if(i_ret <= SUCCESS)
				{
					printf("[SORRY] : unable to read from file\nReason : %s\n",strerror(errno));
					break;
				}
			}		
		}
		else	// that mean file data is bigger than buffer length
		{
			// read from file, Buffer by Buffer
			i_ret = read(i_fd,c_arr,MAXBUFF);
			if(i_ret <= SUCCESS)
			{
				printf("[SORRY] : unable to read from file\nReason : %s\n",strerror(errno));
				break;
			}
			
			// check for last iteration (file data is lesser than buffer length)
			if(i_offs < i_remain)
			{
				i_remain = i_offs;
			}
					
		}// end of IF-ELSE

		// iterate till we dont fulfill the line number(condition)
		for(index = i_ret; (index != FINISH); index--)
		{
			// check for line break
			if(c_arr[index] == '\n')
			{
				i_line--;
				
				if(i_line == FINISH)
				{
					break;
				}
			}
		}// end of for loop
		
	
		// checks for final operation (whether you have to continue or break the loop)
		if((i_line == FINISH) && (i_offs == SUCCESS)) 	// buffer_length > offset
		{
			lseek(i_fd,index+1,SEEK_SET);
		}
		else if((i_line >= SUCCESS) && (index == FINISH) && (i_offs == SUCCESS)) // file gets empty, but line condition not fulfill
		{
			lseek(i_fd,0,SEEK_SET);
			break;
		}
		else if((i_line >= SUCCESS) && (index == FINISH) && (i_offs > SUCCESS)) // buffer_length < offset/file_length
		{
			// if line are not fulfill the condition but there is data in file then continue to while
			i_size = i_size + MAXBUFF; 
			continue;
		}
		else if((i_line == FINISH) && (i_offs > SUCCESS)) // line condition fulfills, but file is bigger than expect
		{
			lseek(i_fd,(i_offs + index+1),SEEK_SET);
		}
		
		
	}// end of while
	
	// flush  the memory		
	memset(c_arr,0,MAXBUFF);

	// read that complete file
	while((i_ret = read(i_fd,c_arr,i_ret)) != 0)
	{
		// write it on console
		write(1,c_arr,i_ret);
	}
	
	// close file
	close(i_fd);		
	
	return;
}
 
 int main(int argc, char **argv)
 {
 	// argument limit
 	if(argc != 4)
 	{
 		printf("[SORRY] : invalid input\n");
 		printf("[usage] : last <number_of_lines> <file_Name>\n\n");
 		return -1;
 	}
 	
 	if(strcasecmp(argv[1],"last") != 0)
 	{
 		printf("[SORRY] : invalid command\n");
 		printf("usage : last <number_of_lines> <file_Name>\n\n");
 		return -1;
 	}
 	
 	last_N(atoi(argv[2]),argv[3]);
 	
 	return 0;
 }
