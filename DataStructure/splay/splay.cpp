#include<cstdio>
#include<algorithm>
#define INF 0x7FFFFFFF
#define gi gI()
#define rep(i, l, r) for (int i = l; i <= r; ++i)

using namespace std;

int const MAXN = 300001;

typedef long long ll;

inline ll gI() {
    ll p = 0, flag = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') flag = -1, c = getchar();
    while ('0' <= c && c <= '9') p = p * 10 + (c - '0'), c = getchar();
    return p * flag;
}

int A[MAXN];

struct Node {
    Node *ch[2], *p;
    int s, v, mx;
    int add;
    bool rev;
    Node() : s(0), v(~INF), mx(~INF), add(0) {}
    bool d() {
	return this == p -> ch[1];
    }
    void setc(Node*c, int d) {
	ch[d] = c;
	c -> p = this;
    }
    void addIt(int ad) {
	add += ad;
	mx += ad;
	v += ad;
    }
    void revIt() {
	rev ^= 1;
    }
    void relax();
    void upd() {
	s = ch[0] -> s + ch[1] -> s + 1;
	mx = max(v, max(ch[0] -> mx, ch[1] -> mx));
    }
} Tnull, *null = &Tnull;

Node mem[MAXN], *C = mem;

void Node::relax() {
    if (add) {
	rep(i, 0, 1) if (ch[i] != null) ch[i] -> addIt(add);
	add = 0;
    }
    if (rev) {
	swap(ch[0], ch[1]);
	rep(i, 0, 1) if (ch[i] != null) ch[i] -> revIt();
	rev = 0;
    }
}

Node* make(int v) {
    C -> ch[0] = C -> ch[1] = null;
    C -> s = 1;
    C -> v = C -> mx = v;
    C -> add = C -> rev = 0;
    return C++;
}

Node* build(int l, int r) {
    if (l >= r) return null;
    int m = (l + r) >> 1;
    Node* t = make(A[m]);
    t -> setc(build(l, m), 0);
    t -> setc(build(m + 1, r), 1);
    t -> upd();
    return t;
}

Node* root;

void rot(Node* t) {
    Node* p = t -> p;
    p -> relax();
    t -> relax();
    int d = t -> d();
    p -> p -> setc(t, p -> d());
    p -> setc(t -> ch[!d], d);
    t -> setc(p, !d);
    p -> upd();
    if (p == root) root = t;
}

void splay(Node* t, Node* f = null) {
    while (t -> p != f) {
	if (t -> p -> p == f) rot(t);
	else t -> d() == t -> p -> d() ? (rot(t -> p), rot(t)) : (rot(t), rot(t));
    }
    t -> upd();
}

Node* select(int k, Node* tHeader = root) {
    for (Node* t = tHeader;;) {
	t -> relax();
	int c = t -> ch[0] -> s;
	if (k == c) return t;
	if (k > c) k -= c + 1, t = t -> ch[1];
	else t = t -> ch[0];
    }
}

Node* &get(int l, int r) {
    Node* L = select(l - 1);
    Node* R = select(r);
    splay(L);
    splay(R, L);
    return R -> ch[0];
}

int n, m;

int main() {
    printf("1: add\n2: rev\n3: max\n4: kth\n");
    n = gi, m = gi;
    rep(i, 0, n - 1) A[i] = gi;
    root = build(0, n + 2);
    root -> p = null;
    rep(i, 0, m - 1) {
	int k, l, r, v;
	k = gi, l = gi, r = gi;
	Node* &t = get(l, r + 1);
	if (k == 1) {
	    v = gi;
	    t -> addIt(v);
	    splay(t);
	} else if (k == 2) {
	    t -> revIt();
	    splay(t);
	} else if (k == 3) {
	    printf("%d\n", t -> mx);
	} else {
	    v = gi;
	    Node* tmp = select(v, t);
	    splay(tmp);
	    printf("%d\n", tmp -> v);
	}
    }
    return 0;
}

