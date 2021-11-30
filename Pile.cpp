#include <stdlib.h>
#include <stdio.h>

typedef struct Element{
	int nombre;
	Element *next;	
}element;

typedef struct Pile{
	element* suivant;
}pile;

pile *initialiser(pile *p){
	p=(pile*)malloc(sizeof(pile));
	p->suivant=NULL;
	return p;
}

void empiler(pile *p,int nombre){
	element *e=(element*)malloc(sizeof(element));
	if(p==NULL){
		printf("La pile est vide");
	}
	e->nombre=nombre;
	e->next=p->suivant;
	p->suivant=e;
}

int depiler(pile*p){
	element *depile=(element*)malloc(sizeof(element));
	if(p==NULL){
		printf("NOP");
	}
	int nb=0;
	depile=p->suivant;
	if(p->suivant!=NULL&&p!=NULL){
		nb=depile->nombre;
		p->suivant=depile->next;
		free(depile);
	}
	return nb;
}

void affichage(pile*p){
	element *affiche;
	affiche=(element*)malloc(sizeof(element));
	affiche=p->suivant;
	while(affiche!=NULL){
		printf("%d\n",affiche->nombre);
		affiche=affiche->next;
	}
}

int main(){
	pile *p=initialiser(p);
	empiler(p,5);
	empiler(p,7);
	empiler(p,9);
	printf("Etat de la pile:\n");
	affichage(p);
		printf("La pile a depiler %d\n",depiler(p));
		printf("Etat apres depile\n");
		affichage(p);
}
