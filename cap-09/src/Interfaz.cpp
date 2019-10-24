//Implementacion de la clase Interfaz-- el cliente recibe este archivo sólo
//como código objeto precompilado, y se mantiene oculta la implementación.

#include "Interfaz.h"
#include "Implementacion.h"

Interfaz::Interfaz(int v)
	:ptr( new Implementacion( v ) ) // inicializa ptr para que apunte a un nuevo objeto
{
	// cuerpo vacio
}

// llama a la función setValor de Implementacion
void Interfaz::setValor(int v)
{
	ptr->setValor( v );
}

// llama a la función getValor de Implementacion
int Interfaz::getValor() const
{
	return ptr->getValor();
}

Interfaz::~Interfaz(void)
{
	delete ptr;
}
