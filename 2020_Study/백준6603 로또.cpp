#include<iostream>
#include<vector>
using namespace std;
vector<int> v;
vector<int> answer;
int num;
void cal(int n) {
	if (n < 0 || n >= v.size()) return;
	if (answer.size() > v.size()) return;
	answer.push_back(v[n]);
	for (int i = n+1; i < num; i++) cal(i);
	if (6 == answer.size()) {
		for (int i = 0; i < answer.size(); i++) {
			printf("%d ",answer[i]);
		}
		printf("\n");
	}
	answer.pop_back();
	
}
int main()
{
	while (1) {
		cin >> num;
		if (num == 0) break;
		for (int i = 0; i < num; i++) {
			int element;
			cin >> element;
			v.push_back(element);
		}
		for (int i = 0; i < num; i++) cal(i);
		printf("\n");
		v.clear();
	}
	return 0;
}