#ifndef SORTS_H
#define SORTS_H

typedef void( *pFSort )(int*, int);

void BubbleSort( int *t, int nSize );
void SelectionSort( int *t, int nSize );
void InsertionSort( int *t, int nSize );
void HalfSort( int* tab, int nSize );
void MixedSort( int* tab, int nSize );
void QuickSort( int* tab, int left, int right );
void MergeSort( int* pTab, int* ptmp, int nSize, int left, int right );
void MergeSortSequence( int* tab, int nSize );
void HeapSort( int* Tab, int nSize );
void callMergeSort( int *t, int nSize );
void callQuickSort( int *t, int nSize );

void fillArray(int* array, int nSize);

#endif

