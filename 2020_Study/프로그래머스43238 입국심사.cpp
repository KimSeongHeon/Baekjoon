#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
#define N_MAX 1000000000
#define J_MAX 1000000000
using namespace std;
long long solution(int n, vector<int> times) {
	long long answer = 0;
	int M = -1;
	for (int i = 0; i < times.size(); i++) {
		M = max(M, times[i]);
	}
	unsigned long long left = 1;
	unsigned long long right = ((unsigned long long)M * (unsigned long long)n);
	answer = right;
	unsigned long long mid;
	bool flag = false;
	int cand = 0;
	while (left<=right) {
		unsigned long long temp = 0;
		mid = (left + right) / 2;
		for (int i = 0; i < times.size(); i++) {
			temp = temp + mid / times[i];
		}
		if (n > temp) left = mid + 1;
		else {
			if (mid <= answer) answer = mid;
			right = mid - 1;
		}
	}
	return answer;
}
int main() {
	cout << solution(6, { 7,10 });
	return 0;
}
