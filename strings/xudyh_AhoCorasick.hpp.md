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
  bundledCode: "#line 1 \"strings/xudyh_AhoCorasick.hpp\"\nconst int MAXN = 500010;\n\
    struct node {\n  node *go[26], *fail;\n  int cnt;\n} pool[MAXN], *nptr = pool,\
    \ *ids[MAXN], *root;\n\nnode *newnode() {\n  node *u = nptr++;\n  for (int i =\
    \ 0; i < 26; i++) u->go[i] = NULL;\n  u->fail = NULL;\n  u->cnt = 0;\n  return\
    \ u;\n}\n\nnode *insert(const string &s) {\n  node *u = root;\n  for (char ch\
    \ : s) {\n    int c = ch - 'a';\n    if (!u->go[c]) u->go[c] = newnode();\n  \
    \  u = u->go[c];\n  }\n  return u;\n}\n\nvector<node*> build() {\n  vector<node*>\
    \ q;\n  q.push_back(root);\n  root->fail = root;\n  for (int i = 0; i < (int)\
    \ q.size(); i++) {\n    node *u = q[i];\n    for (int j = 0; j < 26; j++) {\n\
    \      if (u->go[j]) {\n        if (u == root) u->go[j]->fail = root;\n      \
    \  else u->go[j]->fail = u->fail->go[j];\n        q.push_back(u->go[j]);\n   \
    \   } else {\n        if (u == root) u->go[j] = root;\n        else u->go[j] =\
    \ u->fail->go[j];\n      }\n    }\n  }\n}\n"
  code: "const int MAXN = 500010;\nstruct node {\n  node *go[26], *fail;\n  int cnt;\n\
    } pool[MAXN], *nptr = pool, *ids[MAXN], *root;\n\nnode *newnode() {\n  node *u\
    \ = nptr++;\n  for (int i = 0; i < 26; i++) u->go[i] = NULL;\n  u->fail = NULL;\n\
    \  u->cnt = 0;\n  return u;\n}\n\nnode *insert(const string &s) {\n  node *u =\
    \ root;\n  for (char ch : s) {\n    int c = ch - 'a';\n    if (!u->go[c]) u->go[c]\
    \ = newnode();\n    u = u->go[c];\n  }\n  return u;\n}\n\nvector<node*> build()\
    \ {\n  vector<node*> q;\n  q.push_back(root);\n  root->fail = root;\n  for (int\
    \ i = 0; i < (int) q.size(); i++) {\n    node *u = q[i];\n    for (int j = 0;\
    \ j < 26; j++) {\n      if (u->go[j]) {\n        if (u == root) u->go[j]->fail\
    \ = root;\n        else u->go[j]->fail = u->fail->go[j];\n        q.push_back(u->go[j]);\n\
    \      } else {\n        if (u == root) u->go[j] = root;\n        else u->go[j]\
    \ = u->fail->go[j];\n      }\n    }\n  }\n}"
  dependsOn: []
  isVerificationFile: false
  path: strings/xudyh_AhoCorasick.hpp
  requiredBy: []
  timestamp: '2024-07-13 22:40:00+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: strings/xudyh_AhoCorasick.hpp
layout: document
redirect_from:
- /library/strings/xudyh_AhoCorasick.hpp
- /library/strings/xudyh_AhoCorasick.hpp.html
title: strings/xudyh_AhoCorasick.hpp
---
