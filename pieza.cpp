#include "pieza.hpp"

//Inicializamos la pieza con valores validos
Pieza::Pieza(): m_columna{0}, m_fila{0}, m_color{'B'}, m_icono{"PB"} {}
//Al instanciarla le asignamos posicion (fila y columna), equipo (color) y un icono valido
Pieza::Pieza(int fila, int columna, char color): m_fila{fila}, m_columna{columna}, m_color{color} {
	m_icono="p";
	m_icono.push_back(m_color);
}

//Asignar columna
void Pieza::setColumna(int columna){
	m_columna=columna;
}

//Asignar fila
void Pieza::setFila(int fila){
	m_fila=fila;
}

//Obtener la columna de la pieza
int Pieza::getColumna() const{
	return m_columna;
}

//Obtener la fila de la pieza
int Pieza::getFila() const{
	return m_fila;
}

//Obtener el color de la pieza
char Pieza::getColor() const{
	return m_color;
}

//Obtener el icono de la pieza
string Pieza::getIcono(){
	return m_icono;
}