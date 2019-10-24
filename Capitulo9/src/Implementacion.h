#pragma once

//Fig. 10.24: Implementacion.h
//Definición de la clase Implementación

class Implementacion
{
public:
	// constructor
	Implementacion(int v)
		:valor( v ) // inicializa valor con 'v'
	{
		// cuerpo vacío
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
	int valor; // datos que nos gustaría ocultar del cliente
};

