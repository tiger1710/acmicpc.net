#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

bool cmp(const string& a, const string& b) {
    return a + b > b + a;
}

string solution(vector<int>& numbers) {
    string answer = "";
    vector<string> t;
    transform(numbers.begin(), numbers.end(), back_inserter(t), [](const int& i) { return to_string(i); });
    sort(t.begin(), t.end(), cmp);
    answer = accumulate(t.begin(), t.end(), string(""));
    return (answer[0] == '0') ? "0" : answer;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; cin >> N;
    vector<int> numbers(N);
    for (int& i : numbers) cin >> i;
    cout << solution(numbers);
    
    return 0;
}