#include <stdio.h>

int main(){

    int precio = 0;
    double total = 0;

    printf("¿Cuanto cuesta el producto?\n");
    scanf("%d", &precio);
    fflush(stdin);
    if(precio<4000){
        total = ((double)precio*0.05)+(double)precio; 
    }
    else{
        total = ((double)precio*0.16)+(double)precio;
    }
    printf("El precio nuevo es: %f", total);
}