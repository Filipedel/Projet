#include <stdio.h>
#include <stdlib.h>
#include "Hash.h"
//not finish yet

hash*init(int taille){
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
	int taille=(h)->taille;
	element *e=malloc(sizeof(element*));
	e->k=key;
	int key1=fonctionhash(key,taille);
	if((h)->tab[key1]==0){
	(h)->tab[key1]=e->k;
	}
	else if((h)->tab[key1]!=0){
		while((h)->tab[key1]!=0&&key1<taille){
			key1++;
		}
	h->tab[key1]=e->k;
	}
}



