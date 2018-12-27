#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>


void bantuan();
 
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

int i, psn, seats, duduk, harga, ps, data, hitung;
char name[20], cancelcs[20], sit, rspn, pilih;
int masuk;
int choice;
int el;

void menu(){
	typedef struct cinema{

	int plh[1];

	}movie;

	movie mov;
	int  *pil;
	pil = mov.plh;
	system ("color 5f");	
	printf("|=====================================================================================================================|\n");
	printf("|---------------------------------------------------------------------------------------------------------------------|\n");
	printf("|                                                                                                                     |\n");
	printf("|                                       MENU XXXIII BIOSKOP                                                           |\n");
	printf("|                                                                                                                     |\n");
	printf("|---------------------------------------------------------------------------------------------------------------------|\n");
	printf("|                                        1. Jadwal Film                                                               |\n");
	printf("|                                        2. Pesan                                                                     |\n");
	printf("|                                        3. Batal Pesan                                                               |\n");
	printf("|                                        4. Cari                                                                      |\n");
	printf("|                                        5. Pemutar Film                                                              |\n");
	printf("|                                        6. Records                                                                   |\n");
	printf("|                                        7. Bantuan                                                                   |\n");
	printf("|                                        8. Keluar                                                                    |\n");
	printf("|---------------------------------------------------------------------------------------------------------------------|\n");
	printf("|=====================================================================================================================|\n");
	printf(" Silahkan Pilih	: ");
	scanf("%d", &*pil);
	printf("\n");

	switch(*pil){
		case 1:{
			system("cls");
			jadwal();
			jadwalcont();
			break;
		}
		
		case 2:{
			system("cls");
			jadwal();
			pesan();
			break;
		}
		
		case 3:{
			system("cls");
			batal();
			break;
		}
		
		case 4:{
			system("cls");
			cari();
			break;
		}
			
		case 5:{
			system("cls");
			Queue();
			break;
		}
		
		case 6:{
			system("cls");
			records();
			break;
		}
		
		case 7:{
			system("cls");
			bantuan();
			break;
		}
		
		case 8:{
			system("cls");
			keluar();
			break;
		}
		
		default :
			printf("\n\t\t\tYANG ANDA MASUKAN SALAH ! SILAHKAN COBA LAGI\n\n");
			
			menu();
	}
	system("pause");
	system("cls");
	menu();
	return;
}
