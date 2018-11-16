#ifndef TABLERO_H
#define TABLERO_H


class Tablero
{
private:
    char matriz[3][3];
    char jugador_act;
    char ganador;
    int coordenada[2];

public:
    Tablero();
    void solicitar_jugada();
    bool validar_jugada();
    void actualizar_tablero();
    char check_tablero();
    char declaracion_ganador();
    void imprimir_tablero();
    char turno();
    char getganador(){
        return ganador;
    }
};

#endif // TABLERO_H
