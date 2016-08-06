
#include <iostream>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)

int N;
int p[100];

int main() {
	cin >> N;
	REP(i, N) cin >> p[i];
	int res = 100;
	for (; res >= 0; --res) {
		int cnt = 0;
		REP(i, N) if (p[i] >= res) ++cnt;
		if (cnt >= res) break;
	}
	cout << res << endl;
	return 0;
}
