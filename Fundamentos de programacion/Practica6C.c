#include<stdio.h>

void main (){
    int entero;
    float flotante;
    double doble;
    long int largo;

    int* apuntador1 = &entero;
    float* apuntador2 = &flotante;
    double* apuntador3 = &doble;
    long int* apuntador4 = &largo;

    printf("El lugar en memoria del apuntador 1 es: %p \n", apuntador1);
    printf("El lugar en memoria del apuntador 2 es: %p \n", apuntador2);
    printf("El lugar en memoria del apuntador 3 es: %p \n", apuntador3);
    printf("El lugar en memoria del apuntador 4 es: %p \n", apuntador4);
    printf("\n");
    printf("Ingresa int: \n");
    fflush(stdin);
    scanf("%d", &entero);
    printf("Ingresa float: \n");
    fflush(stdin);
    scanf("%f", &flotante);
    printf("Ingresa double: \n");
    fflush(stdin);
    scanf("%lf", &doble);
    printf("Ingresa long int: \n");
    fflush(stdin);
    scanf("%ld", &largo);
    printf("\n");
    float resultado1 = *apuntador1 + *apuntador2;
    printf("Primer resultado: %.3f \n", resultado1);
    int resultado2 = *apuntador1>>2;
    printf("Segundo resultado: %d \n", resultado2);
    float resultado3 = 2.0* *apuntador3;
    printf("Tercer resultado: %.3f \n", resultado3);
    double resultado4 = *apuntador3/3.1;
    printf("Cuarto resultado: %lf \n", resultado4);
    char resultado5= (char)*apuntador4 % 200;
    printf("Quinto resultado: %c \n", resultado5);
}