#include<iostream>
using namespace std;
int n;
struct Node {
	int data;
	Node *prev;
	Node *next;
};
 
struct List {
	Node *head;
	Node *tail;
};

void Init (List &l){
	l.head = l.tail=NULL; 
} 

Node *createNode(int x){
	Node *p=new Node;
	 if (p==NULL)  exit(1);
	 p->next=NULL;
	 p->data=x;
	 return p;
} 

bool isEmpty(List &l){
	return (l.head==NULL);
}
 
void addHead (List &l,int x){
	Node *p=createNode(x);
	if (isEmpty(l))  l.head=l.tail=p;
	else {
		p->next=l.head;
		l.head=p;
	}
}

void addTail (List &l,int x){
	Node *p=createNode(x);
	if (isEmpty(l))  l.head=l.tail=p;
	else {
		l.tail->next=p;
		l.tail=p;
	}
}

Node *search(List &l,int k) {
	Node *p=l.head;
	while(p->next!=NULL){
		if (p->data==k)  return p;
		else  p=p->next;
	}
	return NULL;
}

void addMid(List &l,int x,int k){
	Node *p=search(l,k);
	if (p!=NULL){
		Node *q=createNode(x);
		q->next=p->next;
		p->next=q;
	}
}

void Nhap(List &l){
	cin>>n;
	for (int i=0;i<n;i++){
		int k;
		cin>>k;
		addTail(l,k);
	}
}
void Xuat(List l){
	Node *p=l.head;
	while(p!=NULL){
		cout<<p->data<<" ";
		p=p->next;
	}
}

void AddAtK(List &l,int x,int k){
	if (k==0)  addHead(l,x);
	else if (k>=n)  addTail(l,x);
	else {
		
	}
}

int main(){
	List l;
	Init(l);
	Nhap(l);
	addMid(l,2,1);
	Xuat(l);
}

