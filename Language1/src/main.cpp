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
#include "ArrayBigramFreqFunctions.h"
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
const int DIM = 500 ;

int main(int argc, char* argv[]) {
    int tam=0 ; 
    
    //Declaración del array
    BigramFreq array[DIM] ;
    
    //Creamos bf1
    BigramFreq bf1;
    bf1.setBigram(Bigram('a','a')) ;
    bf1.setFrequency(10) ;
    
    //Creamos bf2
    BigramFreq bf2;
    bf2.setBigram(Bigram('B','B')) ;
    bf2.setFrequency(10) ;
    
    //Convertimos en mayusculas
    Bigram aux = bf1.getBigram() ;
    aux.toUpper() ;
    bf1.setBigram(aux) ;
    
    array[0] = bf1 ;
    tam++ ;
    array[1] = bf2 ;
    tam++ ;
    
    sortArrayBigramFreq(array, tam) ; 
    
    printArrayBigramFreq(array, tam) ;
    
//    readArrayBigramFreq(array, DIM, tam ) ;
//    
//    printArrayBigramFreq(array, tam) ;
//    
//    sortArrayBigramFreq(array, tam) ;
//    
//    toUpperArrayBigramFreq(array, tam) ;
//    
//    printArrayBigramFreq(array, tam) ;
}

