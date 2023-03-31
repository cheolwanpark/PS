// https://www.acmicpc.net/problem/1918
#include <stdio.h>
#include <string.h>

int oporder(char op) {
    if(op == '+' || op == '-') return 1;
    else if(op == '*' || op == '/') return 2;
    else if(op == '(' || op == ')') return 3;
    return 0;
}

int main() {
    char in[101]; int len;
    scanf("%s", in); len = strlen(in);
    char s[101]; int top = -1;
    for(int i=0; i<len; ++i) {
        // printf("(%c %d)\n", in[i], oporder(in[i]));
        if(oporder(in[i]) == 0) {
            printf("%c", in[i]);
        } else if(in[i] == ')') {
            while(top >= 0) {
                auto op = s[top--];
                if(op == '(') break;
                printf("%c", op);
            }
        } else {
            while(top >= 0 && s[top] != '(' && oporder(s[top]) >= oporder(in[i])) {
                printf("%c", s[top--]);
            }
            s[++top] = in[i];
        }
    }
    while(top >= 0) {
        printf("%c", s[top--]);
    }
    printf("\n");
}