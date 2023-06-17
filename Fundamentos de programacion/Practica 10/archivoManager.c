#include"archivoManager.h"
#include<string.h>
#define TAM 5

void BorrarTabla(Datos** tabla, char *ruta, int indice){
    for(int i=0; i<indice;i++){
        free(tabla[i]);
    }
    free(tabla);
    remove(ruta);
}

//param index -> Filas en total
void almacenarTablaArchivo(Datos** tabla, char *ruta, int indice){
    FILE* archivo = fopen(ruta, "w+");

    int comparator (const void *p, const void *q)
    {
        int l =strlen(((struct Datos *)p)->cadena);
        int r =strlen(((struct Datos *)q)->cadena);
        return (l - r);
    }

    qsort(tabla, sizeof(tabla)/sizeof(tabla[0]), sizeof(Datos*), comparator);

    for(int i=0;i<indice;i++){
        fprintf(archivo, "%d", i +1);
        fputc('\t', archivo);
        fputs("Cadena: ", archivo);
        fprintf(archivo, "%s", tabla[i]->cadena);
        fputc('\t', archivo);
        fputs("Binario: ", archivo);
        fprintf(archivo, "%s", tabla[i]->binario);
        fputc('\t', archivo);
        fputs("ACSII: ", archivo);
        fprintf(archivo, "%s", tabla[i]->acsii);
        fputs("Caracter: ",archivo);
        fprintf(archivo, "%s", tabla[i]->caracter);
        fputc('\t', archivo);
        fputs("Hexadecimal: ", archivo);
        fprintf(archivo, "%x", tabla[i]->hexadecimal);
        fputc('\n', archivo);
    }
    fclose(archivo);
}

void impresiondeArchivo(Datos** tabla, char *ruta){
    FILE* archivo = fopen(ruta, "r");
    if(archivo==NULL){
        printf("No se pudo leer archivo \n");
        exit(1);
    }
    while(!feof(archivo)){
        char *cadenaLectura = (char*)calloc(100, sizeof(char));
        fgets(cadenaLectura, 100, archivo);
        printf("%s", cadenaLectura);
    }
    fclose(archivo);
}

void iniciarOperacion(int argc, char** argv){
    char* ruta = "D:\\Fundamentos de programacion\\Practica 10\\estructura.txt";
    int indice =0;
    int opcion =0;

    Datos **tabla = (Datos**)calloc(1, sizeof(struct Datos*));
    if(tabla==NULL){
        printf("No hay memoria suficiente\n");
        exit(1);
    }
    for(int i =0; i<TAM; i++){
        tabla[i] = (struct Datos*)calloc(1, sizeof(Datos));
        if (tabla[i] == NULL)
        {
            printf("No hay memoria suficiente \n");
        }
    }

    do{
        Datos *dato=(Datos*)malloc(sizeof(Datos));
        dato->cadena = (char*)malloc(sizeof(char));
        dato->binario = (char*)malloc(sizeof(char));
        dato->acsii = (char*)malloc(sizeof(char));
        dato->caracter = (char*)malloc(sizeof(char));
        dato->hexadecimal = (char*)malloc(sizeof(char));

        printf("Introduzca la opcion que desea: \n");
        printf("1. Agregar cadena \n");
        printf("2. Ver tabla \n");
        printf("3. Borrar tabla \n");
        printf("4. Salir \n");
        scanf("%d", &opcion);
        switch(opcion){
        case 1: ;
            tabla[indice] = (Datos*)realloc(tabla[indice], sizeof(Datos) + indice);
            char *str;
            char car;
            int iAsc;
            str = (char*)malloc(sizeof(char));
            printf("Agregar cadena: \n");
            scanf("%s", str);        
            iAsc = atoi(str);
            car = str[0];
            itoa(iAsc, dato->binario, 2);
            strcpy(dato->cadena, str);
            strcpy(dato->hexadecimal, str);
            strcpy(dato->caracter, &car);
            int asc = car;
            itoa(asc, dato->acsii, 10);
            
            tabla[indice] = dato;
            indice++;
            system("clear");
            break;

        case 2:
            printf("Tabla de Cadenas::\n");       
            guardarTablaEnArchivo(tabla, ruta, indice);
            imprimirTablaDesdeArchivo(tabla, ruta);  
            printf("\n");
            break;

        case 3:
            printf("Desea borrar la tabla? \n");
            printf("1. Si \n2. No \n");
            int opcion2;
            scanf("%d", &opcion2);
            if(opcion2 == 1){
            limpiarTabla(tabla, ruta, indice);
            }
            opcion = 4;
            break;
        }

    }while(opcion != 4);
}