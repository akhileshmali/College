/*
Write C++ program using STL for sorting and searching user defined records such as personal
records (Name, DOB, Telephone number etc) using vector container.
*/
#include<iostream>
#include<algorithm>
#include<vector>
 
using namespace std;

class per_rec
{
	public:
		string name,dob,tele;

};

vector<per_rec> p;

void insert()
{
    per_rec p1;
    cout<<"\nEnter your name:";
    cin>>p1.name;
    cout<<"\nEnter date of birth:";
    cin>>p1.dob;
    cout<<"\nEnter Telephone Number:";
    cin>>p1.tele;
    p.push_back(p1);
}

void print(per_rec &p1)
{
		cout<<"\nName:"<<p1.name;
    	cout<<"\nDate of Birth:"<<p1.dob;
     	cout<<"\nTelephone Number:"<<p1.tele<<endl;	
}

void display()
{
	for_each(p.begin(),p.end(),print);
}

void se()
{
	int ele;
	per_rec p1;
	cout<<"Enter element to search: \n1. Name \n2. Date of Birth: \n3. Telephone Number: "<<endl;
	cin>>ele;
	switch(ele)
	{
		case 1:
			vector<per_rec> p;
			cout<<"Enter name to search "<<endl;
			cin>>p1.name;
			p=find(p.begin(),p.end(), p1.name)
			if()
			{	
				cout<<p1.name<<" Found"<<endl;
			}
			else
			{
				cout<<"Not found"<<endl;
			}
			break;
	} 	
}
/*void search()
{
    vector<Item>::iterator p;
    Item i1;
    cout<<"\nEnter Item Code to search:";
    cin>>i1.code;
    p=find(o1.begin(),o1.end(),i1);
    if(p==o1.end())
    {
         cout<<"\nNot found.";
    }
    else
    {
         cout<<"\nFound.";
    }
}*/

int main()
{
	int choice;
	do{
	cout<<"Enter your choice : \n1. Insert \n2. Display \n3. Search \n4. Sort \n5. Exit "<<endl;
	cin>>choice;
	switch(choice)
	{
		case 1:
			insert();
			break;
		case 2:
			display();
			break;
		case 3:	
			se();
			break;
		case 4:
			break;
		case 5:
			cout<<"Meet you soon "<<endl;
			break;
		default:
			cout<<"Enter valid choice"<<endl;
	} 	
	}while(choice!=3);
	return 0;

}
