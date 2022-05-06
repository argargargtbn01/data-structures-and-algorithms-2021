#include<iostream>
using namespace std;
int top = -1 ;
int capacity ;
bool isFull(){
	if (top>=capacity-1)  return true;
	return false;
}

bool isEmpty(){
	if (top==-1)  return true;
	return false;
}

void Push (int stack[],int x){
	if (isFull()==true) {
		cout<<"Stack overflow";
	}
	top++;
	stack[top]=x;
}

void Pop (int stack[]){
	if (isEmpty()==true){
		cout<<"Stack empty";
	}
	top--;
}

int Top (int stack[]){
	if (isEmpty()==true){
		cout<<"Stack empty";
	}
	return stack[top];
}

int main(){
	int stack[capacity];
	capacity=2;
	cout<<bool(isEmpty())<<endl<<isFull()<<endl;
	Push(stack,2);
	cout<<!!isEmpty();
	Push(stack,2);
	cout<<isEmpty()<<endl<<isFull();
}


