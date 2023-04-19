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
#include "Language.h"
#include "ArrayBigramFreqFunctions.h"
using namespace std;

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
const int DIM = 500;


// Funtion to check if the first argument is okay

bool checkFirstParam(int argc, char *argv[]) {
    // If no optional parameter, it is ok.
    if (argv[1][0] != '-')
        return true;
    // If the optional parameter is -t, the next has to be either min or max.
    if (strcmp(argv[1], "-t") == 0)
        if (strcmp(argv[2], "min")==0 || strcmp(argv[2], "max")==0)
            if(argc >= 5)
                return true;
        return false ;
}

int main(int argc, char* argv[]) {
    //Give error if the number of args is not enough
    if (argc < 3 || !checkFirstParam(argc, argv)) {
        cout << "Error, run with the following parameters:";
        cout << endl;
        cout << "language3 [-t min|max] <file1.bgr> <file2.bgr> [ ... <filen.bgr>]" << endl;
        exit(1);
    }


}