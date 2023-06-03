#ifndef REINA_HPP
#define REINA_HPP

#include "pieza.hpp"

struct Reina: public Pieza{
	Reina();
	Reina(int fila, int columna, char color);

	bool validarMovimiento(int fila, int columna, Pieza* casillaDestino, int TableroBin[8][8]) override;
};

#endif