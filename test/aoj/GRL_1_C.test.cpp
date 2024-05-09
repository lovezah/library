#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"
#include "misc/my_template_test.hpp"
#include "graph/base.hpp"
#include "graph/floyd.hpp"

void solve() {
  lls(n, m);
  Graph<ll, 1> G(n);
  G.read_graph(m, 1, 0);
  auto dist = floyd<ll>(G);
  rep(i, n) if (dist[i][i] < 0) return print("NEGATIVE CYCLE");
  rep(a, n) {
    str s;
    rep(b, n) {
      if (b) s += " ";
      ll x = dist[a][b];
      if (x == infty<ll>) s += "INF";
      else s += to_string(x);
    }
    print(s);
  }
}
int main() {
  SETIO();
  solve();
}