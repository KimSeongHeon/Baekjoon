#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;
bool compare(pair<int, int>&a, pair<int, int> &b) {
	if (a.second == b.second) return a.first > b.first;
	return a.second < b.second;
}
int solution(vector<int> food, long long k) {
	int answer = -1;
	vector<pair<int, int>> v; //�Դ½ð�,�ε��� 2���� ���� �����ϴ� �迭
	for (int i = 0; i < food.size(); i++) {
		v.push_back(make_pair(food[i], i));
	}
	sort(v.begin(), v.end());
	int row = 0;
	int before = 0;
	while (row < food.size()) {
		int time = v[row].first;
		int start = row;
		while (row + 1 < food.size() && v[row + 1].first == time) row++;
		//�ٸ� ���ڰ� ����.
		int cnt = food.size() - start;
		//�� �� �ִ� ...
		if (k < (long long)(time - before) * (long long)cnt) {
			sort(v.begin() + start, v.end(), compare);
			answer = v[start + (k%cnt)].second + 1;
			break;
		}
		k -= (time - before) * cnt;
		before = time;
		row++;
	}
	return answer;
}
int main()
{
	vector<int> a;
	a.push_back(5);
	a.push_back(6);
	a.push_back(2);
	a.push_back(5);
	a.push_back(2);
	//a.push_back(4);
	//a.push_back(5);
	//a.push_back(5);
	//a.push_back(6);
	//a.push_back(2);
	//a.push_back(25);
	//a.push_back(6);
	long long  k = 14;
	cout << solution(a, k);
	return 0;
}