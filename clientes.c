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


    printf("ingrese nro de calle del cliente: \n");
    fflush(stdin);
    gets(palabra);

    while(!validarNum(palabra)){
        system("cls");
        printf("Datos invalidos, intente nuevamente\n");
        system("pause");
        system("cls");
        printf("Ingrese nro calle del cliente: \n");
        fflush(stdin);
        gets(palabra);

    }
    strcpy(cliente.domicilio.nro,palabra);


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

    while(!validarNum(palabra)){
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




int validaPalabra(char palabra[]){                ///Devuelve 0 si la palabra es valida
    int palabraValida=0;                          ///         1 si la palabra es invalida
    int flag=0;
    int i=0;
    while(flag==0 && i<strlen(palabra)){           ///
        if(isdigit(palabra[i])){
            palabraValida =1;
            flag=1;
        }
        i++;
    }
return palabraValida;
}


int validarDni(char dni[]){                     ///devuelve 1 si el dni es valido en
    int esValido=1;                             ///en tamaño y en ser todo numerico
    if(strlen(dni)<7 || strlen(dni)>8){
        esValido=0;
    }
    if(!validarNum(dni)){
        esValido=0;
    }


return esValido;
}

int validarNum(char num[])
{                                           /// devuelve 0 (false)si el dni tiene una letra
    int esValido=1;                         ///          1 (true)si no tiene letra
    int i=0;                                ///
    while(esValido==1 && i<strlen(num)){
        if(!isdigit(num[i])){
            esValido=0;
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

stCliente modificaCliente(stCliente cliente){

    stCliente aux=cliente;
    char palabraAux[30];
    char control='s';
    int opcion;


    do{
        system("pause");
        system("cls");
        printf("\t ¿Que campo desea modificar?\n");
        printf("1:Nombre         \n");
        printf("2:Apellido       \n");
        printf("3:DNI            \n");
        printf("4:Telefono          \n");
        printf("5:Email       \n");
        printf("6:Modificar Domicilio    \n");
        printf("7:modificar todo   \n");
        printf("8:salir    \n\n");
        printf("******************************************\n");

        scanf("%d", &opcion);
        system("cls");

            switch(opcion){
                case 1:
                    printf("Nombre:         \n");
                    fflush(stdin);
                    gets(palabraAux);
                    while(validaPalabra(palabraAux)){
                            printf("datos invalidos, intente nuevamente\n");    ///
                            system("pause");
                            system("cls");
                            printf("ingrese el nombre del cliente: \n");
                            fflush(stdin);
                            gets(palabraAux);
                    }

                    strcpy(cliente.nombre,palabraAux);
                    cliente.apellido=aux.apellido;
                    cliente.dni=aux.dni;
                    cliente.nroCliente=aux.nroCliente;
                    cliente.telefono=aux.telefono;
                    cliente.domicilio.calle=aux.domicilio.calle;
                    cliente.domicilio.localidad=aux.domicilio.localidad;
                    cliente.domicilio.cpos=aux.domicilio.cpos;
                    cliente.domicilio.nro=aux.domicilio.nro;
                    cliente.domicilio.provincia=aux.domicilio.provincia;

                    system("pause");
                    system("cls");
                    break;

                case 2:

                    printf("Apellido:         \n");
                    fflush(stdin);
                    gets(palabraAux);
                    while(!validarNum(palabraAux)){
                            printf("datos invalidos, intente nuevamente\n");    ///
                            system("pause");
                            system("cls");
                            printf("ingrese el apellido del cliente: \n");
                            fflush(stdin);
                            gets(palabraAux);
                    }
                    strcpy(cliente.apellido,palabraAux);

                    cliente.nombre=aux.nombre;
                    cliente.dni=aux.dni;
                    cliente.nroCliente=aux.nroCliente;
                    cliente.telefono=aux.telefono;
                    cliente.domicilio.calle=aux.domicilio.calle;
                    cliente.domicilio.localidad=aux.domicilio.localidad;
                    cliente.domicilio.cpos=aux.domicilio.cpos;
                    cliente.domicilio.nro=aux.domicilio.nro;
                    cliente.domicilio.provincia=aux.domicilio.provincia;

                    system("pause");
                    system("cls");
                    break;

                case 3:
                    printf("DNI:         \n");
                    fflush(stdin);
                    gets(palabraAux);
                    while(!validarDni(palabraAux)){
                            printf("datos invalidos, intente nuevamente\n");    ///
                            system("pause");
                            system("cls");
                            printf("ingrese el nombre del cliente: \n");
                            fflush(stdin);
                            gets(palabraAux);
                    }


                    strcpy(cliente.dni,palabraAux);

                    cliente.nombre=aux.nombre;
                    cliente.apellido=aux.apellido;
                    cliente.nroCliente=aux.nroCliente;
                    cliente.telefono=aux.telefono;
                    cliente.domicilio.calle=aux.domicilio.calle;
                    cliente.domicilio.localidad=aux.domicilio.localidad;
                    cliente.domicilio.cpos=aux.domicilio.cpos;
                    cliente.domicilio.nro=aux.domicilio.nro;
                    cliente.domicilio.provincia=aux.domicilio.provincia;

                    system("pause");
                    system("cls");
                    break;
                case 4:

                    printf("Telefono:         \n");
                    fflush(stdin);
                    gets(palabraAux);
                    while(!validarNum(palabra)){
                            printf("datos invalidos, intente nuevamente\n");    ///
                            system("pause");
                            system("cls");
                            printf("ingrese el nombre del cliente: \n");
                            fflush(stdin);
                            gets(palabraAux);
                    }

                    strcpy(cliente.telefono,palabraAux);

                    cliente.nombre=aux.nombre;
                    cliente.apellido=aux.apellido;
                    cliente.nroCliente=aux.nroCliente;
                    cliente.dni=aux.dni;
                    cliente.domicilio.calle=aux.domicilio.calle;
                    cliente.domicilio.localidad=aux.domicilio.localidad;
                    cliente.domicilio.cpos=aux.domicilio.cpos;
                    cliente.domicilio.nro=aux.domicilio.nro;
                    cliente.domicilio.provincia=aux.domicilio.provincia;

                    system("pause");
                    system("cls");
                    break;
                case 5:

                    printf("Email:         \n");
                    fflush(stdin);
                    gets(palabraAux);
                    while(!validarNum(palabra)){
                            printf("datos invalidos, intente nuevamente\n");    ///
                            system("pause");
                            system("cls");
                            printf("ingrese el nombre del cliente: \n");
                            fflush(stdin);
                            gets(palabraAux);
                    }

                    strcpy(cliente.email,palabraAux);
                    cliente.nombre=aux.nombre;
                    cliente.apellido=aux.apellido;
                    cliente.nroCliente=aux.nroCliente;
                    cliente.dni=aux.dni;
                    cliente.domicilio.calle=aux.domicilio.calle;
                    cliente.domicilio.localidad=aux.domicilio.localidad;
                    cliente.domicilio.cpos=aux.domicilio.cpos;
                    cliente.domicilio.nro=aux.domicilio.nro;
                    cliente.domicilio.provincia=aux.domicilio.provincia;

                    system("pause");
                    system("cls");
                    break;

                case 6:
                    modificaDomicilio(cliente);

                    system("pause");
                    system("cls");
                    break;

                case 7:

                    cliente=cargaUnCliente();
                    system("pause");
                    system("cls");
                    break;
                case 8:


                    system("pause");
                    system("cls");
                    break;

                default:
                    printf("Opcion incorrecta, ingrese una opcion valida\n");
                    system("pause");
                    system("cls");
                    break;

            }

            printf("Desea modificar otro dato? s para continuar\n");
            fflush(stdin);
            scanf("%c",&control);


    }while((opcion<0 && opcion>4)||control=='s');


return cliente;
}

stcliente modificaDomicilio(stCliente){
    stCliente aux=cliente;
    char palabraAux[30];
    char control='s';
    int opcion;

    do{
        system("pause");
        system("cls");
        printf("\t¿Que campo desea modificar?       \n");
        printf("1:Calle                          \n");
        printf("2:Localidad                      \n");
        printf("3:Codigo postal                  \n");
        printf("4:Provincia                      \n");
        printf("5:Menu anterior                  \n");
        printf("6:Terminar con modificacion    \n\n");
        printf("******************************************\n");

        scanf("%d", &opcion);
        system("cls");

            switch(opcion){

                case 1:
                    printf("Calle:         \n");
                    fflush(stdin);
                    gets(palabraAux);
                    while(!validarNum(palabra)){
                            printf("datos invalidos, intente nuevamente\n");    ///
                            system("pause");
                            system("cls");
                            printf("ingrese el nombre del cliente: \n");
                            fflush(stdin);
                            gets(palabraAux);
                    }

                    strcpy(cliente.calle,palabraAux);

                    cliente.nombre=aux.nombre;
                    cliente.apellido=aux.apellido;
                    cliente.nroCliente=aux.nroCliente;
                    cliente.dni=aux.dni;

                    cliente.domicilio.localidad=aux.domicilio.localidad;
                    cliente.domicilio.cpos=aux.domicilio.cpos;
                    cliente.domicilio.nro=aux.domicilio.nro;
                    cliente.domicilio.provincia=aux.domicilio.provincia;

                    system("pause");
                    system("cls");
                    break;

                case 2:
                    printf("Localidad:         \n");
                    fflush(stdin);
                    gets(palabraAux);
                    while(!validarNum(palabra)){
                            printf("datos invalidos, intente nuevamente\n");    ///
                            system("pause");
                            system("cls");
                            printf("ingrese el nombre del cliente: \n");
                            fflush(stdin);
                            gets(palabraAux);
                    }

                    strcpy(cliente.localidad,palabraAux);

                    cliente.nombre=aux.nombre;
                    cliente.apellido=aux.apellido;
                    cliente.nroCliente=aux.nroCliente;
                    cliente.dni=aux.dni;
                    cliente.domicilio.calle=aux.domicilio.calle;

                    cliente.domicilio.cpos=aux.domicilio.cpos;
                    cliente.domicilio.nro=aux.domicilio.nro;
                    cliente.domicilio.provincia=aux.domicilio.provincia;

                    system("pause");
                    system("cls");
                    break;

                case 3:
                    printf("cpos:         \n");
                    fflush(stdin);
                    gets(palabraAux);
                    while(!validarNum(palabra)){
                            printf("datos invalidos, intente nuevamente\n");    ///
                            system("pause");
                            system("cls");
                            printf("ingrese el nombre del cliente: \n");
                            fflush(stdin);
                            gets(palabraAux);
                    }

                    strcpy(cliente.cpos,palabraAux);

                    cliente.nombre=aux.nombre;
                    cliente.apellido=aux.apellido;
                    cliente.nroCliente=aux.nroCliente;
                    cliente.dni=aux.dni;
                    cliente.domicilio.calle=aux.domicilio.calle;
                    cliente.domicilio.localidad=aux.domicilio.localidad;
                    cliente.domicilio.nro=aux.domicilio.nro;
                    cliente.domicilio.provincia=aux.domicilio.provincia;

                    system("pause");
                    system("cls");
                    break;

                case 4:
                    printf("nro:         \n");
                    fflush(stdin);
                    gets(palabraAux);
                    while(!validarNum(palabra)){
                            printf("datos invalidos, intente nuevamente\n");    ///
                            system("pause");
                            system("cls");
                            printf("ingrese el nombre del cliente: \n");
                            fflush(stdin);
                            gets(palabraAux);
                    }

                    strcpy(cliente.nro,palabraAux);

                    cliente.nombre=aux.nombre;
                    cliente.apellido=aux.apellido;
                    cliente.nroCliente=aux.nroCliente;
                    cliente.dni=aux.dni;
                    cliente.domicilio.calle=aux.domicilio.calle;
                    cliente.domicilio.localidad=aux.domicilio.localidad;

                    cliente.domicilio.cpos=aux.domicilio.cpos;
                    cliente.domicilio.provincia=aux.domicilio.provincia;

                    system("pause");
                    system("cls");
                    break;

                    case 5:
                    printf("provincia:         \n");
                    fflush(stdin);
                    gets(palabraAux);
                    while(!validarNum(palabra)){
                            printf("datos invalidos, intente nuevamente\n");    ///
                            system("pause");
                            system("cls");
                            printf("ingrese el nombre del cliente: \n");
                            fflush(stdin);
                            gets(palabraAux);
                    }

                    strcpy(cliente.provincia,palabraAux);

                    cliente.nombre=aux.nombre;
                    cliente.apellido=aux.apellido;
                    cliente.nroCliente=aux.nroCliente;
                    cliente.dni=aux.dni;
                    cliente.domicilio.calle=aux.domicilio.calle;
                    cliente.domicilio.localidad=aux.domicilio.localidad;
                    cliente.domicilio.nro=aux.domicilio.nro;
                    cliente.domicilio.cpos=aux.domicilio.cpos;


                    system("pause");
                    system("cls");
                    break;

                case 6:


                    system("pause");
                    system("cls");
                    break;

                case 7:


                    system("pause");
                    system("cls");
                    break;



                default:
                    printf("ingrese una opcion correcta\n");
                    system("pause");
                    system("cls");
                    break;

            }

            printf("Desea modificar otro dato? s para continuar\n");
            fflush(stdin);
            scanf("%c",&control);


    }while((opcion<0 && opcion>4)||control=='s');


return cliente;

}






void modificaClientePorId(char nombre_Archivo[],int idCliente){
    int flag=0;
    stCliente c;
    FILE *archi=fopen(nombre_Archivo,"r+b");
    if(archi){
        while(fread(&c,sizeof(stCliente),1,archi)>0 && !flag){
            if(c.id==idCliente){
                c=modificaCliente(c);
                fseek(archi,-1*sizeof(stCliente),SEEK_CUR);
                fwrite(&c,sizeof(stCliente),1,archi);
                flag=1;
            }
        }
        fclose(archi);
    }
}


void modificaEstadoClientePorId(char nombre_Archivo[],int id_Cliente, int estado){
    int flag=0;
    stCliente c;
    FILE *archi=fopen(nombre_Archivo,"r+b");
    if(archi){
        while(fread(&c,sizeof(stCliente),1,archi)>0 && !flag){
            if(c.id==id_Cliente){
                c.eliminado=estado;
                fseek(archi,-1*sizeof(stCliente),SEEK_CUR);
                fwrite(&c,sizeof(stCliente),1,archi);
                flag=1;
            }
        }
        fclose(archi);
    }
}


void muestraTodosClientes(char nombre_Archivo[], int estado){
    stCliente c;
    FILE *archi=fopen(nombre_Archivo,"rb");
    if(archi){
        while(fread(&c,sizeof(stCliente),1,archi)>0){
            muestraUnCliente(c);

        }
        fclose(archi);
    }
}

void muestraClientePorId(char nombre_Archivo[],int idCliente){
    int flag=0;
    stCliente c;
    FILE *archi=fopen(nombre_Archivo,"rb");
    if(archi){
        while(fread(&c,sizeof(stCliente),1,archi)>0 && !flag){
            if(c.id==idCliente){
                muestraUnCliente(c);
                flag=1;
            }
        }
        fclose(archi);
    }
}


void cargaClienteEnArchivo(char nombreArchivo[])
{
    stCliente cliente;
    FILE *archi=fopen(nombreArchivo,"ab");
    char opcion='s';

    if(archi){
        while(opcion=='s'){
          cliente=cargaUnCliente();
          fwrite(&cliente,sizeof(stCliente),1,archi);
          printf("Desea seguir cargando? s para continuar cualquier tecla para salir\n");
          fflush(stdin);
          scanf("%c",&opcion);
        }
        fclose(archi);
    }


}


