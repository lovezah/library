#pragma once

vector<int> min_factor;
vector<int> primes;
vector<bool> prime;
void sieve(int lim) {
  if (lim < 1) lim = 1;
  min_factor.assign(lim + 1, 0);
  prime.assign(lim + 1, true);
  prime[0] = prime[1] = false;
  primes.reserve(int(lim / log(lim) * 1.1));
  for (int i = 2; i <= lim; i++) {
    if (prime[i]) {
      min_factor[i] = i;
      primes.push_back(i);
    }
    for (const auto &p : primes) {
      if (p > min_factor[i] || i * p > lim) break;
      prime[i * p] = false;
      min_factor[i * p] = p;
    }
  }
}
