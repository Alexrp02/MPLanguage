/*
 * Metodología de la Programación: Language5
 * Curso 2022/2023
 */

/** 
 * @file BigramCounter.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * 
 * Created on 12 February 2023, 11:00
 */

#include <istream>

#include "BigramCounter.h"


// Allocate a matrix of ints of nxn size

int** allocate(int n) {
    int** sol;

    // Allocate space for the array of pointers
    sol = new int*[n];
    for (int i = 0; i < n; i++) {
        sol [i] = new int [n];
    }
    return sol;

}

// Deallocate a matrix of nxn size, where n is @p n

void deallocate(int** &v, int n) {
    for (int i = 0; i < n; i++) {
        delete [] v[i];
    }
    delete [] v;
    v = nullptr;
}

/**
 * DEFAULT_VALID_CHARACTERS is a c-string that contains the set of characters
 * that will be considered as part of a word (valid chars). 
 * The characters not in the c-string will be considered as separator of words.
 * The constructor of the class BigramCounter uses this c-string as a 
 * default parameter. It is possible to use a different c-string if that
 * constructor is used with a different c-string
 */
const char* const BigramCounter::DEFAULT_VALID_CHARACTERS = "abcdefghijklmnopqrstuvwxyz\xE0\xE1\xE2\xE3\xE4\xE5\xE6\xE7\xE8\xE9\xEA\xEB\xEC\xED\xEE\xEF\xF0\xF1\xF2\xF3\xF4\xF5\xF6\xF8\xF9\xFA\xFB\xFC\xFD\xFE\xFF";

BigramCounter::BigramCounter(const std::string& validChars) {
    _validCharacters = validChars;

    // Allocate memory for the frequency array
    _frequency = allocate(validChars.size());

}

/**
 * @brief Copy constructor
 * @param orig the BigramCounter object used as source for the copy. Input
 * parameter
 */
BigramCounter::BigramCounter(const BigramCounter& orig) {
    // Copy the string of valid characters
    this->_validCharacters = orig._validCharacters;
    // Allocate space in frequency matrix for the new valid characters
    this->_frequency = allocate(_validCharacters.size());
    
    // Copy the contents of the frequency vector
    for (int i=0 ; i<orig.getSize() ; i++) {
        for (int j=0 ; j<orig.getSize() ; j++) {
            _frequency[i][j] = orig._frequency[i][j] ;
        }
    }
}

/**
 * @brief Destructor
 */
BigramCounter::~BigramCounter() {
    deallocate(_frequency, _validCharacters.size());
}

/**
 * @brief Returns the number (size) of valid characters that are considered as part 
 * of a word in this BigramCounter object. Query method
 * @return the number (size) of valid characters that are considered as part 
 * of a word in this BigramCounter object 
 */
int BigramCounter::getSize() const {
    return _validCharacters.size();
}

/**
 * @brief Gets the number of bigrams with a frequency greater than 0.
 * Query method
 * @return the number of bigrams with a frequency greater than 0
 */
int BigramCounter::getNumberActiveBigrams() const {
    int cont = 0;
    for (int i = 0; i < getSize(); i++) {
        for (int j = 0; j < getSize(); j++) {
            if (_frequency[i][j] > 0)
                cont++;
        }
    }
    return cont;
}

/**
 * @brief Sets the frequency of the given bigram using the value 
 * provided with @p frequency. Modifier method
 * @param bigram The bigram in which the frequency will be set. Input
 * parameter
 * @param frequency The new frequency. Input parameter
 * @return true if the bigram was found in this object. false otherwise
 */
bool BigramCounter::setFrequency(const Bigram& bigram, int frequency) {
    int i = _validCharacters.find(bigram.at(0));
    int j = _validCharacters.find(bigram.at(1));

    if (i == std::string::npos || j == std::string::npos)
        return false;

    _frequency[i][j] = frequency;
    return true;
}

/**
 * @brief Increases the current frequency of the given bigram using the value 
 * provided with @p frequency. If @p frequency is 0 or frequency is not 
 * provided, then 1 is added to the current frequency of the bigram.
 * Modifier method
 * @throw std::invalid_argument This method throws an 
 * std::invalid_argument exception if the given bigram is not valid
 * @param bigram The bigram in which the frequency will be modified.
 * Input parameter
 * @param frequency The quantity that will be added to the current frequency.
 * Input parameter
 */
void BigramCounter::increaseFrequency(const Bigram& bigram, int frequency) {
    if (!frequency)
        frequency = 1;

    int i = _validCharacters.find(bigram.at(0));
    int j = _validCharacters.find(bigram.at(1));

    // If not found in the valid characters then throw the error
    if (i == std::string::npos || j == std::string::npos)
        throw (std::invalid_argument(std::string("The given bigram is not valid")));

    _frequency[i][j] += frequency;

}

/**
 * @brief Overloading of the assignment operator
 * @param orig the BigramCounter object used as source for the assignment.
 * Input parameter
 * @return A reference to this object
 */
BigramCounter& BigramCounter::operator=(const BigramCounter& orig) {
    // Delete the array
    deallocate(_frequency, getSize());

    // Copy the string of valid characters
    this->_validCharacters = orig._validCharacters;
    // Reallocate space in frequency matrix for the new valid characters
    this->_frequency = allocate(_validCharacters.size());

    // Copy the contents of the orig _frequency vector
    for (int i = 0; i < getSize(); i++)
        for (int j = 0; i < getSize(); j++)
            _frequency[i][j] = orig._frequency[i][j];

    return *this;
}

/**
 * @brief Overloading of the operator +=. It increases the current 
 * frequencies of the bigrams of this object with the frequencies of the 
 * bigrams of the given object. 
 * Modifier method
 * @param rhs a BigramCounter object 
 * @return A reference to this object
 */
BigramCounter& BigramCounter::operator+=(const BigramCounter& rhs) {

    // Iterate through all the frequencies of rhs and increment those bigrams in this.
    for (int i = 0; i < getSize(); i++)
        for (int j = 0; j < getSize(); j++) {
            Bigram b = Bigram(_validCharacters[i], _validCharacters[j]);
            increaseFrequency(b, rhs._frequency[i][j]);
        }

    return *this;
}

/**
 * @brief Reads the given text file and calculates the frequencies of each 
 * bigram in that file.
 * Modifier method
 * @throw std::ios_base::failure Throws a std::ios_base::failure exception
 * if the given file cannot be opened
 * @param fileName The name of the file to process. Input parameter
 * @return true if the file could be read; false otherwise
 */
void BigramCounter::calculateFrequencies(const char* fileName) {
    ifstream file;

    // Open the file
    file.open(fileName);

    if (!file) {
        throw (ios_base::failure("The file " + string(fileName) + " couldn´t be opened."));
    }

    // Get a character
    char first = file.get();
    first = tolower(first);
    char second ;
    if(first != EOF)
        second = file.get();
    else
        second = EOF ;

    // While the second character isn´t the end of the file, read characters.
    // If the first character readed before the while is the end of the file doesn´t
    // even enter the while.
    while (second != EOF && first != EOF) {
        // Find the position in the valid characters
        int first_index = _validCharacters.find(first);
        // If it is valid get the next character, go on
        if (first_index != string::npos) {
            second = file.get();
            second = tolower(second);

            int second_index = _validCharacters.find(second);
            // If it is a valid character, increment the frequency of that bigram by 1
            if (second_index != string::npos) {
                increaseFrequency(Bigram(first, second), 1);
                // If the second char is valid, we assign it to be the next first
                first = second;
            }else if (second != EOF){ // If the second char wasn´t the EOF, get another first character for the next iteration
                first = file.get() ;
                first = tolower(first) ;
            }

        }else { // If the first character is not valid, we get the next char
            first = file.get() ;
            first = tolower(first) ;
        }
    }

}

/**
 * @brief Builds a Language object from this BigramCounter object. The 
 * Language will contain the bigrams and frequencies for those one with 
 * a frequency greater than 0.
 * Query method
 * @return A Language object from this BigramCounter object
 */
Language BigramCounter::toLanguage() const {
    // Create a new Language with the number of active Bigrams this counter has
    Language lang = Language(getNumberActiveBigrams());

    int cont = 0;
    // Iterate through all the Bigrams of this counter and put them in the language
    for (int i = 0; i < getSize(); i++)
        for (int j = 0; j < getSize(); j++) {
            // If the bigram has more than 0 of frequency, add it
            if (_frequency[i][j] > 0) {
                // Set the bigramFreq
                BigramFreq bf = BigramFreq();
                bf.setBigram(Bigram(_validCharacters[i], _validCharacters[j]));
                bf.setFrequency(_frequency[i][j]);
                // Put it in the language
                lang.at(cont++) = bf;
            }
        }

    return lang;
}