#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int a;
vector<int> v;
vector<int> op;
vector<int> comb;
int max_answer = -987654321;
int min_answer = 987654321;

void cal(int n) {//순서
	for (int i = 0; i < comb.size(); i++) {
		if (comb[i] == n) return;
	}
	if (n >= a-1 || n < 0) return;
	comb.push_back(n);
	for (int i = n + 1; i < a; i++) cal(i);
	for (int i = n - 1; i >= 0; i--) cal(i);
	if (comb.size() == v.size()-1) { //수열을 다 뽑았으면
		int temp = v[0];
		for (int i = 1; i <= comb.size(); i++) {
			if (op[comb[i-1]] == '+') temp = temp + v[i];
			else if (op[comb[i - 1]] == '-') temp = temp - v[i];
			else if (op[comb[i - 1]] == '*') temp = temp * v[i];
			else if (op[comb[i - 1]] == '/') temp = temp / v[i];
		}
		//cout << temp << endl;
		max_answer = max(max_answer, temp);
		min_answer = min(min_answer, temp);
	}
	comb.pop_back();
}
int main() {
	cin >> a;
	for (int i = 0; i < a; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	for (int i = 0; i < 4; i++) {
		int num;
		cin >> num;
		for (int j = 0; j < num; j++) {
			if (i == 0) op.push_back('+');
			else if (i == 1) op.push_back('-');
			else if (i == 2) op.push_back('*');
			else if (i == 3) op.push_back('/');
		}
	}
	for (int i = 0; i < a; i++) cal(i);
	cout << max_answer << endl;
	cout << min_answer;
	return 0;
}