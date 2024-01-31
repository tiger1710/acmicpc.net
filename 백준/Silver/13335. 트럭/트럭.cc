#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n, w, L; cin >> n >> w >> L;//w 길이 L 최대 무게
	vector<int> truck(n);
	queue<int> bridge;
	for (int& i : truck) cin >> i;
	
	int sum = 0, sec = 0, cur = 0;
	while (cur < n and bridge.size() < w and sum + truck[cur] <= L) {
		sum += truck[cur];
		bridge.push(truck[cur]);
		sec++, cur++;
	}
	while (bridge.size() < w) {
		bridge.push(0);
		sec++;
	}

	while (true) {
		sum -= bridge.front(); bridge.pop();
		if (not sum and n == cur) break;
		if (cur < n and sum + truck[cur] <= L) {
			sum += truck[cur];
			bridge.push(truck[cur]);
			sec++, cur++;
		}
		else {
			while (bridge.size() < w) {
				bridge.push(0);
				sec++;
			}
		}
	}
	cout << sec + 1 << '\n';


	return 0;
}