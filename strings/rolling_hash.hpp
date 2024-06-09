const int mod1 = 1000000009;
const int mod2 = 993244853;
struct hashv {
  int f, s;
  hashv() {}
  hashv(int _f, int _s) : f(_f), s(_s) {}
  friend bool operator==(hashv a, hashv b) {
    return a.f == b.f && a.s == b.s;
  }
  friend bool operator!=(hashv a, hashv b) {
    return a.f != b.f || a.s != b.s;
  }
  friend hashv operator+(hashv a, hashv b) {
    hashv c = hashv(a.f + b.f, a.s + b.s);
    if (c.f >= mod1) c.f -= mod1;
    if (c.s >= mod2) c.s -= mod2;
    return c;
  }
  friend hashv operator-(hashv a, hashv b) {
    hashv c = hashv(a.f - b.f, a.s - b.s);
    if (c.f < 0) c.f += mod1;
    if (c.s < 0) c.s += mod2;
    return c;
  }
  friend hashv operator*(hashv a, hashv b) {
    return hashv(1ll * a.f * b.f % mod1, 1ll * a.s * b.s % mod2);
  }  
};