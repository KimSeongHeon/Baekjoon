#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, k;
int ans = 0;
vector<int> coin;
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int element;
		cin >> element;
		coin.push_back(element);
	}
	for (int i = coin.size()-1; i >= 0; i--) {
		while (k >= coin[i]) {
			k = k - coin[i];
			ans++;
		}
		if (k == 0) break;
	}
	cout << ans;
	return 0;
}