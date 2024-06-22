
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define DIM 100
#define ESC 27
#include <clientes.h>


int ValidarProv(char dato[]){

    int flag=0;
    int i=0;
    char provincias[][23]={"Buenos aires","Catamarca","Chaco","Chubut","Cordoba","Corrientes","Entre Rios","Formosa","Jujuy","La Pampa","La rioja",
    "Mendoza","Misiones","Neuquen","Rio negro","Salta","San Juan","San Luis","Santa Cruz","Santa Fe","Santiago del Estero",
    "Tierra del Fuego","Tucuman"};
    while( flag==0 && i<22){
       if (ValidarProv[i]==dato){
        flag=1;
       }
        i++;

    }
return flag;
}

void GetProvRand(char Provincia[]){

<<<<<<< HEAD
    char provincias [][23]={"Buenos aires","Catamarca","Chaco","Chubut","Cordoba","Corrientes","Entre Rios","Formosa","Jujuy","La Pampa","La rioja",
=======
 char Provincias [][23]={"Buenos aires","Catamarca","Chaco","Chubut","Cordoba","Corrientes","Entre Rios","Formosa","Jujuy","La Pampa","La rioja",
>>>>>>> 9173097de2bc42f3cd7990bc335a53e25d4c44ff
    "Mendoza","Misiones","Neuquen","Rio negro","Salta","San Juan","San Luis","Santa Cruz","Santa Fe","Santiago del Estero",
    "Tierra del Fuego","Tucuman"};
    strcpy(Provincia, Provincias[rand()%(sizeof(Provincias)/23)]);

}

void GetLocRand(char Localidad[]){


<<<<<<< HEAD
     char localidades[][]={"Moron","Palermo","Recoleta","belgrano","Capilla del Monte","Rio Cuarto","Alta Gracia","Villa Maria",
     "Villa Mercedes","La Punta","Cameron","Rio Grande","San Sebastian","San Rafael","Maipu","Luja de Cuyo","Godoy Cruz",}
      strcpy(Localidad, provincias[rand()%(sizeof(localidades)/23)]);
=======
 char Localidades[][20]={"Moron","Palermo","Recoleta","belgrano","Capilla del Monte","Rio Cuarto","Alta Gracia","Villa Maria",
 "Villa Mercedes","La Punta","Cameron","Rio Grande","San Sebastian","San Rafael","Maipu","Luja de Cuyo","Godoy Cruz","Trelew",
 "Gaiman","Comodoro Rivadabia"};
  strcpy(Localidad, Localidades[rand()%(sizeof(Localidades)/20)]);
 }

char GetNrosRand( char Nro[]){

char Nros[][]={"1000","255","456","546","234","1245","987","673","9822","1122","2388","953","4352","23455","2398","1234",
"99234","765","345","8712"};
strcpy(Nro, Nros[rand()%(sizeof(Nros))/20)]);

}

char GetStreetsRand(char Calle[]){

char Calles[][20]={"Avenida Libertador","Calle Corrientes","Avenida 9 de Julio","Avenida Santa Fe","Calle Rivadavia",
"Calle San Martin","Avenida Santa Fe","Calle Belgrano","Calle Cordoba","Calle Independencia","Calle Moreno",
"Calle Uruguay","Calle Moreno","Calle Jujuy","Calle Mitre","Calle Lavalle","Avenida Callao","Avenida Alvear","Avenida de Mayo",
"Calle Defensa"};
strcpy(Calle, Calles[rand()%(sizeof(Calles))/20)]);

}

char GetCPost(char Cpost[]){

char CodigoPost[][20]={"1001","5000","4000","5700","8300","9400","9000","3500","4400","3600","5500","4600","6000","9200",
"3100","3300","8300","4600","5700","9100"};
strcpy(Cpost, CodigoPost[rand()%(sizeof(CodigoPost))/20)]);

>>>>>>> 9173097de2bc42f3cd7990bc335a53e25d4c44ff
}
