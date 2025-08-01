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
void insert(int val){
	if(head==NULL){
		head=tail=create(val);
	}
	else{
		tail->next=create(val);
		tail=tail->next;
	}
}
void insertathead(int val){
	struct Node*new=create(val);
	new->next=head;
	head=new;
	if(tail==NULL)tail=new;
}
void insertattail(int val){
	struct Node*new=create(val);
	if(tail==NULL){
		tail=head=new;
		return;
	}
	tail->next=new;
	tail=new;
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
	while(n!=(p-1)&& temp!=NULL){
		temp=temp->next;
		n++;
	}
	if(temp==NULL){
		printf("Out of range\n");
		return ;
	}
	struct Node*n1=temp;
	struct Node*n2=temp->next;
	n1->next=new;
	new->next=n2;
}
void deleteathead(){
	if(head==NULL){
		printf("List is empty\n");
		return;
	}
	struct Node*temp=head;
	head=head->next;
	if(head==NULL)tail=NULL;
	free(temp);
}
void deleteattail(){
	if(head==NULL){
		printf("List list empty\n");
		return;
	}
	struct Node*temp=head;
	if(head->next==NULL){
		free(temp);
		head=tail=NULL;
		return;
	}
	while(temp->next->next!=NULL){
		temp=temp->next;
	}
	struct Node*q=temp->next;
	temp->next=NULL;
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
	while(n!=(p-1)&& temp!=NULL ){
		temp=temp->next;
		n++;
	}
	if(temp==NULL||temp->next==NULL){
		printf("Out of range\n");
		return;
	}
	struct Node*n1=temp;
	struct Node*n2=n1->next;
	struct Node*n3=n2->next;
	n1->next=n3;
	if(n2==tail)tail=n1;
	free(n2);
}
void reverse(){
	if(head==NULL){
		printf("List is empty\n");
		return;
	}
	struct Node*prev=NULL;
	struct Node*c=head;
	struct Node*next=NULL;
	tail=head;
	while(c!=NULL){
		next=c->next;
		c->next=prev;
		prev=c;
		c=next;
	}
	head=prev;
}
void display(){
	if(head==NULL){
		printf("List is empty\n");
		return;
	}
	struct Node*temp=head;
	printf("Current list:\n");
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
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