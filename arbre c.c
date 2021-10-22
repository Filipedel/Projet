#include <stdlib.h>
#include <stdio.h>

typedef struct node {
	int key;
	struct node *right;
	struct node *left;
}node;


void addNode(node **tree,int key){
	// création de deux variables temporaires
	node *tmpnode;//une pour le noeud
	node *tmptree=*tree;//l'autre pour l'abre
	node *elem=malloc(sizeof(node));
	elem->key=key;//initialisation des noeuds
	elem->left=NULL;
	elem->right=NULL;
	if(tmptree)
		do{
			tmpnode=tmptree;
			if(key>tmptree->key){//si la clef est plus grande que la clef réference alors elle va a droite
				tmptree=tmptree->right;
				if(!tmptree)tmpnode->right=elem;//si on atteint une feuille alors on met la clef dans le noeud
			}
			else{
				tmptree=tmptree->left;
					if(!tmptree)tmpnode->left=elem;
			}
		}
		while(tmptree);
	else *tree=elem;//si il n'y a pas d'arbres on pose la première clef;
}
//rechercher une clé.
void search(node *tree,int key1){
	while(tree){//tant qu'il y a un arbre on va dans la boucle
		if(key1==tree->key){
			printf("La clef existe");//s'il y a une clef alors on affiche
		}
		if(key1>tree->key){//si la clef est plus grande que la clef ref alors on va parcourir à droite pour si elle si trouve sinon à gauche
			tree=tree->right;
		}
		else{
			tree=tree->left;
		}	
			if(key1!=tree->key)printf("La clef n'existe pas");	
	}

}

void printTree(node *tree) //affichage de l'arbre
{
    if(!tree) return; //si il ya pas on retourne la fct

    if(tree->left)  printTree(tree->left);//fct recursive

    printf("->Cle = %d\n", tree->key);

    if(tree->right) printTree(tree->right);
}
void printTreerev(node *tree) //affichage de l'arbre inverse
{
    if(!tree) return; //si il ya pas on retourne la fct

    if(tree->right) printTree(tree->right);//fct recursive

    printf("->Cle = %d\n", tree->key);

    if(tree->left) printTree(tree->left);
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
	node *arbre;
	arbre=NULL;
	addNode(&arbre,5);
	addNode(&arbre,6);
	addNode(&arbre,4);
	printTree(arbre);
	printf("\n");
	printTreerev(arbre);
		printf("\n");
		search(arbre,1);
	cleartree(&arbre);
}
