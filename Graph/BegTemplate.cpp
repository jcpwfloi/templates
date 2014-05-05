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

#define maxn 1001

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

int main() {
    return 0;
}

