#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> energy;
vector<int> comb;
int num;
int answer = -987654321;
void cal(int n) {//n번째 수열.
	for (int i = 0; i < comb.size(); i++) {
		if (comb[i] == n) return;
	}
	if (n >= num-1 || n <= 0) return;
	comb.push_back(n);
	for (int i = n+1; i < num; i++) cal(i);
	for (int i = n-1; i >= 0; i--) cal(i);
	if (comb.size() == num - 2) {
		int temp = 0;
		vector<int> c_energy = energy;
		for (int i = 0; i < comb.size(); i++) {
			//cout << comb[i] << " ";
			c_energy[comb[i]] = -1;
			int plus_index = 0; int minus_index = 0;
			while (1) {
				plus_index++;
				if (c_energy[comb[i] + plus_index] != -1) break;
			}
			while (1) {
				minus_index++;
				if (c_energy[comb[i] - minus_index] != -1) break;
			}
			temp = temp + c_energy[comb[i] - minus_index] * c_energy[comb[i] + plus_index];
			
		}
		answer = max(answer, temp);
	}
	//cout << endl;
	comb.pop_back();
}
int main() {
	cin >> num;
	for (int i = 0; i < num; i++) {
		int element;
		cin >> element;
		energy.push_back(element);
	}
	for (int i = 1; i < num - 1; i++) {
		cal(i);
	}
	cout << answer;
	return 0;
}