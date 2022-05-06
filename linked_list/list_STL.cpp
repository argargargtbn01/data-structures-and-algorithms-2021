#include<iostream>
#include<list>
using namespace std;
void printList(list<int> list1){
	list <int>::iterator x;
	for (x= list1.begin();x!=list1.end();x++){
		cout<<*x<<"->";
	}
}
int main(){
	list <int> list1(4,50);
	list<int>::iterator i = list1.begin();
	list1.insert(i,2);
	printList(list1);
	
}
