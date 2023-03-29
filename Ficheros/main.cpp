/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: alexrp
 *
 * Created on 29 de marzo de 2023, 10:16
 */

#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //Error si el número de argumentos es menor de 2 (en la condición es 3 pues se cuenta como argumento la llamada a la aplicación).
    if (argc < 3) {
        cerr << "El número de argumentos mínimos son 2, con el siguiente formato: ficheros <archivo de entrada> <archivo de salida>" << endl ;
        exit(1) ;
    }
    
    //Mostramos todos los argumentos del vector de algumentos
    cout << "Los argumentos dados son: " << endl ;
    for (int i=1 ; i<argc ; i++) {
        cout << argv[i] << endl ;
    }
    
    return 0;
}

