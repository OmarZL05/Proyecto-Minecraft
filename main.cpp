#include <iostream>
using namespace std;

int main() {

    string nombre, twitch, youtube, lugarRespawn, nombreMayorCantDiamante;
    int edad, subs, subsTwitch, subsYoutube, horaInicio, horaFinal, horasEnStream;
    int cantOro, cantHierro, cantDiamante, mayorCantDiamante;
    int totalOro, totalHierro;
    int contMazmorras, contValle, contCabo, contVilla, cantStreamers;
    bool seguirEntrevistando;

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

        cantOro = 25;
        subs = subsTwitch+subsYoutube;
        cantOro = subs*0.5;
    
    } while(seguirEntrevistando);
    return 0;
}