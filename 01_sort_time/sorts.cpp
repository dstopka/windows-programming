#include "stdafx.h"
#include "sorts.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

//---------------------------------

void Merge( int* pTab, int* ptmp, int nSize, int left, int m, int right );
void CopySerie( int* pTab, int* temp, int nSize, int* i, int* ix );
void UpdateHeap( int* pTab, int left, int right );
int copy( int* tab, int* temp, int nSize, int* i, int* ix );

//---------------------------------

void BubbleSort( int *t, int nSize )
{
	for ( int j = 0; j < nSize - 1; j++ )
		for ( int i = nSize - 1; i > j; i-- )
			if ( t[i] < t[i - 1] )
			{
				int temp = t[i];
				t[i] = t[i - 1];
				t[i - 1] = temp;
			}
}

//---------------------------------

void SelectionSort( int *t, int nSize )
{
	for ( int i = 0; i < nSize - 1; i++ )
	{
		int min = t[i];
		int ix = i;
		for ( int j = i + 1; j < nSize; j++ )
			if ( t[j] < min )
			{
				min = t[j];
				ix = j;
			}
		t[ix] = t[i];
		t[i] = min;
	}
}

//---------------------------------

void InsertionSort( int *t, int nSize )
{
	for ( int i = 1; i < nSize; i++ )
	{
		int x = t[i];
		int j = i - 1;
		while ( (j >= 0) && (t[j] > x) )
			t[j + 1] = t[j--];
		t[j + 1] = x;
	}
}

//---------------------------------

void HalfSort( int* tab, int nSize )
{
	for ( int i = 1; i < nSize; i++ ) {

		int key = tab[i];
		int left = 0;
		int right = i - 1;
		int m;

		while ( left <= right )
		{
			m = (left + right) / 2;
			if ( key < tab[m] )
				right = m - 1;
			else
				left = m + 1;
		}

		for ( int j = i - 1; j >= m; j-- )
			tab[j + 1] = tab[j];

		tab[left] = key;
	}

}

//---------------------------------

void MixedSort( int* tab, int nSize )
{
	int left = 1;
	int right = nSize - 1;
	int k = nSize - 1;

	while ( right > left ) {
		for ( int j = right; j >= left; j-- )
		{

			if ( tab[j - 1] > tab[j] )
			{
				int x = tab[j - 1];
				tab[j - 1] = tab[j];
				tab[j] = x;
				k = j;
			}
		}
		left = k + 1;

		for ( int j = left; j <= right; j++ )
		{
			if ( tab[j - 1] > tab[j] )
			{
				int x = tab[j - 1];
				tab[j - 1] = tab[j];
				tab[j] = x;
				k = j;
			}
		}
		right = k - 1;
	}
}

//---------------------------------

void QuickSort( int* tab, int left, int right )
{
	int i = left;
	int j = right;
	int x = tab[(left + right) / 2];

	while ( i <= j )
	{
		while ( tab[i] < x ) i++;
		while ( tab[j] > x ) j--;

		if ( i <= j )
		{
			if ( i != j )
			{
				int tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			i++;
			j--;
		}
	}

	if ( left < j ) QuickSort( tab, left, j );
	if ( i < right ) QuickSort( tab, i, right );
}

//---------------------------------

void Merge( int* pTab, int* ptmp, int nSize, int left, int m, int right )
{
	memcpy( ptmp, pTab, nSize * sizeof( *pTab ) );

	int i = left;
	int j = m + 1;
	int k = left;

	while ( i <= m && j <= right )
	{
		if ( ptmp[i] < ptmp[j] )
			pTab[k++] = ptmp[i++];
		else
			pTab[k++] = ptmp[j++];
	}
	while ( i <= m )
		pTab[k++] = ptmp[i++];
}

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

void MergeSort( int* pTab, int* ptmp, int nSize, int left, int right )
{
	if ( left < right )
	{
		int m = (left + right) / 2;
		MergeSort( pTab, ptmp, nSize, left, m );
		MergeSort( pTab, ptmp, nSize, m + 1, right );
		Merge( pTab, ptmp, nSize, left, m, right );
	}
}

//---------------------------------

void MergeSortSequence( int* tab, int nSize )
{
	int* tmp1 = (int*)calloc( nSize, sizeof( int ) );
	int* tmp2 = (int*)calloc( nSize, sizeof( int ) );
	if ( !tmp1 || !tmp2 )
	{
		perror( "ERROR! MEMORY!!!" );
		return;
	}

	int nSerie;
	do
	{
		int i = 0;		// tab
		int j = 0;		// tmp1
		int k = 0;		// tmp2
		while ( i < nSize )
		{
			while ( (i < nSize - 1) && (tab[i] <= tab[i + 1]) )
				tmp1[j++] = tab[i++];
			if ( i < nSize )
				tmp1[j++] = tab[i++];
			while ( (i < nSize - 1) && (tab[i] < tab[i + 1]) )
				tmp2[k++] = tab[i++];
			if ( i < nSize )
				tmp2[k++] = tab[i++];
		}

		int end1 = j;
		int end2 = k;
		nSerie = 0;
		i = j = k = 0;

		while ( (j < end1) && (k < end2) )
		{
			int end = 0;
			while ( !end )
			{
				if ( tmp1[j] <= tmp2[k] )
				{
					end = copy( tab, tmp1, end1, &i, &j );
					if ( end )
						CopySerie( tab, tmp2, end2, &i, &k );
				}
				else
				{
					end = copy( tab, tmp2, end2, &i, &k );
					if ( end )
						CopySerie( tab, tmp1, end1, &i, &j );
				}
			}
			nSerie++;
		}

		while ( j < end1 )
		{
			CopySerie( tab, tmp1, end1, &i, &j );
			nSerie++;
		}
		while ( k < end2 )
		{
			CopySerie( tab, tmp2, end2, &i, &k );
			nSerie++;
		}
	} while ( nSerie > 1 );

	free( tmp1 );
	free( tmp2 );
}

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

void CopySerie( int* pTab, int* temp, int nSize, int* i, int* ix )
{
	int end = 0;
	do
	{
		end = copy( pTab, temp, nSize, i, ix );
	} while ( !end );
}

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

int copy( int* tab, int* temp, int nSize, int* i, int* ix )
{
	tab[(*i)++] = temp[(*ix)++];
	if ( *ix == nSize ) return 1;

	return (temp[*ix - 1] > temp[*ix]);
}

//---------------------------------

void HeapSort( int* Tab, int nSize )
{
	int left = (nSize / 2) + 1;

	for ( ; left >= 0; left-- )
		UpdateHeap( Tab, left, nSize - 1 );

	for ( int right = nSize - 1; right > 0; right-- )
	{
		int x = Tab[0];
		Tab[0] = Tab[right];
		Tab[right] = x;

		UpdateHeap( Tab, 0, right - 1 );
	}
}

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

void UpdateHeap( int* pTab, int left, int right )
{
	if ( left == right ) return;
	int i = left;
	int j = (i + 1) * 2 - 1;
	int x = pTab[i];

	while ( j <= right )
	{
		if ( j < right )
			if ( pTab[j] < pTab[j + 1] )
				j++;

		if ( x > pTab[j] )
			break;

		pTab[i] = pTab[j];
		i = j;
		j = 2 * i + 1;
	}
	pTab[i] = x;
}

void callMergeSort( int *pTab, int nSize )
{
	int* tmp = (int*)calloc( nSize, sizeof( int ) );
	if ( !tmp )
	{
		printf( "\nMEMORY ERROR!!\n" );
	}
	MergeSort( pTab, tmp, nSize, 0, nSize - 1 );
	free( tmp );
}

//----------------------------

void callQuickSort( int *pTab, int nSize )
{
	QuickSort( pTab, 0, nSize - 1 );
}

void fillArray( int* array, int nSize )
{
	int *p = array;
	for ( int i = 0; i < nSize; ++i, ++p )
		*p = rand() % nSize;
}
