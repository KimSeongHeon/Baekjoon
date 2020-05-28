#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> pn;
vector<int> nn;
bool descend(int a, int b) {
	return a > b;
}
int main() {
	int n;
	cin >> n;
	int ans = 0;
	int element;
	int one = 0;
	int zero = 0;
	for (int i = 0; i < n; i++) {
		cin >> element;
		if (element < 0) nn.push_back(element);
		else if (element > 1) pn.push_back(element);
		else if (element == 1) one++;
		else if (element == 0) zero++;
	}
	if (n == 1) {
		cout << element;
		return 0;
	}
	sort(nn.begin(), nn.end());
	sort(pn.begin(), pn.end(), descend);
	int index = 0;
	int sum = 0;
	if (nn.size() > 0) {
		while (1) {
			int first = nn[index];
			index = index + 1;
			if (index >= nn.size()) {
				if (zero > 0) {
					zero--;
				}
				else {
					sum = sum + first;
				}
				break;
			}
			int second = nn[index];
			sum = sum + first * second;
			index = index + 1;
			if (index >= nn.size()) break;
		}
	}
	//cout << sum << endl;
	ans = ans + sum;
	index = 0;
	sum = 0;
	if (pn.size() > 0) {
		while (1) {
			int first = pn[index];
			index = index + 1;
			if (index >= pn.size()) {
				sum = sum + first;
				break;
			}
			int second = pn[index];
			sum = sum + first * second;
			index = index + 1;
			if (index >= pn.size()) break;
		}
	}
	//cout << sum << endl;
	ans = ans + sum + one;
	cout << ans;
	return 0;
}