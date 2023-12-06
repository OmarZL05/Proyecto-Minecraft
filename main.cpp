#include <iostream>
#include <string>
using namespace std;

int main() {

    string nombre, twitch, youtube, lugarRespawn, itemInicial, items, streamerMasDiamantes;
    int edad, subs, subsTwitch, subsYoutube, horaInicio, horaFinal, horasEnStream;
    int cantOro, cantHierro, cantDiamante, cantPicosDiamantes, cantItemInicial, mayorCantDiamante;
    int totalOro, totalHierro, i;
    float promHierro, porcCaboBlanco, porcVillaChica, porcMazmorras, porcValleAlegre, difVilla_ChicaCabo_Blanco;
    int cantCaboBlanco, cantVillaChica, cantMazmorras, cantValleAlegre, cantStreamers;
    char seguirEntrevistando;
    bool noSeRepite;

    // Sección de inicializacion de variables.
    cantStreamers = 0;
    cantMazmorras = 0;
    cantValleAlegre = 0;
    cantVillaChica = 0;
    cantCaboBlanco = 0;
    totalOro = 0;
    totalHierro = 0;
    mayorCantDiamante = 1;
    streamerMasDiamantes = "Ningun jugador";

    do{
        // Sección 1: Encuesta al jugador.
        cout << "Indique su nombre: ";
        getline(cin >> ws, nombre);
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
        do {
            cout << "A que hora vas a iniciar el stream (use formato militar [0-2359]): ";
            cin >> horaInicio;
        } while (horaInicio < 0 || horaInicio > 2359);

        cout << "Cuanto tiempo vas a estar en stream (use formato militar [0-2359]): ";
        cin >> horasEnStream;

        horaFinal = horaInicio + horasEnStream;
        
        subs = subsTwitch+subsYoutube;

        // Sección 2: Asignación de recursos iniciales.
        cantOro = 25+subs*5/100;
        cout << "\nSe te han asignado [" << cantOro << "] de oro" << endl;

        noSeRepite = false;
        do {
            cout << "Cuantas unidades de hierro desea adquirir, son 10 hierro x 1 oro, [solo multiplos de 10]: ";
            cin >> cantHierro;
            if(cantHierro % 10 == 0 && cantHierro >= 10 && cantHierro/10 < cantOro) {
                noSeRepite = true;
            }
        } while (noSeRepite == false);

        cantOro = cantOro - cantHierro/10;

        cantPicosDiamantes = 0;

            
        items = "";
        noSeRepite = false;
        for(i = 1; i <= 3; i++) {
            cout << "Indique el item inicial [" << i << "/3]: ";

            // Cuando escribas el pseudocodigo, solo coloca un "Leer"
            getline(cin >> ws, itemInicial);
                
            do{
                cout << "Indique la cantidad para " << itemInicial << ": ";
                cin >> cantItemInicial;
            } while(cantItemInicial < 1 || cantItemInicial > 64);
            

            items = items + itemInicial + " x" + to_string(cantItemInicial) + " ; ";
            if(itemInicial == "pico de diamante" && noSeRepite == false) {
                cantPicosDiamantes = cantPicosDiamantes + 1;
                noSeRepite = true;
            }
        }

        // Sección 3: Asignación de la zona de respawn.
        if(horaInicio <= 600) {
            lugarRespawn = "Mazmorras de la Torre Oscura";
            cantMazmorras = cantMazmorras + 1;
        }
        if( horaInicio >= 601 && horaInicio <= 1200) {
            lugarRespawn = "Bosque de Valle Alegre";
            cantValleAlegre = cantValleAlegre + 1;
        }

        if( horaInicio >= 1201 && horaInicio <= 1800) {
            lugarRespawn = "Playa de Cabo Blanco";
            cantCaboBlanco = cantCaboBlanco + 1;
        }

        if( horaInicio >= 1801 && horaInicio <= 2359) {
            lugarRespawn = "Poblado de Villa Chica";
            cantVillaChica = cantVillaChica + 1;
        }

        cout << "\nTu zona de respawn es: " << lugarRespawn << endl;

        // Seccion 4: Asignación de los diamantes.

        cantDiamante = 0;

        if(horaInicio <= 400 && horaFinal >= 400) {
            cantDiamante = cantDiamante + 5;
        }

        if(horaInicio <= 1200 && horaFinal >= 1200) {
            cantDiamante = cantDiamante + 15;
        }

        if(horaInicio <= 1600 && horaFinal >= 1600) {
            cantDiamante = cantDiamante + 20;
        }

        if(horaInicio <= 2359 && horaFinal > 2359) {
            cantDiamante = cantDiamante + 25;
        }
        
        cout << "\nSe te han asignado " << cantDiamante << " Diamantes" << endl;
        
        // Sección 5: Final de entrevista a jugador, mostrar datos en pantalla.

        cout << "\nEstos son tus datos " << nombre << ": " << endl;
        cout << "Cantidad de oro: " << cantOro << endl;
        cout << "Cantidad de hierro: " << cantHierro << endl;
        cout << "Cantidad de diamantes: " << cantDiamante << endl;
        cout << "Hora del stream: de " << horaInicio << " a " << horaFinal << endl;
        cout << "Zona de respawn: " << lugarRespawn << endl;
        cout << "Items: " << items << endl;

        cout << "\nDesea entrevistar a alguien más ? [s/n]: ";
        cin >> seguirEntrevistando;
        cout << " " << endl;

        // Sin sección
        cantStreamers = cantStreamers + 1;
        totalOro = totalOro + cantOro;
        totalHierro = totalHierro + cantHierro;
        if(mayorCantDiamante < cantDiamante) {
            mayorCantDiamante = cantDiamante;
            streamerMasDiamantes = nombre;
        }

    } while(seguirEntrevistando == 's' | seguirEntrevistando == 'S');
    
    promHierro = totalHierro / cantStreamers;
    porcMazmorras = cantMazmorras*100/cantStreamers;
    porcValleAlegre = cantValleAlegre*100/cantStreamers;
    porcVillaChica = cantVillaChica*100/cantStreamers;
    porcCaboBlanco = cantCaboBlanco*100/cantStreamers;

    difVilla_ChicaCabo_Blanco = porcCaboBlanco - porcVillaChica;
    
    if(difVilla_ChicaCabo_Blanco < 0) {
        difVilla_ChicaCabo_Blanco = difVilla_ChicaCabo_Blanco * -1;
    }
    // Sección 6: Final del proyecto, mostrar datos generales en pantalla. 
    
    cout << "\nCantidad de streamers registrados: " << cantStreamers << endl;
    cout << "Streamer con más diamantes: " << streamerMasDiamantes << endl;
    cout << "Total en oro: " << totalOro << endl;
    cout << "Promedio de hierro total: " << promHierro << endl;
    cout << "Cantidad de jugadores que elegieron [pico de diamante] como item inicial: " << cantPicosDiamantes << endl;
    cout << "Cantidad de jugadores en el Valle Alegre: " << cantValleAlegre << endl;
    cout << "Porcentaje de jugadores en las Mazmorras de la Torre Oscura: " << porcMazmorras << endl;
    
    if(porcCaboBlanco > porcVillaChica) {
        cout << "En Playa de Cabo Blanco hay un "<< difVilla_ChicaCabo_Blanco <<"% de jugadores, más que en Villa Chica" << endl;
    }

    if (porcCaboBlanco == porcVillaChica) {
        cout << "En Playa de Cabo Blanco hay "<<porcVillaChica<<"% de jugadores, igual que en Villa Chica" << endl;
    } 

    if(porcCaboBlanco < porcVillaChica) {
        cout << "En Playa de Cabo Blanco hay un "<< difVilla_ChicaCabo_Blanco <<"% de jugadores, menos que en Villa Chica" << endl;
    }

    return 0;
}