---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':x:'
    path: graph/floyd.hpp
    title: graph/floyd.hpp
  - icon: ':question:'
    path: misc/my_template_test.hpp
    title: misc/my_template_test.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc073/tasks/abc073_d
    links:
    - https://atcoder.jp/contests/abc073/tasks/abc073_d
  bundledCode: "#line 1 \"test/atcoder/abc073d.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc073/tasks/abc073_d\"\
    \n#line 1 \"misc/my_template_test.hpp\"\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n\nusing db = double;\nusing ll = long long;\nusing u32 = unsigned int;\n\
    using u64 = unsigned long long;\nusing i128 = __int128;\nusing str = string;\n\
    \nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\ntemplate <class T>\nusing\
    \ vt = vector<T>;\ntemplate <class T>\nusing vvt = vector<vt<T>>;\ntemplate <class\
    \ T>\nusing vvvt = vector<vvt<T>>;\ntemplate <class T>\nusing vvvvt = vector<vvvt<T>>;\n\
    template <class T>\nusing pq = priority_queue<T>;\ntemplate <class T>\nusing pqg\
    \ = priority_queue<T, vector<T>, greater<T>>;\ntemplate <class T>\nconstexpr T\
    \ infty = numeric_limits<T>::max() / 2;\n\n#define vv(type, name, h, ...) \\\n\
    \  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n#define vvv(type,\
    \ name, h, w, ...)   \\\n  vector<vector<vector<type>>> name( \\\n      h, vector<vector<type>>(w,\
    \ vector<type>(__VA_ARGS__)))\n#define vvvv(type, name, a, b, c, ...)       \\\
    \n  vector<vector<vector<vector<type>>>> name( \\\n      a, vector<vector<vector<type>>>(\
    \       \\\n             b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))\n\
    \n#define rep1(n) for (ll _ = 0; _ < ll(n); _++)\n#define rep2(i, n) for (ll i\
    \ = 0; i < ll(n); i++)\n#define rep3(i, a, n) for (ll i = a; i < ll(n); i++)\n\
    #define rep4(i, a, n, s) for (ll i = a; i < ll(n); i += (s))\n#define per1(n)\
    \ for (ll i = (n) - 1; i >= ll(0); i--)\n#define per2(i, n) for (ll i = (n) -\
    \ 1; i >= ll(0); i--)\n#define per3(i, n, b) for (ll i = (b) - 1; i >= ll(n);\
    \ i--)\n#define per4(i, n, b, s) for (ll i = (b) - 1; i >= ll(n); i -= (s))\n\
    #define overload4(a, b, c, d, e, ...) e\n#define rep(...) overload4(__VA_ARGS__,\
    \ rep4, rep3, rep2, rep1)(__VA_ARGS__)\n#define per(...) overload4(__VA_ARGS__,\
    \ per4, per3, per2, rep1_R)(__VA_ARGS__)\n#define for_subset(i, x) for (ll i =\
    \ (x); i >= 0; i = (i == 0 ? -1 : (i - 1) & (x)))\n\n#define pb push_back\n#define\
    \ eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n#define f first\n\
    #define s second\n#define all(x) (x).begin(), (x).end()\n#define len(x) ll(x.size())\n\
    \nint popcount(int x) { return __builtin_popcount(x); }\nint popcount(ll x) {\
    \ return __builtin_popcountll(x); }\nint topbit(int x) { return (x == 0 ? -1 :\
    \ 31 - __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x));\
    \ }\nint lobit(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lobit(ll\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\n\n#define lb(x, v) lower_bound(all(x),\
    \ v)\n#define ub(x, v) upper_bound(all(x), v)\n#define lwb(x, v) distance(x.begin(),\
    \ lb(x, v))\n#define upb(x, v) distance(x.begin(), ub(x, v))\n#define rem_dup(x)\
    \ sort(all(x)), x.erase(unique(all(x)), x.end())\n\ntemplate <class T, class U>\n\
    bool ckmax(T &a, U b) { return (a < b ? a = b, true : false); }\ntemplate <class\
    \ T, class U>\nbool ckmin(T &a, U b) { return (a > b ? a = b, true : false); }\n\
    \ntemplate <typename F>\nll first_true(F check, ll lo, ll hi) {\n  ++hi;\n  while\
    \ (lo < hi) {\n    ll mi = lo + (hi - lo) / 2;\n    check(mi) ? hi = mi : lo =\
    \ mi + 1;\n  }\n  return lo;\n}\ntemplate <typename F>\nll last_true(F check,\
    \ ll lo, ll hi) {\n  --lo;\n  while (lo < hi) {\n    ll mi = lo + (hi - lo + 1)\
    \ / 2;\n    check(mi) ? lo = mi : hi = mi - 1;\n  }\n  return lo;\n}\ntemplate\
    \ <typename F>\ndb binary_search_real(F check, db lo, db hi, int iter = 100) {\n\
    \  rep(iter) {\n    db mi = (lo + hi) / 2;\n    (check(mi) ? lo : hi) = mi;\n\
    \  }\n  return (lo + hi) / 2;\n}\ntemplate <typename T, typename U>\nvt<T> cumsum(vt<U>\
    \ &A, int offset = 1) {\n  int N = len(A);\n  vt<T> B(N + 1);\n  rep(i, N) B[i\
    \ + 1] = B[i] + A[i];\n  if (offset == 0) B.erase(B.begin());\n  return B;\n}\n\
    template <typename T>\nvi argsort(vt<T> &A) {\n  vi ids(len(A));\n  iota(all(ids),\
    \ 0);\n  sort(all(ids), [&](int i, int j) { return A[i] == A[j] ? i < j : A[i]\
    \ < A[j]; });\n  return ids;\n}\nvi s_to_vi(const str &S, char first_char) {\n\
    \  vi res(len(S));\n  rep(i, len(S)) res[i] = (S[i] != '?' ? S[i] - first_char\
    \ : -1); \n  return res;\n}\nvoid SETIO() {\n  cin.tie(nullptr)->sync_with_stdio(false);\n\
    \  cout << fixed << setprecision(20);\n}\n\n// https://codeforces.com/submissions/benq\n\
    inline namespace IO {\n#define SFINAE(x, ...)                                \
    \                         \\\n  template <class, class = void> struct x : std::false_type\
    \ {};              \\\n  template <class T> struct x<T, std::void_t<__VA_ARGS__>>\
    \ : std::true_type {}\n\nSFINAE(DefaultI, decltype(std::cin >> std::declval<T\
    \ &>()));\nSFINAE(DefaultO, decltype(std::cout << std::declval<T &>()));\nSFINAE(IsTuple,\
    \ typename std::tuple_size<T>::type);\nSFINAE(Iterable, decltype(std::begin(std::declval<T>())));\n\
    \ntemplate <auto &is> struct Reader {\n  template <class T> void Impl(T &t) {\n\
    \    if constexpr (DefaultI<T>::value) is >> t;\n    else if constexpr (Iterable<T>::value)\
    \ {\n      for (auto &x : t) Impl(x);\n    } else if constexpr (IsTuple<T>::value)\
    \ {\n      std::apply([this](auto &...args) { (Impl(args), ...); }, t);\n    }\
    \ else static_assert(IsTuple<T>::value, \"No matching type for read\");\n  }\n\
    \  template <class... Ts> void read(Ts &...ts) { ((Impl(ts)), ...); }\n};\ntemplate\
    \ <class... Ts> void read(Ts &...ts) { Reader<cin>{}.read(ts...); }\n\ntemplate\
    \ <auto &os, bool debug, bool print_nd> struct Writer {\n  string comma() const\
    \ { return debug ? \",\" : \"\"; }\n  template <class T> constexpr char Space(const\
    \ T &) const {\n    return print_nd && (Iterable<T>::value or IsTuple<T>::value)\
    \ ? '\\n'\n                                                                 :\
    \ ' ';\n  }\n  template <class T> void Impl(T const &t) const {\n    if constexpr\
    \ (DefaultO<T>::value) os << t;\n    else if constexpr (Iterable<T>::value) {\n\
    \      if (debug) os << '{';\n      int i = 0;\n      for (auto &&x : t)\n   \
    \     ((i++) ? (os << comma() << Space(x), Impl(x)) : Impl(x));\n      if (debug)\
    \ os << '}';\n    } else if constexpr (IsTuple<T>::value) {\n      if (debug)\
    \ os << '(';\n      std::apply(\n          [this](auto const &...args) {\n   \
    \         int i = 0;\n            (((i++) ? (os << comma() << \" \", Impl(args))\
    \ : Impl(args)),\n             ...);\n          },\n          t);\n      if (debug)\
    \ os << ')';\n    } else static_assert(IsTuple<T>::value, \"No matching type for\
    \ print\");\n  }\n  template <class T> void ImplWrapper(T const &t) const {\n\
    \    if (debug) os << \"\\033[0;31m\";\n    Impl(t);\n    if (debug) os << \"\\\
    033[0m\";\n  }\n  template <class... Ts> void print(Ts const &...ts) const {\n\
    \    ((Impl(ts)), ...);\n  }\n  template <class F, class... Ts>\n  void print_with_sep(const\
    \ std::string &sep, F const &f,\n                      Ts const &...ts) const\
    \ {\n    ImplWrapper(f), ((os << sep, ImplWrapper(ts)), ...), os << '\\n';\n \
    \ }\n  void print_with_sep(const std::string &) const { os << '\\n'; }\n};\ntemplate\
    \ <class... Ts> void write(Ts const &...ts) {\n  Writer<cout, false, true>{}.print(ts...);\n\
    }\ntemplate <class... Ts> void print(Ts const &...ts) {\n  Writer<cout, false,\
    \ true>{}.print_with_sep(\" \", ts...);\n}\n}\ninline namespace Debug {\ntemplate\
    \ <typename... Args> void err(Args... args) {\n\tWriter<cerr, true, false>{}.print_with_sep(\"\
    \ | \", args...);\n}\ntemplate <typename... Args> void errn(Args... args) {\n\t\
    Writer<cerr, true, true>{}.print_with_sep(\" | \", args...);\n}\n\nvoid err_prefix(str\
    \ func, int line, string args) {\n\tcerr << \"\\033[0;31m\\u001b[1mDEBUG\\033[0m\"\
    \n\t     << \" | \"\n\t     << \"\\u001b[34m\" << func << \"\\033[0m\"\n\t   \
    \  << \":\"\n\t     << \"\\u001b[34m\" << line << \"\\033[0m\"\n\t     << \" -\
    \ \"\n\t     << \"[\" << args << \"] = \";\n}\n\n#ifdef LOCAL\n#define dbg(args...)\
    \ err_prefix(__FUNCTION__, __LINE__, #args), err(args)\n#define dbgn(args...)\
    \ err_prefix(__FUNCTION__, __LINE__, #args), errn(args)\n#else\n#define dbg(...)\n\
    #define dbgn(args...)\n#endif\n\nconst auto beg_time = std::chrono::high_resolution_clock::now();\n\
    // https://stackoverflow.com/questions/47980498/accurate-c-c-clock-on-a-multi-core-processor-with-auto-overclock?noredirect=1&lq=1\n\
    double time_elapsed() {\n\treturn chrono::duration<double>(std::chrono::high_resolution_clock::now()\
    \ -\n\t                                beg_time)\n\t    .count();\n}\n}  // namespace\
    \ Debug\n\n#define ints(...)   \\\n  int __VA_ARGS__; \\\n  read(__VA_ARGS__)\n\
    #define lls(...)   \\\n  ll __VA_ARGS__; \\\n  read(__VA_ARGS__)\n#define strs(...)\
    \      \\\n  string __VA_ARGS__; \\\n  read(__VA_ARGS__)\n#define chars(...) \
    \  \\\n  char __VA_ARGS__; \\\n  read(__VA_ARGS__)\n#define dbs(...)      \\\n\
    \  double __VA_ARGS__; \\\n  read(__VA_ARGS__)\n#define read_vec(type, name, size)\
    \ \\\n  vector<type> name(size);    \\\n  read(name)\n#define read_vv(type, name,\
    \ h, w)                     \\\n  vector<vector<type>> name(h, vector<type>(w));\
    \ \\\n  read(name)\n// ------------------------------------- TEMPLATE ABOVE ------------------------------//\n\
    \n#line 2 \"graph/base.hpp\"\n\ntemplate <typename T> \nstruct Edge {\n  int from,\
    \ to;\n  T cost;\n  int id;\n};\n\ntemplate <typename T = ll, bool directed =\
    \ false>\nstruct Graph {\n  static constexpr bool is_directed = directed;\n  bool\
    \ prepared;\n  int n, m;\n  using cost_type = T;\n  using edge_type = Edge<T>;\n\
    \  vt<edge_type> edges;\n  vt<int> indptr;\n  vt<edge_type> csr_edges;\n\n  class\
    \ outgoing_edges {\n   private:\n    const Graph* G;\n    int l, r;\n\n   public:\n\
    \    outgoing_edges(const Graph* G, int l, int r) : G(G), l(l), r(r) {}\n    const\
    \ edge_type* begin() const {\n      if (l == r) return 0;\n      return &G->csr_edges[l];\n\
    \    }\n    const edge_type* end() const {\n      if (l == r) return 0;\n    \
    \  return &G->csr_edges[r];\n    }\n  };\n\n  Graph() : n(0), m(0), prepared(0)\
    \ {}\n  Graph(int n) : n(n), m(0), prepared(0) {}\n\n  void add(int from, int\
    \ to, T cost = 1, int i = -1) {\n    assert(0 <= from && from < n && 0 <= to &&\
    \ to < n);\n    if (i == -1) i = m;\n    auto e = edge_type({from, to, cost, i});\n\
    \    edges.eb(e);\n    ++m;\n  }\n\n  void read_tree(bool wt = false, int off\
    \ = 1) { read_graph(n - 1, wt, off); }\n  void read_graph(int mm, bool wt = false,\
    \ int off = 1) {\n    for (int i = 0; i < mm; i++) {\n      ints(a, b);\n    \
    \  a -= off, b -= off;\n      if (!wt) {\n        add(a, b);\n      } else {\n\
    \        T c;\n        read(c);\n        add(a, b, c);\n      }\n    }\n    build();\n\
    \  }  \n  void build() {\n    assert(!prepared);\n    prepared = true;\n    indptr.assign(n\
    \ + 1, 0);\n    for (auto e : edges) {\n      indptr[e.from + 1]++;\n      if\
    \ (!directed) indptr[e.to + 1]++;\n    }\n    for (int u = 0; u < n; u++) indptr[u\
    \ + 1] += indptr[u];\n    auto counter = indptr;\n    csr_edges.resize(indptr.back()\
    \ + 1);\n    for (auto e : edges) {\n      csr_edges[counter[e.from]++] = e;\n\
    \      if (!directed) {\n        csr_edges[counter[e.to]++] = edge_type({e.to,\
    \ e.from, e.cost, e.id});\n      }\n    }\n  }\n  outgoing_edges operator[](int\
    \ u) const {\n    assert(prepared);\n    return {this, indptr[u], indptr[u + 1]};\n\
    \  }\n};\n#line 3 \"graph/floyd.hpp\"\n\ntemplate <typename T, typename GT>\n\
    vt<vt<T>> floyd(GT &G) {\n  int n = G.n;\n  vv(T, dist, n, n, infty<T>);\n  rep(i,\
    \ n) {\n    dist[i][i] = 0;\n    for (auto e : G[i]) ckmin(dist[i][e.to], e.cost);\n\
    \  }\n  rep(k, n) rep(i, n) {\n    if (dist[i][k] == infty<T>) continue;\n   \
    \ rep(j, n) {\n      if (dist[k][j] == infty<T>) continue;\n      ckmin(dist[i][j],\
    \ dist[i][k] + dist[k][j]);\n    }\n  }\n  return dist;\n}\n#line 5 \"test/atcoder/abc073d.test.cpp\"\
    \n\nvoid solve() {\n  lls(n, m, r);\n  read_vec(ll, wr, r);\n  rep(i, r) wr[i]--;\n\
    \  Graph<ll, 0> G(n);\n  G.read_graph(m, 1);\n  auto g = floyd<ll> (G);\n  rep(k,\
    \ n) rep(i, n) rep(j, n) ckmin(g[i][j], g[i][k] + g[k][j]);\n  sort(all(wr));\n\
    \  ll ans = infty<ll>;\n  do {\n    ll cur = 0;\n    rep(i, 1, r) {\n      cur\
    \ += g[wr[i - 1]][wr[i]];\n    } \n    ckmin(ans, cur);\n  } while (next_permutation(all(wr)));\n\
    \  print(ans);\n}\nint main() {\n  SETIO();\n  solve();\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc073/tasks/abc073_d\"\n#include\
    \ \"misc/my_template_test.hpp\"\n#include \"graph/base.hpp\"\n#include \"graph/floyd.hpp\"\
    \n\nvoid solve() {\n  lls(n, m, r);\n  read_vec(ll, wr, r);\n  rep(i, r) wr[i]--;\n\
    \  Graph<ll, 0> G(n);\n  G.read_graph(m, 1);\n  auto g = floyd<ll> (G);\n  rep(k,\
    \ n) rep(i, n) rep(j, n) ckmin(g[i][j], g[i][k] + g[k][j]);\n  sort(all(wr));\n\
    \  ll ans = infty<ll>;\n  do {\n    ll cur = 0;\n    rep(i, 1, r) {\n      cur\
    \ += g[wr[i - 1]][wr[i]];\n    } \n    ckmin(ans, cur);\n  } while (next_permutation(all(wr)));\n\
    \  print(ans);\n}\nint main() {\n  SETIO();\n  solve();\n}"
  dependsOn:
  - misc/my_template_test.hpp
  - graph/base.hpp
  - graph/floyd.hpp
  isVerificationFile: true
  path: test/atcoder/abc073d.test.cpp
  requiredBy: []
  timestamp: '2024-05-10 00:35:42+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc073d.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc073d.test.cpp
- /verify/test/atcoder/abc073d.test.cpp.html
title: test/atcoder/abc073d.test.cpp
---
