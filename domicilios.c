
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
       if (ValidarProva[i]==dato){
        flag=1;
       }
        i++;

    }
return flag;
}
void GetProvRand(char Provincia[]){

 char provincias [][23]={"Buenos aires","Catamarca","Chaco","Chubut","Cordoba","Corrientes","Entre Rios","Formosa","Jujuy","La Pampa","La rioja",
    "Mendoza","Misiones","Neuquen","Rio negro","Salta","San Juan","San Luis","Santa Cruz","Santa Fe","Santiago del Estero",
    "Tierra del Fuego","Tucuman"};
    strcpy(provincia, provincias[rand()%(sizeof(provincias)/23)]);

}
void GetLocRand(char Localidad[]){


 char localidades[][]={"Moron","Palermo","Recoleta","belgrano","Capilla del Monte","Rio Cuarto","Alta Gracia","Villa Maria",
 "Villa Mercedes","La Punta","Cameron","Rio Grande","San Sebastian","San Rafael","Maipu","Luja de Cuyo","Godoy Cruz",}

}
