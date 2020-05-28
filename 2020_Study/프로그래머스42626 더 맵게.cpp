#include<iostream>
#include <string>
#include <vector>
#include<queue>
using namespace std;
priority_queue<int,vector<int>,greater<int>> q;
int solution(vector<int> scoville, int K) {
	int answer = 0;
	for (int i = 0; i < scoville.size(); i++) {
		q.push(scoville[i]);
	}
	bool check = false;
	while (!q.empty()) {
		if (q.top() >= K) {
			check = true;
			break;
		}
		if (q.size() == 1) break;
		else {
			answer++;
			int first = q.top(); q.pop();
			int second = q.top(); q.pop();
			q.push(first + second * 2);
		}
	}
	if (check) return answer;
	else return - 1;
}
int main() {
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(9);
	a.push_back(10);
	a.push_back(12);
	cout << solution(a, 7);
	return 0;
}