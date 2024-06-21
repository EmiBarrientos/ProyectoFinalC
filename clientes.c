#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "movimientos.h"
#include "domicilios.h"
#include "clientes.h"



stCliente cargaUnCliente(){

    stCliente cliente;
    char palabra[40];  ///variable aux usada mas de una vez dentro de esta funcion


    printf("ingrese el nombre del cliente: \n");
    fflush(stdin);
    gets(palabra);
    while(validaPalabra(palabra)){                          ///si pasa el while carga
        printf("datos invalidos, intente nuevamente\n");    ///
        system("pause");
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
    strcpy(cliente.apellido,palabra);

    printf("ingrese el DNI del cliente: \n");
    fflush(stdin);
    gets(palabra);
    while(!validarDni(palabra)){///mientras validar dni sea 0( falso ) se ejecuta este while
        system("cls");
        printf("datos invalidos, intente nuevamente\n");
        system("pause");
        system("cls");
        printf("ingrese el DNI del cliente: \n");
        fflush(stdin);
        gets(palabra);
    }
    strcpy(cliente.dni,palabra);

    printf("Ingrese el Email del cliente: \n");
    fflush(stdin);
    gets(palabra);
    while(!validarEmail(palabra)){
        system("cls");
        printf("Datos invalidos, intente nuevamente\n");
        system("pause");
        system("cls");
        printf("Ingrese el email del cliente: \n");
        fflush(stdin);
        gets(palabra);

    }
    strcpy(cliente.email,palabra);

    printf("ingrese telefono del cliente: \n");
    fflush(stdin);
    gets(palabra);

     while(!validarNum(palabra)){
        system("cls");
        printf("Datos invalidos, intente nuevamente\n");
        system("pause");
        system("cls");
        printf("Ingrese el Telefono del cliente: \n");
        fflush(stdin);
        gets(palabra);

    }

    strcpy(cliente.telefono,palabra);

    printf("ingrese calle del cliente: \n");
    fflush(stdin);
    gets(palabra);

    while(validaPalabra(palabra)){
        system("cls");
        printf("Datos invalidos, intente nuevamente\n");
        system("pause");
        system("cls");
        printf("Ingrese calle del cliente: \n");
        fflush(stdin);
        gets(palabra);

    }
    strcpy(cliente.domicilio.calle,palabra);


    printf("ingrese Localidad del cliente: \n");
    fflush(stdin);
    gets(palabra);

    while(validaPalabra(palabra)){
        system("cls");
        printf("Datos invalidos, intente nuevamente\n");
        system("pause");
        system("cls");
        printf("Ingrese Localidad del cliente: \n");
        fflush(stdin);
        gets(palabra);

    }
    strcpy(cliente.domicilio.localidad,palabra);

    printf("ingrese Provincia del cliente: \n");
    fflush(stdin);
    gets(palabra);

    while(validaPalabra(palabra)){
        system("cls");
        printf("Datos invalidos, intente nuevamente\n");
        system("pause");
        system("cls");
        printf("Ingrese Provincia del cliente: \n");
        fflush(stdin);
        gets(palabra);

    }
    strcpy(cliente.domicilio.provincia,palabra);

    printf("ingrese codigo postal del cliente: \n");
    fflush(stdin);
    gets(palabra);

    while(validaPalabra(palabra)){
        system("cls");
        printf("Datos invalidos, intente nuevamente\n");
        system("pause");
        system("cls");
        printf("Ingrese codigo postal del cliente: \n");
        fflush(stdin);
        gets(palabra);

    }
    strcpy(cliente.domicilio.cpos,palabra);


    cliente.eliminado=0;


return cliente;
}

void muestraUnCliente(stCliente cliente){
    printf("------------------------------------------------\n");
    printf("Nro de cliente: %d \n", cliente.nroCliente);
    printf("Nombre del cliente: %s \n", cliente.nombre);
    printf("Apellido del cliente: %s \n", cliente.apellido);
    printf("Email del cliente: %s \n", cliente.email);
    printf("Telefono del cliente: %s \n", cliente.telefono);
    printf("Dni del cliente: %s \n", cliente.dni);
    printf("Calle del cliente: %s \n", cliente.domicilio.calle);
    printf("Numero de vivienda del cliente: %s \n ", cliente.domicilio.nro);
    printf("Localidad del cliente: %s \n", cliente.domicilio.localidad);
    printf("Codigo postal del cliente: %s \n", cliente.domicilio.cpos);
    printf("Provincia del cliente: %s \n", cliente.domicilio.provincia);
}




int validaPalabra(char palabra[]){      ///Devuelve 0 si la palabra es valida
    int palabraValida=0;                ///         1 si la palabra es invalida
    int flag=0;
    int i=0;
    while(flag==0 && i<strlen(palabra)){///
        if(isdigit(palabra[i])){
            palabraValida =1;
            flag=1;
        }
        i++;
    }
return palabraValida;
}


int validarDni(char dni[]){ ///devuelve 1 si el dni es valido en
    int esValido=1;         ///en tamaño y en ser todo numerico
    if(strlen(dni)!=8){
        esValido=0;
    }
    if(!validarNum(dni)){
        esValido=0;
    }


return esValido;
}

int validarNum(char num[])
{                                           /// devuelve 0 si el dni tiene una letra
    int esValido=0;                         ///          1 si no tiene letra
    int i=0;                                ///
    while(esValido==0 && i<strlen(num)){
        if(isdigit(num[i])){
            esValido=1;
        }
        i++;
    }

return esValido;
}

int validarEmail(char email[]){    /// devuelve 1 si el email es valido
                                   ///          0 si el email es invalido
    int flag=1;
    int arroba=0;                  /// Booleano para saber si tiene arroba
    int contadorArroba=0;          /// contador para saber cuantas arrobas tiene
    int posArroba;                 /// contador que te dice la posicion del arroba
    int i=0;                       /// contador
    int posPunto;                  /// posicion del punto
    int contPunto=0;            /// dice si hay mas de un punto
    char punto;                     ///variable por las dudas xd
    while(i<strlen(email)&&flag==1){

        if(email[i]=='@'){ ///dice la posicion del arroba
            arroba=1;
            contadorArroba++;
            posArroba=i;
            }

        if(contadorArroba>1){ ///si hay mas de un arroba devuelve 0
            flag=0;
        }

        if( email[i]=='{'|| email[i]=='}'|| email[i]=='['|| email[i]==']'|| email[i]==';'|| ///excluye todos estos caracteres
            email[i]==':'|| email[i]=='+'|| email[i]==' '|| email[i]=='/'|| email[i]=='<'||
            email[i]=='>'|| email[i]==','|| email[i]=='%'|| email[i]=='&'|| email[i]=='#'||
            email[i]=='('|| email[i]==')'|| email[i]=='='|| email[i]=='?'|| email[i]=='¿'||
            email[i]=='¡'|| email[i]=='!'|| email[i]=='|'|| email[i]=='$'){

                flag=0;

                }

        if(email[i]=='.'){ ///verifica el punto
            posPunto=i;
            contPunto++;
         }
         if(contPunto>1){ ///si hay mas de un punto devuelve 0
            flag=0;
         }

        i++;
    }


    if(!arroba){    ///si no hay arroba devuelve 0
        flag=0;
    }

    if(flag==1){
        if(arroba==1){
            if(email[0]!='@'){
                if(contPunto==1 && posPunto>posArroba){
                    flag=1;
                }else{
                    flag=0;
                }
            }else{
                flag=0;
            }
        }
    }


return flag;
}

