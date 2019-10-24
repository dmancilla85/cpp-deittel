//Fig. 10.25: Interfaz.h
//Definición de la clase proxy Interfaz.
//El cliente ve este código fuente, pero éste no revela
//la distirbución de los datos de la clase Implementacion.

#pragma once

class Implementacion;  // declaración anticipada de la clase

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

