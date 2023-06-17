#include<stdio.h>
#include<string.h>

//Creacion de la estructura automovil
typedef struct{
    int ruedas;
    int puertas;
    int asientos;
    char color[10];
    int año; 
    int cilindrada;
    char motor[20];
}automovil;
//Creacion de la estructura papeleo 
typedef struct{
    char tipoFactura[20];
    char fechaFactura[5];
    char paisProc[20];
    int precio;
    char tipo[10];
    char marca[20];
    char NIV[17];
}papeleo;
//Creacion de la estructura almacen
typedef struct{
    automovil coche;
    papeleo papeles;
}Almacen;
//Creacion de la estructura usuario
typedef struct{
    int idEmpleado;
    char nombreEmpleado[50];
    Almacen almacen[2];
}User;

void main(){
    User empleado;
    User* empleadoAp = &empleado;
    char nombreEmpleado, color, motor, tipoFactura, fechaFactura, paisProc, tipo, marca, NIV;
    int idEmpleado, ruedas, puertas, asientos, año, cilindrada, precio;

    printf("Bienvenido a consecionaria, ingrese los datos solicitados: \n");
    printf("Nombre de empleado: \n");
    scanf("%s", &nombreEmpleado);
    printf("ID del empleado: \n");
    scanf("%d", &idEmpleado);
    print("\n");

    printf("Informacion del auto: \n");
    printf("Numero de ruedas: \n");
    scanf("%d", &ruedas);
    printf("Numero de puertas: \n");
    scanf("%d", &puertas);
    printf("Numero de asientos: \n");
    scanf("%d", &asientos);
    printf("Color: \n");
    scanf("%s", &color);
    printf("año: \n");
    scanf("%d", &año);
    printf("Cilindros del motor: \n");
    scanf("%d", &cilindrada);
    printf("\n");

    printf("Informacion de la factura: \n");
    printf("Tipo de factura: \n");
    scanf("%s", &tipoFactura);
    printf("Fecha factura: \n");
    scanf("%s", &fechaFactura);
    printf("Pais de procedencia: \n");
    scanf("%s", &paisProc);
    printf("Precio: \n");
    scanf("%d", &precio);
    printf("Tipo de auto: \n");
    scanf("%s", &tipo);
    printf("Marca del auto: \n");
    scanf("%s", &marca);
    printf("Numero de identificacion Vehicular: \n");
    scanf("%s", &NIV);
    printf("\n");

    empleadoAp = idEmpleado =idEmpleado;
    strcpy(empleadoAp=nombreEmpleado, &nombreEmpleado);

    empleadoAp = empleado.almacen[0].coche.ruedas =ruedas;
    empleadoAp = empleado.almacen[0].coche.puertas =puertas;
    empleadoAp = empleado.almacen[0].coche.asientos =asientos;
    strcpy(empleadoAp=empleado.almacen[0].coche.color, &color);
    empleadoAp = empleado.almacen[0].coche.año =año;
    empleadoAp = empleado.almacen[0].coche.cilindrada =cilindrada;

    strcpy(empleadoAp=empleado.almacen[1].papeles.tipoFactura, &tipoFactura);
    strcpy(empleadoAp=empleado.almacen[1].papeles.fechaFactura, &fechaFactura);
    strcpy(empleadoAp=empleado.almacen[1].papeles.paisProc, &paisProc);
    empleadoAp = empleado.almacen[1].papeles.precio = precio;
    strcpy(empleadoAp=empleado.almacen[1].papeles.tipo, &tipo);
    strcpy(empleadoAp=empleado.almacen[1].papeles.marca, &marca);
    strcpy(empleadoAp=empleado.almacen[1].papeles.NIV, &NIV);

    printf("Datos del empleado: \n");
    printf("ID: %d\n", (*empleadoAp).idEmpleado);
    printf("Nombre: %s\n", (*empleadoAp).nombreEmpleado);
    printf("\n");
    printf("Datos del auto: \n");
    printf("Numero de ruedas: %d\n", (*empleadoAp).almacen[0].coche.ruedas);
    printf("Numero de puertas: %d\n", (*empleadoAp).almacen[0].coche.puertas);
    printf("Numero de asientos: %d\n", (*empleadoAp).almacen[0].coche.asientos);
    printf("Color del auto: %s\n", (*empleadoAp).almacen[0].coche.color);
    printf("año: %d\n", (*empleadoAp).almacen[0].coche.año);
    printf("Cilindros: %d\n", (*empleadoAp).almacen[0].coche.cilindrada);
    printf("\n");
    printf("Datos de la factura: \n");
    printf("Tipo de factura %s\n", (*empleadoAp).almacen[1].papeles.tipoFactura);
    printf("Fecha factura: %s\n", (*empleadoAp).almacen[1].papeles.fechaFactura);
    printf("Pais de procedencia: %s\n", (*empleadoAp).almacen[1].papeles.paisProc);
    printf("Precio: %d\n", (*empleadoAp).almacen[1].papeles.precio);
    printf("Tipo de auto: %s\n", (*empleadoAp).almacen[1].papeles.tipo);
    printf("Marca: %s\n", (*empleadoAp).almacen[1].papeles.marca);
    printf("Numero de Identificacion Vehicular: %s\n", (*empleadoAp).almacen[1].papeles.NIV);
}