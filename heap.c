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


void swap(heapElem *arr, int a, int b) {
  heapElem aux = arr[a];
  arr[a] = arr[b];
  arr[b] = aux;
}

void heapify_u(Heap *H, int index){
	int parent = (index - 1) / 2;

	if (H->heapArray[parent].priority >= H->heapArray[index].priority)
		return;
	else {
		swap(H->heapArray, parent, index);
		heapify_u(H, parent);
  	}
}

void heap_push(Heap* pq, void* data, int priority){
	pq->size++;
	if (pq->size == pq->capac){
		pq->capac = (pq->capac * 2) + 1;
		pq->heapArray = (heapElem*)realloc(pq->heapArray, sizeof(heapElem) * pq->capac);
	}

	pq->heapArray[pq->size - 1].data = data;
	pq->heapArray[pq->size - 1].priority = priority;

	heapify_u(pq, pq->size - 1);
}

void heapify_d(Heap *H, int index){
	int index_l, index_r;
	index_l = (2 * index) + 1;
	index_r = (2 * index) + 2;

	if (H->heapArray[index].priority < H->heapArray[index_l].priority){
		swap(H->heapArray, index, index_l);
		heapify_d(H, index_l);
	}
	else if (H->heapArray[index].priority < H->heapArray[index_r].priority){
		swap(H->heapArray, index, index_r);
		heapify_d(H, index_r);
	}
	else
		return;
	
}

void heap_pop(Heap* pq){
	if (pq->size == 0)	return;

	heapElem aux;
	pq->size--;

	aux = pq->heapArray[0];
	pq->heapArray[0] = pq->heapArray[pq->size];
	pq->heapArray[pq->size] = aux;

	heapify_d(pq, 0);
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
