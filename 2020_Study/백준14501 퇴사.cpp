#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
int term[20];
int price[20];
int cal(int day) {//day에서 시작할 때 최댓값을 return 함
	cout << day << endl;
	if (day > N) return 0;
	if (day + term[day] > N + 1) return 0;
	if (day + term[day] == N + 1) return price[day];
	int ret = -987654321;
	for (int i = term[day]; i <= N; i++) {
		ret = max(ret, cal(day + i) + price[i]);
	}
	return ret;
}
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> term[i] >> price[i];
	}
	int answer = -987654321;
	for (int i = 1; i <= N; i++) {
		answer = max(answer,cal(i));
	}
	cout << answer;
	return 0;
}