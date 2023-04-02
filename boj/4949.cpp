#include <iostream>
#include <string>
#include <stack>
using namespace std;

int isBalanced(string &in) {
  stack<char> s;
  for(size_t i=0; i<in.length(); ++i) {
    if(in[i] == '(' || in[i] == '[') {
      s.push(in[i]);
    } else if(in[i] == ')') {
      if(s.empty() || s.top() != '(') return false;
      s.pop();
    } else if(in[i] == ']') {
      if(s.empty() || s.top() != '[') return false;
      s.pop();
    }
  }
  return s.empty();
}

int main() {
  while(true) {
    string in;
    getline(cin, in);
    if(in == ".") break;
    printf("%s\n", isBalanced(in) ? "yes" : "no");
  }
}