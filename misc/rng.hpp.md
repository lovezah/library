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
  bundledCode: '#line 1 "misc/rng.hpp"

    mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

    '
  code: mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
  dependsOn: []
  isVerificationFile: false
  path: misc/rng.hpp
  requiredBy: []
  timestamp: '2024-06-29 12:36:30+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/rng.hpp
layout: document
redirect_from:
- /library/misc/rng.hpp
- /library/misc/rng.hpp.html
title: misc/rng.hpp
---
