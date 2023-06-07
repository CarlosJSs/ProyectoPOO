#include "partida.hpp"

Partida::Partida(){
    turno=true;
    opcion=0;
    flagGame=1;
}
    
void Partida::anunciarGanador() const{
    cout<<endl<<endl;
    cout<<endl<<"\t\t\t~ ~ ~ ~ ~ G A N A D O R :     P I E Z A S     "<<(turno? "B L A N C A S" : "N E G R A S")<<" ~ ~ ~ ~ ~";
    cout<<endl<<endl;
}
void Partida::realizarMovimiento(){
    cout<<endl<<"Movimiento:";
    cout<<endl<<"\tCasilla de Origen: ";
    cin>>casillaOrigen;
    cout<<"\tCasilla de Destino: ";
    cin>>casillaDestino;

    if(m_tablero.posicionValida(casillaOrigen) && m_tablero.posicionValida(casillaDestino)){
        if(m_tablero.moverPieza(casillaOrigen[1]-'1',casillaOrigen[0]-'A',casillaDestino[1]-'1',casillaDestino[0]-'A',turno)){

            if(!m_tablero.verificarReyB() || !m_tablero.verificarReyN()){
                flagGame=0;
    
                //m_tablero.imprimirTablero();

                cout<<endl<<"\t\t\t~ ~ ~ R E Y     "<<(!m_tablero.verificarReyB()? "B L A N C O" : "N E G R O")<<"     E L I M I N A D O ~ ~ ~";

                anunciarGanador();
            }

            turno=!turno;
        }
    }else{
        cout<<endl<<"Los valores introducidos NO SON VALIDOS.";
    }
}
void Partida::inciarPartida(){
    cout<<endl<<"\t\t~ ~ ~ ~ ~ I N I C I O     D E     L A     P A R T I D A ~ ~ ~ ~ ~"<<endl;

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
                anunciarGanador();
                break;
            default:
                cout<<endl<<"Opcion NO VALIDA: intente de nuevo.";
                break;
        }

    }while(flagGame && opcion!=0);

    cout<<"\t\t\t\t~ ~ ~ ~ ~ F I N     D E L     J U E G O ~ ~ ~ ~ ~"<<endl;
}