#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};
typedef struct Node node;
node *head;

node *basaekle(node *head,int data){
	node *newnode;
	newnode=(node*)malloc(sizeof(node));
	newnode->data=data;
	newnode->next=head;
	return newnode;
}

node *sonaekle(node *head,int data){
	node *newnode;
	newnode=(node*)malloc(sizeof(node));
	newnode->data=data;
	newnode->next=NULL;
	if(head==NULL){
		return newnode;
	}
	node *p;
	p=head;
	while(p->next!=NULL){
		p=p->next;
	}
	p->next=newnode;
	return head;
}

void listeyi_bastir(node *head){
	node *p;
	p=head;
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
}
int main() {
	node *head=NULL;
	int sayi;
	while(1){
		printf("bir sayi giriniz:");
		scanf("%d",&sayi);
		if(sayi==-1){
			break;
		}
		if(sayi%2==0){
			head=sonaekle(head,sayi);
		}
		else{
			head=basaekle(head,sayi);
		}
	}
	printf("liste:\n");
	listeyi_bastir(head);
	
	return 0;
}
