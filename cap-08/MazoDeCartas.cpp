#include "MazoDeCartas.h"
//Definiciones de las funciones miembro para la clase MazoDeCartas
//que simula cómo barajar y repartir un mazo de cartas de juego

MazoDeCartas::MazoDeCartas(void)
{
	// itera a través de las filas del mazo
	for( int fila = 0; fila <= 3; fila++)
	{
		// itera a través de las columnas del mazo para la fila actual
		for( int columna = 0; columna <= 12; columna++ )
		{
			mazo [ fila ] [ columna ] = 0;
		}
	}

	srand( (unsigned int)time( 0 ) ); // siembra el generador de números aleatorios
}


MazoDeCartas::~MazoDeCartas(void)
{
}


// baraja las cartas en el mazo
void MazoDeCartas::barajar()
{
	int fila;
	int columna;

	// para c/u de las 52 cartas, selecciona una posición del mazo al azar
	for( int carta = 1; carta <= 52; carta++ )
	{
		do // selecciona una nueva posición aleatoria hasta encontrar una desocupada
		{
			fila = rand() % 4; // selecciona al azar la fila (0 a 3)
			columna = rand() % 13; // selecciona al azar la columna (0 a 12)
		} while ( mazo[fila][columna] != 0 );

		mazo[ fila ][ columna ] = carta;
	}
}

// reparte las cartas en el mazo
void MazoDeCartas::repartir()
{
	// inicializa el arreglo palo
	static const char *palo[ 4 ] = 
	{ "Corazones", "Diamantes", "Bastos", "Espadas" };

	// inicializa el arreglo cara
	static const char *cara[ 13 ] =
	{ "As", "Dos", "Tres", "Cuatro", "Cinco", "Seis", "Siete", "Ocho",
	  "Nueve", "Diez", "Sota", "Reina", "Rey" };

	// para cada una de las 52 cartas
	for( int carta = 1; carta <= 52; carta++ )
	{
		// itera a través de las filas del mazo
		for(int fila = 0; fila <= 3; fila++)
		{
			// itera a través de las columnas del mazo para la fila central
			for( int columna = 0; columna <= 12; columna++)
			{
				// si la posición contiene la carta actual, la muestra
				if ( mazo[fila][columna] == carta )
				{
					cout	<< setw( 5 ) << right << cara[ columna ]
							<< " de " << setw( 8 ) << left << palo [ fila ]
							<< ( carta % 2 == 0 ? '\n' : '\t' );
				}
			}
		}
	}
}