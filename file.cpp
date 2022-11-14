/*
Write a C++ program that creates an output file, writes information to it, closes the file, open it again as an input file and read the information from the file
*/

#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
string str;
void write()
{
	ofstream obj;
	obj.open("test.txt");
	cout<<"Enter data "<<endl;
	cin.ignore();
	getline(cin,str);
	obj<<str;
	obj.close();
	cout<<"File closed"<<endl;	
}
void append()
{
	ofstream obj;
	obj.open("test.txt",ios::app);
	cout<<"Enter data "<<endl;
	cin.ignore();
	getline(cin,str);
	obj<<str;
	obj.close();
	cout<<"File closed"<<endl;	
}
void read()
{
	ifstream obj1("test.txt");
	cout<<"Your read data is : ";
	while(getline(obj1,str))
	{
		cout<<str<<endl;
	}
	obj1.close();
	cout<<"File closed "<<endl;
}
int main()
{
	int ch;
	do{
	cout<<"Enter choice 1. Write 2. Read 3. Append 4. Exit"<<endl;
	cin>>ch;
		switch(ch)
		{
			case 1:
				write();
				break;
			case 2:
				read();
				break;
			case 3:
				append();
				break;
			case 4:
				cout<<"Thank You"<<endl;
				break;
			default:
				cout<<"Enter valid choice "<<endl;
				break;
		}
 	}while(ch!=4);
	return 0;
}
