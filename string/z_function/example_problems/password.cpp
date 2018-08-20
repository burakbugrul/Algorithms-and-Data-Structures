/*
    Burak Bugrul
    Problem link: http://codeforces.com/contest/126/problem/B
*/

#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN = 1e6 + 16;

int N;
int cnt[MAXN];
int z[MAXN];

char s[MAXN];

int main(){

    scanf("%s", s);

    N = strlen(s);

    int x = 0, y = 0, ind = 0;

    for (int i = 1; i < N; i++){

        z[i] = max(0, min(z[i - x], y - i + 1));

        while (i + z[i] < N && s[i + z[i]] == s[z[i]]){
            x = i;
            y = i + z[i];
            z[i]++;
        }

        cnt[z[i]]++;
    }

    for (int i = N - 1; i >= 0; i--)
        cnt[i] += cnt[i + 1];

    for (int i = N - 1; i > 0; i--)
        if (z[N - i] == i && cnt[i] > 1){

            for (int j = 0; j < i; j++)
                printf("%c", s[j]);

            puts("");
            return 0;
        }

    puts("Just a legend");
    return 0;
}