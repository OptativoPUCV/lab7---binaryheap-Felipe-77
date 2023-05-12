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
	if (pq->size == 0)	return NULL;
	
	heapElem elem = pq->heapArray[0];
    return elem.data;
}

void resize(Heap* pq){
	int newCapac = (pq->capac * 2) + 1;

	pq->heapArray = (heapElem*) realloc(pq->heapArray, newCapac);
	if (!pq->heapArray)	exit(EXIT_FAILURE);

	return;
}

void heapify_u(Heap *H, int index){
  int parent = (index - 1) / 2;
  int aux;

  if (H->heapArray[parent].priority >= H->heapArray[index].priority)
    return;
  else {
    aux = H->heapArray[parent];
    H->heapArray[parent] = H->heapArray[index];
    H->heapArray[index] = aux;
    heapify_u(H, parent);
  }
}

void heap_push(Heap* pq, void* data, int priority){
	if (pq->size == pq->capac)	resize(pq);

	pq->heapArray[pq->size].data = data;
	pq->heapArray[pq->size].priority = priority;

	pq->size++;
	heapify_u(pq, pq->size - 1);
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
