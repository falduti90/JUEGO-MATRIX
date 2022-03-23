#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>
#include <string.h>
#include "funciones.h"
#include "rlutil.h"

// -------------------------JUGAR---------------------------------

void cargarMatriz (int matriz [] [6],int xtam, int ytam)
{
    for (int x = 0; x<xtam; x++)
    {
        for (int i = 0; i<ytam; i++)
        {
            matriz [x][i] = rand()%10;
        }
    }

}

void mostrarMatriz (int matriz [] [6], bool matrizb [][6], int xtam, int ytam)
{

    cout << endl << " ___ ___ ___ ___ ___ ___";
    rlutil::setBackgroundColor(rlutil::GREY);
    for (int x = 0; x<xtam; x++)
    {
        cout << endl;
        cout << "|";
        for (int i = 0; i<ytam; i++)
        {
            if (!matrizb [x][i])
            {
                cout << " " << matriz [x][i] << " |";
            }
            else
            {
                rlutil::setColor(rlutil::RED);
                cout << " ";
                rlutil::setColor(rlutil::GREEN);
                cout << "X";
                rlutil::setColor(rlutil::LIGHTMAGENTA);
                cout << " |";
            }


        }
        cout << endl << "|___|___|___|___|___|___|" ;
    }
    cout << endl;

    rlutil::setBackgroundColor(rlutil::LIGHTCYAN);

}

bool validacionOperacion (int matriz [][6],int f1, int c1, int f2, int c2, int f3, int c3, char op)
{

    switch(op)
    {
    case '+':


        if (matriz [f1] [c1] + matriz [f2] [c2] == matriz [f3] [c3])
        {

            //cout << endl << "A: " matriz [f1][c1] << "B: " << matriz [f2] [c2] << "C: " << matriz [f3][c3];
            return true;
        }
        else
        {
            return false;
        }
        break;
    case '-':
        if (matriz [f1] [c1] - matriz [f2] [c2] == matriz [f3] [c3])
        {
            //cout << endl << "A: " matriz [f1][c1] << "B: " << matriz [f2] [c2] << "C: " << matriz [f3][c3];
            return true;
        }
        else
        {
            return false;
        }
        break;
    case '*':
        if (matriz [f1] [c1] * matriz [f2] [c2] == matriz [f3] [c3])
        {
            //cout << endl << "A: " matriz [f1][c1] << "B: " << matriz [f2] [c2] << "C: " << matriz [f3][c3];
            return true;
        }
        else
        {
            return false;
        }
        break;
    case '/':
        if (matriz [f2] [c2]==0 )
        {
            return false;
        }
        if (matriz [f1] [c1] / matriz [f2] [c2] == matriz [f3] [c3])
        {
            //cout << endl << "A: " matriz [f1][c1] << "B: " << matriz [f2] [c2] << "C: " << matriz [f3][c3];
            return true;
        }
        else
        {
            return false;
        }
        break;
    case '%':
        if (matriz [f1] [c1] % matriz [f2] [c2] == matriz [f3] [c3])
        {
            //cout << endl << "A: " matriz [f1][c1] << "B: " << matriz [f2] [c2] << "C: " << matriz [f3][c3];
            return true;
        }
        else
        {
            return false;
        }
        break;
    default:
        cout << "Default";
        break;
    }




}

int calcularPuntaje (int matriz [] [6], int f1, int c1, int f2, int c2, int f3, int c3)
{
    int acu;
    acu = matriz [f1][c1] + matriz [f2][c2] + matriz [f3][c3];
    return acu;

}

void borrarEspacios  (bool matriz [] [6], int f1, int c1, int f2, int c2, int f3, int c3)
{
    matriz [f1][c1] = matriz [f2][c2] = matriz [f3] [c3] = true;

}

bool validacionEspacios (bool matrizb [][6], int f1, int c1, int f2, int c2, int f3, int c3)
{

    if (matrizb [f1][c1] || matrizb [f2][c2] || matrizb[f3][c3])
    {
        return false;
    }
    else
    {
        return true;
    }

}

bool rango (int valor, int maxi)
{
    if (valor >= 0 && valor<= maxi-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool validacionRango (int f1, int c1, int f2, int c2, int f3, int c3, int xmax, int ymax)
{
    if ( rango (f1, xmax) && rango (f2, xmax) && rango (f3, xmax))
    {
        if (rango (c1, ymax) && rango (c2, ymax) && rango (c3, ymax))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }

}

void mostrarInfo (char nombre [], int pilas, int ronda, int puntaje)
{
    cout << endl << "-Nombre: ";
    puts (nombre);
    cout << "-Cantidad de pilas: " << pilas;
    cout << endl << "-Ronda numero " << ronda;
    cout << endl << "-Puntaje: " << puntaje;
}



// -------------------------MENU---------------------------------

void mostrarMenu ()
{
    cout << endl << "MATHRIX";
    cout << endl << "------------------------------";
    cout << endl << "1 - JUGAR";
    cout << endl << "2 - ESTADISTICAS";
    cout << endl << "3 - CREDITOS";
    cout << endl << "4 - REGLAS";
    cout << endl << "------------------------------";
    cout << endl << "0 - SALIR" << endl;
}

//-----------------------EXTRA: Dibujos-----------------------------

void divCalculadora ()
{
    rlutil::setBackgroundColor(rlutil::GREY);
    rlutil::setColor(rlutil::BLACK);
    cout << endl << endl << " _____________________ ";
    cout << endl << "|  _________________  |";
    cout << endl << "| | JO           0. | |";
    cout << endl << "| |_________________| |";
    cout << endl << "|  ___ ___ ___   ___  |";
    cout << endl << "| | 7 | 8 | 9 | | + | |";
    cout << endl << "| |___|___|___| |___| |";
    cout << endl << "| | 4 | 5 | 6 | | - | |";
    cout << endl << "| |___|___|___| |___| |";
    cout << endl << "| | 1 | 2 | 3 | | x | |";
    cout << endl << "| |___|___|___| |___| |";
    cout << endl << "| | . | 0 | = | | / | |";
    cout << endl << "| |___|___|___| |___| |";
    cout << endl << "|_____________________|";
    rlutil::setBackgroundColor(rlutil::LIGHTCYAN);
    rlutil::setColor(rlutil::LIGHTMAGENTA);

}
void divMathrixGame ()
{
 rlutil::setColor(rlutil::RED);
    cout <<" __^__                                                                            __^__" << endl;
    rlutil::setColor(rlutil::BROWN);
    cout << "( ___ )--------------------------------------------------------------------------( ___ )" << endl;
    rlutil::setColor(rlutil::GREEN);
    cout << " | / |      \\  |    \\ __ __| |  |  _ \\ _ _| \\ \\  /     __|    \\     \\  |  __|     | /\ |" << endl;
    rlutil::setColor(rlutil::BLUE);
    cout << " | / |     |\\/ |   _ \\   |   __ |    /   |   >  <     (_ |   _ \\   |\\/ |  _|      | /\ |" << endl;
    rlutil::setColor(rlutil::CYAN);
    cout << " |___|    _|  _| _/  _\\ _|  _| _| _|_\\ ___|  _/\\_\\   \\___| _/  _\\ _|  _| ___|     |___|" << endl;
    rlutil::setColor(rlutil::MAGENTA);
    cout << "(_____)--------------------------------------------------------------------------(_____)" << endl;
    cout << endl << endl << endl;
    rlutil::setColor(rlutil::WHITE);

}
void divGameOver ()
{

    rlutil::setBackgroundColor(rlutil::CYAN);
    rlutil::setColor(rlutil::BLACK);
    cout << "_____________________________________________________________________" << endl;
    rlutil::setColor(rlutil::BLACK);
    cout << "                                                                     " << endl;
    cout << "   ___|     \\      \\  |  ____|           _ \\ \\ \\     /  ____|   _ \\  " << endl;
    rlutil::setColor(rlutil::DARKGREY);
    cout << "  |        _ \\    |\\/ |  __|            |   | \\ \\   /   __|    |   | " << endl;
    rlutil::setColor(rlutil::DARKGREY);
    cout << "  |   |   ___ \\   |   |  |              |   |  \\ \\ /    |      __ <  " << endl;
    rlutil::setColor(rlutil::GREY);
    cout << " \\____| _/    _\\ _|  _| _____|         \\___/    \\_/    _____| _| \\_\\ " << endl;
    rlutil::setColor(rlutil::GREY);
    cout << "                                                                     " << endl;
    cout << "_____________________________________________________________________" << endl;
    cout << "                                                                     " << endl;
    rlutil::setColor(rlutil::BLUE);
    rlutil::setBackgroundColor(rlutil::LIGHTCYAN);


}

// -------------------------ESTADISTICAS---------------------------------

void pasajeNombre (char nombreMenu [],char nombreJugar [])
{
    strcpy(nombreMenu,nombreJugar);
}
void pasajePuntaje (int &puntajeMenu, int puntajeJugar)
{
    puntajeMenu = puntajeJugar;
}
