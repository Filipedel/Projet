
#include <stdio.h>
#include <stdlib.h>
#include "Hash.h"
#include<string.h>


hash*init(int taille){
	hash*h;
	h=(hash*)malloc(sizeof(hash)*taille);
	h->tab=(char*)calloc(h->taille,sizeof(char));
	h->taille=taille;
	return h;
}
element *initi(char key,int value){
	element*e;
	e=(element*)malloc(sizeof(element));
	e->key=value;
	e->k=key;
	return e;
}


int fonctionhash(int  key,int taille){
	int l=key%taille;
	return l;
}
void ajout(element*e,hash *h){
	int key1=fonctionhash(e->key,h->taille);

	if((h)->tab[key1]==0){
			if(key1>(h->taille/2)){
		h->taille=ta(h);
		h->tab=cop(h);
	}
	(h)->tab[key1]=e->k;
	return;
}
	if(h->tab[key1]!=0){

	while(h->tab[key1]!=0&&key1<h->taille) {
			if(key1>(h->taille/2)){
		h->taille=ta(h);
		h->tab=cop(h);
	}
		key1++;
	}

	h->tab[key1]=e->k;
}
}

int ta(hash*h){
	return h->taille*3;
}
char* cop(hash* h){
	int j,i,taille=ta(h);
	char *tab;
	tab=(char*)calloc(taille,sizeof(char));
	for(j=0;j<taille;j++){
	tab[j]=h->tab[j];
}
return tab;
}

void search(hash*h,element*e){
	int i;
	for(i=0;i<h->taille;i++){
		if(e->k==h->tab[i]){
			printf("La cle existe:%c et sa valeur correspondante est:[%d]\n",h->tab[i],e->key);
			return;
		}
	}
}
void print(hash *h){
	int i;
	for(i=0;i<h->taille;i++){
		printf("[%d]->%c|\n",i,h->tab[i]);
}
}
void fre(hash *h){
	int i;
	for(i=0;h->taille;i++){
		free(h->tab);
	}
	free(h);
}


