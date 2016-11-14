/*Saya Misdan Wijaya (1305262) dengan ini bersumpah demi tuhan
bahwa mengerjakan TP 1 ini tanpa melakukan kecurangan,
seperti mencatat atau melihat kode sejenis milik teman dan atau 
segala bentuk kecurangan seperti yang telah disepakati bersama*/

#include <stdio.h>
#include <string.h>

typedef struct {
	/* data */
	char nama[10];
	char nomor[10];
	int gaji;
}orang;

typedef struct {
	/* data */
	int next;
	orang kontainer;
}elemen;

typedef struct {
	int first;
	elemen data[10];
}list;

int banyak;
void createList(list *L);

//void untuk fungsi
void createList (list *L);
int countElemen (list L);
void printElemen (list L);
void selectionsort (list *L);
void delfirst(list *L);
void delafter (int sebelum, list *L);
void addlast (char nomor[], char nama[], int gaji, list *L);
void addfirst(char nomor[], char nama[], int gaji, list *L);
int emptyElemen(list L);
