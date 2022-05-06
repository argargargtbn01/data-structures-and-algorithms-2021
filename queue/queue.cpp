#include<iostream>
using namespace std;
int capacity;
void Enqueue(int queue[],int x,int &rear){
	if (rear==capacity){
		cout<<"Overflow";
	}
	else {
		queue[rear]=x;
		rear++;
	}
}
void Dequeue(int queue[],int &front,int &rear){
	if (front==rear){
		cout<<"Underflow";
	}
	else {
		front++;
	}
}
int Front(int queue[],int front){
	return queue[front];
}

int main(){
	int queue[20]={1,2,3,4};
	int front=0,rear=4;
	capacity=20;
	Enqueue(queue,10,rear);
	Dequeue(queue,front,rear);
	for (int i=front;i<rear;i++){
		cout<<queue[i]<<" ";
	}
}
