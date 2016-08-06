
#include <iostream>
#include <vector>
#include <list>
#include <cstring>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, s, n) for (int i = (s); i < (n); ++i)
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int N, P;
vector<pair<int, int>> es1[1000], esr1[1000], es2[1000], esr2[1000];

list<int> tpl;
vector<int> tp;
bool ved[1000];
void tpsort(int i) {
	if (ved[i]) return;
	ved[i] = true;
	REP(j, es1[i].size()) {
		tpsort(es1[i][j].first);
	}
	tpl.push_front(i);
}

int main() {
	cin >> N >> P;
	REP(i, P) {
		int s, e, t1, t2;
		cin >> s >> e >> t1 >> t2;
		--s; --e;
		es1[s].push_back(make_pair(e, t1));
		esr1[e].push_back(make_pair(s, t1));
		es2[s].push_back(make_pair(e, t2));
		esr2[e].push_back(make_pair(s, t2));
	}

	memset(ved, 0, sizeof(ved));
	REP(i, N) tpsort(i);
	for (auto it = tpl.begin(); it != tpl.end(); ++it) tp.push_back(*it);

	// ‚í‚©‚ç‚ñ

	return 0;
}
