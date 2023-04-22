#include <iostream>
#include <list>
#include <string>
#include <sstream>
using namespace std;

list<int> getList(string &&arr) {
  string token;
  stringstream ss(arr);
  list<int> l;
  while(getline(ss, token, ',')) {
    l.push_back(stoi(token));
  }
  return l;
}

int main() {
  int T, N, dir, err;
  string qry, arr;
  cin >> T;
  while(T--) {
    dir = 1;
    err = false;
    cin >> qry >> N >> arr;
    auto l = getList(arr.substr(1, arr.length() - 2));
    for(int i=0; i<qry.length(); ++i) {
      if(qry[i] == 'R') 
        dir *= -1;
      else {
        if(l.empty()) {
          err = true;
          break;
        }
        if(dir > 0) l.pop_front();
        else l.pop_back();
      }
    }
    if(err) 
      printf("error\n");
    else {
      int cnt = 0;
      if(dir < 0) l.reverse();
      printf("[");
      for(auto e : l) {
        cnt++;
        if(cnt < l.size()) printf("%d,", e);
        else printf("%d", e);
      }
      printf("]\n");
    }
  }
}