#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node*next;
};
struct Node*top=NULL;
struct Node*create(int val){
	struct Node*newnode=(struct Node*)malloc(sizeof(struct Node));
	newnode->data=val;
	newnode->next=NULL;
	return newnode;
}
void push(int val){
	struct Node*newnode=create(val);
	newnode->next=top;
	top=newnode;
}
void pop(){
	struct Node*temp=top;
	if(top==NULL){
		printf("Stack is empty\n");
		return;
	}
	top=top->next;
	free(temp);
}
int peek(){
	if(top==NULL){
		printf("Stack is empty\n");
		return -1;
	}
	return top->data;
}
int isempty(){
	return top==NULL;
}
void display(){
	struct Node*temp=top;
	printf("The current stack: ");
	while(temp!=NULL){
		printf("%d->",temp->data);
		temp=temp->next;
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
				if(peek()!=-1){
				printf("The top element is %d\n",peek());
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