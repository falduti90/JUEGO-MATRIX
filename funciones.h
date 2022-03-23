#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

//Jugar
void cargarMatriz (int [] [6], int, int);
void mostrarMatriz (int [] [6], bool [] [6], int, int);
bool validacionOperacion (int [] [6], int, int, int, int, int, int, char);
int calcularPuntaje (int [] [6], int, int, int, int, int, int);
void borrarEspacios  (bool [] [6], int, int, int, int, int, int);
bool validacionEspacios (bool [][6],int, int, int, int, int, int);
bool validacionRango (int, int, int, int, int, int, int, int);
bool rango (int, int, int);
void mostrarInfo (char [], int, int, int);
//Menu
void mostrarMenu ();
//Extra estetico
void divCalculadora ();
void divMathrixGame ();
void divGameOver ();
//Estadisticas
void pasajeNombre (char nombrePuntajeMax[], char []);
void pasajePuntaje (int &puntajeMenu, int);


#endif // FUNCIONES_H_INCLUDED
