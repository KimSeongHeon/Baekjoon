#include<iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
	vector<int> answer;
	int sero;
	int garo;
	for (int i = 1; i <= red; i++) {
		if (red%i != 0) continue;
		sero = i;
		garo = red / i;
		if ((sero + 2)*(garo + 2) - red == brown) break;
	}
	if (sero > garo) answer = { sero+2,garo+2 };
	else answer = { garo+2,sero+2 };
	return answer;
}
int main() {
	vector<int> a = solution(10, 2);
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
}