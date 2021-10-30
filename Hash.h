#include <stdio.h>
#include <stdlib.h>
typedef struct element{
	int k;
}element;

typedef struct hash{
int *tab;
	int taille;
}hash;

hash *init(int taille);
int fonctionhash(int key,int taille);
void ajout(int key,hash *h);

