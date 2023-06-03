#include "peon.hpp"

Peon::Peon(): Pieza(){
	primerMovimiento=true;
	m_icono[0]='P';
}
Peon::Peon(int fila, int columna, char color): Pieza(fila,columna,color){
	primerMovimiento=true;
	m_icono[0]='P';
}

bool Peon::validarMovimiento(int fila, int columna, Pieza* casillaDestino, int TableroBin[8][8]){
	cout<<endl;
	
	//Destino == Origen
	if((m_columna==columna) && (m_fila==fila)){
		cout<<"Movimiento NO VALIDO: La posicion de destino no puede ser igual a la posicion actual de la pieza."<<endl;
		return false;
	}

	//El peon aun no se ha movido
	if(primerMovimiento){
		//Quiere moverse dos casillas y el destino no esta ocupado
		if((m_columna==columna) && (m_fila-fila)==(m_color=='B'? -2 : 2) && casillaDestino==nullptr){
			cout<<"Movimiento VALIDO."<<endl;
			primerMovimiento=false;
			return true;
		}
	}

	//Se quiere mover mas de 1 casilla o de lado (Moverse, No Comer)
	if(((m_fila-fila)!=(m_color=='B'? -1 : 1)) || abs(m_columna-columna)>1){
		cout<<"Movimiento NO VALIDO: El peon no puede moverse a esa posicion.";
		return false;
	}

	//Se quiere mover de lado
	if(abs(m_columna-columna)){
		//Casilla destino sola (No puede comer)
		if(casillaDestino==nullptr){
			cout<<endl<<"Movimiento No VALIDO: Para comer, la casilla debe tener una pieza "<<(m_color=='B'? "NEGRA" : "BLANCA");
			return false;
		}

		//Casilla destino ocupada por una pieza propia
		if(casillaDestino->getColor()==m_color){
			cout<<endl<<"Movimiento NO VALIDO: La casilla debe tener una pieza "<<(m_color=='B'? "NEGRA" : "BLANCA");
			return false;
		}
		
	}else if(casillaDestino!=nullptr){ //Quiere moverse al frente (comiendo)
		cout<<"Movimiento NO VALIDO: La casilla debe estar vacia."<<endl;
		return false;		
	}

	//Para los demas casos:
	cout<<"Movimiento VALIDO."<<endl;
	primerMovimiento=false;
	return true;
}