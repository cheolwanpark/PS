#include <string>
#include <iostream>
#include <map>
using namespace std;

int main() {
    cin.tie(0);
	ios::sync_with_stdio(0);
    int N, M;
    string a, b;
    map<string, string> m;
    cin >> N >> M;
    for(int i=0; i<N; ++i) {
        cin >> a >> b;
        m.insert({a, b});
    }
    for(int i=0; i<M; ++i) {
        cin >> a;
        cout << m.find(a)->second << "\n";
    }
}