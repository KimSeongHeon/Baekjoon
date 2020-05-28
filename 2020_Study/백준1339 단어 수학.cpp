#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<memory.h>
#include<math.h>
using namespace std;
int n;
int answer = -987654321;
vector<int> v[10];
vector<int> list; //중복없는 알파벳 모음
vector<int> comb;
int aucro = 0;
int alp[100];
void cal(int x) {
	for (int i = 0; i < comb.size(); i++) {
		if (comb[i] == x) return;
	}
	if (comb.size() > list.size()) return;
	if (x > 9 || x<0) return;
	else {
		comb.push_back(x);
		if (comb.size() < list.size()) {
			for (int i = x + 1; i <= 9; i++) {
				cal(i);
			}
			for (int i = x - 1; i >= 0; i--) {
				cal(i);
			}
		}
		if (comb.size() == list.size()) { //수열이 다 뽑힌 상태			
			for (int i = 0; i < list.size(); i++)
				alp[list[i]] = comb[i];
			int temp = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < v[i].size(); j++) {
					temp = temp + pow(10, (v[i].size() - j - 1)) * alp[v[i][j]];
				}
			}
			answer = max(answer, temp);
		}
		comb.pop_back();
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			v[i].push_back(s[j]);
			list.push_back(s[j]);
		}
	}
	sort(list.begin(), list.end());
	list.erase(unique(list.begin(), list.end()), list.end());
	cal(9);
	cout << answer;
	return 0;
}