#include "tablero.hpp"

Tablero::Tablero(): cantColumnas(8), cantFilas(8), cantPiezas(32){
	
	//Creamos un arreglo apuntadores a objetos tipo Pieza
	listaPiezas=new Pieza*[cantPiezas];

	// Insertar las torres en la lista
    listaPiezas[0] = new Torre(0,0,'B');
    listaPiezas[1] = new Torre(0,7,'B');
    listaPiezas[2] = new Torre(7,0,'N');
    listaPiezas[3] = new Torre(7,7,'N');

    // Insertar los caballos en la lista
    listaPiezas[4] = new Caballo(0,1,'B');
    listaPiezas[5] = new Caballo(0,6,'B');
    listaPiezas[6] = new Caballo(7,1,'N');
    listaPiezas[7] = new Caballo(7,6,'N');

    // Insertar los alfiles en la lista
    listaPiezas[8] = new Alfil(0,2,'B');
    listaPiezas[9] = new Alfil(0,5,'B');
    listaPiezas[10] = new Alfil(7,2,'N');
    listaPiezas[11] = new Alfil(7,5,'N');

    // Insertar las reinas en la lista
    listaPiezas[12] = new Reina(0,3,'B');
    listaPiezas[13] = new Reina(7,3,'N');

    // Insertar los reyes en la lista
    listaPiezas[14] = new Rey(0,4,'B');
    listaPiezas[15] = new Rey(7,4,'N');

    // Insertar los peones en la lista
    for(int i=0; i<cantColumnas; i++) {
        listaPiezas[16+2*i] = new Peon(1,i,'B');
        listaPiezas[17+2*i] = new Peon(6,i,'N');
    }
}
Tablero::~Tablero(){
	//Liberamos la memoria asignada para cada pieza
	for(int i=0;i<cantPiezas;i+=1){
		delete listaPiezas[i];
		listaPiezas[i]=nullptr;
	}
	//Liberamos la memoria del arreglo
	delete[] listaPiezas;
}

void Tablero::imprimirTablero(){
	//Nuestro tablero sera una Matriz
	string myTablero[cantFilas][cantColumnas];

	//Llenarlo de strings vacios
	for(int i=0;i<cantFilas;i+=1)
		for(int j=0;j<cantColumnas;j+=1)
			myTablero[i][j]="";

	//Insertar cada icono (pieza) en su lugar
	for(int i=0;i<cantPiezas;i+=1)
		myTablero[listaPiezas[i]->getFila()][listaPiezas[i]->getColumna()]=listaPiezas[i]->getIcono();

	//Lineas de separacion (-) y linea de casillas
	for(int i=int(cantFilas)-1;i>=0;i-=1){
		
		//Parte de la separacion
		cout<<endl<<string(2,' ');
		for(int j=0;j<cantColumnas;j+=1)
			cout<<setfill('-')<<setw(5)<<left<<'+';
		cout<<'+'<<endl;

		//Parte de las casillas
		cout<<setfill(' ')<<setw(2)<<left<<i+1;
		for(int j=0;j<cantColumnas;j+=1){
            cout<<setfill(' ')<<setw(2)<<left<<'|';
            cout<<setfill(' ')<<setw(3)<<left<<myTablero[i][j];
		}
		cout<<'|';
	}

	//Ultima linea separadora (-)
	cout<<endl<<string(2,' ');
	for(int i=0;i<cantColumnas;i+=1)
		cout<<setfill('-')<<setw(5)<<left<<'+';
	cout<<'+';

	//Linea de letras
	cout<<endl;
	cout<<string(2,' ');
	for(int i=0; i<cantColumnas;i+=1)
		cout<<setfill(' ')<<setw(5)<<left<<char('A'+i);
	cout<<' '<<endl;

}
bool Tablero::posicionValida(string pos) const{
	if(pos.size()!=2) return false;
	if(!(pos[1]>='1' && pos[1]<'1'+cantFilas)) return false;
	if(!(pos[0]>='A' && pos[0]<'A'+cantColumnas)) return false;
	return true;
}
Pieza* Tablero::buscarPieza(int fila, int columna){
	for(int i=0;i<cantPiezas;i+=1)
		if(listaPiezas[i]->getFila()==fila && listaPiezas[i]->getColumna()==columna)
			return listaPiezas[i];

	return nullptr;
}
void Tablero::eliminarPieza(int fila, int columna){
	Pieza* eliminada=buscarPieza(fila,columna);

	if(eliminada!=nullptr){
		Pieza** Aux=new Pieza* [cantPiezas-1];
		int contador=0;

		for(int i=0;i<cantPiezas;i+=1){
			if(eliminada->getColumna()!=listaPiezas[i]->getColumna() || eliminada->getFila()!=listaPiezas[i]->getFila()){
				Aux[contador]=listaPiezas[i];
				contador+=1;
			}
		}

		delete[] listaPiezas;
		listaPiezas=Aux;
		cantPiezas-=1;
		delete eliminada;
	}
}
bool Tablero::moverPieza(int fila1, int columna1, int fila2, int columna2, bool turno){
	Pieza* casillaOrigen=buscarPieza(fila1,columna1);
	Pieza* casillaDestino=buscarPieza(fila2,columna2);

	//Origen es una casilla sola
	if(casillaOrigen==nullptr){
		cout<<endl<<"Movimiento NO VALIDO: No hay una pieza en la posicion de inicio.";
		return false;
	}
	//Quiere mover una pieza agena
	if(casillaOrigen->getColor()!=(turno? 'B':'N')){
		cout<<endl<<"Movimiento NO VALIDO: Solo se pueden elegir piezas "<<(turno? "BLANCAS" : "NEGRAS");
		return false;
	}

	//------------------------------------No brincar piezas check----------------------------------------
	//Nos apoyaremos de un tablero auxiliar
	int auxTablero[8][8];

	//Llenarlo de ceros (0)
	for(int i=0;i<cantFilas;i+=1)
		for(int j=0;j<cantColumnas;j+=1)
			auxTablero[i][j]=0;

	//Si hay una pieza, ponemos un 1
	for(int i=0;i<cantPiezas;i+=1){
		auxTablero[listaPiezas[i]->getFila()][listaPiezas[i]->getColumna()]=1;
	}
	//------------------------------------------------------------------------------

	//Si la pieza no se puede mover asi
	if(!(casillaOrigen->validarMovimiento(fila2,columna2,casillaDestino,auxTablero))){
		return false;
	}
	
	//Si la casilla Destino esta ocupada
	if(casillaDestino!=nullptr){
		eliminarPieza(fila2,columna2);
	}
	

	//-------------------------------Hacer ENROQUE--------------------------------
	//Para las blancas
	if(casillaOrigen->getIcono()=="KB" && turno){

		//Enroque corto
		if(fila2==0 && columna2==6){
			Pieza* auxTorre=buscarPieza(0,7);

			if(auxTorre->validarMovimiento(0,5,buscarPieza(0,5),auxTablero)){
				if(casillaOrigen->validarMovimiento(0,6,casillaDestino,auxTablero)){
					auxTorre->setFila(0);
					auxTorre->setColumna(5);
				}
			}

		}

		//Enroque Largo
		if(fila2==0 && columna2==2){
			Pieza* auxTorre=buscarPieza(0,0);

			if(auxTorre->validarMovimiento(0,3,buscarPieza(0,3),auxTablero)){
				if(casillaOrigen->validarMovimiento(0,2,casillaDestino,auxTablero)){
					auxTorre->setFila(0);
					auxTorre->setColumna(3);
				}
			}

		}
	}

	//Para las negras
	if(casillaOrigen->getIcono()=="KN" && !turno){

		//Enroque corto
		if(fila2==7 && columna2==6){
			Pieza* auxTorre=buscarPieza(7,7);

			if(auxTorre->validarMovimiento(7,5,buscarPieza(7,5),auxTablero)){
				if(casillaOrigen->validarMovimiento(7,6,casillaDestino,auxTablero)){
					auxTorre->setFila(7);
					auxTorre->setColumna(5);
				}
			}

		}

		//Enroque Largo
		if(fila2==7 && columna2==2){
			Pieza* auxTorre=buscarPieza(7,0);

			if(auxTorre->validarMovimiento(7,3,buscarPieza(7,3),auxTablero)){
				if(casillaOrigen->validarMovimiento(7,2,casillaDestino,auxTablero)){
					auxTorre->setFila(7);
					auxTorre->setColumna(3);
				}
			}
			
		}
	}
	//----------------------------------------------------------------------------


	//-------------------------------Coronar Peon---------------------------------
	if(casillaOrigen->getIcono()[0]=='P' && fila2==7 && turno){
		//eliminarPieza(fila2,columna2);
		
		int indicePeon=-1;
		for(int i=0;i<cantPiezas;i++){
			if(listaPiezas[i]==casillaOrigen){
				indicePeon=i;
				break;
			}
		}
		if(indicePeon!=-1){
			delete listaPiezas[indicePeon];

			unsigned eleccion=0;

			cout<<"~~~CORONAR PEON~~~"<<endl;
			cout<<"Seleccione la pieza por la cual cambiar su peon:"<<endl;
			cout<<"0.- Ninguna (Peon)";
			cout<<"1.- Reina";
			cout<<"2.- Torre";
			cout<<"3.- Alfil";
			cout<<"4.- Caballo";
			cout<<"Su eleccion: ";

			cin>>eleccion;

			switch(eleccion){
				case 0:
					listaPiezas[indicePeon]=new Peon(fila1,columna1,'B');
					break;
				case 1:
					listaPiezas[indicePeon]=new Reina(fila1,columna1,'B');
					break;
				case 2:
					listaPiezas[indicePeon]=new Torre(fila1,columna1,'B');
					break;
				case 3:
					listaPiezas[indicePeon]=new Alfil(fila1,columna1,'B');
					break;
				case 4:
					listaPiezas[indicePeon]=new Caballo(fila1,columna1,'B');
					break;
				default:
					listaPiezas[indicePeon]=new Peon(fila1,columna1,'B');
					break;
			}

			casillaOrigen=listaPiezas[indicePeon];
		}
	}

	if(casillaOrigen->getIcono()[0]=='P' && fila2==0 && !turno){
		//eliminarPieza(fila2,columna2);
		
		int indicePeon=-1;
		for(int i=0;i<cantPiezas;i++){
			if(listaPiezas[i]==casillaOrigen){
				indicePeon=i;
				break;
			}
		}
		if(indicePeon!=-1){
			delete listaPiezas[indicePeon];

			unsigned eleccion=0;

			cout<<"~~~CORONAR PEON~~~"<<endl;
			cout<<"Seleccione la pieza por la cual cambiar su peon:"<<endl;
			cout<<"0.- Ninguna (Peon)";
			cout<<"1.- Reina";
			cout<<"2.- Torre";
			cout<<"3.- Alfil";
			cout<<"4.- Caballo";
			cout<<"Su eleccion: ";

			cin>>eleccion;

			switch(eleccion){
				case 0:
					listaPiezas[indicePeon]=new Peon(fila1,columna1,'N');
					break;
				case 1:
					listaPiezas[indicePeon]=new Reina(fila1,columna1,'N');
					break;
				case 2:
					listaPiezas[indicePeon]=new Torre(fila1,columna1,'N');
					break;
				case 3:
					listaPiezas[indicePeon]=new Alfil(fila1,columna1,'N');
					break;
				case 4:
					listaPiezas[indicePeon]=new Caballo(fila1,columna1,'N');
					break;
				default:
					listaPiezas[indicePeon]=new Peon(fila1,columna1,'N');
					break;
			}

			casillaOrigen=listaPiezas[indicePeon];
		}
	}
	//-----------------------------------------------------------------------------

	//Para los demas casos
	casillaOrigen->setFila(fila2);
	casillaOrigen->setColumna(columna2);

	return true;
}
bool Tablero::verificarReyB(){
	for(int i=0; i<cantPiezas; i+=1){
		if(listaPiezas[i]->getIcono()=="KB"){
			return true;
		}
	}
	return false;
}
bool Tablero::verificarReyN(){
	for(int i=0; i<cantPiezas; i+=1){
		if(listaPiezas[i]->getIcono()=="KN"){
			return true;
		}
	}
	return false;
}