#include<iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
int ans = 0;
vector<int> num;
void dfs(int x, set<int> remain, int target) {
	cout << x << endl;
	if (remain.size() == 0) {
		if (x == target) ans++;
		return;
	}
	for (auto iter = remain.begin(); iter != remain.end(); iter++) {
		set<int> temp = remain;
		temp.erase(temp.find(*iter));
		dfs(x + num[*iter], temp, target);
		dfs(x - num[*iter], temp, target);
	}
	return;
}
int solution(vector<int> numbers, int target) {
	int answer = 0;
	num = numbers;
	set<int> all;
	for (int i = 0; i < numbers.size(); i++) {
		all.insert(i);
	}
	dfs(0, all, target);
	answer = ans;
	return answer;
}
int main() {
	vector<int> a = { 1,1,1,1,1 };
	cout << solution(a, 3);
}