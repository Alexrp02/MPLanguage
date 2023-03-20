/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   ArrayBigramFreqFunctions.cpp
 * Author: alexrp
 * 
 * Created on 20 de marzo de 2023, 11:58
 */

#include "ArrayBigramFreqFunctions.h"

/**
 * @brief Reads the number of used elements and the elements of an array of
 * BigramFreq
 * @param array The array where the elements will be stored. Output parameter
 * @param dim The capacity of the array. Input parameter
 * @param nElements The number of elements used by the array. Output parameter
 */
void readArrayBigramFreq(BigramFreq array[], const int dim, int& nElements) {

}

/**
 * @brief Prints in the standard output the number of used elements and the 
 * elements of an array of BigramFreq 
 * @param array The array of BigramFreq to be printed. Input parameter
 * @param nElements The number of elements used by the array. Input parameter
 */
void printArrayBigramFreq(BigramFreq array[], int nElements);

/**
 * @brief Swaps the elements at positions @p first and @p second in the given
 * array of BigramFreq
 * @param array The array of BigramFreq. Input/Output parameter
 * @param nElements The number of elements used by the array. Input parameter
 * @param first the position of the first element to be swaped. Input parameter
 * @param second the position of the second element to be swaped. Input parameter
 */
void swapElementsArrayBigramFreq(BigramFreq array[], int nElements, int first,
        int second);

/**
 * @brief Sorts the given array of BigramFreq in decreasing order of 
 * frequency and in decreasing order of Bigram when frequency is the same.
 * @param array The array of BigramFreq. Input/Output parameter
 * @param nElements The number of elements used by the array. Input parameter
 */
void sortArrayBigramFreq(BigramFreq array[], int nElements) {

}

/**
 * @brief Converts to uppercase all the bigrams within the given array
 * @param array An array of BigramFreq objects. Input/Output parameter
 * @param nElements The number of elements in the array. Input parameter
 */
void toUpperArrayBigramFreq(BigramFreq array[], int nElements) {
    for (int i=0 ; i< nElements ; i++) {
        array[i].getBigram()->toUpper() ;
    }
}

void quickSort(BigramFreq array[], int low, int high) {
    if (low >= high || low < 0) {
        return;
    }

    int pivot = partition(array, low, high);
    quickSort(array, low, pivot-1);
    quickSort(array, pivot+1, high);

}

int partition(BigramFreq array[], int low, int high) {
    BigramFreq pivot = array[high];
    int pivotInd = low - 1;

    for (int i = low; i < high; i++) {
        if (array[i].getFrequency() == pivot.getFrequency() && array[i].toString().compare(pivot.toString()) < 0) {
            pivotInd++;
            swap(array, pivotInd, i);
        }
        if (array[i].getFrequency() > pivot.getFrequency()) {
            pivotInd++;
            swap(array, pivotInd, i);
        }
    }
    pivotInd++;
    swap(array, pivotInd, high);
    return pivotInd;
}

void swap(BigramFreq array[], const int pos1, const int pos2) {
    BigramFreq aux = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = aux;
}
