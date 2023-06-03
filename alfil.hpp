#ifndef ALFIL_HPP
#define ALFIL_HPP

#include "pieza.hpp"

struct Alfil: public Pieza{
	Alfil();
	Alfil(int fila, int columna, char color);

	bool validarMovimiento(int fila, int columna, Pieza* casillaDestino, int TableroBin[8][8]) override;
};

#endif