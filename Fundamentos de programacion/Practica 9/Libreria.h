#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct{
    int numlibro;
    char titulo[50];
    float altura;
    float anchura;
    char fuente[20];
    int precio;
    int disponibilidad;
}Libro;
typedef struct{
  char nombre[50];
  char apellido[50];
  char edad[4];
  char dinero[50];
  char libros[10][10][50];
}Persona;

void Arreglo(Libro libro[33], char titulo[50], float altura, float anchura, char fuente[20], int precio, int disponibilidad, int posicion);
void Registro(Persona* inv, char nombre[50], char apellido[50], char edad[4], char dinero[6]);
int Asignacion(Persona*inv, Libro libro[33], int numlibro, int disponibilidad, int veces, int cant);
void Contenido (Libro libro [33]);
void ImpUsuario (Persona p);
void start (int arreg, char**arregv);
