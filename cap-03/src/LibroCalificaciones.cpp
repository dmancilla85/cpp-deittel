// Fig. 3.12: LibroCalificaciones.cpp
// Definiciones de las funciones miembro de LibroCalificaciones. Este archivo contiene
// implementaciones de las funciones miembro cuyo prototipo est� en LibroCalificaciones.h

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::fixed; // asegura que se muestre el punto decimal

#include <iomanip> // manipuladores de flujo parametrizados
using std::setprecision; // establece la precisi�n num�rica de salida

#include "LibroCalificaciones.h" // incluye la definici�n de la clase LibroCalificaciones

// el constructor inicializa nombreCurso con el objeto String suministrado como argumento
LibroCalificaciones::LibroCalificaciones(string nombre)
{
	establecerNombreCurso( nombre );
	aCuenta = 0; // inicializa cuenta A de calificaciones en 0
	bCuenta = 0; // inicializa cuenta B de calificaciones en 0
	cCuenta = 0; // inicializa cuenta C de calificaciones en 0
	dCuenta = 0; // inicializa cuenta D de calificaciones en 0
	fCuenta = 0; // inicializa cuenta F de calificaciones en 0
	calificacionMaxima = 0;
}

// funci�n para establecer el nombre del curso
void LibroCalificaciones::establecerNombreCurso( string nombre )
{
	if(nombre.length() <= 25)
		nombreCurso = nombre;
	else
	{
		nombreCurso = nombre.substr(0, 25); // substr(posInicial, longitud)

		cout << "El nombre\"" << nombre << "\" excede la longitud m�xima (25).\n"
			<< "Se limito nombreCurso a los primeros 25 caracteres.\n" << endl;
	}
}

// funci�n para obtener el nombre del curso
string LibroCalificaciones::obtenerNombreCurso()
{
	return nombreCurso;
}

// muestra un mensaje de bienvenida al usuario
void LibroCalificaciones::mostrarMensaje()
{
	cout << "Bienvenido al libro de calificaciones para\n" << obtenerNombreCurso()
		<< "!" << endl;
}

// funci�n para ingreso y c�lculo del promedio de las calificaciones
void LibroCalificaciones::determinarPromedioClase()
{
	int total;
	int contadorCalif;
	int calificacion;
	double promedio;

	// fase de inicializaci�n
	total = 0;
	contadorCalif = 1;

	// fase de procesamiento
	cout << "Escriba una calificacion o -1 para salir: "; // pide la entrada
	cin >> calificacion; // recibe como entrada la calificaci�n o el valor centinela

	while(calificacion != -1) // itera hasta leer el valor centinela
	{
		total += calificacion;
		contadorCalif++;

		cout << "Escriba una calificacion o -1 para salir: "; // pide la entrada
		cin >> calificacion; // recibe como entrada la calificaci�n o el valor centinela
	}
	
	// fase de terminaci�n 
	if(contadorCalif != 0)
	{
		promedio = static_cast<double> (total) / contadorCalif;

		// muestra el total y promedio de las calificaciones
		cout << "\nEl total y el promedio de las " << contadorCalif << " calificaciones es " << total << endl;
		cout << "El promedio de la clase es " << setprecision(2) << fixed << promedio << endl;
	}
	else
		cout << "No se introdujeron calificaciones." << endl;
}

// ingresar calificaciones
void LibroCalificaciones::recibirCalificaciones()
{
	int calificacion; // calificacion introducida por el usuario

	cout << "Escriba las calificaciones de letra." << endl
		<< "Escriba el caracter EOF para terminar la entrada." << endl;

	// itera hasta que el usuario escriba la secuencia de fin de archivo
	while((calificacion = cin.get()) != EOF)
	{
		// determina cual calificaci�n se introdujo
		switch(calificacion)
		{
		case 'A':
		case 'a':
			aCuenta++;
			break;

		case 'B':
		case 'b':
			bCuenta++;
			break;

		case 'C':
		case 'c':
			cCuenta++;
			break;

		case 'D':
		case 'd':
			dCuenta++;
			break;

		case 'F':
		case 'f':
			fCuenta++;
			break;

		case '\n':
		case '\t':
		case ' ':
			break;

		default: // atrapa todos los dem�s caracteres
			cout << "Se introdujo una letra de calificaci�n incorrecta. "
				<< "Escribe una nueva calificacion. " << endl;
			break;
		}
	}
}

// muestra en pantalla el resultado de las calificaciones
void LibroCalificaciones::mostrarReporteCalificaciones()
{
	// imprime resumen de resultados
	cout << "\n\nNumero de estudiantes que recibieron cada calificacion de letra: "
		<< "\nA: " << aCuenta // muestra el numero de calificaciones A 
		<< "\nB: " << bCuenta // muestra el numero de calificaciones B 
		<< "\nC: " << cCuenta // muestra el numero de calificaciones C 
		<< "\nD: " << dCuenta // muestra el numero de calificaciones D 
		<< "\nF: " << fCuenta // muestra el numero de calificaciones F 
		<< endl;
}

void LibroCalificaciones::recibirCalificaciones(int capitulo6)
{
	int calificacion1; // primera calificaci�n introducida por el usuario
	int calificacion2; // segunda calificaci�n introducida por el usuario
	int calificacion3; // tercera calificaci�n introducida por el usuario

	cout << "Introduzca tres calificaciones enteras: ";
	cin >> calificacion1 >> calificacion2 >> calificacion3;

	// almacena el valor m�ximo en el miembro calificacionMaxima
	calificacionMaxima = maximo(calificacion1, calificacion2, calificacion3);
}

// devuelve el m�ximo de sus tres par�metros enteros
int LibroCalificaciones::maximo(int x, int y, int z)
{
	int valorMaximo = x;

	if(y > valorMaximo)
		valorMaximo = y;

	if(z > valorMaximo)
		valorMaximo = z;

	return valorMaximo;
}

void LibroCalificaciones::mostrarReporteCalificaciones(int capitulo6)
{
	// imprime el m�ximo de calificaciones introducidas
	cout << "Calificacion maxima introducida: " << calificacionMaxima << endl;
}