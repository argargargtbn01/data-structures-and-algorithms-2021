#include<iostream>
#include<stack>
using namespace std;
int main(){
	stack<int> stack;
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.pop();
	cout<<"Size: "<<stack.size()<<endl;
	cout<<"Top: "<<stack.top()<<endl;
	while(!stack.empty()){
		cout<<stack.top()<<" ";
		stack.pop();
	}
}
