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
  bundledCode: '#line 1 "ds/ordered_set.hpp"

    #include <ext/pb_ds/assoc_container.hpp>

    using namespace __gnu_pbds;


    template <class T>

    using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

    // T.order_of_key(a) -> number of elements strictly less than a

    // *T.find_by_order(k) -> k-th element in increasing order

    '
  code: '#include <ext/pb_ds/assoc_container.hpp>

    using namespace __gnu_pbds;


    template <class T>

    using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

    // T.order_of_key(a) -> number of elements strictly less than a

    // *T.find_by_order(k) -> k-th element in increasing order'
  dependsOn: []
  isVerificationFile: false
  path: ds/ordered_set.hpp
  requiredBy: []
  timestamp: '2024-05-29 16:41:34+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/ordered_set.hpp
layout: document
redirect_from:
- /library/ds/ordered_set.hpp
- /library/ds/ordered_set.hpp.html
title: ds/ordered_set.hpp
---
