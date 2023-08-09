/* 
In any language program mostly syntax error occurs due to unbalancing delimiter such as (),{},[]. Write C++ program using stack to check whether given expression is well parenthesized or not.
*/
#include<iostream>
using namespace std;
/*int main()
{
int size=0;
cout<<endl<<size<<endl;
cout<<"Enter size"<<endl;
cin>>size;
int A[size];
for(int i=0;i<size;i++)
{
	cin>>A[i];
}
for(int i=0;i<size;i++)
{
	cout<<A[i]<<" ";
}
cout<<endl<<size<<endl;
return 0;
}*/
const int m=10;

class stack
{
public:
	int st[m];
	int top;
	stack()
	{
		top=-1;
	}
	bool isempty()
	{
		//return (top==-1) ? 1 : 0;
		if(top==-1)
			return 1;
		else 
			return 0;
	}
	bool isfull()
	{
		//return (top==max-1) ? 1 : 0;
		if(top==m-1)
			return 1;
		else 
			return 0;
	}
	int push(int in)
	{
		if(isfull()==0)
		{
			top++;
			st[top]=in;
		}
		else
		{
			return 1;
		}
	}
	int pop()
	{
		if(isempty()==0)
		{
			int del=st[top];
			top--;
			return del;
		}
		else
		{
			return 1;		
		}
	}
	int display()
	{
		for(int i=0;i<=top;i++)
		{
			cout<<st[i]<<" ";
		}
	}
	
};


int main()
{
	int fun,ele,che,choice;
	stack s;
	cout<<"IS EMPTY :"<<s.isempty()<<endl;
	cout<<"IS FULL : "<<s.isfull()<<endl;
	do
	{
		cout<<endl<<"Enter choice : \n1. Insert element \n2. Delete Element \n3. Display \n4. Exit"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter element to insert"<<endl;
				cin>>ele;
				che=s.push(ele);
				if (che==1)
				{
					cout<<"Stack overflow"<<endl;
				}
				else
				{
					cout<<ele<<" inserted "<<endl;
				}
				break;
			case 2:
				fun=s.pop();
				if(fun==1)
				{
					cout<<"Stack Underflow"<<endl;
				}
				else
				{
					cout<<fun<<" is deleted "<<endl;
				}
				break;
			case 3:
				s.display();
				break;
			default:
				cout<<"Invalid Choice"<<endl;
		}
	}while(choice!=4);
	
	return 0;	
}
	


