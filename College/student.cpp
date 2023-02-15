/*
Develop an object oriented program in C++ to create a database of student information system containing the following information: 
Name, Roll number, Class, division, Date of Birth, Blood group, Contact address, telephone number, driving license no. and other. 
Construct the database with suitable member functions for initializing and destroying the data viz constructor, default constructor, Copy constructor, destructor, 
static member functions, friend class, this pointer, inline code and dynamic memory allocation operators-new and delete as well as exception handling
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
    	int sea(int srch);
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

int main()
{
  int lo=0,ch,ent;
  string srch; 
  person *p[20],*temp;
  info *p1[20],*temp1;
  char pname[15],pblood[5],paddress[20];
  string proll,pcla,pdiv,pphone,plicense,dd;
  int cnt=0;
  do
  {
	 cout<<"\n--MENU--\n1.DEFAULT CONSTRUCTOR\n2.ADD ENTRY\n3.NUMBER OF ENTRIES \n4.DISPLAY"; 
	 cout<<"\n5.DELETE ENTRY \n6.COPY CONSTRUCTOR \n7.EXIT \nENTER THE CHOICE: "<<endl;
	 cin>>ch;
	 switch(ch)
	{
		 case 1:  
			 p[cnt]=new person();
			 p1[cnt]=new info();
			 cnt=cnt+1;
			 break;
		 case 2:  
		     cout<<"\nENTER THE NAME OF STUDENT :";
		     cin>>pname;
			 cout<<"\nENTER THE BLOOD GROUP OF STUDENT :";
			 cin>>pblood;
			 cout<<"\nENTER THE ROLL NO. :";
			cin>>proll;
			try
			 {
			   	cout<<"\nENTER THE ROLL NO. :";
				cin>>proll;
				throw proll;
		     }
			catch(string proll)
			{
				for (int i = 0; i < cnt; i++)
			{
		        if (p1[i]->roll == proll)
				 {
				 	cout<<"Warning: Roll number already present at "<<i<<endl;
			     }
		     }
		    }
			cout<<"\nENTER THE CLASS :";
			cin>>pcla;
			cout<<"\nENTER THE DIVISION :";
			cin>>pdiv;
			cout<<"\nENTER DATE OF BIRTH :";
			cin>>dd;
			cout<<"\nENTER THE CONTACT ADDRESS:";
			cin>>paddress;
			try
			 {
			 	cout<<"\nENTER THE PHONE NUMBER:";
			    cin>>pphone;
				throw pphone;
		     }
			catch(string pphone)
			{
				if(dd.length()!=10)
			   	{
			   		cout<<"Warning : Check your phone number"<<endl;
			   		ch=1;
			   	}
		    }
			
			cout<<"\nENTER THE LICENSE NUMBER:";
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
			cout<<"Copy Constructor Called"<<endl;
		  	person obj;
			info obj1;
			person obj2(obj);
			info obj3(obj1);
		    break;
		
		}
		if(ch==7)
		{
			break;
		}
		else if(ch<1 || ch>8)
		{
			cout<<"Enter valid choice"<<endl;
		}
	} while(true);
}


