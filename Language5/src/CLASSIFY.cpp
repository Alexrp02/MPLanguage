/*
 * Metodología de la Programación: Language5
 * Curso 2022/2023
 */

/** 
 * @file CLASSIFY.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * 
 * Created on 29 January 2023, 11:00
 */

#include <iostream>
#include "BigramCounter.h"

using namespace std;

/**
 * Shows help about the use of this program in the given output stream
 * @param outputStream The output stream where the help will be shown (for example,
 * cout, cerr, etc) 
 */
void showEnglishHelp(ostream& outputStream) {
    outputStream << "Error, run with the following parameters:" << endl;
    outputStream << "CLASSIFY <text.txt> <lang1.bgr> [<lang2.bgr> <lang3.bgr> ....]" << endl;
    outputStream << "          Obtains the identifier of the closest language to the input text file" << endl;
    outputStream << endl;
}

/**
 * This program print the language identifier of the closest language 
 * for an input text file (<text.txt>) among the set of provided models:
 * <lang1.bgr>, <lang2.bgr>, ...
 * 
 * Running example:
 * > CLASSIFY  <text.txt> <lang1.bgr> [<lang2.bgr> <lang3.bgr> ...]
 * @param argc The number of command line parameters
 * @param argv The vector of command line parameters (cstrings)
 * @return 0 If there is no error; a value > 0 if error
 */
int main(int argc, char *argv[]) {
    cout << "Ejecutando CLASSIFY" << endl;
    if (argc < 3) {
        showEnglishHelp(cerr);
        exit(1);
    }

    // Get the bigramCounter out of the first text
    BigramCounter bc;
    bc.calculateFrequencies(argv[1]);

    // Get the language to be classified of the bigramCounter
    Language compared = bc.toLanguage();
    compared.sort() ;
    cout << "Compared has " << compared.getSize() << " bigrams." << endl ;

    // Set the minimum distance to the first language given
    Language auxLang;
    auxLang.load(argv[2]);
    double minDistance = compared.getDistance(auxLang);
    cout << "First minDistance: " << minDistance << endl;
    compared.setLanguageId(auxLang.getLanguageId());

    // Iterate through all the files with languages and calculate distance, save the minimum distance and set the language id
    for (int i = 2; i < argc; i++) {
        // Load the language
        Language auxLang2;
        auxLang2.load(argv[i]);
        double distance = compared.getDistance(auxLang2);
        cout << i << " minDistance: " << distance << endl;
        if (distance < minDistance) {
            // Change the minimum distance
            minDistance = distance;
            // Change the languageID as the distance is less than the minimum
            compared.setLanguageId(auxLang2.getLanguageId());
        }
    }

    // Show the final decision of the language id
    cout << "Final decision: language " << compared.getLanguageId() << " with a distance of " << minDistance << endl;
}

