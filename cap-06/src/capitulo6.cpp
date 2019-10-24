// Simulación del juego de dados "craps"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::fixed;

#include <iomanip>
using std::setprecision;

#include <cstdlib>
using std::rand;
using std::srand; // Introduce la semilla generadora en rand

#include <ctime>
using std::time;

#include <string>
using std::string;

int tirarDados(); // tira los dados, calcula y muestra la suma
int craps();
void mensaje(bool, string&);

int main()
{
	const double CAJA = 50000.0;
	double saldoBanco = 1000.0;
	double apuesta = 0;
	bool continuar = true;
	bool res = true;
	int resultado;
	string msj;

	cout << fixed;
	cout << setprecision(2);

	cout << "Saldo: " << saldoBanco << " U$S" << endl;
	cout << "Por favor, introduzca su apuesta: ";
	cin >> apuesta;

	while(apuesta <= saldoBanco && continuar)
	{
		cout << "Su saldo actual es: " << saldoBanco << " U$S" << endl;

		resultado = craps();

		if(resultado == 0)
		{
			saldoBanco -= apuesta;
			res = false;
		}
		else
		{
			saldoBanco += apuesta;
			res = true;
		}

		mensaje(res, msj); 

		cout << msj << endl;
		cout << endl << " Su nuevo saldo es: " << saldoBanco << " U$S" << endl;
		
		if( saldoBanco > 0 && saldoBanco < CAJA)
		{
			cout << "Por favor, introduzca su apuesta o [-1] para salir: ";
			cin >> apuesta;
			continuar = (apuesta != -1);
		}

		if( saldoBanco >= CAJA)
		{
			cout << "Salto la banca! Es tiempo de cambiar sus fichas por efectivo. " << endl;
			continuar = false;
		}
	}

	if(apuesta > saldoBanco)
		cout << "Ingresaste una apuesta que no puedes pagar! :(" <<endl;

	cout << "Hasta pronto!" << endl;
	system("pause");
	return 0;
}

int craps()
{
	enum class Estado {CONTINUAR, GANO, PERDIO};
	
	int miPunto; // 'punto' si no se gana o se pierde en el primer tiro
	Estado estadoJuego; // puede contener cualquiera de los tres estados definidos

	// randomiza el generador de números aleatorios usando la hora actual
	srand((unsigned int)time(0));

	int sumaDeDados = tirarDados(); // primer tiro del dado

	// determina el estadodel juego y el punto (si es necesario), con base al primer tiro
	switch(sumaDeDados)
	{
	case 7: // gana con 7 en el primer tiro
	case 11: // gana con 11 en el primer tiro
		estadoJuego = Estado::GANO;
		break;

	case 2: // pierde con 2 en el primer tiro
	case 3: // pierde con 3 en el primer tiro
	case 12: // pierde con 12 en el primer tiro
		estadoJuego = Estado::PERDIO;
		break;

	default: // si no ganó ni perdió, debe continuar
		estadoJuego = Estado::CONTINUAR;
		miPunto = sumaDeDados; // recuerda el punto
		cout << "El punto es: " << miPunto << endl;
		break;
	}

	// mientras el juego no esté completo
	while(estadoJuego == Estado::CONTINUAR)
	{
		sumaDeDados = tirarDados(); // tira los dados de nuevo

		// determina el estado del juego
		if(sumaDeDados == miPunto) // gana al hacer un punto
			estadoJuego = Estado::GANO;
		else
			if(sumaDeDados == 7) // pierde al tirar 7 antes del punto
				estadoJuego = Estado::PERDIO;
	}

	if(estadoJuego == Estado::GANO)
	{
		cout << "El jugador gana!" << endl;
		return 1;
	}
	else
	{
		cout << "El jugador pierde!" << endl;
	}

	return 0;
}

// tira los dados, calcula la suma y muestra los resultados
int tirarDados()
{
	int dado1 = 1 + rand() % 6; // tiro del primer dado
	int dado2 = 1 + rand() % 6; // tiro del segundo dado

	int suma = dado1 + dado2; // calcula la suma de los valores de los datos

	// muestra los resultados de este tiro
	cout << "El jugador tiro " << dado1 << " + " << dado2
		<< " = " << suma << endl;

	return suma;
}

void mensaje(bool estado, string &msj)
{
	int opcion = 1 + rand() % 6;
	
	// randomiza el generador de números aleatorios usando la hora actual
	srand((unsigned int)time(0));

	if(estado) // Va ganando
	{
		switch(opcion)
		{
		case 1: 
			     msj = "Oh, vamos arriesguese!";
				  break;
		case 2: 
			     msj = "Muy bien, lo estas haciendo bien!";
				  break;
		case 3: 
			     msj = "Guau, eso si que es suerte!";
				  break;
		case 4: 
				  msj = "Tu si que eres un maldito suertudo!";
				  break;
		case 5:
				  msj = "Parece que la estas haciendo en grande eh!";
				  break;
		case 6: 
				  msj = "Sigue asi mi compadre!";
				  
		}
	}
	else
	{
	switch(opcion)
		{
		case 1: 
			     msj = "Oh, te estas yendo a la quiebra cierto?";
				  break;
		case 2: 
			     msj = "Mmm parece que no duraras mucho...";
				  break;
		case 3: 
			     msj = "Yo si fuera tu me iria con lo poco que queda!";
				  break;
		case 4: 
				  msj = "Amigo, creo que estas en problemas...";
				  break;
		case 5:
				  msj = "Oh, no otra vez no seas imbecil!";
				  break;
		case 6: 
				  msj = "Ups pinguino te quedaste sin nada!";
				  
		}
	}
}