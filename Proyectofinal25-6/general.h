#ifndef GENERAL_H_INCLUDED
#define GENERAL_H_INCLUDED

/// Clientes
typedef struct{
    char calle[30];
    char nro[6];
    char localidad[30];
    char provincia[40];
    char cpos[6];

}stDomicilio;

typedef struct{
    int id; /// campo único y autoincremental
    int nroCliente;
    char nombre[30];
    char apellido[30];
    char dni[10];
    char email[30];
    stDomicilio domicilio;
    char telefono[12];
    int eliminado;
}stCliente;

/// Cuentas
typedef struct {
    int id; /// campo único y autoincremental
    int idCliente; /// Id del Cliente dueño de la Cuenta;
    int tipoDeCuenta; /// 1. Caja de Ahorro en Pesos, 2. Caja de Ahorro en Dólares, 3. Cta Cte en $
    int nroCuenta;
    float costoMensual; /// Costo de mantenimiento del producto;
    float saldo; /// Debe actualizarse al modidificar o cargar un movimiento.
    int eliminado; /// 0 si está activo - 1 si está eliminado

} stCuentas;

/// Movimientos
typedef struct {

int id; /// campo único y autoincremental
int idCuenta; /// Id de la cuenta
char detalle[100];
float importe;
int anio;
int mes; /// 1 a 12
int dia; /// 1 a … dependiendo del mes
int eliminado; /// 0 si está activo - 1 si está eliminado

}stMovimientos;




/// Prototipos de funciones
stCliente cargaUnCliente(char archivoCliente[]);
int validaPalabra(char palabra[]);                 ///Devuelve 0 si la palabra es valida
int validarDni(char dni[]);                     ///devuelve 1 si el dni es valido en
int validarNum(char num[]);
int validarEmail(char email[]);
void cargaClienteEnArchivo(char nombreArchivo[]);
void muestraUnClienteId(char nombreArchivo[],int idCliente);
void mostrarEncabezadoCliente(); /// ver si arreglamos para que muestre en listado
void muestraUnCliente(stCliente cliente);
void cambiarEstadoCliente(char nombre_Archivo[], int id_Cliente, int estado);
void modificaClientePorId(char nombre_Archivo[],int idCliente);
stCliente modificaCliente(stCliente cliente,char archivoCliente[]);
stCliente modificaDomicilio(stCliente cliente);
void mostrarClientes(char nombreArchivo[],int cantDeClientes);
int traducirDniaIdCliente(char archivoCliente[],char dni[]);///no muestra si retorna -1 no esta, si retorna menores esta repetido, positivos es el id
int ingresarDniClienteValido(char nombreArchivo[]); /// resultados: >=0 ID, -1 Escapo, <-1 duplicado el DNI
int muestraUnClienteXDni (char nombreArchivo[], char dni, stCliente cliente); /// muestra todos pero retorna el ultimo id. la cambiaria a void y usaria la de abajo para int
int mostrarClientesDNIDevolverId(char archivoCliente[], char dni[]); /// para mostrar y seleecionar clientes con DNI duplicados id, -1 escapo -2 no encontro
void traducirIdClientePorDNI(char achivoCliente[], int idCliente, char dniretorna[]); /// retorna arreglo vacio si no esta o el dni




/// funcion de Cuenta
stCuentas cargaUnaCuenta(char nombreArchivo[]); ///Carga 1 sola cuenta, retorna stCuentas cuenta.
void cargaCuentaArch(char nombreArchivo[], char nombreArchivoCliente[], stCuentas cuenta);///Pasa al archivo el stCuenta cuenta de CargaUnaCuenta.
int componerNroCuenta(int cantidadDeCuenta,char dni [],int tipoDeCuenta, int sucursal);/// Componemos el nro de cuenta.
int contarCuentasPorIdClientePorTipo(char nombreArchivo[],int idCliente, int tipoDeCuenta); //Retorna la cantidad de cuentas de por tipo que tiene el cliente.
void encabezadoCuenta();
void muestraUnaCuentaListadoConId(stCuentas Cuenta, char archivoCliente[]);//Te muestra una cuenta en base al id.
void muestraUnaCuenta(stCuentas Cuenta,char archivoCliente[]); ///Muestra cuenta antes de guardar en archivo.
int verificarNroDeCuenta(int numeroCuenta, char nombreCuenta[]); ///Chequea la existencia del nro cuenta, para el entrelazado con los movimientos.
int ingresarNroCuentaValido(char nombreArchivo[], char nombreArchivoCliente[]); ///En movimintos ingresan el nro de cuenta al que quieren cargarle el movimiento.
int resolverCuentasDuplicadas(char nombreArchivo[], char nombreArchivoCliente[],int nroCuenta); ///Para seleccionar el id correcto al cargarle el movimiento en caso de que haya un nro de cta repetido.
void cambiarEstadoCuenta(char nombreArchivo[], int idCuenta, int estado);///Cambia el estado de la cta.
void modificarCostoCuentaPorId(char nombreArchivo[], int idCuenta, float nuevoCosto);///En base al idCuenta cambiamos el costo.
void modificarCostoCuenta(stCuentas* cuenta, float nuevoCosto);///Modifica el costo mensual.
void muestraPorIdCuenta(char nombreArchivo[],char nombreArchivoCliente[], int idCuenta);///Muestra una cta por idCuenta en texto(usarla para mostrar uno solo).
void mostrarCuentasxIdCliente(char archivoCuenta[], int idCliente, char archivoCliente[]);///Muestra una cuenta en base al id.
int mostrarCuentasxIdClienteSeleccionar(char archivoCuenta[], char archivoCliente, int idCliente); ///Poder ver todos los idCuenta en base a un idCliente.
void buscarCuentaModificarSaldo(char nombreArchivoCu[], int idCuenta, float importe);///Te posicionas en el idCuenta al q le queres modificar el saldo y lo modificas.
void mostrarArchivoCuentas(char archivoCuenta[], char archivoCliente[], int cantidad);///Mientras haya cuentas guardadas en el archivo, las muestra en listado.



/// Funciones de Movimiento

stMovimientos cargaManualMovimiento(char ArchivoCuentas[], char ArchivoCliente[]);
// Utiliza el Archivo Cuentas para chequear y conseguir el IdCuenta correcto
// Utiliza el Archivo Clientes para ayudar a ubicar en Nro de cuenta y posteriormente el IdCuenta correspondiente
// Devuelve un Movimiento con dos posibles idClientes
// idCliente = -1 es que termino la carga completa
// idCliente = -2 es que por alguna razon decidio cancelar la carga y no debe cargarse en el archivo movimientos
void cargarUnMovimientoArchivo(char ArchivoMovimientos[], char ArchivoCuentas[], stMovimientos movimiento);
int ingresarIdMovValido(char archivoMovimiento[]); /// devuelve idMovmiento
// pide ingresar un idMovimiento y verifica que sea un numero de movimiento valido entre 0 y el numero de registros regresando un id valido
void modificarEstadoIdMovimiento(char archivoMovimiento[], int idMovimiento, int estado,char nombreArchivoCu[]);
// recibe archivo de movimiento y el de cuenta porque ademas de modificar el estado de movimiento
// en caso de cambiar el estado tiene que modificar el saldo de la cuenta ya sea
// restando el importe si activa un movimiento o sumando si desactiva el movimiento
void modificarRegistroDeUnMovimiento(char ArchivoMovimientos[], int numeroDeRegistro, char nombreArchivoCu[]);
// llama a la funcion mostrarxModificarMovimiento(arreglo de dos movimientos: original y modificado) y modifica los resultados
//    - solo va a permitir modificar: el resto de entendemos que no deben modificarse
//         * Detalle de la operacion
//         * El estado del movimiento
//         * La fecha
void mostrarxModificarMovimiento(stMovimientos arregloMovimiento[]); /// arregloMovimiento[0] original, arregloMovimiento[1] resultado
// sobre dos movimientos de un arreglo copia el primero al segundo y despues va preguntando opciones para mantener lo copiado o modificarlo
// como es un puntero el arreglo los cambios quedan en el segundo elemento del arreglo y el original queda igual para poder comparar cambios despues
void mostrarEncabezadoMovimiento();
void mostrarUnMovimiento(stMovimientos movimiento);
void muestraMovimientoPorIdCuenta(char archivoMovimientos[], int idCuenta, int cantidad);
// busca que coincida el idCuenta en el archivo de movimientos y muestra solo esos movimientos por cantidades fijas
void muestraMovimientoPorIdCuentaPorFecha(char archivoMovimientos[],int idCuenta,int anio0,int mes0,int dia0,int aniof,int mesf,int diaf,int cantidadmostrar);
// Muestra todos los movimientos entre dos fechas de una cuenta pausando cada la cantidad a mostrar en el numero cantidad a mostrar
void mostrarArchivoMovimiento(char ArchivoMovimientos[],int i);
// recorre todo el archivo copiando cada movimiento a un auxiliar y mostrando listas de un tamaño i



void actualizarMontoCuota(float arregloCuota[],char archivoCuotas[]);
// recibe un arreglo donde se va a cargar los valores de las cuotas y un archivo donde esta el historial de los valores de las cuotas
// Lee los valores viejos y pregunta para carga nuevos valores o los viejos en el arreglo:
// - arreglo[0] valor de la cuota TIPO 1
// - arreglo[1] valor de la cuota TIPO 2
// - arreglo[1] valor de la cuota TIPO 2

void cargarMovimientoCuotaCuentas(char nombreCuenta[], char nombreMovimiento[], int anio, int mes, float arregloCosto[]);
// Recibe el archivo Cuenta, el archivo de Movimiento, el mes y año y el Costo de las cuotas
// carga un movimiento por cada cuenta activa por el valor de la cuota y con los datos correspondientes
// actualiza el monto de la cuota y actualiza el saldo de la cuenta

void verificaEjecutaActualizacionCobroCuota(char nombreCuenta[],char nombreMovimiento[], char RegistroCuotas[], int anio, int mes, float arregloCosto[]);
// Recibe el archivo Registro de cuotas, el archivo Cuenta, el archivo de Movimiento, el mes y año y el Costo de las cuotas
// Verifica que no se haya ejecutado ya el cobro y en caso de que no ejecuta el cobro y actualiza el registro de cuotas y montos



/// generales
void ingresarfecha(int* anio, int* mes, int* dia);
int cuentaRegistrosGral(char nombreArchivo[], int tamanioUnSt);
int cuentaRegistrosGralFILE(FILE* archivo, int tamanioUnSt);
int esBisiesto(int anio);



#endif // GENERAL_H_INCLUDED
