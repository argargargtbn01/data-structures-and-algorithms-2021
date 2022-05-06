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
List l3,l4,l5;

void printList(List &l){
	Node *p=l.head;
	while (p!=NULL){
		cout<<p->data<<"->";
		p=p->next;
	}
}

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

void reverse(List &l){
//	Node *parent = l.head;
//	Node *current = l.head->next;
//	l.head=current->next;
//	parent->next=NULL;
//	current->next=parent;
//	while (l.head->next){
//		parent = current;
//		current = l.head;
//		l.head = l.head->next;
//		current->next=parent;
//	}
//	l.head->next=current;
	Node *previous = NULL;
	while (l.head!=NULL){
		Node *Next=l.head->next;
		l.head->next=previous;
		previous = l.head;
		l.head=Next;
	}
	l.head=previous;
	l.tail=l.head;
	while (l.tail->next==NULL){
		l.tail=l.tail->next;
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

void merge (List &l1,List &l2){
	l5=l1;
	l5.tail->next=l2.head;
}

bool isPrime(int n){
	if (n<2){
		return false;
	}
	else {
		for (int i=2;i<n;i++){
			if (n%i==0){
				return false;
			}
		}
		return true;
	}
}
List deletePrime(List l){
	Node *p = l.head;
	while (p != NULL){
		if (isPrime(p->data)){
			addTail(l3,p->data);
		}
		p = p->next;
	}
	return l3;
}
int main(){
	List l;
	Init(l);
	Nhap(l);

	deletePrime(l);
	l4=l3;
	reverse(l3);
	Xuat(l4);
//	Xuat(l5);
	
	
}
