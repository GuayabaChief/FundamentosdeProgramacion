#include<stdio.h>
//Suarez Santos Gerardo 1AM1
void main(){
    int numero1=0;
    int numero2=0;
    char operador;
    double resultado=0;
    int resultadoMod=0;

    printf("Ingrese un numero: \n");
    scanf("%d", &numero1);
    fflush(stdin);
    printf("Ingrese otro numero: \n");
    scanf("%d", &numero2);
    fflush(stdin);
    scanf("Ingrese un operador: suma, resta, multiplicacion, division, modulo\n");
    scanf("%c", &operador);

    switch (operador){
        case '+':
            resultado= (double)numero1 + (double)numero2;
            printf("El resultado es: %f", resultado);
            break;
        case '-':
            resultado= (double)numero1 - (double)numero2;
            printf("El resultado es: %f", resultado);
            break;
        case '*':
            resultado= (double)numero1 * (double)numero2;
            printf("El resultado es: %f", resultado);
            break;
        case '/':
            resultado= (double)numero1 / (double)numero2;
            printf("El resultado es: %f", resultado);
            break;
        case '%':
            resultadoMod= numero1 % numero2;
            printf("El resultado es: %d", resultadoMod);
            break;
        default:
            printf("Ingrese un operador valido\n");
            break;
    }
}