#include<iostream>
#include<vector>
#include<string>
using namespace std;
int n;
char map[21][21];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			map[i][j] = s[j];
		}
	}
	return 0;
}