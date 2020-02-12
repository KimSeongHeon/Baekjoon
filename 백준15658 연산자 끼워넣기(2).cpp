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

pair<int,int> cal(int index,int cur,int plus, int minus, int mul, int div) {
	if (index == v.size()) return make_pair(cur,cur);
	vector<pair<int, int>> res;
	if (plus > 0) {
		res.push_back(cal(index+1, cur + v[index], plus - 1, minus, mul, div));
	}
	if (minus > 0) {
		res.push_back(cal(index+1, cur - v[index], plus, minus-1, mul, div));
	}
	if (mul > 0) {
		res.push_back(cal(index+1, cur * v[index], plus, minus, mul-1, div));
	}
	if (div > 0) {
		res.push_back(cal(index+1, cur / v[index], plus, minus, mul, div-1));
	}
	pair<int, int> ans = res[0];
	for (auto p : res) {
		if (ans.first < p.first) ans.first = p.first;
		if (ans.second > p.second) ans.second = p.second;
	}
	return ans;
	
}
int main() {
	cin >> a;
	for (int i = 0; i < a; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	int op[4];
	for (int i = 0; i < 4; i++) {
		int num;
		cin >> num;
		op[i] = num;
	}
	pair<int,int> p = cal(1, v[0], op[0], op[1], op[2], op[3]);
	cout << p.first << endl;
	cout << p.second << endl;
	return 0;
}