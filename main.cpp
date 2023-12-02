#include <iostream>
using namespace std;

int main() {

    string nombre, twitch, youtube, lugarRespawn, itemInicial, items, nombreMayorCantDiamante;
    int edad, subs, subsTwitch, subsYoutube, horaInicio, horaFinal, horasEnStream;
    int cantOro, cantHierro, cantDiamante, cantPicosDiamantes, mayorCantDiamante;
    int totalOro, totalHierro;
    int i;
    int contMazmorras, contValle, contCabo, contVilla, cantStreamers;
    char seguirEntrevistando;

    do{
        // Sección 1: Encuesta al jugador.
        cout << "Indique su nombre: ";
        cin >> nombre;
        cout << "Indique su edad: ";
        cin >> edad;
        cout << "Indique su canal de twitch: ";
        cin >> twitch;
        cout << "Indique su cantidad de suscriptores en twitch: ";
        cin >> subsTwitch;
        cout << "Indique su canal de youtube: ";
        cin >> youtube;
        cout << "Indique su cantidad de suscriptores en youtube: ";
        cin >> subsYoutube;
        cout << "A que hora vas a iniciar el stream (use formato militar): ";
        cin >> horaInicio;
        cout << "Cuanto tiempo vas a estar en stream: ";
        cin >> horasEnStream;

        horaFinal = horaInicio + horasEnStream*100;
        
        subs = subsTwitch+subsYoutube;

        // Sección 2: Asignación de recursos iniciales.
        cantOro = 25+subs*5/100;
        cout << "\nSe te han asignado [" << cantOro << "] de oro" << endl;

        do {
            cout << "Cuantas unidades de hierro desea adquirir, son 10 hierro x 1 oro, [solo multiplos de 10]: ";
            cin >> cantHierro;
        } while ( (cantHierro % 10 != 0) && cantHierro < 10 && cantHierro/10 < cantOro);

        cantOro = cantOro - cantHierro/10;

        cantPicosDiamantes = 0;

        items = "";
        for(i = 1; i <= 3; i++) {
            cout << "Indique el item inicial [" << i << "/3]: ";
            cin >> itemInicial;
            items = items + itemInicial + "; ";
            if(itemInicial == "Pico de Diamante") {
                cantPicosDiamantes = cantPicosDiamantes + 1;
            }
        }

        // Sección 3: Asignación de la zona de respawn.
        if(horaInicio <= 600) {
            lugarRespawn = "Mazmorras de la Torre Oscura";
            contMazmorras = contMazmorras + 1;
        }
        if( horaInicio >= 601 && horaInicio <= 1200) {
            lugarRespawn = "Bosque de Valle Alegre";
            contValle = contValle + 1;
        }

        if( horaInicio >= 1201 && horaInicio <= 1800) {
            lugarRespawn = "Playa de Cabo Blanco";
            contCabo = contCabo + 1;
        }

        if( horaInicio >= 1801 && horaInicio <= 2359) {
            lugarRespawn = "Poblado de Villa Chica";
            contVilla = contVilla + 1;
        }

        cout << "\nTu zona de respawn es: " << lugarRespawn << endl;

        // Seccion 4: Asignación de los diamantes.

        cantDiamante = 0;

        if(horaFinal >= 400) {
            cantDiamante = cantDiamante + 5;
        }

        if(horaFinal >= 1200) {
            cantDiamante = cantDiamante + 15;
        }

        if(horaFinal >= 1600) {
            cantDiamante = cantDiamante + 20;
        }

        if(horaFinal > 2359) {
            cantDiamante = cantDiamante + 25;
        }
        
        cout << "\nSe te han asignado " << cantDiamante << " Diamantes" << endl;
        
        // Sección 5: Final de entrevista a jugador, mostrar datos en pantalla.

        cout << "\nGracias por participar " << nombre << ", datos: " << endl;
        cout << "Cantidad de oro: " << cantOro << endl;
        cout << "Cantidad de hierro: " << cantHierro << endl;
        cout << "Cantidad de diamantes: " << cantDiamante << endl;
        cout << "Hora del stream: de " << horaInicio << " a " << horaFinal << endl;
        cout << "Zona de respawn: " << lugarRespawn << endl;
        cout << "Items: " << items << endl;

        cout << "\nDesea entrevistar a alguien más ? [s/n]: ";
        cin >> seguirEntrevistando;
        cout << " ";

    } while(seguirEntrevistando == 's');
    
    // Sección 6: Final del proyecto, mostrar datos generales en pantalla. 

    return 0;
}