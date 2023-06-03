#include "torre.hpp"

Torre::Torre(): Pieza(){
	m_icono[0]='T';
}
Torre::Torre(int fila, int columna, char color): Pieza(fila,columna,color){
	m_icono[0]='T';
}

bool Torre::validarMovimiento(int fila, int columna, Pieza* casillaDestino, int TableroBin[8][8]){
	cout<<endl;

	//Origen == Destino
	if((m_fila==fila) && (m_columna==columna)){
		cout<<"Movimiento NO VALIDO: La posicion de destino no puede ser igual a la posicion actual de la pieza."<<endl;
		return false;
	}

	//Movimiento diferente a +
	if((m_fila==fila)==(m_columna==columna)){
		cout<<"Movimiento NO VALIDO: La torre no puede avanzar a esa posicion."<<endl;
		return false;
	}
	
	//Quiere comer una pieza propia
	if(casillaDestino!=nullptr){
		if(casillaDestino->getColor()==m_color){
			cout<<"Movimiento NO VALIDO: Una pieza del mismo color ocupa la posicion de destino."<<endl;
			return false;
		}
	}

	//Checar obstaculos en columna
	if(m_fila==fila){
		int clmnIni=(m_columna<columna)? m_columna+1 : columna+1;
		int clmnFin=(m_columna<columna)? columna-1 : m_columna-1;

		for(int clmnActual=clmnIni; clmnActual<=clmnFin; clmnActual+=1){
			if(TableroBin[m_fila][clmnActual]==1){
				cout<<"Movimiento NO VALIDO: El Caballo es la unica pieza que puede brincar otras piezas."<<endl;
				return false;
			}
		}
	}

	//Checar obstaculos en fila
	if(m_columna==columna){
		int flaIni=(m_fila<fila)? m_fila+1 : fila+1;
		int flaFin=(m_fila<fila)? fila-1 : m_fila-1;

		for(int flaActual=flaIni; flaActual<=flaFin; flaActual+=1){
			if(TableroBin[flaActual][m_columna]==1){
				cout<<"Movimiento NO VALIDO: El Caballo es la unica pieza que puede brincar otras piezas."<<endl;
				return false;
			}
		}
	}

	//Para todos los demas casos
	cout<<"Movimiento VALIDO."<<endl;
	return true;
}