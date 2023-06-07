#ifndef TABLERO_HPP
#define TABLERO_HPP

#include "pieza.hpp"
#include "alfil.hpp"
#include "caballo.hpp"
#include "peon.hpp"
#include "reina.hpp"
#include "rey.hpp"
#include "torre.hpp"

class Tablero{
	public:
		Tablero();
		~Tablero();

		void imprimirTablero();
		bool posicionValida(string pos) const;
		Pieza* buscarPieza(int fila, int columna);
		void eliminarPieza(int fila, int columna);
		bool moverPieza(int fila1, int columna1, int fila2, int columna2, bool turno);
		bool verificarReyB();
		bool verificarReyN();

	private:
		unsigned cantColumnas;
		unsigned cantFilas;
		unsigned cantPiezas;
		Pieza** listaPiezas;
};

#endif