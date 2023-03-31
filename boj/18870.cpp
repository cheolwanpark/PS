// https://www.acmicpc.net/problem/18870
#include <stdio.h>
#include <map>
using namespace std;

map<int, int> nums;
int in[1000000];
int N;

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; ++i) {
        scanf("%d", in + i);
        nums.insert({in[i], 0});
    }
    int count = 0;
    for(auto it=nums.begin(); it!=nums.end(); ++it) {
        it->second = count++;
    }
    for(int i=0; i<N; ++i) {
        printf("%d ", nums[in[i]]);
    }
    printf("\n");
}