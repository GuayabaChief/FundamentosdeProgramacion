#include <stdio.h>
#include <math.h>
//Suarez Santos Gerardo 1AM1

void main(){
    int numero=0;
    double resultado=0;

    printf("Ingrese un numero: \n");
    scanf("%d", &numero);
    fflush(stdin);
    if (-1 > numero ){
        resultado = pow((double)numero, 16);
    }
    else if (-1 < numero && numero <=1){
        resultado=(double)numero;
    }
    else if (1<numero && numero<=2.5){
        resultado= pow((double)numero,3) + 1;
    }
    else if (2.5 < numero){
        resultado = 7 * pow((double)numero, 3);
    }
    printf("El resultado de la ecuacion es: %f \n", resultado);
}