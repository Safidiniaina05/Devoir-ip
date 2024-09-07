#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "exo2_prot.h"

char *get_ip_sous_reseau(int *x, int *y, int *z, int *p, int *res)
{   
    retour:
    try:
    char *ip=(char*)malloc(1000*sizeof(char));
    printf("Entrer l'adress IP: ");
    scanf("%s", ip);
    if (sscanf(ip, "%d.%d.%d.%d/%d", x, y, z, p, res) != 5)
        goto try;
    printf("\n");
    if(*res>=32)
        {
            goto retour;
        }
    printf("IP Adress : %d.%d.%d.%d\n", *x, *y, *z, *p);
    printf("NetMask : %d\n", *res);
    printf("\n");
    return ip;
}

void convertir(char *ip, int *bi1, int *bi2, int *bi3, int *bi4)
{
    int i;
    int x,  y,  z,  p;
    int res;
    char *net=NULL;
    char *a=NULL, *b=NULL, *c=NULL, *d=NULL ;
    if(sscanf(ip, "%d.%d.%d.%d/%d", &x , &y, &z, &p, &res) == 5)
        {
            a=(char*)malloc(32*sizeof(char));
            b=(char*)malloc(32*sizeof(char));
            c=(char*)malloc(32*sizeof(char));
            d=(char*)malloc(32*sizeof(char));

            net=(char*)malloc(32*sizeof(char));

            // Met le sous reseau en 1 et O le reste    
            for(i=0; i < res; i++)
                {
                    net[i]='1';
                }
            for(i=res; i<32; i++)
                {
                    net[i]='0';
                }
            printf("\n");

            // Divise tous les bits en 8 bits * 4
            int j;
            for(i=0; i<8 ; i++)
                {
                    a[i]=net[i];
                }
            for(i=8,j=0; i<16,j<8; j++,i++)
                {
                    b[j]=net[i];
                }
            for(i=16,j=0; i<24,j<8; j++,i++)
                {
                    c[j]=net[i];
                }
            for(i=24,j=0; i<32,j<8; j++,i++)
                {
                    d[j]=net[i];
                }

        // Affichage de l'adress IP en binaire        
        for(i=7; i>=0; i--)
            {
                printf("%d", bi1[i]);
            }
        printf(".");
        for(i=7; i>=0; i--)
            {
                printf("%d", bi2[i]);
            }
        printf(".");
        for(i=7; i>=0; i--)
            {
                printf("%d", bi3[i]);
            }
        printf(".");
        for(i=7; i>=0; i--)
            {
                printf("%d", bi4[i]);
            }
        printf("\n");

        //Affichage de l'adress du masque sous réseau
        display(a, b, c, d);

        //Calcul et affichage de l'adress réseau et broadcast
        calcul_res_broad(ip, a, b, c, d);

        //Calcul et affichage de nombre de machine
        calcul_nbr_machine(ip);
        }
}

void display(char *a, char *b, char *c, char *d)
{
    // Convertir les binaires en decimal (/8 bits)
    int one = strtol(a,NULL,2);
    int two = strtol(b,NULL,2);
    int three = strtol(c,NULL,2);
    int four = strtol(d,NULL,2);
    
    printf("Adress du masque sous réseau(MSR): ");
    printf("%d.%d.%d.%d\n",one, two, three, four);
}
void calcul_res_broad(char *ip, char *a, char *b, char *c, char *d)
{
    int x,  y,  z,  p, res;
    char *q=NULL, *s=NULL, *f=NULL, *g=NULL ;

    int byte1, byte2, byte3, byte4;
    int broad1, broad2, broad3, broad4 ;

    int one = strtol(a,NULL,2);
    int two = strtol(b,NULL,2);
    int three = strtol(c,NULL,2);
    int four = strtol(d,NULL,2);

        q=(char*)malloc(32*sizeof(char));
        s=(char*)malloc(32*sizeof(char));
        f=(char*)malloc(32*sizeof(char));
        g=(char*)malloc(32*sizeof(char));


    if(sscanf(ip, "%d.%d.%d.%d/%d", &x , &y, &z, &p, &res) == 5)
        { 
            byte1=one & x ;
            byte2=two & y ;
            byte3=three & z ;
            byte4=four & p ;
        }

    printf("Adress du réseau: %d.%d.%d.%d\n", byte1, byte2, byte3, byte4);
    char *net1=NULL;
    int i;

    net1=(char*)malloc(32*sizeof(char));

    // Met le sous reseau en 1 et O le reste    
    for(i=0; i < res; i++)
        {
            net1[i]='0';
        }
    for(i=res; i<32; i++)
        {
            net1[i]='1';
        }
    // Inversement de MSR
    int j;
    for(i=0; i<8 ; i++)
        {
            q[i]=net1[i];
        }
    for(i=8,j=0; i<16,j<8; j++,i++)
        {
            s[j]=net1[i];
        }
    for(i=16,j=0; i<24,j<8; j++,i++)
        {
            f[j]=net1[i];
        }
    for(i=24,j=0; i<32,j<8; j++,i++)
        {
            g[j]=net1[i];
        }
    int one1 = strtol(q,NULL,2);
    int two2 = strtol(s,NULL,2);
    int three3 = strtol(f,NULL,2);
    int four4 = strtol(g,NULL,2);

    broad1= one1 | x ;
    broad2= two2 | y ;
    broad3= three3 | z ;
    broad4= four4 | z ;

    printf("Adress de broadcast: %d.%d.%d.%d\n", broad1, broad2, broad3, broad4);
}

void calcul_nbr_machine(char *ip)
{
    int x,  y,  z,  p; /*Juste pour le condition ci_disous qu'on a besoin cette declaration*/
    int res; /*De même pour int res*/
    int result;
    if(sscanf(ip, "%d.%d.%d.%d/%d", &x , &y, &z, &p, &res) == 5)
    {
        result=pow(2,32-res)-2 ;
    }
    printf("Nombre de machine connectés: %d\n", result);
    printf("\n");
}

void convertir_ip_en_bin(char *ip, int **bi1, int **bi2, int **bi3, int **bi4)
{
    int x,  y,  z,  p; /*Juste pour le condition ci_disous qu'on a besoin cette declaration*/
    int res; /*De même pour int res*/
    if(sscanf(ip, "%d.%d.%d.%d/%d", &x , &y, &z, &p, &res) == 5)
        {
            *bi1=decimale_en_binaire(x);
            *bi2=decimale_en_binaire(y);
            *bi3=decimale_en_binaire(z);
            *bi4=decimale_en_binaire(p);
        }
}


// Fonction pour convertir un nombre décimal en binaire et l'afficher
int *decimale_en_binaire(int nombre)
{
    // Vérifier si le nombre est 0
    if (nombre == 0) {
        printf("0");
        exit(0);
    }

    // Créer un tableau pour stocker les chiffres binaires
    int *binaire=NULL;
    binaire=(int*)malloc(8*sizeof(int));

    int index = 0;

    // Convertir le nombre en binaire
    while ( index < 8) {
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