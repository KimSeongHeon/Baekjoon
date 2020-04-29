//
//  백준1725 히스토그램.cpp
//  백준문제풀이
//
//  Created by 김성헌 on 2020/04/07.
//  Copyright © 2020 김성헌. All rights reserved.
//

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<memory.h>
using namespace std;
vector<int> v;
int n;
int mid_go(int left, int right, int height) {
	if (left < 0 || right >= n) return 0;
	//cout << left << " " << right << endl;
	int extension_r = 0;
	int extension_l = 0;
	if (right + 1 < n && (left == 0 || v[right + 1] > v[left - 1])) {
		int n_height = min(height, v[right + 1]);
		extension_r = mid_go(left, right + 1, n_height);
	}
	else {
		int n_height = min(height, v[left - 1]);
		extension_l = mid_go(left - 1, right, n_height);
	}
	int ret = max((right - left + 1)*height, max(extension_l, extension_r));
	return ret;
}
int go(int left, int right) {
	//cout << left << " " << right << endl;
	if (left == right) return v[left];
	int mid = (left + right) / 2;
	int ret = max(go(left, mid), go(mid + 1, right));
	int m = 987654321;
	int height = min(v[mid].v[mid+1]);
	ret = max(ret, mid_go(mid,mid+1,height));
	return ret;
}//반반 나눠서 확인

int main() {
	cin.tie(NULL);
	int element;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> element;
		v.push_back(element);
	}
	cout << (go(0,n-1));
	return 0;
}
