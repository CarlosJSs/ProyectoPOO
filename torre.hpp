#ifndef TORRE_HPP
#define TORRE_HPP

#include "pieza.hpp"

class Torre: public Pieza{
	public:
		Torre();
		Torre(int fila, int columna, char color);
		~Torre() override = default;

		bool validarMovimiento(int fila, int columna, Pieza* casillaDestino, int TableroBin[8][8]) override;
		
	protected:
		bool primerMovimiento;
};

#endif