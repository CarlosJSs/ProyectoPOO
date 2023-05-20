#ifndef PEON_HPP
#define PEON_HPP

#include "pieza.hpp"

class Peon: public Pieza{
	public:
		Peon();
		Peon(int fila, int columna, char color);
		~Peon();

		virtual bool validarMovimiento(int fila, int columna, Pieza* casilla) override;

	private:
		bool primerMovimiento;
};

#endif