#include<iostream>
#include<algorithm>
#include<memory.h>
#include<vector>
using namespace std;
int num, k;
int coin[101];
int cache[10001]; //index의 동전까지 사용했을 때 나오는 경우의 수.
int cal(int index,int price) {
	if (index<0 || index > num || price < 0) return 0;
	int &ret = cache[price];
	cout << index << " " << price << endl;
	if (ret != -1) return ret;
	if (price < coin[index]) ret = cal(index - 1, price);
	else ret = cal(index - 1, price) + cal(index, price - coin[index]);
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	cin >> num >> k;
	for (int i = 1; i <= num; i++) {
		cin >> coin[i];
	}
	sort(coin, coin + num);
	cache[0] = 1;
	cache[coin[1]] = 1;
	cout << cal(num, k);
}