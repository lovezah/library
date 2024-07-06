template <typename T> bool setmin(T& a, T b) { if (b < a) { a = b;  return true; } return false; }
template <typename T> bool setmax(T& a, T b) { if (b > a) { a = b;  return true; } return false; }