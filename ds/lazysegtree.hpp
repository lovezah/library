template <class X, X(* op)(X, X), X (*e)(), class F, X (*mapping)(X, F), F (*composition)(F, F), F (*id)()>
struct lazysegtree {
  int n;
  vector<X> v;
  vector<F> lz;
  lazysegtree(int m = 0) {
    init(vector<X>(m, e()));
  }
  lazysegtree(const vector<X> &dat) {
    init(dat);
  }
  void init(vector<X> dat) {
    n = len(dat);
    v.assign(4 << (int)(log2(n)), e());
    lz.assign(4 << (int)(log2(n)), id());
    function<void(int, int, int)> build = [&](int p, int l, int r) {
      if (r - l == 1) {
        v[p] = dat[l];
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
  void all_apply(int p, F f) {
    v[p] = mapping(v[p], f);
    lz[p] = composition(lz[p], f);
  }
  void push(int p) {
    all_apply(p * 2, lz[p]);
    all_apply(p * 2 + 1, lz[p]);
    lz[p] = id();
  }
  void set(int p, int l, int r, int x, X c) {
    if (r - l == 1) {
      v[p] = c;
      return;
    }
    push(p);
    int m = (l + r) / 2;
    if (x < m) set(p * 2, l, m, x, c);
    else set(p * 2 + 1, m, r, x, c);
    pull(p);
  }
  void apply(int p, int l, int r, int x, F f) {
    if (r - l == 1) {
      all_apply(p, f);
      return;
    }
    push(p);
    int m = (l + r) / 2;
    if (x < m) apply(p * 2, l, m, x, f);
    else apply(p * 2 + 1, m, r, x, f);
    pull(p);
  }
  void apply(int p, int l, int r, int ql, int qr, F f) {
    if (qr <= l || r <= ql) return;
    if (ql <= l && r <= qr) {
      all_apply(p, f);
      return;
    }
    push(p);
    int m = (l + r) / 2;
    apply(p * 2, l, m, ql, qr, f);
    apply(p * 2 + 1, m, r, ql, qr, f);
    pull(p);
  }
  X get(int p, int l, int r, int x) {
    if (r - l == 1) {
      return v[p];
    }
    push(p);
    int m = (l + r) / 2;
    if (x < m) return get(p * 2, l, m, x);
    else return get(p * 2 + 1, m, r, x);
  }
  X query(int p, int l, int r, int ql, int qr) {
    if (qr <= l || r <= ql) return e();
    if (ql <= l && r <= qr) return v[p];
    push(p);
    int m = (l + r) / 2;
    return op(query(p * 2, l, m, ql, qr), query(p * 2 + 1, m, r, ql, qr));
  }
  template <class F>
  int find_first(int p, int l, int r, int ql, int qr, F &f) {
    if (qr <= l || r <= ql) return -1;
    if (ql <= l && r <= qr && !f(v[p])) return -1;
    if (r - l == 1) return l;
    push(p);
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
    push(p);
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
  void apply(int p, F f) {
    assert(0 <= p && p < n);
    apply(1, 0, n, p, f);
  }
  void apply(int l, int r, F f) {
    assert(0 <= l && l < r && r <= n);
    apply(1, 0, n, l, r, f);
  }
  X get(int p) {
    assert(0 <= p && p < n);
    return get(1, 0, n, p);
  }
  X query(int l, int r) {
    assert(0 <= l && l < r && r <= n);
    return query(1, 0, n, l, r);
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
