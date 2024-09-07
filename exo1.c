#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "exo1_prot.h"

void get_ip()
{
    char chaine[1000];
    int a, b, c, d ;
    try:
    while (sscanf(chaine, "%d.%d.%d.%d", &a, &b, &c, &d)!=4)
    {
        printf("Entrer l'addrress IP: ");
        scanf("%s", chaine);
    }
        if(a>255 || b>255 || c>255 || d>255)
        {
            goto try;
        }
    printf("\n");
}

void get_mask()
{
    int x, y, z, o ;
    char mask[100];
    try:
    printf("Entrer le masque sous réseau\n");
    printf("MSR: ");
    scanf("%s", mask);
    while(sscanf(mask, "%d.%d.%d.%d", &x, &y, &z, &o) != 4)
        {
            get_mask();
        }
    if(x>255 || y>255 || z>255 || o>255)
        {
            goto try;
        }
}

void display()
{
    char mask[100];
    char number1[8], number2[8], number3[8], number4[8] ;
    int x, y, z, o ;
    int i;
    char chaine[8];
    if(sscanf(mask, "%d.%d.%d.%d", &x, &y, &z, &o) == 4)
        {
            printf("%d.%d.%d.%d\n", x, y, z ,o);
        }
        printf("\n");
}


// Fonction pour convertir un nombre décimal en binaire et l'afficher
int *decimale_en_binaire(int nombre)
{
    // Créer un tableau pour stocker les chiffres binaires
    int *binaire=NULL;
    binaire=(int*)malloc(8*sizeof(int));

    int index = 0;

    // Convertir le nombre en binaire
    while ( index <= 8) {
        binaire[index] = nombre % 2;
        nombre = nombre / 2;
        index++;
    }

    // Afficher le nombre binaire à l'envers
    // for (int i = 7; i >= 0; i--) {
    //     printf("%d", binaire[i]);
    // }
    return binaire;
}

void affectation(int **bin1, int **bin2, int **bin3, int **bin4)
{
    int x, y, z, o ;
    char mask[100];
    printf("MSR: %s\n",mask);
    if(sscanf(mask, "%d.%d.%d.%d", &x, &y, &z, &o) == 4)
        {
            *bin1=decimale_en_binaire(x);
            *bin2=decimale_en_binaire(y);
            *bin3=decimale_en_binaire(z);
            *bin4=decimale_en_binaire(o);
        }
    // for(int i=0; i<=7; i++)
    // {
    //     printf("%d", bin1[i]);
    // }
    // printf("\n");
}
void affiche(char **chaine, int *bin1, int *bin2, int *bin3, int *bin4)
{
    *chaine=(char*)malloc(33*sizeof(char));
    char* buffer;
    buffer=(char*)malloc(33*sizeof(char));
    int i;
    for(i=7; i>=0; i--)
    {
        sprintf(buffer,"%d", bin1[i]);
        strcat(*chaine,buffer);
    }
    for(i=7; i>=0 ; i--)
    {
        sprintf(buffer,"%d", bin2[i]);
        strcat(*chaine,buffer);
    }
    for(i=7; i>=0; i--)
    {
        sprintf(buffer,"%d", bin3[i]);
        strcat(*chaine,buffer);
    }
    for(i=7; i>=0; i--)
    {
        sprintf(buffer,"%d", bin4[i]);
        strcat(*chaine,buffer);
    }

}

void condition(char *chaine)
{
    int count;
    int i;
    for(i=0; i<32; i++)
        {
            printf("%c", chaine[i]);
        }
    printf("\n");
    if(verify(chaine))
        {
            printf("valide\n");
        }
    else
        {
            return;
        }

}

int  verify(char *chaine)
{
    int n=0, b=0, i;
    for(i=0; i<32 ; i++)
        {
            if(chaine[i]=='1')
                {
                    n=1;
                    b=1;
                }
            else if(chaine[i]=='0')
                {
                    if(!n)
                        {
                            return 0;
                        }
                    if(b)
                        {
                            return 0;
                        } 
                }
            else
                {
                    return 0;
                }
            if(chaine[i+1] == '0')
                {
                    b=0;
                }
        }
    return 1;

}

