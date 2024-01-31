#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> sum;
vector<int> setCost;
int N;

int menu(int rest) {//rest는 남은 붕어빵
	if (rest == 0) return sum[0] = 0;
	if (sum[rest] != -1) return sum[rest];//이미 계산했다면
	int result = 0;//최소값으로 설정
	for (int i = 0; i < rest; i++) {//i + 나머지 조합중 가장 큰 것을 계산
		result = max(result, setCost[i] + menu(rest - (i + 1)));
	}						//(i + 1)개짜리 셋트와 rest - (i + 1)개로
							//만들 수 있는 최대값
	return sum[rest] = result;
}

int main(void) {
	cin >> N;
	sum.resize(N + 1, -1);
	for (int i = 0; i < N; i++) {
		int cost;
		cin >> cost;
		setCost.push_back(cost);
	}
	cout << menu(N) << endl;



	return 0;
}