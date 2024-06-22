#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED



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
    int eliminado;/// 0 si esta activo 1 si esta eliminado
}stCliente;

stCliente cargaUnCliente();
void muestraUnCliente(stCliente cliente);
int validaPalabra(char palabra[]);
int validarDni(char dni[]);
int validarNum(char dni[]);
int validarEmail(char email[]);
stCliente modificaCliente(stCliente cliente);
void modificaClientePorId(char nombre_Archivo[],int id_Cliente);
void cargaClienteEnArchivo(char nombreArchivo[]);




#endif // CLIENTES_H_INCLUDED
