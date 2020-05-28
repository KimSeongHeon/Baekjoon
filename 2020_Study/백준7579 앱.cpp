#include<iostream>
#include<algorithm>
#include<memory.h>
#include<vector>
using namespace std;
int N, M;
int volume[101];
int cost[101];
int cache[101][1000001];
int cal(int index,int price) {
	int &ret = cache[index][price];
	if (index < 0) return 0;
	if (ret != -1) return ret;
	ret = cal(index - 1, price);
	return ret;
}

int main(){
	memset(cache, -1, sizeof(cache));
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> volume[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> cost[i];
		cache[i][cost[i]] = volume[i];
	}
	cal(M);
	for (int i = 0; i <= M; i++) {
		cout << cache[i] << " ";
		if (i % 10 == 0) cout << endl;
	}
}