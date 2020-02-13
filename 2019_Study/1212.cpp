#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#include<string>
#include<deque>
using namespace std;

int main()
{
	string str;
	vector<int> v;
	cin >> str;
	if (str == "0") {
		cout<< 0;
		return 0;
	}
	for (int i = 0; i < str.length(); i++) {
		int value = (int)str.at(i) - 48;
		deque<int> q;
		while (value != 0) {
			q.push_back(value % 2);
			value = value / 2;
		}
		
		while (q.size() != 3 && i!=0) {
			q.push_back(0);
		}
		
		while (q.size() != 0) {
			cout << q.back();
			v.push_back(q.back());
			q.pop_back();
		}
		
	}
	
	return 0;
}
