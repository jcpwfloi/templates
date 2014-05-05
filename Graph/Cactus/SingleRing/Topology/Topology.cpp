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

int n, m;

#define maxn 1000001
#define maxm 1000002

int first[maxn], nex[maxm], to[maxm];
int D[maxn];
int l = 0, r = 0, Q[maxn];
bool del[maxn];
int cnt = 0;

#undef maxn
#undef maxm

inline ll gI() {
    ll flag = 1, p = 0;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') flag = -1, c = getchar();
    while ('0' <= c && c <= '9') p = p * 10 + (c - '0'), c = getchar();
    return p * flag;
}

inline void addEdge(int u, int v) {
    nex[++cnt] = first[u];
    first[u] = cnt;
    to[cnt] = v;
}

void Topology() {
    rep(i, 1, n) if (D[i] == 1) Q[r++] = i;
    while (l < r) {
	int u = Q[l++];
	del[u] = true;
	for (int i = first[u]; i; i = nex[i]) {
	    int v = to[i];
	    if (!del[v]) {
		if (--D[v] == 1) {
		    Q[r++] = v;
		}
	    }
	}
    }
    rep(i, 1, n) if (!del[i]) printf("%d ", i);
    printf("\n");
}

int main() {
    n = gi;
    rep(i, 1, n) {
	int u = gi, v = gi;
	addEdge(u, v);
	addEdge(v, u);
	++D[u], ++D[v];
    }
    Topology();
    return 0;
}

