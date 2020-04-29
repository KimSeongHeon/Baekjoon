#include<iostream>
#include<vector>
#include<algorithm>
#include<memory.h>
using namespace std;
int n;
int line[10001];
int cache[10001];
int max_first = -987654321;
int min_first = 987654321;
int cal(int index) {
	if (line[index] == -1) return 0;
	if (cache[index] != -1) return cache[index];
	int &ret = cache[index];
	ret = 1;
	for (int i = index+1; i <= max_first; i++) {
		if (line[i] > line[index]) ret = max(ret, cal(i) + 1);
	}
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	memset(line, -1, sizeof(line));
	cin >> n;
	for (int i = 0; i < n; i++) {
		int first, second;
		cin >> first >> second;;
		line[first] = second;
		max_first = max(max_first, first);
		min_first = min(min_first, first);
	}
	int lis = -987654321;
	for (int i = min_first; i <= max_first; i++) {
		lis = max(lis, cal(i));
	}
	cout << n - lis;
	return 0;
}