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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ misc/gs.hpp: line 10: unable to process #include in #if / #ifdef / #ifndef other\
    \ than include guards\n"
  code: "/**\n *  author:  happymore\n *  created: $CURRENT_DATE.$CURRENT_MONTH.$CURRENT_YEAR\
    \ $CURRENT_HOUR:$CURRENT_MINUTE:$CURRENT_SECOND\n**/\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\n#ifdef LOCAL\n#include \"debug.hpp\"\n#else\n#define\
    \ debug(...) (void)0\n#endif\n\n#define FOR(i, a, n) for (int i = (a); i < (n);\
    \ i++)\n#define F0R(i, n) FOR(i, 0, n)\n#define FORd(i, a, n) for (int i = (n)\
    \ - 1; i >= a; i--)\n#define F0Rd(i, n) FORd(i, 0, n)\n#define trav(a, v) for\
    \ (auto &a : v)\n\nusing ll = int64_t;\nusing pi = pair<int, int>;\nusing pl =\
    \ pair<ll, ll>;\nusing pli = pair<ll, int>;\nusing db = double;\n\n#define pb\
    \ push_back\n#define eb emplace_back\n#define mp make_pair\n#define f first\n\
    #define s second\n#define si(x) ((int) (x).size())\n#define all(x) (x).begin(),\
    \ (x).end()\n#define ins insert\n#define lb lower_bound\n#define ub upper_bound\n\
    #define remDup(x) sort(all(x)), (x).resize(unique(all(x)) - x.begin())\n\ntemplate\
    \ <typename T, size_t S>\nusing ar = array<T, S>;\ntemplate <typename T>\nusing\
    \ vt = vector<T>;\nusing vi = vt<int>;\nusing vl = vt<ll>;\nusing vb = vt<bool>;\n\
    using vd = vt<db>;\nusing vpi = vt<pi>;\nusing vpl = vt<pl>;\nusing vpli = vt<pli>;\n\
    \ntemplate <typename A, typename B> bool ckmax(A &a, B b) { return b > a ? a =\
    \ b, true : false; }\ntemplate <typename A, typename B> bool ckmin(A &a, B b)\
    \ { return b < a ? a = b, true : false; }\ntemplate <typename A> using pq = priority_queue<A>;\n\
    template <typename A> using pqg = priority_queue<A, vt<A>, greater<A>>;\n\nconst\
    \ char nl = '\\n';\n\nvoid solve() {\n  ${0}\n}\n\nint main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr);\n  int T = 1;\n  // cin >> T;\n  F0R(i, T) solve();\n  return\
    \ 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: misc/gs.hpp
  requiredBy: []
  timestamp: '2024-06-18 21:43:23+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/gs.hpp
layout: document
redirect_from:
- /library/misc/gs.hpp
- /library/misc/gs.hpp.html
title: misc/gs.hpp
---
