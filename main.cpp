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

        subs = subsTwitch+subsYoutube;

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

        cout << "Debug PC:" << cantPicosDiamantes << " Hierro:" << cantHierro << "  Oro: " << cantOro;

        cout << "\nDesea entrevistar a alguien más ? [s/n]: ";
        cin >> seguirEntrevistando;
        cout << " ";

    } while(seguirEntrevistando == 's');
    return 0;
}