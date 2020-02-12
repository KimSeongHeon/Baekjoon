#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int visit(int n, vector<int> friends[2001],vector<int> visited,int index) {
	int count = 0;
	if (visited.size() == 5) {
		return 1;
	}
	else {
		for (int i = 0; i < visited.size(); i++) {
			if (visited[i] == index) {
				return 0;
			}
		}
		visited.push_back(index);
		for (int i = 0; i < friends[index].size(); i++) {
			if (count = count + visit(n, friends, visited, friends[index][i])) {
				return count;
			}
		}
		visited.pop_back();
	}
	return count;
}

int main()
{
	vector<int> friends[2001];
	vector<int> visited;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int pre, pos;
		cin >> pre >> pos;
		friends[pre].push_back(pos);
		friends[pos].push_back(pre);
	}
	for (int i = 0; i < n; i++) {
		if (visit(n, friends, visited, i)) {
			cout << 1;
			return 0;
		}
		else {
			continue;
		}
	}
	cout << 0;
	return 0;
}