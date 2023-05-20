#ifndef PIEZA_HPP
#define PIEZA_HPP

#include <string>

class Pieza{
	public:
		Pieza();
		Pieza(int fila, int columna, char color);

		void setColumna(int columna);
		void setFila(int fila);

		int getColumna() const;
		int getFila() const;
		char getColor() const;
		string getIcono();

		virtual bool validarMovimiento(int fila, int columna, Pieza* casilla) = 0;

	protected:
		int m_columna;
		int m_fila;
		char m_color;
		string m_icono;
};

#endif