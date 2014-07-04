#include<cstdio>
#include<algorithm>

using namespace std;

struct Node {
    Node* ch[2];
    int r, v, s;
    Node(int v) : v(v) , r(rand()) {ch[0] = ch[1] = NULL;}
    void maintain() {
	s = 1;
	if (ch[0]) s += ch[0] -> s;
	if (ch[1]) s += ch[1] -> s;
    }
}

Node* merge(Node& *a, Node& *b) {
    if (a -> r < b -> r) swap(a, b);
    if (b -> v < a -> v) {
	a -> ch[0] = merge(a -> ch[0], b);
	a -> ch[0] -> maintain();
    }
    else {
	a -> ch[1] = merge(a -> ch[1], b);
	a -> ch[1] -> maintain();
    }
    a -> maintain();
    return a;
}

Node* split(Node& *o, int k) {
    if (!o -> ch[0]) {
	o -> ch[1] = NULL;
	merge(ans, o);
	if (k == 1) return o;
	else {
	}
    } else {
    }
}

int main() {
    return 0;
}

