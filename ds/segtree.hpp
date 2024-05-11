#pragma once

template <class X, X(* op)(X, X), X (*e)()>
struct segtree {
  int n;
  vt<X> v;
  segtree(int m = 0) {
    init(vt<X>(m, e()));
  }
  segtree(const vt<X> &vv) {
    init(vv);
  }
  void init(vt<X> vv) {
    n = len(vv);
    v.assign(4 << (int)(log2(n)), e());
    function<void(int, int, int)> build = [&](int p, int l, int r) {
      if (r - l == 1) {
        v[p] = vv[l];
        return;
      }
      int m = (l + r) / 2;
      build(p * 2, l, m);
      build(p * 2 + 1, m, r);
      pull(p);
    };
    build(1, 0, n);
  }
  void pull(int p) {
    v[p] = op(v[p * 2], v[p * 2 + 1]);
  }
  void set(int p, int l, int r, int x, X c) {
    if (r - l == 1) {
      v[p] = c;
      return;
    }
    int m = (l + r) / 2;
    if (x < m) set(p * 2, l, m, x, c);
    else set(p * 2 + 1, m, r, x, c);
    pull(p);
  }
  X get(int p, int l, int r, int x) {
    if (r - l == 1) {
      return v[p];
    }
    int m = (l + r) / 2;
    if (x < m) return get(p * 2, l, m, x);
    else return get(p * 2 + 1, m, r, x);
  }
  X prod(int p, int l, int r, int ql, int qr) {
    if (qr <= l || r <= ql) return e();
    if (ql <= l && r <= qr) return v[p];
    int m = (l + r) / 2;
    return op(prod(p * 2, l, m, ql, qr), prod(p * 2 + 1, m, r, ql, qr));
  }
  template <class F>
  int find_first(int p, int l, int r, int ql, int qr, F &f) {
    if (qr <= l || r <= ql) return -1;
    if (ql <= l && r <= qr && !f(v[p])) return -1;
    if (r - l == 1) return l;
    int m = (l + r) / 2;
    int res = find_first(p * 2, l, m, ql, qr, f);
    if (res == -1) {
      res = find_first(p * 2 + 1, m, r, ql, qr, f);
    }
    return res;
  }
  template <class F>
  int find_last(int p, int l, int r, int ql, int qr, F &f) {
    if (qr <= l || r <= ql) return -1;
    if (ql <= l && r <= qr && !f(v[p])) return -1;
    if (r - l == 1) return l;
    int m = (l + r) / 2;
    int res = find_last(p * 2 + 1, m, r, ql, qr, f);
    if (res == -1) {
      res = find_last(p * 2, l, m, ql, qr, f);
    }
    return res;
  }
  // public 
  void set(int p, X x) {
    assert(0 <= p && p < n);
    set(1, 0, n, p, x);
  }
  X get(int p) {
    assert(0 <= p && p < n);
    return get(1, 0, n, p);
  }
  X prod(int l, int r) {
    assert(0 <= l && l < r && r <= n);
    return prod(1, 0, n, l, r);
  }
  template <class F>
  int find_first(int l, int r, F &f) {
    assert(0 <= l && l < r && r <= n);
    return find_first(1, 0, n, l, r, f);
  }
  template <class F>
  int find_last(int l, int r, F &f) {
    assert(0 <= l && l < r && r <= n);
    return find_last(1, 0, n, l, r, f);
  }
};

ll op(ll x, ll y) {
  return max(x, y);
}
ll e() {
  return -infty<ll>;
}
