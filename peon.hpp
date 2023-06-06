#ifndef PEON_HPP
#define PEON_HPP

#include "pieza.hpp"

class Peon: public Pieza{
	public:
		Peon();
		Peon(int fila, int columna, char color);
		~Peon() override = default;

		virtual bool validarMovimiento(int fila, int columna, Pieza* casillaDestino, int TableroBin[8][8]) override;

	private:
		bool primerMovimiento;
};

#endif