#include <iostream>
using std::cout;
using std::endl;

#include "Tiempo.h"

int main()
{
	Tiempo t;


	cout << "\n\nEl tiempo inicial universal es ";
	t.imprimirUniversal();

	cout << "\n\nEl tiempo inicial est�ndar es ";
	t.imprimirEstandar();

	t.establecerTiempo(13, 27, 6);

	cout << "\n\nEl tiempo universal despu�s de establecer tiempo es ";
	t.imprimirUniversal();

	cout << "\n\nEl tiempo est�ndar despu�s de establecer tiempo es ";
	t.imprimirEstandar();

	cout << endl << endl;

	system("pause");
}