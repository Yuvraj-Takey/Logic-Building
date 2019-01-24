/*
 * Define a complex class with default, parameterised and copy constructor also aoverload the following operator
 *	(+)(-)(++)(--)(unary-)(=)(,)(->)(>>)(<<)
 *
 *	@ DSSD
 */
 
 #include <iostream>
 using namespace std;
 #define RUNNING	1
 
 class Complex_C
 {
 	static short s_obj;
 	short index;
 	int i_real;
 	int i_img;
 	
 	public:
 	Complex_C();
 	Complex_C(int, int);
 	Complex_C(const Complex_C&);
 	Complex_C operator+(Complex_C);
 	Complex_C operator-(Complex_C);
 	Complex_C operator=(Complex_C);
 	Complex_C operator++();
 	Complex_C operator--();
 	Complex_C operator++(int);
 	Complex_C operator--(int);
 	Complex_C operator-();
 	Complex_C operator,(Complex_C);
 	Complex_C* operator->();
 	~Complex_C();
 	
 	friend ostream& operator <<(ostream&,Complex_C&);
 	friend istream& operator >>(istream&,Complex_C&);	
 };
 
 short Complex_C::s_obj = 0;
 
 // Default const
 Complex_C::Complex_C()
 {
 	i_real = i_img = 0;
 	
 	//current object
 	s_obj++;
 	index = s_obj;
 }
 
 // parameterised const
 Complex_C::Complex_C(int real, int img)
 {
 	i_real = real;
 	i_img = img;
 	
 	//current object
 	s_obj++;
 	index = s_obj;
 }
 
 // copy const
 Complex_C::Complex_C(const Complex_C &o_CP)
 {
 	// perform copy
 	this->i_real = o_CP.i_real;
 	this->i_img = o_CP.i_img;
 	
 	// current object
 	s_obj++;
 	index = s_obj;
 }
 
 
 /***********************************************************************************
	Function			: =()
	Description			: This function perform assignment operations
	Input				: Complex_C
	Return				: Complex_C

	@author : Yuvraj Takey
*/
 Complex_C Complex_C::operator =(Complex_C o_CP)
 {
 	// perform assignment
 	i_real = o_CP.i_real;
 	i_img = o_CP.i_img;
 	
 	// return the same pointer
 	return (*this);
 }
 
 /***********************************************************************************
	Function			: +()
	Description			: This function performs addition of 2 Complex class
	Input				: Complex_C
	Return				: Complex_C

	@author : Yuvraj Takey
*/
 Complex_C Complex_C::operator +(Complex_C o_CP)
 {
 	Complex_C o_Temp;
 	
 	// perform addition
 	o_Temp.i_real = i_real + o_CP.i_real;
 	o_Temp.i_img = i_img + o_CP.i_img;
 	
 	// return result
 	return o_Temp;
 }
 
 /***********************************************************************************
	Function			: -()
	Description			: This function performs substraction of 2 complex class
	Input				: Complex_C
	Return				: Complex_C

	@author : Yuvraj Takey
*/
 Complex_C Complex_C::operator -(Complex_C o_CP)
 {
 	Complex_C o_Temp;
 	
 	// perform addition
 	o_Temp.i_real = i_real - o_CP.i_real;
 	o_Temp.i_img = i_img - o_CP.i_img;
 	
 	// return result
 	return o_Temp;
 }
 
 /***********************************************************************************
	Function			: ++()
	Description			: This function perform pre-incrementation operation
	Input				: Nothing
	Return				: Complex_C

	@author : Yuvraj Takey
*/
 Complex_C Complex_C::operator ++()
{
	//pre-increment
	++i_real;
	++i_img;
	
	return (*this);
} 
 
 /***********************************************************************************
	Function			: --()
	Description			: This function perform pre-decrementation operation
	Input				: NOthing
	Return				: Complex_C

	@author : Yuvraj Takey
*/
 Complex_C Complex_C::operator --()
 {
 	//pre-decrement
	--i_real;
	--i_img;
	
	return (*this);
 }
 /***********************************************************************************
	Function			: ++()
	Description			: This function perform post-incrementation operation
	Input				: int
	Return				: Complex_C

	@author : Yuvraj Takey
*/
 Complex_C Complex_C::operator ++(int x_Dummy)
{
	Complex_C o_Temp;
	
	//post-increment
	o_Temp.i_real = i_real++;
	o_Temp.i_img = i_img++;
	
	return (o_Temp);
} 
 
 /***********************************************************************************
	Function			: --()
	Description			: This function perform post-decrementation operation
	Input				: int
	Return				: Complex_C

	@author : Yuvraj Takey
*/
 Complex_C Complex_C::operator --(int x_Dummy)
 {
	Complex_C o_Temp;
	
	//post-decrement
	o_Temp.i_real = i_real++;
	o_Temp.i_img = i_img++;
	
	return (o_Temp);
 }
 /***********************************************************************************
	Function			: -()
	Description			: This function prform operation as uniary (-)
	Input				: Nothing
	Return				: Complex_C

	@author : Yuvraj Takey
*/
 Complex_C Complex_C::operator -()
 {
 	Complex_C o_Temp;
 	
 	o_Temp.i_real = -i_real;
 	o_Temp.i_img = -i_img;
 	
 	return (o_Temp);
 }
 
 /***********************************************************************************
	Function			: ,()
	Description			: This function overload comma operator
	Input				: Complex_C
	Return				: Complex_C

	@author : Yuvraj Takey
*/
 Complex_C Complex_C::operator ,(Complex_C o_CP)
 {
 	Complex_C o_Temp;
 	
 	// assign value
 	o_Temp.i_real = o_CP.i_real;
 	o_Temp.i_img = o_CP.i_img;
 	
 	cout<<"hi"<<endl;
 	return (o_Temp);
 }
 
  /***********************************************************************************
	Function			: ->()
	Description			: This function prform operation with (->)
	Input				: Nothing
	Return				: Complex_C*

	@author : Yuvraj Takey
*/
 Complex_C* Complex_C::operator ->()
 {
 	return (this);
 }
 
 // Destruc
 Complex_C::~Complex_C()
 {
 	--s_obj;
 	index = s_obj;
 }
 
 /*************************************************	Naked	**************************************************/
 // operator << overload
 ostream& operator <<(ostream &m_cout, Complex_C &o_CP)
 {
 	cout<<o_CP->index<<" Complex element is:"<<endl;
 	cout<<o_CP->i_real<<" "<<o_CP->i_img<<"i"<<endl;
 	
 	return (m_cout);
 }
 
 // operator >> overload
 istream& operator >>(istream &m_cin, Complex_C &o_CP)
 {
 	cin>>o_CP->i_real>>o_CP->i_img;
 	
 	return (m_cin);
 }
 /*************************************************	MAIN	**************************************************/
 int main()
 {
 	char c_Choice = ' ';
 	Complex_C o_CP, o_CP2(6,5), o_CP3;

	// accept input from user
	cout<<"kindly enter the first complex element: "<<endl;
	cin>>o_CP;
	cout<<o_CP;
	cout<<"kindly enter the second complex element: "<<endl;
	cin>>o_CP2;
	cout<<o_CP2;
	

	// menu driven
 	while(RUNNING)
 	{
 		// menu
 		cout<<endl<<"Kindly select your operation"<<endl;
 		cout<<"1. (+)\t\t2. (-)\t\t3. unary(-)"<<endl;
 		cout<<"4. (--)Pre\t5. (--)Post\t6.obj3 = (obj1,obj2)"<<endl;
 		cout<<"7. (++)Pre\t8. (++)Post"<<endl;
 		cout<<"9. show\t\t0. exit"<<endl;
 		cin>>c_Choice;
 		
 		switch(c_Choice)
 		{
 			case '1':
 			{
 				o_CP3 = o_CP + o_CP2;
 				break;
 			}
 			case '2':
 			{
 				o_CP3 = o_CP - o_CP2;
 				break;
 			}
 			case '3':
 			{
 				o_CP3 = -o_CP;
 				break;
 			}
 			case '4':
 			{
 				o_CP3 = --o_CP;
 				break;
 			}
 			case '5':
 			{
 				o_CP3 = o_CP--;
 				break;
 			}
 			case '6':
 			{
 				o_CP3 = (o_CP, o_CP2);
 				break;
 			}
 			case '7':
 			{
 				o_CP3 = ++o_CP;
 				break;
 			}
 			case '8':
 			{
 				o_CP3 = o_CP++;
 				break;
 			}
 			case '9':
 			{
 				cout<<o_CP3;
 				
 				break;
 			}
 			case '0':
 			{
 				c_Choice = '\a';
 				break;
 			}
 		}
 		
 		// termination condition for while
 		if(c_Choice == '\a')
 		{
 			break;
 		}
 	} 	
 	
 	return 0;
 }
 
 
