/*
    Burak Bugrul
    Suffix Array O(N * lg^2(N))
    LCP Array O(N)
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN = 1e6;   // Maximum string length

int N;                  // Length of initial string
int currentLength;      // Current length for comparisons

int lcp[MAXN];          // Longest Common Prefixes array
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
        position[i] = ar[i];    // will be used in comparisons
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

// Kasai's Algorithm
inline void buildLCPArray(){

    int current = 0;    // Denotes number of current mathing characters in two consecutive suffixes

    for( int i=0 ; i<N ; i++ )
        if( position[i] != N-1 ){

            int j = suffixArray[position[i] + 1];

            while( ar[i + current] == ar[j + current] )
                current++;
            
            lcp[position[i]] = current;

            if( current )
                current--;
        }
}

int main(){

    scanf("%s", ar);

    buildSuffixArray();
    buildLCPArray();

    cout << "Suffix Array:\n";

    for( int i=0 ; i<N ; i++ )
        cout << suffixArray[i] << " ";
    
    cout << endl << endl << "Suffixes in sorted order:\n";

    for( int i=0 ; i<N ; i++ ){

        cout << suffixArray[i] << " ";

        for( int j=suffixArray[i] ; j<N ; j++ )
            cout << ar[j];
        
        cout << endl;
    }
    
    cout << endl << "LCP array:\n";

    for( int i=0 ; i<N ; i++ )
        cout << lcp[i] << " ";
    
    cout << endl << endl;
    return 0;
}