#include<iostream>
#include<vector>
#include<algorithm>
#include<memory.h>
using namespace std;
int arr[1000001];
int main() {
	cin.tie(NULL);
	int n;
	cin >> n;
	int element;
	for (int i = 0; i < n; i++) {
		cin >> element;
		arr[i] = element;
	}
	vector<int> v;
	for (int i = 0; i < n; i++) {
		auto it = lower_bound(v.begin(),v.end(),arr[i]);
		if (it == v.end()) {
			//못찾았으면,
			v.push_back(arr[i]);
		}
		else {
			*it = arr[i];
		}
	}
	cout << v.size();
	return 0;
}