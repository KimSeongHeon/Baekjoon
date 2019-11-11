#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main() {
	int num, kill;
	cin >> num;
	cin >> kill;
	vector<int> answer;
	queue<int> q;
	for (int i = 1; i <= num; i++) {
		q.push(i);
	}
	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= kill; j++) {
			if (j == kill) {
				answer.push_back(q.front());
				q.pop();
			}
			else {
				q.push(q.front());
				q.pop();
			}
		}
	}
	cout << "<";
	for (int i = 0; i < answer.size() - 1; i++) {
		cout<<answer[i] <<", ";
	}
	cout << answer[answer.size() - 1];
	cout << ">";
}
