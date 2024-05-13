#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "misc/my_template_test.hpp"
#include "ds/segtree.hpp"

ll op(ll x, ll y) {
  return x + y;
}
ll e() {
  return (ll)0;
}
int main() {
  SETIO;
  lls(n, q);
  read_vec(ll, a, n);
  segtree<ll, op, e> seg(a);
  rep(q) {
    lls(o);
    if (o == 0) {
      lls(p, x);
      a[p] += x;
      seg.set(p, a[p]);
    } else {
      lls(l, r);
      print(seg.prod(l, r));
    }
  }
}