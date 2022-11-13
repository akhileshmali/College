/*
Write a C++ program that creates an output file, writes information to it, closes the file, open it again as an input file and read 
the information from the file.
*/

#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class A
{
	public:
		string str;
		void write()
		{
			ofstream c1;
			c1.open("xyz.txt");
			cout<<"Enter data"<<endl;
			getline(cin,str);
			c1<<str;
			c1.close();
			cout<<"File closed"<<endl;
		}
		void read()
		{
			ifstream c2("xyz.txt");
			cout<<"Your read data is"<<endl;
			while(getline(c2,str))
			{
				cout<<str<<endl;
			}
			c2.close();
			cout<<"File closed "<<endl;
		}
}; 
int main()
{
	A obj;
	int ch;
	do{
		cout<<"Enter choice \n1. Write \n2. Read \n3. Exit"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				obj.write();
				break;
			case 2:
				obj.read();
				break;
			case 3:
				break;			
		}
	}while(ch!=3);
	}
