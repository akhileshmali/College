/*
Develop an object oriented program in C++ to create a database of student information system containing the following information: 
Name, Roll number, Class, division, Date of Birth, Blood group, Contact address, telephone number, driving license no. and other. 
Construct the database with suitable member functions for initializing and destroying the data viz constructor, default constructor, Copy constructor, destructor, 
static member functions, friend class, this pointer, inline code and dynamic memory allocation operators-new and delete as well as exception handling


*/

#include<iostream>
#include<string.h>   //for handling string eg.strcpy()
using namespace std;
class info;
class person
{
private:
  char *name,*blood,*address; //declared data variable
  
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
 display();
}
 person(char n[],char b[],char add[])  //parameterized constructor
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
friend class info;
};
class info
{
private: 	
 int dob;
  long long int phone,license;
public:	
	info()
	{
		phone=9911991111;
 		license=123;
 		dob=13012004;
 		display1();
	}
	info(int dob,long int p,long int ln)  //parameterized constructor
{
   this->dob=dob;
 phone=p;
 license=ln;
}
void display1();
 }; 
  int person::count=0;
         void person::display()  //display function definition
{
 cout<<endl<<"\n NAME: "<<name;
 cout<<"\n BLOOD GROUP: "<<blood;
 cout<<"\n CONTACT ADDRESS: "<<address;
 }

void info::display1()  //display function definition
{
 cout<<"\n DATE OF BIRTH: "<<dob;
 cout<<"\n PHONE NUMBER: "<<phone;
 cout<<"\n LICENSE NUMBER: "<<license<<endl;
 }

int main()//initializing main function
{
  int ch; //variable declaration
 person *p[20],*temp;
 info *p1[20],*temp1;
 
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
 p1[cnt]=new info();
 cnt=cnt+1;
 break;
 case 2:  //PARAMETERIZED CONSTRUCTOR INFORMATION
 cout<<"\n ENTER THE NAME OF STUDENT :";
 cin>>pname;
 cout<<"\n ENTER THE BLOOD GROUP OF STUDENT :";
 cin>>pblood;
 cout<<"\n ENTER DATE OF BIRTH :";
 cin>>dd;
 /*do
 {
 	cout<<"\n ENTER DATE OF BIRTH :";
 cin>>dd;
 try
 {
 	if(sizeof(dd)>32)
 	{
 		cout<<" Enter valid date"<<endl;
 		throw "Error";
	 }
	 else
	 {
	 	break;
	 }
 }
 catch(...)
 {
 	cout<<"Enter valid date in DDMMYYYY format"<<endl;
 }
 	
 }while(true);*/
 cout<<"\n ENTER THE CONTACT ADDRESS:";
 cin>>paddress;
 cout<<"\n ENTER THE PHONE NUMBER:";
 cin>>pphone;
 cout<<"\n ENTER THE LICENSE NUMBER:";
 cin>>plicense;
 p[cnt]=new person(pname,pblood,paddress);
 p1[cnt]=new info(dd,pphone,plicense);
 
 
 cnt=cnt+1;
 break;

 case 3:  //NUMBER OF ENTRIES INFORMATION
 person::displaycount();
 break;
 
    
 
 case 4: 
 for(int i=0;i<cnt;i++)
{
 p[i]->display();
 p1[i]->display1();
 }
 
 break; 
 case 5: 
          return 0;
}
} while(ch!=5);
}


