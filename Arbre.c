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
//if you want the height of the tree,you take the max between tree->left and right.
int max(unsigned a,unsigned b){
	return (a>b)? a : b ;
}
int height(node *arbre){
	if(arbre==NULL){
		return 0;
	}
	else{
		return 1+max(height(arbre->left),height(arbre->right));
	}
}
//Shows how elements has the tree..
int element(node *arbre){
	if(arbre==NULL){
		return 0;
	}
	else{
		return 1+(element(arbre->left))+(element(arbre->right));
	}
}

//how many leaves has the tree;
int IsLeave(node* T) //return 1 if the tree has a leave else return 0;
{
	if (T==NULL)
		return 0;
	else if (T->left==NULL && T->right==NULL) 
		return 1;
	else
		return 0;
}
int NbLeaves( node* T)
{
	if( T==NULL)
		return 0;
	 if ( IsLeave(T)==1 )//if we catch a leave, we return 1 and also we make a recursive of the fct according to count the leaves in the tree.
		return 1;
	else
		return NbLeaves(T->left) + NbLeaves(T->right);
}

//how interns nodes has the tree
int nod(node*t){
	if(t==NULL){
		return;
	}
	if(IsLeave(t)==1){ //if the three has a leave we return 0 else 1;
		return 0;
	}
	else return 1+nod(t->left)+nod(t->right);
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



void cleartree(node *tree){

	node *tmp=tree;
	if(!tmp)return;
	if(tmp->right)cleartree(tmp->right);
	if(tmp->left)cleartree(tmp->left);
	free(tmp);
	tree=NULL;
}
int main(){
    node*Arbre=NULL;
   addNode(&Arbre,45,'s');
   addNode(&Arbre,65,'a');
    addNode(&Arbre,25,'l');
    addNode(&Arbre,98,'u');
   addNode(&Arbre,1,'t');
     addNode(&Arbre,0,'q');
       addNode(&Arbre,2,'n');
	
   print(Arbre);
printf("\n Voici la hauteur de l'arbre: %d m",height(Arbre));
    printf("\n");
    printf("\n Il y a %d element(s)",element(Arbre));
    printf("\n Il y a %d feuille(s)",NbLeaves(Arbre));
    printf("\n Il y a %d de noeuds internes",nod(Arbre));
    search(Arbre,98);
    cleartree(Arbre);
    return 0;
}
