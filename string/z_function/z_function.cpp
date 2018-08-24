/*
    Burak Bugrul
    Z-Function O(N)
*/

#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN = 1e5;

int N;          // Length of initial string
int z[MAXN];    // Z array, z[i] holds maximum length we can match with prefix of string s starting from ith indice

char s[MAXN];   // Initial string

inline void z_function( char *s, int N ){

    int l = 0, r = 0;                                   // left and right boundaries of current prefix match

    for (int i = 1; i < N; i++){

        z[i] = max(0, min(z[i - l], r - i + 1));        // We can use previously calculated values for new z[i] value, but we can not go beyond right boundary without checking values

        while (i + z[i] < N && s[i + z[i]] == s[z[i]]){ // Checking values beyond right boundary in a simple way
            l = i;                                      // New boundary starting point
            r = i + z[i];                               // New boundary ending point
            z[i]++;                                     // Checked a new value for z[i]
        }
    }
}

int main(){

    scanf("%s", s);
    N = strlen(s);

    z_function(s, N);

    cout << "Z array:\n";

    for( int i=0 ; i<N ; i++ )
        cout << z[i] << " ";
    
    cout << endl << endl;
    return 0;
}