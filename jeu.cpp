#include <time.h>
#include <stdio.h>
#include <stdlib.h>
void recommencer();
void game();
void jeu();

void jeu(int n){
	srand(time(NULL));
	int b= rand()% 10;
	int i=5,compteur=0;
		do{
			if(n==b){
				compteur++;
				printf("Bravo vous avez trouve le chiffre mystere %d en %d coup(s)\n",b,compteur);
				break;
			}
			if(n>b){
					i--;
					compteur++;
				printf("Cherchez encore, le chiffre  est plus petit ! Plus que %d essais\n",i);
				scanf("%d",&n);
			
			}
			if(n<b){
				i--;
				compteur++;
				printf("Cherchez encore, le chiffre  est plus grand ! Plus que %d essais\n",i);
				scanf("%d",&n);
			
			}
		}
		while(i>=1);
	printf("le chiffre mystere etait %d\n",b);
}

void game(){
		int c;
	printf("Choissisez le nombre!\n");
	scanf("%d",&c);
	jeu(c);
	recommencer();
}


void recommencer(){
	int c;
	printf("Voulez vous recommencer ? 1=OUI 0=NON\n");
	scanf("%d",&c);
	if(c==1){
		game();
	}
	else printf("AU revoir!");
}
int main(){
	printf("Bienvenue dans le jeu du chiffre mystere, le chiffre se situe entre 0 et 10!\n");
	game();
}
