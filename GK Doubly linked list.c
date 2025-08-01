#include<stdio.h>
#include<stdlib.h>
struct Node{
	struct Node*prev;
	int data;
	struct Node*next;
};
struct Node*head=NULL;
struct Node*tail=NULL;
struct Node*create(int val){
	struct Node*newnode=(struct Node*)malloc(sizeof(struct Node));
	newnode->prev=NULL;
	newnode->data=val;
	newnode->next=NULL;
	return newnode;
}
void insertathead(int val){
	struct Node*newnode=create(val);
	if(head==NULL){
		head=tail=newnode;
		return;
	}
	newnode->next=head;
	head->prev=newnode;
	head=newnode;
}
void insertattail(int val){
	if(tail==NULL){
		insertathead(val);
		return;
	}
	struct Node*newnode=create(val);
	tail->next=newnode;
	newnode->prev=tail;
	tail=newnode;
}
void deleteathead(){
	if(head==NULL){
		printf("List is empty\n");
		return;
	}
	struct Node*temp=head;
	if(head->next==NULL){
		head=tail=NULL;
		free(temp);
		temp=NULL;
		return;
	}
	head=head->next;
	free(temp);
	temp=NULL;
}
void deleteattail(){
	if(tail==NULL){
		printf("List is empty\n");
		return;
	}
	if(tail==head){
		deleteathead();
		return;
	}
	struct Node*temp=tail;
	tail=temp->prev;
	tail->next=NULL;
	free(temp);

}
void insertatp(int val,int p){
	if(p<=0){
		printf("Invalid position\n");
		return;	
	}
	if(p==1){
		insertathead(val);
		return;
	}
	struct Node*newnode=create(val);
	struct Node*temp=head;
	int c=1;
	while(c!=(p-1)&& temp!=NULL){
		temp=temp->next;
		c++;
	}
	if(temp==NULL){
		printf("Out of range\n");
		return;
	}
	struct Node*n1=temp;
	struct Node*n2=temp->next;
	n1->next=newnode;
	newnode->prev=n1;
	newnode->next=n2;
	if(n2!=NULL){
		n2->prev=newnode;
	}
	else{
		tail=newnode;
	}
}
void deleteatp(int p){
	if(p<=0){
		printf("Invalid position\n");
		return;
	}
	if(p==1){
		deleteathead();
		return;
	}
	struct Node*temp=head;
	int c=1;
	while(c!=(p-1)&& temp!=NULL){
		temp=temp->next;
		c++;
	}
	if(temp==NULL || temp->next==NULL){
		printf("Out of range\n");
		return ;
	}
	struct Node*n1=temp;
	struct Node*n2=temp->next;
	struct Node*n3=n2->next;
	n1->next=n3;
	if(n3!=NULL){
		n3->prev=n1;
	}
	else{
		tail=n1;
	}
	free(n2);
}
void reverse(){
	if(head==NULL){
		printf("List is empty\n");
		return;
	}
	if(head->next==NULL){
		return;
	}
	struct Node*temp=NULL;
	struct Node*c=head;
	tail=head;
	while(c!=NULL){
		temp=c->prev;
		c->prev=c->next;
		c->next=temp;
		c=c->prev;
	}
	if(temp!=NULL){
		head=temp->prev;
	}
}
void display(){
	if(head==NULL){
		printf("List is empty\n");
		return;
	}
	struct Node*temp=head;
	printf("Current List\n");
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
int main(){
	int n;
	printf("Enter number of node you want to create\n");
	scanf("%d",&n);
	printf("Enter values you want to store in nodes\n");
	for(int i=0;i<n;i++){
		int val;
		scanf("%d",&val);
		insertattail(val);
	}
	while(1){
		printf("Select your option\n");
		printf("1. Insert at head\n");
		printf("2. Insert at tail\n");
		printf("3. Insert at certain position\n");
		printf("4. Delete at head\n");
		printf("5. Delete at tail\n");
		printf("6. Delete at certain position\n");
		printf("7. Reverse\n");
		printf("8. Exit\n");
		int o;
		scanf("%d",&o);
		switch(o){
			case 1:{
				printf("Enter the value you want to insert\n");
				int a;
				scanf("%d",&a);
				insertathead(a);
				break;
			}
			case 2:{
				printf("Enter the value you want to insert\n");
				int b;
				scanf("%d",&b);
				insertattail(b);
				break;
			}
			case 3:{
				printf("Enter the value and position consecutively\n");
				int c,d;
				scanf("%d %d",&c,&d);
				insertatp(c,d);
				break;
			}
			case 4:{
				deleteathead();
				break;
			}
			case 5:{
				deleteattail();
				break;
			}
			case 6:{
				printf("Enter the position\n");
				int e;
				scanf("%d",&e);
				deleteatp(e);
				break;
			}
			case 7:{
				reverse();
				break;
			}
			case 8:exit(0);
			default: printf("Enter valid choice\n");
		}
		display();
		
	}
	return 0;
}