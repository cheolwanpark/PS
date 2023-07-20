#include <stdio.h>
#include <vector>
#include <string>
#include <string.h>
using namespace std;

struct Nd {
    int n;
    Nd *chd[27];

    Nd():n(0) {
        memset(chd, 0, sizeof(chd));
    }

    ~Nd() {
        for(int i=0; i<27; ++i) {
            if(chd[i]) delete chd[i];
        }
    }

    Nd *get(char c) {
        return chd[c-'a'];
    }

    Nd *add(char c) {
        if(!get(c)) {
            ++n;
            chd[c-'a'] = new Nd();
        }
        return get(c);
    }
};

const int END = 'z'+1;

int N;
char s[81];

int main() {
    while(scanf("%d", &N) != EOF) {
        Nd *root = new Nd(), *cur;
        int total = 0;
        vector<string> v;
        for(int i=0; i<N; ++i) {
            scanf("%s", s);
            v.push_back(string(s));
            cur = root;
            for(auto c : v.back()) cur = cur->add(c);
            cur->add(END);
        }
        for(auto &e : v) {
            cur = root;
            for(auto c : e) {
                if(cur == root || cur->n > 1) ++total;
                cur = cur->get(c);
            }
        }
        delete root;
        printf("%.2f\n", 1.0*total/v.size());
    }
}