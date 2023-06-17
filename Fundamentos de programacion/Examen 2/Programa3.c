#include<stdio.h>
#include<string.h>
//Suarez Santos Gerardo 1AM1
void main(){
    int arreglo1[8];
    int pares[8];
    int impares[8];    

    printf("Ingresa los numeros uno por uno\n");
    int i;
    for(i = 0; i < 8; i++){
        int iterador;
        scanf("%d", &iterador);
        arreglo1[i] = iterador;
    }
    int lugar1=0;
    int lugar2=0;
    int k;
    for(k=0;k<8;k++){
        printf("%d", arreglo1[k]);
        if(arreglo1[k]%2==0){
            pares[lugar1]=arreglo1[k];
            lugar1++;
        }else{
            impares[lugar2]=arreglo1[k];
            lugar2++;
        }
    }
    int varx, vary, varz, cambio;
    varz=4;
    for(varx=1;varx<varz;varx++){
        vary=varx;
        cambio=pares[varx];
        while(vary>0 && cambio < pares[vary-1]){
            pares[vary] = pares[vary-1];
            vary=vary-1;
        }
        pares[vary]=cambio;
    }
    int a, b, c, crack;
    c=4;
    for(a=1;a<c;a++){
        b=a;
        crack=impares[a];
        while (b>0 && crack<impares[b-1]){
            impares[b]=impares[b-1];
            b=b-1;
        }
        impares[b]=crack;
    }
    printf("Pares: \n");
    for (int g=0; g<4;g++){
        printf("%d", pares[g]);
    }
    printf("Impares: \n");
    for (int r=0; r<4;r++){
        printf("%d", impares[r]);
    }
}