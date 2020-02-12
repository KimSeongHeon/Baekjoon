#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
using namespace std;
struct Node {
	int value;
	int depth;
	int col;
	Node *left;
	Node *right;
};
Node node[10001];
int num = 1;
void inorder(Node *node) {
	if (node != NULL) {
		inorder(node->left);
		{
			node->col = num;
			num++;
		}
		inorder(node->right);
	}
	else return;
}

int main() {
	int n;
	bool checked[10001];
	memset(checked, false, sizeof(checked));
	cin >> n;
	for (int i = 0; i < n; i++) {
		int current;
		cin >> current;
		int left, right;
		cin >> left >> right;
		node[current].value = current;
		if (left != -1) {
			checked[left] = true;
			node[left].value = left;
			node[left].depth = node[current].depth + 1;
			node[current].left = &node[left];
		}
		if (right != -1) {
			checked[right] = true;
			node[right].value = right;
			node[right].depth = node[current].depth + 1;
			node[current].right = &node[right];
		}
	}
	int root = 0;
	for (int i = 1; i <= n; i++) {
		if (!checked[i]) root = i;
	}
	inorder(&node[root]);
	vector<int> v[10001];
	for (int i = 1; i <= n; i++) {
		v[node[i].depth].push_back(node[i].col);
	}
	int col_answer = 0;
	int answer = -999999999;
	for (int i = 0; i <= n; i++) {
		if (v[i].size() == 0) break;
		else {
			int minimum = 987654321;
			int maximum = -999999999;
			for (int j = 0; j < v[i].size(); j++) {
				minimum = min(minimum, v[i][j]);
				maximum = max(maximum, v[i][j]);
			}
			if (answer < maximum - minimum) {
				answer = maximum - minimum;
				col_answer = i;
			}
		}
	}
	cout << col_answer+1 <<" "<<answer+1;
	return 0;
}