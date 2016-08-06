
#include <iostream>

using namespace std;

int h1, h2, k1, k2, a, b, c, d;

int main() {
	cin >> h1 >> h2 >> k1 >> k2 >> a >> b >> c >> d;
	int h = h1 * a + (h1 / 10) * c + h2 * b + (h2 / 20) * d;
	int k = k1 * a + (k1 / 10) * c + k2 * b + (k2 / 20) * d;
	if (h > k) cout << "hiroshi" << endl;
	else if (k > h) cout << "kenjiro" << endl;
	else cout << "even" << endl;
	return 0;
}
