/*
 * Metodología de la Programación: Language0
 * Curso 2022/2023
 */

/* 
 * File:   main.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 *
 * Created on 2 de febrero de 2023, 12:23
 */
#include <string>
#include <iostream>
#include <stdio.h> 
#include "Bigram.h"
using namespace std ;

/**
 * This program reads a text (without spaces) with a undefined number of 
 * characters and a text with two characters (bigram). It finds the bigrams 
 * contained in the first text, storing them in an array of Bigram. 
 * After that, the bigrams of the array are shown in the standard output. 
 * Then it converts to uppercase the bigrams in the array that are equals to the 
 * bigram of the second text. Finally the bigrams of the array are shown again 
 * in the standard output. 
 * Running example:
 * > language0 < data/SimpleText.txt
 */
int main(int argc, char* argv[]) {
    // This string contains the list of characters that are considered as
    // valid within a word. The rest of characters are considered as
    // separators
    const std::string validCharacters = "abcdefghijklmnopqrstuvwxyz\xE0\xE1\xE2\xE3\xE4\xE5\xE6\xE7\xE8\xE9\xEA\xEB\xEC\xED\xEE\xEF\xF0\xF1\xF2\xF3\xF4\xF5\xF6\xF8\xF9\xFA\xFB\xFC\xFD\xFE\xFF";
    const int TAM = 100 ;
    
    // Read a text
    string texto = "" ;
    cin >> texto ;
    cout << " ----- INPUT TEXT -----" << endl ;
    cout << texto << endl ;
    
    // Read a bigram (tex with two characters)
    string string_input = "" ;
    cin >> string_input ;
    Bigram bigram_input = Bigram(string_input) ;
    cout << " ----- INPUT BIGRAM FOR CONVERSION ----- " << endl ;
    cout << bigram_input.toString() << endl ;
    
    // Find the bigrams in text and put them in an array of Bigrams
    int util = 0 ;
    Bigram array[TAM] ;
    
    for (int i=0; i<texto.size()-1 ; i++) {
        char caracter1, caracter2 ;
        Bigram nuevo ;
        if(isValidCharacter(tolower(texto.at(i)), validCharacters)){
            caracter1 = tolower(texto.at(i)) ;
                if (isValidCharacter(tolower(texto.at(i+1)), validCharacters)){
                    caracter2 = tolower(texto.at(i+1)) ;
                    nuevo = Bigram(caracter1, caracter2) ;
                    array[util++] = nuevo ;
                }
            }
        }
    
    // Show the bigrams stored in the array
    cout << " ----- BIGRAMS BEFORE CONVERSION ----- " << endl;
    cout << "LENGTH=" << util << endl ;
    for (int i=0 ; i<util ; i++) {
        cout << array[i].toString() << endl ;
    }
    
    // Convert to uppercase the bigrams in the array that are equals to input bigram
    for (int i=0 ; i<util ; i++){
        if(array[i].toString() == bigram_input.toString()) {
            toUpper(array[i]) ;
        }
    }
    
    // Show again the bigrams stored in the array
    cout << " ----- BIGRAMS AFTER CONVERSION ----- " << endl;
    cout << "LENGTH=" << util << endl ;
    for (int i=0 ; i<util ; i++) {
        cout << array[i].toString() << endl ;
    }
}

