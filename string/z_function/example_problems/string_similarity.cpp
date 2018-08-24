/*
    Burak Bugrul
    Problem link: https://www.hackerrank.com/challenges/string-similarity/problem
*/

#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN = 1e5 + 15;

int T, N;
int z[MAXN];

char s[MAXN];

int main(){

    scanf("%d", &T);

    while (T--){

        int l = 0, r = 0;
        long long int res = 0LL;

        scanf("%s", s);
        N = strlen(s);

        for (int i = 1; i < N; i++){

            z[i] = max(0, min(r - i + 1, z[i - l]));

            while (s[i + z[i]] == s[z[i]] && i + z[i] < N){
                r = i + z[i];
                l = i;
                z[i]++;
            }
        }

        for (int i = 1; i < N; i++)
            res += z[i];

        printf("%lld\n", res + N);
    }

    return 0;
}