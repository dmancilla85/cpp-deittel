#pragma once

//Definición de la clase MazoDeCartas que
//representa un mazo de cartas de juego.

#include <iostream>
using std::cout;
using std::left;
using std::right;

#include <iomanip>
using std::setw;

#include <cstdlib>
using std::rand;
using std::srand;

#include <ctime>
using std::time;

class MazoDeCartas
{
public:
	MazoDeCartas(void);
	~MazoDeCartas(void);
	void barajar();
	void repartir();

private:
	int mazo[4][13]; // representa el mazo de cartas
};

