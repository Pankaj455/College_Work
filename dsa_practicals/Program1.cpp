#include<iostream>
#include<conio.h>
using namespace std;

int arr[20] = {0};
int ed = 0, capacity = 20, size = 0;

void insert(int element){
	if(ed == capacity){
		cout<<"The array has completely filled."<<endl;
		return;
	}
	arr[ed] = element;
	ed++;	size++;
}

void insert_at(int element, int idx){
	if(size == capacity)	{
		cout<<"The array has completely filled."<<endl;
		return;
	}
	else if(idx >= capacity){
		cout<<"Invalid index"<<endl;
		return;
	}
	arr[idx] = element;
	size++;
	if(idx >= ed)	ed = idx + 1;
}

void remove(int idx){
	if(size == 0)	cout<<"The array is already empty"<<endl;
	else if(idx >= ed){
		cout<<"Invalid index\n";
	}
	else if(idx < ed){
		for(int i = idx; i < ed; i++){
			arr[i] = arr[i + 1];
		}
		ed--;
	}else if(idx == ed){
		ed--;
	}
	size--;
}


int find(int element){
	int left = 0, right = ed - 1;
	while(left <= right){
		int mid = (left + right)/2;
		if(arr[mid] == element){
			return mid;
		}else if(arr[mid] > element)	right = mid - 1;
		else	left = mid + 1;
	}
	return -1;
}

void display(){
	if(size == 0){
		cout<<"The array is empty\n";
		return;
	}
	for(int i = 0; i < ed; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main(){
	label:	cout<<"********* The capacity of the array is 20 ********* \n"<<endl;
	cout<<"1. Inserion at the end\n2. Insertion at an index\n3. Searching\n4. Deletion\n5. Display\n6. Clear previous commands\n7. Exit\n\n";
	while(true){
		cout<<"Choose an option: ";
		int option;
		cin>>option;
		switch(option){
			case 1:
				int num;
				cout<<"Enter a number: ";
				cin>>num;
				insert(num);
				cout<<endl;
				break;
			case 2:
				int index;
				cout<<"Enter a number and index: ";
				cin>>num>>index;
				insert_at(num, index);
				cout<<endl;
				break;
			case 3:
				cout<<"Enter a number to search: ";
				cin>>num;
				index = find(num);
				if(index == -1)	cout<<num<<" is not present in the array\n";
				else	cout<<"The index of "<<num<<" is: "<<index<<endl;
				cout<<endl;
				break;
			case 4:
				cout<<"Enter index of the number to delete: ";
				cin>>num;
				remove(num);
				cout<<endl;
				break;
			case 5:
				display();
				cout<<endl;
				break;
			case 6:
				system("cls");
				goto label;
			case 7:
				exit(0);
			default:
				cout<<"Invalid choice\n";
				cout<<endl;
				
		}
	}
	getch();
	return 0;
}

