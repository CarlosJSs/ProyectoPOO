#include "rey.hpp"

Rey::Rey(): Pieza(){
	primerMovimiento=true;
	m_icono[0]='K';
}
Rey::Rey(int fila, int columna, char color): Pieza(fila,columna,color){
	primerMovimiento=true;
	m_icono[0]='K';
}
Rey::~Rey(){}

bool Rey::validarMovimiento(int fila, int columna, Pieza* casillaDestino, int TableroBin[8][8]){
    cout<<endl;

    //Origen == Destino
	if((m_fila==fila) && (m_columna==columna)){
		cout<<"\t* * * * * Movimiento   N O   V A L I D O :   La posicion de destino no puede ser igual a la posicion actual de la pieza * * * * *"<<endl;
		return false;
	}

    //Intenta comer
    if(casillaDestino!=nullptr){
		if(casillaDestino->getColor()==m_color){
			cout<<"\t* * * * * Movimiento   N O   V A L I D O :   Una pieza del mismo color ocupa la posicion de destino * * * * *"<<endl;
			return false;
		}
	}


	//Permitir ENROQUE ========================================================
	if(primerMovimiento){

		//Para las blancas -----------------------------------------------------
		if(columna==6 && fila==0){//Enroque Corto
			if(TableroBin[0][5]==0 && TableroBin[0][6]==0){
				return true;
			}
		}
		if(columna==2 && fila==0){//Enroque largo
			if(TableroBin[0][1]==0 && TableroBin[0][2]==0 && TableroBin[0][3]==0){
				return true;
			}
		}

		//Para las negras ------------------------------------------------------
		if(columna==6 && fila==7){//Enroque Corto
			if(TableroBin[7][5]==0 && TableroBin[7][6]==0){
				return true;
			}
		}
		if(columna==2 && fila==7){//Enroque largo
			if(TableroBin[7][1]==0 && TableroBin[7][2]==0 && TableroBin[7][3]==0){
				return true;
			}
		}

	}
	//============================================================================


    //Quiere mover mas de una casilla
    if((abs(m_columna-columna)>1 || abs(m_fila-fila)>1)){

    	if(primerMovimiento && fila==0 && (columna==2 || columna==6) && m_color=='B'){
    		primerMovimiento=false;
    		return true;
    	}
    	if(primerMovimiento && fila==7 && (columna==2 || columna==6) && m_color=='N'){
    		primerMovimiento=false;
    		return true;
    	}

			cout<<"\t* * * * * Movimiento   N O   V A L I D O :   El Caballo es la unica pieza que puede brincar otras piezas * * * * *"<<endl;
		return false;
    }


    //Para todos los demas casos
	cout<<"\t\tMovimiento   V A L I D O ."<<endl;
    primerMovimiento=false;
    return true;
}
