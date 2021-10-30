#include <stdio.h>
#include <stdlib.h>
#include "Hash.h"
#include<string.h>


hash*init(int taille){
	int i;
	hash*h;
	h=(hash*)malloc(sizeof(hash)*taille);
	h->tab=(int*)calloc(h->taille,sizeof(int));
	h->taille=taille;
	return h;
}


int fonctionhash(int key,int taille){
	int l=key%taille;
	return l;
}
void ajout(int key,hash *h){
	element *e=malloc(sizeof(element*));
	e->k=key;
	int key1=fonctionhash(key,h->taille);
	if(key1>(h->taille/2)){
		h->taille=ta(h);
		h->tab=cop(h);
	}
	if((h)->tab[key1]==0){
	(h)->tab[key1]=e->k;
	return;
}
	if(h->tab[key1]!=0){
	while(h->tab[key1]!=0&&key1<h->taille) {
		key1++;
	}
	h->tab[key1]=e->k;
}
}

int ta(hash*h){
	return h->taille*4;
}
int* cop(hash* h){
	int j,i,taille=ta(h);
	int *tab;
	tab=(int*)calloc(taille,sizeof(int));
	for(j=0;j<taille;j++){
	tab[j]=h->tab[j];
}
return tab;
}

void search(hash*h,int key){
	int i;
	for(i=0;i<h->taille;i++){
		if(key==h->tab[i]){
			printf("La cle existe:%d dans l'indice:[%d]\n",h->tab[i],i);
		}
	}
}
void print(hash *h){
	int i;
	for(i=0;i<h->taille;i++){
		printf("[%d]->%d|\n",i,h->tab[i]);
	}
}
void fre(hash *h){
	int i;
	for(i=0;h->taille;i++){
		free(h->tab);
	}
	free(h);
}


