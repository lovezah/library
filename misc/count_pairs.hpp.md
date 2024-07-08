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
    - https://github.com/nealwu/competitive-programming/blob/master/div_conquer/count_pairs.cc
  bundledCode: "#line 1 \"misc/count_pairs.hpp\"\n/*\n  source: neal\n  link  : https://github.com/nealwu/competitive-programming/blob/master/div_conquer/count_pairs.cc\n\
    \  docs  : Counts the number of pairs i < j such that compare(values[i], values[j])\
    \ is true.\n*/\ntemplate<typename T_array, typename T_compare>\nint64_t count_pairs(T_array\
    \ values, T_compare &&compare) {\n  T_array buffer(values.size());\n\n  function<int64_t(int,\
    \ int)> solve = [&](int start, int end) -> int64_t {\n    if (end - start <= 1)\n\
    \      return 0;\n\n    int mid = (start + end) / 2;\n    int64_t answer = solve(start,\
    \ mid) + solve(mid, end);\n    int left = start, right = mid, n = 0;\n\n    while\
    \ (left < mid || right < end)\n      if (left < mid && (right == end || compare(values[left],\
    \ values[right]))) {\n        buffer[n++] = values[left++];\n      } else {\n\
    \        answer += left - start;\n        buffer[n++] = values[right++];\n   \
    \   }\n\n    copy(buffer.begin(), buffer.begin() + n, values.begin() + start);\n\
    \    return answer;\n  };\n\n  return solve(0, (int) values.size());\n}\n"
  code: "/*\n  source: neal\n  link  : https://github.com/nealwu/competitive-programming/blob/master/div_conquer/count_pairs.cc\n\
    \  docs  : Counts the number of pairs i < j such that compare(values[i], values[j])\
    \ is true.\n*/\ntemplate<typename T_array, typename T_compare>\nint64_t count_pairs(T_array\
    \ values, T_compare &&compare) {\n  T_array buffer(values.size());\n\n  function<int64_t(int,\
    \ int)> solve = [&](int start, int end) -> int64_t {\n    if (end - start <= 1)\n\
    \      return 0;\n\n    int mid = (start + end) / 2;\n    int64_t answer = solve(start,\
    \ mid) + solve(mid, end);\n    int left = start, right = mid, n = 0;\n\n    while\
    \ (left < mid || right < end)\n      if (left < mid && (right == end || compare(values[left],\
    \ values[right]))) {\n        buffer[n++] = values[left++];\n      } else {\n\
    \        answer += left - start;\n        buffer[n++] = values[right++];\n   \
    \   }\n\n    copy(buffer.begin(), buffer.begin() + n, values.begin() + start);\n\
    \    return answer;\n  };\n\n  return solve(0, (int) values.size());\n}"
  dependsOn: []
  isVerificationFile: false
  path: misc/count_pairs.hpp
  requiredBy: []
  timestamp: '2024-07-08 13:55:24+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/count_pairs.hpp
layout: document
redirect_from:
- /library/misc/count_pairs.hpp
- /library/misc/count_pairs.hpp.html
title: misc/count_pairs.hpp
---
