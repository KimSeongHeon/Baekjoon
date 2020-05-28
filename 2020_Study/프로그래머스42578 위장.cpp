#include<iostream>
#include <string>
#include <vector>
#include<map>
#include<set>
using namespace std;
map<string, vector<int>> m;
vector<string> key;
vector<string> comb;
set<vector<string>> s;
int answer = 1;
int solution(vector<vector<string>> clothes) {
	for (int i = 0; i < clothes.size(); i++) {
		if (m.find(clothes[i][1]) != m.end()) {
			m[clothes[i][1]].push_back(i);
		}
		else {
			vector<int> a;
			a.push_back(i);
			m.insert({clothes[i][1],a});
			key.push_back(clothes[i][1]);
		}
	}
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		answer = answer * ((*iter).second.size()+1);
	}
	return answer-1;
}

int main() {
	//[[yellow_hat, headgear], [blue_sunglasses, eyewear], [green_turban, headgear]]
	vector<vector<string>> a;
	a.push_back({ "yellow_hat", "headgear" });
	a.push_back({ "blue_sunglasses", "eyewear" });
	a.push_back({ "green_turban", "headgear" });
	cout << solution(a);
}