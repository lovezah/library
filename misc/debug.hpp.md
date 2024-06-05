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
  bundledCode: "#line 1 \"misc/debug.hpp\"\ntemplate <typename A, typename B>\nstring\
    \ to_string(pair<A, B> x) {\n  return \"(\" + to_string(x.first) + \",\" + to_string(x.second)\
    \ + \")\";\n}\ntemplate <typename A, typename B, typename C>\nstring to_string(tuple<A,\
    \ B, C> x) {\n  return \"(\" + to_string(get<0>(x)) + \", \" + to_string(get<1>(x))\
    \ + \", \" + to_string(get<2>(x)) + \")\";\n}\ntemplate <typename A, typename\
    \ B, typename C, typename D>\nstring to_string(tuple<A, B, C, D> x) {\n  return\
    \ \"(\" + to_string(get<0>(x)) + \", \" + to_string(get<1>(x)) + \", \" + to_string(get<2>(x))\
    \ + \",\" + to_string(get<3>(x)) + \")\";\n}\nstring to_string(const string &s)\
    \ {\n  return '\"' + s + '\"';\n}\nstring to_string(bool b) {\n  return (b ? \"\
    true\" : \"false\");\n}\nstring to_string(const char *s) {\n  return to_string((string)\
    \ s);\n}\nstring to_string(vector<bool> v) {\n  bool first = true;\n  string res\
    \ = \"{\";\n  for (int i = 0; i < static_cast<int>(v.size()); i++) {\n    if (!first)\
    \ {\n      res += \", \";\n    }\n    first = false;\n    res += to_string(v[i]);\n\
    \  }\n  res += \"}\";\n  return res;\n}\ntemplate <size_t N>\nstring to_string(bitset<N>\
    \ v) {\n  string res = \"\";\n  for (size_t i = 0; i < N; i++) {\n    res += static_cast<char>('0'\
    \ + v[i]);\n  }\n  return res;\n}\ntemplate <typename A>\nstring to_string(A v)\
    \ {\n  bool first = true;\n  string res = \"{\";\n  for (const auto &x : v) {\n\
    \    if (!first) {\n      res += \", \";\n    }\n    first = false;\n    res +=\
    \ to_string(x);\n  }\n  res += \"}\";\n  return res;\n}\nvoid debug_out() {\n\
    \  cerr << endl;\n}\ntemplate <typename H, typename... T>\nvoid debug_out(H h,\
    \ T... t) {\n  cerr << \" \" << to_string(h);\n  debug_out(t...);\n}\n\n#ifdef\
    \ LOCAL\n#define debug(...) cerr << \"[\" << #__VA_ARGS__ << \"]:\", debug_out(__VA_ARGS__)\n\
    #else\n#define debug(...) (void)0\n#endif\n"
  code: "template <typename A, typename B>\nstring to_string(pair<A, B> x) {\n  return\
    \ \"(\" + to_string(x.first) + \",\" + to_string(x.second) + \")\";\n}\ntemplate\
    \ <typename A, typename B, typename C>\nstring to_string(tuple<A, B, C> x) {\n\
    \  return \"(\" + to_string(get<0>(x)) + \", \" + to_string(get<1>(x)) + \", \"\
    \ + to_string(get<2>(x)) + \")\";\n}\ntemplate <typename A, typename B, typename\
    \ C, typename D>\nstring to_string(tuple<A, B, C, D> x) {\n  return \"(\" + to_string(get<0>(x))\
    \ + \", \" + to_string(get<1>(x)) + \", \" + to_string(get<2>(x)) + \",\" + to_string(get<3>(x))\
    \ + \")\";\n}\nstring to_string(const string &s) {\n  return '\"' + s + '\"';\n\
    }\nstring to_string(bool b) {\n  return (b ? \"true\" : \"false\");\n}\nstring\
    \ to_string(const char *s) {\n  return to_string((string) s);\n}\nstring to_string(vector<bool>\
    \ v) {\n  bool first = true;\n  string res = \"{\";\n  for (int i = 0; i < static_cast<int>(v.size());\
    \ i++) {\n    if (!first) {\n      res += \", \";\n    }\n    first = false;\n\
    \    res += to_string(v[i]);\n  }\n  res += \"}\";\n  return res;\n}\ntemplate\
    \ <size_t N>\nstring to_string(bitset<N> v) {\n  string res = \"\";\n  for (size_t\
    \ i = 0; i < N; i++) {\n    res += static_cast<char>('0' + v[i]);\n  }\n  return\
    \ res;\n}\ntemplate <typename A>\nstring to_string(A v) {\n  bool first = true;\n\
    \  string res = \"{\";\n  for (const auto &x : v) {\n    if (!first) {\n     \
    \ res += \", \";\n    }\n    first = false;\n    res += to_string(x);\n  }\n \
    \ res += \"}\";\n  return res;\n}\nvoid debug_out() {\n  cerr << endl;\n}\ntemplate\
    \ <typename H, typename... T>\nvoid debug_out(H h, T... t) {\n  cerr << \" \"\
    \ << to_string(h);\n  debug_out(t...);\n}\n\n#ifdef LOCAL\n#define debug(...)\
    \ cerr << \"[\" << #__VA_ARGS__ << \"]:\", debug_out(__VA_ARGS__)\n#else\n#define\
    \ debug(...) (void)0\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: misc/debug.hpp
  requiredBy: []
  timestamp: '2024-06-05 09:11:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/debug.hpp
layout: document
redirect_from:
- /library/misc/debug.hpp
- /library/misc/debug.hpp.html
title: misc/debug.hpp
---
