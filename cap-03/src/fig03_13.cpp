// Fig. 3.13: fig03_13.cpp
// Demostraci�n de la clase LibroCalificaciones despu�s de separar
// su interfaz de implementaci�n.
#include <iostream>
using std::cout;
using std::endl;

#include <cstdlib>

#include "LibroCalificaciones.h" // incluye la definici�n de la clase LibroCalificaciones

// la funci�n main comienza la ejecuci�n del programa
int main()
{
	// crea dos objetos
	LibroCalificaciones libroCalificaciones1("CS101 Introducci�n a la programaci�n en C++");
	LibroCalificaciones libroCalificaciones2("CS101 Estructuras de datos en C++");

	// muestra el valor inicial de nombreCurso
	cout << "libroCalificaciones1 creado para el curso: " << 
		libroCalificaciones1.obtenerNombreCurso() << "\nlibroCalificaciones2 creado para el curso: " << 
		libroCalificaciones2.obtenerNombreCurso() << endl;

	libroCalificaciones1.mostrarMensaje();
	//libroCalificaciones1.determinarPromedioClase();

	// Cap. 5.
	libroCalificaciones1.recibirCalificaciones();
	libroCalificaciones1.mostrarReporteCalificaciones();

	system("pause");
	return 0;
}

