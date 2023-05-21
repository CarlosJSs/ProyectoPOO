#include "rey.hpp"

Rey::Rey(){
    Pieza();
	m_icono[0]='K';
}
Rey::Rey(int fila, int columna, char color){
    Pieza(fila,columna,color);
	m_icono[0]='K';
}

bool Rey::validarMovimiento(int fila, int columna, Pieza* casilla){
    cout<<endl;

    //Origen == Destino
	if((m_fila==fila) && (m_columna==columna)){
		cout<<"Movimiento NO VALIDO: La posicion de destino no puede ser igual a la posicion actual de la pieza."<<endl;
		return false;
	}

    //Quiere mover mas de una casilla
    if(abs(m_columna-columna)>1 || abs(m_fila-fila)>1){
        cout<<"Movimiento NO VALIDO: El Rey no puede avanzar a esa posicion"<<endl;
		return false;
    }

    //Intenta comer
    if(casilla!=nullptr){
		if(casilla->getColor()==m_color){
			cout<<"Movimiento NO VALIDO: Una pieza del mismo color ocupa la posicion de destino."<<endl;
			return false;
		}
	}

    //Para todos los demas casos
    cout<<"Movimiento VALIDO.";
    return true;
}