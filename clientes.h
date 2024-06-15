#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED


typedef struct{
    int id; /// campo único y autoincremental
    int nroCliente;
    char nombre[30];
    char apellido[30];
    char dni[10];
    char email[30];
    ///stDomicilio domicilio;
    char telefono[12];
    int eliminado;
}stCliente;

stCliente cargaUnCliente();
int validaPalabra(char palabra[]);
int validarDni(char dni[]);
int validarNum(char dni[]);

#endif // CLIENTES_H_INCLUDED
