/*
Develop an object oriented program in C++ to create a database of student information system containing the following information: 
Name, Roll number, Class, division, Date of Birth, Blood group, Contact address, telephone number, driving license no. and other. 
Construct the database with suitable member functions for initializing and destroying the data viz constructor, default constructor, Copy constructor, destructor, 
static member functions, friend class, this pointer, inline code and dynamic memory allocation operators-new and delete as well as exception handling

 Roll number, Class, division, 
*/

#include<iostream>
#include<string.h>   
using namespace std;
class info;
class person
{
private:
  char *name,*blood,*address; 
  static int count;        
public:
 person() 
{
 count++;
 cout<<"-----------------Default Information------------";
 name=new char[13]; 
 strcpy(name,"Akhilesh");
 blood=new char[5];
 strcpy(blood,"B+ve");
 address=new char[20];
 strcpy(address,"Pune");
 display();
}
 person(char n[],char b[],char add[])  
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
void display();     
  
 
inline static int displaycount()  
{
 cout<<"\n NUMBER OF ENTRIES ARE: "<<count<<endl;
}

 ~person()        
{
 cout<<"\n Destructor Called...";
}
friend class info;
};
class info
{
public: 	
 string roll, cla, div, dob,phone,license;
public:	
	info()
	{
		roll="06";
		cla="SE ";
		div="COMP1";
		phone="9911991111";
 		license="MH/123/456";
 		dob="13/01/2004";
 		display1();
	}
	info(string roll,string cla,string div,string dob,string phone,string license)  
{
 this->roll=roll;
 this->cla=cla;
 this->div=div;	
 this->dob=dob;
 this->phone=phone;
 this->license=license;
}
	~info()        
{
 cout<<"\n Destructor Called...";
}
void display1();
int sea(srch);
 }; 
  int person::count=0;
         void person::display()  
{
 cout<<endl<<"\n NAME: "<<name;
 cout<<"\n BLOOD GROUP: "<<blood;
 cout<<"\n CONTACT ADDRESS: "<<address;
 }

void info::display1()  
{
 cout<<"\n ROLL NO. : "<<roll;
 cout<<"\n CLASS: "<<cla;
 cout<<"\n DIVISION : "<<div;
 cout<<"\n DATE OF BIRTH: "<<dob;
 cout<<"\n PHONE NUMBER: "<<phone;
 cout<<"\n LICENSE NUMBER: "<<license<<endl;
 }

/*int info::search_stu(int roll, info *p1[]) {
    for (int i = 0; i < person::displaycount(); i++) {
        if (p1[i]->proll == roll) {
            return i;
        }
    }*/
	int info::sea(srch)
	{
	for (int i = 0; i < person::displaycount(); i++)
	 {
        if (p1[i]->roll == srch)
		 {
            return i;
        }
     }	
	}
int main()
{
  int ar,ch,ent; 
 person *p[20],*temp;
 info *p1[20],*temp1;
 
  char pname[15],pblood[5],paddress[20];
  string proll,pcla,pdiv,pphone,plicense,dd;
  int cnt=0;
 do
{
 cout<<"\n --------MENU--------"<<endl;
 cout<<"\n 1.DEFAULT CONSTRUCTOR ";
 cout<<"\n 2.ADD ENTRY "; 
 cout<<"\n 3.NUMBER OF ENTRIES ";
 cout<<"\n 4.DISPLAY ";
 cout<<"\n 5.DELETE ENTRY ";
 cout<<"\n 6.COPY CONSTRUCTOR ";
 cout<<"\n 7. EXIT";
 cout<<"\n ENTER THE CHOICE: ";
 cin>>ch;
 switch(ch)
{
 case 1:  
	 p[cnt]=new person();
	 p1[cnt]=new info();
	 cnt=cnt+1;
	 break;
 case 2:  
     cout<<"\n ENTER THE NAME OF STUDENT :";
     cin>>pname;
	 cout<<"\n ENTER THE BLOOD GROUP OF STUDENT :";
	 cin>>pblood;
	 cout<<"\n ENTER THE ROLL NO. :";
	cin>>proll;
	cout<<"\n ENTER THE CLASS :";
	cin>>pcla;
	cout<<"\n ENTER THE DIVISION :";
	cin>>pdiv;
	 try
	 {
	   	cout<<"\n ENTER DATE OF BIRTH :";
	    cin>>dd;
		throw dd;
     }
	catch(string dd)
	{
		if(dd.length()!=10)
	   	{
	   		cout<<"Warning : Date of Birth not in DD/MM/YYYY form"<<endl;
	   		ch=1;
	   	}
    }
	cout<<"\n ENTER THE CONTACT ADDRESS:";
	cin>>paddress;
	cout<<"\n ENTER THE PHONE NUMBER:";
	cin>>pphone;
	cout<<"\n ENTER THE LICENSE NUMBER:";
	cin>>plicense;
	p[cnt]=new person(pname,pblood,paddress);
	p1[cnt]=new info(proll,pcla,pdiv,dd,pphone,plicense);
    cnt++;
	break;
case 3:  
	 person::displaycount();
	 break;
case 4: 
	for(int i=0;i<cnt;i++)
	{
		 p[i]->display();
		 p1[i]->display1();
    }
    //search_stu(int roll, student *p1[]);
	break; 
case 5:
		for(int i=0;i<cnt;i++)
		{
			 p[i]->display();
			 p1[i]->display1();
   		}
		cout<<"Enter entry number to delete"<<endl;
		cin>>ent;
	    delete p[ent]; 
	    delete p1[ent];
	    p[ent]=p[cnt-1];
	    p1[ent]=p1[cnt-1];
	    cnt--;
        break;
case 6:
	string srch;
    cout << "Enter Roll number to Search:";
    cin >> srch;
	ar=sea(srch);
	if (ar == -1)
        cout << "No Record Found" << endl;
    else {
        cout << "\tRecord Found." << endl;
    }
     break;
case 7:
	cout<<"Copy Constructor Called"<<endl;
  	person obj;
	 info obj1;
	 person obj2(obj);
	 info obj3(obj1);
     break;

}
if(ch==8)
{
	break;
}
else if(ch<1 || ch>8)
{
	cout<<"Enter valid choice"<<endl;
}
} while(true);
}


