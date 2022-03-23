#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include "funciones.h"
#include "rlutil.h"

/*
================
SEGUNDO PARCIAL
================
-Materia: Laboratorio 1
-Categoría: Juego en consola (Mathrix Game)
-Profesores y Ayudante: Angel Simon, Bryan Lara, Soledad Arena.
-Integrantes del grupo: Avila, Falduti, Illanes
*/

using namespace std;
//      FUNCIONES PRINCIPALES.


void jugar (char nombrePuntajeMax [], int &puntajeMax);
void estadisticas (char [], int);
void creditos ();
void salir (char &rta);
void reglas ();


int main()
{

    setlocale(LC_ALL, "Spanish");
    int opcion;
    char rta = 'N';
    char nombrePuntajeMax [45];
    int puntajeMax = -1;

    srand(time(NULL));

    divMathrixGame();
    rlutil::setColor(rlutil::WHITE);
    cout << "Presiona cualquier tecla para ir al menu  ";
    rlutil::setColor(rlutil::LIGHTMAGENTA);
    rlutil::anykey();

    rlutil::setBackgroundColor(rlutil::LIGHTCYAN);
    rlutil::setColor(rlutil::LIGHTMAGENTA);

    while (rta == 'N')
    {
        rlutil::cls();
        mostrarMenu();
        cout << endl << "Ingrese el numero correspondiente a la opcion deseada: ";
        cin >> opcion;

        switch (opcion)
        {
        case 0:
            salir(rta);
            break;
        case 1:
            jugar(nombrePuntajeMax, puntajeMax);
            break;
        case 2:
            estadisticas(nombrePuntajeMax, puntajeMax);
            break;
        case 3:
            creditos();
            break;
        case 4:
            reglas();
            break;
        default:
            rlutil::setBackgroundColor(rlutil::GREY);
            rlutil::setColor(rlutil::RED);
            cout << endl << "                  =======================               " << endl;
            cout << "                           ERROR                        ";
            cout << endl << "                  =======================               ";
            cout << endl << "Opcion invalida, presione cualquier tecla para continuar";
            rlutil::anykey();
            rlutil::setBackgroundColor(rlutil::LIGHTCYAN);
            rlutil::setColor(rlutil::LIGHTMAGENTA);
            break;

        }




    }




    return 0;
}

// -------------------------------------------------------

void jugar (char nombrePuntajeMax [], int &puntajeMax)
{
    const int ope=4;
    char opFinalJuego = 'N';


    while (opFinalJuego == 'N')
    {


        const int x = 6, y = 6;
        int matrizJugar [x][y];
        //Matriz Sombra
        bool matrizSombra [x][y] = {};
        //Entrada datos usuarios
        int f1, c1, f2, c2, f3, c3, direccion;
        char operador;
        //Pilas
        int pilas = 3;
        int puntaje = 0;
        //Nombre
        char vnombre [45]; // 45 son las letras del nombre mas largo del mundo: Nominchuluunukhaanzayamunkherdeneenkhtuguldur ;)
        int cantRondas = 0;
        char calcFav [45];


        //CONSIGNA: Si se hace una resta y el resultado no es correcto únicamente por
        //el signo. Debe considerarse como correcto pero sumar la mitad de los puntos.



        rlutil::cls();
        rlutil::setBackgroundColor(rlutil::WHITE);
        rlutil::setColor(rlutil::BLUE);
        cout << "=======================" << endl;
        rlutil::setColor(rlutil::BROWN);
        cout << "       JUGAR           ";
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << endl << "=======================" << endl;
        rlutil::setBackgroundColor(rlutil::LIGHTCYAN);
        rlutil::setColor(rlutil::LIGHTMAGENTA);
        divCalculadora();

        gotoxy(30,8);
        cout << "Ingrese su nombre: ";
        gotoxy(49,8);
        cin.ignore();
        cin.getline(vnombre, 45);

        gotoxy(30,11);
        cout << "Ingrese su calculadora favorita: ";
        gotoxy(63,11);
        cin.getline(calcFav, 45);

        gotoxy(30,14);
        cout << "WOW, que coincidencia! La nuestra tambien es ";
        puts(calcFav);
        gotoxy(30,17);
        rlutil::setBackgroundColor(rlutil::CYAN);
        rlutil::setColor(rlutil::BLACK);
        cout << "Presione cualquier tecla para continuar";
        rlutil::setBackgroundColor(rlutil::LIGHTCYAN);
        rlutil::setColor(rlutil::LIGHTMAGENTA);
        gotoxy(75,17);
        rlutil::anykey();


        cargarMatriz(matrizJugar, x, y);

        while (pilas > 0)
        {
            rlutil::cls();
            rlutil::setBackgroundColor(rlutil::WHITE);
            rlutil::setColor(rlutil::BLUE);
            cout << "=======================" << endl;
            rlutil::setColor(rlutil::BROWN);
            cout << "       JUGAR           ";
            rlutil::setColor(rlutil::LIGHTCYAN);
            cout << endl << "=======================" << endl;
            rlutil::setBackgroundColor(rlutil::LIGHTCYAN);
            rlutil::setColor(rlutil::LIGHTMAGENTA);

            cantRondas ++;

            cout << endl;
            mostrarInfo (vnombre, pilas, cantRondas, puntaje);
            cout << endl;
            mostrarMatriz(matrizJugar,matrizSombra, x, y);
            cout << endl;

            cout << "Ingrese las coordenadas";
            cout << endl << "Fila: ";
            cin >> f1;
            f1 --;
            cout << "Columna: ";
            cin >> c1;
            c1 --;
            cout << endl << "Ingrese el operador: ";
            cin >> operador;





            while (operador != '+' && operador != '-' && operador != '*' && operador != '/' && operador != '%')
            {
                rlutil::setBackgroundColor(rlutil::GREY);
                rlutil::setColor(rlutil::RED);
                cout << "Ingreso invalido, vuelva a ingresar (operadores permitidos: '+' | '-' | '*' | '/' | '%' ): ";
                rlutil::setBackgroundColor(rlutil::LIGHTCYAN);
                rlutil::setColor(rlutil::LIGHTMAGENTA);
                cin >> operador;
            }
            cout << endl << "Ingrese direccion: ";
            cin >> direccion;
            while (direccion != 8 && direccion != 2 && direccion != 4 && direccion != 6)
            {
                rlutil::setBackgroundColor(rlutil::GREY);
                rlutil::setColor(rlutil::RED);
                cout << "Ingreso invalido, vuelva a ingresar (8 - Arriba | 2 - Abajo | 4 - Izquierda | 6 - Derecha): ";
                rlutil::setBackgroundColor(rlutil::LIGHTCYAN);
                rlutil::setColor(rlutil::LIGHTMAGENTA);
                cin >> direccion;
            }


            switch (direccion)
            {
            case 2:
                f2 = f1 + 1;
                f3 = f2 + 1;
                c2 = c3 = c1;
                break;
            case 4:
                c2 = c1 - 1;
                c3 = c2 - 1;
                f2 = f3 = f1;
                break;
            case 6:
                c2 = c1 + 1;
                c3 = c2 + 1;
                f2 = f3 = f1;
                break;
            case 8:
                f2 = f1 - 1;
                f3 = f2 - 1;
                c2 = c3 = c1;
                break;
            default:
                cout << "Opcion invalida";

            }

            if (validacionEspacios(matrizSombra, f1, c1, f2, c2, f3, c3) && validacionRango(f1, c1, f2, c2, f3, c3, x, y))
            {


                if (validacionOperacion (matrizJugar, f1, c1, f2, c2, f3, c3, operador))
                {
                    puntaje += calcularPuntaje(matrizJugar, f1, c1, f2, c2, f3, c3);
                    borrarEspacios (matrizSombra, f1, c1, f2, c2, f3, c3);

                }
                else
                {
                    if(operador == '-')
                    {
                        if((matrizJugar[f1][c1]-matrizJugar[f2][c2]==(-1)* matrizJugar [f3][c3]))
                        {
                            puntaje += calcularPuntaje(matrizJugar, f1, c1, f2, c2, f3, c3)/2;
                            borrarEspacios (matrizSombra, f1, c1, f2, c2, f3, c3);
                        }
                        else
                        {
                            pilas --;
                        }


                    }

                    else
                    {
                        pilas --;
                    }

                }

            }

            else
            {

                pilas --;
                cout << endl <<  "Pilas: " << pilas;

            }


        }
        rlutil::cls();
        divGameOver();
        cout<< vnombre;
        cout << endl << "Puntuacion final: " << puntaje<<endl;
        cout<< endl;

        cout << endl;
        cout<< endl;
        rlutil::setColor(rlutil::LIGHTMAGENTA);
        if (puntaje > puntajeMax)
        {
            pasajeNombre (nombrePuntajeMax,vnombre);
            pasajePuntaje (puntajeMax, puntaje);
        }

        cout << endl << "'N' - New Game |  'M' - Back to Menu ";
        cin >> opFinalJuego;
        while (opFinalJuego != 'N' && opFinalJuego != 'M')
        {

            rlutil::setBackgroundColor(rlutil::GREY);
            rlutil::setColor(rlutil::RED);
            cout << "Opcion invalida, vuelva a ingresar: ";
            rlutil::setBackgroundColor(rlutil::LIGHTCYAN);
            rlutil::setColor(rlutil::LIGHTMAGENTA);
            cin >> opFinalJuego;
        }


    }

}

// ------------------------------------------------------

void estadisticas (char nombrePmax[], int pMax)
{
    rlutil::cls();
    rlutil::setBackgroundColor(rlutil::WHITE);
    rlutil::setColor(rlutil::BLUE);
    cout << endl << "=======================" << endl;
    rlutil::setColor(rlutil::BROWN);
    cout << "     ESTADISTICAS      ";
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << endl << "=======================";
    rlutil::setBackgroundColor(rlutil::LIGHTCYAN);
    rlutil::setColor(rlutil::LIGHTMAGENTA);

    char volver = 'N';
    if (pMax == -1)
    {
        cout << endl << endl << "Aun no se cargaron datos, intente jugar una partida";
    }
    else
    {
        cout << endl << endl << "El mayor puntaje fue de " << pMax << " obtenido por ";
        puts(nombrePmax);
    }

    while (volver != 'Y')
    {
        cout << endl << "Want to go back? ('N'- No, 'Y'- Yes)" << endl;
        cin >> volver;
        while (volver != 'N' && volver != 'Y')
        {
            rlutil::setBackgroundColor(rlutil::GREY);
            rlutil::setColor(rlutil::RED);
            cout << "Ingreso incorrecta, vuelva a intentar: ";
            rlutil::setBackgroundColor(rlutil::LIGHTCYAN);
            rlutil::setColor(rlutil::LIGHTMAGENTA);
            cin  >> volver;
        }
    }
}

//-------------------------------------------------------

void creditos ()
{
    rlutil::cls();
    rlutil::setBackgroundColor(rlutil::WHITE);
    rlutil::setColor(rlutil::BLUE);
    cout << endl << "=======================" << endl;
    rlutil::setColor(rlutil::BROWN);
    cout << "      CREDITOS         ";
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << endl << "=======================";
    rlutil::setBackgroundColor(rlutil::LIGHTCYAN);
    rlutil::setColor(rlutil::BLACK);
    char volver = 'N';
    cout << endl;
    rlutil::setBackgroundColor(rlutil::RED);
    cout << endl << "           mateAtletas            ";
    rlutil::setBackgroundColor(rlutil::BROWN);
    cout << endl <<  "----------------------------------";
    rlutil::setBackgroundColor(rlutil::GREEN);
    cout << endl << "24464, Avila Rotela Catalina      ";
    rlutil::setBackgroundColor(rlutil::BLUE);
    cout << endl << "24495, Falduti Matias Nicolas     ";
    rlutil::setBackgroundColor(rlutil::MAGENTA);
    cout << endl << "24512, Illanes Saldivia Maria Jose" << endl;
    rlutil::setBackgroundColor(rlutil::LIGHTCYAN);
    rlutil::setColor(rlutil::LIGHTMAGENTA);
    while (volver != 'Y')
    {
        cout << endl << "Want to go back? ('N'- No, 'Y'- Yes)" << endl;
        cin >> volver;
        while (volver != 'N' && volver != 'Y')
        {
            rlutil::setBackgroundColor(rlutil::GREY);
            rlutil::setColor(rlutil::RED);
            cout << "Ingreso incorrecta, vuelva a intentar: ";
            rlutil::setBackgroundColor(rlutil::LIGHTCYAN);
            rlutil::setColor(rlutil::LIGHTMAGENTA);
            cin  >> volver;
        }
    }
}

//-------------------------------------------------------

void salir (char &rta)
{
    rlutil::cls();
    rlutil::setBackgroundColor(rlutil::WHITE);
    rlutil::setColor(rlutil::BLUE);
    cout << endl << "=======================" << endl;
    rlutil::setColor(rlutil::BROWN);
    cout << "         SALIR         ";
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << endl << "=======================";
    rlutil::setBackgroundColor(rlutil::LIGHTCYAN);
    rlutil::setColor(rlutil::LIGHTMAGENTA);

    cout << endl << endl << "Exit? ('N'- No, 'Y'- Yes)";
    cout << endl;
    cin >> rta;

    while (rta != 'N' && rta != 'Y')
    {
        rlutil::setBackgroundColor(rlutil::GREY);
        rlutil::setColor(rlutil::RED);
        cout << "Ingreso incorrecta, vuelva a intentar: ";
        rlutil::setBackgroundColor(rlutil::LIGHTCYAN);
        rlutil::setColor(rlutil::LIGHTMAGENTA);
        cin  >> rta;
    }
}

//-------------------------------------------------------

void reglas ()
{

    char volver = 'N';

    rlutil::cls();
    rlutil::setBackgroundColor(rlutil::WHITE);
    rlutil::setColor(rlutil::BLUE);
    cout << endl << "=======================" << endl;
    rlutil::setColor(rlutil::BROWN);
    cout << "     REGLAS            ";
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << endl << "=======================";
    rlutil::setBackgroundColor(rlutil::LIGHTCYAN);
    rlutil::setColor(rlutil::LIGHTMAGENTA);


    cout << endl << endl << "Ingrese al siguiente link para acceder a las reglas del juego: ";
    cout << endl << "https://tinyurl.com/instruccionesmathrixgame";

    cout << endl;

    while (volver != 'Y')
    {
        cout << endl << "Want to go back? ('N'- No, 'Y'- Yes)" << endl;
        cin >> volver;

        rlutil::setBackgroundColor(rlutil::GREY);
        rlutil::setColor(rlutil::RED);

        rlutil::setBackgroundColor(rlutil::LIGHTCYAN);
        rlutil::setColor(rlutil::LIGHTMAGENTA);

        while (volver != 'N' && volver != 'Y')
        {
            rlutil::setBackgroundColor(rlutil::GREY);
            rlutil::setColor(rlutil::RED);
            cout << "Ingreso incorrecta, vuelva a intentar: ";
            rlutil::setBackgroundColor(rlutil::LIGHTCYAN);
            rlutil::setColor(rlutil::LIGHTMAGENTA);
            cin  >> volver;
        }
    }




}
