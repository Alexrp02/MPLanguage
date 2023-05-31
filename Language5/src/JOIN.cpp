/*
 * Metodología de la Programación: Language5
 * Curso 2022/2023
 */

/** 
 * @file JOIN.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * 
 * Created on 29 January 2023, 11:00
 */

#include <iostream>
#include <fstream>
#include "Language.h"

using namespace std;

/**
 * Shows help about the use of this program in the given output stream
 * @param outputStream The output stream where the help will be shown (for example,
 * cout, cerr, etc) 
 */
void showEnglishHelp(ostream& outputStream) {
    outputStream << "Error, run with the following parameters:" << endl;
    outputStream << "JOIN [-t|-b] [-o <outputFile.bgr>] <file1.bgr> [<file2.bgr> ... <filen.bgr>] " << endl;
    outputStream << "       join the Language files <file1.bgr> <file2.bgr> ... into <outputFile.bgr>" << endl;
    outputStream << endl;
    outputStream << "Parameters:" << endl;
    outputStream << "-t|-b: text mode or binary mode for the output file (-t by default)" << endl;
    outputStream << "-o <outputFile.bgr>: name of the output file (output.bgr by default)" << endl;
    outputStream << "<file*.bgr>: each one of the files to be joined" << endl;
}

void checkArguments(int& pos, char& mode, string& outputFile, char *argv[], int argc) {

    // Iterate through all the arguments and check if any of them is an option
    string s;
    for (int i = 1; i < argc; i++) {
        s = argv[i];
        // The argument is an option
        if (s[0] == '-') {
            // Opción de texto
            if (s == "-t") {
                mode = 't';
                pos++;
            } else if (s == "-b") {
                mode = 'b';
                pos++;
            } else if (s == "-o") {
                if (argc > i + 2) {
                    outputFile = argv[++i];
                    pos += 2;
                } else {
                    showEnglishHelp(cerr);
                    exit(1);
                }
            }
        } else {
            break;
        }
    }
}

/**
 * This program reads an undefined number of Language objects from the files
 * passed as parameters to main(). It obtains as result the union of all the 
 * input Language objects. The result is then sorted by decreasing order of 
 * frequency and alphabetical order of bigrams when there is any tie in 
 * frequencies. Finally, the resulting Language is saved in an output file. The 
 * program must have at least an output file. 
 * Running example:
 * >  JOIN [-t|-b] [-o <outputFile.bgr>] <file1.bgr> [<file2.bgr> ... <filen.bgr>]
 * @param argc The number of command line parameters
 * @param argv The vector of command line parameters (cstrings)
 * @return 0 If there is no error; a value > 0 if error
 */
int main(int argc, char* argv[]) {
    cout << "Ejecutando JOIN" << endl ;
    
    int offset = 1 ;
    char mode = 't' ;
    string outputFile = "output.bgr" ;
    
    // Check the options of the program
    checkArguments(offset, mode, outputFile, argv, argc) ;
    if (mode == 'b')
        cout << "Executing in binary mode" << endl;
    else
        cout << "Executing in text mode" << endl;

    cout << "Output file: " << outputFile << endl;
    cout << "Joining the next languages: " << endl;
    
    // Read the first language from first file
    ifstream file ;
    file.open(argv[offset++]) ;
    if(!file)
        
    Language lang ;
    lang << argv[offset++] ;
    
    // Iterate through the other languages and add join them to the first
    for (int i = offset; i < argc; i++) {
        cout << "Joining " << argv[i] << " ..." << endl;
        Language auxLang;
        auxLang << argv[i] ;
        lang += auxLang ;
    }
}

