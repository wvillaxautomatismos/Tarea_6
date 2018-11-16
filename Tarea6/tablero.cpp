#include "tablero.h"
#include <iostream>
using namespace std;

Tablero::Tablero()      //Constructor por defecto
{
        for(int i=0,j= 0; j < 3;i++){       //Inicia la matriz del tablero vacio
            matriz[j][i]=' ';
            if(i==2){
                j++;
                i=-1;}
        }
        jugador_act = 'X';              //Inicia con el jugador X por defecto
        ganador = ' ';                  //Inicia la variable de ganador vacia
}

void Tablero::solicitar_jugada()        //Funcion miembro para solicitar las jugadas del jugador
{
    for(int i=0;i<2;i++){               //Rutina para separa los numeros enteros de los caracteres de separacion
    cin >> coordenada[i];               //Se captura los numeros
    cin.ignore(1);                      //Se ignora los caracteres
    }
}


bool Tablero::validar_jugada()          //Funcion miembro para validar jugadas, se excliyen las que no contienen las coordenas correctas
{                                       //y aquellas que usan una coordenada ya usada
    if((coordenada[0]>=0 and coordenada[0]<=2)  //Valida si la primera coordena esta entre 0 y 2
        and (coordenada[1]>=0 and coordenada[1]<=2)   //Valida si la segunda coordenada esta entre 0 y 2
        and (matriz[coordenada[0]][coordenada[1]] == ' '))    //Valida si la coordena ingresada no esta en uso
       return true;                     //Retorna verdadero si la jugada es admitida
    else

        return false;                   //Retorna falso si la jugada es errada


}

void Tablero::actualizar_tablero()                  //Funcion miembro para actualizar el estado del tablero y administrar los resultados
{                                                   //de la jugada
    matriz [coordenada[0]][coordenada[1]] = jugador_act;        //Ingresa el caracter del jugador a la coordenada indicada por el jugador
    ganador = declaracion_ganador();                            //Valida si ha habido un ganador
    if(ganador == ' ')                                          //Si no hubo ganador cede el turno al sotro jugador
        jugador_act = turno();                                  //Habilita al otro jugador
    imprimir_tablero();                                         //Imprime el siguiente tablero con la ultima jugada
}
char Tablero::declaracion_ganador(){                //Funcion miembro que retorna el caracter del ganador o vacio ci no lo hay

    return check_tablero();
}

char Tablero::check_tablero()                       //Funcion miembro que analiza el tablero y determina si hay o no un ganadaor
{                                                   //Retorna el caracter del ganador o vacio si no lo hay.
    int contador(0);
    for(int j=0; j<3;j++){                          //Bucle para evaluar las filas en busca de tres coincidencias del ultimo jugador
        contador=0;
        for(int i=0;i<3;i++){                       //Si encuentra una coincidencia adiciona al contador, si suma tres se asume un ganador
            if(matriz[j][i] == jugador_act)         //En cada fila reinica el contador
                contador++;
            else
                contador=0;
        }
        if (contador == 3)                      //Si el contador es igual a tres sale del bucle
            break;
}
    if(contador == 3)
        return jugador_act;                         //Si hay ganador Retorna con el caracter del ganador


    for(int j=0; j<3;j++){                          //Bucle para evaluar las columnas trabaja igual qel anterior
        contador=0;
          for(int i=0;i<3;i++){
                if(matriz[i][j] == jugador_act)
                    contador++;
                else
                    contador=0;

   }
          if (contador == 3)                      //Si el contador es igual a tres sale del bucle
              break;
}
     if(contador == 3)
        return jugador_act;

    contador = 0;
    for(int i=0; i<3;i++){                  //Bucle para evaluar una diagonal en busca de tres councidencias
    if(matriz[i][i] == jugador_act)
        contador++;
   }
    if(contador == 3)
        return jugador_act;

    contador = 0;
    for(int i=0,j=2; i<3;i++){              //Bucle para evaluar la otra diagonal en busca de coincidencias
    if(matriz[i][j] == jugador_act)
        contador++;
    j--;
}
    if(contador == 3)
        return jugador_act;
    return ' ';                             //Si no hay ganador retorna vacio
}
char Tablero::turno()                       //Funcion Miembro para la administracion del tirno de juego
{
    if(jugador_act == 'X')                  //Evalua cual es el jugador actual y retorna el caracter del siguiente
        return  'O';
    return 'X';
}

void Tablero::imprimir_tablero(){               //Funcion Miembro para impresion a consola del tablero
  system("CLS");                               //Borra el contenido de la consola
    if(ganador != ' ')                          //Determina si hay un ganador
        cout << "Felicidades '" << jugador_act << "' has ganado " <<  endl;
    else
        cout << " Siguiente turno " << jugador_act << endl << endl;         //Impresion del tablero y jugadas
    cout << "\t     0     1     2" << endl;
    cout <<  "\t  |-----|-----|-----|" << endl;
    for(int i=0; i<3;i++){
        cout << "\t" << i <<" |  " << matriz[i][0] << "  |  " << matriz[i][1] << "  |  " << matriz[i][2] << "  |" << endl;
        cout << "\t  |-----|-----|-----|" << endl;

}

}
