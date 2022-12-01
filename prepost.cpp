/*
Implement C++ program for expression conversion as infix to postfix and its evaluation using stack based on given conditions
i. Operands and operator, both must be single character.
ii. Input Postfix expression must be in a desired format.
iii. Only '+', '-', '*' and '/ ' operators are expected. 
*/
#include<iostream>
#include<string.h>
using namespace std;
int k = 0;
class stack
{
	char st[20];
	int top;
	public:
		stack()
		{
			top=-1;
		}
		int empty()
		{
			if(top==-1)
				return 1;
			return 0;
		}
		char gettop()//f7unction will return top element of stack
		{
			return st[top];
		}
		void push(char ch)//insert elemnet into stack
		{
			st[++top]=ch;
		}
		char pop()//removeing top value from stack
		{ 
			if(!empty())
				return st[top--];
		}
};
// get priority of operators as per precedence
// higher priority given to operators with higher precedence
// for non operators, return 0
int getpriority(char ch) 
{
	 switch (ch) 
	 {
		 case '-': return 1;
		 case '+': return 2;
		 case '/': return 3;
		 case '*': return 4;
		 default : return 0;
	 }
}
// convert infix expression to postfix using a stack
void infix2postfix(char infix[], char postfix[], int size)
{
	stack s;
	int priority;
	int i = 0;
	int k = 0;
	char ch;
	while (i < size)//read while infix expression not ended
	{
		 ch = infix[i];
		 if (ch == '(') {// if left paranthesis occur---simply push the opening parenthesis
		 s.push(ch);
		 i++;
		 continue;
	 }
	 if (ch == ')') 
	 { 
	 // if right parenthesis encountered,
	 // pop of all the elements and append it to
	 // the postfix expression till we encounter
	 // a opening parenthesis
	 while (!s.empty() && s.gettop() != '(') 
	 {
		 postfix[k++] = s.gettop();
		 s.pop();
	 }
	 // pop off the opening parenthesis also
	 if (!s.empty()) 
	 {
	 	s.pop();
	 }
	 i++;
	 continue;
	 }
	 priority = getpriority(ch);
	 if (priority == 0) 
	 { 
	 	// we saw an operand simply append it to postfix expression
	 	postfix[k++] = ch;
	 }
	 else 
	 { // we saw an operator
	 	if (s.empty()) 
		{ 
			// simply push the operator onto stack 
		 	// stack is empty
	 		s.push(ch);
		}
	 	else 
		{
			 // pop of all the operators from the stack and
			 // append it to the postfix expression till we
			 // see an operator with a lower precedence that
			 // the current operator
			 while (!s.empty() && s.gettop() != '(' && priority <= getpriority(s.gettop())) 
			 {
				 postfix[k++] = s.gettop();
				 s.pop();
			 }
			 // push the current operator onto stack
			 s.push(ch);
		 }
	 }
	 i++;
 } // pop of the remaining operators present in the stack
 // and append it to postfix expression
 while (!s.empty()) 
 {
	 postfix[k++] = s.gettop();
	 s.pop();
 }
 postfix[k] = 0; // null terminate the postfix expression
}
int eval(int op1, int op2, char operate)// returns the value when a  specific operator
 // operates on two operands
{
 switch (operate) {
 case '*': return op2 * op1;
 case '/': return op2 / op1;
 case '+': return op2 + op1;
 case '-': return op2 - op1;
 default : return 0;
 }
}
// evaluates the postfix operation
int evalPostfix(char postfix[], int size) {
 stack s;
 int i = 0;
 char ch;
 int val;
 while (i < size) {
 ch = postfix[i];
 if (isdigit(ch)) {// we saw an operand
 // push the digit onto stack
 s.push(ch-'0');
 }
 else { // we saw an operator
 // pop off the top two operands from the
// stack and evalute them using the current
// operator
 int op1 = int(s.gettop());
 s.pop();
 int op2 = int(s.gettop());
 s.pop();
 val = eval(op1, op2, ch);// push the value obtained after evaluating
 // onto the stack
 s.push(val);
 }
 i++;
 }
 return val;
}
// main
int main() {
 char infix[20];
cout<<"enter the infix expression";
cin>>infix;
 int size = strlen(infix);
 char postfix[size];
 infix2postfix(infix,postfix,size);
 int val = evalPostfix(postfix, k);
 cout<<"\nInfix Expression :: "<<infix;
 cout<<"\nPostfix Expression :: "<<postfix;
 cout<<"\nExpression evaluates to "<<val;
 cout<<endl;
 cout<<endl;
 return 0;
}

