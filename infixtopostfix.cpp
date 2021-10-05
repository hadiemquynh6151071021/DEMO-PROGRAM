#include <iostream>
#include <string.h>
using namespace std;

typedef int Item;

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
	void control();
	int sequence(char x);
};
stack::stack() {
	top = NULL;
	size = 0;
}
Node* stack::CreateNode(Item v){
	Node* p = new Node;
	p->data = v;	
	p->next = NULL;	
	return p;
}
void stack::push(Item v){
	Node* p = CreateNode(v);
	p->next = top;	
	top=p;
	size++;
}
Item stack::pop(){
	Node *t = top;
	Item data=top->data;
	top = top->next;
	delete t;
	size--;
	return data;
}
Item stack::peek(){
	return top->data;
}
void stack::traverse() const {
	Node *p = top;
	while (p != NULL) {
		cout << p->data << "\t";
		p = p->next;
	}
	delete p;
}
int stack::sequence(char x){
	if(x=='(')
	{
		return 1;
	}
	if(x==')')
	{
		return 2;
	}
	
	if (x=='+'||x=='-')
	{
		return 3;
	}
	if (x=='*'||x=='/')
	{
		return 4;
	}
	return 0;
}
void stack::control(){
	int j=0;
	string input;
	char output[50];
	stack s;
	cout<<"Nhap bieu thuc: ";
	fflush(stdin);
	getline(cin,input);
	int n=input.length();
	for(int i=0;i<n;i++)
	{
		if (sequence(input[i])==0)
		{
			output[j]=input[i];
			j++;
		}
		if (sequence(input[i])==1)
		{
			s.push(input[i]);
		}
		if(sequence(input[i])==2)
		{
			while(s.peek()!=')')
			{
				output[j]=s.pop();
				j++;
			}
			s.pop();	
		}
		if (sequence(s.top->data)>=sequence(input[i]))
		{
			while(sequence(s.top->data)>=sequence(input[i]))
			{
				output[j]=s.pop();
				j++;
			}
			s.push(input[i]);
		}
		if(sequence(s.top->data)<sequence(input[i]))
		{
			s.push(input[i]);
		}
	}
	while(s.size!=0)
	{
		output[j]=s.pop();
		j++;
	}
	cout<<"Bieu thuc hau to: ";
	for (int k=0;k<j+1;k++)
	{
		cout<<output[k];
	}
}
int main()
{
	stack s;
	s.control();
}

