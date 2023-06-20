#include <stdio.h>
#include <string.h>

int R, C, T, m[50][50], r[50][50], di[4] = {-1, 1, 0, 0}, dj[4] = {0, 0, -1, 1}, ci;

int valid(int i, int j) {
    return 0 <= i && i < R && 0 <= j && j < C;
}

void diffuse() {
    memcpy(r, m, sizeof(r));
    for(int i=0; i<R; ++i) {
        for(int j=0; j<C; ++j) {
            if(m[i][j] == -1) continue;
            for(int k=0; k<4; ++k) {
                int y = i + di[k], x = j + dj[k];
                if(valid(y, x) && m[y][x] > 0) {
                    r[i][j] += m[y][x] / 5;
                    r[y][x] -= m[y][x] / 5;
                }
            } 
        }
    }
    memcpy(m, r, sizeof(m));
}

void flow() {
    for(int i=ci-1; i>0; --i) m[i][0] = m[i-1][0];
    for(int i=ci+2; i<R-1; ++i) m[i][0] = m[i+1][0];
    for(int j=0; j<C-1; ++j) {
        m[0][j] = m[0][j+1];
        m[R-1][j] = m[R-1][j+1];
    }
    for(int i=0; i<ci; ++i) m[i][C-1] = m[i+1][C-1];
    for(int i=R-1; i>ci+1; --i) m[i][C-1] = m[i-1][C-1];
    for(int j=C-1; j>1; --j) {
        m[ci][j] = m[ci][j-1];
        m[ci+1][j] = m[ci+1][j-1];
    }
    m[ci][1] = m[ci+1][1] = 0;
}

int main() {
    scanf("%d%d%d", &R, &C, &T);
    for(int i=0; i<R; ++i) {
        for(int j=0; j<C; ++j) scanf("%d", &m[i][j]);
    }
    for(int i=0; i<R; ++i) {
        if(m[i][0] == -1) {
            ci = i; break;
        }
    }
    while(T--) {
        diffuse();
        flow();
    }
    int c=0;
    for(int i=0; i<R; ++i) {
        for(int j=0; j<C; ++j) c += m[i][j] > 0 ? m[i][j] : 0;
    }
    printf("%d\n", c);
}