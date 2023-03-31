// https://www.acmicpc.net/problem/9251
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int memo[1001][1001];
char a[1002], b[1002];
int alen, blen;
int main() {
    scanf("%s", a+1); alen = strlen(a+1);
    scanf("%s", b+1); blen = strlen(b+1);
    for(int i=1; i<=alen; ++i) {
        for(int j=1; j<=blen; ++j) {
            if(a[i] == b[j]) memo[i][j] = memo[i-1][j-1] + 1;
            else memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
        }
    }
    printf("%d\n", memo[alen][blen]);
}