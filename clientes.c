#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "estructuras.h"
#include "domicilios.h"
#include "clientes.h"



stCliente cargaUnCliente(){

    stCliente cliente;
    char palabra[40];


    printf("ingrese el nombre del cliente: \n");
    fflush(stdin);
    gets(palabra);
    while(validaPalabra(palabra)){
        printf("datos invalidos, intente nuevamente\n");
        system("cls");
        printf("ingrese el nombre del cliente: \n");
        fflush(stdin);
        gets(palabra);
    }
    strcpy(cliente.nombre,palabra);

    printf("ingrese el apellido del cliente: \n");
    fflush(stdin);
    gets(palabra);
    while(validaPalabra(palabra)){
        system("cls");
        printf("datos invalidos, intente nuevamente\n");
        system("pause");
        system("cls");
        printf("ingrese el apellido del cliente: \n");
        fflush(stdin);
        gets(palabra);
    }

    gets(cliente.apellido);
    strcpy(cliente.apellido,palabra);

    printf("ingrese el DNI del cliente: \n");
    fflush(stdin);
    gets(cliente.dni);
    printf("ingrese el Email del cliente: \n");
    fflush(stdin);
    gets(cliente.email);




return cliente;
}


int validaPalabra(char palabra[]){
    int palabraValida=0;
    int flag=0;
    int i=0;
    while(flag==0 && i<strlen(palabra)){
        if(isdigit(palabra[i])){
            palabraValida =1;
            flag=1;
        }
        i++;
    }
return palabraValida;
}


int validarDni(char dni[]){
    int esValido=1;
    if(strlen(dni)!=8){
        esValido=0;
    }
    if(validarNum(dni)){
        esValido=0;
    }


return esValido;
}

int validarNum(char dni[])
{
    int esValido=0;
    int i=0;
    while(esValido==0 && i<strlen(dni)){
        if(isdigit(dni[i])){
            esValido=1;
        }
        i++;
    }

return esValido;
}


