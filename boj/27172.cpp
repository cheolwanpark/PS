#include <stdio.h>

int main() {
    int N, card[100000], score[1000001]={0};
    bool exist[1000001]={0};
    scanf("%d", &N);
    for(int i=0; i<N; ++i) {
        scanf("%d", card+i);
        exist[card[i]] = 1;
    }

    for(int i=0; i<N; ++i) {
        for(int j=card[i]*2; j<=1000000; j+=card[i]) {
            if(exist[j]) {
                score[card[i]] += 1;
                score[j] -= 1;
            }
        }
    }
    for(int i=0; i<N; ++i) printf("%d ", score[card[i]]);
    printf("\n");
}