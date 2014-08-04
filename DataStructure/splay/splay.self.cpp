#include<cstdio>
#include<algorithm>

using namespace std;

int const MAXN = 100001;

struct Node {
    Node *ch[2], *p;
    int v, s;
    int add, mx;
    bool rev;
    Node () : v(~INF), s(0), rev(0), add(0), mx(~INF) {}
    void revIt() {
	rev ^= 1;
    }
    void addIt(int x) {
	v += x;
	mx += x;
	add += x;
    }
    void setc(Node* t, int d) {
	ch[d] = t;
	t -> p = this;
    }
    void relax();
    void upd() {
	s = ch[0] -> s + 1 + ch[1] -> s;
    }
} Tnull, *null = &Tnull;

Node* root;
Node mem[MAXN], *C = mem;

Node* mk(int k) {
    C -> ch[0] = C -> ch[1] = null;
    C -> v = C -> mx = k;
    C -> add = C -> rev = 0;
    C -> s = 1;
    return C++;
}

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

Node* build(int l, int r) {
    if (l >= r) return null;
    int m = (l + r) >> 1;
    Node* t = make(0);
    t -> setc(build(l, m), 0);
    t -> setc(build(m + 1, r), 1);
    t -> upd();
    return t;
}

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

void splay(Node *t, Node* f = null) {
    while (t -> p != f) {
	if (t -> p -> p == f) rot(t);
	else t -> d() == t -> p -> d() ? (rot(t -> p), rot(t)) : (rot(t), rot(t)); 
    }
    t -> upd();
}

Node* select(int k, Node* tHeader = root) {
    for (Node* t = tHeader;;) {
	t -> relax();
	if (k == t -> ch[0] -> s) return t;
	else if (k > t -> ch[0] -> s) k -= t -> ch[0] -> s + 1, t = t -> ch[1];
	else t = t -> ch[0];
    }
}

Node* &get(int l, int r) { //[l,r)
    Node* L = select(l - 1);
    Node* R = select(r);
    splay(L);
    splay(R, L);
    return R -> ch[0];
}

int n, m;

int main() {
    return 0;
}

