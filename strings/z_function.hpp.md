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
  bundledCode: "#line 1 \"strings/z_function.hpp\"\ntemplate <typename T>\nvector<int>\
    \ z_function(const T &s) {\n  int n = (int) s.size();\n  vector<int> z(n, n);\n\
    \  int l = 0, r = 0;\n  for (int i = 1; i < n; i++) {\n    z[i] = (i > r ? 0 :\
    \ min(z[i - l], r - i + 1));\n    while (i + z[i] < n && s[z[i]] == s[i + z[i]])\
    \ {\n      ++z[i];\n    }\n    if (i + z[i] - 1 > r) {\n      l = i;\n      r\
    \ = i + z[i] - 1;\n    }\n  }\n  return z;\n}\n"
  code: "template <typename T>\nvector<int> z_function(const T &s) {\n  int n = (int)\
    \ s.size();\n  vector<int> z(n, n);\n  int l = 0, r = 0;\n  for (int i = 1; i\
    \ < n; i++) {\n    z[i] = (i > r ? 0 : min(z[i - l], r - i + 1));\n    while (i\
    \ + z[i] < n && s[z[i]] == s[i + z[i]]) {\n      ++z[i];\n    }\n    if (i + z[i]\
    \ - 1 > r) {\n      l = i;\n      r = i + z[i] - 1;\n    }\n  }\n  return z;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: strings/z_function.hpp
  requiredBy: []
  timestamp: '2024-06-10 03:36:27+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: strings/z_function.hpp
layout: document
redirect_from:
- /library/strings/z_function.hpp
- /library/strings/z_function.hpp.html
title: strings/z_function.hpp
---
