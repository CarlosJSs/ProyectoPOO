#ifdef _WIN32
  #include<windows.h>
#endif  


#ifndef MENU_HPP
#define MENU_HPP

#include "partida.hpp"
#include <cstdlib> 

using namespace std;

struct Menu{
    Menu();
    ~Menu() = default;

    void mostrarMenu();
    void iniciarPartida();
    void limpiarPantalla();
};

#endif