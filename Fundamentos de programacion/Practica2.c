#include<stdio.h>
#include<math.h> //Solo se ocupa una vez, para un ejercicio

int main(){

    putchar('B');
    putchar('i');
    putchar('e');
    putchar('n');
    putchar('v');
    putchar('e');
    putchar('n');
    putchar('i');
    putchar('d');
    putchar('o');
    putchar(32);
    putchar('a');
    putchar('l');
    putchar(32);
    putchar('I');
    putchar('P');
    putchar('N');
    putchar('-');
    putchar('E');
    putchar('S');
    putchar('C');
    putchar('O');
    putchar('M');
    putchar('\n');
    printf("\n");

    float area = 77.8;
    float radio = (area/3.14);
    float box = radio/2;
    float i = 0;
    while (box != i){
        i = box;
        box=(area/i+i) / 2;
    }
    printf("El radio de un circulo de 77.8 cm de area es %f cm \n", box);
    printf("\n");

    long long numeroLargo = 99199919991;
    float radical = numeroLargo / 2;
    float j = 0;
    while (radical != j)
    {
        j = radical;
        radical = (numeroLargo / j +j ) / 2;
    }
    int parteEntera;
    parteEntera = (int) radical;
    printf("La parte entera de la raiz de 99199919991 es %i \n",parteEntera);
    printf("\n");

    double disSol = 150000000;
    double disLunasol = 149615600;
    double resultado = 0;
    resultado = disSol + disLunasol;
    printf("La suma de las distancias Luna-sol y Sol-tierra es %f Km\n", resultado);
    double resMetros = resultado * 1000;
    printf("En metros es: %f m\n",resMetros);
    double resCentim = resultado * 100000;
    printf("En centimetros es: %f cm\n");
    printf("\n");


    printf("El tamaño de datos primitivos es el siguiente: \n");
    printf("El tamaño de int es: %u bits\n", sizeof(int));
    printf("El tamaño de char es: %u bits\n", sizeof(char));
    printf("El tamaño de float es: %u bits\n", sizeof(float));
    printf("El tamaño de double es: %u bits\n", sizeof(double));
    printf("El tamaño de long es: %u bits\n", sizeof(long));
    printf("El tamaño de short es: %u bits\n", sizeof(short));
    printf("\n");

    printf("Valores con signo y sin signo \n");
    unsigned int  a = 456;
    signed int a1 = -456;
    unsigned long long int b = 77777999999, c = 100000000000000, d =333333333333;
    signed int b1= -100; //-1x10^56
    signed int c1= -600; //-6x10^-79
    double e= 0.55, f=-0.55;
    double g= -0.00000000005;
    printf("Los sin signo son los siguientes: %i, %ld, %ld, %ld, %f \n", a, b, c, d, e);
    printf("Los numeros con signo son: %i, %i, %i, %f, %f \n", a1, b1, c1, f, g);
    printf("\n");

    printf("Dibujos de figuras con asteriscos \n");
    //triangulo
    printf("   *\n");
    printf("  ***\n");
    printf(" *****\n");
    printf("*******\n");
    printf("\n");
    //Elipse
    printf("  ***\n");
    printf(" *   *\n");
    printf("*     *\n");
    printf("*     *\n");
    printf("*     *\n");
    printf(" *   *\n");
    printf("  ***\n");
    printf("\n");
    //romboide
    printf("****\n");
    printf(" ****\n");
    printf("  ****\n");
    printf("   ****\n");
    printf("\n");
    //Trapecio
    printf("   ***\n");
    printf("  *   *\n");
    printf(" *     *\n");
    printf("*********\n");
    printf("\n");
    //Circulo
    printf(" ****\n");
    printf("******\n");
    printf(" ****\n");
    printf("\n");
    printf("\n");

    printf("Conversion de valores usando operadores \n");
    //Resultado b (Pendiente)
    //Resultado 32
    int mil24= 1024;
    int res = mil24>>5 ;
    printf ("%d", res);
    printf("\n");
    res = 0;
    //Esperando 2048
    int quin12 = 512;
    int res1 = quin12<<2;
    printf("%d", res1);
    printf("\n");
    //Esperando 1
    int seis5556 =65556;
    int res2 = seis5556/seis5556;
    printf("%d", res2);
    printf("\n");
    //Esperando 12. Unica vez que se usa math
    int unoCuatro4 = 144;
    int res12 = sqrt(unoCuatro4);
    printf("%d", res12);
    printf("\n");
    //Esperando 25.5
    float cinco1 = 5.1;
    float res3= cinco1 * 5;
    printf("%f",res3);
    printf("\n");
    //Esperando 7.77
    float siete77 = 7.7;
    float res4 = siete77 + 0.07;
    printf("%f",res4);
    printf("\n");
    //Esperando 1
    int sieteOcho91 = 7891;
    int res5 = sieteOcho91 - 7890;
    printf("%d",res5);
    printf("\n");
    //Esperando 90
    int ochoNueve = 89;
    int res6 = ++ochoNueve;
    printf("%d", res6);
    printf("\n");
    //Esperando 64
    char arroba = '@';
    printf("%i", arroba);
    printf("\n");
    printf("\n");

    printf("Maximos valores en datos primitivos con y sin signo \n");
    unsigned int maxInt= 2147483647;
    signed int maxSignint = 1075778681; 
    printf("El maximo numero que puede guardar int son: sin signo %i y con signo %i \n", maxInt, maxSignint);
    signed char maxChar = '';
    unsigned char maxSigchar = '';
    printf("El maximo valor de char con signo es: %i y sin el %i \n", maxChar, maxSigchar);
    unsigned long maxLong = 1974300914;
    signed long maxSigLong = 2147483647;
    printf("El maximo valor de un long es %ld con signo, y sin el es de %ld \n", maxSigLong, maxLong);
    double maxDouble = 410171765755391810000000000000000000000000000000000000000000000000000000000000000.000000;
    printf("El valor maximo de double es: %f \n", maxDouble);



    return 0;
}