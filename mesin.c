#include "header.h"

void createList (list *L){
	(*L).first=-1;
	int i;
	
	for(i=0; i<banyak; i++){
		(*L).data[i].next = -2;
	}
}

int countElemen (list L){
	int indeks =0;
	if (L.first != -1){
		int jalan = L.first;
		while (jalan!=-1){
			indeks = indeks + 1 ;
			jalan=L.data[jalan].next;
		}
	}
	return indeks;
}

//cari tempat elemen yang kosong 
int emptyElemen(list L){
	int indeks=-1;
	if (countElemen (L) < banyak){
		int i=0;
		int ketemu=0;
		while ((ketemu==0) && (i<banyak)){
			if(L.data[i].next==-2){
				ketemu=1;
				indeks=i;
			}else
				i++;
		}
	}
	return indeks;
}

void printElemen (list L){
	if(L.first != -1){
		//inisialisasi
		int elemen = L.first;
		int i = 1;
		while(elemen != -1){
			//printf ("Elemen ke %d\n",i);
			printf("%s ", L.data[elemen].kontainer.nama);
			printf("%s ", L.data[elemen].kontainer.nomor);
			//printf("%s\n", L.data[elemen].kontainer.nilai);
			//printf("next : %d\n", L.data[elemen].next);
			
			elemen = L.data[elemen].next;
			i = i + 1;
		}
	}else{
		printf("List Kosong\n");
	}
}


void delfirst(list *L){
	if(countElemen(*L)==1){
		int hapus= (*L).first;
		(*L).first=-1;
		(*L).data[hapus].next=-2;
	}else{
		int hapus=(*L).first;
		(*L).first=(*L).data[hapus].next;
		(*L).data[hapus].next=-2;
	}	
}

void delafter (int sebelum, list *L){
	if(sebelum !=-1){
		if((*L).data[sebelum].next!=-1){
			int hapus=(*L).data[sebelum].next;
			if((*L).data[hapus].next==-1){
				(*L).data[sebelum].next=-1;
				(*L).data[hapus].next=-2;
			}else{
				(*L).data[sebelum].next=(*L).data[hapus].next;
				(*L).data[hapus].next=-2;
			}
		}
	}
}	


void addfirst(char nomor[], char nama[], int gaji, list *L){
	int baru = emptyElemen(*L);
	if(baru!=-1){
		strcpy((*L).data[baru].kontainer.nomor, nomor);
		strcpy((*L).data[baru].kontainer.nama, nama);
		(*L).data[baru].kontainer.gaji=gaji;
		(*L).data[baru].next=-1;
		if((*L).first==-1){	//jika data kosong
			(*L).first=baru;		
		}else{
			(*L).data[baru].next = (*L).first;
			(*L).first=baru;
		}	
	}
}

void addlast (char nomor[], char nama[], int gaji, list *L){
	int baru=emptyElemen(*L);
	if (baru!=-1){
		if((*L).first==-1){ //jika data masih kosong
			addfirst(nomor,nama,gaji, L);
		}else{ //jika ada data lain
			strcpy((*L).data[baru].kontainer.nomor, nomor);
			strcpy((*L).data[baru].kontainer.nama, nama);
			(*L).data[baru].kontainer.gaji=gaji;
			(*L).data[baru].next=-1;
			int akhir= (*L).first; 
			
			while ((*L).data[akhir].next!=-1){
				akhir=(*L).data[akhir].next;
			}
			(*L).data[akhir].next=baru;
		}
	}
}

/*
void selectionsort (list *L){
	int i,j,akhir,awal,s_akhir,s_awal,temp_akhir,temp_awal,indeks_sebelum;
	int banyak=countElemen(*L);
	awal=(*L).first; //pointer data awal
	s_awal=-2; //pointer sebelum data awal
		
	for(i=0; i<banyak-1; i++){
		temp_awal=awal;
		temp_akhir=awal;
		akhir=(*L).data[awal].next; //pointer data yang dibandingin
		indeks_sebelum=temp_awal;
		s_akhir=indeks_sebelum;
		for(j=i+1; j<banyak; j++){
			if((*L).data[akhir].kontainer.gaji<(*L).data[temp_akhir].kontainer.gaji){
				temp_akhir=akhir; //pointer data yang ingin ditukar
				s_akhir=indeks_sebelum;
			}
			indeks_sebelum=akhir;
			akhir=(*L).data[akhir].next; //increment			
		}
		awal=(*L).data[awal].next; //increment
		
		/* temp_awal = pointer data awal yang ingin ditukar
		temp_akhir = pointer data akhir yang ingin ditukar
		s_awal = pointer sebelum data awal
		s_akhir = pointer sebelum data akhir 
		
		// printf("%d temp_akhir %d temp_awal %d s_awal %d s_akhir%d  --%s\n",i, temp_akhir, temp_awal, s_awal, s_akhir,(*L).data[temp_akhir].kontainer.nama);
		
		//jika indeks beda maka pointer ada yang ditukar
		if(temp_akhir!=temp_awal){
			
			//jika data yang ditukar ada di awal
			if(i==0) (*L).first=temp_akhir;
		
			//jika data yang ingin ditukar bersebelahan
			if((*L).data[temp_awal].next==temp_akhir){	
				(*L).data[s_awal].next=(*L).data[temp_awal].next;
				(*L).data[s_akhir].next=(*L).data[temp_akhir].next;
				(*L).data[temp_akhir].next=temp_awal;
				s_awal=temp_akhir;
				awal=temp_awal;
			}else{ //jika data yang ingin ditukar tidak bersebelahan
				(*L).data[s_awal].next=(*L).data[temp_awal].next;
				(*L).data[s_akhir].next=(*L).data[temp_akhir].next;
				(*L).data[temp_akhir].next=(*L).data[s_awal].next;
				(*L).data[temp_awal].next=(*L).data[s_akhir].next;
				(*L).data[s_awal].next=temp_akhir;
				(*L).data[s_akhir].next=temp_awal;
				temp_awal=temp_akhir; //supaya perulangan diulang dari data yang ditukar
				s_awal=temp_awal;
			}
		}else s_awal=temp_awal; //increment		
	}
}*/
/*
void undi(list *L, char togel[], int n){
	char temp[3];
	int  a1,a2,a3;//deklarasi variabel pembagi
	//cari isi variabel untuk pembagi
	temp[0]=togel[0];
	temp[1]=togel[1];
	temp[2]='\0';
	a1=atoi(temp, 10);
	temp[0]=togel[2];
	temp[1]=togel[3];
	temp[2]='\0';
	a2=atoi(temp, 10);
	temp[0]=togel[4];
	temp[1]=togel[5];
	temp[2]='\0';
	a3=atoi(temp, 10);
	
	//proses penggandaan gaji dan penghapusan pengundi
	int i,j;
	for(i=0; i<n; i++){	
		int nomor=atoi((*L).data[i].kontainer.nomor, 10);
		if(nomor%a1==0||nomor%a2==0||nomor%a3==0){
			//gaji dikali 3 kali lipat
			if(nomor%a1==0&&nomor%a2==0&&nomor%a3==0){
				(*L).data[i].kontainer.gaji=(*L).data[i].kontainer.gaji*3;
			}
			//habis dibagi digit pertama
			else if(nomor%a1==0){
				(*L).data[i].kontainer.gaji=(*L).data[i].kontainer.gaji*2;
			}
			//habis dibagi digit kedua
			else if(nomor%a2==0){
				(*L).data[i].kontainer.gaji=(*L).data[i].kontainer.gaji*7/4;
			}
			//habis dibagi digit ketiga
			else if(nomor%a3==0){
				(*L).data[i].kontainer.gaji=(*L).data[i].kontainer.gaji*3/2;
			}
		}else{
			if(i==0) delfirst(L);
			else if(i==1){
				if (i==(*L).first) delfirst(L);
				else {
					delafter((*L).first, L); 
				}
			}
			else{
				delafter(i-1, L);
			}
		}
	}
}
*/
