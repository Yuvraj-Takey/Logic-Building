/*
 * Perform this operation
 * Shifting a binary number to the left n bits and multiplying the binary number by 2n
 * Shifting a binary number to the right n bits and dividing the binary number by 2n.
 *
 *
 *	@Author - Yuvraj Takey
 */
 
 #include <stdio.h>
 typedef unsigned int UINT;
 
 /* If we left shift a perticular number by n and divide with the same n value then the result will same of initial number
  */
 
 int main()
 {
 	UINT i_initB = 0x000ff000 ,i_Bit = 0, i_Res = 0;
 	
 	printf("Kindly enter the number for bitwise operation\n");
 	scanf("%d",&i_Bit);
 	
 	//actual number
 	printf("Initial number is \t: %u\n",i_initB);
 	
 	// left shift by n
 	i_Res = i_initB << i_Bit;
 	printf("Left shift by %u \t: %u\n",i_Bit,i_Res);
 	
 	// perform 2n
 	i_Res = i_Res * (i_Bit * i_Bit);
 	printf("multiply by 2n \t\t: %u\n\n",i_Res);
 	
 	// reset the variable
 	i_Res = 0;
 	
 	// right shift by n
 	i_Res = i_initB >> i_Bit;
 	printf("right shift by %u \t: %u\n",i_Bit,i_Res);
 	
 	// perform 2n
 	i_Res = i_Res / (i_Bit * i_Bit);
 	printf("Divide by 2n \t\t: %u\n",i_Res);
 	
 	return 0;
 }
