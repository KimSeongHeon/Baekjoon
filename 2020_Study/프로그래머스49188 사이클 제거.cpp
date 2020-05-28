#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<memory.h>
#include<map>
using namespace std;
bool visited[5001];
vector<int> graph[5001];
map<int,int> ans; //key:정점 , value : component 개수
int order[5001]; // 정점의 순서
int parent[5001]; //부모
int low[5001]; //백엣지
int t = 0;
void making_dfstree(int v,int pre) {
	order[v] = t++;
	low[v] = t;
	int sub = 0; //자식 수
	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i];
		if (next == parent[v]) continue; //부모 노드이면
		if (order[next] == -1 && next != pre) { //내가 가려는 곳이 방문하지 않은 곳이면
			parent[next] = v; //부모를 현재 노드로 설정
			sub++; //자식의 수를 늘리고
			making_dfstree(next,v); //계속 dfs로 찾아 나감
			if (!parent[v] && sub > 1) {
				cout << "v :" << v << " " << sub << endl;
				ans.insert({ v,sub });
			}
			//루트 노드이며 자식 노드를 2개이상 가지고 있으면
			else if (parent[v] && low[next] >= order[v]) {
				cout << "v :" << v << " " << sub << endl;
				ans.insert({ v,sub });
			}
			//부모가 있고, 벡 엣지가 현재 노드의 순서보다 크다, 즉 나중 순서이다.
			low[v] = min(low[v], low[next]);
			//가장 위의 엣지를 선택한다.
		}
		else low[v] = min(low[v], order[next]);
		//가려는 곳이 방문한 곳이면 가장 작은 곳을 선택
	}
}
void dfs(int v) {
	visited[v] = true;
	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i];
		if (!visited[next]) dfs(next);
	}
}
int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	int M = -1;
	memset(order, -1, sizeof(order));
	for (int i = 0; i < edge.size(); i++) {
		int first = edge[i][0];
		int second = edge[i][1];
		graph[first].push_back(second);
		graph[second].push_back(first);
	}
	for (int i = 1; i <= n; i++) {
		if(order[i] == -1) making_dfstree(i,0);
	}//단절점 찾기
	int origin = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i);
			origin++;
		}
	}
	cout << "origin " << origin << endl;
	for (int i = 1; i <= n; i++) {
		if (origin == 1) {
			if (ans.find(i) == ans.end()) {//단절점이 아님
				if (edge.size() - graph[i].size() < n - 1) answer = answer + i;
			}
			else {
				cout << ans[i] << endl;
				if (edge.size() - graph[i].size() + ans[i] < n - 1) answer = answer + i;
			}
		}
		else {
			if (ans.find(i) == ans.end()) {//단절점이 아님
				if (edge.size() - graph[i].size() + origin < n - 1) answer = answer + i;
			}
			else {
				if (edge.size() - graph[i].size() + ans[i] + origin< n - 1) answer = answer + i;
			}
		}
		
	}
	return answer;
}
int main() {
	vector<vector<int>> a;
	a.push_back({ 1,2 });
	a.push_back({ 1,3 });
	a.push_back({ 2,3 });
	a.push_back({ 1,4 });
	a.push_back({ 1,5 });
	cout << solution(5, a);
}