#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include "misc/my_template.hpp"
#include "ds/union_find.hpp"

void solve() {
  ints(n, q);
  union_find uf(n);
  rep(q) {
    ints(t, u, v);
    if (t == 0) {
      uf.merge(u, v);
    } else print(uf[u] == uf[v] ? 1 : 0);
  }
}

int main() {
  SETIO();
  solve();
}