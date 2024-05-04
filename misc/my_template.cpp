#include <bits/stdc++.h>

using namespace std;

using db = double;
using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;
using str = string;

using pi = pair<ll, ll>;
using vi = vector<ll>;
template <class T>
using vt = vector<T>;
template <class T>
using vvt = vector<vt<T>>;
template <class T>
using vvvt = vector<vvt<T>>;
template <class T>
using vvvvt = vector<vvvt<T>>;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
template <class T>
constexpr T infty = numeric_limits<T>::max() / 2;

#define vv(type, name, h, ...) \
  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define vvv(type, name, h, w, ...)   \
  vector<vector<vector<type>>> name( \
      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...)       \
  vector<vector<vector<vector<type>>>> name( \
      a, vector<vector<vector<type>>>(       \
             b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))

#define FOR1(n) for (ll _ = 0; _ < ll(n); _++)
#define FOR2(i, n) for (ll i = 0; i < ll(n); i++)
#define FOR3(i, a, n) for (ll i = a; i < ll(n); i++)
#define FOR4(i, a, n, s) for (ll i = a; i < ll(n); i += (s))
#define FOR1_R(n) for (ll i = (n) - 1; i >= ll(0); i--)
#define FOR2_R(i, n) for (ll i = (n) - 1; i >= ll(0); i--)
#define FOR3_R(i, n, b) for (ll i = (b) - 1; i >= ll(n); i--)
#define FOR4_R(i, n, b, s) for (ll i = (b) - 1; i >= ll(n); i -= (s))
#define overload4(a, b, c, d, e, ...) e
#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define FOR_R(...) overload4(__VA_ARGS__, FOR4_R, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)
#define FOR_subset(i, x) for (ll i = (x); i >= 0; i = (i == 0 ? -1 : (i - 1) & (x)))

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define len(x) ll(x.size())

int popcount(int x) { return __builtin_popcount(x); }
int popcount(ll x) { return __builtin_popcountll(x); }
int topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
int lobit(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lobit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }

template <class T, class U>
T SUM(vt<U> &A) {
  T res = 0;
  for (auto &&a : A) res += a;
  return res;
}
#define MIN(x) *min_element(all(x))
#define MAX(x) *max_element(all(x))
#define LB(x, v) lower_bound(all(x), v)
#define UB(x, v) upper_bound(all(x), v)
#define ILB(x, v) distance(x.begin(), LB(x, v))
#define IUB(x, v) distance(x.begin(), UB(x, v))
#define SORT(x) sort(all(x))
#define UNIQUE(x) SORT(x), x.resize(unique(all(x)) - x.begin())

template <class T, class U>
bool ckmax(T &a, U b) { return (a < b ? a = b, true : false); }
template <class T, class U>
bool ckmin(T &a, U b) { return (a > b ? a = b, true : false); }
template <class T>
T POP(queue<T> &que) { T a = que.front(); que.pop(); return a; }
template <class T>
T POP(vt<T> &que) { T a = que.back(); que.pop_back(); return a; }
template <class T>
T POP(pq<T> &que) { T a = que.top(); que.pop(); return a; }
template <class T>
T POP(pqg<T> &que) { T a = que.top(); que.pop(); return a; }
template <class T = char>
T POP(str &que) { T a = que.back(); que.pop_back(); return a; }

template <typename F>
ll FIRST_TRUE(F check, ll lo, ll hi) {
  ++hi;
  while (lo < hi) {
    ll mi = lo + (hi - lo) / 2;
    check(mi) ? hi = mi : lo = mi + 1;
  }
  return lo;
}
template <typename F>
ll LAST_TRUE(F check, ll lo, ll hi) {
  --lo;
  while (lo < hi) {
    ll mi = lo + (hi - lo + 1) / 2;
    check(mi) ? lo = mi : hi = mi - 1;
  }
  return lo;
}
template <typename F>
db binary_search_real(F check, db lo, db hi, int iter = 100) {
  FOR(iter) {
    db mi = (lo + hi) / 2;
    (check(mi) ? lo : hi) = mi;
  }
  return (lo + hi) / 2;
}
template <typename T, typename U>
vt<T> cumsum(vt<U> &A, int offset = 1) {
  int N = len(A);
  vt<T> B(N + 1);
  FOR(i, N) B[i + 1] = B[i] + A[i];
  if (offset == 0) B.erase(B.begin());
  return B;
}
template <typename T>
vi argsort(vt<T> &A) {
  vi ids(len(A));
  iota(all(ids), 0);
  sort(all(ids), [&](int i, int j) { return A[i] == A[j] ? i < j : A[i] < A[j]; });
  return ids;
}
vi s_to_vi(const str &S, char first_char) {
  vi res(len(S));
  FOR(i, len(S)) res[i] = (S[i] != '?' ? S[i] - first_char : -1); 
  return res;
}
void SETIO() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
}

// https://codeforces.com/submissions/benq
inline namespace IO {
#define SFINAE(x, ...)                                                         \
  template <class, class = void> struct x : std::false_type {};              \
  template <class T> struct x<T, std::void_t<__VA_ARGS__>> : std::true_type {}

SFINAE(DefaultI, decltype(std::cin >> std::declval<T &>()));
SFINAE(DefaultO, decltype(std::cout << std::declval<T &>()));
SFINAE(IsTuple, typename std::tuple_size<T>::type);
SFINAE(Iterable, decltype(std::begin(std::declval<T>())));

template <auto &is> struct Reader {
  template <class T> void Impl(T &t) {
    if constexpr (DefaultI<T>::value) is >> t;
    else if constexpr (Iterable<T>::value) {
      for (auto &x : t) Impl(x);
    } else if constexpr (IsTuple<T>::value) {
      std::apply([this](auto &...args) { (Impl(args), ...); }, t);
    } else static_assert(IsTuple<T>::value, "No matching type for read");
  }
  template <class... Ts> void read(Ts &...ts) { ((Impl(ts)), ...); }
};
template <class... Ts> void read(Ts &...ts) { Reader<cin>{}.read(ts...); }

template <auto &os, bool debug, bool print_nd> struct Writer {
  string comma() const { return debug ? "," : ""; }
  template <class T> constexpr char Space(const T &) const {
    return print_nd && (Iterable<T>::value or IsTuple<T>::value) ? '\n'
                                                                 : ' ';
  }
  template <class T> void Impl(T const &t) const {
    if constexpr (DefaultO<T>::value) os << t;
    else if constexpr (Iterable<T>::value) {
      if (debug) os << '{';
      int i = 0;
      for (auto &&x : t)
        ((i++) ? (os << comma() << Space(x), Impl(x)) : Impl(x));
      if (debug) os << '}';
    } else if constexpr (IsTuple<T>::value) {
      if (debug) os << '(';
      std::apply(
          [this](auto const &...args) {
            int i = 0;
            (((i++) ? (os << comma() << " ", Impl(args)) : Impl(args)),
             ...);
          },
          t);
      if (debug) os << ')';
    } else static_assert(IsTuple<T>::value, "No matching type for print");
  }
  template <class T> void ImplWrapper(T const &t) const {
    if (debug) os << "\033[0;31m";
    Impl(t);
    if (debug) os << "\033[0m";
  }
  template <class... Ts> void print(Ts const &...ts) const {
    ((Impl(ts)), ...);
  }
  template <class F, class... Ts>
  void print_with_sep(const std::string &sep, F const &f,
                      Ts const &...ts) const {
    ImplWrapper(f), ((os << sep, ImplWrapper(ts)), ...), os << '\n';
  }
  void print_with_sep(const std::string &) const { os << '\n'; }
};
template <class... Ts> void write(Ts const &...ts) {
  Writer<cout, false, true>{}.print(ts...);
}
template <class... Ts> void print(Ts const &...ts) {
  Writer<cout, false, true>{}.print_with_sep(" ", ts...);
}
}
#define INT(...)   \
  int __VA_ARGS__; \
  read(__VA_ARGS__)
#define LL(...)   \
  ll __VA_ARGS__; \
  read(__VA_ARGS__)
#define STR(...)      \
  string __VA_ARGS__; \
  read(__VA_ARGS__)
#define CHAR(...)   \
  char __VA_ARGS__; \
  read(__VA_ARGS__)
#define DBL(...)      \
  double __VA_ARGS__; \
  read(__VA_ARGS__)
#define VEC(type, name, size) \
  vector<type> name(size);    \
  read(name)
#define VV(type, name, h, w)                     \
  vector<vector<type>> name(h, vector<type>(w)); \
  read(name)
// ------------------------------------- TEMPLATE ABOVE ------------------------------//

void solve() {

}

int main() {
  SETIO();
  // INT(t); FOR(t)
  solve();
  return 0;  
}
