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
  bundledCode: "#line 1 \"strings/AhoCorasick.hpp\"\ntemplate <int sigma = 26, char\
    \ first = 'a'> \nstruct AhoCorasick {\n  struct node : array<int, sigma> {\n \
    \   int link;\n    node() : link(0) { this->fill(0); }\n  };\n  vector<node> nodes;\n\
    \  AhoCorasick() : nodes(1) {}\n\n  int insert(const string &s) {\n    int p =\
    \ 0;\n    for (char ch : s) {\n      int c = ch - first;\n      if (!nodes[p][c])\
    \ {\n        nodes[p][c] = (int) nodes.size();\n        nodes.emplace_back();\n\
    \      }\n      p = nodes[p][c];\n    }\n    return p;\n  }\n  vector<int> build()\
    \ {\n    vector<int> q;\n    q.push_back(0);\n    for (int i = 0; i < (int) q.size();\
    \ i++) {\n      int cur = q[i];\n      for (int j = 0; j < sigma; j++) {\n   \
    \     int &nxt = nodes[cur][j], nxt2 = nodes[nodes[cur].link][j];\n        if\
    \ (!nxt) {\n          nxt = nxt2;\n          continue;\n        }\n        nodes[nxt].link\
    \ = cur ? nxt2 : 0;\n        q.push_back(nxt);\n      }\n    }\n    return q;\n\
    \  }\n};\n"
  code: "template <int sigma = 26, char first = 'a'> \nstruct AhoCorasick {\n  struct\
    \ node : array<int, sigma> {\n    int link;\n    node() : link(0) { this->fill(0);\
    \ }\n  };\n  vector<node> nodes;\n  AhoCorasick() : nodes(1) {}\n\n  int insert(const\
    \ string &s) {\n    int p = 0;\n    for (char ch : s) {\n      int c = ch - first;\n\
    \      if (!nodes[p][c]) {\n        nodes[p][c] = (int) nodes.size();\n      \
    \  nodes.emplace_back();\n      }\n      p = nodes[p][c];\n    }\n    return p;\n\
    \  }\n  vector<int> build() {\n    vector<int> q;\n    q.push_back(0);\n    for\
    \ (int i = 0; i < (int) q.size(); i++) {\n      int cur = q[i];\n      for (int\
    \ j = 0; j < sigma; j++) {\n        int &nxt = nodes[cur][j], nxt2 = nodes[nodes[cur].link][j];\n\
    \        if (!nxt) {\n          nxt = nxt2;\n          continue;\n        }\n\
    \        nodes[nxt].link = cur ? nxt2 : 0;\n        q.push_back(nxt);\n      }\n\
    \    }\n    return q;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: strings/AhoCorasick.hpp
  requiredBy: []
  timestamp: '2024-07-13 22:36:20+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: strings/AhoCorasick.hpp
layout: document
redirect_from:
- /library/strings/AhoCorasick.hpp
- /library/strings/AhoCorasick.hpp.html
title: strings/AhoCorasick.hpp
---
