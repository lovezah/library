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
  bundledCode: '#line 1 "misc/setminmax.hpp"

    template <typename T> bool setmin(T& a, T b) { if (b < a) { a = b;  return true;
    } return false; }

    template <typename T> bool setmax(T& a, T b) { if (b > a) { a = b;  return true;
    } return false; }

    '
  code: 'template <typename T> bool setmin(T& a, T b) { if (b < a) { a = b;  return
    true; } return false; }

    template <typename T> bool setmax(T& a, T b) { if (b > a) { a = b;  return true;
    } return false; }'
  dependsOn: []
  isVerificationFile: false
  path: misc/setminmax.hpp
  requiredBy: []
  timestamp: '2024-07-06 15:12:38+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/setminmax.hpp
layout: document
redirect_from:
- /library/misc/setminmax.hpp
- /library/misc/setminmax.hpp.html
title: misc/setminmax.hpp
---
