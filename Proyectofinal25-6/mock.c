#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "general.h"

///Inicio funciones mock clientes

///Inicio funciones mock clientes

void getNombreRandom(char name[])
{
    char names[][35] = {"Emiliano","Gabriel","Luciano","Agustin","Julieta","Luis",
                        "Sofia","Rodrigo","Maria","Lucia","Estela","Rocio",
                        "Lucas","Mariel","Agustina","Fernanda","Guadalupe","Esteban","Estefania","Paula","Dominic",
                        "Efraim","Nicolas","Ignacio","Geraldine","Yair","Ezequiel","Mia","Isabela","Antonella","Luz","Camila","Leonel","Enzo","Raul"
                       };

    strcpy(name, names[rand() % 35]);
}

void getApellidoRandom(char apellido[])
{
    char apellidos[][33] = {"Rodriguez","Martinez","Gomez","Lopez","Perez","Diaz",
                            "Domingues","Guix","Gonzales","Peralta","Argento","Messi",
                            "De Paul","Fernandez","Alvarez","Paredes","Otamendi","Estebanez","Montiel","Palacios","Molina",
                            "Aguilar","Aguero","Di Maria","Gerez","Tintez","Florez","Linares","Rocuzzo","Ardiles","Leccese","Cervi","Ramirez"
                           };

    strcpy(apellido, apellidos[rand() % 33]);
}

void getDniRandom(char dni[])
{
    int numDni = (rand() % 50400673) + 10567123;
    sprintf(dni, "%08d", numDni);
}

void getTelefonosRand( char Telefonos[]){

char Telef[][15]={" 11 2345 6789","351 456 7890"," 342 987 6543","261 123 4567","381 765 4321","387 234 5678","264 987 1234",
"343 345 6789","388 456 7890"," 2920 678 9012","299 123 4567"," 383 765 4321","280 987 6543","266 345 6789"," 2954 234 5678"};
strcpy(Telefonos, Telef[rand()%(sizeof(Telef)/15)]);


}

void getMailsRand(char Mail[],char Nombre[], char Apellido[]){


    char a[60]={""};



     strcat(a,Apellido);
     printf("%s\n",a);
     strcat(a,Nombre);
     printf("%s\n",a);
     fflush(stdin);
     strcat(a,"@gmail.com");
     printf("%s\n",a);
     strcat(Mail,a);

     //strcat(a,MailRand[rand()%(sizeof(MailRand))/3]);
     //strcat(Mail,a);


}



///Fin funciones mock cliente
void clientesRandom(char archivoClientes[], int cantidad)
{
    stCliente aux;
    char auxiliarmail[40];
    int registros = cuentaRegistrosGral(archivoClientes, sizeof(stCliente));
    FILE *archi = fopen(archivoClientes, "ab");
    if (archi)
    {
        for (int i = registros; i < cantidad; i++)
        {


            strcpy(aux.domicilio.calle,"san martin");
            strcpy(aux.domicilio.nro,"2055");
            strcpy(aux.domicilio.localidad,"Mar del Plata");
            strcpy(aux.domicilio.provincia,"Bs As");
            strcpy(aux.domicilio.cpos,"7600");
            strcpy(aux.telefono,"2235882841");
            getApellidoRandom(aux.apellido);

            strcpy(aux.email,aux.apellido);
            strcat(aux.email,"@gmail.com");
            aux.email[0]=aux.apellido[0];

            getDniRandom(aux.dni);
            aux.eliminado = rand() % 2;
            getNombreRandom(aux.nombre);
            aux.nroCliente = (aux.dni[0]- '0')*100000+(aux.dni[1]- '0')*10000+(aux.dni[1]- '0')*1000+(aux.dni[1]- '0')*100+(aux.dni[1]- '0')*10+(aux.dni[1]- '0')*1;
            aux.id = i; // Autoincremental
            fwrite(&aux, sizeof(stCliente), 1, archi);
        }
        fclose(archi);
        /*typedef struct{
        x  int id; /// campo único y autoincremental
        x  int nroCliente;
        x  char nombre[30];
        x  char apellido[30];
        x  char dni[10];
        char email[30]; FALTA
        stDomicilio domicilio; FALTA TODO
            char calle[30];
            char nro[6];
            char localidad[30];
            char provincia[40];
            char cpos[6];
        char telefono[12]; FALTA
        x  int eliminado;
        }stCliente;
        */

    }
}




/// Cuentas

int getCuenta(char archivoCliente[], char archivoCuenta[], int cantidadDeCuentasGeneradas)
{
    char dni [10];
    stCuentas aux;
    int cantidadDeCuenta;
    int i=cuentaRegistrosGral(archivoCuenta,sizeof(stCuentas));
    int total=i+cantidadDeCuentasGeneradas;
    for(i; i<total; i++)
    {
        FILE* archivoCuentaRAM = fopen(archivoCuenta,"ab");
        if(archivoCuentaRAM)
        {
            aux.id=cuentaRegistrosGralFILE(archivoCuentaRAM,sizeof(stCuentas));


            aux.idCliente=rand()%cuentaRegistrosGral(archivoCliente,sizeof(stCliente));

            aux.tipoDeCuenta= rand()%3+1;
            cantidadDeCuenta=contarCuentasPorIdClientePorTipo(archivoCuenta,aux.idCliente, aux.tipoDeCuenta);
            if (cantidadDeCuenta<4)
            {
                switch (aux.tipoDeCuenta)
                {
                case 1:
                    aux.costoMensual= 10;
                    break;
                case 2:
                    aux.costoMensual= 20;
                    break;
                case 3:
                    aux.costoMensual= 30;
                    break;
                }
                traducirIdClientePorDNI(archivoCliente,aux.idCliente,dni);
                aux.nroCuenta=componerNroCuenta(cantidadDeCuenta,dni,aux.tipoDeCuenta, 1);
                aux.saldo=0;
                aux.eliminado=0;
                fseek(archivoCuentaRAM,0,2);
                fwrite(&aux,sizeof(stCuentas),1,archivoCuentaRAM);

            }
            fclose(archivoCuentaRAM);


        }
    }
}

/* typedef struct {

    int id; /// campo único y autoincremental
    int idCliente generar entre 0 y cantidad de registros archiCliente; /// Id del Cliente dueño de la Cuenta;
    int tipoDeCuenta generar entre 1 y 3; /// 1. Caja de Ahorro en Pesos, 2. Caja de Ahorro en Dólares, 3. Cta Cte en $
    float costoMensual; sacar de los tipos de cueta /// Costo de mantenimiento del producto;
    int nroCuenta traducir id a dni, componer NroCuenta;

    float saldo; es 0/// Debe actualizarse al modidificar o cargar un movimiento.
    int eliminado; generar al azar entre 0 y 1 /// 0 si está activo - 1 si está eliminado

} stCuentas;
*/





///movimientos

void getDayMonthYeard(stMovimientos* M)
{
/// para limitar a la fecha actual

    time_t tiempo_actual = time(NULL);
    struct tm *tiempo_local = localtime(&tiempo_actual);
    /// printf("Año: %d\n", tiempo_local->tm_year + 1900); // tm_year cuenta desde 1900
    /// printf("Mes: %d\n", tiempo_local->tm_mon + 1); // tm_mon cuenta desde 0 (enero = 0)
    /// printf("Día: %d\n", tiempo_local->tm_mday);


    M->anio = 2024 - (rand()%41); /// 2024 - numero entre 0 y 40

    /// mes


    M->mes = (rand()%12)+1;
    if( M->anio==2024)
    {
        M->mes = (rand()%6)+1;
    }

    /// dias

    if(M->mes==4 || M->mes== 6|| M->mes==9 || M->mes==11)
    {
        M->dia= (rand()%30)+1;
    }
    if(M->mes==2)
    {
        if (esBisiesto(M->anio)==0)
        {
            M->dia = (rand()%29)+1;
        }
        M->dia= (rand()%28)+1;
    }
    else
    {
        M->dia = (rand()%31)+1;
    }

    if (M->anio==2024 && M->mes == 6)
    {
        M->dia= (rand()%20)+1;
    }

}

void idCuenta(stMovimientos* M, char nombreArchivoCu[])
{

    M->idCuenta = rand()%cuentaRegistrosGral(nombreArchivoCu,sizeof(stCuentas));
}

void eliminado(stMovimientos* M)
{
    M->eliminado = (rand()%2);
}

void importeydetalle(stMovimientos* M)

{
    char detallePositivos[10][100] = {
    "Depósito en efectivo",
    "Transferencia recibida",
    "Reembolso de tarjeta de crédito",
    "Intereses ganados",
    "Depósito por nómina",
    "Reembolso de seguro",
    "Premio de sorteo bancario",
    "Devolución de impuestos",
    "Transferencia desde otra cuenta",
    "Pago de cliente satisfecho"
};
    char detalleNegativos[10][100] = {
    "Pago de tarjeta de crédito",
    "Transferencia enviada",
    "Retiro en efectivo",
    "Pago de servicios",
    "Pago de alquiler",
    "Compra en supermercado",
    "Pago de seguro",
    "Retiro en cajero automático",
    "Compra en tienda online",
    "Comisión bancaria"
};
    int numAzar;
    numAzar = rand()%10;
//generar importe entre -300mil y 300mil
    if (numAzar%2==0) // si es par genera positivos
    {
        M->importe = (rand() % 300001);
    }
    else // si es impar genera negativos
    {
        M->importe = -1*(rand() % 300001);
    }
//generar detalle
    if(M->importe > 0)
    {
        strcpy(M->detalle, detallePositivos[numAzar]); /// hacer un generador al azar
    }
    if(M->importe==0)
    {
        strcpy(M->detalle, "Movimiento nulo");
    }
    if(M->importe<0)
    {
        strcpy(M->detalle, detalleNegativos[numAzar]); /// hacer un generador al azar
    }
}

void mockArchivo (char nombreArchivoMov[], char nombreArchivoCu[], int cantidad)
{
    int i;
    FILE* archivoMov= fopen(nombreArchivoMov,"ab");
    if(archivoMov)
    {
    for (i=0; i<cantidad; i++)
    {
        stMovimientos movimiento;
        getDayMonthYeard(&movimiento);
        idCuenta(&movimiento,nombreArchivoCu);
        importeydetalle(&movimiento);
        eliminado(&movimiento);
        printf("%d",movimiento.eliminado);
        if(movimiento.eliminado==0)
        {


            buscarCuentaModificarSaldo(nombreArchivoCu,movimiento.idCuenta,movimiento.importe);
        }
        movimiento.id=ftell(archivoMov)/sizeof(stMovimientos);
        fwrite(&movimiento,sizeof(stMovimientos),1,archivoMov);
    }
    fclose(archivoMov);
    }
}





