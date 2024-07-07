vector<mint> fact, ifact;

void init() {
  int N = 110000;
  fact.resize(N);
  fact[0] = 1;
  for (int i = 1; i < N; i++) fact[i] = fact[i-1] * i;
  ifact.resize(N);
  ifact.back() = 1 / fact.back();
  for (int i = N - 1; i > 0; i--) ifact[i-1] = ifact[i] * i;
}

mint ncr(int n, int k) {
  if (k < 0 || k > n) return 0;
  return fact[n] * ifact[k] * ifact[n-k];
}