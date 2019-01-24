/*
 * a program that will concatenate two files, that is append the contents of one file at the end of another file
 * and write the results into a third file. You must be able to execute command at DOS prompt as follows:
 * C > CONCAT Source 1.txt source 2.txt Target.txt.
 *
 *	@Author - Yuvraj Takey
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define FAILURE		-1
#define MAXCHAR		512
#define FILE_PERM	0777
#define END		0

void file_Concat(int i_fd1, int i_fd2, int i_out)
{
	char buffer[MAXCHAR] = {'\0'};
	short i_ret = 0;
	int i_Off = 0;
		
	// iterate first file
	while((i_ret = read(i_fd1,buffer,MAXCHAR)) != END)
	{
		// check for reading operation
		if(i_ret == FAILURE)
		{
			dprintf(i_out,"[sorry] : unable to read first file\n");
			break;
		}
		
		// writing the copied data into file
		i_ret = write(i_fd2,buffer,i_ret);
		if(i_ret == FAILURE)
		{
			dprintf(i_out,"[sorry] : unable to write in target file\nReason : %s\n",strerror(errno));
			break;
		}
	
		// writing result into third file
		dprintf(i_out,"Coping file...\n");
		
		// flush buffer
		memset(buffer,0,MAXCHAR);
	}
	
	// writing result into third file
	dprintf(i_out,"Program execution completed\n");
	
	return ;
}


int main(int argc, char **argv)
{
	int i_fd1 = 0, i_fd2 = 0, i_out = 0;
	
	// check number of argument
	if(argc != 5)
	{
		printf("usage : CONCAT <file1> <file2> <target_file>\n");
		return FAILURE;
	}

	// compare first command
	if(strcasecmp(argv[1],"CONCAT"))
	{
		printf("[sorry] : command not found\n");
		printf("usage : CONCAT <file1> <file2> <target_file>\n");
		return FAILURE;
	}
	
	// open first file in read mode
	i_fd1 = open(argv[2],O_RDONLY);
	if(i_fd1 == FAILURE)
	{
		printf("[sorry] : can not find '%s' file\n",argv[2]);
		return FAILURE;
	}
	
	// open second file in append mode
	i_fd2 = open(argv[3],O_WRONLY | O_APPEND);
	if(i_fd2 == FAILURE)
	{
		printf("[sorry] : can not find '%s' file\n",argv[3]);
		close(i_fd1);
		return FAILURE;
	}
	
	// open the target file in write mode
	i_out = open(argv[4],O_WRONLY);
	if(i_out == FAILURE)
	{
		// creating a file with all permission
		i_out = creat(argv[4],FILE_PERM);
		if(i_out == FAILURE)
		{
			// free all resources
			printf("[sorry] : unable to identify file\n");
			close(i_fd2);
			close(i_fd1);
			return -1;
		}
		else
		{
			printf("[here_] : created target file with name '%s'\n",argv[4]);
		}
	}
	
	// calling the function
	file_Concat(i_fd1,i_fd2,i_out);	
	
	// close all file descripters
	close(i_fd1);
	close(i_fd2);
	close(i_out);
	
	return 0;
}
