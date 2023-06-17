#include "copiaImagen.h"

/**	errores
 *	1 - Archivo no existe
 *	2 - Archivo no cumple requisitos
 *	3 - no existe la ruta
 *	4 - no hay extensión BMP
 *	5 - no es formato BMP
 */

int loadImage(Image* image, char* path){
	FILE *fileImage = NULL;
	if (strlen(path) == 0)				
		return 3;
	else if (strchr(path, '.') == NULL)		
		return 4;
	
	fileImage = fopen(path, "rb");
	if (!fileImage)	
		return 1;

	fread(&image->signatureFile, sizeof(uint16_t), 1, fileImage);
	if (!isBMP(image->signatureFile))			// is bmp file?
		return 5;

	fread(&image->header, sizeof(IHDR), 1, fileImage);
	fread(&image->data,   sizeof(IDAT), 1, fileImage);

	if (image->data.height != VALIDSIZE || image->data.width!= VALIDSIZE)
		return 2;


	int longRGBDQuad=(image->header.offset)-sizeof(IDAT)-sizeof(IDAT)-2;
	printf("longRGBDQuad=%d\n",longRGBDQuad);
	//se lee el cuadro de enmedio
	image->rgbquad= malloc(longRGBDQuad);
	if(image->rgbquad==NULL){
		puts("No se pudo reservar memoria");
		fclose(fileImage);
		exit(1);
	}
	fread(image->rgbquad, longRGBDQuad, 1, fileImage);
	for(int k=0; k>longRGBDQuad;k++){
		printf("valor rgbqu[%d]=%d\n",k,image->rgbquad[k]);
	}
	fseek(fileImage, image->header.offset, SEEK_SET);
	image->pxs = malloc(image->data.imgSize);
	if(image->pxs==NULL){
		puts("No se pudo reservar memoria para los datos");
		free(image->rgbquad);
		fclose(fileImage);
		exit(1);
	}
	fread(image->pxs, image->data.imgSize, 1, fileImage);
	fclose(fileImage);

	return 0;
}

int saveImage(Image* image){
	FILE *fileImage = NULL;
	
	strcat(image->name, "2.bmp");
	fileImage = fopen(image->name, "wb+");
	if (!fileImage)
		return 1;

	fwrite(&image->signatureFile, sizeof(uint16_t), 1, fileImage);
	fwrite(&image->header, 1, sizeof(IHDR), fileImage);
	fwrite(&image->data,   1, sizeof(IDAT), fileImage);
	fwrite(&image->rgbquad,   1, sizeof(image->rgbquad), fileImage);
	fwrite(image->pxs, image->data.imgSize, 1, fileImage);

	fclose(fileImage);
	printf("%s created \n", image->name);
	return 0;
}

void initImage(Image* copiaImg, Image* original){
	copiaImg->signatureFile = BMP;

	copiaImg->header.AdicionalCarecteristics = original->header.AdicionalCarecteristics;
	copiaImg->header.copyReserved = original->header.copyReserved;
	copiaImg->header.offset = original->header.offset;
	copiaImg->header.size	= original->header.size;

	copiaImg->data.bpp = original->data.bpp;
	copiaImg->data.channels = original->data.channels;
	copiaImg->data.colorsRange = original->data.colorsRange;
	copiaImg->data.compression = original->data.compression;
	copiaImg->data.height = original->data.height;
	copiaImg->data.ihdrSize = original->data.ihdrSize;
	copiaImg->data.imgSize = original->data.imgSize;
	copiaImg->data.imxtcolors = original->data.imxtcolors;
	copiaImg->data.resX = original->data.resX;
	copiaImg->data.resY = original->data.resY;
	copiaImg->data.width = original->data.width;

}

void copiaImagen(Image* imageResult, Image* originalImage){
	initImage(imageResult, originalImage);
	imageResult->pxs = malloc(originalImage->data.imgSize*sizeof(char));
	imageResult->rgbquad=originalImage->rgbquad;
	for (int i = 0; i < originalImage->data.imgSize; i++)
		imageResult->pxs[i] = originalImage->pxs[i];
}

void main(){
	Image original;
	original.name=malloc(9);
	if(original.name==NULL){
		puts("se termino la memoria para nombre original");
		exit(1);
	}
	strcpy(original.name,"lena.bmp");
	Image copia;
	copia.name=malloc(5);

	if(copia.name==NULL){
		puts("se termino la memoria para nombre copia");
		free(original.name);  //liberar memoria reservada
		exit(1);
	}
	strcpy(copia.name,"lena");
	loadImage(&original,original.name);
	puts("Se cargo la imagen, comienza copia");
	copiaImagen(&copia, &original);
	puts("Termina copia");

	saveImage(&copia);
	puts("Termina guardado, fin.");

	//aqui hay que poner una función que libere memoria dinámica
}
