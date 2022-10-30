/*
Develop an object oriented program in C++ to create a database of student information system containing the following information: 
Name, Roll number, Class, division, Date of Birth, Blood group, Contact address, telephone number, driving license no. and other. 
Construct the database with suitable member functions for initializing and destroying the data viz constructor, default constructor, Copy constructor, destructor, 
static member functions, friend class, this pointer, inline code and dynamic memory allocation operators-new and delete as well as exception handling

friend class, this pointer 

*/

#include<iostream>
#include<string.h>   //for handling string eg.strcpy()
using namespace std;
class person
{
private:
  char *name,*blood,*address; //declared data variable
  int dob;
  long long int phone,license;
  static int count;        //static variables
public:
 person() //default & dynamic constructor
{
 count++;
 cout<<"-----------------Default Information------------";
 name=new char[13]; //allocate dynamic memory using new operator
 strcpy(name,"Akhilesh");
 blood=new char[5];
 strcpy(blood,"B+ve");
 address=new char[20];
 strcpy(address,"Pune");
 phone=9911991111;
 license=123;
 dob=13012004;
 display();
}
 person(char n[],char b[],int yy,char add[],long int p,long int ln)  //parameterized constructor
{
  count++;
  int len;
 len=strlen(n);
 name=new char[len+1];
 strcpy(name,n);

 len=strlen(b);
 blood=new char[len+1];
 strcpy(blood,b);

 len=strlen(add);
 address=new char[len+1];
 strcpy(address,add);
 dob=yy;
 phone=p;
   license=ln;
}
  void display();     //display function declaration
  
 
inline static int displaycount()  //inline static member function
{
 cout<<"\n NUMBER OF ENTRIES ARE: "<<count<<endl;
}

 ~person()         //destructor having same name like construct
{
 cout<<"\n Destructor Called...";
}
};
 
  int person::count=0;
         void person::display()  //display function definition
{
 cout<<endl<<"\n NAME: "<<name;
 cout<<"\n BLOOD GROUP: "<<blood;
 cout<<"\n DATE OF BIRTH: "<<dob;
 cout<<"\n CONTACT ADDRESS: "<<address;
 cout<<"\n PHONE NUMBER: "<<phone;
 cout<<"\n LICENSE NUMBER: "<<license<<endl;
 }

int main()//initializing main function
{
  int ch; //variable declaration
 person *p[20],*temp;
 
  char pname[15],pblood[5],paddress[20];
  long int pphone,plicense;
  int cnt=0,dd;
 do
{
 cout<<"\n --------MENU--------"<<endl;
 cout<<"\n 1.DEFAULT CONSTRUCTOR ";
 cout<<"\n 2.ADD ENTRY "; 
 cout<<"\n 3.NUMBER OF ENTRIES ";
 cout<<"\n 4.DISPLAY ";
 cout<<"\n 5.EXIT ";
 cout<<"\n ENTER THE CHOICE: ";
 cin>>ch;
 switch(ch)
{
 case 1:  //DEFAULT CONSTRUCTER INFORMATION
 p[cnt]=new person();
 
 cnt=cnt+1;
 break;
 case 2:  //PARAMETERIZED CONSTRUCTOR INFORMATION
 cout<<"\n ENTER THE NAME OF STUDENT :";
 cin>>pname;
 cout<<"\n ENTER THE BLOOD GROUP OF STUDENT :";
 cin>>pblood;
 cout<<"\n ENTER DATE OF BIRTH :";
 cin>>dd;
 cout<<"\n ENTER THE CONTACT ADDRESS:";
 cin>>paddress;
 cout<<"\n ENTER THE PHONE NUMBER:";
 cin>>pphone;
 cout<<"\n ENTER THE LICENSE NUMBER:";
 cin>>plicense;
 p[cnt]=new person(pname,pblood,dd,paddress,pphone,plicense);
 
 
 cnt=cnt+1;
 break;

 case 3:  //NUMBER OF ENTRIES INFORMATION
 person::displaycount();
 break;
 
    
 
 case 4: 
 for(int i=0;i<cnt;i++)
{
 p[i]->display();
 }
 break; 
 case 5: 
          return 0;
}
} while(ch!=5);
}

/*
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
*/

