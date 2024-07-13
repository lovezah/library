template <int sigma = 26, char first = 'a'> 
struct AhoCorasick {
  struct node : array<int, sigma> {
    int link;
    node() : link(0) { this->fill(0); }
  };
  vector<node> nodes;
  AhoCorasick() : nodes(1) {}

  int insert(const string &s) {
    int p = 0;
    for (char ch : s) {
      int c = ch - first;
      if (!nodes[p][c]) {
        nodes[p][c] = (int) nodes.size();
        nodes.emplace_back();
      }
      p = nodes[p][c];
    }
    return p;
  }
  vector<int> build() {
    vector<int> q;
    q.push_back(0);
    for (int i = 0; i < (int) q.size(); i++) {
      int cur = q[i];
      for (int j = 0; j < sigma; j++) {
        int &nxt = nodes[cur][j], nxt2 = nodes[nodes[cur].link][j];
        if (!nxt) {
          nxt = nxt2;
          continue;
        }
        nodes[nxt].link = cur ? nxt2 : 0;
        q.push_back(nxt);
      }
    }
    return q;
  }
};