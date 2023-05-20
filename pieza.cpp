#include "pieza.hpp"

Pieza::Pieza(): m_columna{0}, m_fila{0}, m_color{'B'}, m_icono{"PB"} {}
Pieza::Pieza(int fila, int columna, char color): m_fila{fila}, m_columna{columna}, m_color{color} {
	m_icono="p";
	m_icono.push_back(m_color);
}

void Pieza::setColumna(int columna){
	m_columna=columna;
}
void Pieza::setFila(int fila){
	m_fila=fila;
}

int Pieza::getColumna() const{
	return m_columna;
}
int Pieza::getFila() const{
	return m_fila;
}
char Pieza::getColor() const{
	return m_color;
}
string Pieza::getIcono(){
	return m_icono;
}