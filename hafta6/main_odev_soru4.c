#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
Bir baðlý doðrusal listelerde listenin sonundaki düðüm ile baþýndaki düðümün yerini deðiþtiren
changeFirstAndLast isimli bir fonksiyon yazýnýz. Fonksiyon parametre olarak bir liste alýp
güncellenen listeyi geri döndürecektir.
*/




struct node{
    int data;
    struct node* next;
};

typedef struct node node;

node* changeFirstAndLast(node* head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }

        node* p=head;
        node* sonraki=NULL;
        while(p->next!=NULL)
        {
            sonraki=p;
            p=p->next;
        }
        p->next=head->next;
        head->next=NULL;
        sonraki->next=head;
        return(p);



}

void bastir(node* head)
{
    node* p=head;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf(" ");
}




int main()
{


   int n,sayi;
   printf("kac dugum olcak:  ");
   scanf("%d",&n);
   int i;
   node* head=NULL;
   for(i=0;i<n;i++)
   {
       printf("%d. sayiyi giriniz:  ",i+1);
       scanf("%d",&sayi);
       node* newnode=(node*)malloc(sizeof(node));
       newnode->data=sayi;
       newnode->next=NULL;
       if(head==NULL)
       {
           head=newnode;
       }
       else
       {
           node* p=head;
           while(p->next!=NULL)
           {
               p=p->next;
           }
           p->next=newnode;

       }
   }
   printf("orijinal liste:  ");
   bastir(head);

   head=changeFirstAndLast(head);
   printf("guncellenmis:  ");
   bastir(head);

    return 0;
}
