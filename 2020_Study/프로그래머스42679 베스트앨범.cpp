#include<iostream>
#include <string>
#include <vector>
#include<map>
#include<algorithm>
using namespace std;
map<string, int> cnt;
map<string, vector<pair<int, int>>> kind;
bool cmp(pair<int,int> &a,pair<int,int> &b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first > b.first;
}
vector<int> solution(vector<string> genre, vector<int> play) {
	vector<int> answer;
	for (int i = 0; i < genre.size(); i++) {
		if (cnt.find(genre[i]) != cnt.end()) {
			cnt[genre[i]] = cnt[genre[i]] + play[i];
			kind[genre[i]].push_back({play[i],i});
		}
		else {
			cnt.insert({ genre[i], play[i] });
			vector<pair<int, int>> temp;
			temp.push_back({play[i],i});
			kind.insert({ genre[i],temp });
		}
	}
	while (1) {
		if (cnt.size() == 0) break;
		int m = -1;
		string key = "";
		for (auto iter = cnt.begin(); iter != cnt.end(); iter++) {
			m = max(m, (*iter).second);
			if (m == (*iter).second) key = (*iter).first;
		}
		cnt.erase(cnt.find(key));
		sort(kind[key].begin(), kind[key].end(),cmp);
		if (kind[key].size() < 2) {
			answer.push_back(kind[key][0].second);
		}
		else {
			answer.push_back(kind[key][0].second);
			answer.push_back(kind[key][1].second);
		}
	}
	
	return answer;
}
int main() {
	//[classic, pop, classic, classic, pop]
	vector<string> a;
	a.push_back("a");
	a.push_back("a");
	a.push_back("a");
	a.push_back("b");
	a.push_back("b");
	a.push_back("b");
	a.push_back("b");
	a.push_back("c");
	a.push_back("c");
	a.push_back("d");
	a.push_back("d");
	vector<int> b;
	b.push_back(1000);
	b.push_back(2000);
	b.push_back(3000);
	b.push_back(100);
	b.push_back(200);
	b.push_back(300);
	b.push_back(400);
	b.push_back(10);
	b.push_back(20);
	b.push_back(1);
	b.push_back(2);
	vector<int> c = solution(a, b);
	for (int i = 0; i < c.size(); i++) {
		cout << c[i] << " ";
	}
	return 0;
}