//Fig. 10.25: Interfaz.h
//Definici�n de la clase proxy Interfaz.
//El cliente ve este c�digo fuente, pero �ste no revela
//la distirbuci�n de los datos de la clase Implementacion.

#pragma once

class Implementacion;  // declaraci�n anticipada de la clase

class Interfaz
{
public:
	Interfaz(int v);
	void setValor(int); // misma interfaz public que tiene la clase Implementacion
	int getValor() const;
	~Interfaz();

private:
	Implementacion *ptr;
};

