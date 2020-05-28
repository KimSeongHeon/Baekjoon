#include<iostream>
#include<string>
#include<map>
using namespace std;
map<string, string> root;
map<string, int> depth;
map<string, int> node_count;
string find(string x) {
	if (root[x] == x) {
		return x;
	}
	else {
		return root[x] = find(root[x]);
	}
}
void union_by_rank(string x, string y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	if (depth[x] < depth[y]) {
		root[x] = y;
	}
	else {
		root[y] = x;
		if (depth[x] == depth[y])
			depth[x]++;
	}
}
int ret_node_count(string x, string y) {
	x = find(x);
	y = find(y);
	if (x != y) {//다른 뿌리일 경우
		root[y] = x;
		node_count[x] += node_count[y];
		node_count[y] = 1;
	}
	return node_count[x];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		root.clear(); depth.clear(); node_count.clear();
		for (int i = 0; i < n; i++) {
			string str1, str2;
			cin >> str1 >> str2;
			//초기화
			if (root.find(str1) == root.end()) {
				root.insert({ str1,str1 });
				depth.insert({ str1,0 });
				node_count.insert({ str1,1 });
			}
			if (root.find(str2) == root.end()) {
				root.insert({ str2,str2 });
				depth.insert({ str2,0 });
				node_count.insert({ str2,1 });
			}
			cout << ret_node_count(str1, str2) << "\n";
		}
	}

}