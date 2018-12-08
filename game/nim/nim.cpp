#include <cstdio>

int main(){

    int n, pile, result = 0;

    scanf("%d", &n);

    while(n--){
        scanf("%d", &pile);
        result ^= pile;
    }

    printf("%s\n", result ? "First" : "Second");
    return 0;
}