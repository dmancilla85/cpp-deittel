#pragma once

//Fig. 10.24: Implementacion.h
//Definici�n de la clase Implementaci�n

class Implementacion
{
public:
	// constructor
	Implementacion(int v)
		:valor( v ) // inicializa valor con 'v'
	{
		// cuerpo vac�o
	}
	
	// establece valor en v
	void setValor( int v )
	{
		valor = v; // debe validar v
	}

	// devuelve valor
	int getValor() const
	{
		return valor;
	}

private:
	int valor; // datos que nos gustar�a ocultar del cliente
};

