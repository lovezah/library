#define PROBLEM "https://atcoder.jp/contests/abc073/tasks/abc073_d"
#include "misc/my_template_test.hpp"
#include "graph/base.hpp"
#include "graph/floyd.hpp"

void solve() {
  lls(n, m, r);
  read_vec(ll, wr, r);
  rep(i, r) wr[i]--;
  Graph<ll, 0> G(n);
  G.read_graph(m, 1);
  auto g = floyd<ll> (G);
  rep(k, n) rep(i, n) rep(j, n) ckmin(g[i][j], g[i][k] + g[k][j]);
  sort(all(wr));
  ll ans = infty<ll>;
  do {
    ll cur = 0;
    rep(i, 1, r) {
      cur += g[wr[i - 1]][wr[i]];
    } 
    ckmin(ans, cur);
  } while (next_permutation(all(wr)));
  print(ans);
}
int main() {
  SETIO();
  solve();
}