/*
 * Metodolog?a de la Programaci?n: Language3
 * Curso 2022/2023
 */

/** 
 * @file Bigram.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andr?s Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * 
 * Created on 12 February 2023, 10:40
 */

#include <string>
#include <cstring>

#include "Bigram.h"

using namespace std;

Bigram::Bigram(const std::string& text) {
    if (text.size() == 2) {
        strcpy(_text,text.c_str());
    }
    else{
        strcpy(_text, "__"); // ?Lanzar excepci?n?
    }
}
    
Bigram::Bigram(char first, char second) { 
    _text[0] = first;
    _text[1] = second;
    _text[2] = '\0';
}

Bigram::Bigram(const char* text)  { 
    if (strlen(text) == 2) {
        strcpy(_text, text);
    }
    else{
        strcpy(_text, "__");  // ?Lanzar excepci?n?
    } 
}

const char& Bigram::at(int index) const{
    if(index<0 || index>1){
        throw std::out_of_range(string("const char& Bigram::at(int index) const: ") +
                "invalid position " + to_string(index));
    }
    else{
        return _text[index];
    }
}

char& Bigram::at(int index){
    if(index<0 || index>1){
        throw std::out_of_range(string("char& Bigram::at(int index): ") +
                "invalid position " + to_string(index));
    }
    else{
        return _text[index];
    }
}

std::string Bigram::getText() const{
    return string(_text);
}

std::string Bigram::toString() const {
    return string(_text);
}

void Bigram::toUpper() {
    at(0) = toupper(at(0));
    at(1) = toupper(at(1));
}

bool isValidCharacter(char character, const string& validCharacters) {
    return validCharacters.find(character)!=string::npos;
}

std::ostream& operator<<(std::ostream& os, const Bigram& bigram) {
    os << bigram.toString() ;
    return os ;
}

std::istream& operator>>(std::istream& is, Bigram& bigram) {
    string text ;
    is >> text ;
    bigram = Bigram(text) ;
    return is ;
}

/**
     * Serializes this object to the given output stream. Only the two
     * bytes of the two characters of the bigram are sent to the output stream.
     * The '\0' is not sent to the output stream
     * @param outputStream A output stream where this object will be serialized
     */
    void Bigram::serialize(std::ostream& outputStream) {
        outputStream.write(&_text[0], sizeof(char)) ;
        outputStream.write(&_text[1], sizeof(char)) ;
    }
    
    /**
     * Deserializes this object from the given input stream. It reads two
     * bytes from the given input stream and put them in the text of this Bigram
     * @param inputSstream A input stream from which this object will be deserialized
     */
    void Bigram::deserialize(std::istream& inputStream) {
        char c1='_',c2='_' ;
        inputStream.read(&c1, sizeof(char)) ;
        inputStream.read(&c2, sizeof(char)) ;
        _text[0] = c1 ;
        _text[1] = c2 ;
        _text[2] = '\0' ;
    }
