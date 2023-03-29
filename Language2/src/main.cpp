/*
 * Metodología de la Programación: Language0
 * Curso 2022/2023
 */

/* 
 * File:   main.cpp
 * @author estudiante1: Ramos Peña, Alejandro
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
    int tam ; 
    BigramFreq array[DIM] ;
    readArrayBigramFreq(array, DIM, tam ) ;
    
    printArrayBigramFreq(array, tam) ;
    
    sortArrayBigramFreq(array, tam) ;
    
    toUpperArrayBigramFreq(array, tam) ;
    
    printArrayBigramFreq(array, tam) ;
}

