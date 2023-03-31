// https://www.acmicpc.net/problem/1991
#include <stdio.h>

struct Node {
    char name;
    Node *left;
    Node *right;
};

int N;
Node nodes[26];

Node *getNode(char name) {
    if(name == '.') return NULL;
    return &nodes[name - 'A'];
}

void pre(Node *node) {
    if(!node) return;
    printf("%c", node->name);
    pre(node->left);
    pre(node->right);
}

void in(Node *node) {
    if(!node) return;
    in(node->left);
    printf("%c", node->name);
    in(node->right);
}

void post(Node *node) {
    if(!node) return;
    post(node->left);
    post(node->right);
    printf("%c", node->name);
}

int main() {
    scanf("%d", &N);
    char name, left, right;
    for(int i=0; i<N; ++i) {
        scanf(" %c %c %c", &name, &left, &right);
        auto *node = getNode(name);
        node->name = name;
        node->left = getNode(left);
        node->right = getNode(right);
    }
    pre(nodes); printf("\n");
    in(nodes); printf("\n");
    post(nodes); printf("\n");
}