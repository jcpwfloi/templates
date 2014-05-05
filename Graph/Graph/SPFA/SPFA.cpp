#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>

#define gi gI()
#define clr(a) memset(a, 0, sizeof(a))
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define repD(i, r, l) for(int i = r; i >= l; i--)
#define max(a, b) ((a) > (b)) ? (a) : (b)
#define min(a, b) ((a) < (b)) ? (a) : (b)
#define lowbit(x) (x & (-x))

using namespace std;

typedef long long ll;

#define maxn 100001
#define maxm 300001
int n, m;
int D[maxn], first[maxn], nex[maxm], to[maxm], W[maxm];
bool B[maxn];
int cnt = 0;
#undef maxn
#undef maxm

queue<int> Q;

inline ll gI() {
    ll flag = 1, p = 0;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') flag = -1, c = getchar();
    while ('0' <= c && c <= '9') p = p * 10 + (c - '0'), c = getchar();
    return p * flag;
}

inline void SPFA(int S) {
    memset(D, 0x7F, sizeof(D));
    D[S] = 0; Q.push(S); B[S] = true;
    while (!Q.empty()) {
	int u = Q.front(); Q.pop(); B[u] = false;
	for (int i = first[u]; i; i = nex[i]) {
	    int v = to[i];
	    if (D[v] > D[u] + W[i]) {
		D[v] = D[u] + W[i];
		if (!B[v]) {
		    B[v] = true;
		    Q.push(v);
		}
	    }
	}
    }
}

inline void addEdge(int u, int v, int w) {
    nex[++cnt] = first[u];
    first[u] = cnt;
    to[cnt] = v;
    W[cnt] = w;
}

int main() {
    n = gi, m = gi;
    rep(i, 1, m) {
	int u = gi, v = gi, w = gi;
	addEdge(u, v, w);
	addEdge(v, u, w);
    }
    SPFA(1);
    rep(i, 1, n) {
	printf("%d%c", D[i], i == n ? '\n' : ' ');
    }
    return 0;
}

