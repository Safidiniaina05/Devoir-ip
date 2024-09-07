#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "exo1_prot.h"

int main()
{
    char *chaine=NULL;
    char *mask=NULL;
    int* bin3=NULL, *bin1=NULL, *bin2=NULL, *bin4=NULL;
    get_ip();
    get_mask();
    display();
    affectation(&bin1,&bin2,&bin3,&bin4);
    affiche(&chaine, bin1,bin2,bin3,bin4);
    condition(chaine);
    return 0;
}
