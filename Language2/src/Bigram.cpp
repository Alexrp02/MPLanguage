#include "Bigram.h"

/**
 * @brief It builds a Bigram object with @p text as the 
 * text of the bigram. If the string @p text contains a number of characters 
 * other than two, then the text of the bigram will be initialized with
 * "__"
 * 
 * @param text the text for the bigram. It should be a string with just two
 * characters.
 */
Bigram::Bigram(const std::string &text) {
    if (text.size() != 2) {
        _text[0] = '_';
        _text[1] = '_';
        _text[2] = '\0';
    } else {
        strncpy(_text, text.c_str(), 3) ;
    }
}

/**
 * @brief It builds a Bigram object using the two characters passed as
 * parameters of this constructor as the text of the bigram
 *
 * @param first the first character for the bigram
 * @param second the second character for the bigram
 */
Bigram::Bigram(char first, char second) {
    //Hay que añadir un \0 al final del array de caracteres ya que ahora es un cstring
    _text[0] = first;
    _text[1] = second;
    _text[2] = '\0';
}

Bigram::Bigram(char text[]) {
    int count = 0;
    while (text[count] != '\0')
        count++;
    if (count != 2) {
        _text[0] = '_';
        _text[1] = '_';
        _text[2] = '\0';
    }else {
        _text[0] = text[0] ;
        _text[1] = text[1] ;
        _text[2] = '\0' ;
    }
}

/**
 * @brief Obtains a copy of the text of this bigram as a string object
 * @return The text of this bigram as a string object
 */
std::string Bigram::getText() const {
    return _text;
}

/**
 * @brief Obtains a copy of the text of this bigram as a string object
 * @return The text of this bigram as a string object
 */
std::string Bigram::toString() const {
    return std::string(_text);
}

/**
 * @brief Gets a const reference to the character at the given position
 * @param index the position to consider
 * @throw std::out_of_range Throws a std::out_of_range exception if the
 * index is not equals to 0 or 1
 * @return A const reference to the character at the given position
 */
const char &Bigram::at(int index) const {
    if (index > 1 || index < 0) {
        throw (std::out_of_range("The given index has to be either 0 or 1."));
    }
    return _text[index];
}

/**
 * @brief Gets a reference to the character at the given position
 * @param index the position to consider
 * @throw std::out_of_range Throws a std::out_of_range exception if the
 * index is not equals to 0 or 1
 * @return A reference to the character at the given position
 */
char & Bigram::at(int index) {
    if (index > 1 || index < 0) {
        throw (std::out_of_range("The given index has to be either 0 or 1."));
    }
    return _text[index];
}

/**
 * Checks if the given character is contained in @p validCharacters. That is, if
 * the given character can be consireded as part of a word.
 * @param character The character to check
 * @param validCharacters The set of characters that we consider as possible 
 * characters in a word. Any other character is considered as a separator.
 * @return true if the given character is contained in @p validCharacters; false
 * otherwise
 */

bool isValidCharacter(char character, const std::string& validCharacters) {
    return validCharacters.find(character) != std::string::npos;
}

void Bigram::toUpper() {
    _text[0] = toupper(_text[0]);
    _text[1] = toupper(_text[1]);
}