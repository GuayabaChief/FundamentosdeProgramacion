#include<stdio.h>
#include<math.h>

void main(){
    int z = 0;
    double total = 0;

    printf("Ingresa el valor de z: \n");
    scanf("%d", &z);
    fflush(stdin);
    if(z >= 0 && z <= 9){
        total = (1/(double)z)-((double)z/2);
    }
        else if(z<0){
            total = 0;
        }
            else if (z>9 && z<125){
                total = pow((double)z,3) + pow((double)z,5) + pow((double)z,9);
            }else{
                total= (double)z/3;
            }
    printf("El resultado de la funcion es: %f", total);
}