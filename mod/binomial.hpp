#pragma once

#include "mod/modint.hpp"

struct {
  int n = 0;
  vt<mint> _fac, _ifac, _inv;

  void init(int m) {
    if (m <= n) return;
    _fac.resize(m + 1);
    _ifac.resize(m + 1);
    _inv.resize(m + 1);
    _fac[0] = 1;
    FOR(i, n + 1, m + 1) {
      _fac[i] = _fac[i - 1] * i;
    }
    _ifac[m] = _fac[m].inv();
    FOR_R(i, n + 1, m + 1) {
      _ifac[i - 1] = _ifac[i] * i;
      _inv[i] = _ifac[i] * _fac[i - 1];
    }
    n = m;
  }
  mint fac(int m) {
    if (m >= n) init(m | 1);
    return _fac[m];
  }
  mint ifac(int m) {
    if (m >= n) init(m | 1);
    return _ifac[m];
  }
  mint inv(int m) {
    if (m >= n) init(m | 1);
    return _inv[m];
  }
  mint C(int a, int b) {
    if (a < b || b < 0) return 0;
    return fac(a) * ifac(b) * ifac(a - b);
  }
  mint P(int a, int b) {
    if (a < b || b < 0) return 0;
    return fac(a) * ifac(a - b);
  }
} binom;
