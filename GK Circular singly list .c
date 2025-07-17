#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node*next;
};
struct Node*head=NULL;
struct Node*tail=NULL;
struct Node*create(int val){
	struct Node*new=(struct Node*)malloc(sizeof(struct Node));
	new->data=val;
	new->next=NULL;
	return new;
}
void insertathead(int val){
	struct Node*new=create(val);
	if(head==NULL){
		head=tail=new;
		tail->next=head;
		return;
	}
	new->next=head;
	head=new;
	tail->next=head;
}
void insertattail(int val){
	if(tail==NULL){
		insertathead(val);
		return;
	}
	struct Node*new=create(val);
	tail->next=new;
	tail=new;
	tail->next=head;
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
	struct Node*new=create(val);
	struct Node*temp=head;
	int n=1;
	while(n<(p-1)&& temp->next!=head){
		temp=temp->next;
		n++;
	};
	if(temp->next==head&&n!=(p-1)){
		printf("Out of range\n");
		return ;
	}
	struct Node*n1=temp;
	struct Node*n2=temp->next;
	n1->next=new;
	new->next=n2;
	if(n2==head){
		tail=new;
		tail->next=head;
	}
}
void deleteathead(){
	if(head==NULL){
		printf("List is empty\n");
		return;
	}
	struct Node*temp=head;
	if(head==tail){
		head=tail=NULL;
		free(temp);
		return;
	}
	head=head->next;
	tail->next=head;
	free(temp);
}
void deleteattail(){
	if(head==NULL){
		printf("List list empty\n");
		return;
	}
	struct Node*temp=head;
	if(head==tail){
		head=tail=NULL;
		free(temp);
		return;
	}
	while(temp->next!=tail&& temp->next!=head){
		temp=temp->next;
	}
	struct Node*q=tail;
	temp->next=head;
	tail=temp;
	free(q);
}
void deleteatp(int p){
	if(head==NULL){
		printf("List is empty\n");
		return;
	}
	if(p<=0){
		printf("Invalid position\n");
		return;
	}
	if(p==1){
		deleteathead();
		return;
	}
	struct Node*temp=head;
	int n=1;
	while(n<(p-1)&& temp->next!=head ){
		temp=temp->next;
		n++;
	}
	if(temp->next ==head && n!=(p-1)){
		printf("Out of range\n");
		return;
	}
	struct Node*n1=temp;
	struct Node*n2=n1->next;
	struct Node*n3=n2->next;
	n1->next=n3;
	if(n2==tail){
		tail=n1;
		n1->next=head;
	}
	free(n2);
}
void reverse(){
	if(head==NULL){
		printf("List is empty\n");
		return;
	}
	struct Node*prev=tail;
	struct Node*c=head;
	struct Node*next=NULL;
	do{
		next=c->next;
		c->next=prev;
		prev=c;
		c=next;
	}while(c!=head);
	tail=head;
	head=prev;
	tail->next=head;
}
void display(){
	if(head==NULL){
		printf("List is empty\n");
		return;
	}
	struct Node*temp=head;
	printf("Current list:\n");
	do{
		printf("%d ",temp->data);
		temp=temp->next;
	}while(temp!=head);
	printf("\n");
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int val;
		scanf("%d",&val);
		insertattail(val);
	}
	int c;
	while(1){
	printf("Menu:\n1.Insert at head\n2.Insert at tail\n3.Insert at certain position\n4.Delete at head\n5.Delete at tail\n6.Delete at certain position\n7.Reverse\n8.Exit\n");
	scanf("%d",&c);
	switch(c){
		case 1: {
			printf("Enter value\n");
				int n;
				scanf("%d",&n);
				insertathead(n);
				break;
		}
		case 2:{
			 printf("Enter value\n");
				int m;
				scanf("%d",&m);
				insertattail(m);
				break;
		}
		case 3:{
			 printf("Enter value and position respectively\n");
				int k;
				scanf("%d",&k);
				int p;
				scanf("%d",&p);
				insertatp(k,p);
				break;
		}
		case 4:{
				deleteathead();
				break;
		}
		case 5: {deleteattail();
				break;
		}
		case 6:{
			 printf("enter position\n");
				int pn;
				scanf("%d",&pn);
				deleteatp(pn);
				break;
		}
		case 7: {
			reverse();
			break;
		}
		case 8: exit(0);
		default : printf("Enter valid choice\n");
				
		}
	
	display();
}
	return 0;
}