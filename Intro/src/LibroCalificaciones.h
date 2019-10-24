// Fig. 3.11: LibroCalificaciones.h
// Definición de la clase LibroCalificaciones. Este archivo presenta la interfaz
// public de LibroCalificaciones sin revelar las implementaciones de sus funciones 
// miembro, que están definidas en LibroCalificaciones.cpp.

#pragma once

#include <string> // la clase LibroCalificaciones usa la clase string estándar de C++
using std::string;

// Definición de la clase
class LibroCalificaciones
{
public:
	LibroCalificaciones( string ); // constructor que inicializa a nombreCurso
	void establecerNombreCurso( string ); //función que estableceel nombre del curso
	string obtenerNombreCurso(); // función que obtiene el nombre del curso
	void mostrarMensaje(); // función que muestra un mensaje de bienvenida
	void determinarPromedioClase(); // promedia las calificaciones escritas por el usuario
	void recibirCalificaciones(); // recibe un número arbitrario de calificaciones del usuario
	void recibirCalificaciones(int); // (Capitulo6) recibe las tres calificaciones del usuario
	void mostrarReporteCalificaciones(); // muestra un reporte con base en las calificaciones
	void mostrarReporteCalificaciones(int); // (Capitulo6)
	int maximo(int, int, int); // Determina el máximo de tres valores

private:
	string nombreCurso; // nombre del curso para este LibroCalificaciones
	int aCuenta; // cuenta de calificaciones A
	int bCuenta; // cuenta de calificaciones B
	int cCuenta; // cuenta de calificaciones C
	int dCuenta; // cuenta de calificaciones D
	int fCuenta; // cuenta de calificaciones F
	int calificacionMaxima; // valor máximo de las tres calificaciones

}; // Fin de la clase

