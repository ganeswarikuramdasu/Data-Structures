#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int queue[MAX];
int front=-1;
int rear=-1;
int isempty(){
	return front==-1;
}
int isfull(){
	return (rear+1)%MAX==front;
}
void enqueue(int val){
	if(isfull()){
		printf("Queue is full\n");
		return;
	}
	if(isempty()){
		front=rear=0;
	}
	else{
		rear=(rear+1)%MAX;
	}
	queue[rear]=val;
}
void dequeue(){
	if(isempty()){
		printf("Queue is empty\n");
		return;
	}
	if(front==rear){
		front=rear=-1;
		return;
	}
	front=(front+1)%MAX;
}
int peek(){
	if(isempty()){
		printf("Queue is empty\n");
		return -1;
	}
	return queue[front];
}
void display(){
	if(isempty()){
		printf("Queue is empty\n");
		return;
	}
	int a=front;
	printf("Current List: ");
	while(1){
		printf("%d->",queue[a]);
		if(a==rear)break;
		a=(a+1)%MAX;
	}
	printf("Back to front\n");
	return;
}int main(){
	printf("Enter the number of elements you want to store in queue\n");
	int n;
	scanf("%d",&n);
	printf("Enter elements respectively\n");
	for(int i=0;i<n;i++){
		int val;
		scanf("%d",&val);
		enqueue(val);
	}
	while(1){
		printf("Enter your choice:\n");
		printf("1.Enqueue\n2.Dequeue\n3.Peek\n4.Isempty\n5.Exit\n");
		int c;
		scanf("%d",&c);
		switch(c){
			case 1: {
				printf("Enter the value you want to store\n");
				int a;
				scanf("%d",&a);
				enqueue(a);
				display();
				break;
			}
			case 2:{
				dequeue();
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
