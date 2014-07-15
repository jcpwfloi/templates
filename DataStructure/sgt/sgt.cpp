#include<cstdio>
#include<algorithm>

#define rep(i, l, r) for (int i = l; i <= r; i++)
#define gi gI()

#define lson u << 1
#define rson u << 1 | 1

using namespace std;

inline long long gI() {
    long long p = 0, flag = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') flag = -1, c = getchar();
    while ('0' <= c && c <= '9') p = p * 10 + (c - '0'), c = getchar();
    return p * flag;
}

int const MAXN = 100001;

int A[MAXN];
int n, m;

namespace sgt {
    const int T_MAX = 400001;
    struct Node {
	int L, R, min, tag;
    } T[T_MAX];
    inline void Update(int u) {
	T[u].min = min (T[lson].min, T[rson].min);
    }
    inline void Cover(int u, int C) {
	T[u].tag += C;
	T[u].min += C;
    }
    inline void Push(int u) {
	if (T[u].tag) {
	    Cover(lson, T[u].tag);
	    Cover(rson, T[u].tag);
	    T[u].tag = 0;
	}
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
	if (L <= T[u].L && T[u].R <= R) {
	    return T[u].min;
	}
	Push(u);
	int ans = 2147483647;
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

int main() {
    n = gi, m = gi;
    rep(i, 1, n) A[i] = gi;
    sgt::Build(1, 1, n);
    while (m--) {
    }
    return 0;
}
