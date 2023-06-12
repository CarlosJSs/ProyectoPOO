#include "menu.hpp"

Menu::Menu(){}

/*Limpiar pantalla de la consola
        Nos permite limpiar la pantalla dependiendo del OS del usuario */
void Menu::limpiarPantalla(){
	#ifdef _WIN32
        system("cls"); //Para windows
    #else
        system("clear"); //Para Linux
    #endif
}

/*Iniciar la partida de ajedrez
        Crea un objeto Partida y comienza con el juego */
void Menu::iniciarPartida(){
    Partida partida;
    partida.iniciarPartida(); 
}

//Mostrar las opciones del menu principal
void Menu::mostrarMenu(){

cout<<"\n\n";
cout<<" 88888888b dP     .88888.                      dP       oo   dP                     dP              a88888b.\n";
cout<<" 88        88    d8'   `88                     88            88                     88             d8'   `88    dP       dP\n";
cout<<"a88aaaa    88    88        .d8888b. 88d8b.d8b. 88d888b. dP d8888P .d8888b.    .d888b88 .d8888b.    88           88       88\n";
cout<<" 88        88    88   YP88 88'  `88 88'`88'`88 88'  `88 88   88   88'  `88    88'  `88 88ooood8    88        88888888 88888888\n";
cout<<" 88        88    Y8.   .88 88.  .88 88  88  88 88.  .88 88   88   88.  .88    88.  .88 88.  ...    Y8.   .88    88       88\n";
cout<<" 88888888P dP     `88888'  `88888P8 dP  dP  dP 88Y8888' dP   dP   `88888P'    `88888P8 `88888P'     Y88888P'    dP       dP\n\n\n";

    cout<<endl<<"\t\t~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~     B I E N V E N I D O     ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n\n"<<endl;
    int opcion=0;

    do{
        cout<<endl<<"\t\t\t- - - - - - - - - - - - - - -     M E N U :     - - - - - - - - - - - - - - -"<<endl;
        cout<<endl<<"\t\t\t\t 0:    I N S T R U C C I O N E S    (Como jugar)\n";
        cout<<endl<<"\t\t\t\t 1:    I N T E G R A N T E S \n";
        cout<<endl<<"\t\t\t\t 2:    C O N S I D E R A C I O N E S\n";
        cout<<endl<<"\t\t\t\t 3:    J U G A R\n";
        cout<<endl<<"\t\t\t\t 4:    S A L I R\n";
        cout<<endl<<endl;

        do{
            cout<<"\t\tDigite la opcion deseada: ";
            cin>>opcion;
        }while(opcion<0 || opcion>4);

        switch(opcion){
            case 0:
            limpiarPantalla();
                cout<<endl<<"\t- - - - - - - - - - - - - - -     I N S T R U C C I O N E S :   (Como Jugar)     - - - - - - - - - - - - - - -\n"<<endl;

                cout<<endl<<"\tEl gambito de C++ es un juego de ajedrez basico desarrollado bajo el lenguaje de programacion C++\n\n";
                cout<<"\t\t-> Al iniciar, el programa siempre te dara a escoger dos opciones, el realizar un movimiento\n";
                cout<<"\t\t\t o rendirte y ceder la partida.\n";
                cout<<"\t\t-> Nuestro tablero se desplegara y manejara por medio de Columnas y Filas, tomando valores desde\n";
                cout<<"\t\t\t A a G y del 1 al 8 respectivamente.\n";
                cout<<"\t\t-> Al realizar un movimiento se debera indicar la casila de origen y posteriormente la\n";
                cout<<"\t\t\t casilla de destino.\n";
                cout<<"\t\t-> El formato en el cual se introducen cada casilla debe ser uno en especifico, indicando primero\n";
                cout<<"\t\t\t la Columna y despues la Fila. Por ejemplo: E2\n";
                cout<<"\t\t-> Las columnas siempre deberan introducirse con mayusculas para ser considero un valor valido.\n";
                cout<<"\t\t\t Ejemplo: F4 valido, f4 NO valido.\n";
                cout<<"\t\t-> Posteriormente el programa evaluara si el movimiento es valido dependiendo de la pieza\n";
                cout<<"\t\t\t seleccionada. Si es un movimiento invalido nos arrojara un mensaje y nos pedira\n";
                cout<<"\t\t\t realizar un movimiento de nuevo. En caso de ser valido, sera el turno del siguiente\n";
                cout<<"\t\t\t jugador para mover."<<endl;

                cout<<endl<<"\n\t\t~ ~ ~ ~ ~ ~ ~ ~ ~ ~     M O V I M I E N T O S    D E    C A D A    P I E Z A :     ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"<<endl;
                cout<<"\tPara los movimientos de cada pieza se siguen las reglas del Ajedrez:\n\n";
                cout<<"\t\t-> Rey: Puede moverse una casilla en cualquier direccion: horizontal, vertical o diagonal.\n\n";
                cout<<"\t\t-> Reina: Puede moverse en cualquier direccion y en cualquier numero de casillas, tanto en\n";
                cout<<"\t\t\thorizontal, vertical como en diagonal.\n\n";
                cout<<"\t\t-> Torre: Se mueve en linea recta, tanto vertical como horizontalmente, en cualquier numero\n";
                cout<<"\t\t\t de casillas.\n\n";
                cout<<"\t\t-> Alfil: Se mueve en linea recta, pero solo en diagonal, en cualquier numero de casillas.\n\n";
                cout<<"\t\t-> Caballo: Realiza un movimiento especial en forma de L. Puede moverse dos casillas en una\n";
                cout<<"\t\t\tdireccion (horizontal o vertical) y luego una casilla en direccion perpendicular\n\n";
                cout<<"\t\t-> Peon: En su primer movimiento, puede avanzar dos casillas hacia adelante.\n";
                cout<<"\t\t\tDespues de eso, solo pueden avanzar una casilla hacia adelante.\n\n"<<endl;
                break;
            case 1:
            limpiarPantalla();
                cout<<"\t- - - - - - - - - - - - - - - - - -     I N T E G R A N T E S :     - - - - - - - - - - - - - - - - - -"<<endl;

                cout<<endl<<"\t\t-> Ana Michel Conejo Sanchez\n\n";
                cout<<"\t\t-> David Zapien Zaavedra\n\n";
                cout<<"\t\t-> Paola Estefania Razo Perez\n\n";
                cout<<"\t\t-> Carlos Eduardo Lopez Gutierrez\n"<<endl;
                break;
            case 2:
            limpiarPantalla();
                cout<<"\t- - - - - - - - - - - - - - - -     C O N S I D E R A C I O N E S :     - - - - - - - - - - - - - - - -"<<endl;

                cout<<endl<<"\tAl ser un juego de Ajedrez BASICO, nuestro programa tiene algunas diferencias con los tipicos juegos\n";
                cout<<"\t\t que solemos encontrar en la red. Es por ello que en este apartado aclararemos algunas\n";
                cout<<"\t\t consideraciones necesarias antes de realizar una partida.\n\n";

                cout<<"\t\t-> No Hay Advertencia de ataque al Rey (JAQUE):\n";
                cout<<"\t\t\tEn nuestro programa NO se incluye una funcion especifica para advertir\n";
                cout<<"\t\t\tsobre un ataque al rey, es decir, un jaque. Esto se debe a que la deteccion\n";
                cout<<"\t\t\ty prevencion de un jaque implica una logica mas compleja que va mas alla\n";
                cout<<"\t\t\tde los movimientos individuales de las piezas.\n\n";
                cout<<"\t\t\tEn el codigo que hemos desarrollado se implementan las reglas y movimientos\n";
                cout<<"\t\t\tbasicos de cada pieza, permitiendo a los jugadores realizar tmovimientos\n";
                cout<<"\t\t\tlegales en el tablero. Sin embargo, la deteccion y prevencion de un jaque\n";
                cout<<"\t\t\timplica analizar los posibles movimientos futuros de las piezas, considerando\n";
                cout<<"\t\t\tlas interacciones entre ellas.Es por esta razon que para poder ganar la\n";
                cout<<"\t\t\tpartida se debe COMER al REY enemigo definitivamente.\n\n";

                cout<<"\t\t-> SI es posible hacer ENROQUE y CORONAR PEON:\n";
                cout<<"\t\t\tNuestro software permite hacer algunos de los Movimientos Especiales mas\n";
                cout<<"\t\t\tcomunes en el Ajedrez. Como lo son el Enroque entre un Rey y una Torre, o\n";
                cout<<"\t\t\tel Coronar Peon. Por su puesto para hacer este tipo de movimientos se\n";
                cout<<"\t\t\tevaluan las consideraciones necesarias que permiten a cada uno de estos.\n";
                cout<<"\t\t\tPara el Enroque se debe tener en cuenta lo previamente señalado sobre\n";
                cout<<"\t\t\tel JAQUE.\n\n";

                cout<<"\t\t-> NO es posible el PEON AL PASO:\n";
                cout<<"\t\t\tEste es otro movimiento especial no tan conocido que simplemente decidimos\n";
                cout<<"\t\t\tno incluir debido a su relevancia para los jugadores ocasionales de ajedrez.\n"<<endl;
                break;
            case 3:
                limpiarPantalla();
                iniciarPartida();
                break;
            case 4:
                exit(0);
                break;
        }

    }while(opcion!=4);
}
