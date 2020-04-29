#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;
vector<int> pre;
vector<int> post;
bool visited[10001];
bool compare(const pair<int,pair<int, int>> &a, const pair<int,pair<int, int>> &b) {
	if (a.second.second == b.second.second)  return a.second.first < b.second.first;
	return a.second.second > b.second.second;
}
void pre_order(int n) {
	pre.push_back(n);
	pre_order(n);
	pre_order(n);
}
void post_order(int n) {
	post_order(n);
	post_order(n);
	post.push_back(n);
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<int>> answer;
	vector<pair<int,pair<int, int>>> node;
	int parent[10001][2];
	memset(visited,false,sizeof(visited));
	memset(parent, -1, sizeof(parent));
	for (int i = 0; i < nodeinfo.size(); i++) {
		node.push_back(make_pair(i+1,make_pair(nodeinfo[i][0],nodeinfo[i][1])));
	}
	sort(node.begin(), node.end(), compare);
	for (int i = 0; i < node.size(); i++) {
		cout << node[i].first << " " << node[i].second.first << " " <<node[i].second.second << endl;
	}
	for (int i = 0; i < node.size(); i++) {
		for (int j = i+1; j < node.size(); j++) {
			if (node[i].second.second > node[j].second.second) {
				if (node[i].second.first > node[j].second.first && !visited[node[j].first]) {
					parent[i][0] = node[j].first;
					visited[node[j].first] = true;
				}
				else if (node[i].second.first < node[j].second.first && !visited[node[j].first]) {
					parent[i][1] = node[j].first;
					visited[node[j].first] = true;
				}
			}
			if (parent[i][0] != -1 && parent[i][1] != -1) break;
		}
	}
	for (int i = 0; i < nodeinfo.size(); i++) {
		cout << "parent : " << node[i].first << "일 때, 자식 :";
		cout << parent[i][0] << " " << parent[i][1];
		cout << endl;
	}
	return answer;
}
int main(){
	vector<vector<int>> b;
	vector<int> a;
	a.push_back(5);
	a.push_back(3);
	b.push_back(a);
	a.clear();
	a.push_back(11);
	a.push_back(5);
	b.push_back(a);
	a.clear();
	a.push_back(13);
	a.push_back(3);
	b.push_back(a);
	a.clear();
	a.push_back(3);
	a.push_back(5);
	b.push_back(a);
	a.clear();
	a.push_back(6);
	a.push_back(1);
	b.push_back(a);
	a.clear();
	a.push_back(1);
	a.push_back(3);
	b.push_back(a);
	a.clear();
	a.push_back(8);
	a.push_back(6);
	b.push_back(a);
	a.clear();
	a.push_back(7);
	a.push_back(2);
	b.push_back(a);
	a.clear();
	a.push_back(2);
	a.push_back(2);
	b.push_back(a);
	solution(b);
}