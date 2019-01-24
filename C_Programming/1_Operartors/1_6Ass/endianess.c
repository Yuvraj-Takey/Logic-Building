#include<stdio.h>

/*
	Function		: main
	Discription		: This function checks whether the given processor is little endian or big endian
	Input			: None
	Output			: Processor architecture

	@Author			: Yuvraj Takey
*/

int main()
{
	int iNum = 1;
	char ch = (int)iNum;

	if(ch == 1)
	{
		printf("The system is Little endian compatible\n");
	}
	else
	{
		printf("The system is Big endianess compatible\n");
	}

	return 0;
}
