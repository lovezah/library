#pragma once

template <typename T> 
struct Edge {
  int from, to;
  T cost;
  int id;
};

template <typename T = ll, bool directed = false>
struct Graph {
  static constexpr bool is_directed = directed;
  bool prepared;
  int n, m;
  using cost_type = T;
  using edge_type = Edge<T>;
  vt<edge_type> edges;
  vt<int> indptr;
  vt<edge_type> csr_edges;

  class outgoing_edges {
   private:
    const Graph* G;
    int l, r;

   public:
    outgoing_edges(const Graph* G, int l, int r) : G(G), l(l), r(r) {}
    const edge_type* begin() const {
      if (l == r) return 0;
      return &G->csr_edges[l];
    }
    const edge_type* end() const {
      if (l == r) return 0;
      return &G->csr_edges[r];
    }
  };

  Graph() : n(0), m(0), prepared(0) {}
  Graph(int n) : n(n), m(0), prepared(0) {}

  void add(int from, int to, T cost = 1, int i = -1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    if (i == -1) i = m;
    auto e = edge_type({from, to, cost, i});
    edges.eb(e);
    ++m;
  }

  void read_tree(bool wt = false, int off = 1) { read_graph(n - 1, wt, off); }
  void read_graph(int mm, bool wt = false, int off = 1) {
    for (int i = 0; i < mm; i++) {
      ints(a, b);
      a -= off, b -= off;
      if (!wt) {
        add(a, b);
      } else {
        T c;
        read(c);
        add(a, b, c);
      }
    }
    build();
  }  
  void build() {
    assert(!prepared);
    prepared = true;
    indptr.assign(n + 1, 0);
    for (auto e : edges) {
      indptr[e.from + 1]++;
      if (!directed) indptr[e.to + 1]++;
    }
    for (int u = 0; u < n; u++) indptr[u + 1] += indptr[u];
    auto counter = indptr;
    csr_edges.resize(indptr.back() + 1);
    for (auto e : edges) {
      csr_edges[counter[e.from]++] = e;
      if (!directed) {
        csr_edges[counter[e.to]++] = edge_type({e.to, e.from, e.cost, e.id});
      }
    }
  }
  outgoing_edges operator[](int u) const {
    assert(prepared);
    return {this, indptr[u], indptr[u + 1]};
  }
};
