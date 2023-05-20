#include "peon.hpp"

Peon::Peon(){
	Pieza();
	primerMovimiento=true;
	m_icono[0]='P';
}
Peon::Peon(int fila, int columna, char color){
	Pieza(fila,columna,color);
	primerMovimiento=true;
	m_icono[0]='P';
}

bool Peon::validarMovimiento(int fila, int columna, Pieza* casilla){
	cout<<endl;
	
	//Destino == Origen
	if((m_columna==columna) && (m_fila==fila)){
		cout<<"Movimiento NO VALIDO: La posicion de destino no puede ser igual a la posicion actual de la pieza."<<endl;
		return false;
	}

	if(primerMovimiento){
		if((m_columna==columna) && ()){

		}
	}
}