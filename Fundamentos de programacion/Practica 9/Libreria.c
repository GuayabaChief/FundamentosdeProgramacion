#include<Libreria.h>
#include<stdio.h>
#include<stdlib.h>

Libro libro[33];
Persona guest;

char inventario[33][7][30]={
    {
          {"1"},
          {"Anecdota de un dia"},
          {"8.5"},
          {"3.18"},
          {"Tahoma Black"},
          {"2.1"},
          {"5"}
      },
      {
          {"2"},
          {"Burros Blancos"},
          {"7.5"},
          {"0.74"},
          {"Agency"},
          {"164"},
          {"3"}
      },
      {
          {"3"},
          {"Cien años y uno mas"},
          {"6.5"},
          {"0.3"},
          {"Abscissa"},
          {"130"},
          {"7"}
      },
      {
          {"4"},
          {"Diamantes y dados"},
          {"5.5"},
          {"0.14"},
          {"HP Simplified"},
          {"173"},
          {"8"}
      },
      {
          {"5"},
          {"El avestrus"},
          {"4.5"},
          {"0.58"},
          {"Arial"},
          {"29"},
          {"5"}
      },
      {
          {"6"},
          {"El cuento"},
          {"3.5"},
          {"0.46"},
          {"Calibri"},
          {"118"},
          {"5"}
      },
      {
          {"7"},
          {"Elefantes"},
          {"2.5"},
          {"1.46"},
          {"Impact"},
          {"35"},
          {"9"}
      },
      {
          {"8"},
          {"Fiestas"},
          {"1.5"},
          {"1.9"},
          {"Alanis Hand"},
          {"160"},
          {"19"}
      },
      {
          {"9"},
          {"Gatoman"},
          {"0.5"},
          {"2.34"},
          {"Jasmine UPC"},
          {"26"},
          {"12"}
      },
      {
          {"10"},
          {"Hipopotamos en su habitat"},
          {"0.5"},
          {"2.34"},
          {"Latha"},
          {"150"},
          {"8"}
      },
      {
          {"11"},
          {"Italia, un nuevo mundo"},
          {"1.5"},
          {"3.22"},
          {"Kaiti"},
          {"21"},
          {"68"}
      },
      {
          {"12"},
          {"Juanacatlan, pueblo magico"},
          {"2.5"},
          {"3.66"},
          {"Nyala"},
          {"166"},
          {"18"}
      },
      {
          {"13"},
          {"Kids, where are them?"},
          {"3.5"},
          {"4.1"},
          {"Verdana"},
          {"136"},
          {"39"}
      },
      {
          {"14"},
          {"La niña"},
          {"4.5"},
          {"4.54"},
          {"Tahoma"},
          {"70"},
          {"28"}
      },
      {
          {"15"},
          {"Metafisica"},
          {"5.5"},
          {"4.98"},
          {"Modern"},
          {"164"},
          {"4"}
      },
      {
          {"16"},
          {"Nuevos horizontes"},
          {"6.5"},
          {"5.42"},
          {"Univers"},
          {"35"},
          {"84"}
      },
      {
          {"17"},
          {"Osos polares"},
          {"7.5"},
          {"5.86"},
          {"Yu Gothic"},
          {"136"},
          {"90"}
      },
      {
          {"18"},
          {"Pato Hood"},
          {"8.5"},
          {"6.3"},
          {"Ravie"},
          {"82"},
          {"14"}
      },
      {
          {"19"},
          {"Poblaciones vulnerables"},
          {"9.5"},
          {"6.74"},
          {"OCRB"},
          {"44"},
          {"82"}
      },
      {
          {"20"},
          {"Quo duo"},
          {"10.5"},
          {"7.18"},
          {"Selawik"},
          {"71"},
          {"43"}
      },
      {
          {"21"},
          {"Robin Hood"},
          {"11.5"},
          {"7.62"},
          {"Perpetua"},
          {"92"},
          {"83"}
      },
      {
          {"22"},
          {"Significado de la vida"},
          {"12.5"},
          {"8.06"},
          {"Times"},
          {"61"},
          {"18"}
      },
      {
          {"23"},
          {"Soberanos"},
          {"13.5"},
          {"8.5"},
          {"Webdings"},
          {"51"},
          {"87"}
      },
      {
          {"24"},
          {"Trasatlantico"},
          {"14.5"},
          {"8.94"},
          {"Sweet Pea"},
          {"130"},
          {"173"}
      },
      {
          {"25"},
          {"Transportes en el futuro"},
          {"15.5"},
          {"9.38"},
          {"Bell MT"},
          {"137"},
          {"18"}
      },
      {
          {"26"},
          {"Trotamundos"},
          {"16.5"},
          {"9.82"},
          {"Ebrima"},
          {"44"},
          {"73"}
      },
      {
          {"27"},
          {"Uvas para el vino"},
          {"17.5"},
          {"10.26"},
          {"Mangal"},
          {"150"},
          {"36"}
      },
      {
          {"28"},
          {"Verduas y frutas"},
          {"18.5"},
          {"10.7"},
          {"Camria"},
          {"125"},
          {"36"}
      },
      {
          {"29"},
          {"Viajando ando"},
          {"19.5"},
          {"11.14"},
          {"Dotum"},
          {"79"},
          {"73"}
      },
      {
          {"30"},
          {"Walter Cross, Quien fue?"},
          {"20.5"},
          {"11.58"},
          {"Papyrus"},
          {"25"},
          {"73"}
      },
      {
          {"31"},
          {"Xcaret, un lugar magico"},
          {"21.5"},
          {"12.02"},
          {"Arial Black"},
          {"104"},
          {"37"}
      },
      {
          {"32"},
          {"Yardas"},
          {"22.5"},
          {"12.46"},
          {"Georgia"},
          {"162"},
          {"91"}
      },
      {
          {"33"},
          {"Zapato Viejo"},
          {"23.5"},
          {"12.9"},
          {"French Script"},
          {"135"},
          {"18"}
      },
};

void Arreglo (Libro libro[33], char titulo[50], float altura, float anchura, char fuente[20], int precio, int disponibilidad, int posicion){
    int id = posicion+1;
    libro[posicion].numlibro= id;
    strcpy(libro[posicion].titulo, titulo);
    libro[posicion].altura = altura;
    libro[posicion].anchura = anchura;
    strcpy(libro[posicion].fuente, fuente);
    libro[posicion].precio= precio;
    libro[posicion].disponibilidad= disponibilidad;
}

void Registro(Persona*inv, char nombre[50], char apellido[50], char edad[4], char dinero[50]){
    strcpy(inv->nombre, nombre);
    strcpy(inv->apellido, apellido);
    strcpy(inv->edad, edad);
    strcpy(inv->dinero, dinero);
}

int Asignacion(Persona*inv, Libro libro[], int numlibro, int disponibilidad, int veces, int cant){
    if(numlibro > 33 || numlibro < 0){
        printf("Libro no encontrado!! \n");
    }else{
        char numbook[8];
        char vecesC[2];
        sprintf(numbook, "%d", numlibro);
        sprintf(vecesC, "%d", cant);
        printf("Libro encontrado!!! UwU\n");
        printf("ID: %d     Titulo: %s \n", libro[numlibro-1].numlibro, libro[numlibro].titulo);
        if(cant <= libro[numlibro-1].disponibilidad){
            libro[numlibro-1].disponibilidad =libro[numlibro].disponibilidad - cant;
            strcpy(inv->libros[veces][0], numbook);
            strcpy(inv->libros[veces][1], libro[numlibro-1].titulo);
            strcpy(inv->libros[veces][2], vecesC);
            printf("%s libros asignados a %s %s\n", inv->libros[veces][2], inv->nombre, inv->apellido);
            printf("Queda(n) %d copia(s) del libro '%s' \n", libro[numlibro-1].disponibilidad, libro[numlibro-1].titulo);
            return 1;
        }else{
            printf("El libro esta limitado a %d copias \n", libro[numlibro-1].disponibilidad);
            return 0;
        }
    }
}

void Contenido (Libro libro [33]){
    for(int i=0; i < 33; i++){
        printf("Id: %d   Titulo: %s   Disponibles: %d \n", libro[i].numlibro, libro[i].titulo, libro[i].disponibilidad);
        printf("Alto: %0.2f   Ancho: %0.2f \n", libro[i].altura, libro[i].anchura);
        printf("Fuente: %s    Precio: %d \n", libro[i].fuente, libro[i].precio);
    }
}

void ImpUsuario (Persona p){
    printf("Nombre: %s %s \n", p.nombre, p.apellido);
  printf("Edad: %s \n", p.edad);
  printf("Donativo: %s \n", p.dinero);
  printf("Libros pedidos: \n");
  for(int i = 0; i < 10; i++){
    printf("Id: %s   Titulo: %s   Copias: %s \n", p.libros[i][0] + 1, p.libros[i][1], p.libros[i][2]);
  }
}

void start (int arreg, char**arregv){
    for (int i = 0; i < 33; i++){
        char titulo[50];
        char fuente[20];
        strcpy(titulo, inventario[i][1]);
        float alto = atof(inventario[i][2]);
        float ancho = atof(inventario[i][3]);
        strcpy(fuente, inventario[i][4]);
        int precio = atoi(inventario[i][5]);
        int cantidad = atoi(inventario[i][6]);
        Arreglo(libro, titulo, alto, ancho, fuente, precio, cantidad, i);
    };

    Registro(&guest, arregv[1], arregv[2], arregv[3], arregv[4]);
    int opcion=0;
    int numPreg=0;
    int quask=0;
    int veces=0;

    do{
        printf("Ingrese la opcion que desea hacer: \n");
        printf("1. Mirar libros. \n");
        printf("2. Ver usuarios. \n");
        printf("3. Solicitar libro. \n");
        printf("4. Salir del programa. \n");
        scan("%d", &opcion);
        printf("\n");
        switch(opcion){
            case '1':
                printf("Inventario: \n");
                Contenido(libro);
                printf("\n");
            break;
            case '2':
                printf("Usuarios: \n");
                ImpUsuario(guest);
                printf("\n");
            break;
            case '3':
                if(veces != 10){
                    printf("Solicitar libro: \n");
                    printf("Id del Libro: \n");
                    scanf("%d", &numPreg);
                    printf("Cantidad de libros a pedir: \n");
                    scanf("%d", &quask);
                    int val = asignarLibrO(&guest, libro, numPreg, quask, veces);
                    if(val == 1){
                        veces++;
                    }
                } else{
                    printf("La cantidad maxima de libros por pedir es 10");
                } 
            break;
            case '4':
                printf("Adios!!!"); 
            break;

            default:
                printf("Incorrecto, intentalo de nuevo\n"); 
            break;
        }
    }while(opcion !=4);
}