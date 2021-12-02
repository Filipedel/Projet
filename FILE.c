#include <stdlib.h>
#include <stdio.h>
typedef struct e element;
  struct e{
	int nombre;
	element* suivant;
};
typedef struct File file;
 struct File{
	element *premier;
};

file *initialisation(){
file *f=(file*)malloc(sizeof(file));
f->premier=NULL;
return f;
}


void enfiler(int nombre,file *f){
	element *e=(element*)malloc(sizeof(element));
	e->nombre=nombre;
	e->suivant=NULL;
	if(f->premier!=NULL){
		element *enfile;
		enfile=f->premier;
		while(enfile->suivant!=NULL){
			enfile=enfile->suivant;
		}
	enfile->suivant=e;
	}
	else{
		f->premier=e;
	}
}

int defiler(file *f){
	element *e=(element*)malloc(sizeof(element));
	int  nombre=0;
	e=f->premier;
	if(f->premier!=NULL&&f!=NULL){
		nombre=e->nombre;
		f->premier=e->suivant;
		free(e);
	}
	return nombre;
	
}
void affiche(file*f){
element *e=(element*)malloc(sizeof(element));
e=f->premier;
while(e!=NULL){
	printf("%d |",e->nombre);
	e=e->suivant;
}
printf("\n");
}
int main(){
	file *f;
	f=initialisation();
	enfiler(5,f);
	enfiler(10,f);
	enfiler(19,f);
	enfiler(7,f);
	printf("Etat actuel de la file\n");
	affiche(f);
	printf("La file defile %d: \n",defiler(f));
	printf("\n Etat actuel de la file\n");
	affiche(f);
}
