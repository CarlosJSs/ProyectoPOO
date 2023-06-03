#include "reina.hpp"

Reina::Reina(): Pieza(){
	m_icono[0]='Q';
}
Reina::Reina(int fila, int columna, char color): Pieza(fila,columna,color){
	m_icono[0]='Q';
}

bool Reina::validarMovimiento(int fila, int columna, Pieza* casillaDestino, int TableroBin[8][8]){
	cout<<endl;

	//Origen == Destino
	if((m_fila==fila) && (m_columna==columna)){
		cout<<"Movimiento NO VALIDO: La posicion de destino no puede ser igual a la posicion actual de la pieza."<<endl;
		return false;
	}

	//Movimiento diferente a + y x
	if((abs(m_columna-columna)!=abs(m_fila-fila)) && ((m_fila==fila)==(m_columna==columna))){
		cout<<"Movimiento NO VALIDO: La Reina no puede avanzar a esa posicion"<<endl;
		return false;
	}

	//Intenta comer
	if(casillaDestino!=nullptr){
		if(casillaDestino->getColor()==m_color){
			cout<<"Movimiento NO VALIDO: Una pieza del mismo color ocupa la posicion de destino."<<endl;
			return false;
		}
	}

	//Para todos los demas casos
	cout<<"Movimiento VALIDO."<<endl;
	return true;
}