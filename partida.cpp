#include "partida.hpp"

Partida::Partida(){
    turno=true;
    opcion=0;
}
    
void Partida::anunciarGanador() const{
    cout<<endl<<"GANADOR: Piezas "<<(turno? "BLANCAS" : "NEGRAS");
}
void Partida::realizarMovimiento(){
    cout<<endl<<"Movimiento:";
    cout<<endl<<"\tCasilla de Origen: ";
    cin>>casillaOrigen;
    cout<<"\tCasilla de Destino: ";
    cin>>casillaDestino;

    if(m_tablero.posicionValida(casillaOrigen) && m_tablero.posicionValida(casillaDestino)){
        if(m_tablero.moverPieza(casillaOrigen[1]-'1',casillaOrigen[0]-'A',casillaDestino[1]-'1',casillaDestino[0]-'A',turno)){
            turno=!turno;
        }
    }else{
        cout<<endl<<"Los valores introducidos NO SON VALIDOS.";
    }
}
void Partida::inciarPartida(){
    cout<<endl<<"Inicio de la partdida..."<<endl;

    do{
        m_tablero.imprimirTablero();

        cout<<endl<<"Turno de las piezas "<<(turno? "BLANCAS" : "NEGRAS")<<".";
        cout<<endl<<"\tOpciones:";
        cout<<endl<<"\t\t - 1: Mover una pieza.";
        cout<<endl<<"\t\t - 0: Rendirse.";
        cout<<endl<<endl;

        do{
            cout<<"\tDigite la opcion deseada: ";
            cin>>opcion;
        }while(opcion!=0 && opcion!=1);

        switch(opcion){
            case 1:
                realizarMovimiento();
                break;
            case 0:
                cout<<endl<<"Las piezas "<<(turno? "BLANCAS" : "NEGRAS")<<" se han rendido.";
                turno=!turno;
                break;
            default:
                cout<<endl<<"Opcion NO VALIDA: intente de nuevo.";
                break;
        }

    }while(opcion!=0);
    
    cout<<endl<<endl<<"\t\tFIN DEl JUEGO...";
    cout<<endl<<"\t\tGanador: Piezas "<<(turno? "BLANCAS" : "NEGRAS")<<".";
}