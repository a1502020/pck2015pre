
#include <iostream>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)

int C, N, D, r, c;
bool p[1000][1000];

bool symmetric() {
	REP(y, N / 2) REP(x, N / 2) {
		if (p[x][y] != p[N - 1 - x][y]) return false;
		if (p[x][y] != p[x][N - 1 - y]) return false;
		if (p[x][y] != p[N - 1 - x][N - 1 - y]) return false;
	}
	return true;
}

int main() {
	cin >> C >> N;
	char t;
	REP(y, N) REP(x, N) {
		cin >> t;
		p[x][y] = (t == '1');
	}
	int cnt = 0;
	if (symmetric()) ++cnt;
	REP(i, C - 1) {
		cin >> D;
		REP(j, D) {
			cin >> r >> c;
			--r; --c;
			p[c][r] = !p[c][r];
		}
		if (symmetric()) ++cnt;
	}
	cout << cnt << endl;
	return 0;
}
