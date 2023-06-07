#include "caballo.hpp"

Caballo::Caballo(): Pieza(){
	m_icono[0]='C';
}
Caballo::Caballo(int fila, int columna, char color): Pieza(fila,columna,color){
	m_icono[0]='C';
}

bool Caballo::validarMovimiento(int fila, int columna, Pieza* casillaDestino, int TableroBin[8][8]){
	cout<<endl;

	//Origen == Destino
	if((m_fila==fila) && (m_columna==columna)){
		cout<<"\t* * * * * Movimiento   N O   V A L I D O :   La posicion de destino no puede ser igual a la posicion actual de la pieza * * * * *"<<endl;
		return false;
	}
	
	//Movimiento diferente al de una L
	if((m_columna-columna)*(m_columna-columna)+(m_fila-fila)*(m_fila-fila)!=5){
		cout<<"\t* * * * * Movimiento   N O   V A L I D O :   El caballo no puede avanzar a esa posicion * * * * *"<<endl;
		return false;
	}

	//Intenta comer
	if(casillaDestino!=nullptr){
		if(casillaDestino->getColor()==m_color){
			cout<<"\t* * * * * Movimiento   N O   V A L I D O :   Una pieza del mismo color ocupa la posicion de destino * * * * *"<<endl;
			return false;
		}
	}

	//Para los demas casos
	cout<<"\t\tMovimiento   V A L I D O ."<<endl;
	return true;
}