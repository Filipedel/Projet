#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
int ta(hash*h);
int * cop(hash*h);
void print(hash *h);
void search(hash*h,int key);
void fre(hash*h);
