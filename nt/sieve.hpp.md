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
  bundledCode: "#line 2 \"nt/sieve.hpp\"\n\nvector<int> min_factor;\nvector<int> primes;\n\
    vector<bool> prime;\nvoid sieve(int lim) {\n  if (lim < 1) lim = 1;\n  min_factor.assign(lim\
    \ + 1, 0);\n  prime.assign(lim + 1, true);\n  prime[0] = prime[1] = false;\n \
    \ primes.reserve(int(lim / log(lim) * 1.1));\n  for (int i = 2; i <= lim; i++)\
    \ {\n    if (prime[i]) {\n      min_factor[i] = i;\n      primes.push_back(i);\n\
    \    }\n    for (const auto &p : primes) {\n      if (p > min_factor[i] || i *\
    \ p > lim) break;\n      prime[i * p] = false;\n      min_factor[i * p] = p;\n\
    \    }\n  }\n}\n"
  code: "#pragma once\n\nvector<int> min_factor;\nvector<int> primes;\nvector<bool>\
    \ prime;\nvoid sieve(int lim) {\n  if (lim < 1) lim = 1;\n  min_factor.assign(lim\
    \ + 1, 0);\n  prime.assign(lim + 1, true);\n  prime[0] = prime[1] = false;\n \
    \ primes.reserve(int(lim / log(lim) * 1.1));\n  for (int i = 2; i <= lim; i++)\
    \ {\n    if (prime[i]) {\n      min_factor[i] = i;\n      primes.push_back(i);\n\
    \    }\n    for (const auto &p : primes) {\n      if (p > min_factor[i] || i *\
    \ p > lim) break;\n      prime[i * p] = false;\n      min_factor[i * p] = p;\n\
    \    }\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: nt/sieve.hpp
  requiredBy: []
  timestamp: '2024-05-20 19:33:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: nt/sieve.hpp
layout: document
redirect_from:
- /library/nt/sieve.hpp
- /library/nt/sieve.hpp.html
title: nt/sieve.hpp
---
