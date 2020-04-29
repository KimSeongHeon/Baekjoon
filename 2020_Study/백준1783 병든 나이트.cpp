#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n,m;
	cin >> n >> m;
	bool all = false;
	int x, y;
	int ans = 1;
	if (n - 2 >= 1 && m >=6) {
		all = true;
		x = n;
		y = 7;
		ans = ans + 4;
		ans = ans + m - 7;
	}
	else {
		x = n;
		y = 1;
		while (1) {
			if (y == m) break;
			if (x - 2 >= 1) {
				x = x - 2;
				y = y + 1;
				ans++;
			}
			else {
				if (x + 2 <= n) {
					x = x + 2;
					y = y + 1;
					ans++;
				}
				else {
					if (x - 1 >= 1 && y + 2 <= m) {
						x = x - 1;
						y = y + 2;
						ans++;
					}
					else if (x + 1 <= n && y + 2 <= m) {
						x = x + 1;
						y = y + 2;
						ans++;
					}
					else {
						break;
					}
				}
			}
		}
	}
	if (ans >= 5 && !all) cout << 4;
	else cout << ans;
	return 0;
}