#include "header.h"


int main(){
	
	list L;
	createList(&L);
	int i;
	
	scanf("%d",&banyak);
	orang isi;
	
	if(banyak<=20){
		for(i=0;i<banyak;i++){
			scanf("%s %s %d",&isi.nama,&isi.nomor,&isi.gaji);
			addlast(isi.nomor,isi.nama,isi.gaji,&L);
		}
	}
	
	printElemen(L);	
	return 0;
}

