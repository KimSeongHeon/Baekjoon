#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
vector<int> v;
vector<int> comb;
vector<int> answer;
int num;
void cal(int n) {
	for (int i = 0; i < comb.size(); i++) {
		if (n == comb[i]) return;
	}
	if (n < 0 || n >= num) return;
	comb.push_back(n);
	for (int i = n + 1; i < num; i++) cal(i);
	int temp = 0;
	for (int i = 0; i < comb.size(); i++) {
		temp = temp + v[comb[i]];
	}
	answer.push_back(temp);
	comb.pop_back();
}
int main() {
	cin >> num;
	for (int i = 0; i < num; i++) {
		int element;
		cin >> element;
		v.push_back(element);
	}
	for (int i = 0; i < v.size(); i++) cal(i);
	sort(answer.begin(), answer.end());
	answer.erase(unique(answer.begin(), answer.end()), answer.end());
	if (answer[0] != 1) {
		cout << 1;
		return 0;
	}
	for (int i = 1; i <= answer.size(); i++) {
		if (i == answer.size()) {
			cout << i+1;
		}
		else if (i != answer[i-1]) {
			cout << i;
			break;
		}
	}
	return 0;
}