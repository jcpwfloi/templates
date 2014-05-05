#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>

#define gi gI()
#define clr(a) memset(a, 0, sizeof(a))
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define repD(i, r, l) for(int i = r; i >= l; i--)
#define max(a, b) ((a) > (b)) ? (a) : (b)
#define min(a, b) ((a) < (b)) ? (a) : (b)
#define lowbit(x) (x & (-x))

using namespace std;

typedef long long ll;

inline ll gI() {
    ll flag = 1, p = 0;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') flag = -1, c = getchar();
    while ('0' <= c && c <= '9') p = p * 10 + (c - '0'), c = getchar();
    return p * flag;
}

namespace treap {
    struct Node {
	Node* ch[2];
	int r, v, s;
	inline int cmp(int x) {
	    if (x == v) return -1;
	    return x < v ? 0 : 1;
	}
	void maintain() {
	    s = 1;
	    if (ch[0]) s += ch[0] -> s;
	    if (ch[1]) s += ch[1] -> s;
	}
	Node (int v) : v(v), r(rand()), s(1) {
	    ch[0] = ch[1] = NULL;
	}
    };
    inline void Rotate(Node* &o, int d) {
	Node* k = o -> ch[d ^ 1];
	o -> ch[d ^ 1] = k -> ch[d];
	k -> ch[d] = o;
	o -> maintain();
	o = k;
	o -> maintain();
    }
    inline void Insert(Node* &o, int x) {
	if (o == NULL) o = new Node(x);
	else {
	    int d = o -> cmp(x);
	    Insert(o -> ch[d], x);
	    if (o -> ch[d] -> r > o -> r) Rotate(o, d ^ 1);
	}
	o -> maintain();
    }
    inline void Remove(Node* &o, int x) {
	int d = o -> cmp(x);
	if (d == -1) {
	    if (!o -> ch[0]) o = o -> ch[1];
	    if (!o -> ch[1]) o = o -> ch[0];
	    else {
		int d2 = o -> ch[0] -> r > o -> ch[1] -> r ? 1 : 0;
		Rotate(o, d2);
		Remove(o -> ch[d2], x);
	    }
	} else Remove(o -> ch[d], x);
	o -> maintain();
    }
    inline Node* kth(Node* o, int k) {
	if (k < 1 || k > o -> s) return NULL;
	if (!o -> ch[1]) {
	    if (k == 1) return o;
	    else return kth(o -> ch[0], k - 1);
	} else {
	    if (k <= o -> ch[1] -> s) return kth(o -> ch[1], k);
	    if (k == o -> ch[1] -> s + 1) return o;
	    return kth(o -> ch[0], k - 1 - o -> ch[1] -> s);
	}
    }
}

int main() {
    return 0;
}

