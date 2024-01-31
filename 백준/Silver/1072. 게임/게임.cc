#include <iostream>
#include <limits>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	long long X, Y;
	while (cin >> X >> Y) {
		long long Z = (Y * 100) / X;
		if (Z >= 99) {
			cout << -1 << '\n';
			continue;
		}


		long long low = 0, high = 1e17;
		while (low + 1 < high) {
			long long answer = ((low + high) >> 1);

			long long win = ((answer + Y) * 100) / (answer + X);

			if (win != Z) high = answer;
			else low = answer;
		}

		cout << high << '\n';
	}

	return 0;
}