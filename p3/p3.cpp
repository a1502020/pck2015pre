
#include <iostream>

using namespace std;

int D, L;

int main() {
	cin >> D >> L;
	cout << (D / L + D % L) << endl;
	return 0;
}
