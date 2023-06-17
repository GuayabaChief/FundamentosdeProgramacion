#include<stdio.h>
#include<string.h>

void main(){
    char cadena[4];

    printf("Ingresa una cadena de valores: \n");
    fflush(stdin);
    scanf("%[0-9]", cadena);

    if(strlen(cadena) <= 4){
        printf("Su cadena es: %s", cadena);
    }else{
        printf("Error fatal!!! Su cadena es muy larga, intentelo de nuevo unu");
    }
}