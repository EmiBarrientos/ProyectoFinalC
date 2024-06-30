#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include "general.h"

/// Funciones de clientes: mostrarClientes


stCliente cargaUnCliente(char archivoCliente[])
{
    stCliente cliente;
    char palabra[40];  ///variable aux usada mas de una vez dentro de esta funcion
    char Provincias [24][24]= {"Buenos aires","Catamarca","Chaco","Chubut","Cordoba","Corrientes","Entre Rios","Formosa","Jujuy","La Pampa","La rioja",
                               "Mendoza","Misiones","Neuquen","Rio negro","Salta","San Juan","San Luis","Santa Cruz","Santa Fe","Santiago del Estero",
                               "Tierra del Fuego","Tucuman", "Extranjero"
                              };
    int opcion = 25;
    int i;
    int idCliente=0;

    printf("ingrese el nombre del cliente: \n");
    fflush(stdin);
    gets(palabra);
    while(validaPalabra(palabra))                           ///si pasa el while carga
    {
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
    while(validaPalabra(palabra))
    {
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
    while(!validarDni(palabra)) ///mientras validar dni sea 0( falso ) se ejecuta este while
    {
        system("cls");
        printf("datos invalidos, intente nuevamente\n");
        system("pause");
        system("cls");
        printf("ingrese el DNI del cliente: \n");
        fflush(stdin);
        gets(palabra);
    }
    strcpy(cliente.dni,palabra);

    idCliente = traducirDniaIdCliente(archivoCliente,cliente.dni); ///si retorna -1 no esta, si retorna menores esta repetido, positivos es el id
    if (idCliente != -1)
    {
        printf("\n !!!! Ya existen clientes cargados con ese DNI, esta seguro que desea cargarlo? \n");
        printf("\n 1. Para confirmar");
        printf("\n Otro para salir: ");
        scanf("%d",&opcion);
        if (opcion != 1)
        {
            cliente.id=-2;
            return cliente;
        }

    }


    printf("Ingrese el Email del cliente: \n");
    fflush(stdin);
    gets(palabra);
    while(!validarEmail(palabra))
    {
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

    while(!validarNum(palabra))
    {
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
    strcpy(cliente.domicilio.calle,palabra);


    printf("ingrese nro de calle del cliente: \n");
    fflush(stdin);
    gets(palabra);

    while(!validarNum(palabra))
    {
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

    while(validaPalabra(palabra))
    {
        system("cls");
        printf("Datos invalidos, intente nuevamente\n");
        system("pause");
        system("cls");
        printf("Ingrese Localidad del cliente: \n");
        fflush(stdin);
        gets(palabra);

    }
    strcpy(cliente.domicilio.localidad,palabra);

    do
    {
        printf("Seleccione la Provincia del cliente: \n");

        for(i=0; i<24; i++)
        {
            printf(" %d - %s\n",i+1,Provincias[i]);
        }
        fflush(stdin);
        scanf("%d",&opcion);
        opcion=opcion-1;
    }
    while(opcion<0 || opcion>23);

    strcpy(cliente.domicilio.provincia,Provincias[opcion]);


    printf("ingrese codigo postal del cliente: \n");
    fflush(stdin);
    gets(palabra);

    while(!validarNum(palabra))
    {
        system("cls");
        printf("Datos invalidos, intente nuevamente\n");
        system("pause");
        system("cls");
        printf("Ingrese codigo postal del cliente: \n");
        fflush(stdin);
        gets(palabra);

    }
    strcpy(cliente.domicilio.cpos,palabra);

    cliente.nroCliente=(cliente.dni[0]-48)+(cliente.dni[1]-48)*10+(cliente.dni[2]-48)*100+(cliente.dni[3]-48)*1000+(cliente.dni[4]-48)*10000+(cliente.dni[5]-48)*100000+(cliente.dni[6]-48)*100000;
    cliente.eliminado=0;

/// falta ingresar o asignar nro de cliente: Se puede usar el dni mas la primera letra de su apellido en codigo ASCCI
    return cliente;
}

int validaPalabra(char palabra[])                 ///Devuelve 0 si la palabra es valida
{
    int palabraValida=0;                          ///         1 si la palabra es invalida
    int flag=0;
    int i=0;
    while(flag==0 && i<strlen(palabra))            ///
    {
        if(isdigit(palabra[i]))
        {
            palabraValida =1;
            flag=1;
        }
        i++;
    }
    return palabraValida;
}

int validarDni(char dni[])                      ///devuelve 1 si el dni es valido en
{
    int esValido=1;                             ///en tamaño y en ser todo numerico
    if(strlen(dni)<7 || strlen(dni)>8)
    {
        esValido=0;
    }
    if(!validarNum(dni))
    {
        esValido=0;
    }


    return esValido;
}

int validarNum(char num[])
{
    /// devuelve 0 (false)si el dni tiene una letra
    int esValido=1;                         ///          1 (true)si no tiene letra
    int i=0;                                ///
    while(esValido==1 && i<strlen(num))
    {
        if(!isdigit(num[i]))
        {
            esValido=0;
        }
        i++;
    }

    return esValido;
}

int validarEmail(char email[])     /// devuelve 1 si el email es valido
{
    ///          0 si el email es invalido
    int flag=1;
    int arroba=0;                  /// Booleano para saber si tiene arroba
    int contadorArroba=0;          /// contador para saber cuantas arrobas tiene
    int posArroba;                 /// contador que te dice la posicion del arroba
    int i=0;                       /// contador
    int posPunto;                  /// posicion del punto
    int contPunto=0;            /// dice si hay mas de un punto
    char punto;                     ///variable por las dudas xd
    while(i<strlen(email)&&flag==1)
    {

        if(email[i]=='@')  ///dice la posicion del arroba
        {
            arroba=1;
            contadorArroba++;
            posArroba=i;
        }

        if(contadorArroba>1)  ///si hay mas de un arroba devuelve 0
        {
            flag=0;
        }

        if( email[i]=='{'|| email[i]=='}'|| email[i]=='['|| email[i]==']'|| email[i]==';'|| ///excluye todos estos caracteres
                email[i]==':'|| email[i]=='+'|| email[i]==' '|| email[i]=='/'|| email[i]=='<'||
                email[i]=='>'|| email[i]==','|| email[i]=='%'|| email[i]=='&'|| email[i]=='#'||
                email[i]=='('|| email[i]==')'|| email[i]=='='|| email[i]=='?'|| email[i]=='¿'||
                email[i]=='¡'|| email[i]=='!'|| email[i]=='|'|| email[i]=='$')
        {

            flag=0;

        }

        if(email[i]=='.')  ///verifica el punto
        {
            posPunto=i;
            contPunto++;
        }
        if(contPunto>1)  ///si hay mas de un punto devuelve 0
        {
            flag=0;
        }

        i++;
    }


    if(!arroba)     ///si no hay arroba devuelve 0
    {
        flag=0;
    }

    if(flag==1)
    {
        if(arroba==1)
        {
            if(email[0]!='@')
            {
                if(contPunto==1 && posPunto>posArroba)
                {
                    flag=1;
                }
                else
                {
                    flag=0;
                }
            }
            else
            {
                flag=0;
            }
        }
    }


    return flag;
}


void cargaClienteEnArchivo(char nombreArchivo[])
{
    char opcion='s';
    stCliente cliente;

    while(opcion=='s' || opcion=='S')
    {

        FILE *archi=fopen(nombreArchivo,"ab");
{
            cliente=cargaUnCliente(nombreArchivo);
            if (cliente.id!=-2);
            {
                cliente.id=cuentaRegistrosGral(nombreArchivo,sizeof(stCliente));
                printf("\nConfirma la carga del siguiente Cliente\n");
                muestraUnCliente(cliente);
                printf("Desea cargar al clienten? s para confirmar cualquier tecla para salir\n ");
                scanf("%c",&opcion);
                if(opcion=='s' || opcion=='S') /// permite anular la carga
                {
                    fwrite(&cliente,sizeof(stCliente),1,archi);
                        printf("\nSe cargo el cliente DNI: %s\n",cliente.dni);
                }
            }
        }
        fclose(archi);
        printf("Desea seguir cargando? s para continuar cualquier tecla para salir\n");
        fflush(stdin);
        scanf("%c",&opcion);
    }
}

void muestraUnClienteId(char nombreArchivo[],int idCliente)
{
    int flag=0;
    stCliente c;
    FILE *archi=fopen(nombreArchivo,"rb");
    if(archi)
    {
        while(fread(&c,sizeof(stCliente),1,archi)>0 && !flag)
        {

            if(c.id==idCliente)
            {
                muestraUnCliente(c);
                flag=1;
            }
        }
        fclose(archi);
    }
}

void muestraListadoClienteInfoPrincipal(stCliente cliente)
{
    ///muestra el cliente pero solo ciertos datos

      printf("%-10s | %-10s | %-20s | %-10s | %-10s| %-20d \n",
           cliente.dni,
           cliente.nombre,
           cliente.apellido,
           //cliente.email,
           cliente.telefono,
           cliente.eliminado == 1 ? "Inactiva" : "Activa",cliente.id);
    /*printf("------------------------------------------------\n");
    printf("Nro de cliente: %d \n", cliente.nroCliente);
    printf("Nombre del cliente: %s \n", cliente.nombre);
    printf("Apellido del cliente: %s \n", cliente.apellido);
    printf("Email del cliente: %s \n", cliente.email);
    printf("Telefono del cliente: %s \n", cliente.telefono);
    printf("Dni del cliente: %s \n", cliente.dni);
*/
}



void mostrarEncabezadoCliente() /// ver si arreglamos para que muestre en listado
{
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("%-10s | %-10s | %-20s | %-10s | %-10s\n",
           "DNI", "Nombre", "Apellido", "Telefono", "Estado");
    printf("-----------------------------------------------------------------------------------------------------------------\n");
}


void muestraUnCliente(stCliente cliente)
{
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
void cambiarEstadoCliente(char nombre_Archivo[], int id_Cliente, int estado)
{
    int flag=0;
    stCliente c;
    FILE *archi=fopen(nombre_Archivo,"r+b");
    if(archi)
    {
        while(fread(&c,sizeof(stCliente),1,archi)>0 && !flag)
        {
            if(c.id==id_Cliente)
            {
                c.eliminado=estado;
                fseek(archi,-1*sizeof(stCliente),SEEK_CUR);
                fwrite(&c,sizeof(stCliente),1,archi);
                flag=1;
            }
        }
        fclose(archi);
    }
}

///---------------------------------------------------------------------------------------------------

void modificaClientePorId(char nombre_Archivo[],int idCliente)
{
    int flag=0;
    stCliente c;
    FILE *archi=fopen(nombre_Archivo,"r+b");
    if(archi)
    {
        while(flag==0 && fread(&c,sizeof(stCliente),1,archi)>0)
        {
            if(c.id == idCliente)
            {
                c = modificaCliente(c,nombre_Archivo);
                fseek(archi,-1*sizeof(stCliente),SEEK_CUR);
                fwrite(&c,sizeof(stCliente),1,archi);
                flag=1;
            }
        }
        fclose(archi);
    }
}

stCliente modificaCliente(stCliente cliente,char archivoCliente[])
{

    stCliente aux=cliente;
    char palabraAux[30];
    char control='s';
    int opcion;


    do
    {
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

        switch(opcion)
        {
        case 1:
            printf("Nombre:         \n");
            fflush(stdin);
            gets(palabraAux);
            while(validaPalabra(palabraAux))
            {
                printf("datos invalidos, intente nuevamente\n");    ///
                system("pause");
                system("cls");
                printf("ingrese el nombre del cliente: \n");
                fflush(stdin);
                gets(palabraAux);
            }

            strcpy(cliente.nombre,palabraAux);
            strcpy(cliente.apellido,aux.apellido);
            strcpy(cliente.dni,aux.dni);
            cliente.nroCliente=aux.nroCliente;
            strcpy(cliente.telefono,aux.telefono);
            strcpy(cliente.domicilio.calle,aux.domicilio.calle);
            strcpy(cliente.domicilio.localidad,aux.domicilio.localidad);
            strcpy(cliente.domicilio.cpos,aux.domicilio.cpos);
            strcpy(cliente.domicilio.nro,aux.domicilio.nro);
            strcpy(cliente.domicilio.provincia,aux.domicilio.provincia);

            system("pause");
            system("cls");
            break;

        case 2:

            printf("Apellido:         \n");
            fflush(stdin);
            gets(palabraAux);
            while(!validarNum(palabraAux))
            {
                printf("datos invalidos, intente nuevamente\n");    ///
                system("pause");
                system("cls");
                printf("ingrese el apellido del cliente: \n");
                fflush(stdin);
                gets(palabraAux);
            }
            strcpy(cliente.apellido,palabraAux);
            strcpy(cliente.nombre,aux.nombre);
            strcpy(cliente.dni,aux.dni);
            cliente.nroCliente=aux.nroCliente;
            strcpy(cliente.telefono,aux.telefono);
            strcpy(cliente.domicilio.calle,aux.domicilio.calle);
            strcpy(cliente.domicilio.localidad,aux.domicilio.localidad);
            strcpy(cliente.domicilio.cpos,aux.domicilio.cpos);
            strcpy(cliente.domicilio.nro,aux.domicilio.nro);
            strcpy(cliente.domicilio.provincia,aux.domicilio.provincia);

            system("pause");
            system("cls");
            break;

        case 3:
            printf("DNI:         \n");
            fflush(stdin);
            gets(palabraAux);
            while(!validarDni(palabraAux))
            {
                printf("datos invalidos, intente nuevamente\n");    ///
                system("pause");
                system("cls");
                printf("ingrese el nombre del cliente: \n");
                fflush(stdin);
                gets(palabraAux);
            }


            strcpy(cliente.dni,palabraAux);

            strcpy(cliente.nombre,aux.nombre);
            strcpy(cliente.apellido,aux.apellido);
            cliente.nroCliente=aux.nroCliente;
            strcpy(cliente.telefono,aux.telefono);
            strcpy(cliente.domicilio.calle,aux.domicilio.calle);
            strcpy(cliente.domicilio.localidad,aux.domicilio.localidad);
            strcpy(cliente.domicilio.cpos,aux.domicilio.cpos);
            strcpy(cliente.domicilio.nro,aux.domicilio.nro);
            strcpy(cliente.domicilio.provincia,aux.domicilio.provincia);

            system("pause");
            system("cls");
            break;
        case 4:

            printf("Telefono:         \n");
            fflush(stdin);
            gets(palabraAux);
            while(!validarNum(palabraAux))
            {
                printf("datos invalidos, intente nuevamente\n");    ///
                system("pause");
                system("cls");
                printf("ingrese el nombre del cliente: \n");
                fflush(stdin);
                gets(palabraAux);
            }

            strcpy(cliente.telefono,palabraAux);

            strcpy(cliente.nombre,aux.nombre);
            strcpy(cliente.apellido,aux.apellido);
            cliente.nroCliente=aux.nroCliente;
            strcpy(cliente.dni,aux.dni);
            strcpy(cliente.domicilio.calle,aux.domicilio.calle);
            strcpy(cliente.domicilio.localidad,aux.domicilio.localidad);
            strcpy(cliente.domicilio.cpos,aux.domicilio.cpos);
            strcpy(cliente.domicilio.nro,aux.domicilio.nro);
            strcpy(cliente.domicilio.provincia,aux.domicilio.provincia);

            system("pause");
            system("cls");
            break;
        case 5:

            printf("Email:         \n");
            fflush(stdin);
            gets(palabraAux);
            while(!validarNum(palabraAux))
            {
                printf("datos invalidos, intente nuevamente\n");    ///
                system("pause");
                system("cls");
                printf("ingrese el nombre del cliente: \n");
                fflush(stdin);
                gets(palabraAux);
            }

            strcpy(cliente.email,palabraAux);
            strcpy(cliente.nombre,aux.nombre);
            strcpy(cliente.apellido,aux.apellido);
            cliente.nroCliente=aux.nroCliente;
            strcpy(cliente.dni,aux.dni);
            strcpy(cliente.domicilio.calle,aux.domicilio.calle);
            strcpy(cliente.domicilio.localidad,aux.domicilio.localidad);
            strcpy(cliente.domicilio.cpos,aux.domicilio.cpos);
            strcpy(cliente.domicilio.nro,aux.domicilio.nro);
            strcpy(cliente.domicilio.provincia,aux.domicilio.provincia);

            system("pause");
            system("cls");
            break;

        case 6:
            modificaDomicilio(cliente);

            system("pause");
            system("cls");
            break;

        case 7:

            cliente=cargaUnCliente(archivoCliente);
            system("pause");
            system("cls");
            break;
        case 8:

            menuClientes();
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


    }
    while((opcion<0 && opcion>4)||control=='s');


    return cliente;
}

stCliente modificaDomicilio(stCliente cliente)
{
    stCliente aux=cliente;
    char palabraAux[30];
    char control='s';
    int opcion;

    do
    {
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

        switch(opcion)
        {

        case 1:
            printf("Calle:         \n");
            fflush(stdin);
            gets(palabraAux);
            while(!validarNum(palabraAux))
            {
                printf("datos invalidos, intente nuevamente\n");    ///
                system("pause");
                system("cls");
                printf("ingrese el nombre del cliente: \n");
                fflush(stdin);
                gets(palabraAux);
            }


            strcpy(cliente.domicilio.calle,palabraAux);

            strcpy(cliente.nombre,aux.nombre);
            strcpy(cliente.apellido,aux.apellido);
            cliente.nroCliente=aux.nroCliente;
            strcpy(cliente.dni,aux.dni);

            strcpy(cliente.domicilio.localidad,aux.domicilio.localidad);
            strcpy(cliente.domicilio.cpos,aux.domicilio.cpos);
            strcpy(cliente.domicilio.nro,aux.domicilio.nro);
            strcpy(cliente.domicilio.provincia,aux.domicilio.provincia);

            system("pause");
            system("cls");
            break;

        case 2:
            printf("Localidad:         \n");
            fflush(stdin);
            gets(palabraAux);
            while(!validarNum(palabraAux))
            {
                printf("datos invalidos, intente nuevamente\n");    ///
                system("pause");
                system("cls");
                printf("ingrese el nombre del cliente: \n");
                fflush(stdin);
                gets(palabraAux);
            }

            strcpy(cliente.domicilio.localidad,palabraAux);

            strcpy(cliente.nombre,aux.nombre);
            strcpy(cliente.apellido,aux.apellido);
            cliente.nroCliente=aux.nroCliente;
            strcpy(cliente.dni,aux.dni);
            strcpy(cliente.domicilio.calle,aux.domicilio.calle);

            strcpy(cliente.domicilio.cpos,aux.domicilio.cpos);
            strcpy(cliente.domicilio.nro,aux.domicilio.nro);
            strcpy(cliente.domicilio.provincia,aux.domicilio.provincia);

            system("pause");
            system("cls");
            break;

        case 3:
            printf("cpos:         \n");
            fflush(stdin);
            gets(palabraAux);
            while(!validarNum(palabraAux))
            {
                printf("datos invalidos, intente nuevamente\n");    ///
                system("pause");
                system("cls");
                printf("ingrese el nombre del cliente: \n");
                fflush(stdin);
                gets(palabraAux);
            }

            //      strcpy(cliente.cpos,palabraAux);

            strcpy(cliente.nombre,aux.nombre);
            strcpy(cliente.apellido,aux.apellido);
            cliente.nroCliente=aux.nroCliente;
            strcpy(cliente.dni,aux.dni);
            strcpy(cliente.domicilio.calle,aux.domicilio.calle);
            strcpy(cliente.domicilio.localidad,aux.domicilio.localidad);
            strcpy(cliente.domicilio.nro,aux.domicilio.nro);
            strcpy(cliente.domicilio.provincia,aux.domicilio.provincia);

            system("pause");
            system("cls");
            break;

                        case 4:
                            printf("nro:         \n");
                            fflush(stdin);
                            gets(palabraAux);
                            while(!validarNum(palabraAux))
                                {
                                    printf("datos invalidos, intente nuevamente\n");    ///
                                    system("pause");
                                    system("cls");
                                    printf("ingrese el nombre del cliente: \n");
                                    fflush(stdin);
                                    gets(palabraAux);
                            }

                            strcpy(cliente.domicilio.nro,palabraAux);

                            strcpy(cliente.nombre,aux.nombre);
                            strcpy(cliente.apellido,aux.apellido);
                            cliente.nroCliente=aux.nroCliente;
                            strcpy(cliente.dni,aux.dni);
                            strcpy(cliente.domicilio.calle,aux.domicilio.calle);
                            strcpy(cliente.domicilio.localidad,aux.domicilio.localidad);

                            strcpy(cliente.domicilio.cpos,aux.domicilio.cpos);
                            strcpy(cliente.domicilio.provincia,aux.domicilio.provincia);

                            system("pause");
                            system("cls");
                            break;

                            case 5:
                            printf("provincia:         \n");
                            fflush(stdin);
                            gets(palabraAux);
                            while(!validarNum(palabraAux)){
                                    printf("datos invalidos, intente nuevamente\n");    ///
                                    system("pause");
                                    system("cls");
                                    printf("ingrese el nombre del cliente: \n");
                                    fflush(stdin);
                                    gets(palabraAux);
                            }

                            strcpy(cliente.domicilio.provincia,palabraAux);

                            strcpy(cliente.nombre,aux.nombre);
                            strcpy(cliente.apellido,aux.apellido);
                            cliente.nroCliente=aux.nroCliente;
                            strcpy(cliente.dni,aux.dni);
                            strcpy(cliente.domicilio.calle,aux.domicilio.calle);
                            strcpy(cliente.domicilio.localidad,aux.domicilio.localidad);
                            strcpy(cliente.domicilio.nro,aux.domicilio.nro);
                            strcpy(cliente.domicilio.cpos,aux.domicilio.cpos);


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


    }
    while((opcion<0 && opcion>4)||control=='s');


    return cliente;

}


///--------------------------------------------------------------------------------------------------


void mostrarClientes(char nombreArchivo[],int cantDeClientes)
{
    stCliente cliente;
    int contador=0;
    FILE* archivo = fopen(nombreArchivo, "rb");
    if (archivo)
    {
        mostrarEncabezadoCliente();
        while(fread(&cliente,sizeof(stCliente),1,archivo)>0)
        {
            if(contador%cantDeClientes==0)
            {
                printf("\n");

            }
            muestraListadoClienteInfoPrincipal(cliente);
        }
        fclose(archivo);
    }
}

int traducirDniaIdCliente(char archivoCliente[],char dni[])///no muestra si retorna -1 no esta, si retorna menores esta repetido, positivos es el id
{
    int id =-1;
    int bandera=0;
    stCliente cliente;
    FILE * archivo = fopen(archivoCliente,"rb");

    if(archivo)
    {

        while(fread(&cliente,sizeof(stCliente),1,archivo)>0)

            if(strcmp(cliente.dni,dni)==0)
            {
                id=cliente.id;
                bandera=bandera-1;

            }
        fclose(archivo);
    }
    if(bandera<-1)
    {
        id=bandera;
    }

    return id;
}


int ingresarDniClienteValido(char nombreArchivo[]) /// resultados: >=0 ID, -1 Escapo, <-1 duplicado el DNI
{
    int idCliente=-2;
    char dni[10];
    int opcion=1;
    do
    {
        printf("Ingrese un DNI del cliente exitente: ");
        fflush(stdin);
        scanf("%s",&dni);
        idCliente=traducirDniaIdCliente(nombreArchivo,dni); /// -1 no esta, >-1 repetido, <0 el i
        if(idCliente==-1)
        {
            printf("\nNro de DNI no valido, desea probar con otro Nro de DNI?");
            printf("\n1. Si, quiero probar con otro DNI \n2. No, quiero volver al menu anterior");
            printf("\n Opcion: ");
            scanf("%d",&opcion);
            if(opcion == 2)
            {
                idCliente=-1;
            }
        }/// dar opcion de escape y resultado 0 para que sepa que esta escapando y no es un Id
    }
    while(opcion==1 && idCliente==-1);


    return idCliente;
}

int muestraUnClienteXDni (char nombreArchivo[], char dni, stCliente cliente) /// muestra todos pero retorna el ultimo id. la cambiaria a void y usaria la de abajo para int
{
    int id = -1; //Por si el dni a buscar no esta en cliente.
    FILE* archivo = fopen(nombreArchivo, "rb");

    if(archivo)
    {
        while (fread(&cliente, sizeof(stCliente), 1, archivo) > 0)
        {
            if (strcmp(dni,cliente.dni) == 0)
            {
                muestraUnCliente(cliente);
                id = cliente.id;
            }
        }
        fclose(archivo);
    }

    return id;
}

int mostrarClientesDNIDevolverId(char archivoCliente[], char dni[]) /// para mostrar y seleecionar clientes con DNI duplicados id, -1 escapo -2 no encontro
{
    int id =-1;
    int* ids = (int*)malloc(sizeof(int));
    ids[0] = -2;
    int validos=0;
    int opcion;
    stCliente cliente;
    FILE * archivo = fopen(archivoCliente,"rb");
    if(archivo)
    {
        while(fread(&cliente,sizeof(stCliente),1,archivo)>0)
        {

            if(strcmp(cliente.dni,dni)==0)
            {
                ids[validos]=cliente.id;
                validos=validos+1;
                printf("\n%d - Cliente---------------------------------------: ",validos);
                muestraUnCliente(cliente);
                system("pause");
                ids = (int*)realloc(ids,(validos+1)*sizeof(int));
            }
        }
        fclose(archivo);
    }
    id=ids[0]; // -2 si no encuentra ninguno o id del primero encontrado 1
    if(validos>1) // entra solo si hay más de uno sino valido es 0 o 1
    {
        id=-1; // opcion de escape si selecciona otra cosa cambia
        printf("\nSeleccione el Nro de Cliente o 0 para salir: ");
        fflush(stdin);
        scanf("%d",&opcion);
        while (opcion>validos || opcion < 0)
        {
            printf("\nSeleccione una opcion valida entre 1 y %d: ",validos);
            fflush(stdin);
            scanf("%d",&opcion);
        }
        if (opcion == 0)
        {
            id=-1;
        }
        if (opcion !=0)
        {
            id=ids[opcion-1];// asigna la opcion
        }
    }
    free(ids);
    return id;
}

void traducirIdClientePorDNI(char achivoCliente[], int idCliente, char dniretorna[]) /// retorna arreglo vacio si no esta o el dni
{
    int bandera=0;
    stCliente cliente;
    FILE * archivo = fopen(achivoCliente,"rb");
    if(archivo)
    {
        while(bandera ==0 && fread(&cliente,sizeof(stCliente),1,archivo)>0)
        {

            if(cliente.id==idCliente)
            {
                bandera = 1;
                strcpy(dniretorna,cliente.dni);
            }
        }
        fclose(archivo);
    }
    if (bandera==0)
    {
        dniretorna[0] = '\0';
    }
}


/// Funciones de Cuenta:
stCuentas cargaUnaCuenta(char nombreArchivo[]) ///Carga 1 sola cuenta, retorna stCuentas cuenta.
{

    int opcion=0;
    stCuentas Cuenta;
    stCliente Cliente;
    char dni[10];

    printf("Conoce el Id de Cliente o lo quiere buscar por nro de Dni? \n");
    printf("1. Lo conozco. \n");
    printf("2. Lo tengo que buscar. \n");
    scanf("%d", &opcion);

    system("cls");
    system("pause");

    while(opcion > 2 || opcion < 1) //Bucle para que no pueda pasar si no elige una opcion valida.
    {
        printf("Seleccione una opcion valida: \n");
        printf("1. Conozco el Id del Cliente. \n");
        printf("2. Lo tengo que buscar. \n");
        fflush(stdin);
        scanf("%d", &opcion);
    }


    if ( opcion == 2)
    {
        do
        {
            printf("Ingrese el Dni del Cliente que quiere buscar: \n");
            fflush(stdin);
            gets(&Cliente.dni);
            Cuenta.idCliente = mostrarClientesDNIDevolverId(nombreArchivo,Cliente.dni); ///devuelve: id, -1 escapo, -2 no encontro
            ///Para mostrar y seleccionar clientes con DNI, retorna id.
            ///Si hay duplicados te muestra todos los clientes que hay con ese DNI y podes ingresar el id correpondiente.
            if(Cuenta.idCliente==-2)
            {
                printf("\nNo existe ese DNI ingrese 1. para salir u cualquier otro para seguir: ");
                scanf("%d",&opcion);
            }
        }
        while(opcion !=1 && Cuenta.idCliente == -2);/// No existe el dni.

        if(opcion == 1 || Cuenta.idCliente==-1) /// Opcion de escape porque no sabe el dni.
        {
            Cuenta.id=-2;
            return Cuenta;
        }
    }


    while(opcion==1) /// Eligio la opcion 1 porque sabe el Id.
    {
        printf("\nIngrese el Id de Cliente: \n");
        fflush(stdin);
        scanf("%d", &Cuenta.idCliente);
        traducirIdClientePorDNI(nombreArchivo, Cuenta.idCliente, dni);  // Traduce el id ingresado a un dni en stClientes para chequear que exista.
        if(dni[0] == '\0')// Si el dni no existe te deja el string vacio.
        {
            printf("\nNo existe ese Id de Cliente, ingrese 1 para seguir probando u otro numero para salir");
            fflush(stdin);
            scanf("%d", &opcion);
            if(opcion!=1)
            {
                Cuenta.id=-2;
                return Cuenta;//Se retorna una Cuenta con id -2, para filtrarla mas tarde y que no quede cargada en el archivo.
                //A esta cuenta no se le siguen agregando datos.
            }
        }
        else //Si existe te confirma el ingreso.
        {
            printf("Se ingreso el IdCliente %d que se corresponde con el DNI %s", Cuenta.idCliente, dni);
            opcion = 0; // Lo igualamos a 0 para dejarlo limpio y poder usarlo mas adelante.
        }
    }



    printf("\nSeleccione el tipo de cuenta que quiere abrir: \n");
    printf("1. Caja de ahorro en pesos. \n");
    printf("2. Caja de ahorro en dolares. \n");
    printf("3. Cuenta corriente en pesos. \n");
    scanf("%d", &Cuenta.tipoDeCuenta);

    while(Cuenta.tipoDeCuenta > 3 || Cuenta.tipoDeCuenta < 1)// Bucle para que ingrese una opcion valida.
    {
        printf("Opcion no valida. \n");
        printf("Seleccione un tipo de cuenta valido: \n");
        printf("1. Caja de ahorro en pesos. \n");
        printf("2. Caja de ahorro en dolares. \n");
        printf("3. Cuenta corriente en pesos. \n");
        scanf("%d", &Cuenta.tipoDeCuenta);
    }

    //Se cargan costos iniciales que después mes a mes pueden ir variando.
    if(Cuenta.tipoDeCuenta == 1)
    {
        Cuenta.costoMensual = 0;
    }

    if(Cuenta.tipoDeCuenta == 2)
    {
        Cuenta.costoMensual = 45;
    }

    if(Cuenta.tipoDeCuenta == 3)
    {
        Cuenta.costoMensual = 16200;
    }

    Cuenta.saldo = 0; //Lo iniciamos en 0 por ser cuenta nueva.

    Cuenta.eliminado = 0;//Al estar creandola el estado es activo.

    return Cuenta;
}

void cargaCuentaArch(char nombreArchivo[], char nombreArchivoCliente[], stCuentas cuenta)///Pasa al archivo el stCuenta cuenta de CargaUnaCuenta.
{
    if(cuenta.id!=-2) /// Filtro para que si la carga fue cortada al principio no se cargue en el archivo.
    {
        int cantidadDeCuenta=0;
        char dni[10];
        FILE* archivo = fopen(nombreArchivo, "ab");

        if(archivo)
        {
            cuenta.id = cuentaRegistrosGral(nombreArchivo,sizeof(stCuentas)) + 1;//Te retorna la cantidad de regitros ya guardados
            //le sumamos 1 para convertirlo en id.

            /// Generador del nroCuenta = cuenta.nroCuenta.
            cantidadDeCuenta = contarCuentasPorIdClientePorTipo(nombreArchivo,cuenta.idCliente,cuenta.tipoDeCuenta);
            //Retorna la cantidad de cuentas de cada tipo que tiene un cliente.
            traducirIdClientePorDNI(nombreArchivoCliente,cuenta.idCliente,dni);
            //Traducimos el idCliente que tenemos a dni para usarlo en el nro de cuenta.
            cuenta.nroCuenta=componerNroCuenta(cantidadDeCuenta,dni,cuenta.tipoDeCuenta,1);
            //Concatenamos el nro d sucursal (1, un digito), cantidad de cuentas x tipo (3 digitos), 4 primeros nros del dni y tipo de cuenta (1, 2 o 3).
            muestraUnaCuenta(cuenta,nombreArchivoCliente);


            getch();
            printf("\nDesea confirmar la carga? \n 1. Si \n 2. No\n");
            scanf("%d",&cantidadDeCuenta);
            system("cls");
            if(cantidadDeCuenta)
            {
                fwrite(&cuenta, sizeof(stCuentas), 1, archivo);
            }
            fclose(archivo);
        }
    }
}

int componerNroCuenta(int cantidadDeCuenta,char dni [],int tipoDeCuenta, int sucursal)/// Componemos el nro de cuenta.
{
    //Concatenamos el nro d sucursal (1, un digito), cantidad de cuentas x tipo (3 digitos), 4 primeros nros del dni
    //y tipo de cuenta (1, 2 o 3).
    int numeroCuentaInt = tipoDeCuenta+(dni[3]-48)*10+(dni[2]-48)*100+(dni[1]-48)*1000+(dni[0]-48)*10000+cantidadDeCuenta*100000+sucursal*100000000;
    printf("\nNumero de Cuenta: %d",numeroCuentaInt);
    return numeroCuentaInt;
}

int contarCuentasPorIdClientePorTipo(char nombreArchivo[],int idCliente, int tipoDeCuenta) //Retorna la cantidad de cuentas de por tipo que tiene el cliente.
{
    int contador=0;
    stCuentas cuenta;
    FILE* archivo = fopen(nombreArchivo,"rb");
    if(archivo)
    {
        while(fread(&cuenta,sizeof(stCuentas),1,archivo)>0)
        {
            if(cuenta.idCliente==idCliente)
            {
                if(cuenta.tipoDeCuenta==tipoDeCuenta)
                {
                    contador=contador+1;
                }
            }
        }
        fclose(archivo);
    }
    return contador;
}

void encabezadoCuenta()
{
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("%-10s | %-10s | %-20s | %-20s | %-10s | %-10s\n",
           "DNI", "NroCuenta", "TipoDeCuenta", "CostoMensual", "Saldo", "Estado");
    printf("-----------------------------------------------------------------------------------------------------------------\n");
}

void muestraUnaCuentaListadoConId(stCuentas Cuenta, char archivoCliente[])//Te muestra una cuenta en base al id.
{
    char dni[10];
    traducirIdClientePorDNI(archivoCliente,Cuenta.idCliente,dni);//Para mostrarle el dni en el listado y no el id que no es facil de relacionar al cliente.

    printf("%-10s | %-10d | %-20d | %-20.2f | %-10.2f | %-10s| %-20d \n",
           dni,
           Cuenta.nroCuenta,
           Cuenta.tipoDeCuenta,
           Cuenta.costoMensual,
           Cuenta.saldo,
           Cuenta.eliminado == 1 ? "Inactiva" : "Activa",Cuenta.id);
}

void muestraUnaCuenta(stCuentas Cuenta,char archivoCliente[]) ///Muestra cuenta antes de guardar en archivo.
{
    char dni[10];
    traducirIdClientePorDNI(archivoCliente,Cuenta.idCliente,dni);
    printf("\nLos datos de la cuenta cargada son:");
    printf("\nEl DNI: %s", dni);
    printf("\nEl Id del Cliente: %d", Cuenta.idCliente);
    printf("\nEl Nro de Cuenta: %d", Cuenta.nroCuenta);
    printf("\nEl tipo de Cuenta: %.2f", Cuenta.tipoDeCuenta);
    printf("\nEl costo mensual de la Cuenta es: %.2f", Cuenta.costoMensual);
    printf("\nEl saldo actual de la Cuenta es: %d", Cuenta.saldo);
    if(Cuenta.eliminado == 1)
    {
        printf("\nLa cuenta no esta activa.");
    }
    else
    {
        printf("\nLa cuenta esta activa.");
    }
}

int verificarNroDeCuenta(int numeroCuenta, char nombreCuenta[]) ///Chequea la existencia del nro cuenta, para el entrelazado con los movimientos.
{
    int bandera = 0;
    int idCuenta = -1;
    stCuentas cuenta;
    FILE* archivo = fopen(nombreCuenta,"rb");
    if (archivo)
    {
        while (fread(&cuenta,sizeof(stCuentas),1,archivo)>0)
        {

            if(cuenta.nroCuenta==numeroCuenta)
            {
                bandera = bandera -1;
                idCuenta=cuenta.id;
            }
        }

        fclose(archivo);
    }
    if(bandera <-1)
    {
        idCuenta=bandera;
    }
    return idCuenta;// -1 si no existe, idCuenta si existe y de -1 para abajo si hay más de una.
}

int ingresarNroCuentaValido(char nombreArchivo[], char nombreArchivoCliente[]) ///En movimintos ingresan el nro de cuenta al que quieren cargarle el movimiento.
{
    int idCuenta;
    int nroCuenta;
    int opcion=1;
    printf("Ingrese Nro de Cuenta\n");
    scanf("%d",&nroCuenta);
    idCuenta=verificarNroDeCuenta(nroCuenta, nombreArchivo); /// -1 si no existe, idCuenta si existe y de -1 para abajo si hay más de una.

    system("cls");
    getch();

    while(opcion==1 && idCuenta==-1)
    {
        printf("Ingrese Nro de Cuenta valido\n");
        scanf("%d",&nroCuenta);
        idCuenta=verificarNroDeCuenta(nroCuenta, nombreArchivo);//Vuelve a comprobarlo.

        system("cls");
        getch();

        if(idCuenta == -1)
        {
            printf("\nNro de Cuenta no valido, desea probar con otro Nro de cuenta?");
            printf("\n1. Si, quiero probar con otro Nro de Cuenta. \n2. No, quiero volver al menu anterior.\n Opcion: ");
            scanf("%d",&opcion);

        }/// Le damos la opcion de salir del bucle, el idcuenta permanece en -1.
    }

    if(idCuenta < -1)/// El numero de cuenta es valido pero hay mas de una con ese nro.
    {
        idCuenta = resolverCuentasDuplicadas(nombreArchivo,nombreArchivoCliente,nroCuenta); // Devuelve el idCuenta final a usar o -1 si escapo.
    }
    if(opcion == 2)
    {
        idCuenta = -1;
    }

    return idCuenta; /// Retorna -1 si escapo o el idCuenta.
}

int resolverCuentasDuplicadas(char nombreArchivo[], char nombreArchivoCliente[],int nroCuenta) ///Para seleccionar el id correcto al cargarle el movimiento en caso de que haya un nro de cta repetido.
{

    int id;
    int* ids = (int*)malloc(sizeof(int));
    int validos=0;
    int opcion;
    stCuentas cuenta;
    FILE* archivo = fopen(nombreArchivo,"rb");
    if (archivo)
    {

        while(fread(&cuenta,sizeof(stCuentas),1,archivo)>0)
        {
            if(cuenta.nroCuenta == nroCuenta)
            {
                ids[validos] = cuenta.id;
                validos++;
                printf("\n%d - Cuenta ---------------------------------------------------------------------- ", validos);
                muestraUnaCuenta(cuenta,nombreArchivoCliente);
                printf("\n --------------------------------------------------------------------------------");
                ids = (int*)realloc(ids,(validos+1)*sizeof(int));
            }
        }
        fclose(archivo);
    }

    do
    {
        printf("\nSeleccione el Id de Cuenta o elija 0 para salir: ");
        scanf("%d",&opcion);
    }
    while (opcion > validos || opcion < 0);

    if (opcion == 0)
    {
        id = -1; // Escapa.
    }
    else
    {
        id = ids[opcion-1];// Le asignamos a id la opcion elegida, como usamos validos se le resta 1.
    }
    free(ids);
    return id; // Retorna el id cuenta o -1 si escapa.
}

void cambiarEstadoCuenta(char nombreArchivo[], int idCuenta, int estado)///Cambia el estado de la cta.
{

    stCuentas Cuenta;
    FILE* archivo = fopen(nombreArchivo, "r+b");
    if(archivo)
    {
        fseek(archivo, idCuenta*sizeof(stCuentas), 0);
        fread(&Cuenta, sizeof(stCuentas), 1, archivo);
        Cuenta.eliminado = estado;
        fseek(archivo, -1*sizeof(stCuentas), 1);
        fwrite(&Cuenta, sizeof(stCuentas), 1, archivo);

        fclose(archivo);
    }
}

void modificarCostoCuentaPorId(char nombreArchivo[], int idCuenta, float nuevoCosto)///En base al idCuenta cambiamos el costo.
{
    stCuentas Cuenta;
    FILE* archivo = fopen(nombreArchivo, "r+b");
    if(archivo)
    {
        fseek(archivo, idCuenta*sizeof(stCuentas), 0);
        fread(&Cuenta, sizeof(stCuentas), 1, archivo);
        modificarCostoCuenta(&Cuenta, nuevoCosto);//Guardamos el nuevo costo.
        fseek(archivo, -1*sizeof(stCuentas), 1);
        fwrite(&Cuenta, sizeof(stCuentas), 1, archivo);

        fclose(archivo);
    }
}

void modificarCostoCuenta(stCuentas* cuenta, float nuevoCosto)///Modifica el costo mensual.
{
    cuenta->costoMensual=nuevoCosto;
}

void muestraPorIdCuenta(char nombreArchivo[],char nombreArchivoCliente[], int idCuenta)///Muestra una cta por idCuenta en texto(usarla para mostrar uno solo).
{

    stCuentas cuenta;
    FILE *archivo = fopen(nombreArchivo, "rb");

    if (archivo)
    {
        fseek(archivo,idCuenta*sizeof(stCuentas),0);
        fread(&cuenta,sizeof(stCuentas), 1, archivo);
        muestraUnaCuenta(cuenta,nombreArchivoCliente);
        fclose(archivo);
    }
    printf("\n");
    printf("\n");
}

void mostrarCuentasxIdCliente(char archivoCuenta[], int idCliente, char archivoCliente[])///Muestra una cuenta en base al id.
{
    stCuentas cuenta;
    FILE * archivo = fopen(archivoCuenta,"rb");
    if(archivo)
    {
        encabezadoCuenta();
        while(fread(&cuenta,sizeof(stCuentas),1,archivo)>0)
        {
            if(cuenta.idCliente==idCliente)
            {

                muestraUnaCuentaListadoConId(cuenta,archivoCliente);
            }
        }
        fclose(archivo);
    }
}

int mostrarCuentasxIdClienteSeleccionar(char archivoCuenta[], char archivoCliente, int idCliente) ///Poder ver todos los idCuenta en base a un idCliente.
{
    stCuentas cuenta;
    int id = -1;
    int* ids = (int*)malloc(sizeof(int));
    int validos = 0;
    int opcion = 4;
    FILE * archivo = fopen(archivoCuenta,"rb");
    if(archivo)
    {
        while(fread(&cuenta,sizeof(stCuentas),1,archivo)>0)
        {

            if(cuenta.idCliente == idCliente)
            {

                ids[validos] = cuenta.id;
                validos++;
                printf("\n%d - Cuenta: ", validos);
                muestraUnaCuenta(cuenta,archivoCuenta);
                ids = (int*)realloc(ids,(validos + 1)*sizeof(int));
            }
        }
        fclose(archivo);
    }

    /// Si validos = 0 no hay cuentas con ese idCliente, validos = 1 hay una sola, validos > 1 esa cant de cuentas para ese idCliente.

    if(validos > 1)
    {
        printf("\nSeleccione el Nro de Cuenta o elija 0 para salir: ");
        scanf("%d", &opcion);
        while (opcion>validos || opcion < 0)
        {
            printf("\nSeleccione una opcion valida entre 0 y %d: ", validos);
            scanf("%d", &opcion);
        }
    }
    if (opcion != 0) /// mantiene -1 porque opcion fue 0
    {
        id=ids[opcion-1]; /// Eligio la cta correspondiente, se le resta uno pq se lo habiamos sumado para el printf.
    }
    if (validos == 0)
    {
        id=-2; /// El idCliente no tiene cuentas.
    }
    if (validos == 1)
    {
        id=ids[0];
    }
    free(ids);
    return id; ///Retorna el idCuenta o -2 si no tiene cuentas ese idCliente.
}

void buscarCuentaModificarSaldo(char nombreArchivoCu[], int idCuenta, float importe)///Te posicionas en el idCuenta al q le queres modificar el saldo y lo modificas.
{
    stCuentas cuenta;
    FILE * archivo = fopen(nombreArchivoCu,"r+b");
    if( archivo)
    {
        fseek(archivo,(idCuenta)*sizeof(stCuentas),0);
        fread(&cuenta,sizeof(stCuentas),1,archivo);

        cuenta.saldo = cuenta.saldo+importe;

        fseek(archivo,(idCuenta)*sizeof(stCuentas),0);
        fwrite(&cuenta,sizeof(stCuentas),1,archivo);
        fclose(archivo);
    }
}

void mostrarArchivoCuentas(char archivoCuenta[], char archivoCliente[], int cantidad)///Mientras haya cuentas guardadas en el archivo, las muestra en listado.
{
    stCuentas cuenta;
    FILE * archivo = fopen(archivoCuenta,"rb");
    if(archivo)
    {
        encabezadoCuenta();
        while(fread(&cuenta,sizeof(stCuentas),1,archivo)>0)
        {
            muestraUnaCuentaListadoConId(cuenta,archivoCliente);
        }
        fclose(archivo);
    }
}

/// funciones de movimiento

stMovimientos cargaManualMovimiento(char ArchivoCuentas[], char ArchivoCliente[])
// Utiliza el Archivo Cuentas para chequear y conseguir el IdCuenta correcto
// Utiliza el Archivo Clientes para ayudar a ubicar en Nro de cuenta y posteriormente el IdCuenta correspondiente
// Devuelve un Movimiento con dos posibles idClientes
// idCliente = -1 es que termino la carga completa
// idCliente = -2 es que por alguna razon decidio cancelar la carga y no debe cargarse en el archivo movimientos
{
    stMovimientos movimiento;
    stCliente cliente;
    int opcion=0;
    int nroCuenta;
    int idCliente;
    movimiento.id=-1; /// aun no cargado en el archivo de movimientos

    printf("\n Conoce el Nro de Cuenta del Movimiento\n 1. Si\n 2. No \n Eleccion?: ");
    fflush(stdin);
    scanf("%d",&opcion);
    if(opcion==2)
    {
        do
        {
            printf("\n Ingrese el DNI del cliente: ");
            fflush(stdin);
            scanf("%s",&cliente.dni);
            idCliente=mostrarClientesDNIDevolverId(ArchivoCliente,cliente.dni);
            /// para mostrar y seleecionar clientes con DNI duplicados id, -1 escapo o -2 no esta

            if (idCliente==-2)
            {
                printf("\nNo existe ese DNI en el listado de clientes, ingrese 2 para intentar nuevamente: ");
                scanf("%d",&opcion);
            }
        }
        while(opcion == 2 && idCliente==-2); //Resultados del while: opcion !=2 o idCluente =-1 (escapo), sino idCliente

        if(opcion!=2 || idCliente==-1) // escapo
        {
            movimiento.id=-2;
            return movimiento;
        }

        movimiento.idCuenta=mostrarCuentasxIdClienteSeleccionar(ArchivoCuentas,ArchivoCliente,idCliente); /// obtener idCuenta / escapa -1 / no hay -2
        if(movimiento.idCuenta==-2)
        {
            printf("\nEl dni %s, no tiene Cuentas, debe crearle al menos una cuenta para ser asignada",cliente.dni);
            movimiento.id=-2;
            return movimiento;
        }
        if(movimiento.idCuenta==-1)
        {
            movimiento.id=-2; /// condicion para no cargarlo en carga archivo
            return movimiento;
        }
    }
    else
    {
        movimiento.idCuenta=ingresarNroCuentaValido(ArchivoCuentas,ArchivoCliente); /// -1 escapo, 0< idCuenta
        if (movimiento.idCuenta==-1)
        {
            movimiento.idCuenta=-2;
            return movimiento;
        }
    }
    printf("\n Ingrese el detalle de la operacion: ");
    fflush(stdin);
    gets(movimiento.detalle);

    printf("\n Ingrese el importe del movimiento: ");
    scanf("%f",& movimiento.importe);

    ingresarfecha(&movimiento.anio,&movimiento.mes, &movimiento.dia);


    movimiento.eliminado=0;

    return movimiento;
}

void cargarUnMovimientoArchivo(char ArchivoMovimientos[], char ArchivoCuentas[], stMovimientos movimiento)
{
// recibe un movimiento y dependiendo del id.Movimiento
    // id.movimiento = -2 no carga el movimiento por que significa que no esta bien cargado
    // id.movimiento != -2
    // carga el movimiento le asigna el numero de registro (0 para el primero) y modifica el saldo de la cuenta si el movimiento no esta eliminado
    // como esta permitido cargar movimientos de fechas anteriores se permite cargar en cuentas que no esten activas
    int opcion=0;
    if(movimiento.id!=-2)
    {
        movimiento.id=cuentaRegistrosGral(ArchivoMovimientos,sizeof(stMovimientos));
        FILE *archivo = fopen(ArchivoMovimientos, "ab");
        if(archivo)
        {
            printf("\nConfirma la carga del siguiente movimiento");

            mostrarEncabezadoMovimiento();
            mostrarUnMovimiento(movimiento);
            printf("\nIngrese 1 para confirmar u otra para cancelar: ");
            scanf("%d",&opcion);
            if(opcion==1) /// permite anular la carga
            {
                fwrite(&movimiento,sizeof(stMovimientos), 1, archivo);
                if (movimiento.eliminado==0)
                {
                    buscarCuentaModificarSaldo(ArchivoCuentas,movimiento.idCuenta,movimiento.importe);
                }
            }
            fclose(archivo);
        }
    }
}

int ingresarIdMovValido(char archivoMovimiento[]) /// devuelve idMovmiento
// pide ingresar un idMovimiento y verifica que sea un numero de movimiento valido entre 0 y el numero de registros regresando un id valido
{
    int IdMovimiento=0;
    int cantidad=cuentaRegistrosGral(archivoMovimiento,sizeof(stMovimientos));
    do
    {
        printf("\nIngrese un Nro de movimiento Valido (Max. Nro: %d)",cantidad);
        fflush(stdin);
        scanf("%d",&IdMovimiento);
    }
    while (cantidad<IdMovimiento);
    return IdMovimiento;
}

void modificarEstadoIdMovimiento(char archivoMovimiento[], int idMovimiento, int estado,char nombreArchivoCu[])
// recibe archivo de movimiento y el de cuenta porque ademas de modificar el estado de movimiento
// en caso de cambiar el estado tiene que modificar el saldo de la cuenta ya sea
// restando el importe si activa un movimiento o sumando si desactiva el movimiento
{

    stMovimientos movimiento;
    FILE * archivo = fopen(archivoMovimiento,"r+b");
    if( archivo != NULL)
    {
        fseek(archivo,(idMovimiento)*sizeof(stMovimientos),0);
        fread(&movimiento,sizeof(stMovimientos),1,archivo);
        if(movimiento.eliminado!=estado)
        {
            if(estado==1)
            {
                buscarCuentaModificarSaldo(nombreArchivoCu,movimiento.idCuenta,-movimiento.importe);
            }
            else
            {
                buscarCuentaModificarSaldo(nombreArchivoCu,movimiento.idCuenta,movimiento.importe);
            }
            movimiento.eliminado=estado;
            fseek(archivo,(idMovimiento)*sizeof(stMovimientos),0);
            fwrite(&movimiento,sizeof(stMovimientos),1,archivo);
        }
        fclose(archivo);

    }
}

void modificarRegistroDeUnMovimiento(char ArchivoMovimientos[], int numeroDeRegistro, char nombreArchivoCu[])
// llama a la funcion mostrarxModificarMovimiento(arreglo de dos movimientos: original y modificado) y modifica los resultados
//    - solo va a permitir modificar: el resto de entendemos que no deben modificarse
//         * Detalle de la operacion
//         * El estado del movimiento
//         * La fecha
{
    printf("\n---------------------\n modificar movimiento");
    stMovimientos arreglo[2];
    FILE * archivo = fopen(ArchivoMovimientos,"r+b"); /// tengo que lograr esto y listo
    if( archivo != NULL)
    {
        fseek(archivo,(numeroDeRegistro)*sizeof(stMovimientos),0);
        fread(&arreglo[0],sizeof(stMovimientos),1,archivo);
        mostrarxModificarMovimiento(arreglo);
        if(arreglo[1].eliminado!=arreglo[0].eliminado)
        {
            if(arreglo[1].eliminado==1)
            {
                buscarCuentaModificarSaldo(nombreArchivoCu,arreglo[0].idCuenta,-arreglo[0].importe);
            }
            else
            {
                buscarCuentaModificarSaldo(nombreArchivoCu,arreglo[0].idCuenta,arreglo[0].importe);
            }

        }
        fseek(archivo,(numeroDeRegistro)*sizeof(stMovimientos),0);
        fwrite(&arreglo[1],sizeof(stMovimientos),1,archivo);
        fclose(archivo);
    }
}


void mostrarxModificarMovimiento(stMovimientos arregloMovimiento[]) /// arregloMovimiento[0] original, arregloMovimiento[1] resultado
// sobre dos movimientos de un arreglo copia el primero al segundo y despues va preguntando opciones para mantener lo copiado o modificarlo
// como es un puntero el arreglo los cambios quedan en el segundo elemento del arreglo y el original queda igual para poder comparar cambios despues

{
    int opcion=0;
    arregloMovimiento[1]=arregloMovimiento[0];
    mostrarEncabezadoMovimiento();
    mostrarUnMovimiento(arregloMovimiento[0]);

    printf("\nDesea modificar el detalle de la operacion\n 1: Si\n 2:\nNo \nRespuesta: "); /// ver de mejorar la opcion
    scanf("%d",&opcion);
    if( opcion == 1)
    {
        printf("\n Ingrese el detalle de la operacion: ");
        fflush(stdin);
        gets(arregloMovimiento[1].detalle);
    }

    printf("\nDesea modificar la fecha del movimiento\n 1: Si\n 2:\No \nRespuesta: "); /// ver de mejorar la opcion
    scanf("%d",&opcion);
    if( opcion == 1)
    {
        printf("\n Ingresar nueva fecha del movimiento");
        ingresarfecha(&arregloMovimiento[1].anio, &arregloMovimiento[1].mes,&arregloMovimiento[1].dia);
    }

    printf("\nDesea modificar el estado del movimiento\n 1: Si\n 2:\No \nRespuesta: "); /// ver de mejorar la opcion
    scanf("%d",&opcion);
    if( opcion == 1)
    {
        printf("\n Ingrese el estado (0 si esta activo - 1 si esta eliminado): ");
        fflush(stdin);
        scanf("%d",& arregloMovimiento[1].eliminado);
    }
}

void mostrarEncabezadoMovimiento()
{
    printf("\nId del Mov | ");


    printf("Id de Cuenta | ");

    printf("Importe del Movimiento | ");


    printf("   Fecha   | ");

    printf("Estado | "); /// corregir el acento

    printf("Detalle de la operacion ");
}

void mostrarUnMovimiento(stMovimientos movimiento)
{

    printf("\n%04d       | ", movimiento.id);


    printf("%06d       | ", movimiento.idCuenta);

    printf("$ %20.2f | ", movimiento.importe);



    printf("%02d/%02d/%04d |",movimiento.dia, movimiento.mes, movimiento.anio);


    printf("    %d   | ", movimiento.eliminado); /// corregir el acento

    printf("%s", movimiento.detalle);

}

void muestraMovimientoPorIdCuenta(char archivoMovimientos[], int idCuenta, int cantidad)
// busca que coincida el idCuenta en el archivo de movimientos y muestra solo esos movimientos por cantidades fijas
{

    stMovimientos movimiento;
    int contador=0;
    FILE* archivo = fopen(archivoMovimientos, "rb");
    if(archivo)
    {


        while(fread(&movimiento,sizeof(stMovimientos),1,archivo)>0)
        {


            if(movimiento.idCuenta==idCuenta)
            {
                if(contador%cantidad==0)
                {
                    printf("\n");
                    system("pause");
                    mostrarEncabezadoMovimiento();

                }
                mostrarUnMovimiento(movimiento);
                contador=contador+1;
            }

        }
        fclose(archivo);
    }

}

void muestraMovimientoPorIdCuentaPorFecha(char archivoMovimientos[],int idCuenta,int anio0,int mes0,int dia0,int aniof,int mesf,int diaf,int cantidadmostrar)
// Muestra todos los movimientos entre dos fechas de una cuenta pausando cada la cantidad a mostrar en el numero cantidad a mostrar
{
    int contador;
    int fechaMax= aniof * 10000 + mesf * 100 + diaf;
    int fechaMin= anio0 * 10000 + mes0 * 100 + dia0;
    int fechaAux;
    stMovimientos aux;
    FILE* archivo = fopen(archivoMovimientos,"rb");
    if (archivo != NULL)
    {
        while(fread(&aux,sizeof(stMovimientos),1,archivo)>0)
        {
            if(aux.idCuenta==idCuenta)
            {
                fechaAux= aux.anio*10000 + aux.mes *100 + aux.dia;
                if (fechaMin<fechaAux)
                {
                    if(fechaMax>fechaAux)
                    {
                        if(contador%cantidadmostrar==0)
                        {
                            printf("\n");
                            mostrarEncabezadoMovimiento();
                            system("pause");
                        }
                        mostrarUnMovimiento(aux);
                        contador=contador+1;
                    }
                }
            }
        }
        fclose(archivo);
    }

}



void mostrarArchivoMovimiento(char ArchivoMovimientos[],int i)
// recorre todo el archivo copiando cada movimiento a un auxiliar y mostrando listas de un tamaño i
{
    FILE *archivo = fopen(ArchivoMovimientos,"rb");
    int contador=0;

    if(archivo !=NULL)
    {
        stMovimientos aux;

        while( (fread(&aux, sizeof(stMovimientos),1,archivo) ) >0)
        {
            if(contador%i==0)
            {
                printf("\n");
                system("pause");
                mostrarEncabezadoMovimiento();
            }
            mostrarUnMovimiento(aux);
            contador++;
        }
        fclose(archivo);
    }
}




///----------------Funciones nuevas en Movimiento para cobrar y actualizar la cuota

void actualizarMontoCuota(float arregloCuota[],char archivoCuotas[])
// recibe un arreglo donde se va a cargar los valores de las cuotas y un archivo donde esta el historial de los valores de las cuotas
// Lee los valores viejos y pregunta para carga nuevos valores o los viejos en el arreglo:
// - arreglo[0] valor de la cuota TIPO 1
// - arreglo[1] valor de la cuota TIPO 2
// - arreglo[1] valor de la cuota TIPO 2
{

    float valorPrueba;
    int opcion;
    FILE* archivo = fopen(archivoCuotas,"r+b");
    if (archivo)
    {
        fseek(archivo,-3*sizeof(int),2);
        fread(arregloCuota,sizeof(int),3,archivo);

        /// actualizar valor cuota 1
        do
        {
            printf("\nEl valor actual de la cuota del tipo 1 es $ %f, desea modificarla.", arregloCuota[0]);
            printf("\n1. Para modificar");
            printf("\n2. Para mantener el valor.");
            printf("\n2. Opcion: ");
            scanf("%d",&opcion);
        }
        while(opcion >2 || opcion <1);
        fseek(archivo,-3*sizeof(int),1);
        if(opcion==1)
        {
            printf("\nIngrese el nuevo valor: ");
            scanf("%f",&arregloCuota[0]);
            fwrite(&arregloCuota[0],sizeof(int),1,archivo);

            printf("\Se cargo el monto para el valor de la cuota de: %.2f",arregloCuota[0]);
        }
        else
        {
            fseek(archivo,sizeof(int),1);
        }

        /// actualizar valor cuota 2
        do
        {
            printf("\nEl valor actual de la cuota del tipo 2 es $ %.2f, desea modificarla.", arregloCuota[1]);
            printf("\n1. Para modificar");
            printf("\n2. Para mantener el valor");
            printf("\n2. Opcion: ");
            scanf("%d",&opcion);
        }
        while(opcion >2 || opcion <1);
        if(opcion==1)
        {
            printf("\nIngrese el nuevo valor: ");
            scanf("%f",&arregloCuota[1]);
            fwrite(&arregloCuota[1],sizeof(int),1,archivo);

            printf("\nSe cargo el monto para el valor de la cuota de: %.2f",arregloCuota[1]);
        }
        else
        {
            fseek(archivo,sizeof(int),1);
        }


        /// actualizar valor cuota 3
        do
        {
            printf("\nEl valor actual de la cuota del tipo 3 es $ %.2f, desea modificarla.", arregloCuota[2]);
            printf("\n1. Para modificar");
            printf("\n2. Para mantener el valor");
            printf("\n2. Opcion: ");
            scanf("%d",&opcion);
        }
        while(opcion >2 || opcion <1);
        if(opcion==1)
        {
            printf("\nIngrese el nuevo valor: ");
            scanf("%f",&arregloCuota[2]);
            fwrite(&arregloCuota[2],sizeof(int),1,archivo);

            printf("\nSe cargo el monto para el valor de la cuota de: %.2f",arregloCuota[2]);
        }

        fclose(archivo);
    }

}



void cargarMovimientoCuotaCuentas(char nombreCuenta[], char nombreMovimiento[], int anio, int mes, float arregloCosto[])
// Recibe el archivo Cuenta, el archivo de Movimiento, el mes y año y el Costo de las cuotas
// carga un movimiento por cada cuenta activa por el valor de la cuota y con los datos correspondientes
// actualiza el monto de la cuota y actualiza el saldo de la cuenta
{
    stMovimientos aux;
    stCuentas auxCuenta;
    aux.anio = anio;
    aux.mes = mes;
    aux.dia = 1;
    aux.eliminado = 0;
    strcpy(aux.detalle, "costo de cuenta P");
    int i = 0;

    FILE* archivo = fopen(nombreCuenta, "r+b");
    FILE* archiMovRAM = fopen(nombreMovimiento, "ab");

    if (archivo)
    {
        if (archiMovRAM)
        {
            fseek(archivo,0,0);
            while (fread(&auxCuenta, sizeof(stCuentas),1, archivo) == 1)
            {
                printf("\n%d",i);
                if (auxCuenta.eliminado == 0)
                {
                    printf("/");
                    // Movimiento - AuxCuenta
                    aux.idCuenta = auxCuenta.id;
                    aux.importe = -arregloCosto[auxCuenta.tipoDeCuenta - 1];
                    aux.id = ftell(archiMovRAM)/sizeof(stMovimientos);
                    fwrite(&aux,sizeof(stMovimientos),1,archiMovRAM);
                    auxCuenta.costoMensual = aux.importe; // Actualiza el valor de la cuota en la cuenta del cliente
                    auxCuenta.saldo = -aux.importe; // Modifica el saldo restando la cuota
                    fseek(archivo, -1 * sizeof(stCuentas), 1);
                    fwrite(&auxCuenta, sizeof(stCuentas), 1, archivo);
                    printf(" - IdCuenta %d",auxCuenta.id);
                    printf("- importe/cuota %f", auxCuenta.costoMensual);
                    fseek(archivo, 1* sizeof(stCuentas), 1);

                }
                i++;
                system("pause");
            }
            fclose(archiMovRAM);
        }
        fclose(archivo);
    }

    ///--------------------impares
    printf("\nImpares");
    i = 0;

    FILE* archiv = fopen(nombreCuenta, "r+b");
    FILE* archiMovRA = fopen(nombreMovimiento, "ab");

    if (archiv)
    {
        if (archiMovRA)
        {
            fseek(archiv,1*sizeof(stCuentas),0);
            while (fread(&auxCuenta, sizeof(stCuentas),1, archiv) == 1)
            {
                printf("\n%d",i);
                if (auxCuenta.eliminado == 0)
                {
                    printf("/");
                    // Movimiento - AuxCuenta
                    aux.idCuenta = auxCuenta.id;
                    aux.importe = -arregloCosto[auxCuenta.tipoDeCuenta - 1];
                    aux.id = ftell(archiMovRA)/sizeof(stMovimientos);
                    fwrite(&aux,sizeof(stMovimientos),1,archiMovRA);
                    auxCuenta.costoMensual = aux.importe; // Actualiza el valor de la cuota en la cuenta del cliente
                    auxCuenta.saldo = -aux.importe; // Modifica el saldo restando la cuota
                    fseek(archiv, -1 * sizeof(stCuentas), 1);
                    fwrite(&auxCuenta, sizeof(stCuentas), 1, archiv);
                    printf(" - IdCuenta %d",auxCuenta.id);
                    printf("- importe/cuota %f", auxCuenta.costoMensual);
                    fseek(archiv, 1* sizeof(stCuentas), 1);

                }
                i++;
                system("pause");
            }
            fclose(archiMovRA);
        }
        fclose(archiv);
    }







}

void verificaEjecutaActualizacionCobroCuota(char nombreCuenta[],char nombreMovimiento[], char RegistroCuotas[], int anio, int mes, float arregloCosto[])
// Recibe el archivo Registro de cuotas, el archivo Cuenta, el archivo de Movimiento, el mes y año y el Costo de las cuotas
// Verifica que no se haya ejecutado ya el cobro y en caso de que no ejecuta el cobro y actualiza el registro de cuotas y montos
{

    int fecharegis = anio * 10000 + mes * 100 + 1;
    int fecharegisaux;
    int bandera =0;
    FILE * archivoRegistroCuotasRAM = fopen(RegistroCuotas,"r+b");
    if (archivoRegistroCuotasRAM)
    {
        while(bandera==0 && fread(&fecharegisaux,sizeof(int),1,archivoRegistroCuotasRAM)>0)
        {
            if(fecharegisaux==fecharegis)
            {
                bandera=-1;
                printf("\n Ya estaba cobrada la cuota de este mes, no se cargaron los movimientos");
            }
        }
        if(bandera==0)
        {
            printf("\n Se procede a la carga de los movimientos.... ");
            system("pause");
            cargarMovimientoCuotaCuentas(nombreCuenta,nombreMovimiento,anio,mes,arregloCosto);
            fwrite(&fecharegis,sizeof(int),1,archivoRegistroCuotasRAM);
            printf("\n Finalizo la carga");

        }
        fclose(archivoRegistroCuotasRAM);
    }
}





/// funciones generales

void ingresarfecha(int* anio, int* mes, int* dia)
// solicita que se ingrese una fecha y valida el ingreso de una fecha
{
    // Obtener la fecha actual del sistema
    int diasPorMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    time_t t = time(NULL);
    struct tm fechaActual = *localtime(&t);

    int a, m, d; // Variables temporales para almacenar la entrada del usuario

    do
    {
        printf("\nIngrese el year: ");
        fflush(stdin);
        scanf("%d", &a);

        if (a == 0)
        {
            *anio = 0;
            *mes = 0;
            *dia = 0;
            return;
        }
    }
    while (a > fechaActual.tm_year + 1900);

    if(esBisiesto(a)==0)
    {
        diasPorMes[1]=29;
    }

    do
    {
        printf("\nIngrese el month (Meses validos 1-12): ");
        fflush(stdin);
        scanf("%d", &m);

        if (m == 0)
        {
            *anio = 0;
            *mes = 0;
            *dia = 0;
            return;
        }
    }
    while ((a == fechaActual.tm_year + 1900 && m > fechaActual.tm_mon + 1) || m>12 || m <1);

    do
    {
        printf("\nIngrese el day (Dias validos 1-%d): ", diasPorMes[m-1]);
        fflush(stdin);
        scanf("%d", &d);

        if (d == 0)
        {
            *anio = 0;
            *mes = 0;
            *dia = 0;
            return;
        }
    }
    while (d < 1 || d > diasPorMes[m-1] || ( a == fechaActual.tm_year + 1900 && m == fechaActual.tm_mon + 1 && d >= fechaActual.tm_mday));


    *anio = a;
    *mes = m;
    *dia = d;

}

int cuentaRegistrosGral(char nombreArchivo[], int tamanioUnSt)
// cuenta la cantidad de reguistros de un archivo de cualquier tipo teniendo que indicar el tamaño con sizeof(tipodedato)
{
    int cantidad=0;
    FILE* archivo = fopen(nombreArchivo,"rb");
    if(archivo)
    {
        fseek(archivo,0,2);
        cantidad = ftell(archivo)/tamanioUnSt;
        fclose(archivo);
    }
    return cantidad;
}

int cuentaRegistrosGralFILE(FILE* archivo, int tamanioUnSt)
{
    int cantidad=0;
    if(archivo)
    {
        fseek(archivo,0,2);
        cantidad = ftell(archivo)/tamanioUnSt;
    }
    return cantidad;
}


int esBisiesto(int anio) // Función para determinar si un año es bisiesto, (respuesta 1 no es, 0 es)
{
    int respuesta=1;
    if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0))
// Un año es bisiesto si es divisible por 4 salvo que sea divisible por 100. Por eso &&
// Pero los años divisibles por 400 sí son bisiestos. Por eso ||
    {
        respuesta = 0; //devuelve 0 si es bisiesto
    }
    return respuesta; // devuelve 1 si no es bisiesto
}

