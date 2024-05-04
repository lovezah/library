---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/submissions/benq
  bundledCode: "#line 1 \"misc/my_template.cpp\"\n#include <bits/stdc++.h>\n\nusing\
    \ namespace std;\n\nusing db = double;\nusing ll = long long;\nusing u32 = unsigned\
    \ int;\nusing u64 = unsigned long long;\nusing i128 = __int128;\nusing str = string;\n\
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
    \n#define FOR1(n) for (ll _ = 0; _ < ll(n); _++)\n#define FOR2(i, n) for (ll i\
    \ = 0; i < ll(n); i++)\n#define FOR3(i, a, n) for (ll i = a; i < ll(n); i++)\n\
    #define FOR4(i, a, n, s) for (ll i = a; i < ll(n); i += (s))\n#define FOR1_R(n)\
    \ for (ll i = (n) - 1; i >= ll(0); i--)\n#define FOR2_R(i, n) for (ll i = (n)\
    \ - 1; i >= ll(0); i--)\n#define FOR3_R(i, n, b) for (ll i = (b) - 1; i >= ll(n);\
    \ i--)\n#define FOR4_R(i, n, b, s) for (ll i = (b) - 1; i >= ll(n); i -= (s))\n\
    #define overload4(a, b, c, d, e, ...) e\n#define FOR(...) overload4(__VA_ARGS__,\
    \ FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n#define FOR_R(...) overload4(__VA_ARGS__,\
    \ FOR4_R, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)\n#define FOR_subset(i, x) for (ll\
    \ i = (x); i >= 0; i = (i == 0 ? -1 : (i - 1) & (x)))\n\n#define pb push_back\n\
    #define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n#define\
    \ f first\n#define s second\n#define all(x) (x).begin(), (x).end()\n#define len(x)\
    \ ll(x.size())\n\nint popcount(int x) { return __builtin_popcount(x); }\nint popcount(ll\
    \ x) { return __builtin_popcountll(x); }\nint topbit(int x) { return (x == 0 ?\
    \ -1 : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0 ? -1 : 63\
    \ - __builtin_clzll(x)); }\nint lobit(int x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lobit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate\
    \ <class T, class U>\nT SUM(vt<U> &A) {\n  T res = 0;\n  for (auto &&a : A) res\
    \ += a;\n  return res;\n}\n#define MIN(x) *min_element(all(x))\n#define MAX(x)\
    \ *max_element(all(x))\n#define LB(x, v) lower_bound(all(x), v)\n#define UB(x,\
    \ v) upper_bound(all(x), v)\n#define ILB(x, v) distance(x.begin(), LB(x, v))\n\
    #define IUB(x, v) distance(x.begin(), UB(x, v))\n#define SORT(x) sort(all(x))\n\
    #define UNIQUE(x) SORT(x), x.resize(unique(all(x)) - x.begin())\n\ntemplate <class\
    \ T, class U>\nbool ckmax(T &a, U b) { return (a < b ? a = b, true : false); }\n\
    template <class T, class U>\nbool ckmin(T &a, U b) { return (a > b ? a = b, true\
    \ : false); }\ntemplate <class T>\nT POP(queue<T> &que) { T a = que.front(); que.pop();\
    \ return a; }\ntemplate <class T>\nT POP(vt<T> &que) { T a = que.back(); que.pop_back();\
    \ return a; }\ntemplate <class T>\nT POP(pq<T> &que) { T a = que.top(); que.pop();\
    \ return a; }\ntemplate <class T>\nT POP(pqg<T> &que) { T a = que.top(); que.pop();\
    \ return a; }\ntemplate <class T = char>\nT POP(str &que) { T a = que.back();\
    \ que.pop_back(); return a; }\n\ntemplate <typename F>\nll FIRST_TRUE(F check,\
    \ ll lo, ll hi) {\n  ++hi;\n  while (lo < hi) {\n    ll mi = lo + (hi - lo) /\
    \ 2;\n    check(mi) ? hi = mi : lo = mi + 1;\n  }\n  return lo;\n}\ntemplate <typename\
    \ F>\nll LAST_TRUE(F check, ll lo, ll hi) {\n  --lo;\n  while (lo < hi) {\n  \
    \  ll mi = lo + (hi - lo + 1) / 2;\n    check(mi) ? lo = mi : hi = mi - 1;\n \
    \ }\n  return lo;\n}\ntemplate <typename F>\ndb binary_search_real(F check, db\
    \ lo, db hi, int iter = 100) {\n  FOR(iter) {\n    db mi = (lo + hi) / 2;\n  \
    \  (check(mi) ? lo : hi) = mi;\n  }\n  return (lo + hi) / 2;\n}\ntemplate <typename\
    \ T, typename U>\nvt<T> cumsum(vt<U> &A, int offset = 1) {\n  int N = len(A);\n\
    \  vt<T> B(N + 1);\n  FOR(i, N) B[i + 1] = B[i] + A[i];\n  if (offset == 0) B.erase(B.begin());\n\
    \  return B;\n}\ntemplate <typename T>\nvi argsort(vt<T> &A) {\n  vi ids(len(A));\n\
    \  iota(all(ids), 0);\n  sort(all(ids), [&](int i, int j) { return A[i] == A[j]\
    \ ? i < j : A[i] < A[j]; });\n  return ids;\n}\nvi s_to_vi(const str &S, char\
    \ first_char) {\n  vi res(len(S));\n  FOR(i, len(S)) res[i] = (S[i] != '?' ? S[i]\
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
    \ true>{}.print_with_sep(\" \", ts...);\n}\n}\n#define INT(...)   \\\n  int __VA_ARGS__;\
    \ \\\n  read(__VA_ARGS__)\n#define LL(...)   \\\n  ll __VA_ARGS__; \\\n  read(__VA_ARGS__)\n\
    #define STR(...)      \\\n  string __VA_ARGS__; \\\n  read(__VA_ARGS__)\n#define\
    \ CHAR(...)   \\\n  char __VA_ARGS__; \\\n  read(__VA_ARGS__)\n#define DBL(...)\
    \      \\\n  double __VA_ARGS__; \\\n  read(__VA_ARGS__)\n#define VEC(type, name,\
    \ size) \\\n  vector<type> name(size);    \\\n  read(name)\n#define VV(type, name,\
    \ h, w)                     \\\n  vector<vector<type>> name(h, vector<type>(w));\
    \ \\\n  read(name)\n// ------------------------------------- TEMPLATE ABOVE ------------------------------//\n\
    \nvoid solve() {\n\n}\n\nint main() {\n  SETIO();\n  // INT(t); FOR(t)\n  solve();\n\
    \  return 0;  \n}\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing db = double;\n\
    using ll = long long;\nusing u32 = unsigned int;\nusing u64 = unsigned long long;\n\
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
    \ vector<type>(__VA_ARGS__))))\n\n#define FOR1(n) for (ll _ = 0; _ < ll(n); _++)\n\
    #define FOR2(i, n) for (ll i = 0; i < ll(n); i++)\n#define FOR3(i, a, n) for (ll\
    \ i = a; i < ll(n); i++)\n#define FOR4(i, a, n, s) for (ll i = a; i < ll(n); i\
    \ += (s))\n#define FOR1_R(n) for (ll i = (n) - 1; i >= ll(0); i--)\n#define FOR2_R(i,\
    \ n) for (ll i = (n) - 1; i >= ll(0); i--)\n#define FOR3_R(i, n, b) for (ll i\
    \ = (b) - 1; i >= ll(n); i--)\n#define FOR4_R(i, n, b, s) for (ll i = (b) - 1;\
    \ i >= ll(n); i -= (s))\n#define overload4(a, b, c, d, e, ...) e\n#define FOR(...)\
    \ overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n#define FOR_R(...)\
    \ overload4(__VA_ARGS__, FOR4_R, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)\n#define\
    \ FOR_subset(i, x) for (ll i = (x); i >= 0; i = (i == 0 ? -1 : (i - 1) & (x)))\n\
    \n#define pb push_back\n#define eb emplace_back\n#define mp make_pair\n#define\
    \ mt make_tuple\n#define f first\n#define s second\n#define all(x) (x).begin(),\
    \ (x).end()\n#define len(x) ll(x.size())\n\nint popcount(int x) { return __builtin_popcount(x);\
    \ }\nint popcount(ll x) { return __builtin_popcountll(x); }\nint topbit(int x)\
    \ { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return\
    \ (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\nint lobit(int x) { return (x ==\
    \ 0 ? -1 : __builtin_ctz(x)); }\nint lobit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x));\
    \ }\n\ntemplate <class T, class U>\nT SUM(vt<U> &A) {\n  T res = 0;\n  for (auto\
    \ &&a : A) res += a;\n  return res;\n}\n#define MIN(x) *min_element(all(x))\n\
    #define MAX(x) *max_element(all(x))\n#define LB(x, v) lower_bound(all(x), v)\n\
    #define UB(x, v) upper_bound(all(x), v)\n#define ILB(x, v) distance(x.begin(),\
    \ LB(x, v))\n#define IUB(x, v) distance(x.begin(), UB(x, v))\n#define SORT(x)\
    \ sort(all(x))\n#define UNIQUE(x) SORT(x), x.resize(unique(all(x)) - x.begin())\n\
    \ntemplate <class T, class U>\nbool ckmax(T &a, U b) { return (a < b ? a = b,\
    \ true : false); }\ntemplate <class T, class U>\nbool ckmin(T &a, U b) { return\
    \ (a > b ? a = b, true : false); }\ntemplate <class T>\nT POP(queue<T> &que) {\
    \ T a = que.front(); que.pop(); return a; }\ntemplate <class T>\nT POP(vt<T> &que)\
    \ { T a = que.back(); que.pop_back(); return a; }\ntemplate <class T>\nT POP(pq<T>\
    \ &que) { T a = que.top(); que.pop(); return a; }\ntemplate <class T>\nT POP(pqg<T>\
    \ &que) { T a = que.top(); que.pop(); return a; }\ntemplate <class T = char>\n\
    T POP(str &que) { T a = que.back(); que.pop_back(); return a; }\n\ntemplate <typename\
    \ F>\nll FIRST_TRUE(F check, ll lo, ll hi) {\n  ++hi;\n  while (lo < hi) {\n \
    \   ll mi = lo + (hi - lo) / 2;\n    check(mi) ? hi = mi : lo = mi + 1;\n  }\n\
    \  return lo;\n}\ntemplate <typename F>\nll LAST_TRUE(F check, ll lo, ll hi) {\n\
    \  --lo;\n  while (lo < hi) {\n    ll mi = lo + (hi - lo + 1) / 2;\n    check(mi)\
    \ ? lo = mi : hi = mi - 1;\n  }\n  return lo;\n}\ntemplate <typename F>\ndb binary_search_real(F\
    \ check, db lo, db hi, int iter = 100) {\n  FOR(iter) {\n    db mi = (lo + hi)\
    \ / 2;\n    (check(mi) ? lo : hi) = mi;\n  }\n  return (lo + hi) / 2;\n}\ntemplate\
    \ <typename T, typename U>\nvt<T> cumsum(vt<U> &A, int offset = 1) {\n  int N\
    \ = len(A);\n  vt<T> B(N + 1);\n  FOR(i, N) B[i + 1] = B[i] + A[i];\n  if (offset\
    \ == 0) B.erase(B.begin());\n  return B;\n}\ntemplate <typename T>\nvi argsort(vt<T>\
    \ &A) {\n  vi ids(len(A));\n  iota(all(ids), 0);\n  sort(all(ids), [&](int i,\
    \ int j) { return A[i] == A[j] ? i < j : A[i] < A[j]; });\n  return ids;\n}\n\
    vi s_to_vi(const str &S, char first_char) {\n  vi res(len(S));\n  FOR(i, len(S))\
    \ res[i] = (S[i] != '?' ? S[i] - first_char : -1); \n  return res;\n}\nvoid SETIO()\
    \ {\n  cin.tie(nullptr)->sync_with_stdio(false);\n  cout << fixed << setprecision(20);\n\
    }\n\n// https://codeforces.com/submissions/benq\ninline namespace IO {\n#define\
    \ SFINAE(x, ...)                                                         \\\n\
    \  template <class, class = void> struct x : std::false_type {};             \
    \ \\\n  template <class T> struct x<T, std::void_t<__VA_ARGS__>> : std::true_type\
    \ {}\n\nSFINAE(DefaultI, decltype(std::cin >> std::declval<T &>()));\nSFINAE(DefaultO,\
    \ decltype(std::cout << std::declval<T &>()));\nSFINAE(IsTuple, typename std::tuple_size<T>::type);\n\
    SFINAE(Iterable, decltype(std::begin(std::declval<T>())));\n\ntemplate <auto &is>\
    \ struct Reader {\n  template <class T> void Impl(T &t) {\n    if constexpr (DefaultI<T>::value)\
    \ is >> t;\n    else if constexpr (Iterable<T>::value) {\n      for (auto &x :\
    \ t) Impl(x);\n    } else if constexpr (IsTuple<T>::value) {\n      std::apply([this](auto\
    \ &...args) { (Impl(args), ...); }, t);\n    } else static_assert(IsTuple<T>::value,\
    \ \"No matching type for read\");\n  }\n  template <class... Ts> void read(Ts\
    \ &...ts) { ((Impl(ts)), ...); }\n};\ntemplate <class... Ts> void read(Ts &...ts)\
    \ { Reader<cin>{}.read(ts...); }\n\ntemplate <auto &os, bool debug, bool print_nd>\
    \ struct Writer {\n  string comma() const { return debug ? \",\" : \"\"; }\n \
    \ template <class T> constexpr char Space(const T &) const {\n    return print_nd\
    \ && (Iterable<T>::value or IsTuple<T>::value) ? '\\n'\n                     \
    \                                            : ' ';\n  }\n  template <class T>\
    \ void Impl(T const &t) const {\n    if constexpr (DefaultO<T>::value) os << t;\n\
    \    else if constexpr (Iterable<T>::value) {\n      if (debug) os << '{';\n \
    \     int i = 0;\n      for (auto &&x : t)\n        ((i++) ? (os << comma() <<\
    \ Space(x), Impl(x)) : Impl(x));\n      if (debug) os << '}';\n    } else if constexpr\
    \ (IsTuple<T>::value) {\n      if (debug) os << '(';\n      std::apply(\n    \
    \      [this](auto const &...args) {\n            int i = 0;\n            (((i++)\
    \ ? (os << comma() << \" \", Impl(args)) : Impl(args)),\n             ...);\n\
    \          },\n          t);\n      if (debug) os << ')';\n    } else static_assert(IsTuple<T>::value,\
    \ \"No matching type for print\");\n  }\n  template <class T> void ImplWrapper(T\
    \ const &t) const {\n    if (debug) os << \"\\033[0;31m\";\n    Impl(t);\n   \
    \ if (debug) os << \"\\033[0m\";\n  }\n  template <class... Ts> void print(Ts\
    \ const &...ts) const {\n    ((Impl(ts)), ...);\n  }\n  template <class F, class...\
    \ Ts>\n  void print_with_sep(const std::string &sep, F const &f,\n           \
    \           Ts const &...ts) const {\n    ImplWrapper(f), ((os << sep, ImplWrapper(ts)),\
    \ ...), os << '\\n';\n  }\n  void print_with_sep(const std::string &) const {\
    \ os << '\\n'; }\n};\ntemplate <class... Ts> void write(Ts const &...ts) {\n \
    \ Writer<cout, false, true>{}.print(ts...);\n}\ntemplate <class... Ts> void print(Ts\
    \ const &...ts) {\n  Writer<cout, false, true>{}.print_with_sep(\" \", ts...);\n\
    }\n}\n#define INT(...)   \\\n  int __VA_ARGS__; \\\n  read(__VA_ARGS__)\n#define\
    \ LL(...)   \\\n  ll __VA_ARGS__; \\\n  read(__VA_ARGS__)\n#define STR(...)  \
    \    \\\n  string __VA_ARGS__; \\\n  read(__VA_ARGS__)\n#define CHAR(...)   \\\
    \n  char __VA_ARGS__; \\\n  read(__VA_ARGS__)\n#define DBL(...)      \\\n  double\
    \ __VA_ARGS__; \\\n  read(__VA_ARGS__)\n#define VEC(type, name, size) \\\n  vector<type>\
    \ name(size);    \\\n  read(name)\n#define VV(type, name, h, w)              \
    \       \\\n  vector<vector<type>> name(h, vector<type>(w)); \\\n  read(name)\n\
    // ------------------------------------- TEMPLATE ABOVE ------------------------------//\n\
    \nvoid solve() {\n\n}\n\nint main() {\n  SETIO();\n  // INT(t); FOR(t)\n  solve();\n\
    \  return 0;  \n}\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/my_template.cpp
  requiredBy: []
  timestamp: '2024-05-05 05:59:32+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/my_template.cpp
layout: document
redirect_from:
- /library/misc/my_template.cpp
- /library/misc/my_template.cpp.html
title: misc/my_template.cpp
---
