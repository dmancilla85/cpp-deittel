// Fig. 5.6: fig05_06.cpp
// Cálculo del interés compuesto con for.
#include <iostream>
using std::cout;
using std::endl;
using std::fixed;
using std::boolalpha; // hace que los valores bool se impriman como 'true' o 'false'

#include <iomanip>
using std::setw; // permite al programa establecer una anchura de campo
using std::setprecision;

#include <cmath>
using std::pow; 

#include <cstdlib>
using std::system;

int main()
{
	double monto; // monto a depositar al final de cada año
	double principal = 1000.0; // monto inicial antes de aplicar interés
	double tasa = .05; // tasa de interés

	// muestra los encabezados
	cout << "Anio" << setw(21) << "Monto en deposito" << endl;

	// establece el formato de número de punto flotante
	cout << fixed << setprecision(2);

	// calcula el monto en depósito para cada uno de los diez años
	for(int anio = 1; anio <= 10; anio++)
	{
		//calcula el nuevo monto para el año especificado
		monto = principal * pow(1.0 + tasa, anio);

		// muestra el año y el monto
		cout << setw(4) << anio << setw(21) << monto << endl;
	}

	system("pause");
}