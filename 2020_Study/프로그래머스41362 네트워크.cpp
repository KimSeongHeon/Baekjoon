#include<iostream>
#include <string>
#include <vector>

using namespace std;
bool visited[201];
void dfs(int n ,vector<vector<int>> &com,int size) {
	visited[n] = true;
	for (int i = 0; i < size;i++) {
		if (n == i) continue;
		if (com[n][i] == 1) {
			if (!visited[i]) dfs(i, com, size);
		}
	}
	return;
}
int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			dfs(i,computers,n);
			answer++;
		}
	}
	return answer;
}
int main() {
	vector<vector<int>> a;
	a.push_back({ 1,1,0 });
	a.push_back({ 1,1,0 });
	a.push_back({ 0,0,1 });
	cout << solution(3, a);
}