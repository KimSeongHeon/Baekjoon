#include<iostream>
#include <string>
#include <vector>
#include<stack>
using namespace std;
stack<char> s;
bool correct(string str) {
	while (!s.empty()) {
		s.pop();
	}
	for (int i = 0; i < str.length(); i++) {
		if (!s.empty()) {
			if (s.top() == '(' && str[i] == ')') s.pop();
			else s.push(str[i]);
		}
		else {
			s.push(str[i]);
		}
	}
	if (s.empty()) return true;
	else return false;
}
bool balanced(string str) {
	int a = 0;
	int b = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') a++;
		else b++;
	}
	if (a == b) return true;
	else return false;
}
string solution(string p) {
	string answer = "";
	if (correct(p) || p=="") {
		return p;
	}
	else {
		string u = "";
		string v = "";
		for (int i = 1; i <= p.length(); i++) {
			u = p.substr(0, i); v = p.substr(i, p.length());
			if (balanced(u)) break;
		}
		if (correct(u)) {
			u = u + solution(v);
			return u;
		}
		else {
			string str = "(";
			str = str + solution(v);
			str = str + ")";
			int idx = 0;
			u.erase(u.begin() + 1);
			u.erase(u.end() - 1);
			for (auto iter = u.begin(); iter != u.end(); iter++) {
				if (*iter == '(') *iter = ')';
				else *iter = '(';
			}
			str = str + u;
			return str;
		}
	}
}
int main() {
	cout << solution("()))((()");
	//cout << correct("()");
	return 0;
}