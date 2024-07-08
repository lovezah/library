---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://github.com/kth-competitive-programming/kactl/blob/main/content/graph/BellmanFord.h
  bundledCode: "#line 1 \"graph/bellman_ford.hpp\"\n/*\n  source: kactl\n  link  :\
    \ https://github.com/kth-competitive-programming/kactl/blob/main/content/graph/BellmanFord.h\n\
    \  docs  : Unreachable nodes get dist = inf; nodes reachable through negative-weight\
    \ cycles get dist = -inf.\n*/\n#define rep(i, a, b) for(int i = a; i < (b); ++i)\n\
    #define trav(a, x) for(auto& a : x)\n#define all(x) x.begin(), x.end()\n#define\
    \ sz(x) (int)(x).size()\nusing ll = int64_t;\nusing pii = pair<int, int>;\nusing\
    \ vi = vector<int>;\n\nconst ll inf = numeric_limits<int64_t>::max();\nstruct\
    \ Ed { int a, b, w; int s() { return a < b ? a : -a; }};\nstruct Node { ll dist\
    \ = inf; int prev = -1; };\n\nvoid bellman_ford(vector<Node>& nodes, vector<Ed>&\
    \ eds, int s) {\n\tnodes[s].dist = 0;\n\tsort(all(eds), [](Ed a, Ed b) { return\
    \ a.s() < b.s(); });\n\n\tint lim = sz(nodes) / 2 + 2; // /3+100 with shuffled\
    \ vertices\n\trep(i,0,lim) for (Ed ed : eds) {\n\t\tNode cur = nodes[ed.a], &dest\
    \ = nodes[ed.b];\n\t\tif (abs(cur.dist) == inf) continue;\n\t\tll d = cur.dist\
    \ + ed.w;\n\t\tif (d < dest.dist) {\n\t\t\tdest.prev = ed.a;\n\t\t\tdest.dist\
    \ = (i < lim-1 ? d : -inf);\n\t\t}\n\t}\n\trep(i,0,lim) for (Ed e : eds) {\n\t\
    \tif (nodes[e.a].dist == -inf)\n\t\t\tnodes[e.b].dist = -inf;\n\t}\n}\n"
  code: "/*\n  source: kactl\n  link  : https://github.com/kth-competitive-programming/kactl/blob/main/content/graph/BellmanFord.h\n\
    \  docs  : Unreachable nodes get dist = inf; nodes reachable through negative-weight\
    \ cycles get dist = -inf.\n*/\n#define rep(i, a, b) for(int i = a; i < (b); ++i)\n\
    #define trav(a, x) for(auto& a : x)\n#define all(x) x.begin(), x.end()\n#define\
    \ sz(x) (int)(x).size()\nusing ll = int64_t;\nusing pii = pair<int, int>;\nusing\
    \ vi = vector<int>;\n\nconst ll inf = numeric_limits<int64_t>::max();\nstruct\
    \ Ed { int a, b, w; int s() { return a < b ? a : -a; }};\nstruct Node { ll dist\
    \ = inf; int prev = -1; };\n\nvoid bellman_ford(vector<Node>& nodes, vector<Ed>&\
    \ eds, int s) {\n\tnodes[s].dist = 0;\n\tsort(all(eds), [](Ed a, Ed b) { return\
    \ a.s() < b.s(); });\n\n\tint lim = sz(nodes) / 2 + 2; // /3+100 with shuffled\
    \ vertices\n\trep(i,0,lim) for (Ed ed : eds) {\n\t\tNode cur = nodes[ed.a], &dest\
    \ = nodes[ed.b];\n\t\tif (abs(cur.dist) == inf) continue;\n\t\tll d = cur.dist\
    \ + ed.w;\n\t\tif (d < dest.dist) {\n\t\t\tdest.prev = ed.a;\n\t\t\tdest.dist\
    \ = (i < lim-1 ? d : -inf);\n\t\t}\n\t}\n\trep(i,0,lim) for (Ed e : eds) {\n\t\
    \tif (nodes[e.a].dist == -inf)\n\t\t\tnodes[e.b].dist = -inf;\n\t}\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/bellman_ford.hpp
  requiredBy: []
  timestamp: '2024-07-08 13:55:24+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/bellman_ford.hpp
layout: document
redirect_from:
- /library/graph/bellman_ford.hpp
- /library/graph/bellman_ford.hpp.html
title: graph/bellman_ford.hpp
---
