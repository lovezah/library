---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: misc/my_template.hpp
    title: misc/my_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "#line 1 \"test/library_checker/datastructure/union_find.test.cpp\"\
    \n#include <misc/my_template.hpp>\n#include <ds/union_find.hpp>\n\nvoid solve()\
    \ {\n  ints(n, q);\n  union_find uf(n);\n  rep(q) {\n    ints(t, u, v);\n    if\
    \ (t == 0) {\n      uf.merge(u, v);\n    } else print(uf[u] == uf[v] ? 1 : 0);\n\
    \  }\n}\n\nint main() {\n  SETIO();\n  solve();\n}\n"
  code: "#include <misc/my_template.hpp>\n#include <ds/union_find.hpp>\n\nvoid solve()\
    \ {\n  ints(n, q);\n  union_find uf(n);\n  rep(q) {\n    ints(t, u, v);\n    if\
    \ (t == 0) {\n      uf.merge(u, v);\n    } else print(uf[u] == uf[v] ? 1 : 0);\n\
    \  }\n}\n\nint main() {\n  SETIO();\n  solve();\n}"
  dependsOn:
  - misc/my_template.hpp
  isVerificationFile: true
  path: test/library_checker/datastructure/union_find.test.cpp
  requiredBy: []
  timestamp: '2024-05-08 17:32:57+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/datastructure/union_find.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/union_find.test.cpp
- /verify/test/library_checker/datastructure/union_find.test.cpp.html
title: test/library_checker/datastructure/union_find.test.cpp
---
