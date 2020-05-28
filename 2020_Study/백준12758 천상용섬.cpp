//
//  백준12758 천상용섬.cpp
//  백준문제풀이
//
//  Created by 김성헌 on 2020/04/07.
//  Copyright © 2020 김성헌. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include<set>
#define M 1000000007
using namespace std;
vector<int> v;
vector<int> comb;
set<int> s[1000001];
int ans = 0;
void go(int cut, int index) {
	if (index == v.size() - 1) {
		ans += 1;
		return;
	}
	comb.push_back(cut);
	for (auto iter = s[v[index + 1]].begin(); iter != s[v[index + 1]].end(); iter++) {
		if (*iter < cut || *iter == 0) continue;
		else go(*iter, index + 1);
	}
	comb.pop_back();
	return;
}
int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		int element;
		for (int i = 0; i < n; i++) {
			cin >> element;
			v.push_back(element);
			if (s[element].size() == 0) {
				for (int i = 1; i*i <= element; i++) {
					if (element % i == 0) {
						s[element].insert(i);
						s[element].insert(element / i);
					}
				}
			}
		}
		for (auto iter = s[v[0]].begin(); iter != s[v[0]].end(); iter++) {
			go(*iter, 0);
		}
		cout << (ans % M) << endl;
		ans = 0;
		v.clear();
	}
	return 0;
}