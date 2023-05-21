#include "torre.hpp"

Torre::Torre(){
	Pieza();
	m_icono[0]='T';
}
Torre::Torre(int fila, int columna, char color){
	Pieza(fila,columna,color);
	m_icono[0]='T';
}

bool Torre::validarMovimiento(int fila, int columna, Pieza* casilla){
	cout<<endl;

	//Origen == Destino
	if((m_fila==fila) && (m_columna==columna)){
		cout<<"Movimiento NO VALIDO: La posicion de destino no puede ser igual a la posicion actual de la pieza."<<endl;
		return false;
	}

	//Movimiento diferente a +
	if((m_fila==fila)==(m_columna==m_columna)){
		cout<<"Movimiento NO VALIDO: La torre no puede avanzar a esa posicion."<<endl;
		return false;
	}

	//Quiere comer una pieza propia
	if(casilla!=nullptr){
		if(casilla->getColor()==m_color){
			cout<<"Movimiento NO VALIDO: Una pieza del mismo color ocupa la posicion de destino."<<endl;
			return false;
		}
	}

	//Para todos los demas casos
	cout<<"Movimiento VALIDO."<<endl;
	return true;
}