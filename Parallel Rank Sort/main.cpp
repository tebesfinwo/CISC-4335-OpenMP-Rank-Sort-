//
//  main.cpp
//  Parallel Rank Sort
//
//  Created by johnson ooi on 5/1/14.
//  Copyright (c) 2014 tebesfinwo. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

//function prototypes
void linearySort(int*, int*);
void parallelSort(int*, int*);
void printAll(int*);

const int arraySize = 10;



int main(int argc, const char * argv[])
{

    srand(time(NULL));
    
    int arr[arraySize] = {0}; //array to be sorted
    
    int linearRank[arraySize] = {0};
    
    int parallelRank[arraySize] = {0};
    
    //initialize the array with random number from 0 to 32767 (or greater depending on the system)
    for (int i = 0; i < arraySize; i++) {
//        arr[i] = rand() % INT_MAX;
        arr[i] = rand() % 500;
    }
    

    linearySort(arr, linearRank);
    std::cout << "Hello, World!\n";
    printAll(linearRank);
    
    return 0;
}

void linearySort(int* arr, int* linearRankSorted){
    
    int rank[arraySize] = {0};
    
    int sorted[arraySize];
    
    for (int i = 0; i < arraySize; i++) {
        for (int j = 0; j < arraySize; j++) {
            if ( arr[j] > arr[i] || (arr[j] == arr[i] && j < i) ) {
                rank[i]++;
            }
        }
    }
    
    for (int i = 0; i < arraySize; i++) {
        sorted[rank[i]] = arr[i];
    }
    
    for (int i = 0; i < arraySize; i++) {
        linearRankSorted[i] = sorted[i];
    }
}

void printAll(int* arr){
    for (int i = 0; i < arraySize; i++) {
        std::cout << i << " : " << arr[i] << std::endl;
    }
}




