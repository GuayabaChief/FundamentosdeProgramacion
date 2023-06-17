#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    char cadena;
    char* binario;
    char* acsii;
    char* caracter;
    char* hexadecimal;
}Datos;

void BorrarTabla(Datos** tabla, char *ruta, int indice);
void almacenarTablaArchivo(Datos** tabla, char *ruta, int indice);
void impresiondeArchivo(Datos** tabla, char *ruta);
void iniciarOperacion(int argc, char** argv);