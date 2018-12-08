/*
    Burak Bugrul
    Kruskal's Algorithm O(E lg E + V alpha(V))
*/

#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

const int MAX = 1e5;

struct Edge{

    int a, b, length;

    inline bool operator < ( const Edge &other ) const {
        return length < other.length;
    }
};

int V, E;

int parent[MAX];

Edge edges[MAX];

int findParent( int node ){

    if( node == parent[node] )
        return node;
    
    return parent[node] = findParent(parent[node]); // Key part of this function, nex time this function called with same value, it will immediately call the same function with union represent(if it is not cahnged yet)
}

inline int kruskal(){

    for( int i=1 ; i<=V ; i++ )                                         // Setting every node as a separate union 
        parent[i] = i;

    sort(edges, edges + E);                                             // Sorting edges according to their weights

    int cnt = 0, cost = 0;                                              // cnt is for holding number of union merges, after V-1 merges there can be no more merges, cost is the total wieghts of edges included MST

    for( int i=0 ; i<E && cnt < V-1; i++ )
        if( findParent(edges[i].a) != findParent(edges[i].b) ){         // It means node a and node b are in different unions
            parent[findParent(edges[i].a)] = findParent(edges[i].b);    // Merging two unions
            cost += edges[i].length;                                    // Adding weight of current edge to cost
            cnt++;                                                      // Counting number of merges
        }
    
    return cost;
}

int main(){                                                             // A simple main program to test the algorithm

    scanf("%d%d", &V, &E);                                              // V is number of vertexes, E is number of edges

    for( int i=0 ; i<E ; i++ )
        scanf("%d%d%d", &edges[i].a, &edges[i].b, &edges[i].length);
    
    printf("%d\n", kruskal());
    return 0;
}