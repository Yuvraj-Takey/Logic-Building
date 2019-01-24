/*
 * (n, b). This function rotates integer n towards right by b positions.
 *
 *
 *	@Author - Yuvraj Takey
*/


#include<stdio.h>

int rotate_right(int p,int p1)
{
	int i;

	// iterate the loop will p1
	 for(i=0;i<p1;i++)
	 {
		  p=p/2;
	 }

	return p;
}


int main()
{
	 int n,n1;
	 printf("Enter the number\n");
	 scanf("%d",&n);

	 printf("Enter the number of bits u wana shift right\n");
	 scanf("%d",&n1);

	 printf("the %d right shift %d id %d\n",n1,n,rotate_right(n,n1));
	 
	 return 0;
}

