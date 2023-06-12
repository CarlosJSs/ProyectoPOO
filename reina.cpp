#include "reina.hpp"

//Inicializa la pieza como una Reina
Reina::Reina(): Pieza(){
	m_icono[0]='Q';
}
//Al instanciarla le asigna una posicion (fila y columna) y un equipo (color)
Reina::Reina(int fila, int columna, char color): Pieza(fila,columna,color){
	m_icono[0]='Q';
}

/*Validar que el movimiento indicado coincida con las reglas para la REINA
		->Recibe la posicion de la casilla de destino (fila y columna), el apuntador a la casilla destino (objeto tipo pieza)
			y una matriz de 8x8 que representa los lugares libres y ocupados en el tablero.
		->Regresa true si la pieza se puede mover a el destino indicado y false en caso de que no. */
bool Reina::validarMovimiento(int fila, int columna, Pieza* casillaDestino, int TableroBin[8][8]){
	cout<<endl;

	//Origen == Destino
	if((m_fila==fila) && (m_columna==columna)){
		cout<<"\t* * * * * Movimiento   N O   V A L I D O :   La posicion de destino no puede ser igual a la posicion actual de la pieza * * * * *"<<endl;
		return false;
	}

	//Movimiento diferente a + y x
	if((abs(m_columna-columna)!=abs(m_fila-fila)) && ((m_fila==fila)==(m_columna==columna))){
		cout<<"\t* * * * * Movimiento   N O   V A L I D O :   La Reina no puede avanzar a esa posicion * * * * *"<<endl;
		return false;
	}

	//-------------------- No puede brincar check -------------------------------------------------

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

	//Checar obstaculos en Diagonal
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
	//----------------------------------------------------------------------------------------------

	//Intenta comer
	if(casillaDestino!=nullptr){
		if(casillaDestino->getColor()==m_color){
			cout<<"\t* * * * * Movimiento   N O   V A L I D O :   Una pieza del mismo color ocupa la posicion de destino * * * * *"<<endl;
			return false;
		}
	}

	//Para todos los demas casos
	cout<<"\t\tMovimiento   V A L I D O ."<<endl;
	return true;
}