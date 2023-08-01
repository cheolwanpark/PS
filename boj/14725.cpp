#include <stdio.h>
#include <map>
#include <string>
using namespace std;

struct Node {
    map<string, Node*> childs;
    ~Node() {
        for(auto iter : childs) delete iter.second;
    }
    Node *set(const string &s) {
        auto find = childs.find(s);
        if(find != childs.end()) return find->second;
        return childs[s] = new Node();
    }
    void print(int depth) {
        string prefix = "";
        for(int i=0; i<depth; ++i) prefix += "--";
        for(auto iter : childs) {
            printf("%s%s\n", prefix.c_str(), iter.first.c_str());
            iter.second->print(depth+1);
        }
    }
};

char in[16];
int N, K;

int main() {
    Node *root = new Node();
    scanf("%d", &N);
    for(int i=0; i<N; ++i) {
        scanf("%d", &K);
        auto *cur = root;
        for(int j=0; j<K; ++j) {
            scanf("%s", in);
            cur = cur->set(string(in));
        }
    }
    root->print(0);
    delete root;
}