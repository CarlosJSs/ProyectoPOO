#ifndef REY_HPP
#define REY_HPP

#include "pieza.hpp"

struct Rey: public Pieza{
    Rey();
    Rey(int fila, int columna, char color);

    bool validarMovimiento(int fila, int columna, Pieza* casillaDestino, int TableroBin[8][8]) override;
};

#endif