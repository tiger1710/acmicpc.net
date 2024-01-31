#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> arr;
map<int, int> cnt;
int N, S;
int middle;
int sum;
long long ans;

void start(int pos) {
	if (pos == middle) {
		cnt[sum]++;
		return;
	}

	start(pos + 1);
	sum += arr[pos];
	start(pos + 1);
	sum -= arr[pos];
}
void end(int pos) {
	if (pos == N) {
		if (cnt.find(S - sum) not_eq cnt.end()) ans += cnt[S - sum];
		return;
	}

	end(pos + 1);
	sum += arr[pos];
	end(pos + 1);
	sum -= arr[pos];
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> S;
	arr.resize(N);
	for (int& i : arr) {
		cin >> i;
	}
	middle = N >> 1;
	start(0);
	end(middle);
	if (not S) ans--;
	cout << ans << '\n';



	return 0;
}