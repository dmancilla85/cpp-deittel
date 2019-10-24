#pragma once

// Evita mùltiples inclusiones del archivo de encabezado
#ifndef TIEMPO_H
#define TIEMPO_H

class Tiempo
{
public:
	Tiempo(void);
	~Tiempo();
	void establecerTiempo(int, int, int); // Establece hora minuto y segundo
	Tiempo& setHora(int);
	Tiempo& setMinuto(int);
	Tiempo& setSegundo(int);
	void imprimirUniversal() const; // Imprime hora en formato universal
	void imprimirEstandar() const ; // Imprime hora en formato estándar
	static int getInstancias();

private:
	int hora; // Formato 0-23 hs
	int minuto; // 0 - 59
	int segundo; // 0 - 59
	static int objInstanciado;
};

#endif

