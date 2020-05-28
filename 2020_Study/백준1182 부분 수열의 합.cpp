#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v;
vector<int> comb;
int num, s ,answer;
void cal(int n) {
	for (int i = 0; i < comb.size(); i++) {
		if (n == comb[i]) return;
	}
	if (n >= num || n < 0) return;
	if (comb.size() >= num) return;
	comb.push_back(n);
	for (int i = n; i < num; i++) cal(i);
	int sum = 0;
	for (int i = 0; i < comb.size(); i++) {
		//cout << comb[i] << " ";
		sum = sum + v[comb[i]];
	}
	//cout << endl;
	if (sum == s) answer++;
	comb.pop_back();
}
int main()
{
	cin >> num >> s;
	for (int i = 0; i < num; i++) {
		int element;
		cin >> element;
		v.push_back(element);
	}
	for (int i = 0; i < num; i++) cal(i);
	cout << answer;
	return 0;
}