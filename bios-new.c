#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include "menubantuan.h"
#include "Queue.h"
#include "records.h"
#include "menu.h"

typedef struct cinema{

	int plh[1];

}movie;

struct node
{
	int studio;
	char film[25];
    float jam;
    int info;
    struct node *ptr;
    struct node *next;
}*depan,*belakang,*temp,*depann;
struct node *head = NULL;
 
void jadwal();
void jadwalcont();
void pesan();
void batal();
void cari();
void tiket();
void keluar();
int elemendepan();
void enque(int data);

void awal();
void isiputar();
int clrscr();

int i, psn, seats, duduk, harga, ps, data;
int b = 30;
int price = 30000;
char name[20], cancelcs[20], sit, rspn, pilih;
char str[5][25], strt[4][20];
int hitung = 0;
int masuk;
int choice;
int el;
	
int main(){
	system ("color f0");		
	printf("=======================================================================================================================\n");
	printf("=======================================================================================================================\n");
	printf("=                                                                                                                     =\n");
	printf("=                                          SELAMAT DATANG DI E-TICKET BIOSKOP                                         =\n");
	printf("=                                                PROGRAM OLEH :                                                       =\n");
	printf("=                                           NADHILA FAKHIRA  1706043033                                               =\n");
	printf("=                                                     DAN                                                             =\n");
	printf("=                                           NURJANNAH CINTYA 1706986050                                               =\n");
	printf("=                                                                                                                     =\n");
	printf("=======================================================================================================================\n");
	printf("=======================================================================================================================\n\n");
	printf("\n");
	system("pause");
	system("cls");
	menu();	
	return 0;
}
void printList() {

   struct node *ptr = head;
   printf("|\t\t\tFilm\t\t\t Jam\t\tStudio                                                |\n");
   //start from the beginning
   while(ptr != NULL) {        
      printf("\t\t\t%s\t\t\t%2.2f\t\t%d\n",ptr->film,ptr->jam,ptr->studio);
      ptr = ptr->next;
   }
}

void insert(char film[20], float jam, int studio) {

   struct node *link = (struct node*) malloc(sizeof(struct node));

   //link->key = key;
   strcpy(link->film,film);
   link->film[25] = film[25];
   link->jam = jam;
   link->studio = studio;

   link->next = head;

   head = link;
}

void jadwal(){
	char film[25];
	float jam;
	int studio;
	head = NULL;
	char filename[100], c;
 
	system ("color F5");
	printf("|=====================================================================================================================|\n");
	printf("|---------------------------------------------------------------------------------------------------------------------|\n");
	printf("|                                                                                                                     |\n");
	printf("|                                       NOW SHOWING IN CINEMA                                                         |\n");
	printf("|                                                                                                                     |\n");
	printf("|---------------------------------------------------------------------------------------------------------------------|\n");

    insert("Aquaman", 20.05, 2); 
	insert("Suzanna", 19.30, 1);                                           
	printList();
	
	FILE *fptr;
	fptr = fopen("num.txt","r");
	c = fgetc(fptr); 
    while (c != EOF) 
    { 
        printf ("%c", c); 
        c = fgetc(fptr); 
    } 
    fclose(fptr);
	getchar();
	
	printf("\n|=====================================================================================================================|\n");
    return;    
        
}

void jadwalcont(){
	printf("\n Apakah Anda Ingin Pesan? (Y/N) : ");
	scanf("%s",&pilih);
	if (pilih == 'Y' || pilih == 'y'){
		pesan();
	}
	else if (pilih == 'N' ||pilih == 'n'){
		system("pause");
		system("cls");
		menu();	
	}
	else{
		printf("Yang Anda masukan tidak sesuai!\n\n");
		jadwal();
	}
	system("pause");
	system("cls");
	menu();
	return;
} 

void pesan(){
	printf("\n");
	printf("Masukkan Film yang akan dipesan (1/2/3/4): ");
	scanf("%d",&psn);
	if(psn > 4){
		printf("Yang Anda Masukkan Tidak Sesuai\n");
		pesan();
	}
	printf("Silahkan Masukan Nama Pelanggan : ");
	scanf("%s",&name);
	printf("\nHarga Tiket per seat Rp. %d \n",price);
    printf("Silahkan masukan jumlah tempat duduk yang dipesan: "); 
	scanf("%d",&seats);
	
	for(i=0;i<4;i++){
		if (seats <= b){
			duduk = b - seats;
			printf("Tempat duduk tersisa %d \n\n",duduk);
			
          	fflush(stdin);
			tiket();
			
       	}
        if (seats >= b){
        	printf("\nSORRY, THE MOVIE IS FULLY BOOKED\n" );
           	printf("Apakah anda ingin pesan film lain? \n"); 
           	printf("Pilih <Y/N> \n"); 
          	printf("Masukkan Pillihan anda = "); 
        	scanf("%s",&rspn);
        	if (rspn == 'Y' || rspn == 'y'){
	       	jadwal();  
    		}
    		if(rspn == 'N' || rspn == 'n'){
    	   	menu();
			}
  		}
  	system("pause");
	system("cls");
	menu();
	return;
	}
}

void cari(){
	char search;
	strcpy(str[1], "Suzanna"); 
	strcpy(strt[1], "19:30");
	strcpy(str[2], "Aquaman");
	strcpy(strt[2], "20:05");
	strcpy(str[3], "Aku,kamu,KUA");
	strcpy(strt[3], "18:05");
	strcpy(str[4], "Creed II");
	strcpy(strt[4], "19:45");
	printf("\nMasukkan Film yang anda cari : ");
	scanf (" %[^\n]", *str);
	
		if(strcmp(str[1], *str) == 0){
			printf("\nFilm '%s' Ditemukan\n", *str);
			printf("\nDitayangkan hari ini pada pukul %s\n\n",strt[1]);
			jadwal();
			jadwalcont();
		}else if(strcmp(str[2], *str) == 0){
			printf("\nFilm '%s' Ditemukan\n", *str);
			printf("\nDitayangkan hari ini pada pukul %s\n\n",strt[2]);
			jadwal();
			jadwalcont();
		}else if(strcmp(str[3], *str) == 0){
			printf("\nFilm '%s' Ditemukan\n", *str);
			printf("\nDitayangkan hari ini pada pukul %s\n\n",strt[3]);
			jadwal();
			jadwalcont();
		}else if(strcmp(str[4], *str) == 0){
			printf("\nFilm '%s' Ditemukan\n", *str);
			printf("\nDitayangkan hari ini pada pukul %s\n\n",strt[4]);
			jadwal();
			jadwalcont();
		}else{
			printf("\nFilm '%s' Tidak Ditemukan\n",str);
			printf("Apakah anda ingin cari lagi?(Y/N) : ");
			scanf("%s",&search);
			if(search == 'Y' || search == 'y'){
				cari();
			}
			else if(search == 'N' || search == 'n'){
				system("pause");
				system("cls");
				menu();
			}
			else{
				printf("Yang Anda Masukan Salah!\n");
				system("pause");
				system("cls");
				menu();
			}
		}
  	system("pause");
	system("cls");
	menu();
	return;
}

void penjelasan(){
	printf("=====================================================================================\n");
	printf("=              Selamat datang di E-TICKET Bioskop                                   = \n");
	printf("===================================================================================== \n");
	printf("=                                                                                   = \n");
	printf("= Berikut ini adalah penjelasan dari program :                                      = \n");
	printf("= [*]Program ini merupakan program untuk memesan tiket bioskop                      = \n");
	printf("= [*]E-Ticket ini memiliki seats sebanyak 30 seats pada masing-masing studio        = \n");
	printf("= [*]User dapat melihat jadwal fim,                                                 = \n");
	printf("= [*]User dapat memesan ticket bioskop                                              = \n");
	printf("= [*]User dapat membatalkan pemesanan tiket bioskop                                 = \n");
	printf("= [*]Ketika user ingin memastikan jadwal yang ingin ditonton,                       = \n");
	printf("=    User dapat ke menu 'cari'                                                      = \n");
	printf("= [*]Untuk melihat bantuan, user mengenter '1'                                      = \n");
	printf("= [*]Apabila User ke menu 'cari', maka 1 huruf depan judul Film harus besar         = \n");
	printf("===================================================================================== \n");
	printf("\n\nTekan enter untuk kembali ke menu awal                                            \n");
	getch();
	system("cls");
	menu(); 
	} 
	
void tiket(){

	int x;
		if (psn == 1){
			for(x=0;x<seats;x++){
			
				printf("\n\n");
				printf("\t|=============================================================|\n");
				printf("\t|-------------------CINEMA BOOKING TICKET---------------------|\n");
				printf("\t|=============================================================|\n");
				printf("\t|Show Name : Suzanna                                          |\n");
				printf("\t\t\t\t	Date: 29-11-2017                                     \n");
				printf("\t\t\t\t	Time: 19:30                                          \n");
				printf("\t\t\t\t	Hall: 1                                              \n");
				printf("\t\t\t\t	Price\t\t: Rp. %d  \n",price);
				printf("\t\t\t\t	Customer\t: %s \n",name);
				printf("\t|=============================================================|\n");
			}
		}else if(psn == 2){
			for(x=0;x<seats;x++){
				
				printf("\n\n");
				printf("\t|=============================================================|\n");
				printf("\t|-------------------CINEMA BOOKING TICKET---------------------|\n");
				printf("\t|=============================================================|\n");
				printf("\tShow Name : Aquaman\n");
				printf("\tCustomer  : %s\n",name);
				printf("\t\t\t\t	Date\t: 29-11-2017\n");
				printf("\t\t\t\t	Time\t: 20:05\n");
				printf("\t\t\t\t	Hall\t: 2\n");
				printf("\t\t\t\t	Price\t: Rp. %d  \n\n",price);
				printf("\t|=============================================================|\n");
			}
		}else if(psn ==3){
			for(x=0;x<seats;x++){
		
				printf("\n\n");
				printf("\t|=============================================================|\n");
				printf("\t|-------------------CINEMA BOOKING TICKET---------------------|\n");
				printf("\t|=============================================================|\n");
				printf("\tShow Name : Aku,Kamu,KUA \n");
				printf("\tCustomer  : %s\n",name);
				printf("\t\t\t\t	Date\t: 29-11-2017\n");
				printf("\t\t\t\t	Time\t: 18:05\n");
				printf("\t\t\t\t	Hall\t: 3\n");
				printf("\t\t\t\t	Price\t: Rp. %d  \n\n",price);
				printf("\t\t\t\t	Customer\t: %s \n",name);
				printf("\t|=============================================================|\n");
			}
		}else if (psn == 4){
			for(x=0;x<seats;x++){
			
				printf("\n\n");
				printf("\t|=============================================================|\n");
				printf("\t|-------------------CINEMA BOOKING TICKET---------------------|\n");
				printf("\t|=============================================================|\n");
				printf("\tShow Name : Creed II\n");
				printf("\t\t\t\t	Date\t: 29-11-2017\n");
				printf("\t\t\t\t	Time\t: 19:45\n");
				printf("\t\t\t\t	Hall\t: 4\n");
				printf("\t\t\t\t	Price\t: Rp. %d  \n\n",price);
				printf("\t\t\t\t	Customer\t: %s \n",name);
				printf("\t|=============================================================|\n");
			}
		}else{
			system("pause");
			system("cls");
			menu ();
		}
		
			harga = price * seats; 
           	printf("Total Harga adalah Rp. %d \n\n",harga);
	
	system("pause");
	system("cls");
	menu();
	return;
}

void batal(){
	printf("Masukkan Urutan Film yang akan dibatalkan : ");
	scanf("%d",&ps);
	printf("Masukkan nama pelanggan yang akan dibatalkan: ");
	scanf("%s",&cancelcs);
	if (cancelcs == name || ps == psn){
		printf("\nNama anda sudah dibatalkan\n");
		system("pause");
		system("cls");
		menu();
	}
	else{
		printf("\nMAAF, NAMA YANG ANDA MASUKKAN TIDAK SESUAI! \n");
		printf("Silahkan coba lagi\n");
		system("pause");
		system("cls");
		menu();
	}

	return;
}

void awal()
{
    depan = belakang = NULL;
}

void isiputar()
{
    printf("\n Jumlah Film yang sedang diputar : %d", hitung);
}

void enque(int data)
{
	if (masuk == 1){
		printf("\t\t\t   |--------------------------------------------------------------|\n");
		printf("\t\t\t   |                                                              |\n");
		printf("\t\t\t   |           Film Suzanna di Mulai pada studio 1                |\n");
		printf("\t\t\t   |                                                              |\n");
		printf("\t\t\t   |--------------------------------------------------------------|\n");
	}else if (masuk == 2){
		printf("\t\t\t   |--------------------------------------------------------------|\n");
		printf("\t\t\t   |                                                              |\n");
		printf("\t\t\t   |           Film Aquaman di Mulai pada studio 2                |\n");
		printf("\t\t\t   |                                                              |\n");
		printf("\t\t\t   |--------------------------------------------------------------|\n");
	}else if (masuk == 3){
		printf("\t\t\t   |--------------------------------------------------------------|\n");
		printf("\t\t\t   |                                                              |\n");
		printf("\t\t\t   |           Film Aku,Kamu,KUA di Mulai pada studio 3           |\n");
		printf("\t\t\t   |                                                              |\n");
		printf("\t\t\t   |--------------------------------------------------------------|\n");
	}else if(masuk == 4){
	 	printf("\t\t\t   |--------------------------------------------------------------|\n");
		printf("\t\t\t   |                                                              |\n");
		printf("\t\t\t   |           Film Creed II di Mulai pada studio 4               |\n");
		printf("\t\t\t   |                                                              |\n");
		printf("\t\t\t   |--------------------------------------------------------------|\n");
	}else{
		printf("Yang Anda Masukkan Tidak Sesuai!\n\n");
	}
    if (belakang == NULL)
    {
        belakang = (struct node *)malloc(1*sizeof(struct node));
        belakang->ptr = NULL;
        belakang->info = data;
        depan = belakang;
    }
    else
    {
        temp=(struct node *)malloc(1*sizeof(struct node));
        belakang->ptr = temp;
        temp->info = data;
        temp->ptr = NULL;
 
        belakang = temp;
    }
    hitung++;
}

void tampilan()
{
	printf("\nFilm yang sedang diputar: \n");
	depann = depan;
 
    if ((depann == NULL) || (belakang == NULL))
    {
        printf("Tidak ada film yang sedang diputar!");
        return;
    }else if (depann->info == 1 || belakang == NULL){
		printf("\t\t\t   |--------------------------------------------------------------|\n");
		printf("\t\t\t   |                                                              |\n");
		printf("\t\t\t   |           Film Suzanna Sedang Diputar                        |\n");
		printf("\t\t\t   |                                                              |\n");
		printf("\t\t\t   |--------------------------------------------------------------|\n");
		}else if (depann->info == 2 || belakang == NULL){
			printf("\t\t\t   |--------------------------------------------------------------|\n");
			printf("\t\t\t   |                                                              |\n");
			printf("\t\t\t   |           Film Aquaman Sedang Diputar                        |\n");
			printf("\t\t\t   |                                                              |\n");
			printf("\t\t\t   |--------------------------------------------------------------|\n");
		}else if (depann->info == 3 || belakang == NULL){
			printf("\t\t\t   |--------------------------------------------------------------|\n");
			printf("\t\t\t   |                                                              |\n");
			printf("\t\t\t   |           Film Aku,Kamu,KUA Sedang Diputar                   |\n");
			printf("\t\t\t   |                                                              |\n");
			printf("\t\t\t   |--------------------------------------------------------------|\n");
		}else if(depann->info == 4 || belakang == NULL){
			printf("\t\t\t   |--------------------------------------------------------------|\n");
			printf("\t\t\t   |                                                              |\n");
			printf("\t\t\t   |           Film Creed II Sedang Diputar                       |\n");
			printf("\t\t\t   |                                                              |\n");
			printf("\t\t\t   |--------------------------------------------------------------|\n");
		}
	    
    while (depann != belakang)
    {
    	 printf("\t\t\t    Urutan film ke- :%d \n", depann->info);
	        depann = depann->ptr;
    	if (depann->info == 1){
			printf("\t\t\t   |--------------------------------------------------------------|\n");
			printf("\t\t\t   |                                                              |\n");
			printf("\t\t\t   |           Film Suzanna Sedang Diputar                        |\n");
			printf("\t\t\t   |                                                              |\n");
			printf("\t\t\t   |--------------------------------------------------------------|\n");
		}else if (depann->info == 2){
			printf("\t\t\t   |--------------------------------------------------------------|\n");
			printf("\t\t\t   |                                                              |\n");
			printf("\t\t\t   |           Film Aquaman Sedang Diputar                        |\n");
			printf("\t\t\t   |                                                              |\n");
			printf("\t\t\t   |--------------------------------------------------------------|\n");
		}else if (depann->info == 3){
			printf("\t\t\t   |--------------------------------------------------------------|\n");
			printf("\t\t\t   |                                                              |\n");
			printf("\t\t\t   |           Film Aku,Kamu,KUA Sedang Diputar                   |\n");
			printf("\t\t\t   |                                                              |\n");
			printf("\t\t\t   |--------------------------------------------------------------|\n");
		}else if(depann->info == 4){
			printf("\t\t\t   |--------------------------------------------------------------|\n");
			printf("\t\t\t   |                                                              |\n");
			printf("\t\t\t   |           Film Creed II Sedang Diputar                       |\n");
			printf("\t\t\t   |                                                              |\n");
			printf("\t\t\t   |--------------------------------------------------------------|\n");
		}
	       
    }
    if (depann == belakang){
        printf("\t\t\t    Urutan film ke- :%d \n", depann->info);
        
   	}
   	
} 
 
void deque()
{
	if (depan->info == 1){
		printf("\t\t\t   |--------------------------------------------------------------|\n");
		printf("\t\t\t   |                                                              |\n");
		printf("\t\t\t   |           Film Suzanna telah Selesai                         |\n");
		printf("\t\t\t   |                                                              |\n");
		printf("\t\t\t   |--------------------------------------------------------------|\n");
	}else if (depan->info == 2){
		printf("\t\t\t   |--------------------------------------------------------------|\n");
		printf("\t\t\t   |                                                              |\n");
		printf("\t\t\t   |           Film Aquaman telah Selesai                         |\n");
		printf("\t\t\t   |                                                              |\n");
		printf("\t\t\t   |--------------------------------------------------------------|\n");
	}else if (depan->info == 3){
		printf("\t\t\t   |--------------------------------------------------------------|\n");
		printf("\t\t\t   |                                                              |\n");
		printf("\t\t\t   |           Film Aku,Kamu,KUA telah Selesai                    |\n");
		printf("\t\t\t   |                                                              |\n");
		printf("\t\t\t   |--------------------------------------------------------------|\n");
	}else if(depan->info == 4){
		printf("\t\t\t   |--------------------------------------------------------------|\n");
		printf("\t\t\t   |                                                              |\n");
		printf("\t\t\t   |           Film Creed II telah Selesai                        |\n");
		printf("\t\t\t   |                                                              |\n");
		printf("\t\t\t   |--------------------------------------------------------------|\n");
	}
    depann = depan;
 
    if (depann == NULL)
    {
        printf("\n Error: Trying to display elements from empty queue");
        return;
    }
    else
        if (depann->ptr != NULL)
        {
            depann = depann->ptr;
            printf("\n Berada di urutan film ke- : %d", depan->info);
            free(depan);
            depan = depann;
        }
        else
        {
           	printf("\t\t\t   |--------------------------------------------------------------|\n");
			printf("\t\t\t   |                                                              |\n");
			printf("\t\t\t   |           Tidak Ada Film Yang Sedang Diputar                 |\n");
			printf("\t\t\t   |                                                              |\n");
			printf("\t\t\t   |--------------------------------------------------------------|\n");
            free(depan);
            depan = NULL;
            belakang = NULL;
        }
        hitung--;
}

int elemendepan()
{
	if (depan == NULL){
		printf("\n Kosong\n");
	}else if (depan->info == 1){
			printf("\t\t\t   |----------------------------------|\n");
			printf("\t\t\t   |                                  |\n");
			printf("\t\t\t   |           Suzanna                |\n");
			printf("\t\t\t   |                                  |\n");
			printf("\t\t\t   |----------------------------------|\n");
	}else if (depan->info == 2){
			printf("\t\t\t   |----------------------------------|\n");
			printf("\t\t\t   |                                  |\n");
			printf("\t\t\t   |           Aquaman                |\n");
			printf("\t\t\t   |                                  |\n");
			printf("\t\t\t   |----------------------------------|\n");
	}else if (depan->info == 3){
			printf("\t\t\t   |----------------------------------|\n");
			printf("\t\t\t   |                                  |\n");
			printf("\t\t\t   |           Aku,Kamu,KUA           |\n");
			printf("\t\t\t   |                                  |\n");
			printf("\t\t\t   |----------------------------------|\n");
	}else if(depan->info == 4){
			printf("\t\t\t   |----------------------------------|\n");
			printf("\t\t\t   |                                  |\n");
			printf("\t\t\t   |           Creed II               |\n");
			printf("\t\t\t   |                                  |\n");
			printf("\t\t\t   |----------------------------------|\n");
	}
    if ((depan != NULL) || (belakang != NULL))
        return(depan->info);
    else
        return 0;
}

int clrscr(){
	system("cls");
}

void keluar(){
		printf("\tTerima Kasih telah menggunakan program ini :) \n");
		exit(1);
		return;
}
