#include<iostream>
#include<string>
using namespace std;
int main() {
	string s;
	getline(cin, s);
	int space = 0;
	int shift = 0;
	int left = 0;
	int right = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') {
			space++;
		}
		else if (s[i] >= 'A' && s[i] <= 'Z') {
			shift++;
			if (s[i] == 'Q' || s[i] == 'W' || s[i] == 'E' || s[i] == 'R' || s[i] == 'T' || s[i] == 'Y' ||
				s[i] == 'A' || s[i] == 'S' || s[i] == 'D' || s[i] == 'F' || s[i] == 'G' ||
				s[i] == 'Z' || s[i] == 'X' || s[i] == 'C' || s[i] == 'V' || s[i] == 'B') {
				left++;
			}
			else {
				right++;
			}
		}
		else {
			if (s[i] == 'q' || s[i] == 'w' || s[i] == 'e' || s[i] == 'r' || s[i] == 't' || s[i] == 'y' ||
				s[i] == 'a' || s[i] == 's' || s[i] == 'd' || s[i] == 'f' || s[i] == 'g' ||
				s[i] == 'z' || s[i] == 'x' || s[i] == 'c' || s[i] == 'v' || s[i] == 'b') {
				left++;
			}
			else {
				right++;
			}
		}
	}
	//cout << space << " " << shift << endl;
	int div = space + shift;
	while (div > 0) {
		if (left > right) right++;
		else left++;
		div--;
	}
	cout << left << " " << right;
	return 0;
}