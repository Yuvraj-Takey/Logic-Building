#include<stdio.h>

//void fun(int **ptr, int rows, int cols)
void fun(int (*ptr)[2], int rows, int cols)
{
	int i,j;
//	printf("%p\n",ptr);
	printf("%d\n",ptr[0][0]);
	printf("%d\n",ptr[0][1]);
	printf("%d\n",ptr[1][0]);
	printf("%d\n",ptr[1][1]);
//	ptr[0][1] = 10;
//	printf("%d\n",ptr[1][1]);
	printf("%d\n",*(*(ptr + 0)+0));
	printf("%d\n",*(*(ptr + 0)+1));
	printf("%d\n",*(*(ptr + 1)+0));
	printf("%d\n",*(*(ptr + 1)+1));
	return ;
}

int main(void)
{
//	int *a[2]={{1,2},{3,4}};
	int a[2][2]={{1,2},{3,4}};	
	
	fun (a, 2, 2);
	return 0;
}


/*

#include<stdio.h>

//void fun(int **ptr, int rows, int cols)
void fun(int (*ptr)[2], int rows, int cols)
{
	int i,j;
	printf("%p\n",ptr);
	printf("%d\n",ptr[0][0]);
	printf("%d\n",ptr[0][1]);
	printf("%d\n",ptr[1][0]);
	ptr[0][1] = 10;
	printf("%d\n",ptr[1][1]);
//	printf("%d\n",*(*(ptr + 0)+0));
//	printf("%d\n",*(*(ptr + 0)+1));
//	printf("%d\n",*(*(ptr + 1)+0));
//	printf("%d\n",*(*(ptr + 1)+1));
	return ;
}

int main(void)
{
//	int *a[2]={{1,2},{3,4}};
	int a[2][2]={{1,2},{3,4}};	
	
	fun (a, 2, 2);
	printf("%d\n",a[0][1]);
	return 0;
}

*/
