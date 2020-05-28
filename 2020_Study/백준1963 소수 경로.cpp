#include<iostream>
#include<algorithm>
#include<memory.h>
#include<queue>
#include<string>
#include<cmath>
using namespace std;
int T;
queue<int> q;
int depth[10000];
//소수인지 판별하는 함수
bool isPrime(int n) {

}
void bfs(int s2) {
	while (!q.empty()) {
		int s = q.front(); q.pop();
		if (s == s2) return;
		for (int i = 0; i < 4; i++) {
			if (i == 0) {
				for (int j = 1; j < 10; j++) {
					int new_element = s % 1000 + j * 1000;
					if (isPrime(new_element) && depth[new_element] == -1) {
						q.push(new_element);
						depth[new_element] = depth[s] + 1;
					}
				}
			}
			else {
				for (int j = 0; j < 10; j++) {
				}
			}
		}
	}
}
int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		memset(depth, -1, sizeof(depth));
		int s1, s2;
		cin >> s1 >> s2;

	}
	return 0;
}