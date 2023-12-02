#include <iostream>
using namespace std;

int main() {

    string nombre, twitch, youtube, lugarRespawn, itemInicial, nombreMayorCantDiamante;
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
        cout << "Se te han asignado [" << cantOro << "] de oro" << endl;

        do {
            cout << "Cuantas unidades de hierro desea adquirir, son 10 hierro x 1 oro, [solo multiplos de 10]: ";
            cin >> cantHierro;
        } while ( (cantHierro % 10 != 0) && cantHierro < 10 && cantHierro/10 < cantOro);

        cantOro = cantOro - cantHierro/10;

        cantPicosDiamantes = 0;

        for(i = 1; i <= 3; i++) {
            cout << "Indique el item inicial [" << i << "/3]: ";
            cin >> itemInicial;
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

        cout << "Tu zona de respawn es: " << lugarRespawn;

        // Seccion 4: Asignación de los diamantes.
        /*
        Los streamers que esten conectados en estas horas recibiran un 
        premio(sí está conectado entre bonos, se recibiran de igual forma):
          -  400: 05 Diamantes
          - 1200: 15 Diamantes
          - 1600: 20 Diamantes
          -    0: 25 Diamantes
        */

        cout << "\nDesea entrevistar a alguien más ? [s/n]: ";
        cin >> seguirEntrevistando;
        cout << " ";

    } while(seguirEntrevistando == 's');
    return 0;
}