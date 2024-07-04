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
  bundledCode: "#line 1 \"geo/point.hpp\"\ntemplate <typename T> struct Point {\n\
    public:\n\tT x, y;\n\tPoint() : x(0), y(0) {}\n\tPoint(T x_, T y_) : x(x_), y(y_)\
    \ {}\n\ttemplate <typename U> explicit Point(const Point<U>& p) : x(p.x), y(p.y)\
    \ {}\n\tPoint(const std::pair<T, T>& p) : x(p.first), y(p.second) {}\n\tPoint(const\
    \ std::complex<T>& p) : x(real(p)), y(imag(p)) {}\n\texplicit operator std::pair<T,\
    \ T> () const { return std::pair<T, T>(x, y); }\n\texplicit operator std::complex<T>\
    \ () const { return std::complex<T>(x, y); }\n\n\tfriend std::ostream& operator\
    \ << (std::ostream& o, const Point& p) { return o << '(' << p.x << ',' << p.y\
    \ << ')'; }\n\tfriend std::istream& operator >> (std::istream& i, Point& p) {\
    \ return i >> p.x >> p.y; }\n\tfriend bool operator == (const Point& a, const\
    \ Point& b) { return a.x == b.x && a.y == b.y; }\n\tfriend bool operator != (const\
    \ Point& a, const Point& b) { return !(a==b); }\n\n\tPoint operator + () const\
    \ { return Point(+x, +y); }\n\tPoint operator - () const { return Point(-x, -y);\
    \ }\n\n\tPoint& operator += (const Point& p) { x += p.x, y += p.y; return *this;\
    \ }\n\tPoint& operator -= (const Point& p) { x -= p.x, y -= p.y; return *this;\
    \ }\n\tPoint& operator *= (const T& t) { x *= t, y *= t; return *this; }\n\tPoint&\
    \ operator /= (const T& t) { x /= t, y /= t; return *this; }\n\n\tfriend Point\
    \ operator + (const Point& a, const Point& b) { return Point(a.x+b.x, a.y+b.y);\
    \ }\n\tfriend Point operator - (const Point& a, const Point& b) { return Point(a.x-b.x,\
    \ a.y-b.y); }\n\tfriend Point operator * (const Point& a, const T& t) { return\
    \ Point(a.x*t, a.y*t); }\n\tfriend Point operator * (const T& t ,const Point&\
    \ a) { return Point(t*a.x, t*a.y); }\n\tfriend Point operator / (const Point&\
    \ a, const T& t) { return Point(a.x/t, a.y/t); }\n\n\tT dist2() const { return\
    \ x * x + y * y; }\n\tauto dist() const { return std::sqrt(dist2()); }\n\tPoint\
    \ unit() const { return *this / this->dist(); }\n\tauto angle() const { return\
    \ std::atan2(y, x); }\n\n\tT int_norm() const { return __gcd(x,y); }\n\tPoint\
    \ int_unit() const { if (!x && !y) return *this; return *this / this->int_norm();\
    \ }\n\n\t// Convenient free-functions, mostly for generic interop\n\tfriend auto\
    \ norm(const Point& a) { return a.dist2(); }\n\tfriend auto abs(const Point& a)\
    \ { return a.dist(); }\n\tfriend auto unit(const Point& a) { return a.unit();\
    \ }\n\tfriend auto arg(const Point& a) { return a.angle(); }\n\tfriend auto int_norm(const\
    \ Point& a) { return a.int_norm(); }\n\tfriend auto int_unit(const Point& a) {\
    \ return a.int_unit(); }\n\n\tPoint perp_cw() const { return Point(y, -x); }\n\
    \tPoint perp_ccw() const { return Point(-y, x); }\n\n\tfriend T dot(const Point&\
    \ a, const Point& b) { return a.x * b.x + a.y * b.y; }\n\tfriend T cross(const\
    \ Point& a, const Point& b) { return a.x * b.y - a.y * b.x; }\n\tfriend T cross3(const\
    \ Point& a, const Point& b, const Point& c) { return cross(b-a, c-a); }\n\n\t\
    // Complex numbers and rotation\n\tfriend Point conj(const Point& a) { return\
    \ Point(a.x, -a.y); }\n\n\t// Returns conj(a) * b\n\tfriend Point dot_cross(const\
    \ Point& a, const Point& b) { return Point(dot(a, b), cross(a, b)); }\n\tfriend\
    \ Point cmul(const Point& a, const Point& b) { return dot_cross(conj(a), b); }\n\
    \tfriend Point cdiv(const Point& a, const Point& b) { return dot_cross(b, a) /\
    \ b.norm(); }\n\n\t// Must be a unit vector; otherwise multiplies the result by\
    \ abs(u)\n\tPoint rotate(const Point& u) const { return dot_cross(conj(u), *this);\
    \ }\n\tPoint unrotate(const Point& u) const { return dot_cross(u, *this); }\n\n\
    \tfriend bool lex_less(const Point& a, const Point& b) {\n\t\treturn std::tie(a.x,\
    \ a.y) < std::tie(b.x, b.y);\n\t}\n\n\tfriend bool same_dir(const Point& a, const\
    \ Point& b) { return cross(a,b) == 0 && dot(a,b) > 0; }\n\n\t// check if 180 <=\
    \ s..t < 360\n\tfriend bool is_reflex(const Point& a, const Point& b) { auto c\
    \ = cross(a,b); return c ? (c < 0) : (dot(a, b) < 0); }\n\n\t// operator < (s,t)\
    \ for angles in [base,base+2pi)\n\tfriend bool angle_less(const Point& base, const\
    \ Point& s, const Point& t) {\n\t\tint r = is_reflex(base, s) - is_reflex(base,\
    \ t);\n\t\treturn r ? (r < 0) : (0 < cross(s, t));\n\t}\n\n\tfriend auto angle_cmp(const\
    \ Point& base) {\n\t\treturn [base](const Point& s, const Point& t) { return angle_less(base,\
    \ s, t); };\n\t}\n\tfriend auto angle_cmp_center(const Point& center, const Point&\
    \ dir) {\n\t\treturn [center, dir](const Point& s, const Point& t) -> bool { return\
    \ angle_less(dir, s-center, t-center); };\n\t}\n\n\t// is p in [s,t] taken ccw?\
    \ 1/0/-1 for in/border/out\n\tfriend int angle_between(const Point& s, const Point&\
    \ t, const Point& p) {\n\t\tif (same_dir(p, s) || same_dir(p, t)) return 0;\n\t\
    \treturn angle_less(s, p, t) ? 1 : -1;\n\t}\n};\n"
  code: "template <typename T> struct Point {\npublic:\n\tT x, y;\n\tPoint() : x(0),\
    \ y(0) {}\n\tPoint(T x_, T y_) : x(x_), y(y_) {}\n\ttemplate <typename U> explicit\
    \ Point(const Point<U>& p) : x(p.x), y(p.y) {}\n\tPoint(const std::pair<T, T>&\
    \ p) : x(p.first), y(p.second) {}\n\tPoint(const std::complex<T>& p) : x(real(p)),\
    \ y(imag(p)) {}\n\texplicit operator std::pair<T, T> () const { return std::pair<T,\
    \ T>(x, y); }\n\texplicit operator std::complex<T> () const { return std::complex<T>(x,\
    \ y); }\n\n\tfriend std::ostream& operator << (std::ostream& o, const Point& p)\
    \ { return o << '(' << p.x << ',' << p.y << ')'; }\n\tfriend std::istream& operator\
    \ >> (std::istream& i, Point& p) { return i >> p.x >> p.y; }\n\tfriend bool operator\
    \ == (const Point& a, const Point& b) { return a.x == b.x && a.y == b.y; }\n\t\
    friend bool operator != (const Point& a, const Point& b) { return !(a==b); }\n\
    \n\tPoint operator + () const { return Point(+x, +y); }\n\tPoint operator - ()\
    \ const { return Point(-x, -y); }\n\n\tPoint& operator += (const Point& p) { x\
    \ += p.x, y += p.y; return *this; }\n\tPoint& operator -= (const Point& p) { x\
    \ -= p.x, y -= p.y; return *this; }\n\tPoint& operator *= (const T& t) { x *=\
    \ t, y *= t; return *this; }\n\tPoint& operator /= (const T& t) { x /= t, y /=\
    \ t; return *this; }\n\n\tfriend Point operator + (const Point& a, const Point&\
    \ b) { return Point(a.x+b.x, a.y+b.y); }\n\tfriend Point operator - (const Point&\
    \ a, const Point& b) { return Point(a.x-b.x, a.y-b.y); }\n\tfriend Point operator\
    \ * (const Point& a, const T& t) { return Point(a.x*t, a.y*t); }\n\tfriend Point\
    \ operator * (const T& t ,const Point& a) { return Point(t*a.x, t*a.y); }\n\t\
    friend Point operator / (const Point& a, const T& t) { return Point(a.x/t, a.y/t);\
    \ }\n\n\tT dist2() const { return x * x + y * y; }\n\tauto dist() const { return\
    \ std::sqrt(dist2()); }\n\tPoint unit() const { return *this / this->dist(); }\n\
    \tauto angle() const { return std::atan2(y, x); }\n\n\tT int_norm() const { return\
    \ __gcd(x,y); }\n\tPoint int_unit() const { if (!x && !y) return *this; return\
    \ *this / this->int_norm(); }\n\n\t// Convenient free-functions, mostly for generic\
    \ interop\n\tfriend auto norm(const Point& a) { return a.dist2(); }\n\tfriend\
    \ auto abs(const Point& a) { return a.dist(); }\n\tfriend auto unit(const Point&\
    \ a) { return a.unit(); }\n\tfriend auto arg(const Point& a) { return a.angle();\
    \ }\n\tfriend auto int_norm(const Point& a) { return a.int_norm(); }\n\tfriend\
    \ auto int_unit(const Point& a) { return a.int_unit(); }\n\n\tPoint perp_cw()\
    \ const { return Point(y, -x); }\n\tPoint perp_ccw() const { return Point(-y,\
    \ x); }\n\n\tfriend T dot(const Point& a, const Point& b) { return a.x * b.x +\
    \ a.y * b.y; }\n\tfriend T cross(const Point& a, const Point& b) { return a.x\
    \ * b.y - a.y * b.x; }\n\tfriend T cross3(const Point& a, const Point& b, const\
    \ Point& c) { return cross(b-a, c-a); }\n\n\t// Complex numbers and rotation\n\
    \tfriend Point conj(const Point& a) { return Point(a.x, -a.y); }\n\n\t// Returns\
    \ conj(a) * b\n\tfriend Point dot_cross(const Point& a, const Point& b) { return\
    \ Point(dot(a, b), cross(a, b)); }\n\tfriend Point cmul(const Point& a, const\
    \ Point& b) { return dot_cross(conj(a), b); }\n\tfriend Point cdiv(const Point&\
    \ a, const Point& b) { return dot_cross(b, a) / b.norm(); }\n\n\t// Must be a\
    \ unit vector; otherwise multiplies the result by abs(u)\n\tPoint rotate(const\
    \ Point& u) const { return dot_cross(conj(u), *this); }\n\tPoint unrotate(const\
    \ Point& u) const { return dot_cross(u, *this); }\n\n\tfriend bool lex_less(const\
    \ Point& a, const Point& b) {\n\t\treturn std::tie(a.x, a.y) < std::tie(b.x, b.y);\n\
    \t}\n\n\tfriend bool same_dir(const Point& a, const Point& b) { return cross(a,b)\
    \ == 0 && dot(a,b) > 0; }\n\n\t// check if 180 <= s..t < 360\n\tfriend bool is_reflex(const\
    \ Point& a, const Point& b) { auto c = cross(a,b); return c ? (c < 0) : (dot(a,\
    \ b) < 0); }\n\n\t// operator < (s,t) for angles in [base,base+2pi)\n\tfriend\
    \ bool angle_less(const Point& base, const Point& s, const Point& t) {\n\t\tint\
    \ r = is_reflex(base, s) - is_reflex(base, t);\n\t\treturn r ? (r < 0) : (0 <\
    \ cross(s, t));\n\t}\n\n\tfriend auto angle_cmp(const Point& base) {\n\t\treturn\
    \ [base](const Point& s, const Point& t) { return angle_less(base, s, t); };\n\
    \t}\n\tfriend auto angle_cmp_center(const Point& center, const Point& dir) {\n\
    \t\treturn [center, dir](const Point& s, const Point& t) -> bool { return angle_less(dir,\
    \ s-center, t-center); };\n\t}\n\n\t// is p in [s,t] taken ccw? 1/0/-1 for in/border/out\n\
    \tfriend int angle_between(const Point& s, const Point& t, const Point& p) {\n\
    \t\tif (same_dir(p, s) || same_dir(p, t)) return 0;\n\t\treturn angle_less(s,\
    \ p, t) ? 1 : -1;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: geo/point.hpp
  requiredBy: []
  timestamp: '2024-07-04 09:29:04+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geo/point.hpp
layout: document
redirect_from:
- /library/geo/point.hpp
- /library/geo/point.hpp.html
title: geo/point.hpp
---
