template <typename T = long long>
struct flow {
  struct edge {
    int to;
    T cap;
    edge(int _to, T _cap) : to(_to), cap(_cap) {}
  };
  int n;
  vector<int> cur, lev;
  vector<edge> edges;
  vector<vector<int>> g;
  flow(int _n) : n(_n) {
    g.resize(n);
  }
  void add(int from, int to, T c) {
    g[from].push_back((int) edges.size());
    edges.emplace_back(to, c);
    g[to].push_back((int) edges.size());
    edges.emplace_back(from, 0);
  }
  bool bfs(int s, int t) {
    lev.assign(n, -1);
    queue<int> que;
    que.push(s);
    lev[s] = 0;
    while (!que.empty()) {
      int u = que.front();
      que.pop();
      for (int i : g[u]) {
        const auto &[v, c] = edges[i];
        if (c > 0 && lev[v] == -1) {
          lev[v] = lev[u] + 1;
          if (v == t) {
            return true;
          }
          que.push(v);
        }
      }
    }
    return false;
  }
  T dfs(int u, int t, T f) {
    if (u == t) {
      return f;
    }
    auto r = f;
    for (int &i = cur[u]; i < (int) g[u].size(); i++) {
      const int j = g[u][i];
      const auto &[v, c] = edges[j];
      if (c > 0 && lev[v] == lev[u] + 1) {
        auto a = dfs(v, t, std::min(r, c));
        edges[j].cap -= a;
        edges[j ^ 1].cap += a;
        r -= a;
        if (r == 0) {
          return f;
        }
      }
    }
    return f - r;
  }
  T dinic(int s, int t) {
    T ans = 0;
    while (bfs(s, t)) {
      cur.assign(n, 0);
      ans += dfs(s, t, std::numeric_limits<T>::max());
    }
    return ans;
  }
};