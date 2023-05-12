#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
    return pq->heapArray[0];
}



void heap_push(Heap* pq, void* data, int priority){

}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
	Heap* nuevo = (Heap*) malloc (sizeof(Heap));
	if (!nuevo)	exit(EXIT_FAILURE);

	nuevo->size = 0;
	nuevo->capac = 3;

	nuevo->heapArray = (heapElem*) malloc(sizeof(heapElem) * nuevo->capac);
	if (!nuevo->heapArray)	exit(EXIT_FAILURE);

   	return nuevo;
}
