#include<iostream>
#include <string>
#include <vector>
using namespace std;

int solution(string s) {
	int answer = 0;
	string ans = "";
	for (int i = 1; i <= s.length(); i++) {
		string temp = "";
		string pre = "";
		int cnt = 1;
		for (int j = 0; j < s.length(); j=j+i) {
			string sub = "";
			for (int k = 0; k <= i-1; k++) {
				if (j + k < s.length()) sub = sub + s[j+k];
			}
			if (j!=0) {
				if (pre == sub) cnt++;
				else {
					if (cnt != 1) temp = temp + to_string(cnt) + pre;
					else temp = temp + pre;
					cnt = 1;
				}
			}
			pre = sub;
		}
		if(cnt != 1) temp = temp + to_string(cnt) + pre;
		else temp = temp + pre;
		//cout << temp << endl;
		/*for (auto iter = temp.begin(); iter != temp.end(); iter++) {
			if ((*iter) == '1') temp.erase(iter);
		}*/
		if (ans == "") ans = temp;
		else {
			if (ans.length() > temp.length()) {
				ans = temp;
			}
		}
	}
	answer = ans.length();
	return answer;
}
int main() {
	cout << solution("aabbaccc");
	return 0;
}