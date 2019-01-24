/*
 *
 *	a) Display the hexadecimal equivalent of the one’s complement
 *	b) Carry out a masking operation and then display the hexadecimal equivalent of the result
 * 	c) Carry out a bit shifting operation and then display the hexadecimal equivalent of the result
 * 	d) Exit
 *
 *	If the masking operation is selected, prompt the user for the type of operation (bitwise and, bitwise exclusive
 *	or, or bitwise or) and then a (hexadecimal) value for the mask. If the bit shifting operation is selected, prompt
 *	the user for the type of shift (left to right), and then the number of bits.
 *
 *	@Author - Yuvraj Takey
 */
 
 #include <stdio.h>
 #include <stdio_ext.h>
 #define RUNNING 1
 
 int binary_con(int num)
 {
 	
 	//printf("HEX VALUE %d\n\n", num);
 	
 	static int i_bin = 0;
	int mod = 0, rem = 0;	
	
	if(num == 0)
	{
		return 1;
	}
	
	// take reminder
	rem = num % 2;
	
	// recursive call
	binary_con(num / 2);
	
	// store the reminder into static variable
	i_bin = i_bin ^ rem;
	
	// filter for shifting
	if(num != 1)
	{
		// shift by 1 bit
		i_bin = i_bin << 1;
	}
	
	// return binary
	return i_bin;
 }
 
 void once_Comp(int hex)
 {
 	int i_Ret = 0;
 	
 	// calling function ()
 	i_Ret = binary_con(hex);
 	 	
 	printf("Once Compliment : %#x\n",~i_Ret);
 	
 	return ;
 }
 
 int main()
 {
 	char ch = 0;
 	int i_Hex = 0, i_Mask = 0;
 	
 	printf("Enter Hexadecimal number\n");
 	scanf("%x",&i_Hex);
 	
 	// unconditional loop
 	while (RUNNING)
 	{
 		__fpurge(stdin);
	 	printf("Enter your choice\n");
	 	printf("a.	Display the hexadecimal equivalent of the one’s complement\n");
	 	printf("b.	Carry out a masking operation and then display the hexadecimal equivalent of the result\n");
	 	printf("c.	Carry out a bit shifting operation and then display the hexadecimal equivalent of the result\n");
	 	printf("d. 	Exit\n");
	 	
	 	scanf("%c",&ch);
	 	
	 	switch(ch)
	 	{
	 		__fpurge(stdin);
	 		case 'a' :
	 			once_Comp(i_Hex);
	 			break;
	 			
	 		case 'b':
	 			// flush buffer
	 			__fpurge(stdin);
	 			
	 			// menu for second operation
	 			printf("a.	Bitwise AND\n");
	 			printf("b.	Bitwise OR\n");
	 			printf("c.	Bitwise Ex-OR\n");	 			
	 			scanf("%c",&ch);
	 			
	 			printf("Enter mask number\n");
	 			scanf("%x",&i_Mask);
	 			
	 			if(ch == 'a')
	 			{
	 				printf("HEX value : %#x\t Mask value : %#x\nAND Operation : %#x\n",i_Hex,i_Mask,i_Hex & i_Mask);
	 			}
	 			else if(ch == 'b')
	 			{
	 				printf("HEX value : %#x\t Mask value : %#x\nOR Operation : %#x\n",i_Hex,i_Mask,(i_Hex | i_Mask));
	 			}
	 			else if(ch == 'c')
	 			{
	 				printf("HEX value : %#x\t Mask value : %#x\nEx-OR Operation : %#x\n",i_Hex,i_Mask,(i_Hex ^ i_Mask));
	 			}
	 			else
	 			{
	 				printf("[SORRY] : operation could not permit\n");
	 			}
	 			
	 			break;
	 			
	 		case 'c':
	 			// flush buffer
	 			__fpurge(stdin);
	 			
	 			// menu for third operation
	 			printf("a.	Left Shift\n");
	 			printf("b.	Right Shift\n");	 			
	 			scanf("%c",&ch);
	 			
	 			printf("Enter bit to shift number\n");
	 			scanf("%x",&i_Mask);
	 			
	 			if(ch == 'a')
	 			{
	 				printf("HEX value : %#x\t bit to be shifted : %#x\nOperation : %#x\n",i_Hex,i_Mask,(i_Hex << i_Mask));
	 			}
	 			else if (ch == 'b')
	 			{
	 				printf("HEX value : %#x\t bit to be shifted : %#x\nOperation : %#x\n",i_Hex,i_Mask,(i_Hex >> i_Mask));
	 			}
	 			else
	 			{
	 				printf("[SORRY] : operation could not permit\n");
	 			}
	 			break;
	 			
	 		case 'd':
	 			ch = '~';
	 			break;
	 			
	 		default:
	 			printf("[SORRY] : Invalid input\n");
	 			
	 	}
		
		// termination for while	 	
	 	if(ch == '~')
	 	{
	 		break;
	 	}
	 }
	 	
 	return 0;
 }
