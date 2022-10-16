/*
Develop an object oriented program in C++ to create a database of student information system containing the following information: 
Name, Roll number, Class, division, Date of Birth, Blood group, Contact address, telephone number, driving license no. and other. 
Construct the database with suitable member functions for initializing and destroying the data viz constructor, default constructor, Copy constructor, destructor, 
static member functions, friend class, this pointer, inline code and dynamic memory allocation operators-new and delete as well as exception handling
*/

//Name, Class,Roll number,  Date of Birth, Blood group,  string
//division char

//driving license no., Contact address, telephone number string MH-09-2008-0003369 
#include<iostream>
using namespace std;
string name,clas,roll,dob,bg;
class ot;
class basic
{
	public:
		basic()
		{
			name="Akhilesh";
			clas="SE COMP 1";
			roll="F21111006";
			dob="13/01/2004";
			bg="B+ve";
		}
	void input(ot*);
	void show(ot*);
	friend class ot;
};
string dl,ca,tn;
class ot
{
	public:
	ot()
	{
		dl="MH-14-2022-0003369";
		ca="Chinchwad , Pune";
		tn="+91 123456789";
	}
	void input1()
	{
		cout<<"Enter your Driving License No. :"<<endl;
		getline(cin,dl);
		cout<<"Enter your Contact Address :"<<endl;
		getline(cin,ca);
		cout<<"Enter your Telephone No. :"<<endl;
		getline(cin,tn);
	}
	void show1()
	{
		cout<<"Driving License No. : "<<dl<<endl;
		cout<<"Contact Address : "<<ca<<endl;
		cout<<"Telephone No. : "<<tn<<endl;
	}
			
};

inline void basic::input(ot *st)
{
	cin.ignore();
	cout<<"Enter your name :"<<endl;
	getline(cin,name);
	cout<<"Enter your class :"<<endl;
	getline(cin,clas);
	cout<<"Enter your Roll No :"<<endl;
	getline(cin,roll);
	cout<<"Enter your Date of Birth :"<<endl;
	getline(cin,dob);
	cout<<"Enter your Blood Group :"<<endl;
	getline(cin,bg);
	st->input1();
}
inline void basic::show(ot *st)
{
	cout<<"Name : "<<name<<endl;
	cout<<"Class : "<<clas<<endl;
	cout<<"Roll No. : "<<roll<<endl;
	cout<<"Date of Birth : "<<dob<<endl;
	cout<<"Blood Group : "<<bg<<endl;
}
int main()
{
	int n=0;
	/*cout<<"Enter how many records to enter"<<endl;
	cin>>n;
	basic p1[n];*/
	stud1[n]=new basic;
    stud2[n]=new ot;
	basic obj;
	ot obj1;
	
	while(true)
	{
		int x;
		cout<<"Enter choice 1. Display Data 2. Enter Data 3. Exit"<<endl;
		cin>>x;
		
		switch(x)
		{
			case 1:{
				/*obj.show();
				obj1.show1();*/
				for(int i=0;i<n;i++)
   				{
        			cout<<"---------------------------------------------------------------"<<endl;
        			stud1[i]->show(stud2[i]);
			    }
				break;
			}
			case 2:{
				//obj.input();
				//p1[x].input(name,clas,roll,dob,bg);
				//obj1.input1();
				/*p1[x].input(dl,ca,tn);
				x++;*/
        		stud1[n]->input(stud2[n]);
        		n++;
				break;
			}
			case 3:
				break;
			default:
				cout<<"Invalid"<<endl;	
		}
	}
	return 0;
}


