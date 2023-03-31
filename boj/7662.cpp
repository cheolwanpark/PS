// https://www.acmicpc.net/problem/7662
#include <stdio.h>
#include <map>
#include <iterator>
using namespace std;

int main() {
    int T, k, n;
    char op[10];
    map<int, int> q;
    scanf("%d", &T);
    while(T--) {
        q.clear();
        scanf("%d", &k);
        for(int i=0; i<k; ++i) {
            scanf("%s%d", op, &n);
            if(op[0] == 'I') {
                auto iter = q.find(n);
                if(iter == q.end()) q.insert({n, 1});
                else iter->second += 1;
            } else if(op[0] == 'D' && !q.empty()) {
                auto iter = n == 1 ? prev(q.end()) : q.begin();
                iter->second -= 1;
                if(iter->second == 0) {
                    q.erase(iter);
                }
            }
        }
        if(q.empty()) {
            printf("EMPTY\n");
        } else {
            printf("%d %d\n", q.rbegin()->first, q.begin()->first);
        }
    }
}