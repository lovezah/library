/*
  source: neal
  link  : https://github.com/nealwu/competitive-programming/blob/master/div_conquer/count_pairs.cc
  docs  : Counts the number of pairs i < j such that compare(values[i], values[j]) is true.
*/
template<typename T_array, typename T_compare>
int64_t count_pairs(T_array values, T_compare &&compare) {
  T_array buffer(values.size());

  function<int64_t(int, int)> solve = [&](int start, int end) -> int64_t {
    if (end - start <= 1)
      return 0;

    int mid = (start + end) / 2;
    int64_t answer = solve(start, mid) + solve(mid, end);
    int left = start, right = mid, n = 0;

    while (left < mid || right < end)
      if (left < mid && (right == end || compare(values[left], values[right]))) {
        buffer[n++] = values[left++];
      } else {
        answer += left - start;
        buffer[n++] = values[right++];
      }

    copy(buffer.begin(), buffer.begin() + n, values.begin() + start);
    return answer;
  };

  return solve(0, (int) values.size());
}