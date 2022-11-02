/*

Imagine a publishing company which does marketing for book and audio cassette versions.
Create a class publication that stores the title (a string) and price (type float) of a publication.
From this class derive two classes: book, which adds a page count (type int), and tape, which adds a playing time in minutes (type float).
Write a program that instantiates the book and tape classes, allows user to enter data and displays the data members. 

*****If an exception is caught, replace all the data member values with zero values.*****
*/

#include<iostream>
//#include<string.h>
using namespace std;
class pub
{
	public:
	string title;
	void tl()
	{
	cout<<"Enter the title";
	cin.ignore();
	getline(cin,title);
	}
	float price;
	void pr()
	{
	
	cout<<"Enter the price";
	cin>>price;
	}
	
	void disp3()
	{
		cout<<"Title : "<<title<<"\nPrice: "<<price<<endl;
	}
	
};

class book: public pub
{
	public:
	int page_count;
	void pa()
	{
	
	cout<<"Enter the page count";
	cin>>page_count;
	}
	void disp1()
	{
		cout<<"Title : "<<title<<"\nPrice: "<<price<<endl;
		cout<<"\nNo of pages : "<<page_count<<endl;
	}
};

class tape: public pub
{
	public:
	float play_time;
	void pl()
	{
	
	cout<<"Enter the play time";
	cin>>play_time;
	}
	
	void disp2()
	{
		cout<<"Title : "<<title<<"\nPrice: "<<price<<endl;
		cout<<"Time : "<<play_time<<endl;
	}
};

int main()
{
	tape obj1;
	book obj2;
	int x;
	do{
	cout<<"Enter choice 1. Audio cassette\n2. Book\n3. Exit"<<endl;
	cin>>x;
	switch(x)
	{
	case 1:
		obj1.tl();
		obj1.pr();
		obj1.pl();
		obj1.disp2();
		break;
	case 2:
		obj2.tl();
		obj2.pr();
		obj2.pa();	
		obj2.disp1();
	case 3:
		break;
	default:
		cout<<"Enter valid choice"<<endl;
		
	}
	if(x==3)
	{
		cout<<"See you soon. Keep coding"<<endl;
		break;
	}
	
		}while(x!=3);
		return 0;
}
