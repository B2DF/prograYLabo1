#include <iostream>
using namespace std;

void ingresoDatos(string mensaje, int &valor){
    cout << mensaje << endl;
    cin >> valor;
    return;
};

void laVueltaMasRapida(int vueltaNumero, int duracion, int &vueltaMasRapida, int &tiempoMasRapida){
    if(duracion > tiempoMasRapida || tiempoMasRapida == 0){
        tiempoMasRapida = duracion;
        vueltaMasRapida = vueltaNumero;
    }
    return;
}
void laVueltaMasLenta( int vueltaNumero, int duracion, int &vueltaMasLenta, int &tiempoMasLenta){
    if(duracion < tiempoMasLenta || tiempoMasLenta == 0){
        tiempoMasLenta = duracion;
        vueltaMasLenta = vueltaNumero;
    }
    return;
}
void reduccionDeTiempo(int tiempomasLenta, int tiempoMasRapida, float &reduccion){
    float parcial = tiempomasLenta / (tiempoMasRapida - 1);
    reduccion = (parcial / (tiempomasLenta + tiempoMasRapida)) * 100;
    return;    
}
void imprimirResultados(string mensaje, int valor){
    cout << mensaje << valor << endl;
    return;
}
void cargarVueltasObteniendoTiempos(int vueltas, int &vueltaMasRapida, int &tiempoMasRapida, int &vueltaMasLenta, int &tiempoMasLenta, float &reduccion){
    int vueltaNumero = 0;
    int duracion = 0;
    for(int i= 0; i < vueltas; i++){
        ingresoDatos("Ingrese la posicion de la vuelta", vueltaNumero);
        ingresoDatos("Ingrese la duracion de la vuelta en formato MMSS", duracion);
        laVueltaMasRapida(vueltaNumero, duracion, vueltaMasRapida, tiempoMasRapida);
        laVueltaMasLenta(vueltaNumero, duracion, vueltaMasLenta, tiempoMasLenta);
    }
}



int main () {
    int vueltas;
    int vueltaMasRapida = 0;
    int tiempoMasRapida = 0;
    int vueltaMasLenta = 0;
    int tiempoMasLenta = 0;
    float reduccion = -1;

    ingresoDatos("Ingrese la cantidad de vueltas a cargar", vueltas);
    cargarVueltasObteniendoTiempos(vueltas, vueltaMasRapida, tiempoMasRapida, vueltaMasLenta, tiempoMasLenta, reduccion);
    reduccionDeTiempo(tiempoMasLenta, tiempoMasRapida, reduccion);
    
    imprimirResultados("La vuelta mas rapida fue la: ", vueltaMasRapida);
    imprimirResultados("El tiempo de duracion fue: ", tiempoMasRapida);
    imprimirResultados("La vuelta mas lenta fue la: ", vueltaMasLenta);
    imprimirResultados("El tiempo de duracion fue: ", tiempoMasLenta);
    cout << "El porcentaje de reduccion fue de: " << reduccion << "%" << endl;
   
 system("pause");
 return 0;
}