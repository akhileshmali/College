#include <iostream>

using namespace std;

int top = -1;
char stack[100];

// to push elements in stack

void push(char a)
{
	stack[top] = a;
 	top++;
}

// to pop elements from stack

void pop()
{
 	if (top == -1)
 	{
		 cout<<"expression is invalid\n";
 		 exit(0);
 	}
 	else
 	{
 		top--;
 	}
}

// to find top element of stack

void find_top()
{
 	if (top == -1)
		cout<<"expression is valid\n";
 	else
 		cout<<"\nexpression is invalid\n";
}

void check(char a[])
{
	for(int i = 0; a[i] != '\0';i++)
	{
	 	if (a[i] == '('||a[i] == '{'||a[i] == '[')
		 {
	 		push(a[i]);
	 	 }
	 	else if (a[i] == ')'||a[i] == '}'||a[i] == ']')
	 	{
	 		pop();
	 	}
	 }
}
int main()
{
 	int i;
 	char a[100];
	cout<<"enter expression\n";
	cin>>a;
    check(a);
	find_top();
 }
 
 
