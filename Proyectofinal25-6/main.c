#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include "general.h"

void menuPrincipal();
void menuClientes();
void menuCuentas();
void menuMovimientos();

int main()
{

    int clave[4];
    int i=0;

printf("\n");
printf("\n");

printf("\t    ### ###     ##     ## ##   ##  ##            ### ##     ####    ## ##     ####      \n");
printf("\t     ##  ##    ###    ##   ##  ##  ##             ##  ##     ##    ##   ##     ##        \n");
printf("\t     ##       ## ##   ####     ##  ##             ##  ##     ##    ##          ##       \n");
printf("\t     ## ##    ##  ##   #####    ## ##             ## ##      ##    ##          ##       \n");
printf("\t     ##       ## ###      ###    ##               ##  ##     ##    ##          ##        \n");
printf("\t     ##  ##   ##  ##  ##   ##    ##               ##  ##     ##    ##   ##     ##       \n");
printf("\t    ### ###  ###  ##   ## ##     ##              ### ##     ####    ## ##     ####      \n");


/*

    printf("\n\n\t ******************************************************************************************** \n");
    printf("\n\t\t\t\t\t\t Banco Easy Bici \n");
    printf("\n\t\t ************************************************************************************ \n");
*/
    srand(time(NULL));
    printf("\n");
    printf("\n");
    printf("Ingrese clave de acceso\n");
    printf("clave :");
    while (clave[0] != '1' || clave[1] != '2' || clave[2] != '3' || clave[3] != '4') {
        for (i = 0; i < 4; i++) {

            fflush(stdin);
            clave[i] = getche();
            system("cls");

            // Imprimir asteriscos según el índice
            if (i == 0)
                printf("clave: *");
            else if (i == 1)
                printf("clave: **");
            else if (i == 2)
                printf("clave: ***");
            else if (i == 3)
                printf("clave: ****");
        }
    }

    printf("\nAcceso concedido.\n");
    system("cls");


    menuPrincipal();
    return 0;
}

void menuPrincipal()
{
  printf("\n\n\t ******************************************************************************************** \n");
    printf("\n\t\t\t\t\t\t Banco Easy Bici \n");
    printf("\n\t\t ************************************************************************************ \n");



    int opcion;
    do
    {

        printf("\n Menu Principal:\n");
        printf(" 1. Clientes\n");
        printf(" 2. Cuentas\n");
        printf(" 3. Movimientos\n");
        printf(" 0. Salir\n");
        printf(" Seleccione una opcion: ");
        scanf("%d", &opcion);
        system("pause");
        system("cls");

        switch (opcion)
        {
        case 1:
            menuClientes();
            break;
        case 2:
            menuCuentas();
            break;
        case 3:
            menuMovimientos();
            break;
        case 0:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opción no válida\n");
        }
    }
    while (opcion != 0);
}

void menuClientes()
{
  printf("\n\n\t ******************************************************************************************** \n");
    printf("\n\t\t\t\t\t\t Banco Easy Bici \n");
    printf("\n\t\t ************************************************************************************ \n");


    int opcion;
    char archivoClientes[] = "clientes.dat";
    char archivoCuentas[] = "cuentas.dat";
    char archivoMovimientos[] = "movimientos.dat";
    stCliente cliente;
    char dni[10];
    int idCliente;

    do
    {
        printf("\n Menu Clientes:\n");
        printf(" 1. Alta Cliente\n");
        printf(" 2. Baja Cliente\n");
        printf(" 3. Modificar Cliente\n");
        printf(" 4. Consultar Cliente\n");
        printf(" 5. Listar Clientes\n");
        printf(" 0. Volver al Menu Principal\n");
        printf(" Seleccione una opcion: ");
        scanf("%d", &opcion);
        system("pause");
        system("cls");

        switch (opcion)
        {
        case 1:
            cargaClienteEnArchivo(archivoClientes);
            break;
        case 2:
            idCliente = ingresarDniClienteValido(archivoClientes); /// resultados: >=0 ID, -1 Escapo, <-1 duplicado el DNI
            if (idCliente < -1)
            {
                printf("\nDNI duplicado, ingrese nuevamente el DNI: ");
                fflush(stdin);
                scanf("%s", dni);
                idCliente = mostrarClientesDNIDevolverId(archivoClientes, dni);
            }
            if (idCliente >= 0)
            {
                cambiarEstadoCliente(archivoClientes, idCliente, 1);
                printf("\n Cliente dado de baja:");
                muestraUnClienteId(archivoClientes,idCliente);
                printf("\n");
                system("pause");
            }
            break;
        case 3:
            idCliente = ingresarDniClienteValido(archivoClientes);
            if (idCliente < -1)
            {
                printf("\nDNI duplicado, ingrese nuevamente el DNI: ");
                fflush(stdin);
                scanf("%s", dni);
                idCliente = mostrarClientesDNIDevolverId(archivoClientes, dni);
            }
            if (idCliente >= 0)
            {
                modificaClientePorId(archivoClientes, idCliente);
            }
            break;
        case 4:
            idCliente = ingresarDniClienteValido(archivoClientes);
            if (idCliente < -1)
            {
                printf("\nDNI duplicado, ingrese nuevamente el DNI: ");
                fflush(stdin);
                scanf("%s", dni);
                idCliente = mostrarClientesDNIDevolverId(archivoClientes, dni);
                idCliente = -1; /// ya los mostro
            }
            if (idCliente >= 0)
            {
                muestraUnClienteId(archivoClientes, idCliente);
            }
            break;
        case 5:
            mostrarClientes(archivoClientes, 5); /// muestra 30 clientes
            break;

        case 10:
            clientesRandom(archivoClientes, 70);
            break;

        case 0:
            printf("Volviendo al Menu Principal...\n");
            break;
        default:
            printf("Opción no válida\n");
        }
    }
    while (opcion != 0);
}

void menuCuentas()
{
  printf("\n\n\t ******************************************************************************************** \n");
    printf("\n\t\t\t\t\t\t Banco Easy Bici \n");
    printf("\n\t\t ************************************************************************************ \n");


    int opcion;
    char archivoClientes[] = "clientes.dat";
    char archivoCuentas[] = "cuentas.dat";
    char archivoMovimientos[] = "movimientos.dat";
    stCuentas cuenta;
    int idCuenta;
    int idCliente;
    float nuevoCosto;
    char dni[10];

    do
    {
        printf("\n Menu Cuentas:\n");
        printf(" 1. Alta Cuenta\n");
        printf(" 2. Listar Cuentas por Cliente\n");
        printf(" 3. Baja Cuenta\n");
        printf(" 4. Activar Cuenta\n");
        printf(" 5. Consultar Cuenta\n");
        printf(" 6. Listar Todas Las Cuentas del Banco\n");
        printf(" 0. Volver al Menu Principal\n");
        printf(" Seleccione una opcion: ");
        scanf("%d", &opcion);
        system("pause");
        system("cls");

        switch (opcion)
        {
        case 1:
            printf(" 1. Alta Cuenta\n");
            cuenta = cargaUnaCuenta(archivoClientes);
            cargaCuentaArch(archivoCuentas, archivoClientes, cuenta);
            break;
        case 2:
            printf(" 2. Listar Cuentas por Cliente\n");
            idCliente = ingresarDniClienteValido(archivoClientes);
            if (idCliente < -1)
            {
                printf("\nDNI duplicado, ingrese nuevamente el DNI: ");
                fflush(stdin);
                scanf("%s", dni);
                idCliente = mostrarClientesDNIDevolverId(archivoClientes, dni);
            }
            if (idCliente >= 0)
            {
                mostrarCuentasxIdCliente(archivoCuentas, idCliente, archivoClientes);
            }
            break;
        case 3:
            printf(" 3. Baja Cuenta\n");
            idCuenta = ingresarNroCuentaValido(archivoCuentas,archivoClientes);
            if (idCuenta != -1)
            {
                cambiarEstadoCuenta(archivoCuentas, idCuenta, 1);
            }
            break;
        case 4:
            printf(" 4. Activar Cuenta\n");
            idCuenta = ingresarNroCuentaValido(archivoCuentas,archivoClientes);
            if (idCuenta != -1)
            {
                cambiarEstadoCuenta(archivoCuentas,idCuenta,0);
            }
            break;
        case 5:
            printf(" 5. Consultar Cuenta\n");
            idCuenta = ingresarNroCuentaValido(archivoCuentas,archivoClientes);
            if (idCuenta != -1)
            {
                muestraPorIdCuenta(archivoCuentas,archivoClientes, idCuenta);
            }
            break;
        case 6:
            printf(" 6. Listar Todas Las Cuentas del Banco\n");
            mostrarArchivoCuentas(archivoCuentas,archivoClientes,30);
            break;
        case 10:
            getCuenta(archivoClientes,archivoCuentas,80);
            break;
        case 0:
            printf("Volviendo al Menu Principal...\n");
            break;
        default:
            printf("Opción no válida\n");
        }
    }
    while (opcion != 0);
}

void menuMovimientos()
{
  printf("\n\n\t ******************************************************************************************** \n");
    printf("\n\t\t\t\t\t\t Banco Easy Bici \n");
    printf("\n\t\t ************************************************************************************ \n");


    char montoCuotas[]="montoCuotas.dat";
    char archivoRegistroCuotas[]="registroCuotas.dat";
    float arregloCosto[3];
    int opcion;
    char archivoCuotas[]="archivoCuotas.dat";
    char archivoClientes[] = "clientes.dat";
    char archivoCuentas[] = "cuentas.dat";
    char archivoMovimientos[] = "movimientos.dat";

    int idCuenta;
    int idMovimiento;
    stMovimientos movimiento;
    time_t t = time(NULL);
    struct tm fechaActual = *localtime(&t);
    int anio0, mes0, dia0;
    int aniof, mesf, diaf;

    do
    {
        printf("\n Menu Movimientos:\n");
        printf(" 1. Alta Movimiento\n");
        printf(" 2. Baja Movimiento\n");
        printf(" 3. Modificar Movimiento\n");

        printf(" 4. Listar Movimientos por Cuenta\n");
        printf(" 5. Listar Movimientos por Fecha y por Cuenta\n");
        printf(" 6. Listar Todos los Movimientos\n");
        printf(" 7. Ejecutar Proceso de Cargar de Costo Mensuales\n");
        printf(" 0. Volver al Menu Principal\n");
        printf(" Seleccione una opcion: ");
        scanf("%d", &opcion);
        system("pause");
        system("cls");

        switch (opcion)
        {
        case 1:
            printf(" 1. Alta Movimiento\n");
            movimiento = cargaManualMovimiento(archivoCuentas, archivoClientes);
            if (movimiento.id == -1)
            {
                cargarUnMovimientoArchivo(archivoMovimientos, archivoCuentas, movimiento);
            }
            break;
        case 2:
            printf(" 2. Baja Movimiento\n");
            idCuenta = ingresarNroCuentaValido(archivoCuentas,archivoClientes);

            if (idCuenta != -1)
            {
                muestraMovimientoPorIdCuenta(archivoMovimientos, idCuenta, 30);
                idMovimiento=ingresarIdMovValido(archivoMovimientos);
                modificarEstadoIdMovimiento(archivoMovimientos, idMovimiento, 1, archivoCuentas);
            }
            break;
        case 3:
            printf(" 3. Modificar Movimiento\n");

            idCuenta = ingresarNroCuentaValido(archivoCuentas,archivoClientes); /// -1 escapo, 0< idCuenta
            if (idCuenta != -1)
            {
                muestraMovimientoPorIdCuenta(archivoMovimientos, idCuenta, 30);
                idMovimiento=ingresarIdMovValido(archivoMovimientos);
                modificarRegistroDeUnMovimiento(archivoMovimientos, idMovimiento, archivoCuentas);
            }
            break;
        case 4:
            printf(" 4. Listar Movimientos por Cuenta\n");

            idCuenta = ingresarNroCuentaValido(archivoCuentas,archivoClientes);
            if (idCuenta != -1)
            {
                muestraMovimientoPorIdCuenta(archivoMovimientos, idCuenta, 30);
            }
            break;
        case 5:
            printf(" 5. Listar Movimientos por Fecha y por Cuenta\n");
            idCuenta = ingresarNroCuentaValido(archivoCuentas,archivoClientes);
            if (idCuenta != -1)
            {
                printf("\nIngresar fecha inicial.");
                ingresarfecha(&anio0, &mes0, &dia0);
                printf("\nIngresar fecha final.");
                ingresarfecha(&aniof, &mesf, &diaf);
                muestraMovimientoPorIdCuentaPorFecha(archivoMovimientos, idCuenta, anio0, mes0, dia0, aniof, mesf, diaf, 30);
            }
            break;
        case 6:
            printf(" 6. Listar Todos los Movimientos\n");
            system("pause");
            mostrarArchivoMovimiento(archivoMovimientos,30);
            break;
        case 7:
            printf(" 7. Ejecutar Proceso de Cargar de Costo Mensuales\n");
            actualizarMontoCuota(arregloCosto,archivoCuotas);

            printf("Desea correr el proceso?. Ingrese 1. para confirmar u otro para salir\n");
            scanf("%d",&opcion);

            if(opcion==1)
            {

                anio0=fechaActual.tm_year + 1900;
                mes0=fechaActual.tm_mon-1;
                printf(" Se va a cargar la cuota correspondiente al %d-%d\n",mes0,anio0);
                printf(" 1. Para confirmar otro para salir\n");
                scanf("%d",&opcion);
                if(opcion==1)
                {
                    verificaEjecutaActualizacionCobroCuota(archivoCuentas,archivoMovimientos,archivoRegistroCuotas,anio0,mes0,arregloCosto);

                }
            }
            break;
        case 10:
            mockArchivo(archivoMovimientos,archivoCuentas,1000);
            break;

        case 0:
            printf("Volviendo al Menu Principal...\n");
            break;
        default:
            printf("Opción no válida\n");
        }
    }
    while (opcion != 0);
}
