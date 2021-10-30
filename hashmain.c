#include <stdio.h>
#include <stdlib.h>
#include "Hash.h"
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int i;
hash *h=init(3);
ajout(2,h);
ajout(1,h);
ajout(3,h);
ajout(4,h);
print(h);
fre(h);
return 0;
}
