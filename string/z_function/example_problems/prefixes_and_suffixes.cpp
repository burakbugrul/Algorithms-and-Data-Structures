/*
    Burak Bugrul    
    Problem link: http://codeforces.com/contest/432/problem/D
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

const int MAXN = 1e5 + 15;

int N;
int z[MAXN];
int cnt[MAXN];

char s[MAXN];

vector<ii> ans;

int main(){

    scanf("%s", s);

    N = strlen(s);

    int x = 0, y = 0;

    for (int i = 1; i < N; i++){

        z[i] = max(0, min(z[i - x], y - i + 1));

        while (i + z[i] < N && s[i + z[i]] == s[z[i]]){
            x = i;
            y = i + z[i];
            z[i]++;
        }

        cnt[z[i]]++;
    }

    cnt[N]++;

    for (int i = N - 1; i; i--)
        cnt[i] += cnt[i + 1];

    for (int i = 1; i <= N; i++)
        if (z[N - i] == i)
            ans.push_back(ii(i, cnt[i]));

    ans.push_back(ii(N, 1));

    printf("%d\n", (int)ans.size());

    for (ii p : ans)
        printf("%d %d\n", p.first, p.second);

    return 0;
}