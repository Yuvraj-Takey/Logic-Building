/* print_Console.c
 *
 * a c program to printing the same file on the console.
 *
 *	@Author - Yuvraj Takey
 *
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#define BAD_DISC	-1
#define END		0
#define MAXCHAR		500
#define	STDERR		2
#define STDOUT		1
#define STDIN		0

/***********************************************************************************
	Function			: print_Console()
	Description			: This function prints the file on colsole
	Input				: int
	Output				: nothing

	@Author : Yuvraj Takey
*/
void print_Console(int i_fd)
{
	int i_ret = 0;
	char buffer[MAXCHAR] = {'\0'};
	
	// read whole file
	while((i_ret = read(i_fd,buffer,MAXCHAR)) != END)
	{
		// check for reading file operation
		if(i_ret == BAD_DISC)
		{
			dprintf(STDERR,"[sorry] : unable to read the file\nReason : %s\n",strerror(errno));
			break;
		}
		
		// printing on screen
		dprintf(STDOUT,"%s",buffer);
		
		// flush buffer
		memset(buffer,0,MAXCHAR);
	}
	
	// execution status	
	dprintf(STDOUT,"Program execution completed\n");

}

int main()
{
	int i_fd = 0;
	
	// open file
	i_fd = open("print_Console.c",O_RDONLY);
	if(i_fd == BAD_DISC)
	{
		dprintf(STDERR,"[sorry] : unable to open file\n");
		return 0;
	}

	print_Console(i_fd);
	
	close(i_fd);	
	return 0;
}
