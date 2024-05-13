#pragma once

vt<int> min_factor;
vt<int> primes;
vt<bool> prime;
void sieve(int lim) {
  ckmax(lim, 1);
  min_factor.assign(lim + 1, 0);
  prime.assign(lim + 1, true);
  prime[0] = prime[1] = false;
  primes.reserve(int(lim / log(lim) * 1.1));
  rep(i, 2, lim + 1) {
    if (prime[i]) {
      min_factor[i] = i;
      primes.eb(i);
    }
    for (const auto &p : primes) {
      if (p > min_factor[i] || i * p > lim) break;
      prime[i * p] = false;
      min_factor[i * p] = p;
    }
  }
}
