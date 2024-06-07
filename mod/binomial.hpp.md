---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"mod/binomial.hpp\"\nstruct {\n  int n = 0;\n  vector<mint>\
    \ _fac, _ifac, _inv;\n\n  void init(int m) {\n    if (m <= n) return;\n    _fac.resize(m\
    \ + 1);\n    _ifac.resize(m + 1);\n    _inv.resize(m + 1);\n    _fac[0] = 1;\n\
    \    for (int i = n + 1; i <= m; i++) {\n      _fac[i] = _fac[i - 1] * i;\n  \
    \  }\n    _ifac[m] = _fac[m].inv();\n    for (int i = m; i > n; i--) {\n     \
    \ _ifac[i - 1] = _ifac[i] * i;\n      _inv[i] = _ifac[i] * _fac[i - 1];\n    }\n\
    \    n = m;\n  }\n  mint fac(int m) {\n    if (m >= n) init(m | 1);\n    return\
    \ _fac[m];\n  }\n  mint ifac(int m) {\n    if (m >= n) init(m | 1);\n    return\
    \ _ifac[m];\n  }\n  mint inv(int m) {\n    if (m >= n) init(m | 1);\n    return\
    \ _inv[m];\n  }\n  mint C(int a, int b) {\n    if (a < b || b < 0) return 0;\n\
    \    return fac(a) * ifac(b) * ifac(a - b);\n  }\n  mint P(int a, int b) {\n \
    \   if (a < b || b < 0) return 0;\n    return fac(a) * ifac(a - b);\n  }\n} binom;\n"
  code: "struct {\n  int n = 0;\n  vector<mint> _fac, _ifac, _inv;\n\n  void init(int\
    \ m) {\n    if (m <= n) return;\n    _fac.resize(m + 1);\n    _ifac.resize(m +\
    \ 1);\n    _inv.resize(m + 1);\n    _fac[0] = 1;\n    for (int i = n + 1; i <=\
    \ m; i++) {\n      _fac[i] = _fac[i - 1] * i;\n    }\n    _ifac[m] = _fac[m].inv();\n\
    \    for (int i = m; i > n; i--) {\n      _ifac[i - 1] = _ifac[i] * i;\n     \
    \ _inv[i] = _ifac[i] * _fac[i - 1];\n    }\n    n = m;\n  }\n  mint fac(int m)\
    \ {\n    if (m >= n) init(m | 1);\n    return _fac[m];\n  }\n  mint ifac(int m)\
    \ {\n    if (m >= n) init(m | 1);\n    return _ifac[m];\n  }\n  mint inv(int m)\
    \ {\n    if (m >= n) init(m | 1);\n    return _inv[m];\n  }\n  mint C(int a, int\
    \ b) {\n    if (a < b || b < 0) return 0;\n    return fac(a) * ifac(b) * ifac(a\
    \ - b);\n  }\n  mint P(int a, int b) {\n    if (a < b || b < 0) return 0;\n  \
    \  return fac(a) * ifac(a - b);\n  }\n} binom;\n"
  dependsOn: []
  isVerificationFile: false
  path: mod/binomial.hpp
  requiredBy: []
  timestamp: '2024-06-07 21:27:30+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/binomial.hpp
layout: document
redirect_from:
- /library/mod/binomial.hpp
- /library/mod/binomial.hpp.html
title: mod/binomial.hpp
---
