template <typename A, typename B>
string to_string(pair<A, B> x) {
  return "(" + to_string(x.first) + "," + to_string(x.second) + ")";
}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> x) {
  return "(" + to_string(get<0>(x)) + ", " + to_string(get<1>(x)) + ", " + to_string(get<2>(x)) + ")";
}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> x) {
  return "(" + to_string(get<0>(x)) + ", " + to_string(get<1>(x)) + ", " + to_string(get<2>(x)) + "," + to_string(get<3>(x)) + ")";
}
string to_string(const string &s) {
  return '"' + s + '"';
}
string to_string(bool b) {
  return (b ? "true" : "false");
}
string to_string(const char *s) {
  return to_string((string) s);
}
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() {
  cerr << endl;
}
template <typename H, typename... T>
void debug_out(H h, T... t) {
  cerr << " " << to_string(h);
  debug_out(t...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) (void)0
#endif