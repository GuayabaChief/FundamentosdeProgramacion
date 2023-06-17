#include<stdio.h>
#include<stdint.h>
#include<string.h>

void main(){
    char expresion[30];
    int fin;
    do{
        printf("Ingresa caracteres:\n");
        fflush(stdin);
        scanf("%[0-9]", expresion);

        if (strlen(expresion)<=9)
        {
            printf("Su cadena es: %s \n", expresion);
        } else{
            printf("Su cadena es muy larga!!!Error!! \n");
        }
        printf("Presiona cualquier numero que no sea 0 y 1 \n");
        fflush(stdin);
        scanf("%d", &fin);
        
    }while (fin != 0 && fin != 1);
    
}