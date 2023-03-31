// https://www.acmicpc.net/problem/11725
#include <stdio.h>
#include <vector>
using namespace std;

int N;
vector<int> e[100001];
int p[100001];
char visit[100001];
void findParents(int root) {
    visit[root] = true;
    for(auto child : e[root]) {
        if(!visit[child]) {
            p[child] = root;
            findParents(child);
        }
    }
}

int main() {
    scanf("%d", &N);
    int a, b;
    for(int i=0; i<N-1; ++i) {
        scanf("%d%d", &a, &b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    findParents(1);
    for(int i=2; i<=N; ++i) {
        printf("%d\n", p[i]);
    }
}