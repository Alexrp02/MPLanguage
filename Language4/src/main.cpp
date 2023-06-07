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
#include <cstring>
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

/**
 * Shows help about the use of this program in the given output stream
 * @param outputStream The output stream where the help will be shown (for example,
 * cout, cerr, etc) 
 */
void showEnglishHelp(ostream& outputStream) {
    outputStream << "Error, run with the following parameters:" << endl;
    outputStream << "language4 [-t min|max] <file1.bgr> <file2.bgr> [ ... <filen.bgr>]" << endl;
}

void checkParameters(int &offset, bool &min, int &minimum, int argc, char *argv[]) {

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            if (argv[i][1] == 't') {
                if (!strcmp(argv[i + 1], "min")) {
                    min = true;
                    offset++;
                } else if (!strcmp(argv[i + 1], "max")) {
                    min = false;
                    offset++;
                } else {
                    showEnglishHelp(cerr);
                    exit(1);
                }
            } else if (argv[i][1] == 'q') {
                minimum = atoi(argv[i + 1]);
                offset++;
            }
            offset++;
        }
    }
}

bool checkFirstParam(int argc, char *argv[]) {
    // If no optional parameter, it is ok.
    if (argc < 3)
        return false;
    if (argv[1][0] != '-')
        return true;

    // If the optional parameter is -t, the next has to be either min or max.
    if (strcmp(argv[1], "-t") == 0)
        if (strcmp(argv[2], "min") == 0 || strcmp(argv[2], "max") == 0)
            if (argc >= 5)
                return true;
    return false;
}

int main(int argc, char* argv[]) {
    //Give error if the number of args is not enough
    if (argc < 3) {
        showEnglishHelp(cerr);
        exit(1);
    }

    int tam = argc - 2; // Vector size
    int offset = 1; // first language index
    bool min = true; // Variable to check or not for the min
    int minimum = 0 ;
    checkParameters(offset, min, minimum, argc, argv);
    
    // Initialize language vector
    Language *vector = new Language[tam];

    double res = 0;
    int pos = 0;
    int nameIndex = offset + 1;
    int languageIndex = 0;

    Language comparado;
    comparado.load(argv[offset++]); // Load the first language

    // Assign the initial res to the comparation of the first 2.
    vector[pos++].load(argv[offset]);
    res = comparado.getDistance(vector[0]);
    cout << "Distance to " << argv[offset++] << ": " << res << endl;

    // Load every other language (if present)
    for (int i=offset; i < argc; i++) {
        // Load next language and calculate distance
        vector[pos].load(argv[i]);
        double distance = comparado.getDistance(vector[pos]);
        cout << "Distance to " << argv[i] << ": " << distance << endl;

        // Check if we are looking for the maximum or the minimum and update variable
        if (min) {
            if (distance < res) {
                nameIndex = i;
                res = distance;
                languageIndex = pos;
            }
        } else {
            if (distance > res) {
                nameIndex = i;
                res = distance;
                languageIndex = pos;
            }
        }
        pos++;
    }

    // Show the result
    if (min) {
        cout << "Nearest language file: " << argv[nameIndex] << endl << "Identifier of the nearest language: " << vector[languageIndex].getLanguageId() << endl;
    } else {
        cout << "Farthest language file: " << argv[nameIndex] << endl << "Identifier of the farthest language: " << vector[languageIndex].getLanguageId() << endl;
    }
    
    Language filtered = comparado.filtrarFreq(minimum);
    
    cout << "Lenguaje filtrado: " << endl << filtered.toString() << endl ;

    // Deassign memory to the vector
    delete[] vector;
    return 0;
}