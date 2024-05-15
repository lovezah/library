#pragma once

struct union_find {
  int n, comp;
  vector<int> p;
  union_find(int m = 0) : n(m) {
    p.assign(n, -1);
  }
  int get(int x) {
    while (p[x] >= 0) {
      if (p[p[x]] >= 0) p[x] = p[p[x]];
      x = p[x];
    }
    return x;
  }
  bool merge(int x, int y) {
    x = get(x), y = get(y);
    if (x == y) return false;
    if (-p[x] < -p[y]) swap(x, y);
    p[x] += p[y];
    p[y] = x;
    comp--;
    return true;
  }
  int size(int x) {
    x = get(x);
    return -p[x];
  }
};
