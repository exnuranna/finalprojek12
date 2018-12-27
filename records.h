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

int i, psn, seats, duduk, harga, ps, data, hitung;
char name[20], cancelcs[20], sit, rspn, pilih;
int masuk;
int choice;
int el;


void records(){
	int b = 30;
	printf("\t====================================\n");
	printf("\tALL SHOW RECORDS\n");
	printf("\t====================================\n\n");
	if (duduk == 0){
		printf("NO RECORDS!\n");
		printf("Tempat Duduk Tersedia : %d\n",b);
	}else{
	printf("Tempat Duduk tersedia : %d\n", duduk);
	tiket();
	}
	system("pause");
	system("cls");
	menu();
	
	return;
}
