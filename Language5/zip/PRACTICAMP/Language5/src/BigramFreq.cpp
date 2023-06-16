/*
 * Metodolog�a de la Programaci�n: Language3
 * Curso 2022/2023
 */

/** 
 * @file BigramFreq.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andr�s Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * 
 * Created on 12 February 2023, 10:40
 */

#include <string>

#include "BigramFreq.h"

using namespace std;

BigramFreq::BigramFreq(){
    _bigram = Bigram('_', '_');
    _frequency = 0 ;
}

const Bigram& BigramFreq::getBigram() const {
    return _bigram;
}
int BigramFreq::getFrequency() const {
    return _frequency;
}

void BigramFreq::setBigram(const Bigram& bigram) {
    this->_bigram = bigram;
}

void BigramFreq::setFrequency(int frequency) {
    if(frequency<0){
        throw  std::out_of_range(string("void BigramFreq::setFrequency(int frequency): ") +
                "invalid frecuency " + to_string(frequency));
    }
    this->_frequency = frequency;
}

string BigramFreq::toString() const {
    return _bigram.toString() + " " + to_string(_frequency);
}

/**
 * @brief Overloading of the stream insertion operator for BigramFreq class
 * @param os The output stream to be used. Output parameter
 * @param bigramFreq the BigramFreq object. Input parameter
 * @return @p os A reference to the output stream
 */
std::ostream& operator<<(std::ostream & os, const BigramFreq& bigramFreq) {
    os << bigramFreq.toString() ;
    return os;
}

/**
 * @brief Overloading of the stream extraction operator for BigramFreq class
 * @param is The input stream to be used. Input parameter
 * @param bigramFreq the BigramFreq object. Output parameter
 * @return @p is A reference to the input stream
 */
std::istream& operator>>(std::istream& is, BigramFreq& bigramFreq) { 
    Bigram b;
    is >> b ;
    int freq ; 
    is >> freq;
    bigramFreq.setBigram(b);
    bigramFreq.setFrequency(freq) ;
    return is ;
}

/**
 * @brief Overloading of the relational operator > for BigramFreq class
 * @param bigramFreq1 The first object to be compared. Input parameter
 * @param bigramFreq2 The second object to be compared. Input parameter
 * @return true if the frequency of @p bigramFreq1 is lower than that of
 * @p bigramFreq2 or if both frequencies are equals and the text of the
 * @p bigramFreq1 is minor than the text of @p bigramFreq2; false otherwise
 */
bool operator>(const BigramFreq& bigramFreq1, const BigramFreq & bigramFreq2){
    if (bigramFreq1.getFrequency() < bigramFreq2.getFrequency())
        return true;
    else if (bigramFreq1.getFrequency() == bigramFreq2.getFrequency() and bigramFreq1.getBigram().toString() < bigramFreq2.getBigram().toString())
        return true ;
    else
        return false ;
}

/**
 * @brief Overloading of the operator < for BigramFreq class
 * @param bigramFreq1 a Bigram object. Input parameter
 * @param bigramFreq2 a Bigram object. Input parameter
 * @return true if the bigramFreq1 < bigramFreq2; false otherwise
 */
bool operator<(const BigramFreq& bigramFreq1, const BigramFreq & bigramFreq2) {
    if (bigramFreq1.getFrequency() > bigramFreq2.getFrequency())
        return true;
    else if (bigramFreq1.getFrequency() == bigramFreq2.getFrequency() and bigramFreq1.getBigram().toString() > bigramFreq2.getBigram().toString())
        return true ;
    else
        return false ;
}

/**
 * @brief Overloading of the operator == for Bigram class
 * @param bigramFreq1 a BigramFreq object. Input parameter
 * @param bigramFreq2 a BigramFreq object. Input parameter
 * @return true if the two bigrams contains the same pair Bigram-Frequency;
 * false otherwise
 */
bool operator==(const BigramFreq & bigramFreq1, const BigramFreq &  bigramFreq2) {
    return (bigramFreq1.getBigram().toString() == bigramFreq2.getBigram().toString() and bigramFreq1.getFrequency() == bigramFreq2.getFrequency()) ;
}

/**
 * @brief Overloading of the operator != for BigramFreq class
 * @param bigramFreq1 a Bigram object. Input parameter
 * @param bigramFreq2 a Bigram object. Input parameter
 * @return true if the two bigramFreq1 are not equals (see operator==); 
 * false otherwise
 */
bool operator!=(const BigramFreq & bigramFreq1, const BigramFreq & bigramFreq2){
    return !(bigramFreq1 == bigramFreq2) ;
}

/**
 * @brief Overloading of the operator <= for BigramFreq class
 * @param bigramFreq1 a Bigram object. Input parameter
 * @param bigramFreq2 a Bigram object. Input parameter
 * @return true if the bigramFreq1 <= bigramFreq2; false otherwise
 */
bool operator<=(const BigramFreq &bigramFreq1, const BigramFreq & bigramFreq2) {
    return (bigramFreq1 < bigramFreq2 or bigramFreq1 == bigramFreq2) ;
}

/**
 * @brief Overloading of the operator >= for BigramFreq class
 * @param bigramFreq1 a Bigram object. Input parameter
 * @param bigramFreq2 a Bigram object. Input parameter
 * @return true if the bigramFreq1 >= bigramFreq2
 */
bool operator>=(const BigramFreq & bigramFreq1, const BigramFreq & bigramFreq2){
    return (bigramFreq1 > bigramFreq2 or bigramFreq1 == bigramFreq2) ;
}

/**
     * Serializes this object to the given output stream. It first serializes
     * the bigram of this object and them the bytes of the
     * frequency (an int value) in binary format (using 
     * method ostream::write(const char* s, streamsize n))
     * @param outputStream A output stream where this object will be serialized
     */
    void BigramFreq::serialize(std::ostream& outputStream) {
        _bigram.serialize(outputStream) ;
        outputStream.write(reinterpret_cast<char*>(&_frequency), sizeof(int)) ;
    }
    
    /**
     * Deserializes this object from the given input stream. It first deserializes
     * the Bigram of this object and them then the bytes of the
     * frequency (an int value) in binary format (using 
     * method istream::read(char* s, streamsize n))
     * @param inputSstream A input stream from which this object will be deserialized
     */
    void BigramFreq::deserialize(std::istream& inputSstream) {
        Bigram b ;
        b.deserialize(inputSstream) ;
        _bigram = b ;
        int f ;
        inputSstream.read(reinterpret_cast<char*>(&f), sizeof(int)) ;
        _frequency = f ;
    }