#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"
#include "domicilios.h"



stCliente cargaUnCliente(){

    stCliente cliente;
    char palabra[40];


    printf("ingrese el nombre del cliente: \n");
    fflush(stdin);
    gets(palabra);
    while(validarNombre(palabra)){
        printf("datos invalidos, intente nuevamente\n")
        system("cls");
        printf("ingrese el nombre del cliente: \n");
        fflush(stdin);
        gets(palabra);
    }
        cliente.nombre=palabra;



    printf("ingrese el apellido del cliente: \n");
    fflush(stdin);
    gets(cliente.apellido);
    printf("ingrese el DNI del cliente: \n");
    fflush(stdin);
    gets(cliente.dni);
    printf("ingrese el Email del cliente: \n");
    fflush(stdin);
    gets(cliente.email);




return cliente;
}


int validarNombre(char palabra[], int v){
    palabraValida=0;
    for(int i=0; i<v;i++){
        if(isdigit(palabra[i]))

    }


return palabraValida;
}








