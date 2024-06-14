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
  bundledCode: '#line 1 "misc/lazy.hpp"

    #define rng(i, a, n) for (int i = (a); i < (n); i++)

    #define rep(i, n) rng(i, 0, n)

    #define gnr(i, a, n) for (int i = (n) - 1; i >= a; i--)

    #define per(i, n) gnr(i, 0, n)

    #define trav(a, v) for (auto &a : v)


    using pi = pair<int, int>;

    using pl = pair<ll, ll>;

    using pli = pair<ll, int>;

    using db = double;


    #define pb push_back

    #define mp make_pair

    #define f first

    #define s second

    #define si(x) ((int) (x).size())

    #define all(x) (x).begin(), (x).end()

    #define ins insert

    #define lb lower_bound

    #define ub upper_bound


    template <typename T>

    using vt = vector<T>;

    using vi = vt<int>;

    using vl = vt<ll>;

    using vb = vt<bool>;

    using vd = vt<db>;

    using vpi = vt<pi>;

    using vpl = vt<pl>;

    using vpli = vt<pli>;


    template <typename A, typename B> bool ckmax(A &a, B b) { return b > a ? a = b,
    true : false; }

    template <typename A, typename B> bool ckmin(A &a, B b) { return b < a ? a = b,
    true : false; }

    template <typename A> using pq = priority_queue<A>;

    template <typename A> using pqg = priority_queue<A, vt<A>, greater<A>>;

    '
  code: '#define rng(i, a, n) for (int i = (a); i < (n); i++)

    #define rep(i, n) rng(i, 0, n)

    #define gnr(i, a, n) for (int i = (n) - 1; i >= a; i--)

    #define per(i, n) gnr(i, 0, n)

    #define trav(a, v) for (auto &a : v)


    using pi = pair<int, int>;

    using pl = pair<ll, ll>;

    using pli = pair<ll, int>;

    using db = double;


    #define pb push_back

    #define mp make_pair

    #define f first

    #define s second

    #define si(x) ((int) (x).size())

    #define all(x) (x).begin(), (x).end()

    #define ins insert

    #define lb lower_bound

    #define ub upper_bound


    template <typename T>

    using vt = vector<T>;

    using vi = vt<int>;

    using vl = vt<ll>;

    using vb = vt<bool>;

    using vd = vt<db>;

    using vpi = vt<pi>;

    using vpl = vt<pl>;

    using vpli = vt<pli>;


    template <typename A, typename B> bool ckmax(A &a, B b) { return b > a ? a = b,
    true : false; }

    template <typename A, typename B> bool ckmin(A &a, B b) { return b < a ? a = b,
    true : false; }

    template <typename A> using pq = priority_queue<A>;

    template <typename A> using pqg = priority_queue<A, vt<A>, greater<A>>;'
  dependsOn: []
  isVerificationFile: false
  path: misc/lazy.hpp
  requiredBy: []
  timestamp: '2024-06-14 20:57:00+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/lazy.hpp
layout: document
redirect_from:
- /library/misc/lazy.hpp
- /library/misc/lazy.hpp.html
title: misc/lazy.hpp
---
