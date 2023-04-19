/* 
 * File:   BigramFreq.cpp
 * Author: alexrp
 * 
 * Created on 15 de marzo de 2023, 10:37
 */

#include "BigramFreq.h"

/**
 * @brief Base constructor. It builds a BigramFreq object with "__" as 
 * the text of the bigram and 0 as the frequency
 */
BigramFreq::BigramFreq() {
    _bigram = Bigram('_', '_');
    _frequency = 0;
}

/**
 * @brief Gets a const reference to the Bigram of this BigramFreq object.
 * Query method
 * @return A const reference to the Bigram of this BigramFreq object
 */
const Bigram BigramFreq::getBigram() const{
    return _bigram;
}

/**
 * @brief Gets the frequency of this BigramFreq object
 * Query method
 * @return The frequency of this BigramFreq object
 */
int BigramFreq::getFrequency() const{
    return _frequency;
}

/**
 * @brief Sets the Bigram of this BigramFreq object
 * Modifier method
 * @param bigram The new Bigram value for this object. Input parameter
 */
void BigramFreq::setBigram(Bigram& bigram) {
    _bigram = bigram ;
}

/**
 * @brief Sets the frequency of this BigramFreq object. Modifier method.
 * @throw std::out_of_range if @p frequency is negative
 * @param frequency the new frequency value for this BigramFreq object. 
 * Input parameter
 */
void BigramFreq::setFrequency(int frequency) {
    _frequency = frequency ;
}

/**
 * @brief Obtains a string with the string and frecuency of the bigram
 * in this object (separated by a whitespace). Query method
 * @return A string with the string and frecuency of the bigram
 * in this object. 
 */
std::string BigramFreq::toString() const{
    return std::string(_bigram.toString() + " " + std::to_string(_frequency)) ;
}
