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

	while(search){
	if(key==search->key){
	printf("\nLa cle existe: %d,voici sa valeur: %c",search->key,search->c);}
	if(key>search->key){
	search=search->right;}
	else{
	 search=search->left;}
	}

	
}

void print(node *tree,int taille){
    node *tmp=malloc(sizeof(node*));
    tmp=tree;
	if(tree==NULL){
		printf("Nothing");
	}	
    if(tmp->left) print(tmp->left,taille);
    	 
    	  if(tree){
    printf("[%d]->%c|",tmp->key,tmp->c);
}
 
    if(tmp->right)print(tmp->right,taille);
    
   
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
    addNode(&Arbre,4,'o');
    print(Arbre,7);
    search(Arbre,45);
    cleartree(Arbre);
}
