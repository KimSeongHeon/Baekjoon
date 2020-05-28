#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n,k;
	cin >> n >> k;
	int low = 1;
	int high = k;
	int result = -1;
	while (low <= high) {
		int cnt = 0;
		int mid = (low + high) / 2;
		for (int i = 1; i <= n; i++) {
			cnt += min(mid / i, n);
		}
		//cout << mid << endl;
		//cout << cnt << endl;
		if (cnt < k) low = mid + 1;
		else {
			result = mid;
			high = mid - 1;
		}
	}
	cout << result << endl;
	return 0;
}