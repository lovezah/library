---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/union_find.hpp
    title: ds/union_find.hpp
  - icon: ':x:'
    path: misc/my_template.hpp
    title: misc/my_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/library_checker/datastructure/union_find.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#line 1 \"misc/my_template.hpp\"\
    \n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing db = double;\nusing\
    \ ll = long long;\nusing u32 = unsigned int;\nusing u64 = unsigned long long;\n\
    using i128 = __int128;\nusing str = string;\n\nusing pi = pair<ll, ll>;\nusing\
    \ vi = vector<ll>;\ntemplate <class T>\nusing vt = vector<T>;\ntemplate <class\
    \ T>\nusing vvt = vector<vt<T>>;\ntemplate <class T>\nusing vvvt = vector<vvt<T>>;\n\
    template <class T>\nusing vvvvt = vector<vvvt<T>>;\ntemplate <class T>\nusing\
    \ pq = priority_queue<T>;\ntemplate <class T>\nusing pqg = priority_queue<T, vector<T>,\
    \ greater<T>>;\ntemplate <class T>\nconstexpr T infty = numeric_limits<T>::max()\
    \ / 2;\n\n#define vv(type, name, h, ...) \\\n  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n\
    #define vvv(type, name, h, w, ...)   \\\n  vector<vector<vector<type>>> name(\
    \ \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define vvvv(type,\
    \ name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>> name( \\\
    \n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
    \ vector<type>(__VA_ARGS__))))\n\n#define rep1(n) for (ll _ = 0; _ < ll(n); _++)\n\
    #define rep2(i, n) for (ll i = 0; i < ll(n); i++)\n#define rep3(i, a, n) for (ll\
    \ i = a; i < ll(n); i++)\n#define rep4(i, a, n, s) for (ll i = a; i < ll(n); i\
    \ += (s))\n#define per1(n) for (ll i = (n) - 1; i >= ll(0); i--)\n#define per2(i,\
    \ n) for (ll i = (n) - 1; i >= ll(0); i--)\n#define per3(i, n, b) for (ll i =\
    \ (b) - 1; i >= ll(n); i--)\n#define per4(i, n, b, s) for (ll i = (b) - 1; i >=\
    \ ll(n); i -= (s))\n#define overload4(a, b, c, d, e, ...) e\n#define rep(...)\
    \ overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)\n#define per(...)\
    \ overload4(__VA_ARGS__, per4, per3, per2, rep1_R)(__VA_ARGS__)\n#define for_subset(i,\
    \ x) for (ll i = (x); i >= 0; i = (i == 0 ? -1 : (i - 1) & (x)))\n\n#define pb\
    \ push_back\n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n\
    #define f first\n#define s second\n#define all(x) (x).begin(), (x).end()\n#define\
    \ len(x) ll(x.size())\n\nint popcount(int x) { return __builtin_popcount(x); }\n\
    int popcount(ll x) { return __builtin_popcountll(x); }\nint topbit(int x) { return\
    \ (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0\
    \ ? -1 : 63 - __builtin_clzll(x)); }\nint lobit(int x) { return (x == 0 ? -1 :\
    \ __builtin_ctz(x)); }\nint lobit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x));\
    \ }\n\n#define lb(x, v) lower_bound(all(x), v)\n#define ub(x, v) upper_bound(all(x),\
    \ v)\n#define lwb(x, v) distance(x.begin(), lb(x, v))\n#define upb(x, v) distance(x.begin(),\
    \ ub(x, v))\n#define rem_dup(x) sort(all(x)), x.erase(unique(all(x)), x.end())\n\
    \ntemplate <class T, class U>\nbool ckmax(T &a, U b) { return (a < b ? a = b,\
    \ true : false); }\ntemplate <class T, class U>\nbool ckmin(T &a, U b) { return\
    \ (a > b ? a = b, true : false); }\n\ntemplate <typename F>\nll first_true(F check,\
    \ ll lo, ll hi) {\n  ++hi;\n  while (lo < hi) {\n    ll mi = lo + (hi - lo) /\
    \ 2;\n    check(mi) ? hi = mi : lo = mi + 1;\n  }\n  return lo;\n}\ntemplate <typename\
    \ F>\nll last_true(F check, ll lo, ll hi) {\n  --lo;\n  while (lo < hi) {\n  \
    \  ll mi = lo + (hi - lo + 1) / 2;\n    check(mi) ? lo = mi : hi = mi - 1;\n \
    \ }\n  return lo;\n}\ntemplate <typename F>\ndb binary_search_real(F check, db\
    \ lo, db hi, int iter = 100) {\n  rep(iter) {\n    db mi = (lo + hi) / 2;\n  \
    \  (check(mi) ? lo : hi) = mi;\n  }\n  return (lo + hi) / 2;\n}\ntemplate <typename\
    \ T, typename U>\nvt<T> cumsum(vt<U> &A, int offset = 1) {\n  int N = len(A);\n\
    \  vt<T> B(N + 1);\n  rep(i, N) B[i + 1] = B[i] + A[i];\n  if (offset == 0) B.erase(B.begin());\n\
    \  return B;\n}\ntemplate <typename T>\nvi argsort(vt<T> &A) {\n  vi ids(len(A));\n\
    \  iota(all(ids), 0);\n  sort(all(ids), [&](int i, int j) { return A[i] == A[j]\
    \ ? i < j : A[i] < A[j]; });\n  return ids;\n}\nvi s_to_vi(const str &S, char\
    \ first_char) {\n  vi res(len(S));\n  rep(i, len(S)) res[i] = (S[i] != '?' ? S[i]\
    \ - first_char : -1); \n  return res;\n}\nvoid SETIO() {\n  cin.tie(nullptr)->sync_with_stdio(false);\n\
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
    \nvoid solve() {\n\n}\n\nint main() {\n  SETIO();\n//ints(n); rep(n)\n  solve();\n\
    }\n#line 2 \"ds/union_find.hpp\"\n\nstruct union_find {\n  int n, comp;\n  vt<int>\
    \ p;\n  union_find(int m = 0) {\n    init(m);\n  }\n  void init(int m) {\n   \
    \ n = m;\n    comp = m;\n    p.assign(n, -1);\n  }\n  void reset() { init(n);\
    \ }\n  int operator[](int x) {\n    while (p[x] >= 0) {\n      if (p[p[x]] >=\
    \ 0) p[x] = p[p[x]];\n      x = p[x];\n    }\n    return x;\n  }\n  bool merge(int\
    \ x, int y) {\n    x = (*this)[x], y = (*this)[y];\n    if (x == y) return false;\n\
    \    if (-p[x] < -p[y]) swap(x, y);\n    p[x] += p[y];\n    p[y] = x;\n    comp--;\n\
    \    return true;\n  }\n  ll size(int x) {\n    return -p[(*this)[x]];\n  }\n\
    \  vt<int> get_all() {\n    vt<int> par(n);\n    rep(i, n) par[i] = (*this)[i];\n\
    \    return par;\n  }\n};\n#line 4 \"test/library_checker/datastructure/union_find.test.cpp\"\
    \n\nvoid solve() {\n  ints(n, q);\n  union_find uf(n);\n  rep(q) {\n    ints(t,\
    \ u, v);\n    if (t == 0) {\n      uf.merge(u, v);\n    } else print(uf[u] ==\
    \ uf[v] ? 1 : 0);\n  }\n}\n\nint main() {\n  SETIO();\n  solve();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include \"\
    misc/my_template.hpp\"\n#include \"ds/union_find.hpp\"\n\nvoid solve() {\n  ints(n,\
    \ q);\n  union_find uf(n);\n  rep(q) {\n    ints(t, u, v);\n    if (t == 0) {\n\
    \      uf.merge(u, v);\n    } else print(uf[u] == uf[v] ? 1 : 0);\n  }\n}\n\n\
    int main() {\n  SETIO();\n  solve();\n}"
  dependsOn:
  - misc/my_template.hpp
  - ds/union_find.hpp
  isVerificationFile: true
  path: test/library_checker/datastructure/union_find.test.cpp
  requiredBy: []
  timestamp: '2024-05-08 17:48:11+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/datastructure/union_find.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/union_find.test.cpp
- /verify/test/library_checker/datastructure/union_find.test.cpp.html
title: test/library_checker/datastructure/union_find.test.cpp
---
