/*
 * Define string class with dynamic memory allocation for string also define all constructors and verload the following operator
 *	(+)([])(=)(>>)(<<). Observe the behaviour of shallow copy and deep copy
 *
 *	@ DSSD
*/
#include <iostream>
using namespace std;
#include <string.h>
#include <stdio_ext.h>
#define MAXBUFF	255
#define MAXARR	5
#define MAXNAME	80

class String_C
{
	char *str;
	int i_size;
	char *arr[MAXARR];
	
	public:
	String_C();
	String_C(const char*);
	String_C(const String_C&);
	void get_Strings();
	String_C operator+(String_C);
	String_C operator=(String_C);
	char* operator[](int);
	~String_C();
	
	friend ostream& operator<<(ostream&, String_C&);
	friend istream& operator>>(istream&, String_C&);
};
// Default Constructor
String_C::String_C()
{
	str = NULL;
	i_size = 0;
	
	// flush string array
	memset(arr,0,sizeof(arr));
}

// Parameterised Constructor
String_C::String_C(const char *newStr)
{
	// get size and parameter string in class object
	i_size = strlen(newStr);
	str = new char[i_size+1];
	
	memset(str,0,i_size);
	memcpy(str,newStr,i_size);
	
	// flush string array
	memset(arr,0,sizeof(arr));
}

// copy constructor
String_C::String_C(const String_C& o_ST)
{
	// copy the object size (deep copy)
	i_size = o_ST.i_size;
	str = new char[i_size+1];
	
	memset(str,0,i_size);
	memcpy(str,o_ST.str,i_size);
	
	// flush string array
	memset(arr,0,sizeof(arr));
}

/***********************************************************************************
	Function			: get_String()
	Description			: This function accept the string array from user
	Input				: Nothing
	Return				: Nothing

	@author : Yuvraj Takey
*/
void String_C::get_Strings()
{
	int index = 0;
	
	cout<<"Enter the "<<MAXARR<<" strings for overload array subscript operator"<<endl;
	
	for(index = 0; index < MAXARR; index++)
	{
		__fpurge(stdin);
		arr[index] = new char[MAXNAME];
		cin.get(arr[index],MAXNAME);
	}
}

/***********************************************************************************
	Function			: []()
	Description			: This function overloads array subscript operator
	Input				: int
	Return				: char*

	@author : Yuvraj Takey
*/
char* String_C::operator[](int index)
{
	return (arr[index]);
}

/***********************************************************************************
	Function			: =()
	Description			: This function overload assignment operator
	Input				: String_C
	Return				: String_C

	@author : Yuvraj Takey
*/
String_C String_C::operator=(String_C o_ST)
{	
	// check for old memory
	if(str != NULL)
	{
		delete []str;
	}
	
	// copy the object size (deep copy)
	i_size = o_ST.i_size;
	str = new char[i_size];
	
	//flush the memory and copy the data
	memset(str,0,i_size);	
	memcpy(str,o_ST.str,i_size);
	
	return (*this);
}

/***********************************************************************************
	Function			: +()
	Description			: This function concatinate the input string
	Input				: String_C
	Return				: String_C

	@author : Yuvraj Takey
*/
String_C String_C::operator+(String_C o_ST1)
{
	String_C o_Temp;
	
	cout<<endl<<"Examle of string concatination"<<endl;
	
	// get the size and allocate new memory
	o_Temp.i_size = ((o_ST1.i_size + (*this).i_size)+1);
	o_Temp.str = new char[(o_Temp.i_size)+1];
	
	//flush the memory
	memset(o_Temp.str,0,o_Temp.i_size);
	
	// concatinate both the strings
	strcpy(o_Temp.str,o_ST1.str);
	strcat(o_Temp.str,(*this).str);
	
	return (o_Temp);
}


// destructor
String_C::~String_C()
{
	// free the allocated memory
	if(str != NULL)
	{
		delete []str;
	}
	
	// check for allocated memory
	if(arr[0] != NULL)
	{
		int index = 0;
		
		// release the memory
		for(index = 0; index < MAXARR; index++)
		{
			delete arr[index];
		}
	}
}

/*************************************************	Naked	***********************************************/

// overloaded insertion operator
ostream& operator<<(ostream& m_cout, String_C &o_ST)
{
	m_cout<<"Your string is :";
	m_cout<<o_ST.str<<endl;
	return (m_cout);
}

// overloaded extraction operator
istream& operator>>(istream& m_cin, String_C &o_ST)
{
	char c_buff[MAXBUFF] = {'\0'};
	
	// accept input from user
	cout<<"Kindly enter your string"<<endl;
	// release old memory
	m_cin.get(c_buff,MAXBUFF);
	
	if(o_ST.str != NULL)
	{
		delete []o_ST.str;
	}
	
	// allocate data to object
	o_ST.i_size = strlen(c_buff);
	o_ST.str = new char[o_ST.i_size+1];
	
	memset(o_ST.str,0,o_ST.i_size);
	memcpy(o_ST.str, c_buff,o_ST.i_size);
	
	return (m_cin);
}

/************************************************	MAIN	***********************************************/


int main()
{
	String_C o_ST1, o_ST2("Same_"), o_ST3(o_ST2), o_STarr;
	
	// accept from user (overload >> and <<)
	cin>>o_ST1;
	cout<<o_ST1;	
	
	
	// addition of two string
	o_ST1 = o_ST2 + o_ST3;
	cout<<o_ST1;	
	
	// for array subscript
	o_STarr.get_Strings();
	
	// show result
	for(int index = 0; index < MAXARR; index++)
	{
		cout<<o_STarr[index]<<"\t";
	}
	
	cout<<endl<<"execution comleted"<<endl;
	
		
	return 0;
}
