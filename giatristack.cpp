#include <iostream>
#include <string.h>
#include<math.h>
using namespace std;

typedef double Item;

struct Node{
	Item data;
	Node *next;
};

struct stack{
	Node *top;
	long size;
	
	stack();
	void traverse() const;	
	Node* CreateNode(Item v);		
	void push(Item v);
	Item pop();
	Item peek();	
};
stack::stack() {
	top = NULL;
	size = 0;
}
void stack::traverse() const {
	Node *p = top;
	while (p != NULL) {
		cout << p->data << "\t";
		p = p->next;
	}
	delete p;
}
Node* stack::CreateNode(Item v) {
	Node* p = new Node;
	p->data = v;	
	p->next = NULL;	
	return p; 
}	
void stack::push(Item v) {
	Node* p = CreateNode(v);
	p->next = top;
	top = p;	
	size++;
}
Item stack::pop() {	
	Node *t = top;
	Item data = top->data;
	top = top->next;
	delete t;
	size--;	
	return data;
}
Item stack::peek() {
	return top->data;
}
// check if a character is a number (operand)
bool isOperand(char ch) {
	if ((ch!='+')&&(ch!='-')&&(ch!='*')&&(ch!='/'))
	{
		return true;
	}
	return false;
	// SINH VIEN HOAN THIEN PHAN THAN HAM DE KIEM TRA MOT KY TU CO PHAI LA TOAN HANG HAY KHONG
	// INPUT CUA HAM: MOT KY TU
	// OUTPUT CUA HAM: TRUE NEU KY TU LA TOAN HANG, FALSE NEU KY TU KHONG PHAI LA TOAN HANG
	// WRITE YOUR CODE INSIDE THIS FUNCTION.
}
// evaluate postfix expression
double evalute(string postfix) {
	stack s;
	int n=postfix.length();
	for (int i=0;i<n;i++)
	{
		if(isOperand(postfix[i])==true)
		{
			s.push(postfix[i]);
		}
		else
		{
			double a=s.pop();
			double b=s.pop();
			switch (postfix[i])
			{
			case '+':
				{
					double c=b+a;
					s.push(c);
				}
			case '-':
				{
					double c=b-a;
					s.push(c);
				}
			case '*':
				{
					double c=b*a;
					s.push(c);
				}
			case '/':
				{
					double c=b/a;
					s.push(c);
				}
			case '^':
				{
					double c=pow(b,a);
					s.push(c);
				}
			default:
				return 0;
			}
		}
		return s.pop();
	}
	// SINH VIEN HOAN THIEN PHAN THAN HAM DE TINH GIA TRI BIEU THUC HAU TO
	// INPUT CUA HAM: BIEU THUC HAU TO
	// OUTPUT CUA HAM: GIA TRI CUA BIEU THUC HAU TO
	// WRITE YOUR CODE INSIDE THIS FUNCTION.
}
// main function
int main() {
	string e1 = "82/7*";	//28
	string e2 = "623+-382/+*2^3+";	//8
	string e3 = "72*93/+";	//17
	string e4 = "2578*+*9-";	//113
	string e5 = "753-/9*2+";	//33.5
	
	cout << e1 << " = " << evalute(e1) << endl;
	cout << e2 << " = " << evalute(e2) << endl;
	cout << e3 << " = " << evalute(e3) << endl;
	cout << e4 << " = " << evalute(e4) << endl;
	cout << e5 << " = " << evalute(e5) << endl;
	
	return 0;
}
