#include<iostream>
#include<vector>

using namespace std;
struct Node {
	char value;
	Node *left;
	Node *right;
};
Node node[200] = {0,NULL,NULL};
void preorder(Node *node) {
	if (node != NULL) {
		cout << node->value;
		preorder(node->left);
		preorder(node->right);
	}
	else return;
}
void inorder(Node *node) {
	if (node != NULL) {
		inorder(node->left);
		cout << node->value;
		inorder(node->right);
	}
	else return;
}
void postorder(Node *node) {
	if (node != NULL) {
		postorder(node->left);
		postorder(node->right);
		cout << node->value;
	}
	else return;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		char current;
		cin >> current;
		char left, right;
		cin >> left >> right;
		node[current].value = current;
		if (left != '.') {
			node[left].value = left;
			node[current].left = &node[left];
		}
		if (right != '.') {
			node[right].value = right;
			node[current].right = &node[right];
		}
	}
	preorder(&node['A']);
	cout << endl;
	inorder(&node['A']);
	cout << endl;
	postorder(&node['A']);
	return 0;
}