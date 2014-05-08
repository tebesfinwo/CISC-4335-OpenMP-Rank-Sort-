/**
 * 
 * @author Jun Han ( Johnson  )  Ooi 
 * CISC 4335 
 * Parallel Rank Sort  
 * 
 * Created on : April 30th 2014
 * Modified on : May 2nd 2014
 *
 * */
#include <omp.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>

#define arraySize 100000
#define numThreads 4

int main() {
 
 double openmp_start, openmp_end;
 time_t seq_start, seq_end;

 int i, j; 

 int arr[arraySize]; //array to be sorted
 int sorted[arraySize];
 int linearlySorted[arraySize];
 int rank[arraySize];

 srand(time(NULL)); 

 for(i = 0; i < arraySize; i++){
  //arr[i] = rand() % INT_MAX; 
  arr[i] = rand() % 500;
 } 

 //Sequential Rank Sort
 time(&seq_start);
 
 for(i = 0; i < arraySize; i++){
  rank[i] = 0;
 }

 for(i = 0; i < arraySize; i++){
  for(j = 0; j < arraySize; j++){
   if ( arr[j] > arr[i] || ( arr[j] == arr[i] && j < i ) ){
    rank[i]++;
   }
  }
 }
 
 for(i = 0; i < arraySize; i++){
  linearlySorted[rank[i]] = arr[i];
 }
 
 time(&seq_end);
  

 //Parallel Rank sort using Openmp
 openmp_start = omp_get_wtime();
 
 for(i = 0; i < arraySize; i++){
  rank[i] = 0;
 }

 omp_set_num_threads(numThreads);
 
 //Rank sort with openmp
 #pragma omp parallel for private(j)
  for(i = 0; i < arraySize; i++){
    for(j = 0; j < arraySize; j++){
     if ( arr[j] > arr[i] || ( arr[j] == arr[i] && j < i )  ){
      rank[i]++;
     }
    }
  }
  
  
  
  for(i = 0; i < arraySize; i++){
   sorted[rank[i]] = arr[i];
  }
  

 
 openmp_end = omp_get_wtime();
	
 for(i = 0; i < arraySize; i++){
  printf("unsorted : %d, Parallel sorted : %d, Sequential sorted : %d  \n",arr[i], sorted[i], linearlySorted[i]);
 }	
  
 printf( "Time used in parallel rank sort using openmp : %.0f seconds \n " , openmp_end - openmp_start ); 
 printf( "Time used in sequential rank sort : %.0f seconds \n ", difftime( seq_end, seq_start ) );
 
 return 0;
}

