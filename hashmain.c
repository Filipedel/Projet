#include <stdio.h>
#include <stdlib.h>
#include "Hash.h"
#include <string.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	element*e=initi('c',10);
	element*e1=initi('c',10);
	element *e2=initi('b',8);
	element *e3=initi('b',21);
hash *h;
h=init(3);
ajout(e,h);
ajout(e1,h);
ajout(e2,h);
ajout(e3,h);

print(h);
search(h,e);
fre(h);
free(e);
free(e1);
free(e2);
return 1;
}
