#include<stdio.h>
#include<string.h>
//Suarez Santos Gerardo 1AM1
void main(){
    char cadena1[5];
    char cadena2[5];
    char mixFinal[10];

    printf("Ingresa una cadena (maximo 5 caracteres):\n");
    fflush(stdin);
    scanf("%[^\n]", &cadena1);
    printf("Ingresa tu segunda cadena (maximo 5 caracteres): \n");
    fflush(stdin);
    scanf("%[^\n]", &cadena2);
    int i;
    for(i=0; i<5;i++){
        strncat(mixFinal, &cadena1[i], 1);
        strncat(mixFinal, &cadena2[i], 1);
    }
    printf("%s", mixFinal);
}