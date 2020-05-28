#include<iostream>
#include <string>
#include <vector>
#include<list>
using namespace std;

vector<int> solution(int n) {
	vector<int> answer;
	if (n == 1) return { 0 };
	else if (n == 2) return { 0,0,1 };
	else {
		list<int> list;
		auto iter = list.begin();
		list.insert(iter, 0); list.insert(iter, 0); list.insert(iter, 1);
		for (int i = 0; i < n - 2; i++) {
			int size = list.size();
			int cnt = 0;
			iter = list.begin();
			int value = 0;
			while (iter!=list.end()) {
				list.insert(iter, value);
				//cout << value <<  "»ğÀÔ" <<endl;

				/*for (auto k = list.begin(); k != list.end(); k++) {
					cout << *k << " ";
				}
				cout << endl;*/
				if (value==0) value = 1;
				else value = 0;
				iter++;
				cnt++;
			}
			list.insert(list.end(), value);
			//cout << value << "»ğÀÔ" << endl;
		}
		for (auto iter = list.begin(); iter != list.end(); iter++) {
			answer.push_back(*iter);
		}
	}
	return answer;
}
using namespace std;
int main() {
	vector<int> a = solution(4);
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
}