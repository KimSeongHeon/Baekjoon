#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<memory.h>
#include<map>
using namespace std;
bool visited[5001];
vector<int> graph[5001];
map<int,int> ans; //key:���� , value : component ����
int order[5001]; // ������ ����
int parent[5001]; //�θ�
int low[5001]; //�鿧��
int t = 0;
void making_dfstree(int v,int pre) {
	order[v] = t++;
	low[v] = t;
	int sub = 0; //�ڽ� ��
	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i];
		if (next == parent[v]) continue; //�θ� ����̸�
		if (order[next] == -1 && next != pre) { //���� ������ ���� �湮���� ���� ���̸�
			parent[next] = v; //�θ� ���� ���� ����
			sub++; //�ڽ��� ���� �ø���
			making_dfstree(next,v); //��� dfs�� ã�� ����
			if (!parent[v] && sub > 1) {
				cout << "v :" << v << " " << sub << endl;
				ans.insert({ v,sub });
			}
			//��Ʈ ����̸� �ڽ� ��带 2���̻� ������ ������
			else if (parent[v] && low[next] >= order[v]) {
				cout << "v :" << v << " " << sub << endl;
				ans.insert({ v,sub });
			}
			//�θ� �ְ�, �� ������ ���� ����� �������� ũ��, �� ���� �����̴�.
			low[v] = min(low[v], low[next]);
			//���� ���� ������ �����Ѵ�.
		}
		else low[v] = min(low[v], order[next]);
		//������ ���� �湮�� ���̸� ���� ���� ���� ����
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
	}//������ ã��
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
			if (ans.find(i) == ans.end()) {//�������� �ƴ�
				if (edge.size() - graph[i].size() < n - 1) answer = answer + i;
			}
			else {
				cout << ans[i] << endl;
				if (edge.size() - graph[i].size() + ans[i] < n - 1) answer = answer + i;
			}
		}
		else {
			if (ans.find(i) == ans.end()) {//�������� �ƴ�
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