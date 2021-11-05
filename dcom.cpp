#include <stdlib.h>
#include <stdio.h>

void decomp(int n){
	int b=n;
	while(b>0){
	if(b%2==0){
		printf("0");
	}
	else printf("1");
	b=b/2;
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

