#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Nodo{
  char *cadena;
  char *binario;
  char *ascii;
  char *caracter;
  char *hexa;
};

void iniciarOperaciones(int argc, char** argv);

void guardarTablaEnArchivo(struct Nodo** tabla, char *path, int index);

void imprimirTablaDesdeArchivo(struct Nodo** tabla ,char *path);

void limpiarTabla(struct Nodo** tabla, char *path, int index);

