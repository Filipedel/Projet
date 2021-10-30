#include <stdio.h>
#include <stdlib.h>
#include "Hash.h"
#include<string.h>


hash*init(int taille){
	int i;
	hash*h=malloc(sizeof(hash*));
	h->taille=taille;
	h->tab=(int*)calloc(taille,sizeof(int));
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
	if((h)->tab[key1]==0){
	(h)->tab[key1]=e->k;
	}
	if((h)->tab[key1]!=0){
	if(key1>(h->taille/2)){
		h->taille=ta(h);
		h->tab=cop(h);
	}
	while(h->tab[key1]!=0&&key1<h->taille){
		key1++;
	}
	h->tab[key1]==e->k;
	}
}
int ta(hash*h){
	return h->taille*2;
}
int* cop(hash* h){
	int j,i,taille=ta(h);
int *tab=(int*)calloc(taille,sizeof(int*));
for(j=0;j<taille;j++){
	tab[j]=h->tab[j];
}
return tab;
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
