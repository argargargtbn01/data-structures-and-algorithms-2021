#include<iostream>
using namespace std;
int n;
struct Node {
	int data;
	Node *next;
};

struct List {
	Node *head;
	Node *tail;
};

void Init(List &l){
	l.head = l.tail = NULL;	
}

Node *createNode(int x){
	Node *p=new Node;
	if (p==NULL) exit(1);
	p->next=NULL;
	p->data=x;
	return p;
}

bool isEmpty(List l){
	if (l.head==NULL)  return true;
	return false;
}

void addHead(List&l, int x){
	Node *p=createNode(x);
	if (isEmpty(l))  l.head=l.tail=p;
	else {
		p->next = l.head;
		l.head=p;
	}
}

void addTail (List&l,int x){
	Node *p=createNode(x);
	if (isEmpty(l))  l.head=l.tail=p;
	else {
		l.tail->next = p;
		l.tail = p;
	}
}

Node *Search(List l,int k){
	Node *p= l.head;
	while (p!=NULL){
		if (p->data==k)  return p;
		p=p->next;
	}
	return NULL;
}
//Chen node co data=x vao sau node co data=k
void addMid(List &l,int x,int k){
	Node *p= Search(l,k);
	if (p!=NULL){
		Node *q=createNode(x);
		Node *r=p->next;
		p->next=q;
		q->next=r;
	}
}

void addAtK(List &l, int x , int k){
	Node *p=l.head;
	if (isEmpty(l)|| k==0)  addHead(l,x);
	else if (k==n)  addTail(l,x);
	else {
	
		for (int i=0;i<k-1;i++){
			p=p->next;
		}
		Node *q=createNode(x);
		Node *r=p->next;
		p->next=q;
		q->next=r;
}
}

void delHead(List &l){
	if (isEmpty(l))  return ;
	else {
		Node *p=l.head;
		l.head=l.head->next;
		delete p;
	}
}

void delTail(List &l){
	if (isEmpty(l))  return ;
	else {
		Node *p=l.head;
		while (p->next->next!=NULL)  p=p->next;
		delete (p->next);
		p->next=NULL;
	}
}

void delAtK(List &l,int k){
	if (k==0)  delHead(l);
	else if (k>=n)  delTail(l);
	else {
		Node *p=l.head;
		for (int i=0;i<k-1;i++){
			p=p->next;
		}
		Node *temp=p->next;
		p->next=p->next->next;
		delete temp;
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

void Xuat (List l){
	Node *p=l.head;
	while (p!=NULL){
		cout<<p->data<<" ";
		p=p->next;
	}
	;
}

Node *getNode (List &l,int k){
	Node *p=l.head;
	for (int i=0;i<k;i++){
		p=p->next;
	}
	return p;
}

void convert(List &l,int a,int b){
	Node *p=l.head;
	while (p!=NULL){
		if (p->data==a){
			p->data=b;
		}
		p=p->next;
	}
}

int main(){
	List l;
	Init(l);
	Nhap(l);
	delTail(l);
	Xuat(l);
}
