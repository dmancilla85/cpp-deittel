#include "Tiempo.h"

#include <iostream>
using std::cout;

#include <iomanip>
using std::setfill;
using std::setw;

int Tiempo::objInstanciado = 0; // Cuenta el total de objetos instanciados

int Tiempo::getInstancias()
{
	return Tiempo::objInstanciado;
}

Tiempo::Tiempo(void)
{
	hora = minuto = segundo = 0;
	Tiempo::objInstanciado++;
}

Tiempo::~Tiempo()
{
	Tiempo::objInstanciado--;
}

// Establece el nuevo valor de tiempo usando la hora universal; asegura que
// los datos sean consistentes al establecer los valores inválidos en cero
void Tiempo::establecerTiempo(int h, int m, int s)
{
	setHora(h).setMinuto(m).setSegundo(s); // Llamadas en cascada :P
}
	

Tiempo& Tiempo::setSegundo(int s)
{
	segundo = (s >= 0 && s < 60) ? s : 0; // Valida el segundo
	return *this; // Permite llamadas en cascada
}

Tiempo& Tiempo::setMinuto(int m)
{
	minuto = (m >= 0 && m < 60) ? m : 0; // Valida el minuto
	return *this; // Permite llamadas en cascada
}

Tiempo& Tiempo::setHora(int h)
{
	hora = (h >= 0 && h < 24) ? h : 0; // Valida la hora
	return *this; // Permite llamadas en cascada
}

// imprime el tiempo en formato universal (HH:MM:SS)
void Tiempo::imprimirUniversal() const
{
	cout << setfill('0') << setw(2) << hora << ":"
		<< setw(2) << minuto << ":" << setw(2) << segundo;
}

void Tiempo::imprimirEstandar() const
{
	cout << setfill('0')  << setw(2) << ( (hora == 0 || hora == 12) ? 12 : hora % 12) << ":"
		<< setw(2) << minuto << ":" << setw(2)
		<< segundo << (hora < 12) ? " AM" : " PM";
}