#include<cstdio>
#include<algorithm>
#include<cstring>

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

#define maxn 100001
int A[maxn];
#undef maxn

#define lson u << 1
#define rson u << 1 | 1

namespace sgt {
    int const T_MAX = 400001;
    struct Node {
	int L, R, min, tag;
    } T[T_MAX];
    inline void Cover(int u, int C) {
	T[u].min += C;
	T[u].tag += C;
    }
    inline void Push(int u) {
	if (T[u].tag) {
	    Cover(lson, T[u].tag);
	    Cover(rson, T[u].tag);
	    T[u].tag = 0;
	}
    }
    inline void Update(int u) {
	T[u].min = min(T[lson].min, T[rson].min);
    }
    inline void Edit(int u, int L, int R, int C) {
	if (L <= T[u].L && T[u].R <= R) {
	    Cover(u, C);
	    return;
	}
	Push(u);
	if (L <= T[lson].R) Edit(lson, L, R, C);
	if (R >= T[rson].L) Edit(rson, L, R, C);
	Update(u);
    }
    inline int Query(int u, int L, int R) {
	if (L <= T[u].L && T[u].R <= R) return T[u].min;
	Push(u);
	int ans = 0x7FFFFFFF;
	if (L <= T[lson].R) ans = min(ans, Query(lson, L, R));
	if (R >= T[rson].L) ans = min(ans, Query(rson, L, R));
	return ans;
    }
    inline void Build(int u, int L, int R) {
	T[u].L = L;
	T[u].R = R;
	if (L == R) {
	    T[u].min = A[L];
	    return;
	}
	int M = (L + R) >> 1;
	Build(lson, L, M);
	Build(rson, M + 1, R);
	Update(u);
    }
}

#undef lson
#undef rson

int main() {
    return 0;
}

