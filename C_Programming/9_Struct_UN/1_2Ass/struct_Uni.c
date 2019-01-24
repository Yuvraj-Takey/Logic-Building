/*
 * Define structure with two members (one int and other char). Also define s union with two members (one int and other char).
 * Print the sizes of structure and union in number of bytes.
 *
 *	@Author - Yuvraj Takey
 */
 
 #include <stdio.h>
 
 //#pragma pack(1)
 typedef struct exampleStruct
 {
 	char st_ch;
 	int st_no;
 }STEXAMP;
 
 typedef union exampleUnion
 {
 	char un_ch;
 	int un_no;
 }UNEXAMP;
 
 int main()
 {
 	// creating object of structure and union
 	STEXAMP st_obj;
 	UNEXAMP un_obj;
 	
 	// printing result
 	printf("Size of Struct : %ld\nSize of Union : %ld\n\n",sizeof(st_obj),sizeof(un_obj));
 	return 0;
 }
