/*
 * Metodología de la Programación: Language5
 * Curso 2022/2023
 */

/** 
 * @file LEARN.cpp
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
    outputStream << "LEARN [-t|-b] [-l languageId] [-o outputFilename] <text1.txt> [<text2.txt> <text3.txt> .... ]" << endl;
    outputStream << "           learn the model for the language languageId from the text files <text1.txt> <text2.txt> <text3.txt> ..." << endl;
    outputStream << endl;
    outputStream << "Parameters:" << endl;
    outputStream << "-t|-b: text mode or binary mode for the output file (-t by default)" << endl;
    outputStream << "-l languageId: language identifier (unknown by default)" << endl;
    outputStream << "-o outputFilename: name of the output file (output.bgr by default)" << endl;
    outputStream << "<text1.txt> <text2.txt> <text3.txt> ....: names of the input files (at least one is mandatory)" << endl;
}

void checkArguments(int& pos, bool& binary, string& languageId, string& outputFile, char *argv[], int argc) {

    // Iterate through all the arguments and check if any of them is an option
    string s;
    for (int i = 1; i < argc; i++) {
        s = argv[i];
        // The argument is an option
        if (s[0] == '-') {
            // Opción de texto
            if (s == "-t") {
                binary = false;
                pos ++ ;
            } else if (s == "-b") {
                binary = true;
                pos++ ;
            } else if (s == "-l") {
                if (argc > i + 2) {
                    languageId = argv[++i];
                    pos += 2 ;
                } else {
                    showEnglishHelp(cerr);
                    exit(1) ;
                }
            } else if (s == "-o") {
                if (argc > i + 2) {
                    outputFile = argv[++i];
                    pos += 2 ;
                } else {
                    showEnglishHelp(cerr);
                    exit(1) ;
                }
            }
        }else{
            break ;
        }
    }
}

/**
 * This program learns a Language model from a set of input tex files (tex1.txt,
 * tex2.txt, ...
 * Running example:
 * > LEARN [-t|-b] [-l languageId] [-o outputFilename] <text1.txt> [<text2.txt> <text3.txt> ....]
 * @param argc The number of command line parameters
 * @param argv The vector of command line parameters (cstrings)
 * @return 0 If there is no error; a value > 0 if error
 */

int main(int argc, char *argv[]) {
    cout << "Running LEARN" << endl;

    // If there isn´t at least one input file, show help and exit
    if (argc < 2) {
        showEnglishHelp(cerr);
        exit(1);
    }

    BigramCounter bc = BigramCounter();
    int pos = 1;
    bool binary = false;
    string languageId = "unknown";
    string outputFile = "output.bgr";

    // Check the parameters
    checkArguments(pos, binary, languageId, outputFile, argv, argc);
    cout << pos << " " << binary << " " << languageId << " " << outputFile << " " << endl;
    cout << argv[pos] << endl;
}

