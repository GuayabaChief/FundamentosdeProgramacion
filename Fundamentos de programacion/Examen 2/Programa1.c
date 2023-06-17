#include<stdio.h>
//Suarez Santos Gerardo 1AM1
typedef struct{
    int fuerza;
    int salud;
    int altura;
    int velocidad; 
    char aura;
}Caracteristicasfisicas;

typedef struct {
    char camiseta;
    char pantalones;
    char armadura;
    char alas;
    char grebas;

}Vestiduras;
typedef struct {
    char nombreP[30];
    Caracteristicasfisicas fisico;
    Vestiduras vesti;
}Personaje;

void main (){
    char opcion;
    Personaje personaje;
    Personaje* personajeAp = &personaje;
    char aura, camiseta, pantalones, armadura, alas, grebas, nombreP;
    int fuerza, salud, altura, velocidad; 

    do
    {
        printf("Bienvenido al creador de personajes, por favor selecciona que quieras hacer \n");
        printf("1. Hacer un personajes\n");
        printf("2. Ver los personajes\n");
        printf("3. Salir del programa\n");
        scanf("%c", &opcion);

        switch(opcion){
            case '1':
                printf("Nombre: \n");
                scanf("%s", &nombreP);
                printf("Fuerza: \n");
                scanf("%d",&fuerza);
                printf("Salud: \n");
                scanf("%d", &salud);
                printf("Altura: \n");
                scanf("%d", &altura);
                
            break;

            case '2':

            break;

            case '3':

            break;

            default:
                printf("Adios!! :)\n");
            break;
        }
    } while (opcion != '3');
    
}