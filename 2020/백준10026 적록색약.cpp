#include<iostream>

using namespace std;

int rgb[101][101];
int main()
{
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			cin >> rgb[i][j];
		}
	}
	return 0;
}
