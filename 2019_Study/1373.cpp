#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
using namespace std;

int main()
{
	string str;
	cin >> str;
	vector<int> answer;
	for (int i = str.length() - 1; i >= 0; i=i-3) {
		int value = 0;
		for (int j = 0; j < 3; j++) {
			if (i - j >= 0) {
				value = value + (int)(str.at(i - j)-48)*pow(double(2), (double)j);

			}
		}
		//cout << value << endl;
		answer.push_back(value);
	}
	while (answer.size() != 0) {
		cout << answer.back();
		answer.pop_back();
	}
	
}
