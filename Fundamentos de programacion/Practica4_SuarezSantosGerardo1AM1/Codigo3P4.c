#include <stdio.h>

int main(){
    int numero=1;

    while(numero != 0){
        printf("Ingrese un numero positivo \n");
        scanf("%d", &numero);
        if(numero>0){
            int resultado = 1;
            for (int i =1; i<= numero;i++){
                resultado *= i;
            }
        printf("El factorial es: %d \n", resultado);
        }
    }
}