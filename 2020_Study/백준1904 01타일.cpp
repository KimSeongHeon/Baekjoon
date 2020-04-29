#include<iostream>
#include<memory.h>
using namespace std;
int N;
int cache[1000001];
int cal(int n) {
	if (n < 0) return 0;
	int &ret = cache[n];
	if (ret != -1) return ret;
	ret = (cal(n - 2) + cal(n - 1))%15746;
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	cin >> N;
	cache[0] = 0;
	cache[1] = 1;
	cache[2] = 2;
	cout << cal(N);
	return 0;
}