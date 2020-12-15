#include<iostream>
#include<conio.h>
using namespace std;

class Node{
public:
	int data;
	Node* next;

	Node(int data){
		this->data = data;
		this->next = NULL;
	}
};

Node* front = NULL;
Node* rear = NULL;

void enqueue(int data){
	Node* nn = new Node(data);
	if(front == NULL and rear == NULL){
		front = rear = nn;
	}else{
		Node* temp = front;
		while(temp->next != NULL)	temp = temp->next;
		temp->next = nn;
		rear = nn;
	}
}

int dequeue(){
	if(front == NULL){
		cout<<"Queue underflow\n";
		return -1;
	}else if(front->next == NULL){
		int data = front->data;
		delete front;
		delete rear;
		front = rear = NULL;
		return data;
	}
	int data = front->data;
	Node* temp = front;
	front = front->next;
	delete temp;
	return data;
}

void display(){
	if(front == NULL){
		cout<<"Queue is empty\n";
		return;
	}
	Node* temp = front;
	cout<<"Queue: ";
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

int main(){
	cout<<"------------------ Queue implementation using linked list -----------------\n";
	label:	cout<<endl<<"1. Enqueue\n2. Dequeue\n3. Display\n4. Clear previous queries\n5. Exit\n";
	cout<<"------------ Hi, This is 'Pankaj 196030' --------------\n\n";
	while(true){
		cout<<"Choose an option: ";
		int option;
		cin>>option;
		switch(option){
			case 1:
				int num;
				cout<<"Enter a number to insert: ";
				cin>>num;
				enqueue(num);
				cout<<endl;
				break;
			case 2:
				dequeue();
				cout<<endl;
				break;
			case 3:
				display();
				cout<<endl;
				break;
			case 4:
				system("cls");
				goto label;
			case 5:
				exit(0);
			default:
				cout<<"Invalid choice\n";
				cout<<endl;
				
		}
	}
	getch();
	return 0;
}

