// https://www.acmicpc.net/problem/11053
#include <stdio.h>
#include <algorithm>
using namespace std;

int memo[1000];
int arr[1000];
int N;

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; ++i) scanf("%d", arr + i);
    int result = 0;
    for(int k=0; k<N; ++k) {
        memo[k] = 1;
        for(int i=0; i<k; ++i) {
            if(arr[i] < arr[k])
                memo[k] = max(memo[k], memo[i] + 1);
        }
        result = max(result, memo[k]);
    }
    printf("%d\n", result);
}