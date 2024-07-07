/*
  source: template from kactl
  link  : https://github.com/kth-competitive-programming/kactl/blob/main/content/graph/BellmanFord.h
  docs  : Unreachable nodes get dist = inf; nodes reachable through negative-weight cycles get dist = -inf.
*/
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
using ll = int64_t;
using pii = pair<int, int>;
using vi = vector<int>;

const ll inf = numeric_limits<int64_t>::max();
struct Ed { int a, b, w; int s() { return a < b ? a : -a; }};
struct Node { ll dist = inf; int prev = -1; };

void bellman_ford(vector<Node>& nodes, vector<Ed>& eds, int s) {
	nodes[s].dist = 0;
	sort(all(eds), [](Ed a, Ed b) { return a.s() < b.s(); });

	int lim = sz(nodes) / 2 + 2; // /3+100 with shuffled vertices
	rep(i,0,lim) for (Ed ed : eds) {
		Node cur = nodes[ed.a], &dest = nodes[ed.b];
		if (abs(cur.dist) == inf) continue;
		ll d = cur.dist + ed.w;
		if (d < dest.dist) {
			dest.prev = ed.a;
			dest.dist = (i < lim-1 ? d : -inf);
		}
	}
	rep(i,0,lim) for (Ed e : eds) {
		if (nodes[e.a].dist == -inf)
			nodes[e.b].dist = -inf;
	}
}