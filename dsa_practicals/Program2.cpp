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

Node* head = NULL;

void insert_node(int data){
	Node* nn = new Node(data);

	if(head == NULL){
		head = nn;
	}
	else{
		if(data < head->data){
			nn->next = head;
			head = nn;
		}else{
			Node* curr = head;
			Node* prev = NULL;
			while(curr != NULL){
				if(data < curr->data){
					prev->next = nn;
					nn->next = curr;
					return;
				}
				prev = curr;
				curr = curr->next;
			}
			prev->next = nn;
		}
		
	}
}

void remove_node(int data){
	if(head == NULL){
		cout<<"List is empty\n";
		return;
	}	
	if(head->data == data){
		Node* temp = head;
		head = head->next;
		delete temp;
		return;
	}
	else{
		Node* prev = NULL;
		Node* curr = head;
		while(curr != NULL){
			if(curr->data == data){
				prev->next = curr->next;
				delete curr;
				return;
			}
			prev = curr;
			curr = curr->next;
		}
		cout<<data<<" is not present in the list\n";
	}	
}


int find(int data){
	int index = 0;
	Node* temp = head;
	while(temp != NULL){
		if(temp->data == data){
			return ++index;
		}
		index++;
		temp = temp->next;
	}
	return -1;
}

void display(){
	Node* temp = head;
	if(temp == NULL)	cout<<"List is empty";
	else{
		while(temp != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
		}
	}
	cout<<endl;
}

int main(){
	label:	cout<<endl; 
	cout<<endl<<"1. Insertion\n2. Deletion\n3. Searching\n4. Display\n5. Clear previous queries\n6. Exit\n";
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
				insert_node(num);
				cout<<endl;
				break;
			case 2:
				cout<<"Enter a number to delete: ";
				cin>>num;
				remove_node(num);
				cout<<endl;
				break;
			case 3:
				cout<<"Enter a number to search: ";
				cin>>num;
				int index;
				index = find(num);
				if(index == -1)	cout<<num<<" is not present in the list\n";
				else	cout<<"The position of "<<num<<" is: "<<index<<endl;
				cout<<endl;
				break;
			case 4:
				display();
				cout<<endl;
				break;
			case 5:
				system("cls");
				goto label;
			case 6:
				exit(0);
			default:
				cout<<"Invalid choice\n";
				cout<<endl;
				
		}
	}
	getch();
	return 0;
}
