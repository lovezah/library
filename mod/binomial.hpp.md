---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ mod/binomial.hpp: line 2: #pragma once found in a non-first line\n"
  code: "\n#pragma once\n\n#include \"mod/modint.hpp\"\n\nstruct {\n  int n = 0;\n\
    \  vt<mint> _fac, _ifac, _inv;\n\n  void init(int m) {\n    if (m <= n) return;\n\
    \    _fac.resize(m + 1);\n    _ifac.resize(m + 1);\n    _inv.resize(m + 1);\n\
    \    _fac[0] = 1;\n    FOR(i, n + 1, m + 1) {\n      _fac[i] = _fac[i - 1] * i;\n\
    \    }\n    _ifac[m] = _fac[m].inv();\n    FOR_R(i, n + 1, m + 1) {\n      _ifac[i\
    \ - 1] = _ifac[i] * i;\n      _inv[i] = _ifac[i] * _fac[i - 1];\n    }\n    n\
    \ = m;\n  }\n  mint fac(int m) {\n    if (m >= n) init(m | 1);\n    return _fac[m];\n\
    \  }\n  mint ifac(int m) {\n    if (m >= n) init(m | 1);\n    return _ifac[m];\n\
    \  }\n  mint inv(int m) {\n    if (m >= n) init(m | 1);\n    return _inv[m];\n\
    \  }\n  mint C(int a, int b) {\n    if (a < b || b < 0) return 0;\n    return\
    \ fac(a) * ifac(b) * ifac(a - b);\n  }\n  mint P(int a, int b) {\n    if (a <\
    \ b || b < 0) return 0;\n    return fac(a) * ifac(a - b);\n  }\n} binom;\n"
  dependsOn:
  - mod/modint.hpp
  isVerificationFile: false
  path: mod/binomial.hpp
  requiredBy: []
  timestamp: '2024-05-06 00:02:18+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/binomial.hpp
layout: document
redirect_from:
- /library/mod/binomial.hpp
- /library/mod/binomial.hpp.html
title: mod/binomial.hpp
---
