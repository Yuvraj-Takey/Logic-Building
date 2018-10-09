/*
 * write a program to diaplay the marks sheet of 10th class student
 * use formatted Return operation, while displaying the details
 *
 *	@ DSSD
*/

 #include <iostream>
 using namespace std;
 #include <string.h>
 #include <stdlib.h>
 #include <stdio_ext.h>
 #include <iomanip>
 #define MAXNAME	255
 #define MAXMODULE	5
 #define MSIZE		70
 #define RUNNING	1
 
 // global value
 const char *m_List[MAXMODULE] = {"Mathematics","Science","History","Geography","Language"};
 
 class Marks_Sheet
 {
 	char c_grade;
 	int i_rollno;
 	int i_total;
 	char c_name[MAXNAME];
 	int i_marks[MAXMODULE];
 	
 	
 	public:
 	Marks_Sheet();
 	void writeD(ofstream&);
 	void readD(ifstream&);
 	
 	friend istream& operator >>(istream&, Marks_Sheet&);
 	friend void generate_result(Marks_Sheet[],int);
 	friend void form_MSheet(Marks_Sheet[],int,int);
 	friend void print_Sheet(Marks_Sheet);
 };
 
// default constructor
 Marks_Sheet::Marks_Sheet()
 {
 	// assign default value to class data member
 	c_grade = ' ';
 	i_rollno = 0;
 	i_total = 0;
 	memset(c_name,0,MAXNAME);
 	memset(i_marks,0,MAXMODULE);
 }

 
 /****************************************	Naked Function	*****************************************************/
 
 // >> operator overload
 istream& operator >>(istream& m_cin, Marks_Sheet& o_DS)
 {
 	// flush the memory
 	__fpurge(stdin);
 	
 	// accept name
 	cout<<"Kindly enter your name\t\t";
 	m_cin.get(o_DS.c_name,MAXNAME);
	 	
 	// accept roll number
 	cout<<"Kindly enter roll number\t";
 	m_cin>>o_DS.i_rollno;
	 	
 	// accept marks one by one
 	cout<<endl<<"Kindly enter marks of Subjects"<<endl;
 	for(int indexj = 0; indexj < MAXMODULE; indexj++)
 	{
 		cout<<"Enter the marks of "<<m_List[indexj]<<"\t";
 		cin>>o_DS.i_marks[indexj];
 	}
 	
 	cout<<endl;
 	
 	return m_cin;
 }
 
 
 /***********************************************************************************
	Function			: generate_result()
	Description			: This function calculates marks of the students
	Input				: Marks_Sheet[], int
	Return				: nothing

	@author : Yuvraj Takey
*/
 void generate_result(Marks_Sheet o_DS[], int i_stud)
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
 
 /***********************************************************************************
	Function			: print_Sheet()
	Description			: This function generates the marksheet of given student
	Input				: Marks_Sheet
	Return				: nothing

	@author : Yuvraj Takey
*/
 void print_Sheet(Marks_Sheet o_DS)
 {
	int i_calc = 0;
	char c_Roll[10] = {"\0"};

 	cout << setfill('*') << setw(MSIZE) << '*'<<endl;

	i_calc = strlen("Telangana State Board of");	
	cout << setfill(' ') << setw((MSIZE-i_calc)/2) <<' ';
	cout<<"Telangana State Board of"<<endl;

	i_calc = strlen("Secondary and Higher Secondary Education, Hyderabad");
	cout << setfill(' ') << setw((MSIZE-i_calc)/2) <<' ';
	cout<<"Secondary and Higher Secondary Education, Hyderabad"<<endl<<endl;

	i_calc = strlen("Secondary School Certificate");
	cout << setfill(' ') << setw((MSIZE-i_calc)/2) <<' ';
	cout << "Secondary School Certificate" <<endl;
	
	i_calc = strlen("This is to certify that");
	cout << setfill(' ') << setw((MSIZE-i_calc)/2) <<' ';
	cout << "This is to certify that" <<endl;

	i_calc = strlen(o_DS.c_name) + 6;
	cout << setfill(' ') << setw((MSIZE-i_calc)/2) <<' ';
	cout << "~~~"<<o_DS.c_name<<"~~~" <<endl<<endl;
	
	// other details

	cout << setfill('_') << setw(MSIZE) << '_'<<endl;
	cout << "\tDivision";
	cout << setfill(' ') << setw(MSIZE/14) <<'|';
	cout << "\tSeat__No";
	cout << setfill(' ') << setw(MSIZE/14) <<'|';
	cout << "\tCenter__No";
	cout << setfill(' ') << setw(MSIZE/14) <<'|';
	cout << "\tYear\t ";
	cout << setfill(' ') << setw(MSIZE/14) <<'|'<<endl;
	cout << "\tHYD";
	cout << setfill(' ') << setw((MSIZE/14)+5) <<'|';

	sprintf(c_Roll,"%s%d","HO0257",o_DS.i_rollno);
	cout << "\t"<<c_Roll;
	cout << setfill(' ') << setw(MSIZE/14) <<'|';
	cout << "\t0257";
	cout << setfill(' ') << setw((MSIZE/14)+6) <<'|';
	cout << "\t2018\t ";
	cout << setfill(' ') << setw(MSIZE/14) <<'|'<<endl;	
	cout << setfill('_') << setw(MSIZE) << '_'<<endl<<endl;


	// Marks

	cout << "\t\tSubject";
	cout << setfill(' ') << setw(MSIZE/3) <<'|';
	cout<< "\tMarks\t";	
	cout << setfill(' ') << setw(MSIZE/24) <<'|';
	cout<< "\tMax ";	
	cout << setfill(' ') << setw(MSIZE/24) <<'|'<<endl;

	cout << setfill('_') << setw(MSIZE) << '_'<<endl<<endl;

	for(int index = 0; index < MAXMODULE; index++)
	{
		i_calc = strlen(m_List[index]);
		cout << m_List[index];
		cout << setfill(' ') << setw((46-i_calc)) <<'|';
		cout<< o_DS.i_marks[index] <<"\t";	
		cout << setfill(' ') << setw(MSIZE/24) <<'|';
		cout<<100<<"\t";	
		cout << setfill(' ') << setw(MSIZE/11) <<'|'<<endl;
	}

	cout << setfill('_') << setw(MSIZE) <<'_'<<endl;

	cout<< setfill(' ') << setw(40) <<"Total:\t\t"<<o_DS.i_total<<endl;	

	cout<< setfill(' ') << setw(40) <<"Grade:\t\t"<<o_DS.c_grade<<endl;	

	cout << setfill('_') << setw(MSIZE) <<'_'<<endl<<endl;

	cout<< setfill(' ') << setw(10) << "Place \t- Hyderabad"<<endl;
	cout<< setfill(' ') << setw(10) << "Date \t- 08-oct-2018";
	cout<<setfill(' ') << setw(45) <<"Divisional Secretary" <<endl<<endl;	
	
	// END

 	cout << setfill('*') << setw(MSIZE) << '*'<<endl;
 
	return ;
 }
 
  /***********************************************************************************
	Function			: form_MSheet()
	Description			: This function searches record for given roll number
	Input				: Marks_Sheet[], int, int
	Return				: nothing

	@author : Yuvraj Takey
*/
 void form_MSheet(Marks_Sheet o_DS[], int i_roll, int i_size)
 {
 	int index = 0;
 	
 	// iterate the student data
 	for(index = 0; index < i_size; index++)
 	{
 		// check for roll number untill it not find
 		if(o_DS[index].i_rollno == i_roll)
 		{
 			break;
 		}
 	}
 	
 	// if record matches
 	if(index != i_size)
 	{
		// generate the marksheet of that perticular student
		print_Sheet(o_DS[index]);
 	}
 	else
 	{
 		cout<<"[SORRY] : There is no record found"<<endl;
 	}
 }
 
 
 /**************************************************************	MAIN	************************************************/
 
 int main()
 {
 	int i_size = 0, index = 0;
	char c_Choice = ' ';
 	
 	cout<<"Kindly enter the number of students"<<endl;
 	cin>>i_size;
 	
 	// create the object of 'n element'
 	Marks_Sheet o_DS[i_size];
 	
	// accept the input
 	for(index = 0; index < i_size; index++)
 	{
 		cout<<"Enter the details for student "<<(index+1)<<endl;
 		cin>>o_DS[index]; 		
 	}
 
 	// calling to gererate result
 	generate_result(o_DS, i_size);

	while(RUNNING)
	{
		// clear the console 
	 	system("clear");
	 	
	 	cout<<"Kindly enter the Roll Number of student"<<endl;
	 	cin >> index;
	 	
	 	// generate marksheet
	 	form_MSheet(o_DS, index, i_size);
	
		cout<<"Do you want to continue..(y/n)"<<endl;
		cin>>c_Choice;

		if((c_Choice == 'y') || (c_Choice == 'Y'))
		{
			continue;
		}
		else
		{
			break;
		}
		
	}
 	return 0;
 }
