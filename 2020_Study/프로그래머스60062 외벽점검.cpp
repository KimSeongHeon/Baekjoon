#include<iostream>
#include<algorithm>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;
bool cmp(int &a, int &b) {
	return a > b;
}
int solution(int n, vector<int> weak, vector<int> dist) {
	int answer = 0;
	sort(dist.begin(), dist.end(),cmp);
	for (int i = 0; i < dist.size(); i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) { //시계 방향
			if (j + dist[i] < n) {
				for (int k = 0; k < weak.size(); k++) {
					if (weak[k] < j + dist[i]) cnt++;
				}
			}
			else {

			}
		}
		for (int j = n; j > 0; j--) {//반시계 방향

		}
	}
	
	
	return answer;
}
int main() {
	cout << solution(12, { 1,5,6,10 }, { 1,2,3,4 });
	return 0;
}