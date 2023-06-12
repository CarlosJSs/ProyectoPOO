#include "torre.hpp"

//Inicializa la pieza como una TORRE que no se ha movido
Torre::Torre(): Pieza(){
	primerMovimiento=true;
	m_icono[0]='T';
}
//Al instanciarla le asigna una posicion (fila y columna), un equipo (color) e indica que no se ha movido antes
Torre::Torre(int fila, int columna, char color): Pieza(fila,columna,color){
	primerMovimiento=true;
	m_icono[0]='T';
}

/*Validar que el movimiento indicado coincida con las reglas para la TORRE
		->Recibe la posicion de la casilla de destino (fila y columna), el apuntador a la casilla destino (objeto tipo pieza)
			y una matriz de 8x8 que representa los lugares libres y ocupados en el tablero.
		->Regresa true si la pieza se puede mover a el destino indicado y false en caso de que no. */
bool Torre::validarMovimiento(int fila, int columna, Pieza* casillaDestino, int TableroBin[8][8]){
	cout<<endl;

	//Origen == Destino
	if((m_fila==fila) && (m_columna==columna)){
		cout<<"\t* * * * * Movimiento   N O   V A L I D O :   La posicion de destino no puede ser igual a la posicion actual de la pieza * * * * *"<<endl;
		return false;
	}

	//Movimiento diferente a +
	if((m_fila==fila)==(m_columna==columna)){
		cout<<"\t* * * * * Movimiento   N O   V A L I D O :   La Torre no puede avanzar a esa posicion * * * * *"<<endl;
		return false;
	}
	
	//Quiere comer una pieza propia
	if(casillaDestino!=nullptr){
		if(casillaDestino->getColor()==m_color){
			cout<<"\t* * * * * Movimiento   N O   V A L I D O :   Una pieza del mismo color ocupa la posicion de destino * * * * *"<<endl;
			return false;
		}
	}

	//Checar obstaculos en columna
	if(m_fila==fila){
		int clmnIni=(m_columna<columna)? m_columna+1 : columna+1;
		int clmnFin=(m_columna<columna)? columna-1 : m_columna-1;

		for(int clmnActual=clmnIni; clmnActual<=clmnFin; clmnActual+=1){
			if(TableroBin[m_fila][clmnActual]==1){
				cout<<"\t* * * * * Movimiento   N O   V A L I D O :   El Caballo es la unica pieza que puede brincar otras piezas * * * * *"<<endl;
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
				cout<<"\t* * * * * Movimiento   N O   V A L I D O :   El Caballo es la unica pieza que puede brincar otras piezas * * * * *"<<endl;
				return false;
			}
		}
	}

	//Permitir ENROQUE ========================================================
	if(primerMovimiento){

		//Para las blancas -----------------------------------------------------
		if(columna==5 && fila==0){//Enroque Corto
			if(TableroBin[0][5]==0 && TableroBin[0][6]==0){
				primerMovimiento=false;
				return true;
			}
		}
		if(columna==3 && fila==0){//Enroque largo
			if(TableroBin[0][1]==0 && TableroBin[0][2]==0 && TableroBin[0][3]){
				primerMovimiento=false;
				return true;
			}
		}

		//Para las negras ------------------------------------------------------
		if(columna==5 && fila==7){//Enroque Corto
			if(TableroBin[7][5]==0 && TableroBin[7][6]==0){
				primerMovimiento=false;
				return true;
			}
		}
		if(columna==3 && fila==7){//Enroque largo
			if(TableroBin[7][1]==0 && TableroBin[7][2]==0 && TableroBin[7][3]){
				primerMovimiento=false;
				return true;
			}
		}

	}
	//============================================================================


	//Para todos los demas casos
	cout<<"\t\tMovimiento   V A L I D O ."<<endl;
    primerMovimiento=false;
	return true;
}
