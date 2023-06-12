#include "peon.hpp"

//Inicializa la pieza como un Peon que no se ha movido
Peon::Peon(): Pieza(){
	primerMovimiento=true;
	m_icono[0]='P';
}
//Al instanciarla le asigna una posicion (fila y columna), un equipo (color) e indica que no se ha movido antes
Peon::Peon(int fila, int columna, char color): Pieza(fila,columna,color){
	primerMovimiento=true;
	m_icono[0]='P';
}

/*Validar que el movimiento indicado coincida con las reglas para el PEON
		->Recibe la posicion de la casilla de destino (fila y columna), el apuntador a la casilla destino (objeto tipo pieza)
			y una matriz de 8x8 que representa los lugares libres y ocupados en el tablero.
		->Regresa true si la pieza se puede mover a el destino indicado y false en caso de que no. */
bool Peon::validarMovimiento(int fila, int columna, Pieza* casillaDestino, int TableroBin[8][8]){
	cout<<endl;
	
	//Destino == Origen
	if((m_columna==columna) && (m_fila==fila)){
		cout<<"\t* * * * * Movimiento   N O   V A L I D O :   La posicion de destino no puede ser igual a la posicion actual de la pieza * * * * *"<<endl;
		return false;
	}

	//El peon aun no se ha movido
	if(primerMovimiento){
		//Quiere moverse dos casillas y el destino no esta ocupado
		if((m_columna==columna) && (m_fila-fila)==(m_color=='B'? -2 : 2) && casillaDestino==nullptr && TableroBin[fila+(m_color=='B'? -1 : 1)][columna]==0){
			cout<<"\t\tMovimiento   V A L I D O ."<<endl;
			primerMovimiento=false;
			return true;
		}
	}

	//Se quiere mover mas de 1 casilla o de lado (Moverse, No Comer)
	if(((m_fila-fila)!=(m_color=='B'? -1 : 1)) || abs(m_columna-columna)>1){
		cout<<"\t* * * * * Movimiento   N O   V A L I D O :   El Peon no puede moverse a esa posicion * * * * *"<<endl;
		return false;
	}

	//Se quiere mover de lado
	if(abs(m_columna-columna)){
		//Casilla destino sola (No puede comer)
		if(casillaDestino==nullptr){
			cout<<endl<<"\t* * * * * Movimiento   N O   V A L I D O :   Para comer, la casilla debe tener una pieza "<<(m_color=='B'? "NEGRA" : "BLANCA")<<" * * * * *"<<endl;
			return false;
		}

		//Casilla destino ocupada por una pieza propia
		if(casillaDestino->getColor()==m_color){
			cout<<endl<<"\t* * * * * Movimiento   N O   V A L I D O :   La casilla debe tener una pieza "<<(m_color=='B'? "NEGRA" : "BLANCA")<<" * * * * *"<<endl;
			return false;
		}
		
	}else if(casillaDestino!=nullptr){ //Quiere moverse al frente (comiendo)
		cout<<endl<<"\t* * * * * Movimiento   N O   V A L I D O :   La casilla debe estar vacia * * * * *"<<endl;
		return false;		
	}

	//Para los demas casos:
	cout<<"\t\tMovimiento   V A L I D O ."<<endl;
	primerMovimiento=false;
	return true;
}