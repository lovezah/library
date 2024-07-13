const int MAXN = 500010;
struct node {
  node *go[26], *fail;
  int cnt;
} pool[MAXN], *nptr = pool, *ids[MAXN], *root;

node *newnode() {
  node *u = nptr++;
  for (int i = 0; i < 26; i++) u->go[i] = NULL;
  u->fail = NULL;
  u->cnt = 0;
  return u;
}

node *insert(const string &s) {
  node *u = root;
  for (char ch : s) {
    int c = ch - 'a';
    if (!u->go[c]) u->go[c] = newnode();
    u = u->go[c];
  }
  return u;
}

vector<node*> build() {
  vector<node*> q;
  q.push_back(root);
  root->fail = root;
  for (int i = 0; i < (int) q.size(); i++) {
    node *u = q[i];
    for (int j = 0; j < 26; j++) {
      if (u->go[j]) {
        if (u == root) u->go[j]->fail = root;
        else u->go[j]->fail = u->fail->go[j];
        q.push_back(u->go[j]);
      } else {
        if (u == root) u->go[j] = root;
        else u->go[j] = u->fail->go[j];
      }
    }
  }
}