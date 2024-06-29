vector<int> min_factor;
vector<int> primes;
vector<bool> prime;
void sieve(int N) {
  min_factor.assign(N + 1, 0);
  prime.assign(N + 1, true);
  prime[0] = prime[1] = false;
  for (int i = 2; i <= N; i++) {
    if (prime[i]) {
      min_factor[i] = i;
      primes.push_back(i);
    }
    for (const auto &p : primes) {
      if (p > min_factor[i] || i * p > N) break;
      prime[i * p] = false;
      min_factor[i * p] = p;
    }
  }
}
