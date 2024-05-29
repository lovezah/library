#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// T.order_of_key(a) -> number of elements strictly less than a
// *T.find_by_order(k) -> k-th element in increasing order