/*
 * a sample programs using preprocessor operators #, ## and also conditional compilation.
 *
 *	@Author - Yuvraj Takey
 */
 
 #include <stdio.h>
 #define COMBINE(token1,token2) token1##token2
 
 #define background 10
 	#ifndef background
 		#define background 10
 		#define foreground 20
 	#else
 		#define foreground 20
 	#endif
 	
 
 int main()
 { 	
 	int ivar1 = 10, ivar2 = 20, ivar3 = 30, ivar5 = 50;
 	static int ivar4 = 40;
 	
 	printf("%d\n",COMBINE(ivar,1));
 	printf("%d\n",COMBINE(ivar,2));
 	printf("%d\n",COMBINE(ivar,3));
 	printf("%d\n",COMBINE(ivar,4));
 	printf("%d\n",COMBINE(ivar,5));
 	
 	printf("\nConditional Compilation : %d , %d\n",background,foreground);
 	
 	return 0;
 }
