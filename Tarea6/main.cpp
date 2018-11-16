#include <iostream>
#include "tablero.h"
using namespace std;

int main()
{
    cout << "Tic-Tac-Toe (Triqui)" << endl << endl;
    cout << "Bienvenidos!. Juegen al tradicional Tic-Tac-Toe (Triqui)," << endl
         << "Realiza tripletas Horizontales, Verticales o Diagonales" << endl
         << "El jugador 1 estara identificado con la 'ficha' 'X', y el jugador 2 con la 'ficha' 'O'" << endl
         << "Ingresa tu jugada usando duplas de coordenadas 'Fila,Columna' asi: {0,0 - 0,1 - 0,2 - 1,0...} y finaliza pulsando Enter" << endl
         << "Ganara aquel que logre ubicar su 'ficha' en tripletas continuas." << endl
         << "Si tras llenar el tablero nadie a logrado conseguir una tripleta, se declarara un empate" << endl << endl;

    cout << "Pulse Enter pera Iniciar...";
    getchar();


    Tablero nuevo_juego;            //Instancia de la clase Tablero con el constructor por defecto
    nuevo_juego.imprimir_tablero();         //se ejecuta el metodo imprimir tablero muestra tablero vacio y asigna el primer turno

   for(int i=0; i<9;i++){           //Bucle para 9 jugadas, si despuest de estas 9 no hay ganador se declara empate
       bool ok(false);
      while (ok==false) {           //Bucle while para soliciatar jugada, solo es posible salir si se hace una jugada correcta
          cout << "Ingresa tu jugada" << endl
               << "'Fila' , 'Colunma'" << endl;
          nuevo_juego.solicitar_jugada();
           ok = nuevo_juego.validar_jugada();
           if(ok==false)
               cout << "Jugada invalida, Intenta de nuevo" << endl;
      }
      nuevo_juego.actualizar_tablero();         //Tras obtener una jugada exitosa se actualiza el tablero y se desencadena el analisis de la jugada
        if(nuevo_juego.getganador() != ' ')     //Se recupera el estado del ganador, si el valor es vacio se continua de lo contrio sale y declara el ganador
            break;
        if(i == 8)
            cout << "Se declara un empate, gracias por jugar" << endl;
   }

    }



