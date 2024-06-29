template <typename T, bool maximum = false>
struct sparse_table {
  static int highest_bit(int x) {
    return (x == 0 ? -1 : 31 - __builtin_clz(x));
  }
  int n;
  vector<T> vals;
  vector<vector<int>> f;
  
  sparse_table(const vector<T> &_vals = {}) {
    init(_vals);
  }
  int better_index(int x, int y) {
    if (maximum) return (vals[x] < vals[y] ? y : x);
    else return (vals[x] < vals[y] ? x : y);
  }
  void init(const vector<T> &_vals) {
    vals = _vals;
    n = (int) vals.size();
    int level = highest_bit(n) + 1;
    f = vector<vector<int>>(level, vector<int>(n));
    for (int i = 0; i < n; i++) {
      f[0][i] = i;
    }
    for (int b = 1; b < level; b++) {
      for (int i = 0; i + (1 << b) - 1 < n; i++) {
        f[b][i] = better_index(f[b - 1][i], f[b - 1][i + (1 << (b - 1))]);
      }
    }
  }
  int query_index(int x, int y) {
    assert(0 <= x && x < y && y <= n);
    int level = highest_bit(y - x);
    return better_index(f[level][x], f[level][y - (1 << level)]);
  }
  T query_value(int x, int y) {
    return vals[query_index(x, y)];
  }
};
