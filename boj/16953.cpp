#include <stdio.h>
#include <queue>
#include <map>
using namespace std;

typedef long long ll;

ll A, B;
queue<ll> q;
map<ll, int> m;

void push(ll n, int c) {
    if(n <= B && m.find(n) == m.end()) {
        q.push(n);
        m[n] = c;
    }
}

int main() {
    scanf("%lld%lld", &A, &B);
    m.insert({A, 1});
    q.push(A);
    while(!q.empty()) {
        auto n = q.front(); q.pop();
        auto c = m[n];
        if(n == B) break;
        push(n*2, c+1);
        push(n*10+1, c+1);
    }
    printf("%d\n", m.find(B) != m.end() ? m[B] : -1);
}