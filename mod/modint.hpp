#pragma once

// template from maspy
template <int mod>
struct modint {
  static constexpr u32 umod = u32(mod);
  static_assert(umod < u32(1) << 31);
  u32 val;
  static u32 MOD;
  constexpr static u32 get_mod() {
    if (mod > 0) {
      return umod;
    } else {
      return MOD;
    }
  }
  constexpr static void set_mod(int x) {
    MOD = u32(x);
  }
  friend ostream& operator << (ostream& out, const modint& n) { 
    return out << u32(n.val); 
  }
  friend istream& operator >> (istream& in, modint& n) { 
    ll v_; in >> v_; n = modint(v_); return in; 
  }
  static modint raw(u32 v) {
    modint x;
    x.val = v;
    return x;
  }
  constexpr modint() : val(0) {}
  constexpr modint(u32 x) : val(x % get_mod()) {}
  constexpr modint(u64 x) : val(x % get_mod()) {}
  constexpr modint(int x) : val((x %= (int)get_mod()) < 0 ? x + (int)get_mod() : x){};
  constexpr modint(ll x) : val((x %= (int)get_mod()) < 0 ? x + (int)get_mod() : x){};
  constexpr modint(i128 x) : val((x %= (int)get_mod()) < 0 ? x + (int)get_mod() : x){};
  bool operator<(const modint &other) const { return val < other.val; }
  modint &operator+=(const modint &p) {
    if ((val += p.val) >= get_mod()) val -= get_mod();
    return *this;
  }
  modint &operator-=(const modint &p) {
    if ((val += get_mod() - p.val) >= get_mod()) val -= get_mod();
    return *this;
  }
  modint &operator*=(const modint &p) {
    val = u64(val) * p.val % get_mod();
    return *this;
  }
  modint &operator/=(const modint &p) {
    *this *= p.inv();
    return *this;
  }
  modint operator-() const { return modint::raw(val ? get_mod() - val : u32(0)); }
  modint operator+(const modint &p) const { return modint(*this) += p; }
  modint operator-(const modint &p) const { return modint(*this) -= p; }
  modint operator*(const modint &p) const { return modint(*this) *= p; }
  modint operator/(const modint &p) const { return modint(*this) /= p; }
  bool operator==(const modint &p) const { return val == p.val; }
  bool operator!=(const modint &p) const { return val != p.val; }
  modint inv() const {
    int a = val, b = get_mod(), u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b), swap(u -= t * v, v);
    }
    return modint(u);
  }
  modint pow(ll n) const {
    assert(n >= 0);
    modint ret(1), mul(val);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }
};
template <int mod>
u32 modint<mod>::MOD;

template <> 
u32 modint<0>::MOD = 1000000007;

constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
using mint = modint<MOD>;
