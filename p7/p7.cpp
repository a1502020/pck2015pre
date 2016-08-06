
#include <iostream>
#include <utility>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)

int N, M, K, t, a, b;

int pa[100000], sz[100000];
int club[100000];

int root(int i) {
	while (pa[i] != -1) i = pa[i];
	return i;
}

int merge(int i, int j) {
	int a = root(i), b = root(j);
	if (a == b) return a;
	if (sz[a] < sz[b]) swap(a, b);
	pa[b] = a;
	if (club[a] == -1) club[a] = club[b];
	sz[a] += sz[b];
	return a;
}

int main() {
	cin >> N >> M >> K;
	REP(i, N) {
		pa[i] = -1;
		sz[i] = 1;
		club[i] = -1;
	}
	int res = 0;
	REP(i, K) {
		cin >> t >> a >> b;
		--a; --b;
		if (t == 1) {
			int ra = root(a), rb = root(b);
			if (club[ra] != -1 && club[rb] != -1 && club[ra] != club[rb]) {
				res = i + 1;
				break;
			}
			merge(ra, rb);
		}
		else {
			int ra = root(a);
			if (club[ra] != -1 && club[ra] != b) {
				res = i + 1;
				break;
			}
			club[ra] = b;
		}
	}
	cout << res << endl;
	return 0;
}
