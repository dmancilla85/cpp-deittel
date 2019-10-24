//Implementacion de la clase Interfaz-- el cliente recibe este archivo s�lo
//como c�digo objeto precompilado, y se mantiene oculta la implementaci�n.

#include "Interfaz.h"
#include "Implementacion.h"

Interfaz::Interfaz(int v)
	:ptr( new Implementacion( v ) ) // inicializa ptr para que apunte a un nuevo objeto
{
	// cuerpo vacio
}

// llama a la funci�n setValor de Implementacion
void Interfaz::setValor(int v)
{
	ptr->setValor( v );
}

// llama a la funci�n getValor de Implementacion
int Interfaz::getValor() const
{
	return ptr->getValor();
}

Interfaz::~Interfaz(void)
{
	delete ptr;
}
