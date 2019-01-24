
#include <stdio.h>

int main()
{
	int c = 0;
	
	__asm__
	(
		"movl	$10, -12(%rbp);"
		"movl	$20, -8(%rbp);"
		"movl	$0, -4(%rbp);"
		"movl	-12(%rbp), %edx;"
		"movl	-8(%rbp), %eax;"
		"addl	%edx, %eax;"
		"movl	%eax, -4(%rbp);"
		"movl	$.LC0, %edi;"
	
	);
	
	printf("Addition is: %d\n",c);
	
	return 0;
}
