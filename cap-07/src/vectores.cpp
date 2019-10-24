#pragma once


#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

#include <cmath>
using std::rand;

int paseoDelCaballito()
{
	const int TOTAL = 64;
	int numeroMovimiento = 0; // Casilleros visitados
	bool puedeSeguir = true; // El caballo todavia tiene movimientos posibles
	int tablero[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, 
								{0, 0, 0, 0, 0, 0, 0, 0}}; // Inicializo los casilleros del tablero en cero.
	int horizontal[8]; // Describe los 8 movimientos horizontales posibles.
	int vertical[8]; // Describe los 8 movimientos verticales posibles. 
	
	/* Comienza en el casillero superior izquierdo */
	int filaActual = 0; // Fila donde se encuentra el caballo.
	int columnaActual = 0; // Columna donde se encuentra el caballo
	int movida;

	// Movimiento 1
	horizontal[0] = 2;
	vertical[0] = -1;

	// Movimiento 2
	horizontal[1] = 1;
	vertical[1] = -2;

	// Movimiento 3
	horizontal[2] = -1;
	vertical[2] = -2;

	// Movimiento 4
	horizontal[3] = -2;
	vertical[3] = -1;

	// Movimiento 5
	horizontal[4] = -2;
	vertical[4] = 1;

	// Movimiento 6
	horizontal[5] = -1;
	vertical[5] = 2;

	// Movimiento 7
	horizontal[6] = 1;
	vertical[6] = 2;

	// Movimiento 8
	horizontal[7] = 2;
	vertical[7] = 1;


	// Marco la posición inicial
	tablero[filaActual][columnaActual] = 1;

	while(numeroMovimiento++ < TOTAL /*&& puedeSeguir*/)
	{
		// Muestro el tablero en pantalla
		for(int i = 0; i < 8; i++) 
		{
			for(int j = 0; j < 8; j++)
				cout << setw(5) << tablero[i][j];

			cout << endl;
		}

		system("pause");
		cout << endl << endl;
		
		movida = (1 + rand() % 8) - 1;  

		filaActual += vertical[movida];
		columnaActual += horizontal[movida];

		while(filaActual < 0 || columnaActual < 0 
			|| tablero[filaActual][columnaActual] == 1) {
			
				movida = (1 + rand() % 8) - 1; 
				filaActual = vertical[movida];
				columnaActual = horizontal[movida];
		}

		tablero[filaActual][columnaActual] = 1;
	}

	return 0;
}

int main()
{
	/*vector<string> palabras(6);

	palabras[0] = "Hola";
	palabras[1] = "Mi nombre";
	palabras[2] = "es David";
	palabras[3] = "Significante";
	palabras[4] = "Palabrerio";
	palabras[5] = "Habeis armado";

	for(int i = 0; i < palabras.size() ; i++)
		cout << palabras[i] << endl; */


	paseoDelCaballito();

	system("pause");
	return 0;
}