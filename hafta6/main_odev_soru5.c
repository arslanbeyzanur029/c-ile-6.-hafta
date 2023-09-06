#include <stdio.h>
#include <stdlib.h>

struct Node { 
int number; 
struct Node *next; 
};
typedef struct Node node;
node *head;
node *liste_olustur(node *head,int sayi){
	node *p;
	int i;
	for(i=0;i<sayi;i++){
		if(i==0){
			head=(node*)malloc(sizeof(node));
			p=head;
		}
		else{
			p->next=(node*)malloc(sizeof(node));
			p=p->next;
		}
		printf("%d. veriniz:",i+1);
		scanf("%d",&p->number);
	}
	p->next=NULL;
	return head;
}

node* cutlastaddhead(node* head){
	node *p,*q;
	p=head;
	if(head==NULL || head->next==NULL){
		printf("yapılacak islem yok");
	}
	else{
		while(p->next!=NULL){
		q=p;
		p=p->next;
		}
	p->next=head;
    head=head->next;
    p->next->next=NULL;
	}
	return head;
}

void bastir(){
  	node *p;
  	p=head;
  	while(p!=NULL){
  		printf("%d ",p->number);
  		p=p->next;
	  }
  }
int main() {
	int n;
	printf("kac adet veri gireceksiniz:");
	scanf("%d",&n);
	head=liste_olustur(head,n);
	bastir(head);
	printf("\n");
	head=cutlastaddhead(head);
	bastir(head);
	return 0;
}  
