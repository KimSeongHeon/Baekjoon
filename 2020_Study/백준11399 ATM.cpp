#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
vector<int> time;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int element;
		cin >> element;
		time.push_back(element);
	}
	sort(time.begin(), time.end());
	int ans = 0;
	for (int i = 0; i < time.size(); i++) {
		for (int j = 0; j <= i; j++) {
			ans = ans + time[j];
		}
	}
	cout << ans;
	return 0;
}