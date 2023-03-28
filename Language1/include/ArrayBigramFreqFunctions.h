
/*
 * Metodología de la Programación: Language1
 * Curso 2022/2023
 */

/** 
 * @file ArrayBigramFreqFunctions.h
 * @author estudiante1: Ramos Peña, Alejandro
 * 
 * Created on 7 February 2023, 19:45
 */
#ifndef ARRAYBIGRAMFREQFUNCTIONS_H
#define ARRAYBIGRAMFREQFUNCTIONS_H

#include "BigramFreq.h"
#include <string>
#include <iostream>
#include <stdio.h> 

/**
 * @brief Reads the number of used elements and the elements of an array of
 * BigramFreq
 * @param array The array where the elements will be stored. Output parameter
 * @param dim The capacity of the array. Input parameter
 * @param nElements The number of elements used by the array. Output parameter
*/
void readArrayBigramFreq(BigramFreq array[], const int dim, int& nElements);

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
void sortArrayBigramFreq(BigramFreq array[], int nElements);

/**
 * @brief Converts to uppercase all the bigrams within the given array
 * @param array An array of BigramFreq objects. Input/Output parameter
 * @param nElements The number of elements in the array. Input parameter
 */
void toUpperArrayBigramFreq(BigramFreq array[], int nElements);

/**
 * @brief Sorts the given array in the delimited zone by the @p low and @p high, calling other functions like swap and partition.
 * @param array The array to be sorted.
 * @param low The lower index of the array to be sorted.
 * @param high The high index of the array to be sorted.
 */
void quickSort(BigramFreq array[] , int low, int high) ;

/**
 * 
 * @param array The array where the swap is going to be done.
 * @param pos1 The position of the first item to be swapped.
 * @param pos2 The position of the second item to be swapped.
 */
void swap(BigramFreq array[], int pos1, int pos2) ;

/**
 * 
 * @param array The array to be partitioned.
 * @param low The lower bound where the array is going to be partitioned.
 * @param high The higher bound where the array is going to be partitioned.
 * @return The position where the pivot is (the pivot is in the final position of the sorted array).
 */
int partition(BigramFreq array[], int low, int high) ;

#endif /* ARRAYBIGRAMFREQFUNCTIONS_H */

