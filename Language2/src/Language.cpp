/*
 * Metodología de la Programación: Language2
 * Curso 2022/2023
 */

/** 
 * @file Language.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * 
 * Created on 29 January 2023, 11:00
 */

#include <fstream>

#include "Language.h"


using namespace std;

const string Language::MAGIC_STRING_T = "MP-LANGUAGE-T-1.0";

/**
 * @brief Base constructor. It builds a Language object with "unknown" as
 * identifier, and an empty vector of pairs Bigram-frequency. 
 */
Language::Language() {
    _languageId = string("unknown");
}

/**
 * @brief It builds a Language object with "unknow" as
 * identifier, and a vector of @p numberBigrams pairs Bigram-frequency. 
 * Each pair will be initialized as "__" for the Bigram and 0 for the 
 * frequency.
 * @throw std::out_of_range Throws a std::out_of_range exception if
 * @p numberBigrams > @p DIM_VECTOR_BIGRAM_FREQ or numberBigrams<0
 * @param numberBigrams The number of bigrams to use in this Language.
 * Input parameter
 */
Language::Language(int numberBigrams) {
    if (numberBigrams > DIM_VECTOR_BIGRAM_FREQ or numberBigrams<0)
        throw (std::out_of_range("The number of bigram frequencies can´t be less than 0 and more than " + DIM_VECTOR_BIGRAM_FREQ));
    
    _languageId = string("unknown");
    _size = numberBigrams ;
}

/**
 * @brief Returns the identifier of this language object. 
 * Query method.
 * @return A const reference to the identifier of this language object.
 */
std::string Language::getLanguageId() const {
    return _languageId ;
}

/**
 * @brief Sets a new identifier for this language object. 
 * Modifier method.
 * @param id The new identifier. Input parameter 
 */
void Language::setLanguageId(std::string id) {
    _languageId = id ;
}


/**
 * @brief Gets a const reference to the BigramFreq at the given position 
 * of the vector in this object. 
 * Query method
 * @param index the position to consider. Input parameter
 * @throw std::out_of_range Throws an std::out_of_range exception if the 
 * given index is not valid
 * @return A const reference to the BigramFreq at the given position
 */
const BigramFreq Language::at(int index) const {
    if (index<0 or index>=_size)
        throw (std::out_of_range("The given index is not correct.")) ;
    return _vectorBigramFreq[index] ;
}

/**
 * @brief Gets a reference to the BigramFreq at the given position of the 
 * vector in this object. 
 * Query and modifier method
 * @param index the position to consider. Input parameter
 * @throw std::out_of_range Throws an std::out_of_range exception if the 
 * given index is not valid
 * @return A reference to the BigramFreq at the given position
 */
//BigramFreq Language::at(int index) const {
//    if (index<0 or index>=_size)
//        throw (std::out_of_range("The given index is not correct.")) ;
//    return _vectorBigramFreq[index] ;
//}

/**
 * @brief Gets the number of BigramFreq objects. 
 * Query method
 * @return The number of BigramFreq objects
 */
int Language::getSize() const{
    return _size ;
}

/**
 * @brief Searchs the given bigram in the list of bigrams in this
 * Language. If found, it returns the position where it was found. If not,
 * it returns -1. We consider that position 0 is the one of the first 
 * bigram in the list of bigrams and this->getSize()-1 the one of the last 
 * bigram.
 * Query method
 * @param bigram A bigram. Input parameter
 * @pre The list of bigrams should be ordered in decreasing order of
 * frequency. This is not checked in this method. 
 * @return If found, it returns the position where the bigram 
 * was found. If not, it returns -1
 */
int Language::findBigram(Bigram& bigram) const {
    
    //Iterate through the array to find the Bigram position.
    for (int i=0 ; i<_size ; i++) {
        if (_vectorBigramFreq[i].getBigram().toString().compare(bigram.toString()) == 0)
            return i ;
    }
    //If not, return -1
    return -1 ;
}

/**
 * @brief Obtains a string with the following content:
 * - In the first line, the number of bigrams in this Language 
 * - In the following lines, each one of the pairs bigram-frequency 
 * (separated by a whitespace).
 * Query method
 * @return A string with the number of bigrams and the list of pairs of
 * bigram-frequency in the object
 */
std::string Language::toString() const {
    std::string result = string(_size + "\n") ;
    for (int i=0 ; i<_size ; i++ ) {
        result += _vectorBigramFreq[i].toString() ;
        if (i!=_size-1)
            result+=string(" ") ;
    }
    return result;
}

/**
 * @brief Sort the vector of BigramFreq in decreasing order of frequency.
 * If two BigramFreq objects have the same frequency, then the alphabetical 
 * order of the bigrams of those objects will be considered (the object 
 * with a bigram that comes first alphabetically will appear first)
 * Modifier method
 */
void Language::sort() {
    //Call the function to quickSort the vector.
    sortArrayBigramFreq(_vectorBigramFreq, _size) ;
}

/**
 * @brief Saves this Language object in the given file. 
 * Query method
 * @param fileName A c-string with the name of the file where this Language 
 * object will be saved. Input parameter
 * @throw std::ios_base::failure Throws a std::ios_base::failure exception 
 * if the given file cannot be opened or if an error occurs while writing
 * to the file
 */
void Language::save(char fileName[]) const {
    ofstream file ;
    //We open the file
    file.open(fileName) ;
    
    //If there was an error opening it, throw exception.
    if (!file)
        throw (std::ios_base::failure(std::string("An error occurred while opening the file ") + std::string(fileName))) ;
    //The magic string
    file << MAGIC_STRING_T << endl ;
    
    //The language id
    file << _languageId << endl ;
    
    //Number of bigrams
    file << _size << endl ;
    
    //The list of bigrams with frequencies
    for (int i=0 ; i<_size ; i++) {
        file << _vectorBigramFreq[i].toString() << endl ;
    }
}

/**
 * @brief Loads into this object the Language object stored in the given 
 * file
 * Modifier method
 * @param fileName A c-string with the name of the file where the Language 
 * will be stored. Input parameter
 * @throw std::out_of_range Throws a std::out_of_range exception if the 
 * number of bigrams in the given file, cannot be allocated in this Language
 * because it exceeds the maximum capacity
 * @throw std::ios_base::failure Throws a std::ios_base::failure exception 
 * if the given file cannot be opened or if an error occurs while reading
 * from the file
 * @throw throw std::invalid_argument Throws a std::invalid_argument if
 * an invalid magic string is found in the given file
 */
void Language::load(char fileName[]) {
    ifstream file;
    //We open the file
    file.open(fileName) ;
    
    //If there was an error opening it, throw exception.
    if (!file)
        throw (std::ios_base::failure(std::string("An error occurred while opening the file ") + std::string(fileName))) ;
    
    //Read the magic string and if it is not valid, throw exception.
    std::string magicString ;
    file >> magicString ;
    if(magicString.compare(MAGIC_STRING_T) !=0) 
        throw(std::invalid_argument ("The given file, does not contain a valid magic string.")) ;
    
    //Read the language id
    file >> _languageId ;
    
    //Read the number of bigrams in the file, if it is bigger than maximum dimension, throw error.
    file >> _size;
    if (_size > DIM_VECTOR_BIGRAM_FREQ)
        throw (std::out_of_range("The maximum number of arguments is " + DIM_VECTOR_BIGRAM_FREQ)) ;
    
    //Read the array of BigramFreq
    for (int i=0 ; i<_size ; i++){
        std::string bigramText;
        int bigramFrequency ;
        
        file >> bigramText ;
        file >> bigramFrequency ;
        
        //Set the bigram info with the text and frequency from the file.
        BigramFreq b;
        Bigram bigram = Bigram(bigramText) ;
        b.setBigram(bigram) ;
        b.setFrequency(bigramFrequency) ;
        
        _vectorBigramFreq[i] = b ;
    }
}

/**
 * @brief Appends a copy of the given BigramFreq to this Language object.
 * If the bigram is found in this object, then its frequency is increased
 * with the one of the given BigramFreq object. If not, a copy of the 
 * given BigramFreq object is appended to the end of the list of
 * BigramFreq objects in this Language.
 * @thow std::out_of_range Throws a std::out_of_range exception in case
 * that a new element must be appended to the end of the array and the
 * number of elements in the array of BigramFreq is equals to the capacity
 * of that array. In that case, the array is full, and no more elements
 * can be appended to the array.
 * Modifier method
 * @param bigramFreq The BigramFreq to append to this object. Input parameter
 */
void Language::append(BigramFreq bigramFreq) {
    Bigram b = bigramFreq.getBigram() ;
    if (findBigram(b) == -1)
        if (_size == DIM_VECTOR_BIGRAM_FREQ) {
            throw (std::out_of_range("The element can´t be appended to the language because it has the maximum number of bigrams.")) ;
        }
}

/**
 * @brief Appends to this Language object, the list of pairs  
 * bigram-frequency objects contained in the Language @p language. This
 * method uses the method append(BigramFreq bigramFreq) to
 * append the pairs bigram-frequency contained in the Language @p language
 * Modifier method
 * @param language A Language object. Input parameter
 */
void Language::join(Language& language) {
    
}