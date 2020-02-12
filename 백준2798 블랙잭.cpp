#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int answer = 0;
vector<int> select;
int calculate_sum(int n, int m, vector<int> card) {
	if (select.size() == 3) return answer = max(answer, select[0] + select[1] + select[2]);

}
int main()
{
	int n, m;
	vector<int> card;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		card.push_back(c);
	}
	cout << calculate_sum(n, m, card,0);
	return 0;
}