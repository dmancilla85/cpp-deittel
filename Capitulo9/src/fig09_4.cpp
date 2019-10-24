#include <iostream>
using std::cout;
using std::endl;

#include "Tiempo.h"

int main()
{
	Tiempo t;


	cout << "\n\nEl tiempo inicial universal es ";
	t.imprimirUniversal();

	cout << "\n\nEl tiempo inicial estándar es ";
	t.imprimirEstandar();

	t.establecerTiempo(13, 27, 6);

	cout << "\n\nEl tiempo universal después de establecer tiempo es ";
	t.imprimirUniversal();

	cout << "\n\nEl tiempo estándar después de establecer tiempo es ";
	t.imprimirEstandar();

	cout << endl << endl;

	system("pause");
}