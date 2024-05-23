template <typename T>
struct fenwick {
  int n;
  vector<T> fen;
  fenwick(int _n) : n(_n) {
    fen.resize(n);
  }
  void modify(int x, T v) {
    assert(0 <= x && x < n);
    for (int i = x + 1; i <= n; i += i & -i) {
      fen[i - 1] += v;
    }
  }
  T query(int r) {
    T res = 0;
    for (int i = r; i > 0; i -= i & -i) {
      res += fen[i - 1];
    }
    return res;
  }
  T query(int l, int r) {
    assert(0 <= l && l <= r && r <= n);
    return query(r) - query(l);
  }
  int kth(const T &k) {
    int x = 0;
    T res = 0;
    for (int d = 1 << (int) log2(n); d > 0; d /= 2) {
      if (x + d <= n && res + fen[x + d - 1] <= k) {
        x += d;
        res += fen[x - 1];
      }
    }
    return x;
  }
};