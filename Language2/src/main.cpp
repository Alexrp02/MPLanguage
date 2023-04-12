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

int main(int argc, char* argv[]) {
    cout << argc << endl ;
    //Give error if the number of args is not enough
    if (argc == 1) {
        cout << "Error: run the programa with the following parameters: " ;
        cout << endl ;
        cout << "language2 <file1.bgr> [<file2.bgr> ... <filen.bgr>] <outputFile.bgr>" << endl ;
    }

    //Create an array of Languages to store the laguages from the files
    Language languageArray[argc - 2];
    cout << "Array created." << endl ;

    //Iterate and read every language
    for (int i = 0; i < argc - 2; i++) {
        languageArray[i] = Language();
        languageArray[i].load(argv[i + 1]);
    }
    cout << "Array iterated and loaded." << endl ; 

    //Join all the languages (only if they are of the same languageID of the first language)
    Language languageJoin = languageArray[0];
    
    for (int i = 1; i < argc - 2; i++) {
        //If same languageId then join
        if (languageArray[i].getLanguageId().compare(languageJoin.getLanguageId()) == 0)
            languageJoin.join(languageArray[i]);
    }
    cout << "Joined all the languages." << endl ;

    //Sort the final language
    languageJoin.sort() ;
    cout << "Final language sorted." << endl ;
    
    //Save the join of the languages to the file
    languageJoin.save(argv[argc - 1]);
    cout << "Finished the join of " << argc-2 << " languages." << endl ; 
}

