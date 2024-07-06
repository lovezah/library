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
  bundledCode: "#line 1 \"misc/yc.hpp\"\nnamespace std {\n\ntemplate<class Fun>\n\
    class y_combinator_result {\n\tFun fun_;\npublic:\n\ttemplate<class T>\n\texplicit\
    \ y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}\n\n\ttemplate<class\
    \ ...Args>\n\tdecltype(auto) operator()(Args &&...args) {\n\t\treturn fun_(std::ref(*this),\
    \ std::forward<Args>(args)...);\n\t}\n};\n\ntemplate<class Fun>\ndecltype(auto)\
    \ y_combinator(Fun &&fun) {\n\treturn y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));\n\
    }\n\n} // namespace std\n"
  code: "namespace std {\n\ntemplate<class Fun>\nclass y_combinator_result {\n\tFun\
    \ fun_;\npublic:\n\ttemplate<class T>\n\texplicit y_combinator_result(T &&fun):\
    \ fun_(std::forward<T>(fun)) {}\n\n\ttemplate<class ...Args>\n\tdecltype(auto)\
    \ operator()(Args &&...args) {\n\t\treturn fun_(std::ref(*this), std::forward<Args>(args)...);\n\
    \t}\n};\n\ntemplate<class Fun>\ndecltype(auto) y_combinator(Fun &&fun) {\n\treturn\
    \ y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));\n}\n\n} // namespace\
    \ std"
  dependsOn: []
  isVerificationFile: false
  path: misc/yc.hpp
  requiredBy: []
  timestamp: '2024-07-06 15:12:38+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/yc.hpp
layout: document
redirect_from:
- /library/misc/yc.hpp
- /library/misc/yc.hpp.html
title: misc/yc.hpp
---
