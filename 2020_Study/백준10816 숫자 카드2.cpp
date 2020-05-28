#include<iostream>
using namespace std;
int a[10000001][2];
int main(){
	cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n;
	int element;
	for (int i = 0; i < n; i++) {
		cin >> element;
		if (element < 0) {
			a[-1 * element][1]++;
		}
		else {
			a[element][0]++;
		}
	}
	cin >> m;
	for (int j = 0; j < m; j++) {
		cin >> element;
		if (element < 0) cout << a[-1 * element][1] << " ";
		else cout << a[element][0] << " ";
	}
	return 0;
}