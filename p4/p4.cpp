
#include <iostream>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)

int N, X, Y, Z;
bool a[100], b[100], c[1000];

int main() {
	cin >> N;
	REP(i, N) a[i] = b[i] = c[i] = false;
	int t;
	cin >> X;
	REP(i, X) {
		cin >> t;
		--t;
		a[t] = true;
	}
	cin >> Y;
	REP(i, Y) {
		cin >> t;
		--t;
		b[t] = true;
	}
	cin >> Z;
	REP(i, Z) {
		cin >> t;
		--t;
		c[t] = true;
	}

	int cnt = 0;
	REP(i, N) if ((!a[i] || b[i]) && c[i]) ++cnt;
	cout << cnt << endl;
	return 0;
}
