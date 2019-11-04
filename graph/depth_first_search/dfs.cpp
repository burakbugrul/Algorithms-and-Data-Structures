/*
    Burak Bugrul
    Depth First Search Algorithm O(V + E)
*/

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1e5;

int V, E;

bool visited[MAX];

vector<int> graph[MAX];

void dfs( int node ) {

    visited[node] = true;

    for( int adj : graph[node]) {
        if (!visited[adj]) {
            dfs(adj);
        }
    }
}

int main() {                                    // A simple main program to test the algorithm

    scanf("%d%d", &V, &E);                      // V is number of vertexes, E is number of edges

    for( int first, second, i=0 ; i<E ; i++ ) {

        scanf("%d%d", &first, &second);

        graph[first].push_back(second);
        graph[second].push_back(first);
    }

    for( int i=1 ; i <= V ; i++ ) {
        if (!visited[i]) {                      // Found a component/
            dfs(i);
        }
    }

    return 0;
}