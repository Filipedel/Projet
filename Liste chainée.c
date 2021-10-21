#include <stdio.h>
#include <stdlib.h>
typedef struct Element element;
struct Element{
	int key;
	element *next;
};


struct Liste{
	element *head;
};
typedef struct Liste liste;




liste *init(){
	element *e;
	liste* l;
	e=(element*)malloc(sizeof(element));
		l=(liste*)malloc(sizeof(liste));
	e->key=0;
	e->next=NULL;
	l->head=e;
	return l;	
}

liste *addfirst(liste*l,int v){
	element *first = malloc(sizeof(*first));
   
  if (l == NULL || first == NULL)
    {
        exit(EXIT_FAILURE);
    }
	first->key=v;
	
	
first->next=l->head;
l->head=first;
return l;
}
//remove premiere occurence
void removefirst(liste*l){
	element *assup=malloc(sizeof(*assup));
	if(l->head==NULL){
	 exit(EXIT_FAILURE);
}
assup=l->head;
l->head=l->head->next;
free(assup);

}

void addlast(liste *l,int key1){
	element *last=malloc(sizeof(*last));
	element * temp=malloc(sizeof(*temp));
	last->key=key1;
			last->next=NULL;
		temp=l->head;
		while(temp->next!=NULL){
			temp=temp->next;
		}	
		temp->next=last;
}

void removelast(liste*l){
	element* ap=malloc(sizeof(*ap));
	element *av=malloc(sizeof(*av));
		ap=l->head;
		av->next=NULL;
		while(ap->next!=NULL){
			av=ap;
			ap=ap->next;
		}
		av->next=NULL;
		free(ap);
		
}


// Voir si la liste est vide
liste *thisempty(liste *l){
	if(l->head==NULL){
		return NULL;
	}
	return l;
}
void affiche(liste *l){
	 if (l == NULL)
    {
        exit(EXIT_FAILURE);
    }
	element *e=malloc(sizeof(*e));
	e=l->head;
	while(e!=NULL){
		printf("(%d)->",e->key);
		e=e->next;
	}
	  printf("NADA\n");
	
}

//rechercher une clé dans une liste chainee
void keee(int key,liste*l){
	element *search=malloc(sizeof(*search));
	search=l->head;
	while(search!=NULL&&search->key!=key){
		search=search->next;
		if(search->key==key){
			printf("La clef est dans la liste");
		}
		else{
			printf("La clef n'est pas dans la liste");
		}
}
 	
}

int main(){
	liste*l;
	l=init();
	removefirst(l);
	addfirst(l,0);
	addfirst(l,2);
	affiche(l);
	keee(3,l);

}
