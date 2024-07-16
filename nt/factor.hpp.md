---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://github.com/kth-competitive-programming/kactl/blob/main/content/number-theory/Factor.h
  bundledCode: "#line 1 \"nt/factor.hpp\"\n/*\n  source: kactl\n  link  : https://github.com/kth-competitive-programming/kactl/blob/main/content/number-theory/Factor.h\n\
    \  docs  : O(N^{1/4}) \n          return prime factors for a number, in arbitray\
    \ order\n*/\n#define rep(i, a, b) for(int i = a; i < (b); ++i)\n#define trav(a,\
    \ x) for(auto& a : x)\n#define sz(x) (int)(x).size()\ntypedef pair<int, int> pii;\n\
    typedef vector<int> vi;\n\ntypedef unsigned long long ull;\null modmul(ull a,\
    \ ull b, ull M) {\n\tll ret = a * b - M * ull(1.L / M * a * b);\n\treturn ret\
    \ + M * (ret < 0) - M * (ret >= (ll)M);\n}\null modpow(ull b, ull e, ull mod)\
    \ {\n\tull ans = 1;\n\tfor (; e; b = modmul(b, b, mod), e /= 2)\n\t\tif (e & 1)\
    \ ans = modmul(ans, b, mod);\n\treturn ans;\n}\n\nbool isPrime(ull n) {\n\tif\
    \ (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;\n\tull A[] = {2, 325, 9375, 28178,\
    \ 450775, 9780504, 1795265022},\n\t    s = __builtin_ctzll(n-1), d = n >> s;\n\
    \tfor (ull a : A) {   // ^ count trailing zeroes\n\t\tull p = modpow(a%n, d, n),\
    \ i = s;\n\t\twhile (p != 1 && p != n - 1 && a % n && i--)\n\t\t\tp = modmul(p,\
    \ p, n);\n\t\tif (p != n-1 && i != s) return 0;\n\t}\n\treturn 1;\n}\n\null pollard(ull\
    \ n) {\n\tauto f = [n](ull x) { return modmul(x, x, n) + 1; };\n\tull x = 0, y\
    \ = 0, t = 30, prd = 2, i = 1, q;\n\twhile (t++ % 40 || __gcd(prd, n) == 1) {\n\
    \t\tif (x == y) x = ++i, y = f(x);\n\t\tif ((q = modmul(prd, max(x,y) - min(x,y),\
    \ n))) prd = q;\n\t\tx = f(x), y = f(f(y));\n\t}\n\treturn __gcd(prd, n);\n}\n\
    vector<ull> factor(ull n) {\n\tif (n == 1) return {};\n\tif (isPrime(n)) return\
    \ {n};\n\tull x = pollard(n);\n\tauto l = factor(x), r = factor(n / x);\n\tl.insert(l.end(),\
    \ all(r));\n\treturn l;\n}\n"
  code: "/*\n  source: kactl\n  link  : https://github.com/kth-competitive-programming/kactl/blob/main/content/number-theory/Factor.h\n\
    \  docs  : O(N^{1/4}) \n          return prime factors for a number, in arbitray\
    \ order\n*/\n#define rep(i, a, b) for(int i = a; i < (b); ++i)\n#define trav(a,\
    \ x) for(auto& a : x)\n#define sz(x) (int)(x).size()\ntypedef pair<int, int> pii;\n\
    typedef vector<int> vi;\n\ntypedef unsigned long long ull;\null modmul(ull a,\
    \ ull b, ull M) {\n\tll ret = a * b - M * ull(1.L / M * a * b);\n\treturn ret\
    \ + M * (ret < 0) - M * (ret >= (ll)M);\n}\null modpow(ull b, ull e, ull mod)\
    \ {\n\tull ans = 1;\n\tfor (; e; b = modmul(b, b, mod), e /= 2)\n\t\tif (e & 1)\
    \ ans = modmul(ans, b, mod);\n\treturn ans;\n}\n\nbool isPrime(ull n) {\n\tif\
    \ (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;\n\tull A[] = {2, 325, 9375, 28178,\
    \ 450775, 9780504, 1795265022},\n\t    s = __builtin_ctzll(n-1), d = n >> s;\n\
    \tfor (ull a : A) {   // ^ count trailing zeroes\n\t\tull p = modpow(a%n, d, n),\
    \ i = s;\n\t\twhile (p != 1 && p != n - 1 && a % n && i--)\n\t\t\tp = modmul(p,\
    \ p, n);\n\t\tif (p != n-1 && i != s) return 0;\n\t}\n\treturn 1;\n}\n\null pollard(ull\
    \ n) {\n\tauto f = [n](ull x) { return modmul(x, x, n) + 1; };\n\tull x = 0, y\
    \ = 0, t = 30, prd = 2, i = 1, q;\n\twhile (t++ % 40 || __gcd(prd, n) == 1) {\n\
    \t\tif (x == y) x = ++i, y = f(x);\n\t\tif ((q = modmul(prd, max(x,y) - min(x,y),\
    \ n))) prd = q;\n\t\tx = f(x), y = f(f(y));\n\t}\n\treturn __gcd(prd, n);\n}\n\
    vector<ull> factor(ull n) {\n\tif (n == 1) return {};\n\tif (isPrime(n)) return\
    \ {n};\n\tull x = pollard(n);\n\tauto l = factor(x), r = factor(n / x);\n\tl.insert(l.end(),\
    \ all(r));\n\treturn l;\n}"
  dependsOn: []
  isVerificationFile: false
  path: nt/factor.hpp
  requiredBy: []
  timestamp: '2024-07-16 11:24:45+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: nt/factor.hpp
layout: document
redirect_from:
- /library/nt/factor.hpp
- /library/nt/factor.hpp.html
title: nt/factor.hpp
---
