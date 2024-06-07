template <typename T> 
struct Edge {
  int from, to;
  T cost;
  int id;
};

template <typename T = int, bool directed = false>
struct graph {
  static constexpr bool is_directed = directed;
  int n, m;
  using cost_type = T;
  using edge_type = Edge<T>;
  vector<edge_type> edges;
  vector<vector<int>> g;

  graph(int _n) : n(_n), m(0) {
    g.resize(n);
  }

  void add(int from, int to, T cost = 1, int i = -1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    if (i == -1) i = m++;
    g[from].push_back((int) edges.size());
    edges.push_back(edge_type({from, to, cost, i}));
    if (!is_directed) {
      g[to].push_back((int) edges.size());
      edges.push_back(edge_type({to, from, cost, i}));
    }
  }
};
