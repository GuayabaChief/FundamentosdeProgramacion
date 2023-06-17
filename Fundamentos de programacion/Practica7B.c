#include<stdio.h>
#include<stdint.h>

int main(void){
    void concatenacion(char concaTotal[], char texto[], char numero[]);
    char strTexto[25];
    char strNumero[25];
    char strConcat[50];
    
    printf("Bienvenido, por favor, ingresa algun texto: \n");
    fflush(stdin);
    scanf("%[A-Za-z., ]", strTexto);
    printf("Por favor, ingresa un numero: \n");
    fflush(stdin);
    scanf("%[0-9.]", strNumero);
    printf("\n");
    concatenacion(strConcat, strTexto, strNumero);
    printf("La informacion que ingresaste es: %s \n", strConcat);
    return 0;
}

void concatenacion (char concaTotal[], char texto[], char numero[]){
    int i=0;
    while(texto[i]!='\0'){
        concaTotal[i] = texto[i];
        i++;
    }
    concaTotal[i] = ' ';
    i++;
    int j=0;
    while(numero[j]!='\0'){
        concaTotal[i+j] = numero[j];
        j++;
    }
    concaTotal[i+j]='\0';
}