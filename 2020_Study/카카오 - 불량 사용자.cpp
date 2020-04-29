#include <string>
#include <vector>
#include<set>
#include<algorithm>
#include<iostream>
using namespace std;
vector<int> comb;
set<set<string>> s;
int cal(int n,int set_num,vector<vector<string>> &all,int size) {
	if (comb.size() == all.size()) {
		set<string> a;
		for (int i = 0; i < comb.size(); i++) {
			a.insert(all[i][comb[i]]);
		}
		if (a.size() == size) {
			s.insert(a);
		}
	}
	if (set_num == all.size()) return 0;
	comb.push_back(n);
	if (set_num != all.size() - 1) {
		for (int i = 0; i < all[set_num + 1].size(); i++) {
			cal(i, set_num + 1, all,size);
		}
	}
	else {
		cal(0, set_num+1, all,size);
	}
	comb.pop_back();
	return 0;
}

int solution(vector<string> user, vector<string> ban) {
	int answer = 0;
	vector<vector<string>> all;
	for (int i = 0; i < ban.size(); i++) {
		vector<string> element;
		for (int j = 0; j < user.size(); j++) {
			bool check = true;
			if (ban[i].length() == user[j].length()) {
				for (int k = 0; k < ban[i].length(); k++) {
					if ((ban[i][k] == user[j][k]) || (ban[i][k] == '*')) {

					}
					else {
						check = false;
						break;
					}
				}
			}
			else continue;
			if (check) element.push_back(user[j]);
		}
		all.push_back(element);
	}
	for (int i = 0; i < all[0].size(); i++) {
		cal(i, 0, all,ban.size());
	}
	/*for (auto i = s.begin(); i != s.end(); i++) {
		for (auto j = (*i).begin(); j != (*i).end(); j++) {
			cout << (*j) << " ";
		}
		cout << endl;
	}*/
	answer = s.size();
	return answer;
}
int main() {
	vector<string> a;
	vector<string> b;
	a.push_back("frodo");
	a.push_back("fradi");
	a.push_back("crodo");
	a.push_back("abc123");
	a.push_back("frodoc");
	b.push_back("*rodo");
	b.push_back("*rodo");
	b.push_back("******");
	cout << solution(a, b);
}