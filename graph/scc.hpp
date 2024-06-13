template <typename GT>
vector<int> find_scc(const GT &g, int &cnt) {
  int n = g.n;
  cnt = 0;
  vector<int> done(n);
  vector<int> dfn(n);
  vector<int> bel(n);
  vector<int> stack;
  auto dfs = [&](auto self, int v) -> int {
    int low = dfn[v] = (int) stack.size();
    stack.push_back(v);
    for (const auto &i : g.g[v]) {
      int u = g.edges[i].to;
      if (!done[u]) low = min(low, !dfn[u] ? self(self, u) : dfn[u]);
    }
    if (low == dfn[v]) {
      vector<int> who{stack.begin() + low, stack.end()};
      for (int w : who) done[w] = true, bel[w] = cnt;
      stack.resize(low);
      ++cnt;
    }
    return low;
  };
  for (int i = 0; i < n; i++) {
    if (!done[i]) {
      dfs(dfs, i);
    }
  }
  return bel;
}