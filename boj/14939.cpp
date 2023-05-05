#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

void flip(int y, int x, char b[][11]) {
    if(y < 0 || y >= 10 || x < 0 || x >= 10) return;
    b[y][x] = b[y][x] == '#' ? 'O' : '#';
}
void set(int y, int x, char b[][11]) {
    flip(y-1, x, b);
    flip(y, x-1, b);
    flip(y, x, b);
    flip(y, x+1, b);
    flip(y+1, x, b);
}

int main() {
    char board[10][11];
    char b[10][11];
    for(int i=0; i<10; ++i) scanf("%s", board[i]);

    int r = 101;
    for(int mask=0; mask<1024; ++mask) {
        int cnt=0;
        memcpy(b, board, sizeof(board));
        for(int i=0; i<10; ++i) {
            if(mask & (1 << i)) {
                set(0, i, b);
                cnt++;
            }
        }
        for(int i=1; i<10; ++i) {
            for(int j=0; j<10; ++j) {
                if(b[i-1][j] == 'O') {
                    set(i, j, b);
                    cnt++;
                }
            }
        }
        for(int i=0; i<10; ++i) {
            if(b[9][i] == 'O') cnt=101;
        }
        r = min(r, cnt);
    }
    printf("%d\n", r == 101 ? -1 : r);
}