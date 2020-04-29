#include<iostream>
#include<string>
#include<set>
#include<algorithm>
using namespace std;
int ans = 0;
int ans2 = 0;
int N, K;
string str[51];
set<char> lis[51];
set<char> comb;
set<char> cand;
int cal(int point) {
	int answer = 0;
	if(point > cand.size()) return 0;
	if (comb.size() > K) return 0;
	/*if (comb.size() == K) {
		/*cout << "comb : ";
		for (set<char>::iterator iter = comb.begin(); iter != comb.end(); ++iter) {
			cout << *iter << " ";
		}
		cout << endl;
		for (int i = 0; i < N; i++) {
			if (includes(comb.begin(),comb.end(),lis[i].begin(),lis[i].end())) answer++;
		}
		return answer;
	}//´Ù ¹è¿üÀ» ¶§..*/
	int part = 0;
	for (int i = 0; i < N; i++) {
		if (comb.size() >= lis[i].size()) {
			if (includes(comb.begin(), comb.end(), lis[i].begin(), lis[i].end())) part++;
		}
	}
	ans2 = max(ans2, part);
	for (int i = point; i < cand.size(); i++) {
		set<char>::iterator iter = cand.begin();
		for (int j = 0; j < i; j++) {
			iter++;
		}
		comb.insert(*iter);
		ans = max(ans,cal(i + 1));
		comb.erase(*iter);
	}
	return 0;
}
int main() {
	comb.insert('a');
	comb.insert('n');
	comb.insert('t');
	comb.insert('i');
	comb.insert('c');
	cin >> N >> K;
	if (K < 5) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < N; i++) {
		cin >> str[i];
		for (int j = 0; j < str[i].size(); j++) {
			lis[i].insert(str[i][j]);
			if (str[i][j] != 'a' && str[i][j] != 'n' 
				&& str[i][j] != 't' && str[i][j] != 'i' && str[i][j] != 'c') {
				cand.insert(str[i][j]);
			}
		}
	}
	cal(0);
	cout << max(ans,ans2);
	return 0;
}