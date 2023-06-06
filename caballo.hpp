#ifndef CABALLO_HPP
#define CABALLO_HPP

#include "pieza.hpp"

struct Caballo: public Pieza{
	Caballo();
	Caballo(int fila, int columna, char color);
	~Caballo() override = default;

	bool validarMovimiento(int fila, int columna, Pieza* casillaDestino, int TableroBin[8][8]) override;
};

#endif