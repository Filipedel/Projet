
#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int key;
    char c;
    struct node *left;
   struct node *right;
}node;

void addNode(node **tree,int key,char b){
    node *TmpNode;
    node *TmpTree=*tree;
    node *elem=malloc(sizeof(node*));
    elem->key=key;
    elem->c=b;
    elem->right=NULL;
    elem->left=NULL;
    if(TmpTree){
        do{
            TmpNode=TmpTree;
            if(key>TmpTree->key){
                TmpTree=TmpTree->right;
                if(!TmpTree)TmpNode->right=elem;
            }
            else{
                TmpTree=TmpTree->left;
                if(!TmpTree)TmpNode->left=elem;
            }
        }
        while(TmpTree);
    }
    else{
        *tree=elem;
    }
}

void search(node *arbre,int key){
	node *search=malloc(sizeof(node*));
	search=arbre;
	int i=0;
	while(search){
	if(key==search->key){
	printf("\nLa cle existe: %d,voici sa valeur: %c ",search->key,search->c);
	i=0;
	break;
	}
	if(key!=search->key){
		i=1;
	}
	if(key>search->key){
	search=search->right;}
	else{
	 search=search->left;}
	 
	}
	if(i==1){
		printf("\n il y a pas la clef dans l'arbre");
	}
}

void print(node *tree){
    node *tmp=malloc(sizeof(node*));
    tmp=tree;
	if(tree==NULL){
		printf("Nothing");
	}	
    if(tmp->left) print(tmp->left);
    	 
    	  if(tree){
    printf("[%d]->%c|",tmp->key,tmp->c);
}
 
    if(tmp->right)print(tmp->right);
    
   
}
void taille(node *tree){
	int countleft=1,countright=1;
	if(!tree){
		printf("Pas de taille");
	}
else{
		if(tree->left==NULL&&tree->right==NULL)
		 {printf("La taille est de 0");
		 return;
		 }
	do{
	if(tree!=NULL){

		if(tree->left!=NULL){
				countleft++;
				tree=tree->left;
			}
	else{                   countright++;
				tree=tree->right;
			}
		}
		
	}
		while(tree);
		if(countright>countleft){
	printf("La taille de l'arbre est de %d sans compter la racine",countright);
}
if(countleft>countright){
	printf("La taille de l'arbre est de %d sans compter la racine",countleft);
}
	}
}

void cleartree(node *tree){
	node *tmp=tree;
	if(!tmp)return;
	if(tmp->right)cleartree(tmp->right);
	if(tmp->left)cleartree(tmp->left);
	free(tmp);
	tree=NULL;
}
int main(){
    node *Arbre=NULL;
   addNode(&Arbre,45,'s');
    addNode(&Arbre,65,'a');
    addNode(&Arbre,25,'l');
    addNode(&Arbre,98,'u');
    addNode(&Arbre,1,'t');
    addNode(&Arbre,10,'t');
	addNode(&Arbre,4,'s');
	addNode(&Arbre,5,'a');
	addNode(&Arbre,2,'m');

	
   print(Arbre);
    printf("\n");
    taille(Arbre);
    printf("\n");
    search(Arbre,9);
    cleartree(Arbre);
    return 0;
}
