#ifndef MOCK_H_INCLUDED
#define MOCK_H_INCLUDED


void getNombreRandom(char name[]);
void getApellidoRandom(char apellido[]);
void getDniRandom(char dni[]);
void clientesRandom(char archivoClientes[], int cantidad);
int getCuenta(char archivoCliente[], char archivoCuenta[], int cantidadDeCuentasGeneradas);
void mockArchivo (char nombreArchivoMov[], char nombreArchivoCu[], int cantidad);
char getTelefonosRand( char Telefonos[]);
void  getMailsRand(char Mail[],char Nombre[], char Apellido[]);
char GetCPost(char Cpost[]);
char GetStreetsRand(char Calle[]);
char GetNrosRand( char Nro[]);
void GetLocRand(char Localidad[]);
 void GetProvRand(char Provincia[]);

#endif // MOCK_H_INCLUDED
