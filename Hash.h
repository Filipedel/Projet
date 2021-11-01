#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct element{
	char k;
	int key;
}element;

typedef struct hash{
	char *tab;
	int taille;

}hash;

hash *init(int taille);
element *initi(char key,int value);
int fonctionhash(int key,int taille);
void ajout(element*e,hash *h);
int ta(hash*h);
char * cop(hash*h);
void print(hash *h);
void search(hash*h,element*e);
void fre(hash*h);
