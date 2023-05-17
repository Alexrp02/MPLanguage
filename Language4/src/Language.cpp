/*
 * Metodología de la Programación: Language4
 * Curso 2022/2023
 */

/** 
 * @file Language.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * 
 * Created on 12 February 2023, 10:40
 */


#include <fstream>

#include "Language.h"


using namespace std;

const string Language::MAGIC_STRING_T = "MP-LANGUAGE-T-1.0";

void Language::allocate(int n) {
    if (n < 1)
        throw ("Error, allocation of memory must be of more than 0");
    _vectorBigramFreq = new BigramFreq[n];
}

void Language::deallocate() {
    if (_vectorBigramFreq != nullptr)
        delete [] _vectorBigramFreq;
    _vectorBigramFreq = nullptr;
    _size = 0;
}

void Language::copy(const Language& lang) {
    this->_languageId = lang.getLanguageId();
    this->_size = lang.getSize();

    // Copiamos los bigramFreq
    for (int i = i; i < _size; i++) {
        _vectorBigramFreq[i] = lang.at(i);
    }
}

/**
 * @brief Base constructor. It builds a Language object with "unknown" as
 * identifier, and an empty vector of pairs Bigram-frequency. 
 */
Language::Language() {
    _languageId = string("unknown");
    _size = 0;
    _vectorBigramFreq = nullptr;
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
    if (numberBigrams < 0)
        throw (std::out_of_range("The number of bigram frequencies can't be less than 0 )"));

    // Allocate the number of bigrams
    allocate(numberBigrams);
    _languageId = string("unknown");
    _size = numberBigrams;
}

Language::Language(const Language& lang) {
    // Allocate the same size
    allocate(lang.getSize());
    // Copy the language 
    copy(lang);
}

Language& Language::operator=(const Language& orig) {
    // Comprobamos que no sea el mismo objeto
    if (this != &orig) {
        // Deallocate the previous vector
        deallocate();

        // Allocate the same size
        allocate(orig.getSize());
        // Copy the language 
        copy(orig);
    }
    return *this;
}

Language::~Language() {
    deallocate();
}

/**
 * @brief Returns the identifier of this language object. 
 * Query method.
 * @return A const reference to the identifier of this language object.
 */
const std::string& Language::getLanguageId() const {
    return _languageId;
}

/**
 * @brief Sets a new identifier for this language object. 
 * Modifier method.
 * @param id The new identifier. Input parameter 
 */
void Language::setLanguageId(const std::string& id) {
    _languageId = id;
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
const BigramFreq& Language::at(int index) const {
    if (index < 0 or index >= _size)
        throw (std::out_of_range("The given index is not correct."));
    return _vectorBigramFreq[index];
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
BigramFreq& Language::at(int index) {
    if (index < 0 or index >= _size)
        throw (std::out_of_range("The given index is not correct."));
    return _vectorBigramFreq[index];
}

/**
 * @brief Gets the number of BigramFreq objects. 
 * Query method
 * @return The number of BigramFreq objects
 */
int Language::getSize() const {
    return _size;
}

/*
 * For each Bigram look for the position of the bigram in the @p language
 * If not present, position must be size value in order to penalize
 * Substract to the index of the current Bigram the position and apply absolute value
 * Sum all the substractions, divide by the square of the size and return.
 */
double Language::getDistance(const Language &language) const {
    double suma = 0;
    for (int i = 0; i < _size; i++) {
        // Look for the position of the Bigram in the other language
        int pos = language.findBigram(_vectorBigramFreq[i].getBigram());

        // If it is not present, assign the size value
        if (pos == -1)
            pos = getSize();

        // Substract the two values and apply absolute value
        suma += abs(i - pos);
    }
    // Divide by the square of the size
    suma = suma / (_size * _size);
    return suma;
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
int Language::findBigram(const Bigram& bigram) const {

    //Iterate through the array to find the Bigram position.
    for (int i = 0; i < _size; i++) {
        if (_vectorBigramFreq[i].getBigram().toString().compare(bigram.toString()) == 0)
            return i;
    }
    //If not, return -1
    return -1;
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
    std::string result;
    result += getLanguageId() + "\n";
    result += to_string(getSize()) + "\n";
    for (int i = 0; i < _size; i++) {
        //        cout << "The Bigram is " << _vectorBigramFreq[i].getBigram().toString() << endl ;
        result += _vectorBigramFreq[i].toString();
        result += "\n";
    }
    return result;
}

void swap(BigramFreq array[], const int pos1, const int pos2) {
    BigramFreq aux = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = aux;
}

int partition(BigramFreq array[], int low, int high) {
    BigramFreq pivot = array[high];
    int pivotInd = low - 1;

    for (int i = low; i < high; i++) {
        if ((array[i].getFrequency() == pivot.getFrequency() && array[i].toString().compare(pivot.toString()) < 0) || array[i].getFrequency() > pivot.getFrequency()) {
            pivotInd++;
            swap(array, pivotInd, i);
        }
    }
    pivotInd++;
    swap(array, pivotInd, high);
    return pivotInd;
}

void quickSort(BigramFreq* array, int low, int high) {
    if (low >= high || low < 0) {
        return;
    }

    int pivot = partition(array, low, high);
    quickSort(array, low, pivot - 1);
    quickSort(array, pivot + 1, high);

}

void Language::sort() {
    //Call the function to quickSort the vector.
    quickSort(_vectorBigramFreq, 0, _size - 1);
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
void Language::save(const char fileName[]) const {
    ofstream file;
    //We open the file
    file.open(fileName);

    //If there was an error opening it, throw exception.
    if (!file)
        throw (std::ios_base::failure(std::string("An error occurred while opening the file ") + std::string(fileName)));
    //Save the magic string
    file << Language::MAGIC_STRING_T << endl;

    //Save the Language String
    file << toString();
    //Close the file
    file.close();
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
void Language::load(const char* fileName) {
    ifstream file;
    //We open the file
    //    cout << "Reading language from: " << fileName << endl;
    file.open(fileName);
    //If there was an error opening it, throw exception.
    if (!file) {
        throw (std::ios_base::failure(std::string("An error occurred while opening the file ") + std::string(fileName)));
        exit(1);
    }
    //Read the magic string and if it is not valid, throw exception.
    std::string magicString;
    file >> magicString;
    if (magicString.compare(Language::MAGIC_STRING_T) != 0) {
        throw (std::invalid_argument("The given file, does not contain a valid magic string."));
        exit(1);
    }
    //Read the language id
    file >> _languageId;

    //Read the number of bigrams in the file
    file >> _size;

    // Allocate the number of bigrams, if it had already memory allocated, we deallocate it
    if (_vectorBigramFreq != nullptr)
        deallocate();
    allocate(_size);

    //Read the array of BigramFreq
    for (int i = 0; i < _size; i++) {
        std::string bigramText;
        int bigramFrequency;

        file >> bigramText;
        file >> bigramFrequency;

        //Set the bigramFreq object with the text and frequency from the file.
        BigramFreq b;
        Bigram bigram = Bigram(bigramText);
        b.setBigram(bigram);
        b.setFrequency(bigramFrequency);

        //Add the created BigramFreq to the array.
        _vectorBigramFreq[i] = b;
    }
    file.close();
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
void Language::append(const BigramFreq& bigramFreq) {
    Bigram b = bigramFreq.getBigram();
    int pos = findBigram(b);
    if (pos == -1) {
        // Create an auxiliar pointer and copy the contents of the actual vector
        BigramFreq* v_aux = new BigramFreq [_size + 1];
        for (int i = 0; i < _size - 1; i++) {
            v_aux[i] = _vectorBigramFreq[i];
        }
        // Deallocate the old vector
        deallocate();
        // Assign the new value of the vector pointer
        _vectorBigramFreq = v_aux;
    } else
        _vectorBigramFreq[pos].setFrequency(_vectorBigramFreq[pos].getFrequency() + bigramFreq.getFrequency());



}

/**
 * @brief Appends to this Language object, the list of pairs  
 * bigram-frequency objects contained in the Language @p language. This
 * method uses the method append(BigramFreq bigramFreq) to
 * append the pairs bigram-frequency contained in the Language @p language
 * Modifier method
 * @param language A Language object. Input parameter
 */
void Language::join(const Language& language) {
    //Iterate through the language and append every bigramFreq
    for (int i = 0; i < language.getSize(); i++) {
        append(language.at(i));
    }
}