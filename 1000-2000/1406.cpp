#include<iostream>
#include<stack>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int main() {
	vector<char> s1; //커서 전 취급
	vector<char> s2; //커서 후 취급
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		s1.push_back(str.at(i));
	}
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		char command;
		cin >> command;
		if (command == 'P') {
			char next;
			cin >> next;
			s1.push_back(next);
		}
		else if (command == 'L') {
			if (s1.size() != 0) {
				s2.push_back(s1.back());
				s1.pop_back();
			}
		}
		else if (command == 'D') {
			if (s2.size() != 0) {
				s1.push_back(s2.back());
				s2.pop_back();
			}

		}
		else if (command == 'B') {
			if (s1.size() != 0) {
				s1.pop_back();
			}
		}
	}
	for (int i = 0; i < s1.size(); i++) {
		cout << s1[i];
	}
	for (int i = s2.size() - 1; i >= 0; i--) {
		cout << s2[i];
	}
}
