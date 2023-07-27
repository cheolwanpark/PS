#include <stdio.h>
#include <string.h>
#include <string>
#include <unordered_set>
using namespace std;

struct Node {
    Node *childs[26];
    bool last;
    Node(): last(false) { 
        memset(childs, 0, sizeof(childs)); 
    }
    ~Node() { 
        for(auto *child : childs) 
            if(child) delete child; 
    }
    Node *get(char c) {
        return childs[c-'a'];
    }
    Node *set(char c) {
        if(get(c)) return get(c);
        return childs[c-'a'] = new Node();
    }
};

int N, C, Q;
char s[2001];
Node root;
unordered_set<string> nicknames;

void assign(char *s, int len) {
    auto *cur = &root;
    for(int i=0; i<len; ++i) cur = cur->set(s[i]);
    cur->last = true;
}

bool isMatch(const string &s) {
    auto *cur = &root;
    for(int i=0; i<s.length(); ++i) {
        if(!cur->get(s[i])) return false;
        cur = cur->get(s[i]);
        if(cur->last && nicknames.find(s.substr(i+1, s.length()-i-1)) != nicknames.end()) return true;
    }
    return false;
}

int main() {
    scanf("%d%d", &C, &N);
    for(int i=0; i<C; ++i) {
        scanf("%s", s);
        assign(s, strlen(s));
    }
    for(int i=0; i<N; ++i) {
        scanf("%s", s);
        nicknames.insert(string(s));
    }
    scanf("%d", &Q);
    for(int i=0; i<Q; ++i) {
        scanf("%s", s);
        printf("%s\n", isMatch(string(s)) ? "Yes" : "No");
    }
}