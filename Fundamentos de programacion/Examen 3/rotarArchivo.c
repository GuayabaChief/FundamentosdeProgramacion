#include"rotarArchivo.h"

unsigned char* aperturaImagen(char* rutaArchivoImagen, CabeceraImagen* headerImage){
    FILE* archivoImagen=fopen(rutaArchivoImagen, "r");
    if(archivoImagen==NULL){
        puts("No se encontro la imagen o no se pudo abrir");
        return NULL;
    }
    CabeceraArchivo headerFile;
    unsigned char* matrizPixeles;
    int typeImage=0;
    fread(&typeImage, sizeof(uint16_t),1,archivoImagen);
    if (typeImage!=0x4D42){
        printf("typeImage: %p\n", typeImage);
        puts("No es BMP");
        return NULL;
    }
    
}