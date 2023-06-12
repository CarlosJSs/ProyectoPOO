#include "partida.hpp"

//Inicializar la partida correctamente
Partida::Partida(){
    turno=true;
    opcion=0;
    flagGame=1;
}

//Imprimir el ganador del juego de acuerdo al valor de "turno"
void Partida::anunciarGanador() const{
    cout<<endl<<endl;
    cout<<"\t\t\t~ ~ ~ ~ ~    G A N A D O R :     P I E Z A S     "<<(turno? "B L A N C A S" : "N E G R A S")<<"    ~ ~ ~ ~ ~";
    cout<<endl<<endl;
}

/*Realizar el movimiento indcado
        Hara las validaciones necesarias dependiendo de la pieza y el estado del tablero,
        en caso de estar correcto cambia de turno */
void Partida::realizarMovimiento(){
    cout<<endl<<"\t\tMovimiento:";
    cout<<endl<<"\t\t\tCasilla de Origen: ";
    cin>>casillaOrigen;
    cout<<"\t\t\tCasilla de Destino: ";
    cin>>casillaDestino;

    if(m_tablero.posicionValida(casillaOrigen) && m_tablero.posicionValida(casillaDestino)){
        if(m_tablero.moverPieza(casillaOrigen[1]-'1',casillaOrigen[0]-'A',casillaDestino[1]-'1',casillaDestino[0]-'A',turno)){

            if(!m_tablero.verificarReyB() || !m_tablero.verificarReyN()){
                flagGame=0;
                m_tablero.imprimirTablero();
                cout<<endl<<"\t\t\t\t~ ~ ~ R E Y     "<<(!m_tablero.verificarReyB()? "B L A N C O" : "N E G R O")<<"     E L I M I N A D O ~ ~ ~";
                anunciarGanador();
            }

            turno=!turno;
        }
    }else{
        cout<<endl<<"Los valores introducidos NO SON VALIDOS.";
    }
}

/*Inicia la partida de Ajedrez
        Muestra el tablero y conforme va avanzando el juego nos da la opcion de seguir jugando o rendirnos */
void Partida::iniciarPartida(){
    cout<<endl<<"\t\t~ ~ ~ ~ ~ I N I C I O     D E     L A     P A R T I D A ~ ~ ~ ~ ~"<<endl;

    do{
        m_tablero.imprimirTablero();

        cout<<endl<<"\t~ ~ ~ ~ ~ Turno de las piezas   "<<(turno? "B L A N C A S" : "N E G R A S")<<"   ~ ~ ~ ~ ~"<<endl;
        cout<<endl<<"\t\tO P C I O N E S :";
        cout<<endl<<"\t\t\t -> 1: MOVER una pieza.";
        cout<<endl<<"\t\t\t -> 0: RENDIRSE.";
        cout<<endl<<endl;

        do{
            cout<<"\t\tDigite la opcion deseada: ";
            cin>>opcion;
        }while(opcion!=0 && opcion!=1);

        switch(opcion){
            case 1:
                realizarMovimiento();
                break;
            case 0:
                cout<<endl<<endl<<"\t\t~ ~ ~ ~ ~    Las piezas   "<<(turno? "B L A N C A S" : "N E G R A S")<<"   se han   R E N D I D O    ~ ~ ~ ~ ~";
                turno=!turno;
                anunciarGanador();
                break;
            default:
                cout<<endl<<"\t\t* * * * * Opcion   N O    V A L I D A :   intente de nuevo * * * * *";
                break;
        }

    }while(flagGame && opcion!=0);

    cout<<"\t\t\t\t~ ~ ~ ~ ~    F I N     D E L     J U E G O    ~ ~ ~ ~ ~"<<endl<<endl<<endl;
}