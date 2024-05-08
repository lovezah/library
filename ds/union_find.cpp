#pragma once

struct union_find {
  int n, comp;
  vt<int> p;
  union_find(int m = 0) {
    init(m);
  }
  void init(int m) {
    n = m;
    comp = m;
    p.assign(n, -1);
  }
  void reset() { init(n); }
  int operator[](int x) {
    while (p[x] >= 0) {
      if (p[p[x]] >= 0) p[x] = p[p[x]];
      x = p[x];
    }
    return x;
  }
  bool merge(int x, int y) {
    x = (*this)[x], y = (*this)[y];
    if (x == y) return false;
    if (-p[x] < -p[y]) swap(x, y);
    p[x] += p[y];
    p[y] = x;
    comp--;
    return true;
  }
  ll size(int x) {
    return -p[(*this)[x]];
  }
  vt<int> get_all() {
    vt<int> par(n);
    rep(i, n) par[i] = (*this)[i];
    return par;
  }
};