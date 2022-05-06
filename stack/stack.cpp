#include<iostream>
using namespace std;
int top=-1;
int capacity;
bool isEmpty(){
	if (top==-1)  return true;
	return false;
}
bool isFull(){
	if (top>=capacity-1)  return true;
	return false;
}
void Push(int stack[],int x){
	if (isFull()){
		cout<<"Stack overflow";
	}
	else {
		top++;
		stack[top]=x;
	}
}
void Pop (int stack[]){
	if (isEmpty()){
		cout<<"Stack underflow";
	}
	else {
		top--;
	}
}
int Top(int stack[]){
	return stack[top];
}
int size(){
	return top+1;
}
int main(){
	int stack[50];
	capacity=2;
	Push(stack,2);
	Push(stack,3);
	cout<<size();
	cout<<size();
}
