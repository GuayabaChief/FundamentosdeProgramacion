#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdint.h>
#include<math.h>

typedef struct{
    uint32_t tamArchivo;
    uint16_t reserva1;
    uint16_t reserva2;
    uint32_t offSet;
}CabeceraArchivo;

typedef struct{
    uint32_t tamCabecera;
    uint32_t ancho;
    uint32_t alto;
    uint16_t planos;
    uint16_t bpp; 
    uint32_t estadoCompresion;
    uint32_t tamImagen;
    uint32_t resX;
    uint32_t resY;
    uint32_t rangoColores;
    uint32_t paletaColorImportante;
}CabeceraImagen;