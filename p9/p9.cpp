
#include <iostream>
#include <iomanip>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int N;
double x[100000], r[100000];

double l1, r1;

bool check(double d) {
	double l2 = l1, r2 = r1;
	REP(i, 100) {
		double m = (l2 + r2) / 2;
		int in = 0, left = 0, right = 0;
		REP(j, N) {
			double dx = x[j] - m;
			if (dx * dx + d * d <= r[j] * r[j]) ++in;
			else if (dx > 0) ++right;
			else ++left;
		}
		if (left != 0 && right != 0) return false;
		if (left == 0 && right == 0) return true;
		if (left != 0) r2 = m;
		else l2 = m;
	}
	return false;
}

int main() {
	cin >> N;
	l1 = -1000000, r1 = 2000000;
	REP(i, N) {
		cin >> x[i] >> r[i];
		l1 = max(l1, x[i] - r[i]);
		r1 = min(r1, x[i] + r[i]);
	}
	double l2 = 0, r2 = 1000000;
	REP(i, 100) {
		double m = (l2 + r2) / 2;
		if (check(m)) l2 = m;
		else r2 = m;
	}
	cout << fixed << setprecision(10) << ((l2 + r2) / 2) << endl;
	return 0;
}
