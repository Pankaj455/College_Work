#include<iostream>
#include<conio.h>
using namespace std;

class Stack{
	public:
		char stack[50];
		int height = 0;
		int top = -1;

		void push(char ch){
			if(top == 50){
				cout<<"Stack overflow"<<endl;
				return;
			}
			stack[++top] = ch;
			height++;
		}

		char pop(){
			height--;
			return stack[top--];
		}

		int size(){
			return height;
		}

		char peek(){
			return stack[top];
		}
		
};

int precedence_of(char ch){
	if(ch == '*' or ch == '/')	return 1;
	return 0;
}

int main(){
	cout<<"------------ Hi, This is 'Pankaj 196030' --------------\n\n";
	cout<<"Enter an infix expression: ";
	string postfix = "";
	string infix;
	cin>>infix;
	Stack* op = new Stack();
	for(int i = 0; i < infix.length(); i++){
		char ch = infix[i];
		if(ch >= 'a' and ch <= 'z' or ch >= 'A' and ch <= 'Z' or ch >= '0' and ch <= '9'){
			postfix += ch;
		}else{
			if(op->size() == 0)		op->push(ch);
			else if(precedence_of(ch) > precedence_of(op->peek()))		op->push(ch);
			else if(precedence_of(ch) <= precedence_of(op->peek())){
				while(op->size()){
					postfix += op->pop();
				}
				op->push(ch);
			}
		}
	}
	
	while(op->size()){
		postfix += op->pop();
	}
	
	cout<<"It's postfix is: "<<postfix;

	getch();
	return 0;
}

