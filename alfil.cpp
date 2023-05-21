#include "alfil.hpp"

Alfil::Alfil(){
	Pieza();
	m_icono[0]='A';
}
Alfil::Alfil(int fila, int columna, char color){
	Pieza(fila,columna,color);
	m_icono[0]='A';
}

bool Alfil::validarMovimiento(int fila, int columna, Pieza* casilla){
	cout<<endl;

	//Origen == Destino
	if((m_fila==fila) && (m_columna==columna)){
		cout<<"Movimiento NO VALIDO: La posicion de destino no puede ser igual a la posicion actual de la pieza."<<endl;
		return false;
	}

	//Movimiento diferente de diagonal
	if(abs(m_columna-columna)!=abs(m_fila-fila)){
		cout<<"Movimiento NO VALIDO: El alfil no puede avanzar a esa posicion"<<endl;
		return false;
	}

	//Intenta comer
	if(casilla!=nullptr){
		if(casilla->getColor()==m_color){
			cout<<"Movimiento NO VALIDO: Una pieza del mismo color ocupa la posicion de destino."<<endl;
			return false;
		}
	}
	cout<<"Movimiento VALIDO."<<endl;
	return true;
}