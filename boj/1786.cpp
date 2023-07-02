#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_LEN = 1000000;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    string T, P;
    getline(cin, T);
    getline(cin, P);
    vector<int> pi(P.size(), 0);
    vector<int> found;
    for(int l=0, r=1; r<P.size(); ++r) {
        while(l > 0 && P[l] != P[r]) l = pi[l-1];
        if(P[l] == P[r]) ++l;
        pi[r] = l;
    }
    for(int i=0, j=0; i<T.size(); ++i) {
        while(j < P.size() && i+j < T.size() && T[i+j] == P[j]) ++j;
        if(j == P.size()) found.push_back(i+1);
        i += max(j - pi[j-1] - 1, 0);
        j = pi[j-1];
    }
    printf("%u\n", found.size());
    for(auto i : found) printf("%d ", i);
    printf("\n");
}