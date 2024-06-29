vector<int> find_bridge(const vector<vector<pair<int, int>>> &g) {
  int n = (int) g.size();
  vector<int> tin(n), low(n), in_stack(n), stack;
  vector<int> res;
  int timer = 0;
  
  function<void(int, int)> dfs = [&](int v, int pid) {
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
    if (low[v] == tin[v] && pid != -1) {
      res.push_back(pid);
    }
  };

  for (int i = 0; i < n; i++) {
    if (tin[i] == 0) {
      dfs(i, -1);
    }
  }

  return res;
}