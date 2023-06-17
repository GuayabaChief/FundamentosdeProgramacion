#include <stdio.h>

char cadena[95] = "Un puntero a un apuntador es un puntero doble.";
char cadenaDos[95]; //cadena donde se debe copiar la cadena 1 

int main(void){
    char* apuntadorCadena1=cadena;//Declarar valores del apuntador desde un principio 
    char* apuntadorCadena2=&cadenaDos[0];//Error en el * en la sintaxis de inicializacion
    printf("Se imprime la cadena original: ");//Cambiar forma de impresion y añadir un espacio para que no se vea mal
    printf("%c \n", apuntadorCadena1); //Mala impresion del contenido de apuntadorCadena1 
    while(*apuntadorCadena1 != '\0') {//Faltaba el * en el apuntador
        *apuntadorCadena2++ = *apuntadorCadena1++;//Faltaba el * en los apuntadores 
        printf("La localidad de memoria que está copiando el dato es: %c hacia %c\n", (void *)&apuntadorCadena1, (void *)&apuntadorCadena2);//Faltaba el & en los arreglos
    }
    *apuntadorCadena1 = '\0';//Faltaba el * en el apuntador
    puts("Se imprime el resultado de la copia: ");//agregar un espacio 
    puts(cadenaDos); 
    return 0;
}