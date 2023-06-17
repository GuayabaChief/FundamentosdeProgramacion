#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdint.h>

//Header de la imagen: Metadatos de la misma
typedef struct{
    uint32_t tamArchivo;
    uint16_t reserva1;
    uint16_t reserva2;
    uint32_t offSet; // Se refiere a la posicion del primer pixel
}CabeceraArchivo;

//Datos de la imagen
typedef struct{
    uint32_t tamCabecera;
    uint32_t ancho;
    uint32_t alto;
    uint16_t planos;
    uint16_t bpp; // bits por pixel
    uint32_t estadoCompresion;
    uint32_t tamImagen;
    uint32_t resX;  //bits por metro en ancho(ejex)
    uint32_t resY;  //bits por metro en alto(eje Y)
    uint32_t rangoColores;
    uint32_t paletaColorImportante;
}CabeceraImagen;

void imprimeCabeceraArchivo(CabeceraArchivo headerFile){
    //Se imprimen los atributos del Header de la imagen
    printf("Tamaño del archivo :%d \n",headerFile.tamArchivo);
    printf("Reserva1 del archivo :%d \n",headerFile.reserva1);
    printf("Reserva2 del archivo :%d \n",headerFile.reserva2);
    printf("offSet del archivo :%d \n",headerFile.offSet);
}

void imprimeCabeceraImagen(CabeceraImagen headerImage){
    //Se imprimen los datos de la imagen
    printf("Tamaño de la cabecera de la imagen :%d \n",headerImage.tamCabecera);
    printf("Alto la imagen :%d \n",headerImage.alto);
    printf("Ancho de la imagen :%d \n",headerImage.ancho);
    printf("Bits por pixel de la imagen :%d \n",headerImage.bpp);
    printf("Tamaño de la imagen :%d \n",headerImage.tamImagen);
    printf("Planos de la imagen :%d \n",headerImage.planos);
}
//Se hace un arreglo unidimensional con los pixeles de la imagen
/**
 * @brief 
 * 
 * @param fileName  Nombre del archivo imagen que se va abrir
 * @param headerImage Variable vacía o nula donde se guardara el header de la imagen (Paso por referencia)
 * @return unsigned* Un arreglo unidimensional con los pixeles
 */
unsigned char* aperturaImagen(char* rutaArchivoImagen, CabeceraImagen* headerImage){
    FILE* archivoImagen=fopen(rutaArchivoImagen, "r"); //Apuntador con la ruta imagen, abierta en modo lectura
    if(archivoImagen==NULL){
        puts("No se encontro la imagen o no se pudo abrir");
        return NULL; //Revisamos si la ruta esta bien establecida
    }
    CabeceraArchivo headerFile;
    unsigned char* matrizPixeles; //Variable unidimensional que lleva los datos de pixeles
    int typeImage=0;
    //Leer el tipo de imagen directo del archivo
    fread(&typeImage,sizeof(uint16_t),1,archivoImagen);
    if(typeImage!=0x4D42){ //Asi se denomina el header BM en hexadecimal
        printf("typrImage: %p\n", typeImage);
        puts("No es imagen BMP");
        return NULL;
    }
    //Lectura de las cabeceras, primero se lee la de archivo
    fread(&headerFile, sizeof(CabeceraArchivo),1,archivoImagen);
    //Lectura de la cabecera de la imagen
    fread(headerImage,sizeof(CabeceraImagen),1,archivoImagen);

    //Se imprimen las cabeceras
    imprimeCabeceraArchivo(headerFile);
    imprimeCabeceraImagen(*headerImage);
    //Reserva memoria para guardar los pixeles de la imagen
    matrizPixeles=(unsigned char*) malloc(sizeof(char)*(headerImage->tamImagen));
    if(matrizPixeles==NULL){
        puts("No se pudo reservar memoria para la matriz de datos");//Se comprueba si hay memoria disponible
        fclose(archivoImagen);//Cerrar la imagen ya que queda abierta
        return NULL;
    }
    //Posicionar Cursor en el offset, para que se mueva y lea datos de la imagen, se cuenta desde el principio del archivo
    fseek(archivoImagen,headerFile.offSet,SEEK_SET);

    //Leer la matriz de la Imagen
    fread(matrizPixeles,sizeof(char)*(headerImage->tamImagen),1,archivoImagen);
    fclose(archivoImagen);
    return matrizPixeles;
}

void imprimirImagenEnFormaDeMatriz(unsigned char* vectorPixeles, CabeceraImagen headerImage){
    //variables para convertir y recorrer posiciones
    //posX y PosY son las posiciones en la matriz (nuevas por conversion)
    //ejeX y ejeY son variables que recorren la posiciones actuales de manera estrategica
    int posX, posY=0, ejeX, ejeY;
    for (ejeY=--headerImage.alto; ejeY>0; ejeY--){
        posX=0;
        for (ejeX=0; ejeX<headerImage.ancho; ejeX++){
            printf("[%d][%d]=%d\n", posY,posX,vectorPixeles[ejeX+ejeY*headerImage.ancho]);//Lee los pixeles matriz por matriz en columnas
            posX++;
        }
        posY++;
    }
}

void main(){
    char rutaArchivo[12]="porsche.bmp";
    CabeceraImagen imagenCabecera;
    unsigned char* datosPixeles=aperturaImagen(rutaArchivo,&imagenCabecera);
    imprimirImagenEnFormaDeMatriz(datosPixeles,imagenCabecera);
}