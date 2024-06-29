vector<vector<int>> find_scc(const vector<vector<int>> &g) {
  int n = (int) g.size();
  vector<int> tin(n), low(n), in_stack(n), stack;
  vector<vector<int>> res;
  int timer = 0;
  
  function<void(int)> dfs = [&](int v) {
    tin[v] = low[v] = ++timer;
    stack.push_back(v);
    in_stack[v] = true;
    for (int u : g[v]) {
      if (!tin[u]) {
        dfs(u);
        low[v] = min(low[v], low[u]);
      } else if (in_stack[u]) {
        low[v] = min(low[v], tin[u]);
      }
    }
    if (low[v] == tin[v]) {
      vector<int> r;
      while (true) {
        int u = stack.back();
        stack.pop_back();
        r.push_back(u);
        in_stack[u] = false;
        if (u == v) break;
      }
      res.push_back(r);
    }
  };

  for (int i = 0; i < n; i++) {
    if (tin[i] == 0) {
      dfs(i);
    }
  }

  return res;
}