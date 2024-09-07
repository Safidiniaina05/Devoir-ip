#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exo2_prot.h"

int main()
{
    int x,y,z,p,res;
    char *ip =NULL;
    int *bi1, *bi2, *bi3, *bi4 ;

    ip=get_ip_sous_reseau(&x,&y,&z,&p,&res);
    convertir_ip_en_bin(ip, &bi1, &bi2, &bi3, &bi4);
    convertir(ip, bi1, bi2, bi3, bi4);

    return 0;
}
