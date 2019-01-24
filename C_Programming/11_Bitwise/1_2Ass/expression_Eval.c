/*
 *	evaluate each of the following bitwise expressions with a = 0xa2c3.
 *
 *	a) ~a
 *	b) a ^ 0x3f06
 *	c) a | 0x3f06
 *	d) a | ~0x3f06
 *	e) a >> 3
 *	f) a << 5
 *	g) a ^ ~a
 *	h) a | ~a
 *	i) (a & ~0x3f06) << 8
 *	j) a & ~ (0x3f06 >> 8)
 *
 *
 *	@Author - Yuvraj Takey
 */
 #include <stdio.h>
 typedef unsigned short USHT;
 
 int main()
 {
 	USHT a = 0xa2c3, s_rs = 0;
 	
 	printf("\nvalue (a)  : %hu\t value ( a )\t\t\t : %hu\t HEX : %#X\n",a,a,a);
 	
 	s_rs = ~a;
 	printf("value (a)  : %hu\t value ( ~a )\t\t\t : %hu\t HEX : %#X\n",a,s_rs,s_rs);
 	
 	s_rs = a ^ 0x3f06;
 	printf("value (a)  : %hu\t value ( a ^ 0x3f06 )\t\t : %hu\t HEX : %#X\n",a,s_rs,s_rs);
 	
 	s_rs = a | 0x3f06;
 	printf("value (a)  : %hu\t value ( a | 0x3f06 )\t\t : %hu\t HEX : %#X\n",a,s_rs,s_rs);
 	
 	s_rs = a | ~0x3f06;
 	printf("value (a)  : %hu\t value ( a | ~0x3f06 )\t\t : %hu\t HEX : %#X\n",a,s_rs,s_rs);
 	
 	s_rs = a >> 3;
 	printf("value (a)  : %hu\t value ( a >> 3 )\t\t : %hu\t\t HEX : %#X\n",a,s_rs,s_rs);
 	
 	s_rs = a << 5;
 	printf("value (a)  : %hu\t value ( a << 5 )\t\t : %hu\t HEX : %#X\n",a,s_rs,s_rs);
 	
 	s_rs = a ^ ~a;
 	printf("value (a)  : %hu\t value ( a ^ ~a )\t\t : %hu\t HEX : %#X\n",a,s_rs,s_rs);
 	
 	s_rs = a | ~a;
 	printf("value (a)  : %hu\t value ( a | ~a )\t\t : %hu\t HEX : %#X\n",a,s_rs,s_rs);
 	
 	s_rs = (a & ~0x3f06) << 8;
 	printf("value (a)  : %hu\t value ( ( a & ~0x3f06) << 8 )\t : %hu\t HEX : %#X\n",a,s_rs,s_rs);
 	
 	s_rs = a & ~ (0x3f06 >> 8);
 	printf("value (a)  : %hu\t value ( a & ~ (0x3f06 >> 8) )\t : %hu\t HEX : %#X\n\n",a,s_rs,s_rs);
 	
 	
 	return 0; 
 }
