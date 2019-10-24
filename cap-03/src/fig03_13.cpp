// Fig. 3.13: fig03_13.cpp
// Demostración de la clase LibroCalificaciones después de separar
// su interfaz de implementación.
#include <iostream>
using std::cout;
using std::endl;

#include <cstdlib>

#include "LibroCalificaciones.h" // incluye la definición de la clase LibroCalificaciones

// la función main comienza la ejecución del programa
int main()
{
	// crea dos objetos
	LibroCalificaciones libroCalificaciones1("CS101 Introducción a la programación en C++");
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

