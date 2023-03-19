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
#include "BigramFreq.h"
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
    int tam ; 
    cin >> tam ;
    BigramFreq array[tam] ;
    
    for (int i=0 ; i<tam ; i++) {
        string text ;
        int freq ;
        BigramFreq b ;
        cin >> text ;
        cin >> freq ;
        b.setBigram(Bigram(text)) ;
        b.setFrequency(freq) ;
        array[i] = b ;
    }
    
    cout << tam << endl ;
    for (int i=0 ; i<tam ; i++) {
        cout << array[i].getBigram().toString() << " " << array[i].getFrequency() << endl ;
    }
}

