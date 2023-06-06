#ifndef REY_HPP
#define REY_HPP

#include "pieza.hpp"

class Rey: public Pieza{
    public:
        Rey();
        Rey(int fila, int columna, char color);
        ~Rey();

        bool validarMovimiento(int fila, int columna, Pieza* casillaDestino, int TableroBin[8][8]) override;
    
    protected:
        bool primerMovimiento;
};

#endif