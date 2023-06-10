#include <string>
#include <iostream>
using namespace std;

int isSub(char *s, int top, string &b) {
    for(int i=1; i<=b.size(); ++i) {
        if(s[top-i] != b[b.size()-i]) return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string a, b;
    char s[1000000];
    int top = 0;
    cin >> a >> b;
    for(int i=0; i<a.size(); ++i) {
        s[top++] = a[i];
        if(isSub(s, top, b)) {
            top -= b.size();
        }
    }
    if(top > 0) cout << string(s, s+top) << "\n";
    else cout << "FRULA\n";
}