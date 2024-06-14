#define FOR(i, a, n) for (int i = (a); i < (n); i++)
#define F0R(i, n) FOR(i, 0, n)
#define FORd(i, a, n) for (int i = (n) - 1; i >= a; i--)
#define F0Rd(i, n) FORd(i, 0, n)
#define trav(a, v) for (auto &a : v)

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pli = pair<ll, int>;
using db = double;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define si(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define remDup(x) sort(all(x)), (x).resize(unique(all(x)) - x.begin())

template <typename T, size_t S>
using ar = array<T, S>;
template <typename T>
using vt = vector<T>;
using vi = vt<int>;
using vl = vt<ll>;
using vb = vt<bool>;
using vd = vt<db>;
using vpi = vt<pi>;
using vpl = vt<pl>;
using vpli = vt<pli>;

template <typename A, typename B> bool ckmax(A &a, B b) { return b > a ? a = b, true : false; }
template <typename A, typename B> bool ckmin(A &a, B b) { return b < a ? a = b, true : false; }
template <typename A> using pq = priority_queue<A>;
template <typename A> using pqg = priority_queue<A, vt<A>, greater<A>>;

const char nl = '\n';