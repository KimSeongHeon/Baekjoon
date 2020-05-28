#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	string s;
	cin >> s;
	vector<int> number;
	vector<char> op;
	int pre_op = -1;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '-' || s[i] == '+') {
			op.push_back(s[i]);
			string temp = "";
			for (int j = pre_op + 1; j < i; j++) {
				temp = temp + (s[j]);
			}
			number.push_back(atoi(temp.c_str()));
			pre_op = i;
		}
	}
	if (op.size() == 0) {
		cout << atoi(s.c_str());
		return 0;
	}
	string temp = "";
	for (int i = pre_op+1; i < s.length(); i++) {
		temp = temp + s[i];
	}
	number.push_back(atoi(temp.c_str()));
	/*for (int i = 0; i < number.size(); i++) {
		cout << number[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < op.size(); i++) {
		cout << op[i] << " ";
	}
	cout << endl;*/
	vector<int> cal;
	int successive = 0;
	for (int i = 0; i < op.size(); i++) {
		if (op[i] == '-') {
			//cout << "-" << endl;
			successive = successive + number[i];
			//cout << successive << endl;
			cal.push_back(successive);
			successive = 0;
		}
		else {
			//cout << "+" << endl;
			//cout << number[i];
			successive = successive + number[i];
			//cout << successive << endl;
		}
	}
	if(op[op.size()-1] == '-') 	cal.push_back(number[number.size() - 1]);
	else if (op[op.size() - 1] == '+') cal.push_back(successive + number[number.size() - 1]);
	int ans = cal[0];
	/*for (int i = 0; i < cal.size(); i++) {
		cout << cal[i] << " ";
	}
	cout << endl;*/
	for (int i = 1; i < cal.size(); i++) {
			ans = ans - cal[i];
	}
	
	cout << ans;
	return 0;
}