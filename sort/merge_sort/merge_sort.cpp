#include <cstdio>
#include <iostream>

using namespace std;

inline void merge( int *ar, int begin, int end ){
    
    int *tmp = new int[end - begin + 1];                            // Allocating temporary array for merging
    int middle = (begin + end) / 2;                                 // Finding middle point of current subarray
    int leftIndice = begin, rightIndice = middle + 1, indice = 0;   // Setting current indices for comparisons in right and left halves of subarray, also setting current indice for tmp array

    while( leftIndice <= middle && rightIndice <= end )             // '<=' is for stability
        if( ar[leftIndice] <= ar[rightIndice] )                     // When next number in the left half is going to tmp
            tmp[indice++] = ar[leftIndice++];
        else                                                        // WHen next number in the right half is going to tmp
            tmp[indice++] = ar[rightIndice++];
    
    while( leftIndice <= middle )                                   // There may be some numbers left in the left half
        tmp[indice++] = ar[leftIndice++];
    
    while( rightIndice <= end )                                     // There may be some numbers left in the right half
        tmp[indice++] = ar[rightIndice++];
    
    for( int i=0 ; i<indice ; i++ )                                 // Copying sorted numbers into main array
        ar[begin + i] = tmp[i];
    
    delete [] tmp;
}

void mergeSort( int *ar, int begin, int end ){

    if( begin == end )              // Termination case for recursive function
        return;
    
    int middle = (begin + end) / 2; // Finding middle point of current subarray

    mergeSort(ar, begin, middle);   // Sorting the left half
    mergeSort(ar, middle + 1, end); // Sorting the right half
    merge(ar, begin, end);          // Merging two halves
}

int main(){                     // An example main program for testing Merge Sort

    int N, *ar;

    scanf("%d", &N);            // Reading number of elements

    ar = new int[N];            // Allocating space for elements

    for( int i=0 ; i<N ; i++ )  // Reading elements
        scanf("%d", ar+i);
    
    mergeSort(ar, 0, N-1);

    puts("Sorted array:");      // Printing output

    for( int i=0 ; i<N ; i++ )
        printf("%d ", ar[i]);
    
    puts("");
    delete [] ar;

    return 0;
}