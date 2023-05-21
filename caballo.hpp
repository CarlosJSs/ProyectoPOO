#ifndef CABALLO_HPP
#define CABALLO_HPP

#include "pieza.hpp"

struct Caballo: public Pieza{
	Caballo();
	Caballo(int fila, int columna, char color);

	bool validarMovimiento(int fila, int columna, Pieza* casilla) override;
};

#endif