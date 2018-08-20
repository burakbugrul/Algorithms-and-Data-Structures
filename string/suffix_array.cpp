/*
    Burak Bugrul
    Suffix Array O(n lg^2 n)
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN = 1e6;   // Maximum string length

int N;                  // Length of initial string
int currentLength;      // Current length for comparisons

int sum[MAXN];          // Helper prefix sum array for finding new positions
int position[MAXN];     // Current position of suffixes
int suffixArray[MAXN];  // Current suffix array

char ar[MAXN];          // Initial string

inline bool suffixCompare( const int &first, const int &second){

    if( position[first] != position[second] )
        return position[first] < position[second];
    
    if( first + currentLength < N && second + currentLength < N )
        return position[first + currentLength] < position[second + currentLength];
    
    return first > second;
}

inline void buildSuffixArray(){

    N = strlen(ar);
    currentLength = 1;

    for( int i=0 ; i<N ; i++ ){
        suffixArray[i] = i;     // suffix started at ith position
        position[i] = ar[i];    // ith position has character ar[i] now
    }

    while( sum[N-1] != N-1 ){
        
        sort(suffixArray, suffixArray + N, suffixCompare);

        for( int i=0 ; i<N-1 ; i++ )
            sum[i+1] = sum[i] + suffixCompare(suffixArray[i], suffixArray[i+1]); // Finding if suffixArray[i] and suffixArray[i+1] different or not
        
        for( int i=0 ; i<N ; i++ )
            position[suffixArray[i]] = sum[i]; // Adjusting position array according to new places in suffixArray

        currentLength <<= 1; // Making currentLength double in order to use suffixCompare function properly
    }
}

int main(){

    scanf("%s", ar);

    buildSuffixArray();

    for( int i=0 ; i<N ; i++ ) // Printing suffix order
        cout << suffixArray[i] << " ";
    
    cout << endl;

    for( int i=0 ; i<N ; i++ ){ // Printing suffixes

        cout << suffixArray[i] << " ";

        for( int j=suffixArray[i] ; j<N ; j++ )
            cout << ar[j];
        
        cout << endl;
    }

    return 0;
}