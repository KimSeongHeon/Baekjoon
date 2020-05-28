#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<memory.h>
using namespace std;
vector<char> v;
vector<int> big;
vector<int> small;
vector<int> answer1;
vector<int> answer2;

void big_select(int n,int index) {
	for (int i = 0; i < big.size(); i++) {
		if (n == big[i]) return;
	}
	if (n > 9 || n < 0) return;
	if (big.size() == v.size()+1) return;
	else {
		big.push_back(n);
		if (index < v.size()) {
			if (v[index] == '<') {
				for (int i = n + 1; i <= 9; i++)
					big_select(i, index + 1);
			}
			else if (v[index] == '>') {
				for (int i = n - 1; i >= 0; i--)
					big_select(i, index + 1);
			}
		}
		if (big.size() != v.size() + 1)
			big.pop_back();
	}
}
void small_select(int n, int index) {
	for (int i = 0; i < small.size(); i++) {
		if (n == small[i]) return;
	}
	if (small.size() == v.size() + 1) return;
	if (n > 9 || n < 0) return;
	else {
		small.push_back(n);
		if (index < v.size()) {
			if (v[index] == '<') {
				for (int i = n + 1; i <= 9; i++)
					small_select(i, index + 1);
			}
			else if (v[index] == '>') {
				for (int i = n - 1; i >= 0; i--)
					small_select(i, index + 1);
			}
		}
		if (small.size() != v.size() + 1)
			small.pop_back();
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		v.push_back(c);
	}
	for (int i = 9; i >= 0; i--) {
		big.clear();
		big_select(i, 0);
		if (big.size() == v.size() + 1) break;
	}
	for (int i = 0; i <= 9; i++) {
		small.clear();
		small_select(i, 0);
		if (small.size() == v.size() + 1)break;
	}

	for (int i = 0; i < big.size(); i++)
		cout << big[i];
	cout << endl;
	for (int i = 0; i < small.size(); i++)
		cout << small[i];

}
