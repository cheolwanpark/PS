// https://www.acmicpc.net/problem/2263
#include <stdio.h>

struct node {
    int val;
    node *left;
    node *right;
};

node *build(int *in, int *post, int len) {
    if(len == 0) return NULL;
    else if(len == 1) return new node({in[0], NULL, NULL});
    int root = post[len-1];
    int leftN, rightN;
    for(int i=0; i<len; ++i) {
        if(in[i] == root) {
            leftN = i;
            break;
        }
    }
    rightN = len - leftN - 1;
    node *left = build(in, post, leftN);
    node *right = build(in+(leftN + 1), post+leftN, rightN);
    return new node({root, left, right});
}

void pre(node *root) {
    printf("%d ", root->val);
    if(root->left) pre(root->left);
    if(root->right) pre(root->right);
}
void clear(node *root) {
    if(root->left) clear(root->left);
    if(root->right) clear(root->right);
    delete root;
}

int in[100000], post[100000], N;

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; ++i) scanf("%d", in + i);
    for(int i=0; i<N; ++i) scanf("%d", post + i);
    node *tree = build(in, post, N);
    pre(tree); printf("\n"); clear(tree);
}