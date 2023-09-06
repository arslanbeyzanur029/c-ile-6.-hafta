#include <stdio.h>
#include <stdlib.h>


/*Bir baðlý doðrusal listelerde listenin ortasýnda yer alan elemaný silen (tuttuðu alaný belleðe geri 
iade eden) bir fonksiyon yazýnýz (Liste 100 ya da 101 elemanlý ise 50. elamaný silecek þekilde). 
Fonksiyon parametre olarak bir liste alýp güncellenen listeyi geri döndürecektir. */

struct Node{
	int data;
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
		scanf("%d",&p->data);
	}
	p->next=NULL;
	return head;
}
  node *ortaya_ekle(node *head,int n){
  	node *p,*q;
  	p=head;
  	int temp;
  	temp=n/2+1;
  	while(p->next!=NULL && n!=temp){
  		q=p;
  		p=p->next;
  		n--;
	  }
	  if(n==temp){
	  	q->next=p->next;
	  	free(p);
	  }
	  return head;
  }
  void bastir(){
  	node *p;
  	p=head;
  	while(p!=NULL){
  		printf("%d ",p->data);
  		p=p->next;
	  }
  }

int main() {
	int n;
	printf("kac adet veri gireceksiniz:");
	scanf("%d",&n);
	head=liste_olustur(head,n);
	head=ortaya_ekle(head,n);
	bastir(head);
	return 0;
}
