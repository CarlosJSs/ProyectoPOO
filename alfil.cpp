#include "alfil.hpp"

Alfil::Alfil(): Pieza(){
	m_icono[0]='A';
}
Alfil::Alfil(int fila, int columna, char color): Pieza(fila,columna,color){
	m_icono[0]='A';
}

bool Alfil::validarMovimiento(int fila, int columna, Pieza* casillaDestino, int TableroBin[8][8]){
	cout<<endl;

	//Origen == Destino
	if((m_fila==fila) && (m_columna==columna)){
		cout<<"\t* * * * * Movimiento   N O   V A L I D O :   La posicion de destino no puede ser igual a la posicion actual de la pieza * * * * *"<<endl;
		return false;
	}

	//Movimiento diferente de diagonal
	if(abs(m_columna-columna)!=abs(m_fila-fila)){
		cout<<"\t* * * * * Movimiento   N O   V A L I D O :   El Alfil no puede avanzar a esa posicion * * * * *"<<endl;
		return false;
	}

	//---------------------------Checar obstaculos en Diagonal -----------------------------------
	int flaActual=m_fila;
	int clmnActual=m_columna;
	int flaDiferencia=(fila>m_fila)? 1 : -1;
	int clmnDiferencia=(columna>m_columna)? 1 : -1;

	while(flaActual!=fila && clmnActual!=columna){
		flaActual+=flaDiferencia;
		clmnActual+=clmnDiferencia;

		if(flaActual==fila && clmnActual==columna){
			break;
		}

		if(TableroBin[flaActual][clmnActual]==1){
			cout<<"\t* * * * * Movimiento   N O   V A L I D O :   El Caballo es la unica pieza que puede brincar otras piezas * * * * *"<<endl;
			return false;
		}
	}
	//---------------------------------------------------------

	//Intenta comer
	if(casillaDestino!=nullptr){
		if(casillaDestino->getColor()==m_color){
			cout<<"\t* * * * * Movimiento   N O   V A L I D O :   Una pieza del mismo color ocupa la posicion de destino * * * * *"<<endl;
			return false;
		}
	}

	cout<<"\t\tMovimiento   V A L I D O ."<<endl;
	return true;
}