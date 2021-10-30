#include <stdio.h>
#include <stdlib.h>
#include "Hash.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
hash *h=init(5);
ajout(1,h);
ajout(3,h);
ajout(3,h);

int i;
for( i=0;i<5;i++){
	printf("%d\n",h->tab[i]);
}
}
