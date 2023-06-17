#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main(){
    char arregloBase[35][6][30]={
        {{'1'},{"Anécdota de un día"},{"8.5"},{"3.18"},{"Tahoma black"},{"2.1"}},
        {{'2'},{"Burros Blancos"},{"7.5"},{"0.74"},{"Agency"},{"117"}},
        {{'3'},{"Cien años y uno mas"},{"6.5"},{"0.3"},{"Abscissa"},{"33"}},
        {{'4'},{"Diamantes y dados"},{"5.5"},{"0.14"},{"HP Simplified"},{"56"}},
        {{'5'},{"El avestrus"},{"4.5"},{"0.58"},{"Arial"},{"12"}},
        {{'6'},{"El cuento"},{"3.5"},{"0.46"},{"Calibri"},{"28"}},
        {{'7'},{"Elefantes"},{"2.5"},{"1.46"},{"Impact"},{"71"}},
        {{'8'},{"Fiestas "},{"1.5"},{"1.9"},{"alanis hand"},{"100"}},
        {{'9'},{"Gatoman"},{"0.5"},{"2.34"},{"Jasmine UPC"},{"66"}},
        {{"10"},{"Hipopotamos en su habitat"},{"0.5"},{"2.78"},{"Latha"},{"157"}},
        {{"11"},{"Italia, un nuevo mundo"},{"1.5"},{"3.22"},{"Kaiti"},{"116"}},
        {{"12"},{"Juanacatlan, pueblo magico"},{"2.5"},{"3.66"},{"Nyala"},{"95"}},
        {{"13"},{"Kids, where are them?"},{"3.5"},{"4.1"},{"Verdana"},{"55"}},
        {{"14"},{"La niña"},{"4.5"},{"4.54"},{"Tahoma"},{"200"}},
        {{"15"},{"Metafisica"},{"5.5"},{"4.98"},{"Modern"},{"150"}},
        {{"16"},{"Nuevos horizontes"},{"6.5"},{"5.42"},{"Univers"},{"30"}},
        {{"17"},{"Osos polares"},{"7.5"},{"5.86"},{"Yu Gothic"},{"84"}},
        {{"18"},{"Pato Hood"},{"8.5"},{"6.3"},{"Ravie"},{"72"}},
        {{"19"},{"Poblaciones vulnerables"},{"9.5"},{"6.74"},{"OCRB"},{"81"}},
        {{"20"},{"Quo duo"},{"10.5"},{"7.18"},{"Selawik"},{"111"}},
        {{"21"},{"Robin Hood"},{"11.5"},{"7.62"},{"Perpetua"},{"93"}},
        {{"22"},{"Significado de la vida"},{"12.5"},{"8.06"},{"Times"},{"81"}},
        {{"23"},{"Soberanos"},{"13.5"},{"8.5"},{"Webdings"},{"139"}},
        {{"24"},{"Trasatlantico"},{"14.5"},{"8.94"},{"Sweet Pea"},{"188"}},
        {{"25"},{"Trasportes en el futuro"},{"15.5"},{"9.38"},{"Bell MT"},{"125"}},
        {{"26"},{"Trotamundos"},{"16.5"},{"9.82"},{"Ebrima"},{"132"}},
        {{"27"},{"Uvas para el vino"},{"17.5"},{"10.26"},{"Mangal"},{"100"}},
        {{"28"},{"Verduras y frutas"},{"18.5"},{"10.7"},{"Cambria"},{"165"}},
        {{"29"},{"Viajando ando"},{"19.5"},{"11.14"},{"Dotum"},{"20"}},
        {{"30"},{"Walter Cross, ¿Quién fue?"},{"20.5"},{"11.58"},{"Papyrus"},{"62"}},
        {{"31"},{"Xcaret, un lugar magico"},{"21.5"},{"12.02"},{"Arial Black"},{"59"}},
        {{"32"},{"Yardas"},{"22.5"},{"12.46"},{"Georgia"},{"78"}},
        {{"33"},{"Zapato Viejo"},{"23.5"},{"12.9"},{"French script"},{"15"}},
        {{"34"},{"-"},{"-"},{"-"},{"-"},{"-"}},
        {{"35"},{"-"},{"-"},{"-"},{"-"},{"-"}}
    };
    
    //Procedimiento de arreglos uwu
    char arregloID[35][2][30];
    char caracteristicasLibro[35][5][30];

    for(int i=0; i <=34;i++){
        strcpy(arregloID[i][0], arregloBase[i][0]);
        strcpy(arregloID[i][1], arregloBase[i][1]);
    }
    for(int i=0; i <=34;i++){
        strcpy(caracteristicasLibro[i][0], arregloBase[i][0]);
        strcpy(caracteristicasLibro[i][1], arregloBase[i][2]);
        strcpy(caracteristicasLibro[i][2], arregloBase[i][3]);
        strcpy(caracteristicasLibro[i][3], arregloBase[i][4]);
        strcpy(caracteristicasLibro[i][4], arregloBase[i][5]);
    }
    //Menu principal
    int seleccion = 0;
    printf("Bienvenido a su liberia de confianza\n");
    do{ //Esto pemitira seguir ejecutando el programa y poder ver las modificaciones
        printf("Por favor, ingrese el numero del menu de la accion que quiera realizar:\n");
        printf("1.Modificar datos de un libro\n");
        printf("2.Visualizar la lista de libros\n");
        printf("3.Terminar programa\n");
        scanf("%d",&seleccion);
        fflush(stdin);
        switch(seleccion){
            case 1:
                for(int i =0; i<=34; i++){
                  
                    printf("ID: %s Titulo: %s\n", arregloID[i][0], arregloID[i][1]);
                }        
                int libroMod;
                printf("ID del libro a modificar:\b");
                scanf("%d", &libroMod);
                int cambiar;
                printf("¿Que quieres cambiar?\n");
                printf("1. Titulo\n");
                printf("2. Alto\n");
                printf("3. Ancho\n");
                printf("4. Fuente\n");
                printf("5. Precio\n");
                scanf("%d", &cambiar);
                char modificacion[50];
                switch(cambiar){
                    case 1:
                        printf("Escribe el titulo nuevo: \n");
                        scanf(" %[^\n]s", modificacion);
                        strcpy(arregloID[libroMod-1][1], modificacion);
                        printf("Cambio realizado con exito!!! uwu\n");
                        break;
                    case 2:
                        printf("Escribe el alto nuevo: \n");
                        scanf(" %[^\n]s", modificacion);
                        strcpy(caracteristicasLibro[libroMod-1][1], modificacion);
                        printf("Cambio realizado con exito!!! uwu\n");
                        break;
                    case 3:
                        printf("Escribe el ancho nuevo: \n");
                        scanf(" %[^\n]s", modificacion);
                        strcpy(caracteristicasLibro[libroMod-1][1], modificacion);
                        printf("Cambio realizado con exito!!! uwu\n");
                        break;
                    case 4:
                        printf("Escribe la fuente nueva: \n");
                        scanf(" %[^\n]s", modificacion);
                        strcpy(caracteristicasLibro[libroMod-1][1], modificacion);
                        printf("Cambio realizado con exito!!! uwu\n");
                        break;
                    case 5:
                        printf("Escribe el precio nuevo: \n");
                        scanf(" %[^\n]s", modificacion);
                        strcpy(caracteristicasLibro[libroMod-1][1], modificacion);
                        printf("Cambio realizado con exito!!! uwu\n");
                        break;
                }
                break;

            case 2:
                for(int i=0; i<=34; i++){
                    printf("ID: %s Titulo: %s\n", arregloID[i][0], arregloID[i][1]);
                    printf("Alto: %s  Ancho: %s\n", caracteristicasLibro[i][1], caracteristicasLibro[i][2]);
                    printf("Fuente: %s  Precio: %s\n", caracteristicasLibro[i][3], caracteristicasLibro[i][4]);
                    printf("\n");
                }
                break;
        
            case 3:
                exit(-1);
                break;
        
            default:
                printf("Valor incorrecto, ingrese un valor valido\n");
                break;
        }
    }while (seleccion != 3);
}