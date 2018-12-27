#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

 
void menu();
void jadwal();
void jadwalcont();
void pesan();
void batal();
void cari();
void tiket();
void records();
void Queue();
void keluar();
int elemendepan();
void enque(int data);
void deque();
void tampilan();
void awal();
void isiputar();
int clrscr();

int i, psn, seats, duduk, harga, ps, data;
char name[20], cancelcs[20], sit, rspn, pilih;
int masuk;
int choice;
int el;

void Queue(){
	system ("color 5f");	
	printf("|=====================================================================================================================|\n");
	printf("|---------------------------------------------------------------------------------------------------------------------|\n");
	printf("|                                                                                                                     |\n");
	printf("|                                      MENU PILIHAN                                                                   |\n");
	printf("|                                                                                                                     |\n");
	printf("|---------------------------------------------------------------------------------------------------------------------|\n");
	printf("|                                        1. Mulai                                                                     |\n");
	printf("|                                        2. Selesai                                                                   |\n");
	printf("|                                        3. Film Yang Sedang Diputar                                                  |\n");
	printf("|                                        4. Film Pertama Yang diPutar                                                 |\n");
	printf("|                                        5. Menu Utama                                                                |\n");
	printf("|---------------------------------------------------------------------------------------------------------------------|\n");
	printf("|=====================================================================================================================|\n");
    awal();
  	while (1)
    {
    printf("\n Silahkan Pilih sesuai dengan menu pilihan : ");
	scanf("%d", &choice);
    switch (choice)
	{
    	case 1:
    		jadwal();
            printf("Masukkan Film yang akan diputar (1/2/3/4) : ");
            scanf("%d", &masuk);
            enque(masuk);
            break;
            
        case 2:
            deque();
            break;
        
        case 3:
            tampilan();
            isiputar();
            break;
                
        case 4:
        	el = elemendepan();
            if (el != 0){
                printf("\n\t\t\t   Urutan Film ke-%d\n", el);
            }else{
                printf("\n Tidak Ada Film Yang Diputar!\n");
            }
			break;
        
        case 5:
        	system("cls");
        	menu();
        	break;
            
        default:
            printf("Yang anda masukkan tidak sesuai!");
            break;
    }
}
}
