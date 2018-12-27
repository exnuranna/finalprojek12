#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>


void menu();
void penjelasan();

void bantuan(){
	int dec;
	printf("\nMenu Bantuan                          \n");
	printf("Pada program ini terdapat  :            \n");
	printf("    Penjelasan                          \n");
	printf("Enter 1 to see it:                       \n"); 
	scanf("%d", &dec); 
	switch (dec){ 
		case 1:
			system("cls");
			penjelasan();
			break;
		bantuan();
		system("cls");
		break;
	}}
	

