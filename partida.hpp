#ifndef PARTIDA_HPP
#define PARTIDA_HPP

#include "tablero.hpp"
#include <iostream>

using namespace std;

class Partida{
    public:
        Partida();
        ~Partida() = default;
        
        void anunciarGanador() const;
        void realizarMovimiento();
        void iniciarPartida();

    private:
        Tablero m_tablero;
        int opcion;
        string casillaOrigen;
        string casillaDestino;
        bool turno; //  true:Blancas, false:Negras
        int flagGame;
};

#endif