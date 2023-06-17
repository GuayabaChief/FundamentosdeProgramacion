#include <stdio.h>
#include <math.h>

void main (){
    int numero;

    printf("Ingresa un numero: \n");
    scanf("%d", &numero);
    if(numero>0){
        printf("Serie 1: \n");
        for(int i=1; i <= numero;i++){
            double serie1 = 2+pow(i,3);
            printf("%1.0f, ", serie1);
        }
        printf("\n");
        printf("Serie 2: \n");
        for(int j=1; j <= numero; j++){
            double serie2 = pow(j,3) + pow(j,2) + 2;
            printf("%1.0f, ",  serie2);
        }
        printf("\n");
        printf("Serie 3: \n");
        for(int k=1; k<=numero;k++){
            double serie3 = 25 *pow(k,2);
            printf("%1.0f, ", serie3);
        }
        printf("\n");
        printf("Serie 4: \n");
        for(int l = 1; l<=numero; l++){
            printf("%d, %d, ", l, l*-1);
        }
        printf("\n");
    }
}