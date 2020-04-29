#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	while (k > 0) {
		if (n > 2 * m) n--;
		else m--;
		k--;
	}
	if (n >= 2 * m) {
		cout << m;
	}
	else {
		cout << n / 2;
	}
	return 0;
}