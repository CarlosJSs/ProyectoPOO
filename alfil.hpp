#ifndef ALFIL_HPP
#define ALFIL_HPP

struct Alfil: public Pieza{
	Alfil();
	Alfil(int fila, int columna, char color);

	bool validarMovimiento(int fila, int columna, Pieza* casilla) override;
};

#endif