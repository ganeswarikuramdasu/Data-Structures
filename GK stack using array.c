#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int stack[MAX];
int top=-1;
int isempty(){
	return top==-1;
}
int isfull(){
	return top==MAX-1;
}
void push(int val){
	if(isfull()){
		printf("Stack is full\n");
		return;
	}
	else{
	top++;
	stack[top]=val;
	}
}
void pop(){
	if(isempty()){
		printf("Stack is empty\n");
		return;
	}
	top--;
}
int peek(){
	if(top==-1){
		printf("Stack is empty\n");
		return -1;
	}
	return stack[top];
}
void display(){
	if(isempty()){
		printf("Stack is empty\n");
		return;
	}
	int a=top;
	printf("Current list: ");
	while(a!=-1){
		printf("%d->",stack[a]);
		a--;
	}
	printf("NULL\n");
}
int main(){
	printf("Enter the number of elements you want to store in stack\n");
	int n;
	scanf("%d",&n);
	printf("Enter elements respectively\n");
	for(int i=0;i<n;i++){
		int val;
		scanf("%d",&val);
		push(val);
	}
	while(1){
		printf("Enter your choice:\n");
		printf("1.Push\n2.Pop\n3.Peek\n4.Isempty\n5.Exit\n");
		int c;
		scanf("%d",&c);
		switch(c){
			case 1: {
				printf("Enter the value you want to store\n");
				int a;
				scanf("%d",&a);
				push(a);
				display();
				break;
			}
			case 2:{
				pop();
				display();
				break;
			}
			case 3:{
				int val=peek();
				if(val!=-1){
				printf("The top element is %d\n",val);
			}
				break;
			}
			case 4:{
				if(isempty()==1)printf("YES\n");
				else printf("NO\n");
				break;
			}
			case 5:{
				printf("Thank you\n");
				exit(0);
				break;
			}
			default :
				printf("Enter valid choice\n");
		}
	}
	return 0;
}