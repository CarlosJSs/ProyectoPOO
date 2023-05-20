#ifndef TORRE_HPP
#define TORRE_HPP

#include "pieza.hpp"

struct Torre: public Pieza{
	Torre();
	Torre(int fila, int columna, char color);

	bool validarMovimiento(int fila, int columna, Pieza* casilla) override;
};

#endif