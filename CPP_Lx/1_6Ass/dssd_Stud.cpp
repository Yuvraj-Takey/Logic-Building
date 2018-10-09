/*
 * Generate DSSD_STUDENT marksheet. use << and >> for overload and also accept the input in array of object.
 * provide the file storage functionality to user
 *
 *	@ DSSD
 */
 
 #include <iostream>
 using namespace std;
 #include <string.h>
 #include <stdio_ext.h>
 #include <fstream>
 #define MAXNAME	255
 #define MAXMODULE	5
 
 // global value
 const char *m_List[MAXMODULE] = {"C","C++","Data Structure","Linux Programming","Windows Programming"};
 
 class DSSD_STUDENT
 {
 	char c_grade;
 	int i_rollno;
 	int i_total;
 	char c_name[MAXNAME];
 	int i_marks[MAXMODULE];
 	char fname[MAXNAME];
 	
 	public:
 	DSSD_STUDENT();
 	DSSD_STUDENT(char*);
 	void writeD(ofstream&);
 	void readD(ifstream&);
 	
 	friend istream& operator >>(istream&, DSSD_STUDENT&);
 	friend ostream& operator <<(ostream&, DSSD_STUDENT);
 	friend void generate_result(DSSD_STUDENT[],int);
 };
 
// default constructor
 DSSD_STUDENT::DSSD_STUDENT()
 {
 	// assign default value to class data member
 	c_grade = ' ';
 	i_rollno = 0;
 	i_total = 0;
 	memset(c_name,0,MAXNAME);
 	memset(i_marks,0,MAXMODULE);
 	
 	memset(this->fname,0,MAXNAME);
 }

 // parameterised constructor
 DSSD_STUDENT::DSSD_STUDENT(char * fname)
 {
 	// assign default value to class data member
 	c_grade = ' ';
 	i_rollno = 0;
 	i_total = 0;
 	memset(c_name,0,MAXNAME);
 	memset(i_marks,0,MAXMODULE);
 	
 	memcpy(this->fname,fname,strlen(fname));
 }
 
 /***********************************************************************************
	Function			: writeD()
	Description			: This function writes the data into file
	Input				: ofstream&
	Return				: nothing

	@author : Yuvraj Takey
*/
 void DSSD_STUDENT::writeD(ofstream& of)
 {
 	// write data into file stream
 	of.write((char*) this, sizeof(DSSD_STUDENT));
 }
 
 /***********************************************************************************
	Function			: readD()
	Description			: This function reads the data from file
	Input				: ifstream&
	Return				: nothing

	@author : Yuvraj Takey
*/
 void DSSD_STUDENT::readD(ifstream& ifs)
 {
 	DSSD_STUDENT o_Temp;
 	
 	// read data from file stream
 	ifs.read((char*) &(o_Temp), sizeof(DSSD_STUDENT));
 	cout<<o_Temp;
 }
 
 /****************************************	Naked Function	*****************************************************/
 
 // >> operator overload
 istream& operator >>(istream& m_cin, DSSD_STUDENT& o_DS)
 {
 	// flush the memory
 	__fpurge(stdin);
 	
 	// accept name
 	cout<<"Kindly enter your name"<<endl;
 	m_cin.get(o_DS.c_name,MAXNAME);
	 	
 	// accept roll number
 	cout<<"Kindly enter your roll number"<<endl;
 	m_cin>>o_DS.i_rollno;
	 	
 	// accept marks one by one
 	cout<<"Kindly enter marks for your module"<<endl;
 	for(int indexj = 0; indexj < MAXMODULE; indexj++)
 	{
 		cout<<"Enter the marks of "<<m_List[indexj]<<endl;
 		cin>>o_DS.i_marks[indexj];
 	}
 	
 	return m_cin;
 }
 
 // << operator overload
 ostream& operator <<(ostream& m_cout, DSSD_STUDENT o_DS)
 {
 	m_cout<<endl<<"Name\t\t: "<<o_DS.c_name<<endl;
 	m_cout<<"Roll Num\t: "<<o_DS.i_rollno<<endl;
 	m_cout<<"Marks\t\t: "<<o_DS.i_total<<endl;
 	m_cout<<"Grade\t\t: "<<o_DS.c_grade<<endl<<endl;
 	
 	return m_cout;
 }
 
 /***********************************************************************************
	Function			: generate_result()
	Description			: This function calculates marks of the students
	Input				: DSSD_STUDENT[], int
	Return				: nothing

	@author : Yuvraj Takey
*/
 void generate_result(DSSD_STUDENT o_DS[], int i_stud)
 {
 	int index = 0;
 	float i_Cal = 0, i_perc = 0;
 	
 	for(index = 0; index < i_stud; index++)
 	{
 		// vanish the memory
 		i_Cal = i_perc = 0.0f;
 	
 		// iterate till all marks
		for(int indexj = 0; indexj < MAXMODULE; indexj++)
		{
			// calculate marks
			 i_Cal = i_Cal + o_DS[index].i_marks[indexj];
		}  
	
		// allocate the marks in object
		o_DS[index].i_total = i_Cal;
	
		// calculate percentage
		i_perc = (i_Cal/(MAXMODULE*100))*100;
	
		// checks for grades
		if((i_perc >= 75) && (i_perc <= 100))
		{
			o_DS[index].c_grade = 'O';
		}
		else if((i_perc >= 60) && (i_perc < 75))
		{
			o_DS[index].c_grade = 'A';
		}
		else if((i_perc >= 45) && (i_perc < 60))
		{
			o_DS[index].c_grade = 'B';
		}
		else if((i_perc >= 35) && (i_perc < 45))
		{
			o_DS[index].c_grade = 'C';
		}
		else if(i_perc < 35)
		{
			o_DS[index].c_grade = 'D';
		}
		else
		{
			o_DS[index].c_grade = '-';
		}
	}
 }
 
 int main()
 {
 	int i_size = 0, index = 0;
 	char c_fname[MAXNAME] = {"Data"};
 	
 	// create file streams
 	ofstream of(c_fname);
 	
 	cout<<"Kindly enter the number of students"<<endl;
 	cin>>i_size;
 	
 	// create the object of 'n element'
 	DSSD_STUDENT o_DS[i_size]("Data"), o_DSR;
 	
 	// accept the input
 	for(index = 0; index < i_size; index++)
 	{
 		cout<<"Enter the details for student "<<(index+1)<<endl;
 		cin>>o_DS[index]; 		
 	}
 
 	// calling to gererate result
 	generate_result(o_DS, i_size);
 	
 	// writing into file
 	for(index = 0; index < i_size; index++)
 	{
 		o_DS[index].writeD(of);
 	}
 
 	// close file out-stream
 	of.close();
 	
 	// open file in in-stream
 	ifstream ifs(c_fname);
 	
 	// printing result from file
 	for(index = 0; index < i_size; index++)
 	{
 		o_DS[index].readD(ifs);
 	}
 	
 	// close the stream
 	ifs.close();
 	
 	return 0;
 }
