/*
 * Define matrix class with dynamic memory allocation for 2-D matrix. include operator overloading + - << and >>
 * also overload new and delete operators by using malloc and free
 *
 *	@ DSSD
 */
 
 #include <iostream>
 using namespace std;
 #include <stdlib.h>
 
 #define RUNNING	1
 
 class Matrix_C
 {
 	private:
 	static int p;
 	int **mat;
 	int i_Row;
 	int i_Col;
 	
 	public:
 	Matrix_C();
 	Matrix_C(int, int);
 	Matrix_C(const Matrix_C&);
 	~Matrix_C();
 	
 	// we need to overload = operator for deep copy
 	Matrix_C operator =(Matrix_C);
 	Matrix_C operator +(Matrix_C);
 	Matrix_C operator +(int);
 	Matrix_C operator -(Matrix_C);
 	Matrix_C operator -(int);
 	void* operator new(size_t);
 	void operator delete(void *);
 	
 	friend istream& operator >>(istream&, Matrix_C&);
 	friend ostream& operator <<(ostream&, Matrix_C);
 	friend Matrix_C operator +(int, Matrix_C);
 	friend Matrix_C operator -(int, Matrix_C);
 };
 int Matrix_C::p = 0;
 /*
  *	 default constructor
  */
 Matrix_C::Matrix_C()
 {
 	// initialise variable with default value
 	mat = NULL;
 	i_Row = 0;
 	i_Col = 0;
 }
 /*
  *	parameterised constructor
  */
 Matrix_C::Matrix_C(int i_size, int j_size)
 {p++;
	mat = NULL;
 	
 	// allocate memory for rows
 	mat = new int*[i_size];
 	
 	// allocate memory for column
 	for(int index = 0; index < i_size; index++)
 	{
 		mat[index] = new int[j_size];
  	}
 	
 	// initialise the array size
 	this->i_Row = i_size;
 	this->i_Col = j_size;
 }
 /*
  *	copy constructor
  */
 Matrix_C::Matrix_C(const Matrix_C& o_MT)
 {
 	int index = 0;
 	
 	if(o_MT.mat != NULL)
 	{
	 	// allocate new memory for rows
	 	mat = new int*[o_MT.i_Row];
	 	
	 	for(index = 0; index < o_MT.i_Row; index++)
	 	{
	 		// allocate new memory for column
	 		mat[index] = new int[o_MT.i_Col];
	 	}
	 	
	 	// allocate size of the array
	 	i_Row = o_MT.i_Row;
	 	i_Col = o_MT.i_Col;
	 	
	 	// If object contain data then copy it to
	 	if(o_MT.mat != NULL)
	 	{
	 		for(index = 0; index < i_Row; index++)
	 		{
	 			for(int jindex = 0; jindex < i_Col; jindex++)
	 			{
	 				this->mat[index][jindex] = o_MT.mat[index][jindex];
	 			}
	 		}
	 	}
	 }
 }
 
 /***********************************************************************************
	Function			: >>()	// operator overload
	Description			: This function accept the element in object
	Input				: istream&, Matrix_C&
	Return				: istream&

	@author : Yuvraj Takey
*/
 istream& operator >>(istream& m_cin, Matrix_C& o_MTx)
 {
 	int index = 0;

 	// accept the element
 	for(index = 0; index < o_MTx.i_Row; index++)
 	{
 		for(int jndex = 0; jndex < o_MTx.i_Col; jndex++)
 		{
 			m_cin>>o_MTx.mat[index][jndex];
 		}
 	} 
 
 	return m_cin;
 }


 /***********************************************************************************
	Function			: <<()	// operator overload
	Description			: This function displays the element of object
	Input				: ostream&, Matrix_C
	Return				: ostream&

	@author : Yuvraj Takey
*/
 ostream& operator <<(ostream& m_cout, Matrix_C o_MTx)
 {
 	int index = 0;
 	
 	if(o_MTx.mat != NULL)
 	{
	 	cout<<"The matrix elements :"<<endl;
	 	for(index = 0; index < o_MTx.i_Row; index++)
	 	{
	 		for(int jndex = 0; jndex < o_MTx.i_Col; jndex++)
	 		{
	 			m_cout<<o_MTx.mat[index][jndex]<<" ";
	 		}
	 		
	 		m_cout<<endl;
	 	}
 	}
 	
 	return m_cout;
 }
 
 /***********************************************************************************
	Function			: +()	// operator overload
	Description			: This function performs addintion of matrices
	Input				: Matrix_C
	Return				: Matrix_C

	@author : Yuvraj Takey
*/
Matrix_C Matrix_C::operator +(Matrix_C o_M2)
{
	Matrix_C o_Temp;
	
	// check for NULL object
	if((mat == NULL) || (o_M2.mat == NULL))
	{
		cout<<"[SORRY] : invalid operation"<<endl;
		return o_Temp;
	}
	
	int i_index = 0, j_index = 0;
	
	// allocate memory for o_Temp object
	o_Temp.mat = new int*[i_Row];
	
	// allocate memory for columns of matrix
	for(i_index = 0; i_index < i_Row; i_index++)
	{
		o_Temp.mat[i_index] = new int[i_Col];
	}
	
	// assign sizes to o_Temp objct
	o_Temp.i_Row = i_Row;
	o_Temp.i_Col = i_Col;
	
	// perform addition
	for(i_index = 0; i_index < i_Row; i_index++)
	{
		for(j_index = 0; j_index < i_Col; j_index++)
		{
			o_Temp.mat[i_index][j_index] = ((mat[i_index][j_index]) + (o_M2.mat[i_index][j_index]));
		}
	}

	// return local object to callie
	return (o_Temp);
}
/***********************************************************************************
	Function			: +()	// operator overload
	Description			: This function performs addintion of matrice with integral value
	Input				: int
	Return				: Matrix_C

	@author : Yuvraj Takey
*/
Matrix_C Matrix_C::operator +(int i_value)
{
	Matrix_C o_Temp;
	
	// check for NULL object
	if((mat == NULL) || (i_value == 0))
	{
		cout<<"[SORRY] : invalid operation"<<endl;
		return o_Temp;
	}
	
	int i_index = 0, j_index = 0;
	
	// allocate memory for o_Temp object
	o_Temp.mat = new int*[i_Row];
	
	// allocate memory for columns of matrix
	for(i_index = 0; i_index < i_Row; i_index++)
	{
		o_Temp.mat[i_index] = new int[i_Col];
	}
	
	// assign sizes to o_Temp objct
	o_Temp.i_Row = i_Row;
	o_Temp.i_Col = i_Col;
	
	// perform addition
	for(i_index = 0; i_index < i_Row; i_index++)
	{
		for(j_index = 0; j_index < i_Col; j_index++)
		{
			o_Temp.mat[i_index][j_index] = ((mat[i_index][j_index]) + (i_value));
		}
	}

	// return local object to callie
	return (o_Temp);
}

/***********************************************************************************
	Function			: -()	// operator overload
	Description			: This function performs substraction of matrices
	Input				: Matrix_C
	Return				: Matrix_C

	@author : Yuvraj Takey
*/
Matrix_C Matrix_C::operator -(Matrix_C o_M2)
{
	Matrix_C o_Temp;
	
	// check for NULL object
	if((mat == NULL) || (o_M2.mat == NULL))
	{
		cout<<"[SORRY] : invalid operation"<<endl;
		return o_Temp;
	}
	
	int i_index = 0, j_index = 0;
	
	// allocate memory for o_Temp object
	o_Temp.mat = new int*[i_Row];
	
	// allocate memory for columns of matrix
	for(i_index = 0; i_index < i_Row; i_index++)
	{
		o_Temp.mat[i_index] = new int[i_Col];
	}
	
	// assign sizes to o_Temp objct
	o_Temp.i_Row = i_Row;
	o_Temp.i_Col = i_Col;
	
	// perform addition
	for(i_index = 0; i_index < i_Row; i_index++)
	{
		for(j_index = 0; j_index < i_Col; j_index++)
		{
			o_Temp.mat[i_index][j_index] = ((mat[i_index][j_index]) - (o_M2.mat[i_index][j_index]));
		}
	}

	// return local object to callie
	return (o_Temp);
}

/***********************************************************************************
	Function			: -()	// operator overload
	Description			: This function performs addintion of matrice with integral value
	Input				: int
	Return				: Matrix_C

	@author : Yuvraj Takey
*/
Matrix_C Matrix_C::operator -(int i_value)
{
	Matrix_C o_Temp;
	
	// check for NULL object
	if((mat == NULL) || (i_value == 0))
	{
		cout<<"[SORRY] : invalid operation"<<endl;
		return o_Temp;
	}
	
	int i_index = 0, j_index = 0;
	
	// allocate memory for o_Temp object
	o_Temp.mat = new int*[i_Row];
	
	// allocate memory for columns of matrix
	for(i_index = 0; i_index < i_Row; i_index++)
	{
		o_Temp.mat[i_index] = new int[i_Col];
	}
	
	// assign sizes to o_Temp objct
	o_Temp.i_Row = i_Row;
	o_Temp.i_Col = i_Col;
	
	// perform addition
	for(i_index = 0; i_index < i_Row; i_index++)
	{
		for(j_index = 0; j_index < i_Col; j_index++)
		{
			o_Temp.mat[i_index][j_index] = ((mat[i_index][j_index]) - (i_value));
		}
	}

	// return local object to callie
	return (o_Temp);
}


 /***********************************************************************************
	Function			: =()	// operator overload
	Description			: This function performs deep copy for matrices
	Input				: Matrix_C
	Return				: Matrix_C

	@author : Yuvraj Takey
*/
Matrix_C Matrix_C::operator =(Matrix_C o_M2)
{
	int index = 0, jindex = 0;
	
	// check for memory allocation
	if(mat != NULL)
	{
		// deallocate the memory
		for(index = 0; index < i_Row; index++)
		{
			delete mat[index];
		}
		
		if(index != 0)
		{
			delete []mat;
			mat = NULL;
		}
	}
	
	// allocate new memory for rows
 	mat = new int*[o_M2.i_Row];
 	
 	for(index = 0; index < o_M2.i_Row; index++)
 	{
 		// allocate new memory for column
 		mat[index] = new int[o_M2.i_Col];
 	}
 	
 	// allocate size of the array
 	i_Row = o_M2.i_Row;
 	i_Col = o_M2.i_Col;
 	
 	// If object contain data then copy it to
 	if(o_M2.mat != NULL)
 	{
 		for(index = 0; index < i_Row; index++)
 		{
 			for(jindex = 0; jindex < i_Col; jindex++)
 			{
 				mat[index][jindex] = o_M2.mat[index][jindex];
 			}
 		}
 	}
 	
 	return (*this);
}

/***********************************************************************************
	Function			: new()	// operator overload
	Description			: This function allocate the memory dynamically for matrix
	Input				: size_t
	Return				: void*

	@author : Yuvraj Takey
*/

void* Matrix_C:: operator new(size_t i_size)
 {
 	void *newM = NULL;
 	
 	// use malloc here
 	newM = malloc(i_size); 	
 	if(newM == NULL)
 	{
 		cout<<"[SORRY] : failed in dynamic memory allocation"<<endl;
 	}
 	else
 	{
 		cout<<"Allocating memory dynamically for object"<<endl;
 		return newM;
 	}
 }
 
 /***********************************************************************************
	Function			: delete()	// operator overload
	Description			: This function deallocate the memory for matrix
	Input				: void*
	Return				: void

	@author : Yuvraj Takey
*/
void Matrix_C:: operator delete(void *mem)
 {
 	if(mem != NULL)
 	{
 		free(mem);
 		cout<<"Free the dynamic memory"<<endl;
 	}
 }
 
 /*
  *	Destructor
  */
 Matrix_C::~Matrix_C()
 { 	
 	if(mat != NULL)
 	{
 		int index = 0;
 		
 		// iterate till all rows
 		for(index = 0; index < i_Row; index++)
 		{
 			delete mat[index];
 		}
 		
 		if(index != 0)
 		{
 			delete mat;
 			mat = NULL;
 		}
 	}
 }
 /************************************************	Naked Function	******************************************/
/***********************************************************************************
	Function			: +()	// operator overload
	Description			: This function performs addintion of matrix with integral value
	Input				: int, Matrix_C
	Return				: Matrix_C

	@author : Yuvraj Takey
*/
Matrix_C operator +(int i_value, Matrix_C o_M1)
{
	Matrix_C o_Temp;
	
	// check for NULL object
	if((o_M1.mat == NULL) || (i_value == 0))
	{
		cout<<"[SORRY] : invalid operation"<<endl;
		return o_Temp;
	}
	
	int i_index = 0, j_index = 0;
	
	// allocate memory for o_Temp object
	o_Temp.mat = new int*[o_M1.i_Row];
	
	// allocate memory for columns of matrix
	for(i_index = 0; i_index < o_M1.i_Row; i_index++)
	{
		o_Temp.mat[i_index] = new int[o_M1.i_Col];
	}
	
	// assign sizes to o_Temp objct
	o_Temp.i_Row = o_M1.i_Row;
	o_Temp.i_Col = o_M1.i_Col;
	
	// perform addition
	for(i_index = 0; i_index < o_M1.i_Row; i_index++)
	{
		for(j_index = 0; j_index < o_M1.i_Col; j_index++)
		{
			o_Temp.mat[i_index][j_index] = ((i_value) + (o_M1.mat[i_index][j_index]));
		}
	}

	// return local object to callie
	return (o_Temp);
} 

/***********************************************************************************
	Function			: -()	// operator overload
	Description			: This function performs substraction of matrix with integral value
	Input				: int, Matrix_C
	Return				: Matrix_C

	@author : Yuvraj Takey
*/
Matrix_C operator -(int i_value, Matrix_C o_M1)
{
	Matrix_C o_Temp;
	
	// check for NULL object
	if((o_M1.mat == NULL) || (i_value == 0))
	{
		cout<<"[SORRY] : invalid operation"<<endl;
		return o_Temp;
	}
	
	int i_index = 0, j_index = 0;
	
	// allocate memory for o_Temp object
	o_Temp.mat = new int*[o_M1.i_Row];
	
	// allocate memory for columns of matrix
	for(i_index = 0; i_index < o_M1.i_Row; i_index++)
	{
		o_Temp.mat[i_index] = new int[o_M1.i_Col];
	}
	
	// assign sizes to o_Temp objct
	o_Temp.i_Row = o_M1.i_Row;
	o_Temp.i_Col = o_M1.i_Col;
	
	// perform addition
	for(i_index = 0; i_index < o_M1.i_Row; i_index++)
	{
		for(j_index = 0; j_index < o_M1.i_Col; j_index++)
		{
			o_Temp.mat[i_index][j_index] = ((i_value) - (o_M1.mat[i_index][j_index]));
		}
	}

	// return local object to callie
	return (o_Temp);
} 
 
 
 /************************************************	MAIN	*************************************************/
 
 int main()
 { 	
 	int i_size = 0, j_size = 0, i_value = 0;
 	char c_Choice = ' ';
 	
 	// accept the matrix size from user
 	cout<<"Kindly enter the size of matrix"<<endl;
 	cin>>i_size>>j_size;
 	
 	// creation of object
 	Matrix_C o_M1(i_size,j_size), o_M2(o_M1);
 	Matrix_C *op_M4;
 	
 	// dynamic memory allocation
 	// overload new
 	// call is like	=> 100(i_size, j_size)		// where 100 is the new allocated memory on heap
 	op_M4 = new Matrix_C(i_size,j_size);
 	
 	// input 1
 	cout<<"Kindly enter the first matrix element"<<endl;
 	cin>>o_M1;
 	
 	// input 2		
 	cout<<"Kindly enter the second matrix element"<<endl;
 	cin>>o_M2;
 	
 	while(RUNNING)
 	{
 		cout<<"Select your operation"<<endl;
 		cout<<"1.->  M1  + M2"<<"\t\t4.->  M1  - M2"<<endl;
 		cout<<"2.->  M1  + int"<<"\t\t5.->  M1  - int"<<endl;
 		cout<<"3.->  int + M2"<<"\t\t6.->  int - M2"<<endl<<endl;
 		cout<<"7.->  Show\t\t8.->  Exit"<<endl;
 		cin>>c_Choice;
 		
 		switch(c_Choice)
 		{
 			case '1':
 			{
 				// perform addition
 				cout<<"Addition of matrix"<<endl;
 				*op_M4 = o_M1 + o_M2;
 					
 				break;
 			}
 			case '2':
 			{
 				cout<<"Enter any integral value for addition"<<endl;
				cin>>i_value;

				// perform addition
				*op_M4 = o_M1 + i_value;
 	
 				break;
 			}
 			case '3':
 			{
 				cout<<"Enter any integral value for addition"<<endl;
			 	cin>>i_value;
			 	
			 	//perform addition
			 	*op_M4 = i_value + o_M2;
 				
 				break;
 			}
 			case '4':
 			{
 				// perform addition
 				cout<<"Substraction of matrix"<<endl;
 				*op_M4 = o_M1 - o_M2;
 				
 				break;
 			}
 			case '5':
 			{
 				cout<<"Enter any integral value for substraction"<<endl;
				cin>>i_value;

				// perform addition
				*op_M4 = o_M1 - i_value;
 				
 				break;
 			}
 			case '6':
 			{
 				cout<<"Enter any integral value for substraction"<<endl;
			 	cin>>i_value;
			 	
			 	//perform substraction
			 	*op_M4 = i_value - o_M2;
 				
 				break;
 			}
 			case '7':
 			{
 				cout<<*op_M4<<endl;
 				
 				break;
 			}
 			case '8':
 			{
 				c_Choice = '\a';
 				break;
 			}
 			default:
 				cout<<"[SORRY] : invalid input"<<endl;
 				break;
 		}
 		
 		// terminating condition for while
 		if(c_Choice == '\a')
 		{
 			// delete the memory
 			delete op_M4;
 			break;
 		}
 	} 	
 	
 	return 0;
 }
