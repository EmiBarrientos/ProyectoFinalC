#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include "movimientos.h"
#include "clientes.h"
#include "mock.h"


int main(){

char dni[20];
printf("dni: %s",dni);



}


/***
********************************************************************************************************************

for(int i=0;i<strlen(dni);i++){
    if(isdigit(dni[i])){
        printf("soy un digito y estoy en la posicion %d\n",i);
    }

}

stCliente newCliente=cargaUnCliente();
muestraUnCliente(newCliente);

  stCliente arrayCliente[20];

  int vClientes=0;
   vClientes=cargaArrayCliente(arrayCliente,vClientes, 20);




 printf("Hello world!\n");
    srand(time(NULL));

    stMovimientos unMovimiento;
    stMovimientos arregloDeMovimientos[1000];
    int validosDeMovimiento=0;
    stCuentas arregloDeCuentas[1000];
    int validosDeCuentas=200; //asumo que hay 200 Cuentas
    int numeroDeMovimientosGenerarMock=300;

    printf("\n Uso de MOCK");
    validosDeMovimiento=mockArreglo(arregloDeMovimientos,numeroDeMovimientosGenerarMock,validosDeCuentas,arregloDeCuentas);
/// Ver validos de cuenta (ver el tema de las fechas del movimiento generado y la cuenta donde se genera, hay que establecer un condicionante de fecha agregando como argumeto la fecha de creacion de las cuentas)
/// Cuenta[] para sumar el saldo
/// Pensar el registro de la fecha en que se pasa de activo a pasivo porque no queda registro.

    mostrarArregloDeMovimientos(arregloDeMovimientos,validosDeMovimiento); ///muestra todos los movimientos de un arreglo de Movimientos

    imprimirMovimientos(arregloDeMovimientos,validosDeMovimiento); /// muestra arreglo de movimientos por filtros

    printf("\trabajar con movivimientos manualmente");
    printf("\n cargar un movimiento");
    unMovimiento=cargaUnMovimientomanual();
    printf("\n mostrar el movimiento");
    muestraUnMovimiento(unMovimiento);
    printf("\n incorporar el movimiento");
    incorporarMovimientoManual(arregloDeMovimientos,&validosDeMovimiento,unMovimiento,arregloDeCuentas,validosDeCuentas);
    printf("\n mostrar el movimiento en el arreglo reciente");
    muestraUnMovimiento(arregloDeMovimientos[validosDeMovimiento-1]);
    printf("\n Modificar estado a 0 en el arreglo reciente");
    modificarEstado2Movimiento(&arregloDeMovimientos[validosDeMovimiento-1],0);
    printf("\n Mostrar el estado a 0 en el arreglo reciente");
    muestraUnMovimiento(arregloDeMovimientos[validosDeMovimiento-1]);

    printf("\n Goodbye world!\n");
    return 0;


  ********************************************************************************************************

  char palabr[20];
    printf("ingrese una palavra");
    fflush(stdin);
    gets(palabr);




    int i=0;
    int flag=0;
    while(!flag && i<strlen(palabr)){
        if(isdigit(palabr[i])){         /// is digit devuelve 1 si hay un numero, va comparando de 1 en 1, si no hay numero devuelve 0
            flag=1;
           }
        i++;

    }
    printf("la palabra tiene un digito? %d ",flag);
    printf("el digito esta en %d ",i);



    return 0;



}
**/
