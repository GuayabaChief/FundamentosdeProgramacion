#include "p10.h"
#include <string.h>
#define TAM 5


void limpiarTabla(struct Nodo** tabla, char *path, int index){
  for(int i = 0; i < index; i++){
    free(tabla[i]);
  }
  free(tabla);
  remove(path);
}

// @param index -> Total de filas
void guardarTablaEnArchivo(struct Nodo** tabla, char *path, int index){
  FILE* archivo = fopen(path, "w+");

  int comparator(const void *p, const void *q) 
  {
    int l = strlen(((struct Nodo *)p)->cadena);
    int r = strlen(((struct Nodo *)q)->cadena); 
    return (l - r);
  }

  qsort(tabla, sizeof(tabla)/sizeof(tabla[0]), sizeof(struct Nodo*), comparator);
  
  for(int i = 0; i < index; i++){
    fprintf(archivo, "%d", i + 1);
    fputc('\t', archivo);
    fputs("| Cadena: ", archivo);
    fprintf(archivo, "%s", tabla[i]->cadena);
    fputc('\t', archivo);
    fputs("| Binario: ", archivo);
    fprintf(archivo, "%s", tabla[i]->binario);
    fputc('\t', archivo);
    fputs("| Ascii: ", archivo);
    fprintf(archivo, "%s", tabla[i]->ascii);
    fputc('\t', archivo);
    fputs("| Caracter: ", archivo);
    fprintf(archivo, "%s", tabla[i]->caracter);
    fputc('\t', archivo);
    fputs("| Hexadecimal: ", archivo);
    fprintf(archivo, "%x", tabla[i]->hexa);
    fputc('\n', archivo);
  }
  fclose(archivo);
}

void imprimirTablaDesdeArchivo(struct Nodo** tabla, char *path){
  FILE* archivo = fopen(path, "r");
  if(archivo == NULL){
    printf("No se pudo leer el archivo \n");
    exit(1);
  }
  while(!feof(archivo)){
    char *cadenaLectura = (char*)calloc(100, sizeof(char));
    fgets(cadenaLectura, 100, archivo);
    printf("%s", cadenaLectura);
  }
  fclose(archivo);
}

void iniciarOperaciones(int argc, char** argv){
  char* path = "C:\\Users\\Emmanuel\\Documents\\Main\\Escuela\\IPN\\Fundamentos_Programacion\\practica10\\tabla.txt";
  int index = 0;
  int opc = 0;

  struct Nodo **tabla = (struct Nodo**)calloc(1, sizeof(struct Nodo*));
  if(tabla == NULL){
    printf("No hay memoria \n");
    exit(1);
  } 

  for(int i = 0; i < TAM; i++){
    tabla[i] = (struct Nodo*)calloc(1, sizeof(struct Nodo));
    if(tabla[i] == NULL){
      printf("No hay memoria \n");
    }
  }

  
  do{
    struct Nodo *node = (struct Nodo*)malloc(sizeof(struct Nodo));
    node->cadena = (char*)malloc(sizeof(char));
    node->binario = (char*)malloc(sizeof(char));
    node->ascii = (char*)malloc(sizeof(char));
    node->caracter = (char*)malloc(sizeof(char));
    node->hexa = (char*)malloc(sizeof(char));
    
    printf("--MENU-- \n");
    printf("1. Agregar cadena \n");
    printf("2. Ver tabla \n");
    printf("3. Borrar tabla \n");
    printf("4. Salir \n");
    scanf("%d", &opc);
    switch(opc){
      case 1: ;
        tabla[index] = (struct Nodo*)realloc(tabla[index], sizeof(struct Nodo) + index);
        char *str;
        char car;
        int iAsc;
        str = (char*)malloc(sizeof(char));
        printf("Agregar cadena: \n");
        scanf("%s", str);        
        iAsc = atoi(str);
        car = str[0];
        itoa(iAsc, node->binario, 2);
        strcpy(node->cadena, str);
        strcpy(node->hexa, str);
        strcpy(node->caracter, &car);

        // node->caracter = car;
        int asc = car;
        itoa(asc, node->ascii, 10);

        // TODO: Falta el hexadecimal
        
        tabla[index] = node;
        index++;
        system("clear");
        break;

      case 2:
        printf("-- Tabla -- \n");       
        guardarTablaEnArchivo(tabla, path, index);
        imprimirTablaDesdeArchivo(tabla, path);  
        
        printf("\n");
        break;

      case 3:
        printf("Desea borrar la tabla? \n");
        printf("1- Si | 2- No \n");
        int opc2;
        scanf("%d", &opc2);
        if(opc2 == 1){
          limpiarTabla(tabla, path, index);
        }
        opc = 4;
        break;
    }

  }while(opc != 4);
}