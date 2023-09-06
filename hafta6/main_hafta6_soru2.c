#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Ogrenci{
	char ad[50];
	char bolum[50];
	int no;
};
struct Ogrenci ogrenci[20];

void dosya_olustur(){
	int n,i;
	FILE *dosya;
	dosya=fopen("ogrencibilgi.txt","w");
	printf("kac adet ogrenci gireceksiniz:");
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++){
		printf("%d.ogrencinin adi:",i+1); 
		fgets(ogrenci[i].ad,sizeof(ogrenci[i].ad),stdin);
		printf("%d.ogrencinin bolumu:",i+1);
		 fgets(ogrenci[i].bolum,sizeof(ogrenci[i].bolum),stdin);
		printf("%d.ogrencinin numarasi:",i+1);
		 scanf("%d",&ogrenci[i].no);
		 getchar();
		fprintf(dosya,"%s %s %d",ogrenci[i].ad,ogrenci[i].bolum,ogrenci[i].no);
	}
	if(dosya!=NULL){
		printf("dosya basariyla olusturuldu.\n");
	}
	fclose(dosya);
}
 void dosya_bastir(){
 	char k1[200];
 	FILE *dosya;
 	dosya=fopen("ogrencibilgi.txt","r");
 	if(dosya!=NULL){
 		while(fgets(k1, sizeof(k1), dosya)!=NULL){
 			printf("%s",k1);
		 }
	 }
	 else{
	 	printf("hata");
	 }
	 fclose(dosya);
 }
 void kayit_ekle(){
 	char ad[20],bolum[20];
 	int numara;
 	FILE *dosya;
 	dosya=fopen("ogrencibilgi.txt","a");
 	getchar();
 	if(dosya!=NULL){
 		printf("yeni kisinin ismi:"); 
		fgets(ad,sizeof(ad),stdin);
 		printf("yeni kisinin bolumu:"); 
		fgets(bolum,sizeof(bolum),stdin);
 		printf("yeni kisinin numrasi:"); 
		scanf("%d",&numara);
		getchar();
 		fprintf(dosya,"%s %s %d\n",ad,bolum,numara);
	 }
	 else{
	 	printf("hata");
	 }
	 printf("kayit basariyla eklenmistir.\n");
	 fclose(dosya);
 }
 void isim_ara(){
     char isim[20];
    int bulunan = 0;
    printf("aratacaginiz ismi giriniz:");
    scanf("%s",isim);
    FILE *dosya;
    dosya = fopen("ogrencibilgi.txt", "r");
    if (dosya != NULL) {
        char ad[20], bolum[20];
        int numara;
        while ( fscanf(dosya, "%s %s %d", ad, bolum, &numara)!=EOF){
            if (strcmp(ad, isim) == 0) {
                printf("Bulunan Kayit:\n");
                printf("Isim: %s\n", ad);
                printf("Bolum: %s\n", bolum);
                printf("Numara: %d\n", numara);
                printf("\n");
                bulunan++;
            }
        }

        if (bulunan == 0) {
            printf("Boyle bir kayit bulunamadi!\n");
        }
    } else {
        printf("Hata\n");
    }

    fclose(dosya);
}
 
int main() {
	int secim;
	printf("once islem yapilacak dosyayi olusturalim\n");
	dosya_olustur();
	printf("Ne yapacaginizi belirtin:\n1-Olusturulan Dosyayi Ekrana Yazdirma\n2-Dosyaya Yeni Kayit Ekleme\n3-Olusturlan Dosyadan Isim Arama\n4-Cikis: ");
	scanf("%d",&secim);
	switch(secim){
		case 1:{
			dosya_bastir();
			break;
		}
		case 2:{
			kayit_ekle();
			dosya_bastir();
			break;
		}
		case 3:{
			isim_ara();
			break;
		}
		case 4:{
			exit(0);
			break;
		}
		default:{
			printf("Hatali islem tanimlamasi!");
			break;
		}
	}
	
	
	
	
	return 0;
}
