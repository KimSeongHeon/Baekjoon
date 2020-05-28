#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
bool compare(int a, int b) {
	return a > b;
}
int main() {
	string s;
	cin >> s;
	bool check = false;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '0') {
			check = true;
			break;
		}
	}
	if (!check) {
		cout << -1;
		return 0;
	}
	else {
		vector<int> v;
		for (int i = 0; i < s.length(); i++) {
			v.push_back(s[i]-48);
		}
		sort(v.begin(), v.end(), compare);
		int temp = 0;
		for (int i = 0; i < v.size(); i++) {
			temp = temp + v[i];
		}
		if (temp % 3 == 0) {
			for (int i = 0; i < v.size(); i++) {
				cout << v[i];
			}
		}
		else {
			cout << -1;
		}
	}
	return 0;
}