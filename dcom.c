#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
void  decomp(int n){
	int b=n;
	int i=0;
	int k=0;
	int *tab=(int*)malloc(sizeof(int)*INT_MAX);
	while(b>0&&i<INT_MAX){
	if(b%2!=0){
		tab[i]=1;
	
	}
if(b%2==0){
tab[i]=0;

	}
	b=b/2;
	i++;
	
}

for(k=i-1;k>=0;k--){
	printf("%d",tab[k]);
}

}


int main(){

int b;
	int c;
	printf("Voulez vous tester un nombre ? Tapez 1 pour oui ou 0 sinon\n");
	scanf("%d",&c);
	do{
	if(c==1){
	printf("Choissisez un nombre\n");
	scanf("%d",&b);
	printf("Voici le nombre choisi: %d\n",b);
	printf("Voici sa decomposition en base 2:\n");
	decomp(b);
	printf("\nVoulez vous recommencer? 1=oui, 0 sinon\n");
	scanf("%d",&c);
}
else{
	return 0;
}
}
while(c);
}
