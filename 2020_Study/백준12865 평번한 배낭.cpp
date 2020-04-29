#include<iostream>
#include<vector>
#include<algorithm>
#include<memory.h>
using namespace std;
int N, K;
int volume[101];
int value[101];
int cache[101][100001];
int cal(int index,int capacity) {
	int &ret = cache[index][capacity];
	if (index > N - 1) return 0;
	//cout << index << "  " << capacity << endl;
	if (ret != -1) return ret;
	ret = cal(index + 1, capacity);
	if (capacity >= volume[index]) {
		ret = max(ret, cal(index + 1, capacity - volume[index]) + value[index]);
	}
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> volume[i] >> value[i];
	}
	cout << cal(0, K);
	return 0;
}