#include<iostream>
#include <string>
#include <vector>
#include<set>
#include<algorithm>
using namespace std;
bool compare(vector<string> &a,vector<string> &b) {
	return a.size() < b.size();
}
vector<int> solution(string s) {
	vector<int> answer;
	bool check = false;
	string temp = "";
	vector<string> v;
	vector<vector<string>> vv;
	for (int i = 1; i < s.length()-1; i++) {
		if (s[i] == '{') check = true; 
		else if (s[i] == '}') {
			v.push_back(temp);
			temp = "";
			check = false;
		}
		else {
			if (check) {
				if (s[i] == ',') {
					v.push_back(temp);
					temp = "";
				}
				else temp = temp + s[i];
			}
			else {
				if (s[i] == ',') {
					vv.push_back(v);
					v.clear();
				}
			}
		}
	}
	vv.push_back(v);
	v.clear();
	sort(vv.begin(), vv.end(), compare);
	set<string> sa;
	for (int i = 0; i < vv.size(); i++) {
		for (int j = 0; j < vv[i].size(); j++) {
			if (sa.find(vv[i][j]) == sa.end()) {
				answer.push_back(atoi(vv[i][j].c_str()));
				sa.insert(vv[i][j]);
				cout << vv[i][j] << " ";
			}
		}
	}
	return answer;
}
int main() {
	string s = "{{4,2,3},{3},{2,3,4,1},{2,3}}";
	solution(s);
	return 0;
}