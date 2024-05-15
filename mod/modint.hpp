#pragma once

template <int P>
struct modint {
  int v;
  constexpr modint() : v {0} {}
  constexpr modint(int64_t v) : v {int(v % mod())} { if (v < 0) v += mod(); }

  static int MOD;
  constexpr static int mod() {
    if (P > 0) {
      return P;
    } else {
      return MOD;
    }
  }
  constexpr static void set_mod(int MOD_) {
    MOD = MOD_;
  }

  explicit operator int() const { return v; }
  friend std::ostream& operator << (std::ostream& out, const modint &n) {
    return out << int(n);
  }
  friend std::istream& operator >> (std::istream& in, modint &n) {
    int64_t v_;
    in >> v_;
    n = modint(v_);
    return in;
  }
  friend bool operator == (const modint &a, const modint &b) {
    return a.v == b.v;
  }
  friend bool operator != (const modint &a, const modint &b) {
    return a.v != b.v;
  }

  constexpr modint inv() const {
    int a = val, b = mod(), u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b), swap(u -= t * v, v);
    }
    return modint(u);
  }
  friend modint inv(const modint &m) {
    return m.inv();
  }
  modint operator-() const {
    modint res;
    res.v = v ? mod() - v : 0;
    return res;
  }
  modint operator+() const {
    return modint(*this);
  }
  modint& operator ++ () {
    v++;
    if (v == mod()) v = 0;
    return *this;
  }
  modint& operator -- () {
    if (v == 0) v = mod();
    v--;
    return *this;
  }
  modint& operator += (const modint &o) {
    v -= mod() - o.v;
    v = v < 0 ? v + mod() : v;
    return *this;
  }
  modint& operator -= (const modint &o) {
    v -= o.v;
    v = v < 0 ? v + mod() : v;
    return *this;
  }
  modint& operator *= (const modint &o) {
    v = int(int64_t(v) * int64_t(o.v) % mod());
    return *this;
  }
  modint& operator /= (const modint &o) {
    return *this *= o.inv();
  }

  friend modint operator ++ (modint &a, int) {
    modint res = a;
    ++a;
    return res;
  }
  friend modint operator -- (modint &a, int) {
    modint res = a;
    --a;
    return res;
  }
  friend modint operator + (const modint &a, const modint &b) {
    return modint(a) += b;
  }
  friend modint operator - (const modint &a, const modint &b) {
    return modint(a) -= b;
  }
  friend modint operator * (const modint &a, const modint &b) {
    return modint(a) *= b;
  }
  friend modint operator / (const modint &a, const modint &b) {
    return modint(a) /= b;
  }
};

template <typename T> T pow(T a, int64_t b) {
	assert(b >= 0);
  T r = 1;
  while (b) {
    if (b & 1) r *= a;
    b >>= 1;
    a *= a;
  }
  return r;
}

template<>
int modint<0>::MOD = 998244353;

using mint = modint<998244353>; // 1000000007
