#ifndef PARTIDA_HPP
#define PARTIDA_HPP

#include "tablero.hpp"

struct Partida{
    Partida();
    
    void anunciarGanador() const;
    void realizarMovimiento();
    void inciarPartida();

    Tablero m_tablero;
    int opcion;
    string casillaOrigen;
    string casillaDestino;
    bool turno; //  true:Blancas, false:Negras
    int flagGame;
};

#endif