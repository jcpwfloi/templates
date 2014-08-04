#include<cstdio>
#include<algorithm>
#include<vector>
#include<complex>
#include<cmath>
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define foreach(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); ++i)

using namespace std;

typedef complex<double> Comp;

const Comp I(0, 1);

int const MAXN = 1 << 20;
Comp tmp[MAXN];

void DFT(Comp *a, int n, int rev) {
    if (n == 1) return;
    rep(i, 0, n - 1) {
	tmp[i] = a[i];
    }
    rep(i, 0, n - 1) {
	if (i & 1) a[n / 2 + i / 2] = tmp[i];
	else a[i / 2] = tmp[i];
    }
    Comp *a0 = a, *a1 = a + n / 2;
    DFT(a0, n / 2, rev);
    DFT(a1, n / 2, rev);
    Comp cur(1, 0);
    double alpha = 2 * M_PI / n * rev;
    Comp step = exp(I * alpha);
    for (int k = 0; k < n / 2; ++k) {
	tmp[k] = a0[k] + cur * a1[k];
	tmp[k + n / 2] = a0[k] - cur * a1[k];
	cur *= step;
    }
    rep(i, 0, n - 1) a[i] = tmp[i];
}

int main() {
    static Comp a[1 << 20] = { }, b[1 << 20] = { };
    int n = 1 << 20;
    DFT(a, n, 1);
    DFT(b, n, 1);
    for (int i = 0; i < n; ++i) {
        a[i] *= b[i];
    }
    DFT(a, n, -1);
    for (int i = 0; i < n; ++i) {
        a[i] /= n;
    }
    return 0;
}

