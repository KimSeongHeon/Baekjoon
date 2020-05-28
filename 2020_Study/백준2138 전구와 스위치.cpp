#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int n;
vector<int> light;
vector<int> goal;
vector<int> copy_light;
void change(int num) {
	if (num != n-1 && num != 0) {
		for (int i = -1; i <2; i++) {
			if (light[num + i] == 0) light[num + i] = 1;
			else light[num + i] = 0;
		}
	}
	else if (num == 0) {
		for (int i = 0; i < 2; i++) {
			if (light[i] == 0) light[i] = 1;
			else light[i] = 0;
		}
	}
	else if (num == n - 1) {
		for (int i = n - 2; i <= n - 1; i++) {
			if (light[i] == 0) light[i] = 1;
			else light[i] = 0;
		}
	}
}
int main() {
	int ans1 = 0;
	int ans2 = 0;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		light.push_back((int)s[i]-48);
		copy_light.push_back((int)s[i] - 48);
	}
	cin >> s;
	for (int i = 0; i < n; i++) {
		goal.push_back((int)s[i]-48);
	}
	//0번 스위치를 눌렀을때.
	for (int i = 0; i <= 1; i++) {
		if (light[i] == 0) light[i] = 1;
		else light[i] = 0;
	}
	ans1++;
	for (int i = 1; i < n; i++) {
		if (light[i-1] != goal[i-1]) {
			ans1++;
			change(i);
		}
	}
	for (int i = 0; i < n; i++) {
		if (light[i] != goal[i]) {
			ans1 =  -1;
			break;
		}
	}
	
	//0번 스위치를 안눌렀을때
	light = copy_light;
	for (int i = 1; i < n; i++) {
		if (light[i - 1] != goal[i - 1]) {
			ans2++;
			change(i);
		}
	}
	for (int i = 0; i < n; i++) {
		if (light[i] != goal[i]) {
			ans2 = -1;
			break;
		}
	}
	if (ans1 == -1 && ans2 == -1) cout << -1;
	else if (ans1 == -1 && ans2 != -1) cout << ans2;
	else if (ans1 != -1 && ans2 == -1) cout << ans1;
	else cout << min(ans1, ans2);
	return 0;
}