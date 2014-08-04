#include<cstdio>
#include<algorithm>
#include<vector>
#include<complex>

using namespace std;

typedef complex<double, double> Comp;

const Comp i(0, 1);

int const MAXN = 300001;

Comp tmp[MAXN];

void DFT(Comp *a, int n, int rev) {
    if (n == 1) return;
    for (int i = 0; i < n; i++) tmp[i] = a[i];
    for (int i = 0; i < n; i++) {
	if (i & 1) a[n / 2 + i / 2] = tmp[i];
	else a[i / 2] = tmp[i];
    }
    Comp *a0 = a, *a1 = a + n / 2;
    DFT(a0, n / 2, rev);
    DFT(a1, n / 2, rev);
    Comp Cur(1, 0);
    double alpha = 2 * M_PI / n * rev;
    Comp step = exp(I * alpha);
    for (int k = 0; k < n / 2; k++) {
	tmp[k] = a0[k] + a1[k] * cur;
	tmp[n / 2 + k] = a0[k] - a1[k] * cur;
	cur *= step;
    }
    for (int i = 0; i < n; i++) a[i] = tmp[i];
}

int main() {
    static Comp a[1<< 20] = {}, b[1 << 20] = {};
    int n = 1 << 20;
    DFT(a, n, 1);
    DFT(b, n, 1);
    for (int i = 0; i < n; i++)
}
