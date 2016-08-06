
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)

int N, M;
string w[50000], wr[50000], slate;

string key;
bool pred(const string &lhs, const string &rhs) {
	if (lhs == key) return lhs < rhs.substr(0, lhs.length());
	else return lhs.substr(0, rhs.length()) < rhs;
}

int count(string &str) {
	if (str[str.length() - 1] == '*') {
		key = str.substr(0, str.length() - 1);
		auto lb = lower_bound(w, w + N, key, pred);
		auto ub = upper_bound(w, w + N, key, pred);
		return ub - lb;
	}
	else if (str[0] == '*') {
		key = str;
		reverse(key.begin(), key.end());
		key = key.substr(0, key.length() - 1);
		auto lb = lower_bound(wr, wr + N, key, pred);
		auto ub = upper_bound(wr, wr + N, key, pred);
		return ub - lb;
	}
	else {
		if (binary_search(w, w + N, str)) return 1;
		else return 0;
	}
}

int main() {
	cin >> N >> M;
	REP(i, N) {
		cin >> w[i];
		wr[i] = w[i];
		reverse(wr[i].begin(), wr[i].end());
	}
	sort(w, w + N);
	sort(wr, wr + N);
	REP(i, M) {
		cin >> slate;
		auto found = find(slate.begin(), slate.end(), '?');
		if (found == slate.end()) {
			cout << count(slate) << endl;
		}
		else {
			int cnt = 0;
			for (char c = 'a'; c <= 'z'; ++c) {
				(*found) = c;
				cnt += count(slate);
			}
			cout << cnt << endl;
		}
	}
	return 0;
}
