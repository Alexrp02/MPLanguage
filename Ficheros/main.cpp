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
        cerr << "El número de argumentos mínimos son 2, con el siguiente formato: ficheros <archivo de entrada> <archivo de salida>" << endl;
        exit(1);
    }

    //Mostramos los nombres de los ficheros dados como argumentos
    cout << "Los ficheros de entrada son: " << endl;
    for (int i = 1; i < argc - 1; i++) {
        cout << argv[i] << endl;
    }

    cout << "El fichero de salida es: " << endl;
    cout << argv[argc - 1] << endl;

    //Definimos stream de salida y abrimos el fichero de salida.
    ofstream salida;
    salida.open(argv[argc - 1]);


    //Creamos el stream para las entradas
    ifstream entrada;
    int nElements;
    //Gestionamos los ficheros de entrada con un bucle for
    for (int i = 1; i < argc - 1; i++) {

        //Vamos abriendo los ficheros de entrada de uno en uno
        entrada.open(argv[i]);

        //Comprobamos si el fichero ha sido abierto correctamente, si no, se enviará un mensaje de error y finalizaremos el programa
        //con un código de estado 1.
        if (!entrada) {
            cerr << "El fichero " << argv[i] << " no existe o no se ha podido abrir correctamente";
            exit(1);
        }

        //Tomamos el numero de elementos para poder iterar sobre el fichero
        entrada >> nElements;
        cout << "El numero de elementos es " << nElements << endl;
        salida << nElements << endl;

        //Iteramos sobre los elementos del fichero, metiendo los datos en el fichero de salida.
        for (int j = 0; j < nElements; j++) {
            string texto;
            int freq;
            entrada >> texto >> freq;
            salida << texto << " " << freq << endl;
        }
        salida << endl;

        //Cerramos el fichero de entrada
        entrada.close();
    }

    //Cerramos el fichero de salida
    salida.close();
    return 0;
}

